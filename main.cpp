#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#include "Spider.h"
#include "Web.h"
#include "Fly.h"
#include "Events.h"

using namespace std;

void rupture(int D);
int gamble();
void afterDay(int FlysCatch,int size,const char* name,int eatenFlys,int addWeb );

int main(int argc, char const *argv[])
{
	system("clear");
	srand(time(NULL));
	int n=atoi(argv[2]);
	if(n<0)	
	{
		cout<<"Nieprawdilowe dane wejsciowe."<<endl;
		exit(0);
	}
	Spider Arek(argv[1]); 	
	Web home;

	Fly *tabOfFlys=NULL;
	tabOfFlys=new Fly[n];

	vector<Fly> flys;
	vector<Spider> hero;
	hero.push_back(Arek);

	cout<<"!!!@Projekt_Pajak by O.Szubert:\n \tZACZYNAMY!"<<endl<<"Twoja pajak : [HP/Size] ";hero[0].description();
	cout<<"\nDo wykorzystania "<<hero[0].getAP()<<" pkt akcji/ dzien. ";
	usleep(2000000);

	int starving=0,action,_round=1;
	while(hero[0].getHP()>0)
	{
		cout<<endl<<"@@@ Dzien: "<<_round<<":-------------------------------------------"<<endl;
		// ile muszek sie zlapalo:
		int trial=rand()%n+home.getSize();
		if(!trial<=n-flys.size())
			trial=n-flys.size();

		int FlysCatch=0;
		for(int i=0;i<trial;i++)
		{

			if( flys.size()==0&& gamble()<=70 )
			{
				flys.insert( flys.begin() , tabOfFlys[ rand()%n+1 ] );
				FlysCatch++;
			}
			else  
			{
				if(gamble()<=45)
				{
					flys.insert( flys.begin() , tabOfFlys[ rand()%flys.size() ] );
					FlysCatch++;			
				}
			}
		}
		action=hero[0].getAP();
		while(action) 
		{
			//co robimy:
			int eatenFlys=0,addWeb=0;
			if(home.getDurability()>=80&& hero[0].hpIndicator()>=80)
			{
				if(gamble()<50)
				{		
					if(!flys.size()==0) 
					{		
						hero[0].eat( flys[ flys.size() - 1 ].getSize() );
						flys.pop_back();
						action--;
						starving=0;
						eatenFlys++;
					}
				}
				else
				{
					home.buildWeb(hero[0].getSize());
					addWeb+=hero[0].getSize();
					action--;

				}
			}			
			else
			{
				if(home.getDurability()<hero[0].hpIndicator() )
				{
					if(!flys.size()==0)
					{
						hero[0].eat( flys[ flys.size() - 1 ].getSize() );
						flys.pop_back();
						action--;
						starving=0;
						eatenFlys++;
					}
				}
				else 
				{
					home.buildWeb(hero[0].getSize());
					addWeb+=hero[0].getSize();
					action--;

				}
			}

			//opis ile sie flys zlapalo i co robil dudus
			if(action==0)
				afterDay(FlysCatch,flys.size(),argv[1],eatenFlys,addWeb );
			//walka:
			if(home.getSize()>30)
			{
				afterDay(FlysCatch,flys.size(),argv[1],eatenFlys,addWeb );
				action=0;
				Spider mob(  rand()%hero[0].getHP()+1,	rand()%hero[0].getSize()+1 );
				int Fround=1,dmg=0,miss=0,critical=0,sumOfRebound=0;
				hero.push_back(mob);

				cout<<endl<<"-------------------------------------------------------"<<endl;
				cout<<"Uwaga! "<<hero[1].getName()<<" chce przejac Twoja pajeczyne."<<endl<<endl;

				cout<<hero[0].getName()<<" vs "; hero[1].description();
				cout<<endl;
				int i=0;
				if(gamble()<=45)
					i++;
				while(hero[0].getHP()>0 && hero[1].getHP()>0)
					{
						int _gamble=gamble(),hit=hero[i%2].hit();

						if(_gamble<=5)
							miss++;
						else if (_gamble==100)
						{
							hero[(i+1)%2].strike(2*hit);
							critical++;
							if(i%2==0)
								dmg+=hit;	
						}
						else
						{
							hero[(i+1)%2].strike(hit);
							if(i%2==0)
								dmg+=hit;							
						}

						if(gamble()<=5);
						{
							int rebound=rand()%2+1;
							sumOfRebound+=rebound;
							home.setDurability( home.getDurability()-rebound );
						}

						i++;
						Fround++;
					}
				//podusomowanie walki:
				cout<<"# Walka trwala: "<<Fround<<" tur. "<<argv[1]<<" Zadal "<<dmg<<" obrazen."<<endl
					<<"## Chybil "<<miss<<" razy. Zadal "<<critical<<" trafien krytycznych."<<endl
					<<"### W czasie walki pajeczyna zostala uszkodzona o "<<sumOfRebound<<" procent."<<endl<<endl;
				usleep(2000000);

				if(hero[0].getHP()<=0)
				{
					cout<<"Mimo to "<<argv[1]<<" zginal w walce. "<<endl;
					goto koniec;
				}
				else
				{
					cout<<"Wygrana! Teraz "<<argv[1]<<" posila sie zwlokami przeciwnika.";
					hero[0].eat( hero[1].getSize());
					hero.pop_back();
					starving=0;
				}
				usleep(2000000);

			}	
		}

		//nieprzewidziane zdarzenie:
		Events accident;
		if(gamble() <= accident.getChance() )
		{
			cout<<endl<<endl<<"@! Nie uwierzysz, ale: "<<endl;
			cout<<accident.getDescription();
			hero[0].disaster( accident.getHP() );
			home.extraSize( accident.getSize() );
		}

		hero[0].regeneration();	
		rupture(home.getDurability());

		//odpadajace muchy:
		for(int i=flys.size();i>0;i--) 
		{
			flys[i].remain++;
			if(flys[flys.size() - 1 ].remain==3)
				flys.pop_back();
		}
		//podsumowanie:
		cout<<endl<<endl<<"@@@@ Podsumowanie dnia:"<<endl<<argv[1]
			<<" ma "<< hero[0].getHP() <<"hp - "<< hero[0].hpIndicator()<< "% HP max"<<endl
			<<"Na sieci jest "<<flys.size()<<" x much."<<endl;	
		home.webCondition();
		cout<<endl<<"########################################################"<<endl;
		usleep(2000000);

		starving++;
		if(starving==3)
		{
			cout<<argv[1]<<" zmarl z glodu."<<endl;
			goto koniec;
		}
		_round++;
	}

	koniec: //podobno mozna uzywac w takich przypadkach petli goto 
	cout<<"\n \tKONIEC!"<<endl;
	delete[]tabOfFlys;
	flys.clear();
	hero.clear();

	return 0;
}

void rupture(int D)
{
	if(D<=0)
	{
		cout<<"Twoja pajeczyna sie zerwala!"<<endl;
		if(gamble()<=70)
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

int gamble()
{
	return rand()%100+1;
}

void afterDay(int FlysCatch,int size,const char* name,int eatenFlys,int addWeb )
{
	cout<<endl<<"# Na pajeczyne zlapalo sie "<<FlysCatch<<" x much."<<"Teraz jest ich "<<size<<endl
	<<"## "<<name<<" zjadl "<<eatenFlys<<" x much."<<endl
	<<"### Siec zostala rozubudowana o "<<addWeb ;
	usleep(2000000);
}