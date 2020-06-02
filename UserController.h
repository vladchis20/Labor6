#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include "Film.h"
#include "Repository.h"

#include <vector>
#include <stdlib.h>
class UserController
{
    public:
        UserController(Repository* r);
        virtual ~UserController();

        // functie care ia din repository toate filmele de un anumit gen. In interior populeaza membrul de clasa m_selectedMovies
        void getMoviesByGenre(std::string genre);

        // functie care returneaza urmatorul film din vectorul m_selectedMovies
        Film &getNextMovie();

        // functie care adauga un film la watchlist
        bool addMovieToWatchlist();

        bool removeMovieFromWatchlist(std::string filmID, bool like);

        // functie care fiseaza toate filmele din watchlist, punctul 5
        void displayWatchlist();

        bool saveWatchlist(string filepath);

        void openWatchlist();
    private:
        Repository *m_repo;// acelasi repository ca pentru administrator, doar ca aici nu il modificam

        std::vector<Film> m_watchList;

        // filmele selectate de utilizator dupa genre
        std::vector<Film> m_selectedMovies;
        // controlerul o sa ii afiseze in bucla utilizatorului toate filmele din m_selectedMovies, pentru asta avem nevoie de un index pentru filmul curent pe care il afisam
        // indexul curent (din vectorul m_selectedMovies) , adica indexul filmului pe care il afiseaza utilizatorului
        int m_movieIndex;

};

#endif // USERCONTROLLER_H
