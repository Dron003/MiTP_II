#include <iostream>
using namespace std;
class urzadzenie
{
public:
    virtual int zapis(int id, string dane) = 0;
    virtual string odczyt(int id) = 0;
    virtual ~urzadzenie() {}
};
class dysk : public urzadzenie
{
private:
    int id_;
    string dane_;
public:
    dysk(int id);
    int zapis(int id, string dane);
    string odczyt(int id);
};
dysk::dysk(int id)
{
    cout << "Tworzenie obiektu klasy dysk " << endl;
    if (id > 0) {
        id_ = id;
    }
    else {
        id_ = -1;
    }
}
int dysk::zapis(int id, string dane)
{
    if (id_ == -1 || id != id_) {
        return -1;
    }
    dane_ = dane;
    cout << "zapis danych: " << dane << endl;
    return 1;
}
string dysk::odczyt(int id)
{
    if (id_ == -1 || id != id_)
        return "Pomylka";
    cout << "odczyt danych: " << dane_ << endl;
    return dane_;
}
int main()
{
     /*1. Czy program się kompiluje?
     O: Nie, bo nie mozna utworzyc objekt abstraktnegej klasy*/
    //    urzadzenie u;
    dysk d1(7);
    d1.zapis(7, "test 11");
    d1.odczyt(7);
}