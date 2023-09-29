#include <iostream>
#include <stdlib.h>
#include "Movie.h"
using namespace std;

Movie::Movie(unsigned int id, unsigned int year, string directorLast, string directorFirst, string title )
{
	movieid = id;
	movieTitle = title;
	releaseYear = year;
	dirlast = directorLast;
	dirfirst = directorFirst;
	cast = new vector<Actor>;
}

Movie::Movie() {
	movieid = -1;
	movieTitle = "";
	releaseYear = 0;
	dirlast = "";
	dirfirst = "";
	cast = new vector<Actor>;
}
int Movie::getMovieId() {
	return movieid;
}
string Movie::getMovieTitle() {
	return movieTitle;
}
int Movie::findActorIndex(int actorid) {
	for (unsigned int i = 0; i < (*cast).size(); i++)
	{
		Actor curr = (*cast).at(i);
		if (curr.id == actorid)
		{
			return i;
		}
	}
	return -1;
}
void Movie::addActorToCast(Actor actor) {
	if (findActorIndex(actor.id) != -1) {
		cout << "join_cast: Error " << actor.first << " " << actor.last << " is already in the cast of " << movieTitle << endl;
		return;
	}
	(*cast).push_back(actor);
	cout << "join_cast: Added actor " << actor.first << " " << actor.last << " to the cast of " << movieTitle << endl;
	return;
}
void Movie::printCast() {
	cout << movieTitle << " features:" << endl;
	for (unsigned int i=0; i<(*cast).size(); i++) {
		Actor curr = (*cast).at(i);
		cout << "- " << curr.first << " " << curr.last << endl;
	}
	return;
}