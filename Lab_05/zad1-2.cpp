#include <iostream>

using namespace std;

class student {
private:
    string imie_nazwisko_ = "NO_NAME";
    unsigned int nr_indeksu_ = 0;
public:
    student(string imie_nazwisko, unsigned int
    nr_indeksu);

    string Opis_ = "student grupy";

    virtual void printOpis();

    void printDane() {
        cout << " Metoda printDane klasy bazowej" << endl;
        cout << " imie nazwisko " << imie_nazwisko_ << endl;
        cout << " nr indeksu " << nr_indeksu_ << endl;
    }
};

class funkcyjny {
public:
    funkcyjny(string Opis_ = "funkcyjny grupy");

    void poinformuj_grupe(string info);

    void poinformuj_prowadzacego(string info, string imie);
};

void funkcyjny::poinformuj_grupe(string info) {
    cout << "Uwaga grupa! " << info << endl;
}

void funkcyjny::poinformuj_prowadzacego(string info, string imie) {
    info.insert(info.begin(), ' ');
    cout << "Szanowny Panie,  " << imie << info << endl;
}

funkcyjny::funkcyjny(string Opis_) {
    cout << "Tworzenie obiektu klasy student o nazwie: " << Opis_ << endl;
}

class starosta : public student, public funkcyjny {
private:
    string email_ = "nouser@noemail";
public:
    starosta(string imie_nazwisko, unsigned int nr_indeksu, string email);

    string Opis_ = "starosta grupy";

    void printOpis() override;

    void printDane() {
        cout << " Metoda printDane klasy starosta" << endl;
        cout << " email " << email_ << endl;
        student::printDane();
    }
};

starosta::starosta(string imie_nazwisko, unsigned int nr_indeksu, string email) :
        student(imie_nazwisko, nr_indeksu), email_(email) {
    cout << "Tworzenie obiektu klasy starosta o nazwie: " << Opis_ << endl;
}

void starosta::printOpis() {
    cout << "Opis: " << Opis_ << endl;
}

student::student(string imie_nazwisko, unsigned int nr_indeksu) :
        imie_nazwisko_(imie_nazwisko) {
    nr_indeksu_ = nr_indeksu;
    cout << "Tworzenie obiektu klasy student o nazwie: " << Opis_ << endl;
}

void student::printOpis() {
    cout << "Opis: " << Opis_ << endl;
}

int main() {
    student stud("Jan Kowalski", 7);
    stud.printOpis();
    stud.printDane();
    starosta star("Aleksandra Nowak", 999, "mail@nomail.dot");
    star.printOpis();
    star.printDane();

    /*
     * 1. Zmodyfikuj klasę student aby metoda printOpis() była metodą wirtualną.
        2. Jak zmieni się działanie programu?
        O: Wywola sie najnowsza wersja metody printOpis(), zamiast metod klas bazowych
     */
}