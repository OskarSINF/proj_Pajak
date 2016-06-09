///	\brief Defeinicja klasy Web- Pajeczyna.
///	\details Klasa odpowiedzialna za tworzenie obietu pajeczyny.\n Klasa posiada atrybuty:\n-size - rozmiar pajeczyny,
/// \n-durability - wytrzymalosc pajeczyny mierzona w procentach.
class Web
{
	int size,durability;

	public:
	/// \brief Konstruktor obiektu. Wartosc wytzymalosci(durability) domyslenie okreslana jest na 100, 
	/// rozmiar(size) przyjmuje wartosc losowa. 
	Web();
	/// \brief Gettery wytrzymalosci pajeczyny(durability). 
	int getDurability(){return durability;}
	/// \brief Settery wytrzymalosci pajeczyny(durability). 
	void setDurability(int d);

	/// \brief Gettery rozmiaru pajeczyny(size).
	int getSize(){return size;}
	/// \brief Metoda pozwalajaca rozbudowac lub naprawic pajeczyne.
	void buildWeb(int spiederSize);
	/// \brief Metoda okresla wplyw zdarzen nieprzeiwdzianych na obiekt.	
	void extraSize(int extra);
	/// \brief Metoda wyslwitlajaca ważniejsze atrybuty obiektu.
	void webCondition();
};
