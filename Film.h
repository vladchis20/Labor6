#ifndef FILM_H
#define FILM_H

#include <iostream>
#include <string>

#include <vector>
#include <algorithm>
#include <ostream>
#include <iomanip>
using namespace std;

class Film
{
    public:
        Film();
        Film(string Titel, string Genre, int Erscheinungsjahr, int Anzahl_von_Likes, string Trailer);
        ~Film();

        //setteri
        void setTitel(string Titel);
        void setGenre(string Genre);
        void setErscheinungsjahr(int Erscheinungsjahr);
        void setAnzahl_von_Likes(int Anzahl_von_Likes);
        void setTrailer(string Trailer);

        //getteri
        string getTitel();
        string getGenre();
        int getErscheinungsjahr();
        int getAnzahl_von_Likes();
        string getTrailer();

        //getteri NEU
        string getNeuesGenre();
        int getNeuesErscheinungsjahr();
        int getNeuesAnzahl_von_Likes();
        string getNeuesTrailer();

        // overloading la operatorul de insertie in stream, pentru ca sa putem afisa un film cu cout<<film;
        friend ostream& operator<<(ostream& s, const Film &f);

        friend istream& operator>>(istream& s,  Film &f);
    private:
        std::string Titel;
        string Genre;
        int Erscheinungsjahr;
        int Anzahl_von_Likes;
        string Trailer;
};

#endif // FILM_H
