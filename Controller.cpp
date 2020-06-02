#include "Controller.h"

#include <iostream>
#include <string>
#include <vector>


#include "Film.h"
#include "Repository.h"
#include "RepositoryExceptions.h"
using namespace std;

Controller::Controller(Repository* r)
{
    f_repo = r;
}

Controller::~Controller()
{
    //dtor
}

//Administratormodus
void Controller::Film_hinzufugen(Film film)
{

    if(f_repo->search_Film(film.getTitel()) == -1) //daca filmul nu exista...
        f_repo->add_Film(film); // il adaug
    else //altfel se trimite mesaj ca filmul exista deja
    //    cout<<"Dises Film existiert schon! Bitte fugen Sie einen anderen an."; //asta e mesajul de eroare
        // daca filmul exista deja aruncam o exceptie
        throw DuplicateMovieException(film.getTitel());

}
void Controller::Film_loschen(Film film)
{
    if(f_repo->search_Film(film.getTitel()) == -1) //daca filmul nu exista...
        throw InexistentMovieException(film.getTitel()); //aruncam exceptie
        //cout<<"Dises Film existiert nicht! Bitte loschen Sie etwas was existiert."; //=> nu am ce sterge=> eroare
    else //altfel
    {
        f_repo->delete_Film(film.getTitel()); //sterge filmul
        cout<<"Das Film wurde geloscht"; //mesaj sa vad ca filmul a fost sters cu succes
    }
}
//aici trebuie sa pot modifica: Genre, Erscheinungsjahr, Anzahl_von_Likes, Trailer (Titel ramane "id-ul" dupa care identifica elemetul)
void Controller::Film_bearbeiten(Film film)
{
    if(f_repo->search_Film(film.getTitel()) == -1) //daca filmul cautat nu este gasit
        throw InexistentMovieException(film.getTitel()); //aruncam exceptie
        //cout<<"Dises Film existiert nicht! Bitte suchen Sie einen anderen Film."; //mesaj de eroare
    else //altfel...modific datele filmului
        f_repo->update_Film(film.getTitel(), film.getGenre(), film.getErscheinungsjahr(), film.getAnzahl_von_Likes(), film.getTrailer(),
                        film.getNeuesGenre(), film.getNeuesErscheinungsjahr(), film.getNeuesAnzahl_von_Likes(), film.getNeuesTrailer());
}
//aici trebuie afisate toate filmele existente
void Controller::Filme_anzusehen(Film film)
{
    f_repo->display_repo();
}
