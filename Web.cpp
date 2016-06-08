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

void Web::buildWeb(int spiederSize) 
{	
	if(durability==100)
		size+=rand()%spiederSize+1;
	else
	{
		durability+=rand()%spiederSize+1;
		if(durability>100)
			durability=100;
	}
}

void Web::extraSize(int extra)
{
	size+=extra;
	if(size<0) size=0;
}


void Web::webCondition()
{
	cout<<"#Rozmiar pajeczyny: "<<size<<". ";
	if(durability>=80) 				cout<<"Pajeczyna jest w idealnym stanie.";
	else if (durability<80&& durability>=50) 	cout<<"Pajeczyna jest w dobrym stanie.";
	else if (durability<50&& durability>=10) 	cout<<"Zly stan pajeczyny";
	else 					cout<<"Uwaga! Pajeczyna zaraz sie zerwie! ";
}

