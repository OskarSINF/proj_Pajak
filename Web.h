class Web
{
	public:

	int size,durability;

	friend class Spider;
	Web();
	int getDurability(){return durability;}
	int getSize(){return size;}
	void setDurability(int d);
	void webCondition();
};
