#include <iostream>
#include <stdlib.h>
#include "MovieDatabase.h"

MovieDatabase::MovieDatabase() {

}

int MovieDatabase::findMovieIndex(int movieid)
{
	for (unsigned int i = 0; i < movies.size(); i++)
	{
		Movie curr = movies.at(i);
		if (curr.getMovieId() == movieid)
		{
			return i;
		}
	}
	return -1;
}
int MovieDatabase::findActorIndex(int actorid)
{
	for (unsigned int i = 0; i < actors.size(); i++)
	{
		Actor curr = actors.at(i);
		if (curr.id == actorid)
		{
			return i;
		}
	}
	return -1;
}
void MovieDatabase::addMovie(unsigned int movieid, unsigned int year, string dirlast, string dirfirst, string title) {
	if (findMovieIndex(movieid) != -1) {
		cout << "add_movie: Error movie id " << movieid << " already in use" << endl;
		return; 
	};
	Movie newMovie(movieid, year, dirlast, dirfirst, title);
	movies.push_back(newMovie);
	cout << "add_movie: " << "Added " << title << " (" << year << ") directed by " << dirfirst << " " << dirlast << endl;
	return;
}
void MovieDatabase::addActor(unsigned int actorid, string first, string last)
{
	if (findActorIndex(actorid) != -1)
	{
		cout << "register_actor: Error actor id " << actorid << " already in use" << endl;
		return;
	};
	Actor newActor(actorid, first, last);
	actors.push_back(newActor);
	cout << "register_actor: Registered actor " << newActor.first << " " << newActor.last << endl;
	return;
}

void MovieDatabase::removeMovie(unsigned int movieid) {
	int location = findMovieIndex(movieid);
	if (location == -1) {
		cout << "remove_movie: Error movie id " << movieid << " does not exist" << endl;
		return;
	}
	Movie movieToDelete = movies.at(location);
	cout << "remove_movie: Removed " << movieToDelete.getMovieTitle() << endl;
	movies.erase(movies.begin() + location);
	return;
}

void MovieDatabase::addActorToMovie(unsigned int actorid, unsigned int movieid) {
	int actorLocation = findActorIndex(actorid);
	if (actorLocation == -1) {
		cout << "join_cast: Error actor id " << actorid << " does not exist" << endl;
		return;
	}
	int movieLocation = findMovieIndex(movieid);
	if (movieLocation == -1) {
		cout << "join_cast: Error movie id " << movieid << " does not exist" << endl;
		return;
	}
	Movie currMovie = movies.at(movieLocation);
	Actor currActor = actors.at(actorLocation);
	currMovie.addActorToCast(currActor);
	return;
}
void MovieDatabase::printCastOfMovie(unsigned int movieid) {
	int location = findMovieIndex(movieid);
	if (location == -1) {
		cout << "cast: Error movie id " << movieid << " does not exist" << endl;
		return;
	}
	movies.at(location).printCast();
	return;
}
// void MovieDatabase::printMovieVector(vector<Movie> v) {
// 	cout << "starting " << endl;
// 	for (int i=0; i<v.size(); i++ ){
// 		cout << v.at(i).getMovieTitle() << endl;
// 	}
// 	cout << "end" << endl;
// 	return;
// }
// void MovieDatabase::printActorVector(vector<Actor> v)
// {
// 	cout << "starting " << endl;
// 	for (int i = 0; i < v.size(); i++)
// 	{
// 		cout << v.at(i).first << endl;
// 	}
// 	cout << "end" << endl;
// 	return;
// }