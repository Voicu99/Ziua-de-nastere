// Ziua de nastere.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

class ZiuaNasterii {
private:
    int an;
    std::string luna;
    int zi;
public:
    ZiuaNasterii(int an, std::string luna, int zi) : an(an), luna(luna), zi(zi) {}

    int getAn() const {
        return an;
    }

    std::string getLuna() const {
        return luna;
    }

    int getZi() const {
        return zi;
    }
};

class Persoana {
private:
    std::string nume;
    std::string prenume;
    ZiuaNasterii ziuaNasterii;
public:
    Persoana(std::string nume, std::string prenume, ZiuaNasterii ziuaNasterii)
        : nume(nume), prenume(prenume), ziuaNasterii(ziuaNasterii) {}

    int varsta() const {
        auto acum = std::chrono::system_clock::now();
        auto acum_timp = std::chrono::system_clock::to_time_t(acum);
        std::tm timpCurent;
        gmtime_s(&timpCurent, &acum_timp);

        int anCurent = 1900 + timpCurent.tm_year;
        int lunaCurenta = 1 + timpCurent.tm_mon;
        int ziCurenta = timpCurent.tm_mday;

        return anCurent - ziuaNasterii.getAn();
    }

    std::string getNume() const {
        return nume;
    }
};

int main() {
    ZiuaNasterii ziNasterii(1999, "Noiembrie", 11);
    Persoana persoana("Voicu", "Librimir", ziNasterii);

    std::cout << "Varsta lui " << persoana.getNume() << " este " << persoana.varsta() << " ani." << std::endl;

    return 0;
}
