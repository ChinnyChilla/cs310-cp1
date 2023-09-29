#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Actor.h"
using namespace std;
class Movie 
{
	public:
		Movie();
		Movie(unsigned int movieid, unsigned int year, string dirlast, string dirfirst, string title);
		int getMovieId();
		void addActorToCast(Actor actor);
		int findActorIndex(int actorid);
		string getMovieTitle();
		void printCast();
	
	private:
		unsigned int movieid = 0;
		string movieTitle = "";
		unsigned int releaseYear = 0;
		string dirlast = "";
		string dirfirst = "";
		vector<Actor> *cast;
};	