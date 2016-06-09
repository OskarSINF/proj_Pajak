#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "Fly.h"

using namespace std;

Fly::Fly()
{
	remain=0;
	size=rand()%3+3;
}