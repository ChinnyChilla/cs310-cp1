#include <iostream>
#include <stdlib.h>
using namespace std;

class Actor
{
	public:
		int id;
		string first;
		string last;
		Actor();
		Actor(unsigned int id, string firstname, string lastname);
};