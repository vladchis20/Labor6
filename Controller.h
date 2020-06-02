#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Film.h"
#include "Repository.h"

#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Controller
{
    public:
        Controller(Repository* r);
        ~Controller();

        //Administratormodus
        void Film_hinzufugen(Film film);
        void Film_loschen(Film film);
        void Film_bearbeiten(Film film);
        void Filme_anzusehen(Film film);

    private:
        Repository* f_repo;
};

#endif // CONTROLLER_H
