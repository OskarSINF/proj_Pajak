
#Oskar Szubert
#Symulator Pająka:

###
- Na początku tworzony jest obiekt pająk, w klasie Pająk- posiadać on będzie atrybuty tj punkty akcji, hp  wielkość , siła ataku, współczynnik regeneracji oraz metody: atak, atak specjalny (trucizna),rage, regeneracja, budowanie sieci, odżywianie, ucieczka.

- Dodatkowo będzie istnieć klasa Pajęczyna o atrybutach: wielkość, wytrzymałość oraz metodzie: zerwanie.

- Na początku symulacji pająk będzie zaczynał na pajęczynie o określonej, <małej> wielkości. W każdej turze na pajęczyne losowo łapać się będą muchy oraz  inne większe owady np pszczoła.

- Spożywanie swoich zdobyczy będzie zwiększało statystyki naszego pająka. 

- Większy rozmiar tuptusia oznaczać będzie konieczność rozbudowy pajęczyny. Po przekroczeniu pewnej wielkości sieci- stanie się ona widzialna  dla innych pająków. Co zainizjuje walkę o pajęczyne.


###Dodatkowe informacje:
- Symulator będzie turówką, pająk posiada punkty akcji.
- Decyzja na co zostaną rozdzielone PA, zapadac będzie w oparciu o wartości: zdrowie(mało hp idź zjedz muche), stan pajęczyny(sieć się zarwie- idź ją napraw) - obliczane wg odpowiedniego algorytmu. 
- Złapane owady, jeżeli nie zostaną wykorzystane w przeciągu 1-3 tur odpadają z pajęczyny i przepadają.
- Pająk,  który nie jadł przez 2 (?) Tury ginie.
- Sieć może być niszczona: w czasie walki, w każdej turze od warunków zewnętrznych np deszcz, wiatr.
- Nie naprawiana sieć ulega zniszczeniu.
- W czasie walki i małej ilości hp pająk może uciec z pajęczyny i założyć nowa.
