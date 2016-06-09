#include <vector>
using namespace std;

///	\brief Defeinicja klasy Spider- Pajak.
///	\details Klasa odpowiedzialna za tworzenie obietu, ktorego przedstawicielem jest glowny bohater symulacji oraz jego przeciwnicy.
///\n Klasa posiada atrybuty:\n-name - imie pajaka,\n-HP - aktualne pkt zycia\n-hpMAX - maksymalne hp jakie moze przyjac pajak,\n-size - rozmiar pajaka,\n-ap - punkty akcji do wykorzystania w czasie jednej tury.
class Spider
{
	string name;
	int hp,hpMAX,size,ap;
	vector<string> names;

	public:
	/// \brief Konstruktor glownego bohatera. \param N Jest to imie(name) pajaka. W main.cpp przyjmuje pierwszy argument wiersza polecen.
	Spider(string N);	
	/// \brief Konstruktor wrogow. \param H Ilosc HP pajaka. W main.cpp przyjmuje losowa wartosc. \param S rozmiar(size) pajaka. W main.cpp przyjmuje losowa wartosc.		
	Spider(int H,int S); 			
	/// \brief Destruktor czyszczacy wektor imion jakie moze przyjac przeciwnik.
	~Spider();						

	/// \brief Gettery aktualnego HP(hp) pajaka.
	int getHP(){return hp;}		
 	/// \brief Gettery aktualnego rozmiaru(size) pajaka. 
	int getSize(){return size;}	
	/// \brief Gettery Imienia(name) obiektu.		
	string getName(){return name;}	
	/// \brief Gettery ilosci punktow akcji(ap) obiektu.		 
	int getAP(){return ap;}				 

	/// \brief Metoda zwiekszajaca HP/hpMAX pajaka oraz jego rozmiar \param flySize Rozmiar muchy zlapanej na pajeczyne. 
	void eat(int flySize);
	/// \brief Regeneracja HP pajaka.
	void regeneration();
	/// \brief Metoda zwracajaca procentowa ilosc HP.
	int hpIndicator();

	/// \brief Metoda wywolywana w konstruktorze. Pobiera imiona z pliku txt.
	void enemies();
	/// \brief Metoda symuluje orzymywanie obrazen \param enemyStrike Sila uderzenia. Wielkosc jaka zostanie odjeta od HP obiektu.
	void strike(int enemyStrike);
	/// \brief Metoda okreslajaca sile uderzenia na podstawie rozmiaru pajaka.
	int hit();
	/// \brief Metoda okresla wplyw zdarzen nieprzeiwdzianych na obiekt.
	void disaster(int dmg);
	/// \brief Metoda wyslwitlajaca ważniejsze atrybuty obiektu. 
	void description();
};