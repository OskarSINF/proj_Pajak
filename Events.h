#include <vector>
using namespace std;

class Events
{
	vector<string> line;
	string description;
	char bufor[5];
	int chance,hp,size;
	public:
	Events();

	int getChance(){return chance;}
	int getHP(){return hp;}
	int getSize(){return size;}

	string getDescription(){return description;}
	
	void file();
};