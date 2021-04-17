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

    void
    printOpis();

    void printDane() {
        cout << " Metoda printDane klasy bazowej" << endl;
        cout << " imie nazwisko " << imie_nazwisko_ << endl;
        cout << " nr indeksu " << nr_indeksu_ << endl;
    }
};

class starosta : public student {
public:
    string email_ = "no@noemail";

    starosta(string imie_nazwisko, unsigned int nr_indeksu, string
    email);

    string Opis_ = "starosta grupy";

    void printDane();
};

starosta::starosta(string imie_nazwisko, unsigned int nr_indeksu, string email) :
        student(imie_nazwisko, nr_indeksu), email_(email) {
    cout << "Tworzenie obiektu klasy starosta o nazwie: " << Opis_ << endl;
}

void starosta::printDane() {
    student::printDane();
    cout << " email " << email_ << endl;
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
//    cout << "Dane:" << stud.imie_nazwisko_ << " " << stud.nr_indeksu_ << endl;
    starosta star("Aleksandra Nowak", 999, "mail@nomail.dot");
    star.printOpis();
//    cout << "Dane:" << star.imie_nazwisko_ << " " << star.nr_indeksu_ << endl;
    star.printDane();

    /*
     *  2.Przeanalizuj jego działanie. Zwróć uwagę jak tworzony jest nowy obiekt klasy pochodnej.
        Zmodyfikuj definicję klasy podstawowej tak, aby składowe imie_nazwisko i nr_indeksu
        były prywatne.
        3. Uruchom program. Czy jego działanie zmieniło się? Jaki z tego płynie wniosek?
        O: Tak jak skladowe prywatne to nie ma do nich dostempu zewnatrz klasy
     * */

    /*
     * 5. Dodaj metodę printDane() do klasy starosta, która uwzględni także email_. Czy dostęp
        do składowych imie_nazwisko i nr_indeksu jest możliwy? Popraw program, aby
        wyświetlał poprawnie wszystkie dane klasy starosta.

        O: Dostemp do skladowych klasy bazowej nie jest mozliwy, bo to sa skladowe prywatne w klasie bazowej;
        O2: Zeby wyswietlic wszytkie dane poprawnie mozna zmienic modyfikator dostempu na protected dla imienia i nr indeksu
        lub po prostu wywolac wersje metody klasy bazowej, i dodac nowa funkjonalnosc
     * */
}