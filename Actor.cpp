#include <iostream>
#include <stdlib.h>
#include "Actor.h"
using namespace std;

Actor::Actor(unsigned int actorid, string firstname, string lastname) {
	id = actorid;
	first = firstname;
	last = lastname;
}
Actor::Actor() {
	id = -1;
	first = "NoName";
	last = "NoName";
}

