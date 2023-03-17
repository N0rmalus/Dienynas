#include "header.h"

void generatorius(string failas, int kiek_studentu, int kiek_nd) {
    std::mt19937 mt(1729);
    std::uniform_int_distribution<int> dist(1, 10), sdist(1, kiek_studentu);

    ofstream failasO(failas);

    failasO << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde";
    for(int i = 1; i <= kiek_nd; i++) {
        failasO << setw(10) << right << ("ND" + to_string(i));
    }
    failasO << setw(10) << right << "Egz." << endl;

    for(int i = 1; i <= kiek_studentu; i++) {
        failasO << setw(15) << left << ("Vardas" + to_string(sdist(mt))) << setw(15) << left << ("Pavarde" + to_string(sdist(mt)));
        for (int j = 1; j <= kiek_nd; j++) {
            failasO << setw(10) << right << dist(mt);
        }
        failasO << setw(10) << right << dist(mt) << endl;
    }

    failasO.close();

    cout << "Baigta." << endl;
}