#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <fstream>

#include "Spider.h"
#include "Web.h"
#include "Fly.h"

using namespace std;

void rupture(int D);
int  gamble();

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	vector<string> names;

	fstream plik;
	plik.open("enemies.txt",ios::in);
	if(plik.good()==false)
	{
		cout<<"Error!"<<endl;	exit(0);
	}
	string nameOfEnemy;
	while(getline(plik,nameOfEnemy))
		names.push_back(nameOfEnemy);
	
	Spider hero(argv[1]);
	Web home;

	int n=atoi(argv[2]);
	if(n<0)	
	{
		cout<<"Nieprawdilowe dane wejsciowe."<<endl;
		exit(0);
	}

	Fly *tabOfFlys=NULL;
	tabOfFlys=new Fly[n];
	vector<Fly> flys;

	int starving;
	while(hero.getHP())
	{
		//ile muszek sie zlapalo:
		{
			for(int i=0;i<rand()%n+1+home.getSize()*0.1;i++)
			{
				if(flys.size()==0&&gamble()>=20)
						flys.push_back(tabOfFlys[ rand()%n+1 ]);
				if(flys.size()<n) 
				{
					if(gamble()>=50)
						flys.push_back(tabOfFlys[ rand()%n+1 ]);
				}
			}
		}
		hero.ap=5;
		while(hero.ap)
		{
			//co robimy:
			if(hero.hpIndicator()<home.getDurability()&& flys.size()>0)
				{
					hero.eat(flys[ flys.size()-1 ].getSize());
					flys.pop_back();
					starving=0;

				}
			else if(hero.hpIndicator()<30&& flys.size()>0) 
				{
					hero.eat(flys[ flys.size()-1 ].getSize());
					flys.pop_back();
					starving=0;
				}
			else if(home.getDurability()<50)
					hero.buildWeb(home.getDurability());
			else 
					hero.buildWeb(home.getDurability());

			//walka:
			if(home.getSize()>20)
			{
				if(gamble()<=30+home.getSize()*0.1)
				{
					hero.ap=0;
					Spider mob(	names[ rand()%names.size() ],	rand()%hero.getHP()+0.1*hero.getHP()	,	rand()%hero.getSize()+0.1*hero.getSize() );	

					while(hero.getHP()>0&& mob.getHP()>0)
					{
						if(gamble()>50)
							hero.attack(mob.getHP(),home.getDurability());
						else
							mob.attack(hero.getHP(),home.getDurability());

						hero.description();cout<<" -/- ";mob.description();

						if(hero.hpIndicator()<=30&& gamble()<=10)
						{
							cout<<argv[1]<<" porzuca swoja siec. Zaczynasz budowe od poczatku."<<endl;
							flys.clear();
							Web home;
							break;
						}	
					}
				}
			}
	
		}

		hero.regeneration();	
		rupture(home.getDurability());
		hero.description();


		for(int i=flys.size();i>0;i--) //odpadajace muchy
		{
			flys[i].setRemain( flys[i].getRemain()+1 );
			if(flys[i].getRemain()==3)
				flys.pop_back();
		}

		//podsumowanie:


		home.webCondition();
		starving++;
		if(starving==3)
		{
			cout<<argv[1]<<" zmarl z glodu."<<endl;
			exit(0);
		}
	}
	delete[]tabOfFlys;
	flys.clear();
	return 0;
}

void rupture(int D)
{
	if(D<=0)
	{
		cout<<"Twoja pajeczyna sie zerwala!"<<endl;
		if(gamble()>=30)
		{
			cout<<"Udaje Ci sie uciec- zakladasz nowa siec";
			Web home;
		}
		else
		{
			cout<<"Pajak spada z pajeczyny i ginie ;("<<endl;
			exit(0);
		}
	} 
}

int  gamble()
{
	return rand()%100+1;
}


//pajczyna musi byc wieksza od pajaka minimum 3 krotnie wieksza 
//jezeli bedzie wieksza tylko o 10% i mniej 
//to w kazdej w kolejce dostaje 5-15 na minusie do duranb;

