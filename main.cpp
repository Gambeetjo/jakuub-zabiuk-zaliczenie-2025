#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

int main() {

    std::srand(static_cast<unsigned int>(std::time(0)));


    const int MIN_LICZBA = 1;
    const int MAX_LICZBA = 100;


    const int szukanaLiczba = std::rand() % (MAX_LICZBA - MIN_LICZBA + 1) + MIN_LICZBA;

    int probaGracza;
    int liczbaProb = 0;
    bool odgadniete = false;

    std::cout << "Witaj w grze w zgadywanie liczb!" << std::endl;
    std::cout << "Komputer wylosowal liczbe miedzy " << MIN_LICZBA << " a " << MAX_LICZBA << "." << std::endl;
    std::cout << "Sprobuj ja odgadnac!" << std::endl;
    std::cout << "------------------------------------------" << std::endl;


    while (!odgadniete) {
        std::cout << "Podaj swoja liczbe: ";
        std::cin >> probaGracza;


        if (std::cin.fail()) {
            std::cout << "To nie jest poprawna liczba! Sprobuj ponownie." << std::endl;

            std::cin.clear();

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        liczbaProb++;
        if (probaGracza < szukanaLiczba) {
            std::cout << "Za malo! Moja liczba jest wieksza." << std::endl;
        } else if (probaGracza > szukanaLiczba) {
            std::cout << "Za duzo! Moja liczba jest mniejsza." << std::endl;
        } else {
            std::cout << "Gratulacje! Odgadles liczbe " << szukanaLiczba << "!" << std::endl;
            std::cout << "Zajelo Ci to " << liczbaProb << " prob." << std::endl;
            odgadniete = true;
        }
    }

    std::cout << "Dziekuje za gre!" << std::endl;

    return 0;
}
