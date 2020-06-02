#include "UI.h"

#include "Film.h"
#include "Repository.h"
#include "RepositoryExceptions.h"
#include "Controller.h"
#include "UserController.h"

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

UI::UI(Controller* c, UserController* uc)
{
    this->c = c;
    this->uc = uc;
}

UI::~UI()
{
    //dtor
}

void UI::Afisare_Exit()
{
    exit(7);
    cout<<"Exit";
}

//Functii pentru Administratormodus
void UI::Afisare_Film_hinzufugen(Film film)
{
    string titel, genre, trailer;
    int erscheinungsjahr, anzahl_von_likes;
    cout<<"Titel: "; cin>>titel;
    film.setTitel(titel);
    cout<<"Genre: "; cin>>genre;
    film.setGenre(genre);
    cout<<"Erscheinungsjahr: "; cin>>erscheinungsjahr;
    film.setErscheinungsjahr(erscheinungsjahr);
    cout<<"Anzahl_von_Likes: "; cin>>anzahl_von_likes;
    film.setAnzahl_von_Likes(anzahl_von_likes);
    cout<<"Trailer: "; cin>>trailer;
    film.setTrailer(trailer);
    //ne ocupam de exceptie
    try{
    c->Film_hinzufugen(film);
    }catch(RepositoryExceptions &repoE){
        cout<<"Oops!! Exception occured: "<<repoE.what()<<endl;
    }
    cout<<endl<<"Bitte ihre nachste Option einfugen: "; //asa se pot efectua alte comenzi
}

void UI::Afisare_Film_loschen(Film film)
{
    string titel, genre, trailer;
    int erscheinungsjahr, anzahl_von_likes;
    cout<<"Bitte den Titel des Filmes geben welches Sie loschen wollen: "; cin>>titel;
    film.setTitel(titel);
    //ne ocupam de exceptie
    try{
        c->Film_loschen(film);
    }catch(RepositoryExceptions &repoE){
        cout<<"Oops!! Exception occured: "<<repoE.what()<<endl;
    }
    cout<<"Bitte ihre nachste Option einfugen: "; //asa se pot efectua alte comenzi
}

void UI::Afisare_Film_bearbeiten(Film film)
{
    string titel, genre, trailer;
    int erscheinungsjahr, anzahl_von_likes;
    cout<<"Bitte den Titel des Filmes geben welches Sie bearbeiten wollen: "; cin>>titel;
    cout<<"Bitte den neuen Genre des Filmes geben: "; cin>>genre;
    film.setGenre(genre); //aici cred ca ar trebui sa pun si "titel" ca identificator
    cout<<"Bitte den neuen Erscheinungsjahr des Filmes geben: "; cin>>erscheinungsjahr;
    film.setErscheinungsjahr(erscheinungsjahr);
    cout<<"Bitte den neuen Anzahl von Likes des Filmes geben: "; cin>>anzahl_von_likes;
    film.setAnzahl_von_Likes(anzahl_von_likes);
    cout<<"Bitte den neuen Trailer des Filmes geben: "; cin>>trailer;
    film.setTrailer(trailer);
    //ne ocupam de exceptie
    try{
        c->Film_bearbeiten(film);
    }catch(RepositoryExceptions &repoE){
        cout<<"Oops!! Exception occured: "<<repoE.what()<<endl;
    }
    //deoarece nu era specificat, am gandit o varianta in care sa modifici toate "campurile" unui film deodata
    cout<<"Bitte ihre nachste Option einfugen: "; //asa se pot efectua alte comenzi
}

void UI::Afisare_Film_anzusehen(Film film)
{
    string titel, genre, trailer;
    int erscheinungsjahr, anzahl_von_likes;
    cout<<"Die existierende Filme sind: "<<endl;
    c->Filme_anzusehen(film);
    cout<<"Bitte ihre nachste Option einfugen: "; //asa se pot efectua alte comenzi
}

void UI::Administratormodus(Film film)
{
    int opt;
    cout<<endl;
    cout<<"Administratormodus"<<endl;
    cout<<"Fur Film_hinzufugen => Taste 1"<<endl;
    cout<<"Fur Film_loschen => Taste 2"<<endl;
    cout<<"Fur Film_bearbeiten => Taste 3"<<endl;
    cout<<"Fur Film_anzusehen => Taste 4"<<endl;
    cout<<"Fur Hauptmenu => Taste 5"<<endl;
    cout<<"Ihre Option ist: ";
    do
    {
        cin>>opt;
        switch(opt)
        {
            case 1: Afisare_Film_hinzufugen(film); break;
            case 2: Afisare_Film_loschen(film); break;
            case 3: Afisare_Film_bearbeiten(film); break;
            case 4: Afisare_Film_anzusehen(film); break;
            case 5: Hauptmenu(film); break;
        }
    }while(true);
}

void UI::Afisare_openWatchlist(Film film)
{
    uc->openWatchlist();
}

void UI::Benutzermodus(Film film)
{
    string titel, genre, trailer;
    int erscheinungsjahr, anzahl_von_likes;
    cout<<"Bitte den Genre der Filme die Sie sehen wollen einfugen: "; cin>>genre; //se citeste genul filmelor care vor fi afisate
    uc->getMoviesByGenre(genre);
    do
    {
        cout<<"\nWahlen was Sie machen wollen: 1 - nachstes Film ansehen, 2 - zum Watchliste einfugen,  3 - stop, 4 - Watchliste zeigen, 5 - Hauptmenu\n";
        int cmd;
        cin>>cmd;
        if(cmd == 1)
        {
            Film f = uc->getNextMovie();
            cout<<f;
        }
        if(cmd == 2){
            uc->addMovieToWatchlist();
        }

        if(cmd == 3)
        {
            break;
        }
        if(cmd == 4){
            uc->displayWatchlist();
        }
        if(cmd == 5){
            Hauptmenu(film);
        }
    }while(true);
}

void UI::Benutzermodus_und_Watchliste(Film film)
{
    int opt;
    cout<<endl;
    cout<<"Benutzermodus und Watchliste"<<endl;
    cout<<"Fur Benutzermodus => Taste 1"<<endl;
    cout<<"Fur Watchliste => Taste 2"<<endl;
    cout<<"Fur Hauptmenu => Taste 3"<<endl;
    cout<<"Ihre Option ist: ";
    do
    {
        cin>>opt;
        switch(opt)
        {
            case 1: Benutzermodus(film); break;
            case 2: Afisare_openWatchlist(film); break;
            case 3: Afisare_Exit(); break;
        }
    }while(true);
}

void UI::Hauptmenu(Film film)
{
    int opt;
    cout<<endl;
    cout<<"Hauptmenu"<<endl;
    cout<<"Fur Administratormodus => Taste 1"<<endl;
    cout<<"Fur Benutzermodus und Watchliste => Taste 2"<<endl;
    cout<<"Fur Beenden des Programms => Taste 3"<<endl;
    cout<<"Ihre Option ist: ";
    do
    {
        cin>>opt;
        switch(opt)
        {
            case 1: Administratormodus(film); break;
            case 2: Benutzermodus_und_Watchliste(film); break;
            case 3: Afisare_Exit(); break;
        }
    }while(true);
}
