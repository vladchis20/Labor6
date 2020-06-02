#ifndef REPOSITORYEXCEPTIONS_H
#define REPOSITORYEXCEPTIONS_H

#include <exception>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RepositoryExceptions
{
    public:
        RepositoryExceptions();
        ~RepositoryExceptions();

        void ConsoleerrorChar();
        const char * what(){ return message.c_str();}
    protected:
        string message;
    private:
};

class DuplicateMovieException: public RepositoryExceptions
{
public:
    DuplicateMovieException(string movieTitle)
    {
        message = "Error! Dieses Film "+movieTitle+" existiert schon! ";
    }
};

class InexistentMovieException: public RepositoryExceptions
{
public:
    InexistentMovieException(string movieTitle)
    {
        message = "Error! Dieses Film "+movieTitle+" existiert nicht! ";
    }
};

#endif // REPOSITORYEXCEPTIONS_H
