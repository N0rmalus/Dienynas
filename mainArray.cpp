#include "libraries.h"

struct Studentas {
    string vardas, pavarde;
    int kiek_rez, egz_rez;
    int *rezultatai;
};

// Galutinio balo apskaičiavimas su rezultatų vidurkiu
double galutinisVid(Studentas studentas) {
    double suma = 0;
    for (int i = 0; i < studentas.kiek_rez; i++)
        suma += studentas.rezultatai[i];
    double vidurkis = suma / studentas.kiek_rez;

    return vidurkis * 0.4 + studentas.egz_rez * 0.6;
}
// Galutinio balo apskaičiavimas su rezultatų mediana
double galutinisMed(Studentas studentas) {
    sort(studentas.rezultatai, studentas.rezultatai + studentas.kiek_rez);

    double mediana;
    
    // Jei yra lyginis skaičius rezultatų, imamas dviejų vidurinių skaičių vidurkis, jei nelyginis, imamas vidurinis skaičius
    if (studentas.kiek_rez % 2 == 0) {
        mediana = (studentas.rezultatai[studentas.kiek_rez / 2 - 1] + studentas.rezultatai[studentas.kiek_rez / 2]) / 2.0;
    } else {
        mediana = studentas.rezultatai[studentas.kiek_rez / 2];
    }

    return mediana * 0.4 + studentas.egz_rez * 0.6;
}

int main() {
    int max_studentai = 5, kiek_studentai = 0, kiek_nd;
    double galutinis_vid, galutinis_med;

    Studentas *studentai = new Studentas[max_studentai];
    
    char pasirinkimas, pasirinkimas2;
    bool is_naujo = false, is_naujo2 = false;

    do {
        cout << "-----------------------------------------------------------------------" << endl;

        cout << "Iveskite studento varda: ";
        cin >> studentai[kiek_studentai].vardas;
        cout << "Iveskite studento pavarde: ";
        cin >> studentai[kiek_studentai].pavarde; cout << endl;

        int rez, egz_rez;
        studentai[kiek_studentai].kiek_rez = 0;
        studentai[kiek_studentai].rezultatai = new int[1];
        
        
        cout << "Ar norite, kad mokinio gautieji balai uz namu darbus bei egzamina butu generuojami atsitiktinai? (Y/N): ";
        cin >> pasirinkimas2;

        if(pasirinkimas2 == 'Y' || pasirinkimas2 == 'y') {
            cout << "-----------------------------------------------------------------------" << endl;

            do {
                try {
                    cout << "Iveskite [" << studentai[kiek_studentai].vardas << " " << studentai[kiek_studentai].pavarde << "] namu darbu rezultatu kieki, kuris bus atsitiktinai sugeneruotas: ";
                    cin >> kiek_nd; cout << endl; 
                    if(cin.fail()) {
                        throw invalid_argument("Klaida: ivestas neteisingas simbolis.");
                    } else {
                        break;
                    }
                } catch(const invalid_argument& e) {
                    cout << e.what() << endl;
                    cin.clear(); 
                    cin.ignore();
                }
            } while(true);

            // Generuojami atsitiktiniai namų darbų bei egzamino rezultatai
            mt19937 mt(1729);
            uniform_int_distribution<int> dist(1, 10);
            for(int i = 0; i < kiek_nd; i++) {
                studentai[kiek_studentai].kiek_rez++;
                rez = dist(mt);
                egz_rez = dist(mt);

                int *laik_rez = new int[studentai[kiek_studentai].kiek_rez];
                for (int i = 0; i < studentai[kiek_studentai].kiek_rez - 1; i++)
                    laik_rez[i] = studentai[kiek_studentai].rezultatai[i];

                laik_rez[studentai[kiek_studentai].kiek_rez - 1] = rez;
                delete[] studentai[kiek_studentai].rezultatai;
                studentai[kiek_studentai].rezultatai = laik_rez;

                cout << "Atsitiktinis [" << studentai[kiek_studentai].vardas << " " << studentai[kiek_studentai].pavarde << "] namu darbu rezultatas: " << rez << endl;
            }

            cout << endl << "Atsitiktinis [" << studentai[kiek_studentai].vardas << " " << studentai[kiek_studentai].pavarde << "] egzamino rezultatas: " << egz_rez << endl;


            studentai[kiek_studentai].egz_rez = egz_rez;
        } else if (pasirinkimas2 == 'N' || pasirinkimas2 == 'n') {
            cout << "-----------------------------------------------------------------------" << endl << endl;

            do {
                try {
                    cout << "Iveskite [" << studentai[kiek_studentai].vardas << " " << studentai[kiek_studentai].pavarde << "] namu darbo rezultata intervale [1; 10] (arba 0, jei daugiau nenorite vesti): ";
                    cin >> rez;

                    if(cin.fail()) {
                        throw invalid_argument("Klaida: ivestas neteisingas simbolis.");
                    } if(rez != 0 && rez > 0 && rez <= 10) {
                        studentai[kiek_studentai].kiek_rez++;

                        int *laik_rez = new int[studentai[kiek_studentai].kiek_rez];
                        for (int i = 0; i < studentai[kiek_studentai].kiek_rez-1; i++)
                            laik_rez[i] = studentai[kiek_studentai].rezultatai[i];

                        laik_rez[studentai[kiek_studentai].kiek_rez-1] = rez;
                        delete[] studentai[kiek_studentai].rezultatai;
                        studentai[kiek_studentai].rezultatai = laik_rez;
                    } else if(rez < 0 || rez > 10) {
                        cout << "Klaida: pazymys turi buti intervale [1; 10]." << endl;

                        continue;
                    } else if(rez == 0) {break;}  
                } catch(const invalid_argument& e) {
                    cout << e.what() << endl;
                    cin.clear(); 
                    cin.ignore();

                    is_naujo = true;
                }
            } while (rez != 0 || is_naujo != false);

            if(studentai[kiek_studentai].kiek_rez < 1) {
                cout << "Klaida: truksta rezultatu. [" << studentai[kiek_studentai].vardas << " " << studentai[kiek_studentai].pavarde << "] bus neirasytas." << endl;

                is_naujo = true;
            }
            cout << endl;

            do {
                try {
                    cout << "Iveskite [" << studentai[kiek_studentai].vardas << " " << studentai[kiek_studentai].pavarde << "] egzamino rezultata intervale [1; 10]: ";
                    cin >> egz_rez;
                    
                    if(cin.fail()) {
                        throw invalid_argument("Klaida: ivestas neteisingas simbolis.");
                    }
                } catch(const invalid_argument& e) {
                    cout << e.what() << endl;
                    cin.clear(); 
                    cin.ignore();
                } if(egz_rez > 0 && egz_rez <= 10) {
                    studentai[kiek_studentai].egz_rez = egz_rez;

                    break;
                } else if(egz_rez < 1 && egz_rez > 10) {
                    cout << "Klaida: rezultatas turi buti intervale [1; 10]." << endl;

                    continue;
                }
            } while(true);  
        } else {
            cout << "Tokio pasirinkimo [" << pasirinkimas2 << "] nera." << endl;

            is_naujo = true;
            continue;
        }

        cout << "-----------------------------------------------------------------------" << endl;

        do {
            cout << "Ar norite ivesti nauja studenta? (Y/N): ";
            cin >> pasirinkimas;

            if(pasirinkimas != 'N' && pasirinkimas != 'n' && pasirinkimas != 'Y' && pasirinkimas != 'y') {
                cout << "Tokio pasirinkimo [" << pasirinkimas << "] nera." << endl;
            } else {break;}
        } while(pasirinkimas != 'Y' || pasirinkimas != 'y');

        kiek_studentai++;
        if (kiek_studentai == max_studentai) {
            max_studentai *= 2;
            Studentas *temp_studentai = new Studentas[max_studentai];
            for (int i = 0; i < kiek_studentai; i++) {
                temp_studentai[i] = studentai[i];
            }
            delete[] studentai;
            studentai = temp_studentai;
        }

        is_naujo = false;
    } while(is_naujo || pasirinkimas == 'Y' || pasirinkimas == 'y');

    do {
        try {
            cout << endl << "Ar norite, kad galutini bala apskaiciuotu su mediana? (Y/N): ";
            cin >> pasirinkimas;

            if(cin.fail()) {
                throw invalid_argument("Klaida: ivestas neteisingas simbolis.");
            }
        } catch(const invalid_argument& e) {
            cout << e.what();
            cin.clear(); 
            cin.ignore();
        }

        cout << "-----------------------------------------------------------------------" << endl << endl;

        if(pasirinkimas == 'Y' || pasirinkimas == 'y') {
            // Mokinių duomenų išrašymas su medianos galutiniu balu
            cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(5) << left << "Galutinis (Med.)" << endl;
            cout << "---------------------------------------------------" << endl;
            for (int i = 0; i < kiek_studentai; i++) {
                if (studentai[i].kiek_rez <= 0) {continue;}

                double galutinis_med = galutinisMed(studentai[i]);
                cout << setw(15) << left << studentai[i].pavarde << setw(15) << left << studentai[i].vardas << setw(5) << left << fixed << setprecision(2) << galutinis_med << endl;

            }
            cout << "-----------------------------------------------------------------------" << endl;

            break;
        } if(pasirinkimas == 'N' || pasirinkimas == 'n') {
            // Mokinių duomenų išrašymas su vidurkio galutiniu balu
            cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(5) << left << "Galutinis (Vid.)" << endl;
            cout << "---------------------------------------------------" << endl;
            for (int i = 0; i < kiek_studentai; i++) {
                if (studentai[i].kiek_rez <= 0) {continue;}

                double galutinis_vid = galutinisVid(studentai[i]);
                cout << setw(15) << left << studentai[i].pavarde << setw(15) << left << studentai[i].vardas << setw(5) << left << fixed << setprecision(2) << galutinis_vid << endl;
            }
            cout << endl << "-----------------------------------------------------------------------" << endl;

            break;
        } else {
            cout << "Tokio pasirinkimo [" << pasirinkimas << "] nera." << endl;
            cout << endl << "Ar norite, kad galutini bala apskaiciuotu su mediana? (Y/N): ";
            cin >> pasirinkimas; cout << endl;
            
            continue;
        }
    } while(true);

    return 0;
}
