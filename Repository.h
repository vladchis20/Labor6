#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "Film.h"

#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Repository
{
    public:
        Repository();
        ~Repository();

        bool loadFromCSV(string csvPath);

        bool saveToCSV(string csvPath);

        bool add_Film(Film f);

        int search_Film(string x);

        bool delete_Film(string Titel);

        bool update_Film(string Titel, string Genre, int Erscheinungsjahr, int Anzahl_von_Likes, string Trailer, string neues_Genre, int neues_Erscheinungsjahr, int neues_Anzahl_von_Likes, string neues_Trailer);

        void display_repo()
        {
            for(int i=0; i<sizeRepo;i++)
            {
                cout<<elem[i].getTitel()<<" ";
                cout<<elem[i].getGenre()<<" ";
                cout<<elem[i].getErscheinungsjahr()<<" ";
                cout<<elem[i].getAnzahl_von_Likes()<<" ";
                cout<<elem[i].getTrailer()<<endl;
            }
        }

        std::vector<Film> getMoviesByGenre(std::string genre) const;

    private:
        int sizeRepo;
        int capRepo;
        Film* elem;
};

#endif // REPOSITORY_H
