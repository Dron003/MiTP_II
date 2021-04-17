#include<iostream>
#include<vector>
#include <algorithm>
#include <numeric>
#include <queue>

constexpr int QUEUE_MAX_SIZE = 8;
static_assert(QUEUE_MAX_SIZE > 1, "Kolejka musi mieć więcej 1 elementu");

void printVector(const std::vector<int>& v) {
    for (const auto n : v) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;
}

void printQueue(std::queue<int>& q) {
    for (int i = 0; i < q.size(); ++i) {
        std::cout << (q.front() + i) << ' ';
    }
    std::cout << std::endl;
}

void myInsert(std::queue<int>& q, int value) {
    while (q.size() >= QUEUE_MAX_SIZE) {
        q.pop();
    }
    q.push(value);
}

int main(){
    // Zmodyfikować kod programu z punktu 1 aby rozmiar wektora mógł być dynamiczny
    std::cout << "Podaj rozmiar vectora: ";
    int size;
    std::cin >> size;
    std::vector<int> v(size);

    if (size < 8) {
        std::cerr << "Rozmiar wektora musi byc wiekszy lub rowny 8" << std::endl;
        return EXIT_FAILURE;
    }

    // Uzupelnienie vectora
    std::iota(v.begin(), v.end(), 0);
    // Wypisz ilość elementów w wektorze

    std::cout << "Ilość elementów w wektorze: " << v.size() << std::endl;
    printVector(v);


    std::cout << "\nUsuń elementy od 3 do 7 i wyświetl wynik.\n";
    v.erase(v.begin() + 3, v.begin() + 8);
    printVector(v);

    std::cout << "\nUsuń ostatni element wektora i wyświetl wynik.\n";
    v.pop_back();
    printVector(v);

    std::cout << "\nWstaw na początek wektora liczbę 102 i wyświetl wynik.\n";
    v.insert(v.begin(), 102);
    printVector(v);

    std::cout << "\nWstaw na koniec wektora liczbę 110011 i wyświetl wynik.\n";
    v.insert(v.end(), 110011);
    printVector(v);

    std::cout << "\nZadanie 2.\n";

    std::queue<int> q;
    std::cout << "\nNapisz program wstawiający do kolejki liczby naturalne"
                 " od 1 do 12. Wyświetl zawartość kolejki na ekran.\n";
    for (int i = 1; i <= 12; ++i) {
        q.push(i);
    }

    printQueue(q);

    std::cout << "\nPodaj długość kolejki używając metody size.\n";
    std::cout << "Długość: " <<q.size() << std::endl;

    std::cout << "\nUsuń z kolejki 5 elementów. Wyświetl zawartość kolejki na ekran i podaj jej długość.\n";
    for (int i = 0; i < 5; ++i) {
        q.pop();
    }
    printQueue(q);
    std::cout << "Długość: " <<q.size() << std::endl;

    std::cout << "\nUzupełnić program o funkcje ograniczającą długość kolejki do zadanej wartości np. 6 i usuwającej\n"
                 "elementy przekraczające ograniczenie. W przypadku gdy przekroczone jest ograniczenie funkcja\n"
                 "ma wyświetlać informację, ze kolejka jest pełna a element jest usuwany.\n";

    std::cout << "\nWykorzystując opracowaną funkcję dodać do kolejki 4 elementy.\n";

    for (int i = 100; i >= 97; --i) {
        myInsert(q, i);
    }

    std::cout << "\nWyświetl zawartość kolejki na ekran i podaj jej długość.\n";
    printQueue(q);
    std::cout << "Długość: " << q.size() << std::endl;

    std::cout << "\nUsunąć z kolejki 2 elementy.\n";
    std::cout << "\nWyświetl zawartość kolejki na ekran i podaj jej długość.\n";
    for (int i = 0; i < 2; ++i) {
        q.pop();
    }
    printQueue(q);
    std::cout << "Długość: " << q.size() << std::endl;

    std::cout << "\nDodać do kolejki 7 elementów.\n";
    std::cout << "\nWyświetl zawartość kolejki na ekran i podaj jej długość.\n";

    for (int i = 200; i >= 194; --i) {
        myInsert(q, i);
    }
    printQueue(q);
    std::cout << "Długość: " << q.size() << std::endl;
    return EXIT_SUCCESS;
}