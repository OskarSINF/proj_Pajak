#include <vector>
using namespace std;

/// \brief Defeinicja klasy Events- nieprzewidziane zdarzenie.
/// \details Klasa odpowiedzialna za tworzenie obietu, którego kolejne atrybuty wplywaja na glownego bohater symulacji.\n
/// Wszystkie atrybuty czytane sa pliku txt. Sa to:\n-description - opis zdarzenia,\n-chance - szansa na zaistnienie zdarzenia,\n
///-hp - wplyw zdarzenia na hp obiektu Spider,\n-size - wplyw zdarzenia na rozmiar obiekt Web.
class Events
{
	vector<string> line;
	string description;
	char bufor[5];
	int chance,hp,size;
	public:
	/// \brief Konstruktor zdarzenia, kolejne atrybuty przyjmuja odpowienie wartosci okreslone w pliku txt 
	Events();
	/// \brief Gettery szansy(chance) na zainstenie zdarzenia.
	int getChance(){return chance;}
	/// \brief Gettery wielkosci wplywajacej na hp obiektu Spider.
	int getHP(){return hp;}
	/// \brief Gettery wielkosci wplywajacej na rozmiar obiektu Web.
	int getSize(){return size;}
	/// \brief Gettery tekstu opisujacego nieprzewidziane zdarzenie.
	string getDescription(){return description;}

	/// \brief Metoda wywolywana w konstruktorze. Pobiera dane z pliku txt.
	void file();
};