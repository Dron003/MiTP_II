#include <iostream>

using namespace std;

class student {
public:
    student();

    string Opis_ = "student grupy";

    void printOpis();
};

class starosta : public student {
public:
    string Opis_ = "starosta grupy";

    void printOpis() over;
};

student::student() {
    cout << "Tworzenie obiektu klasy student o nazwie: " << Opis_ << endl;
}

void student::printOpis() {
    cout << "Opis: " << Opis_ << endl;
}

void starosta::printOpis() {
    cout << "Opis: " << Opis_ << endl;
}

int main() {
    /* Dlaczego program się nie kompiluje?
     * O: Program nie kompiluje się bo metoda printOpis jest prywatna;
     */
    student stud;
    stud.printOpis();

    /*
     * 3. Utwórz nowy obiekt klasy starosta i uruchom program. Jaki jest rezultat? Jaki z tego
    płynie wniosek?
     O: Klasa starosta wywoluje konstruktor klasy student
     4. Wywołaj dla niego metodę printOpis(). Jaki jest rezultat? Jaki z tego płynie wniosek?
     O: Klasa starosta wykorzystuje wersje metody klasy student
     */
    starosta starosta;
    starosta.printOpis();

    /*
     * 2. Wywołaj dla niego metodę printOpis(). Jaki jest rezultat? Jaki z tego płynie wniosek?
     * O: Pojawila sie nowa definicja metody i wywola sie ta ostatnia
     * */
}