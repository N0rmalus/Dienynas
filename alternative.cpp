#include "header.h"

void galutinis(studentaiVector& studentai) {
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

// auto sRusiavimas = std::chrono::system_clock::now(), eRusiavimas = std::chrono::system_clock::now();
void isvesti(studentaiVector& studentai) {
    ofstream rasoL("luzeriai.txt");
    ofstream rasoW("neluzeriai.txt");

    vector<Studentas> luzeriai;
    vector<Studentas> neluzeriai;

    rasoL << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << "Galutinis (Med.)" << endl;
    rasoW << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << "Galutinis (Med.)" << endl;
    rasoL << "--------------------------------------------------------------------" << endl;
    rasoW << "--------------------------------------------------------------------" << endl;

    // Mokinių rūšiavimas pagal galutinius pažymius
    auto sRusiavimas = std::chrono::system_clock::now();
    for(const auto& s : studentai) {
        if(s.galutinis_vid < 5.0 && s.galutinis_med < 5.0) {luzeriai.push_back(s);}
        if(s.galutinis_vid >= 5.0 && s.galutinis_med >= 5.0) {neluzeriai.push_back(s);}
    }   
    auto eRusiavimas = std::chrono::system_clock::now();
    std::chrono::duration<double> dRusiavimas = eRusiavimas - sRusiavimas;

    cout << "Rusiavimas baigtas per " << dRusiavimas.count() << "s." << endl;

    // Surūšiuotų mokinių duomenų išrašymas į skirtingus failus
    auto sIsvestis = std::chrono::system_clock::now();
    for(const auto& l : luzeriai) {
        if(l.nd_rezultatai.empty() || l.galutinis_vid <= 0 || l.galutinis_med <= 0) {continue;}
        rasoL << setw(15) << left << l.pavarde << setw(15) << left << l.vardas << setw(20) << left << fixed << setprecision(2) << l.galutinis_vid << fixed << setprecision(2) << l.galutinis_med << endl;
    } for(const auto& w : neluzeriai) {
        if(w.nd_rezultatai.empty() || w.galutinis_vid <= 0 || w.galutinis_med <= 0) {continue;}
        rasoW << setw(15) << left << w.pavarde << setw(15) << left << w.vardas << setw(20) << left << fixed << setprecision(2) << w.galutinis_vid << fixed << setprecision(2) << w.galutinis_med << endl;
    }
    auto eIsvestis = std::chrono::system_clock::now();
    std::chrono::duration<double> dIsvestis = eIsvestis - sIsvestis;

    cout << "Israsymas baigas per " << dIsvestis.count() << "s. Rezultatas luzeriai.txt / neluzeriai.txt failuose.";

    rasoL.close();
    rasoW.close();
}

// List
void galutinisList(list<Studentas>& studentai) {
    for(auto it = studentai.begin(); it != studentai.end(); ++it) {
        double vidurkis = 0;
        double mediana = 0;
        if(it->nd_rezultatai.size() > 0) {
            // Galutinio balo apskaičiavimas su rezultatų vidurkiu
            vidurkis = accumulate(it->nd_rezultatai.begin(), it->nd_rezultatai.end(), 0.0) / it->nd_rezultatai.size();

            // Galutinio balo apskaičiavimas su rezultatų mediana
            int dydis = it->nd_rezultatai.size();
            vector<int> nd_copy(it->nd_rezultatai.begin(), it->nd_rezultatai.end());
            sort(nd_copy.begin(), nd_copy.end());

            // Jei yra lyginis skaičius rezultatų, imamas dviejų vidurinių skaičių vidurkis, jei nelyginis, imamas vidurinis skaičius
            if(dydis % 2 == 0) {
                mediana = (double)(nd_copy[dydis / 2 - 1] + nd_copy[dydis / 2]) / 2;
            } else {
                mediana = nd_copy[dydis / 2];
            }
        }
        it->galutinis_med = 0.4 * mediana + 0.6 * it->egzamino_rezultatas;
        it->galutinis_vid = 0.4 * vidurkis + 0.6 * it->egzamino_rezultatas;
    }
}
void isvestiList(list<Studentas>& studentai) {
    ofstream rasoL("luzeriai.txt");
    ofstream rasoW("neluzeriai.txt");

    list<Studentas> luzeriai;
    list<Studentas> neluzeriai;

    rasoL << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << "Galutinis (Med.)" << endl;
    rasoW << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << "Galutinis (Med.)" << endl;
    rasoL << "--------------------------------------------------------------------" << endl;
    rasoW << "--------------------------------------------------------------------" << endl;

    // Mokinių rūšiavimas pagal galutinius pažymius
    auto sRusiavimas = std::chrono::system_clock::now();
    for(const auto& s : studentai) {
        if(s.galutinis_vid < 5.0 && s.galutinis_med < 5.0) {luzeriai.push_back(s);}
        if(s.galutinis_vid >= 5.0 && s.galutinis_med >= 5.0) {neluzeriai.push_back(s);}
    }   
    auto eRusiavimas = std::chrono::system_clock::now();
    std::chrono::duration<double> dRusiavimas = eRusiavimas - sRusiavimas;

    cout << "Rusiavimas baigtas per " << dRusiavimas.count() << "s." << endl;

    // Surūšiuotų mokinių duomenų išrašymas į skirtingus failus
    auto sIsvestis = std::chrono::system_clock::now();
    for(const auto& l : luzeriai) {
        if(l.nd_rezultatai.empty() || l.galutinis_vid <= 0 || l.galutinis_med <= 0) {continue;}
        rasoL << setw(15) << left << l.pavarde << setw(15) << left << l.vardas << setw(20) << left << fixed << setprecision(2) << l.galutinis_vid << fixed << setprecision(2) << l.galutinis_med << endl;
    } for(const auto& w : neluzeriai) {
        if(w.nd_rezultatai.empty() || w.galutinis_vid <= 0 || w.galutinis_med <= 0) {continue;}
        rasoW << setw(15) << left << w.pavarde << setw(15) << left << w.vardas << setw(20) << left << fixed << setprecision(2) << w.galutinis_vid << fixed << setprecision(2) << w.galutinis_med << endl;
    }
    auto eIsvestis = std::chrono::system_clock::now();
    std::chrono::duration<double> dIsvestis = eIsvestis - sIsvestis;

    cout << "Israsymas baigas per " << dIsvestis.count() << "s. Rezultatas luzeriai.txt / neluzeriai.txt failuose.";

    rasoL.close();
    rasoW.close();
}

// Deque
void galutinisDeque(deque<Studentas>& studentai) {
    for(auto it = studentai.begin(); it != studentai.end(); ++it) {
        double vidurkis = 0;
        double mediana = 0;
        if(it->nd_rezultatai.size() > 0) {
            // Galutinio balo apskaičiavimas su rezultatų vidurkiu
            vidurkis = accumulate(it->nd_rezultatai.begin(), it->nd_rezultatai.end(), 0.0) / it->nd_rezultatai.size();

            // Galutinio balo apskaičiavimas su rezultatų mediana
            int dydis = it->nd_rezultatai.size();
            vector<int> nd_copy(it->nd_rezultatai.begin(), it->nd_rezultatai.end());
            sort(nd_copy.begin(), nd_copy.end());

            // Jei yra lyginis skaičius rezultatų, imamas dviejų vidurinių skaičių vidurkis, jei nelyginis, imamas vidurinis skaičius
            if(dydis % 2 == 0) {
                mediana = (double)(nd_copy[dydis / 2 - 1] + nd_copy[dydis / 2]) / 2;
            } else {
                mediana = nd_copy[dydis / 2];
            }
        }
        it->galutinis_med = 0.4 * mediana + 0.6 * it->egzamino_rezultatas;
        it->galutinis_vid = 0.4 * vidurkis + 0.6 * it->egzamino_rezultatas;
    }
}
void isvestiDeque(deque<Studentas>& studentai) {
    ofstream rasoL("luzeriai.txt");
    ofstream rasoW("neluzeriai.txt");

    deque<Studentas> luzeriai;
    deque<Studentas> neluzeriai;

    rasoL << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << "Galutinis (Med.)" << endl;
    rasoW << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << "Galutinis (Med.)" << endl;
    rasoL << "--------------------------------------------------------------------" << endl;
    rasoW << "--------------------------------------------------------------------" << endl;

    // Mokinių rūšiavimas pagal galutinius pažymius
    auto sRusiavimas = std::chrono::system_clock::now();
    for(const auto& s : studentai) {
        if(s.galutinis_vid < 5.0 && s.galutinis_med < 5.0) {luzeriai.push_back(s);}
        if(s.galutinis_vid >= 5.0 && s.galutinis_med >= 5.0) {neluzeriai.push_back(s);}
    }   
    auto eRusiavimas = std::chrono::system_clock::now();
    std::chrono::duration<double> dRusiavimas = eRusiavimas - sRusiavimas;

    cout << "Rusiavimas baigtas per " << dRusiavimas.count() << "s." << endl;

    // Surūšiuotų mokinių duomenų išrašymas į skirtingus failus
    auto sIsvestis = std::chrono::system_clock::now();
    for(const auto& l : luzeriai) {
        if(l.nd_rezultatai.empty() || l.galutinis_vid <= 0 || l.galutinis_med <= 0) {continue;}
        rasoL << setw(15) << left << l.pavarde << setw(15) << left << l.vardas << setw(20) << left << fixed << setprecision(2) << l.galutinis_vid << fixed << setprecision(2) << l.galutinis_med << endl;
    } for(const auto& w : neluzeriai) {
        if(w.nd_rezultatai.empty() || w.galutinis_vid <= 0 || w.galutinis_med <= 0) {continue;}
        rasoW << setw(15) << left << w.pavarde << setw(15) << left << w.vardas << setw(20) << left << fixed << setprecision(2) << w.galutinis_vid << fixed << setprecision(2) << w.galutinis_med << endl;
    }
    auto eIsvestis = std::chrono::system_clock::now();
    std::chrono::duration<double> dIsvestis = eIsvestis - sIsvestis;

    cout << "Israsymas baigas per " << dIsvestis.count() << "s. Rezultatas luzeriai.txt / neluzeriai.txt failuose.";

    rasoL.close();
    rasoW.close();
}