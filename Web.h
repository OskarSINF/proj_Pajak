class Web
{
	int size,durability;

	public:
	Web();

	int getDurability(){return durability;}
	void setDurability(int d);

	int getSize(){return size;}

	void buildWeb(int spiederSize);
	void extraSize(int extra);
	void webCondition();
};
