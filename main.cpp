#include "libraries.h"

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> nd_rezultatai;
    int egzamino_rezultatas;
    double galutinis_vid, galutinis_med;
};

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

int main() {
    vector<Studentas> studentai;
    int kiek_nd;
    string vardas, pavarde, failas;
    char pasirinkimas, pasirinkimas2, skaityti;
    bool is_naujo = false, is_naujo2 = false;

    do {
        cout << "-----------------------------------------------------------------------" << endl;
        cout << "Duomenis skaityti is failo? (Y/N): ";
        cin >> skaityti;

        if(skaityti == 'Y' || skaityti == 'y') {
            cout << endl << "Failu sarasas: "; system("ls *.txt");
            cout << "Pasirinkite faila: ";
            cin >> failas;

            ifstream skaito(failas);
            if(!skaito.is_open()) {
                cout << "Klaida: tokio failo [" << failas << "] nera." << endl;
                
                is_naujo = true;
                continue;
            } else {
                // Praleisti pirmą eilutę
                string headers;
                getline(skaito, headers);

                while (skaito >> vardas >> pavarde) {
                    Studentas naujas_studentas;
                    naujas_studentas.vardas = vardas;
                    naujas_studentas.pavarde = pavarde;

                    int nd_rezultatas;

                    while (skaito >> nd_rezultatas) {
                        if (nd_rezultatas < 1 || nd_rezultatas > 10) {continue;}
                        naujas_studentas.nd_rezultatai.push_back(nd_rezultatas);
                        if (skaito.peek() == '\n') {break;}
                    }

                    if (naujas_studentas.nd_rezultatai.empty()) {
                        cout << "Nerasta rezultatu [" << naujas_studentas.vardas << " " << naujas_studentas.pavarde << "]" << endl;
                        continue;
                    }
                    naujas_studentas.egzamino_rezultatas = naujas_studentas.nd_rezultatai.back();
                    naujas_studentas.nd_rezultatai.pop_back();

                    studentai.push_back(naujas_studentas);
                }

                cout << "-----------------------------------------------------------------------" << endl;

                skaito.close();
                break;
            }
        } else if (skaityti == 'N' || skaityti == 'n') {
            do {
                cout << "-----------------------------------------------------------------------" << endl;

                cout << "Iveskite studento varda: ";
                cin >> vardas;
                cout << "Iveskite studento pavarde: ";
                cin >> pavarde; cout << endl;

                Studentas naujas_studentas;
                naujas_studentas.vardas = vardas;
                naujas_studentas.pavarde = pavarde;

                int nd_rezultatas, egz_rez;

                cout << "Generuoti mokinio rezultatus atsitiktinai? (Y/N): ";
                cin >> pasirinkimas2;

                if(pasirinkimas2 == 'Y' || pasirinkimas2 == 'y') {
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
                } else if (pasirinkimas2 == 'N' || pasirinkimas2 == 'n') {
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
                } else {
                    cout << "Tokio pasirinkimo [" << pasirinkimas2 << "] nera." << endl;

                    is_naujo = true;
                    continue;
                }

                if(naujas_studentas.nd_rezultatai.size() < 1) {
                    cout << "Klaida: truksta rezultatu. [" << naujas_studentas.vardas << " " << naujas_studentas.pavarde << "] bus neirasytas." << endl;
                }

                cout << "-----------------------------------------------------------------------" << endl;

                studentai.push_back(naujas_studentas);

                do {
                    cout << "Ar norite ivesti nauja studenta? (Y/N): ";
                    cin >> pasirinkimas;

                    if(pasirinkimas != 'N' && pasirinkimas != 'n' && pasirinkimas != 'Y' && pasirinkimas != 'y') {
                        cout << "Tokio pasirinkimo [" << pasirinkimas << "] nera." << endl;
                    } else {break;}
                } while(true);

                is_naujo = false;
            } while(is_naujo || pasirinkimas == 'Y' || pasirinkimas == 'y');
        } else {
            cout << "Tokio pasirinkimo [" << skaityti << "] nera." << endl;

            is_naujo = true;
        }
    } while(is_naujo);

    galutinis(studentai);
    sort(studentai.begin(), studentai.end(), [](const Studentas& s1, const Studentas& s2) { 
        return s1.vardas < s2.vardas; 
    });

    cout << "Rezultatas rezultatai.txt faile";
    ofstream raso("rezultatai.txt");

    // Mokinių duomenų išrašymas
    raso << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << "Galutinis (Med.)" << endl;
    raso << "--------------------------------------------------------------------" << endl;
    for (const auto& s : studentai) {
        if(s.nd_rezultatai.empty() || s.galutinis_vid <= 0 || s.galutinis_med <= 0) {continue;}
        raso << setw(15) << left << s.pavarde << setw(15) << left << s.vardas << setw(20) << left << fixed << setprecision(2) << s.galutinis_vid << fixed << setprecision(2) << s.galutinis_med << endl;
    }    

    return 0;
}
