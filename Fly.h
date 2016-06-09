///	\brief Definicja klasy Flys- Mucha.
///	\details Klasa odpowiedzialna za tworzenie obietu o atrybutach size oraz remain. Okreslajacy czas przyczpu muchy do pajeczyny 
class Fly
{
	int size;;
	public:
	int remain;
	/// \brief Konstruktor obiektu. Rozmiaru(size) muchy. przyjmuje wartosc losowa.  
	Fly();
	/// \brief Gettery rozmiaru(size) muchy. 
	int getSize(){return size;}
};