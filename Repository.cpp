#include "Film.h"
#include "Repository.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

Repository::Repository()
{
    capRepo = 1;
    sizeRepo = 0;
    elem = new Film[capRepo];
}

Repository::~Repository()
{
    delete[] elem;
    elem = 0;
    capRepo = 0;
    sizeRepo = 0;
}

bool Repository::loadFromCSV(string csvPath)
{
    ifstream f(csvPath.c_str());
    if (!f.is_open())
    {
        return false;
    }
    Film film;
    while (f >> film)
    {
        if(sizeRepo >= capRepo)
        {
            Film* elem_l;
            elem_l = new Film[2*capRepo];
            capRepo = 2*capRepo;
            for(int i=0; i<sizeRepo; i++)
            {
                elem_l[i] = elem[i];
            }
            delete[] elem;
            elem = elem_l;
        }
        elem[sizeRepo++] = film;
    }
    f.close();
    return true;
}

bool Repository::saveToCSV(string csvPath)
{
    fstream fout;
    fout.open(csvPath.c_str(), ios::out);
    // daca nu am reusit sa deschidem fisierul returnam false
    if(!fout.is_open())
        return false;
    for(int i = 0; i < sizeRepo; i++)
    {
        // scriem in fisier proprietatile fiecarui film din repository separate prin spatiu
        fout<<elem[i].getTitel()<<","<<elem[i].getGenre()<<","<<elem[i].getErscheinungsjahr()<<","<<elem[i].getAnzahl_von_Likes()<<","<<elem[i].getTrailer()<<endl;
    }
    return true;
}

bool Repository::add_Film(Film f)
{
    if(sizeRepo >= capRepo)
    {
        Film* elem_l;
        elem_l = new Film[2*capRepo];
        capRepo = 2*capRepo;
        for(int i=0; i<sizeRepo; i++)
        {
            elem_l[i] = elem[i];
        }
        delete[] elem;
        elem = elem_l;
    }
    elem[sizeRepo] = f;
    sizeRepo++;
    return true;
}

int Repository::search_Film(string x)
{
    int i;
    bool found = false;
    for(i=0; i<sizeRepo; i++)
    {
        Film f = elem[i];
        if(x==f.getTitel())
        {
            found = true;
            return i;
        }
    }
    //in cazul in care ai ajuns pana aici, inseamna ca nu ai gasit elementul si returnezi -1
    return -1;
}

bool Repository::delete_Film(string Titel)
{
    int i;
    int indexFilm = search_Film(Titel); //indexFilm stocheaza indexul in array-ul elem

    if(indexFilm !=-1) //daca ai gasit filmul
    {
        sizeRepo--;
        for(i = indexFilm; i < sizeRepo; i++)// decremetezi dimensiuena repo-ului pentru ca o sa stergi un film
            elem[i] = elem[i+1];// stergi filmul din repo (shiftezi la stanga in array-ul)
    }
    return true;
}

bool Repository::update_Film(string Titel, string Genre, int Erscheinungsjahr, int Anzahl_von_Likes, string Trailer, string neues_Genre, int neues_Erscheinungsjahr, int neues_Anzahl_von_Likes, string neues_Trailer)
{
    int indexFilm = search_Film(Titel); //indexFilm stocheaza indexul in array-ul elem

    if(indexFilm !=-1)//daca ai gasit filmul
    {
        //setezi noile campuri
        elem[indexFilm].setGenre(neues_Genre);
        elem[indexFilm].setErscheinungsjahr(neues_Erscheinungsjahr);
        elem[indexFilm].setAnzahl_von_Likes(neues_Anzahl_von_Likes);
        elem[indexFilm].setTrailer(neues_Trailer);
        return true;
    }
    return false;
}

std::vector<Film> Repository::getMoviesByGenre(std::string genre) const
{
    std::vector<Film> moviesWithGenre;
    // returneaza toate filmele cu un anumit genre
    for(int i = 0; i < sizeRepo; i++) // parsam toate filmele din repository
    {
        if(elem[i].getGenre() == genre)  // daca au genre-ul cerut
            moviesWithGenre.push_back(elem[i]); // le adaugam in vectorul filmelor cu genre
    }
    return  moviesWithGenre;
}
