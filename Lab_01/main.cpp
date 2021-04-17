#include <iostream>
#include <cstring>

using namespace std;

class pracownik {
public: // Publiczne skladowe klasy
    pracownik(const char *, long, float); // Konstruktor klasy

    ~pracownik(void); // Destruktor klasy

    void inf_o_prac(void); // Metody klasy

    int zmien_pensje(float);

    long podaj_id(void);

private: // Prywatne skladowe klasy (niedostepne poza klasa)
    char imie_nazwisko[64];
    long ident_pracownika;
    float zarobki;
};

pracownik::pracownik(const char *imie_nazwisko, long ident_prac, float // Definicja konsturktora poza klasa
zarobki) {
    strcpy(pracownik::imie_nazwisko, imie_nazwisko);
    pracownik::ident_pracownika = ident_prac;
    if (zarobki < 15000)
        pracownik::zarobki = zarobki;
    else
        pracownik::zarobki = 0.0;
}

pracownik::~pracownik(void) { // Definicja destruktora poza klasa
    cout << "Usuwam obiekt: " << imie_nazwisko << endl;
}

void pracownik::inf_o_prac(void) { // Definicja metody poza klasa
    cout << "Imie i nazwisko: " << imie_nazwisko << endl;
    cout << "Identyfikator: " << ident_pracownika << endl;
    cout << "Zarobki: " << zarobki << endl;
}


int main(void) { // Glowna funkcja programy
    // Tworzenie objektow typu pracownik i wywolywanie metody klasy
    pracownik informatyk("Jan Kowalski", 101101, 4000.0);
    informatyk.inf_o_prac();
    pracownik technik("Marcin Zieliński", 331100, 4500.0);
    technik.inf_o_prac();
    pracownik kierownik("Alicja Nowak", 331200, 5000.0);
    kierownik.inf_o_prac();
}