#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "Web.h"
using namespace std;

Web::Web()
{
	durability=100;
	size=rand()%4+12;
}

void Web::setDurability(int d)
{
	durability=d;
}

void Web::webCondition()
{
	cout<<"#Rozmiar pajeczyny: "<<size<<". ";
	if(durability>=85) 				cout<<"Pajeczyna jest w idealnym stanie."<<endl;
	else if (durability<85&& durability>=50) 	cout<<"Pajeczyna jest w dobrym stanie."<<endl;
	else if (durability<50&& durability>=10) 	cout<<"Zly stan pajeczyny"<<endl;
	else 					cout<<"Uwaga! Pajeczyna zaraz sie zerwie! "<<endl;
}

