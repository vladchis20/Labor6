#include "Film.h"
#include "Repository.h"
#include "Controller.h"
#include "UserController.h"
#include "UI.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

int main()
{
    //Filmele care trebuie adaugate direct din cod
    Repository *f = new Repository();

    Film f1("Joker", "drama", 2019, 206, "www.Joker.com");
    Film f2("Colectiv", "documentar", 2019, 57, "www.Colectiv.com");
    Film f3("Parasite", "comedie", 2019, 328, "www.Parasite.com");
    Film f4("El reino", "thriller", 2018, 72, "www.El-reino.com");
    Film f5("Green Book", "biografic", 2018, 32, "www.Green-Book.com");
    Film f6("Bohemian Rhapsody", "biografic", 2018, 897, "www.Bohemian-Rhapsody.com");
    Film f7("Black Panther", "actiune", 2018, 100, "www.Black-Panther.com");
    Film f8("Dunkirk", "actiune", 2017, 87, "www.Dunkirk.com");
    Film f9("Coco", "animatie", 2017, 675, "www.Coco.com");
    Film f10("Loving Vincent", "biografic", 2017, 123, "www.Loving-Vincent.com");

    f->loadFromCSV("test.csv");

    Film filme;
    Controller *ctrl = new Controller(f);
    UserController userController(f);
    UI *ui = new UI(ctrl, &userController);
    ui->Hauptmenu(filme);

    return 0;
}
