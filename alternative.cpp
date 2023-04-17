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
    vector<Studentas> win;
    vector<Studentas> loss;

    int strategija;

    cout << "Kokia rusiavimo strategija norite naudoti? (1 / 2): ";
    cin >> strategija; cout << endl;

    // Mokinių duomenų išrašymas
    switch(strategija) {
        case 1:
            for (const auto& s : studentai) {
                if(s.nd_rezultatai.empty() || s.galutinis_vid <= 0 || s.galutinis_med <= 0) {continue;}

                auto sRusiavimas = std::chrono::system_clock::now();
                if(s.galutinis_vid < 5.0 && s.galutinis_med < 5.0) {

                    loss.push_back(s);
                } if(s.galutinis_vid >= 5.0 && s.galutinis_med >= 5.0) {

                    win.push_back(s);
                }
                auto eRusiavimas = std::chrono::system_clock::now();
            }
        case 2:
            for (auto it = studentai.begin(); it != studentai.end();) {
                auto& s = *it;

                if(s.nd_rezultatai.empty() || s.galutinis_vid <= 0 || s.galutinis_med <= 0) {
                    ++it;

                    continue;
                } if(s.galutinis_vid < 5.0 && s.galutinis_med < 5.0) {
                    loss.push_back(s);
                    it = studentai.erase(it);
                } else if(s.galutinis_vid >= 5.0 && s.galutinis_med >= 5.0) {
                    win.push_back(s);
                    ++it;
                } else {++it;}
            } 
        default: 
            cout << "Tokio pasirinkimo [" << strategija << "] nera. Tesiama su pirma strategija" << endl;

            for (const auto& s : studentai) {
                if(s.nd_rezultatai.empty() || s.galutinis_vid <= 0 || s.galutinis_med <= 0) {continue;}

                auto sRusiavimas = std::chrono::system_clock::now();
                if(s.galutinis_vid < 5.0 && s.galutinis_med < 5.0) {

                    loss.push_back(s);
                } if(s.galutinis_vid >= 5.0 && s.galutinis_med >= 5.0) {

                    win.push_back(s);
                }
                auto eRusiavimas = std::chrono::system_clock::now();
            }
    }    

    cout << "Baigta. Rezultatas luzeriai.txt / neluzeriai.txt failuose.";
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
    list<Studentas> win;
    list<Studentas> loss;

    int strategija;

    cout << "Kokia rusiavimo strategija norite naudoti? (1 / 2): ";
    cin >> strategija; cout << endl;

    // Mokinių duomenų išrašymas
    switch(strategija) {
        case 1: {
            for (const auto& s : studentai) {
                if(s.nd_rezultatai.empty() || s.galutinis_vid <= 0 || s.galutinis_med <= 0) {continue;}

                auto sRusiavimas = std::chrono::system_clock::now();
                if(s.galutinis_vid < 5.0 && s.galutinis_med < 5.0) {

                    loss.push_back(s);
                } if(s.galutinis_vid >= 5.0 && s.galutinis_med >= 5.0) {

                    win.push_back(s);
                }
                auto eRusiavimas = std::chrono::system_clock::now();
            }    
        }
        case 2: {
            for (auto it = studentai.begin(); it != studentai.end();) {
                auto& s = *it;
                if (s.nd_rezultatai.empty() || s.galutinis_vid <= 0 || s.galutinis_med <= 0) {
                    ++it;

                    continue;
                }

                auto sRusiavimas = std::chrono::system_clock::now();
                if (s.galutinis_vid < 5.0 && s.galutinis_med < 5.0) {
                    loss.push_back(std::move(s));
                    it = studentai.erase(it);
                } else {++it;}
                auto eRusiavimas = std::chrono::system_clock::now();
            } 
        }
        default: {
            cout << "Tokio pasirinkimo [" << strategija << "] nera. Tesiama su pirma strategija" << endl;

            for (const auto& s : studentai) {
                if(s.nd_rezultatai.empty() || s.galutinis_vid <= 0 || s.galutinis_med <= 0) {continue;}

                auto sRusiavimas = std::chrono::system_clock::now();
                if(s.galutinis_vid < 5.0 && s.galutinis_med < 5.0) {

                    loss.push_back(s);
                } if(s.galutinis_vid >= 5.0 && s.galutinis_med >= 5.0) {

                    win.push_back(s);
                }
                auto eRusiavimas = std::chrono::system_clock::now();
            }    
        }
    }

    cout << "Baigta. Rezultatas luzeriai.txt / neluzeriai.txt failuose.";
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
    deque<Studentas> win;
    deque<Studentas> loss;

    int strategija;

    cout << "Kokia rusiavimo strategija norite naudoti? (1 / 2): ";
    cin >> strategija; cout << endl;

    // Mokinių duomenų išrašymas
    switch(strategija) {
        case 1: {
            for (const auto& s : studentai) {
                if(s.nd_rezultatai.empty() || s.galutinis_vid <= 0 || s.galutinis_med <= 0) {continue;}

                auto sRusiavimas = std::chrono::system_clock::now();
                if(s.galutinis_vid < 5.0 && s.galutinis_med < 5.0) {

                    loss.push_back(s);
                } if(s.galutinis_vid >= 5.0 && s.galutinis_med >= 5.0) {

                    win.push_back(s);
                }
                auto eRusiavimas = std::chrono::system_clock::now();
            }    

            break;
        }
        case 2: {
            for (auto it = studentai.begin(); it != studentai.end();) {
                if (it->nd_rezultatai.empty() || it->galutinis_vid <= 0 || it->galutinis_med <= 0) {
                    ++it;

                    continue;
                }
                if (it->galutinis_vid < 5.0 && it->galutinis_med < 5.0) {
                    loss.push_back(std::move(*it));
                    it = studentai.erase(it);
                } else {++it;}
            }    

            break;
        }
        default: {
            cout << "Tokio pasirinkimo [" << strategija << "] nera. Tesiama su pirma strategija" << endl;

            for (const auto& s : studentai) {
                if(s.nd_rezultatai.empty() || s.galutinis_vid <= 0 || s.galutinis_med <= 0) {continue;}

                auto sRusiavimas = std::chrono::system_clock::now();
                if(s.galutinis_vid < 5.0 && s.galutinis_med < 5.0) {

                    loss.push_back(s);
                } if(s.galutinis_vid >= 5.0 && s.galutinis_med >= 5.0) {

                    win.push_back(s);
                }
                auto eRusiavimas = std::chrono::system_clock::now();
            }  

            break;
        }
    }

    cout << "Baigta. Rezultatas luzeriai.txt / neluzeriai.txt failuose.";
}