#ifndef UI_H
#define UI_H

#include "Film.h"
#include "Repository.h"
#include "Controller.h"
#include "UserController.h"

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

class UI
{
    public:
        UI(Controller* c, UserController* uc);
        ~UI();

        void Afisare_Exit();

        //Functii pentru Administratormodus

        void Afisare_Film_hinzufugen(Film film);

        void Afisare_Film_loschen(Film film);

        void Afisare_Film_bearbeiten(Film film);

        void Afisare_Film_anzusehen(Film film);

        void Administratormodus(Film film);

        void Afisare_openWatchlist(Film film);

        void Benutzermodus(Film film);

        void Benutzermodus_und_Watchliste(Film Film);

        void Hauptmenu(Film film);

    private:
        Controller* c;
        UserController* uc;
};

#endif // UI_H
