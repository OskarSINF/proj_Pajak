class Fly
{
	int size,remain;
public:
	friend class Spider;
	Fly();
	void setRemain(int r);
	int getRemain(){return remain;}

	int getSize(){return size;}
};