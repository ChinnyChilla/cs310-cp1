#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Movie.h"
using namespace std;

class MovieDatabase {

	public:
		vector<Movie> movies;
		vector<Actor> actors;
		MovieDatabase();
		int findMovieIndex(int movieId);
		int findActorIndex(int actorId);
		void addMovie(unsigned int movieid, unsigned int year, string dirlast, string dirfirst, string title);
		void addActor(unsigned int actorid, string first, string last);
		void removeMovie(unsigned int movieid);
		void addActorToMovie(unsigned int actorid, unsigned int movieid);
		void printCastOfMovie(unsigned int movieid);
		// void printMovieVector(vector<Movie> v);
		// void printActorVector(vector<Actor> v);
		
};