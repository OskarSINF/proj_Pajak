#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>

#include "Events.h"
using namespace std;

Events::Events()
{
	file();
	int n=line.size()-1;
	description=line[rand()% n];
	int i;
	for(i=0;i<5;i++)
		bufor[i]=description[i];
	chance=atoi(bufor);
	i++;
	for(int k=0;i<11;i++,k++)
		bufor[k]=description[i];
	hp=atoi(bufor);
	i++;
	for(int k=0;i<17;i++,k++)
		bufor[k]=description[i];
	size=atoi(bufor);

	description.erase(0,17);
}

void Events::file()
{
	fstream plik;
	plik.open("disaster.txt",ios::in);
	if(plik.good()==false)
	{
		cout<<"Error!"<<endl;
		exit(0);
	}
	string event;
	while(getline(plik,event))
		line.push_back(event);
	plik.close();
}