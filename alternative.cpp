#include "header.h"

void galutinis(vector<Studentas>& studentai) {
    for(int i = 0; i < studentai.size(); i++) {
        double vidurkis = 0;
        double mediana = 0;
        if(studentai[i].nd_rezultatai.size() > 0) {
            // Galutinio balo apskaičiavimas su rezultatų vidurkiu
            vidurkis = accumulate(studentai[i].nd_rezultatai.begin(), studentai[i].nd_rezultatai.end(), 0.0) / studentai[i].nd_rezultatai.size();

            // Galutinio balo apskaičiavimas su rezultatų mediana
            int dydis = studentai[i].nd_rezultatai.size();
            sort(studentai[i].nd_rezultatai.begin(), studentai[i].nd_rezultatai.end());

            // Jei yra lyginis skaičius rezultatų, imamas dviejų vidurinių skaičių vidurkis, jei nelyginis, imamas vidurinis skaičius
            if(dydis % 2 == 0) {
                mediana = (double)(studentai[i].nd_rezultatai[dydis / 2 - 1] + studentai[i].nd_rezultatai[dydis / 2]) / 2;
            } else {
                mediana = studentai[i].nd_rezultatai[dydis / 2];
            }
        }
        studentai[i].galutinis_med = 0.4 * mediana + 0.6 * studentai[i].egzamino_rezultatas;
        studentai[i].galutinis_vid = 0.4 * vidurkis + 0.6 * studentai[i].egzamino_rezultatas;
    }
}
void atsitiktiniai_rez(int nd_rezultatas, int egz_rez, int kiek_nd, Studentas& naujas_studentas) {
    cout << "-----------------------------------------------------------------------" << endl;
    do {
        try {
            cout << "Iveskite [" << naujas_studentas.vardas << " " << naujas_studentas.pavarde << "] namu darbu rezultatu kieki, kuris bus atsitiktinai sugeneruotas: ";
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
    std::mt19937 mt(1729);
    std::uniform_int_distribution<int> dist(1, 10);
    srand(time(NULL));
    for(int i = 0; i < kiek_nd; i++) {
        nd_rezultatas = dist(mt);
        egz_rez = dist(mt);

        cout << "Atsitiktinis [" << naujas_studentas.vardas << " " << naujas_studentas.pavarde << "] namu darbu rezultatas: " << nd_rezultatas << endl;

        // Atsitiktiniai rezultatai pridedami į vektoriaus pabaigą
        naujas_studentas.nd_rezultatai.push_back(nd_rezultatas);
    }

    naujas_studentas.egzamino_rezultatas = egz_rez;
    
    cout << endl << "Atsitiktinis [" << naujas_studentas.vardas << " " << naujas_studentas.pavarde << "] egzamino rezultatas: " << egz_rez << endl;
}
void rasomi_rez(bool is_naujo2, int nd_rezultatas, int egz_rez, Studentas& naujas_studentas) {
    cout << "-----------------------------------------------------------------------" << endl;
    do {
        try {
            cout << "Iveskite [" << naujas_studentas.vardas << " " << naujas_studentas.pavarde << "] namu darbo rezultata intervale [1; 10] (arba 0, jei daugiau nenorite vesti): ";
            cin >> nd_rezultatas;

            if(cin.fail()) {
                throw invalid_argument("Klaida: ivestas neteisingas simbolis.");
            } if(nd_rezultatas != 0 && nd_rezultatas > 0 && nd_rezultatas <= 10) {
                // Įvestas rezultatas pridedamas į vektoriaus pabaigą
                naujas_studentas.nd_rezultatai.push_back(nd_rezultatas);
            } else if(nd_rezultatas < 0 || nd_rezultatas > 10) {
                cout << "Klaida: pazymys turi buti intervale [1; 10]." << endl;

                continue;
            } else if(nd_rezultatas == 0) {break;}  
        } catch(const invalid_argument& e) {
            cout << e.what() << endl;
            cin.clear(); 
            cin.ignore();

            is_naujo2 = true;
        }
    } while (nd_rezultatas != 0 || is_naujo2 != false);

    do {
        try {
            cout << endl << "Iveskite [" << naujas_studentas.vardas << " " << naujas_studentas.pavarde << "] egzamino rezultata intervale [1; 10]: ";
            cin >> egz_rez;
            
            if(cin.fail()) {
                throw invalid_argument("Klaida: ivestas neteisingas simbolis.");
            }
        } catch(const invalid_argument& e) {
            cout << e.what() << endl;
            cin.clear(); 
            cin.ignore();
        } if(egz_rez > 0 && egz_rez <= 10) {
            naujas_studentas.egzamino_rezultatas = egz_rez;

            break;
        } else if(egz_rez < 1 && egz_rez > 10) {
            cout << "Klaida: rezultatas turi buti intervale [1; 10]." << endl;

            continue;
        }
    } while(true);  
}
void spausdinti(vector<Studentas>& studentai) {
    cout << "Rezultatas rezultatai.txt faile";
    ofstream raso("rezultatai.txt");

    // Mokinių duomenų išrašymas
    raso << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << "Galutinis (Med.)" << endl;
    raso << "--------------------------------------------------------------------" << endl;
    for (const auto& s : studentai) {
        if(s.nd_rezultatai.empty() || s.galutinis_vid <= 0 || s.galutinis_med <= 0) {continue;}
        raso << setw(15) << left << s.pavarde << setw(15) << left << s.vardas << setw(20) << left << fixed << setprecision(2) << s.galutinis_vid << fixed << setprecision(2) << s.galutinis_med << endl;
    }    
}