#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>

#include "Spider.h"
using namespace std;

Spider::Spider(string N)
{
	name=N;
	hpMAX=rand()%4+4;
	hp=hpMAX;
	ap=rand()%7+2;
	size=rand()%2+1;
}

Spider::Spider(int H,int S) 
{
	enemies();
	name=names[ rand()%names.size() ];
	hpMAX=H;
	hp=hpMAX;
	size=S;
}

Spider::~Spider()
{
	names.clear();
}
//------
void Spider::eat(int flySize)
{
	if(hp==hpMAX)
	{
		size+=rand()%flySize+1;
		hpMAX+=rand()%flySize+1;
		hp=hpMAX;
	}
	else 
	{
		hp+=flySize;
		if(hp>hpMAX)
			hpMAX=hp;
	}
}

void Spider::regeneration()
{
	if(hp<hpMAX)
	{
		hp+=rand()%5+1;
		if(hp>hpMAX)
			hp=hpMAX;
	}
}

int Spider::hpIndicator()
{
	return hp/hpMAX*100;
}
//------
void Spider::enemies()
{
	fstream plik;
	plik.open("enemies.txt",ios::in);
	if(plik.good()==false)
	{
		cout<<"Error!"<<endl;
		exit(0);
	}
	string nameOfEnemy;
	while(getline(plik,nameOfEnemy))
		names.push_back(nameOfEnemy);
	plik.close();
}

void Spider::strike(int enemyStrike)
{
	hp-=enemyStrike;
	if(hp<0) hp=0;
}

int Spider::hit()
{
	return rand()%size+1;
}

void Spider::disaster(int dmg)
{
	hp-=dmg;
	if(hp<0) hp=0;
}

void Spider::description()
{
	cout<<name<<" ["<<hp<<"]/["<<size<<"]";
}