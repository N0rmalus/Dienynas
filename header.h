#include "libraries.h"

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> nd_rezultatai;
    int egzamino_rezultatas;
    double galutinis_vid, galutinis_med;
};

void galutinis(vector<Studentas>& studentai);
void atsitiktiniai_rez(int nd_rezultatas, int egz_rez, int kiek_nd, Studentas& naujas_studentas);
void rasomi_rez(bool is_naujo2, int nd_rezultatas, int egz_rez, Studentas& naujas_studentas);
void spausdinti(vector<Studentas>& studentai);