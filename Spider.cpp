#include <iostream>
#include <time.h>
#include <stdlib.h>


#include "Spider.h"
using namespace std;

Spider::Spider(string N)
{
	name=N;
	hpMAX=rand()%4+4;
	hp=hpMAX;
	ap=5;
	size=1;
}

Spider::Spider(string N,int H,int S) 
{
	name=N;
	hpMAX=H;
	hp=hpMAX;
	size=S;
}

void Spider::eat(int flySize)
{
	if(hp==hpMAX)
		hpMAX+=flySize;
	else 
	{
		hpMAX+=(1-hp/hpMAX)*flySize; 
		hp+=flySize;
		if(hp>hpMAX)
			hp=hpMAX;
	}
	ap--;
}

void Spider::regeneration()
{
	if(hp<hpMAX)
	{
		hp+=((rand()%5+1)/100)*hpMAX;
		if(hp>hpMAX)
			hp=hpMAX;
	}
}



void Spider::buildWeb(int dura)
{	
	if(dura==100)
		dura+=((rand()%10+1)/100)*size;
	else
	{
		dura+=rand()%21;
		if(dura>100)
			dura=100;
	}

	ap--;
}

void Spider::attack(int enemyHP,int dura)
{
	int gamble=rand()%20+1;

	if(gamble==1)
		cout<<"Atak nie trafia w przeciwnika. ";
	else if (gamble==20)
	{
		cout<<"Trafienie krytyczne!!!(2x). ";
		enemyHP-=2*strike(); 
	}
	else
		enemyHP-=strike();

	if(rand()%10+1==10);
	{
		dura-=rand()%6;
		cout<<"Podczas ataku pajeczyna zostala uszkodzona o "<<dura<<" !"<<endl;
	}
}

int Spider::strike()
{
	return rand()%hpMAX*0.3;
}

int Spider::hpIndicator()
{
	return hp/hpMAX*100;
}

void Spider::description()
{
	cout<<name<<" HP: "<<hp<<" / "<<hpMAX<<endl;
}
