#include <vector>
using namespace std;

class Spider
{
	string name;
	int hp,hpMAX,size,ap;
	vector<string> names;

	public:

	Spider(string N);	
	Spider(int H,int S); 

	~Spider();

	int getHP(){return hp;}
	int getSize(){return size;}
	string getName(){return name;}
	int getAP(){return ap;}

	void eat(int flySize);
	void regeneration();
	int hpIndicator();

	void enemies();
	void strike(int enemyStrike);
	int hit();
	int disaster(int dmg);

	void description();

};