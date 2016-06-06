#include <vector>
using namespace std;

class Spider
{
	string name;
	int hp,hpMAX,size;

	public:

	int ap;
	Spider(string N);	
	Spider(string N,int H,int S); 	
	int getHP(){return hp;}
	int getSize(){return size;}

	void eat(int flySize);
	int hpIndicator();
	void regeneration();
	void description();
	void buildWeb(int dura);

	void attack(int enemyHP,int dura);
	int strike();
};