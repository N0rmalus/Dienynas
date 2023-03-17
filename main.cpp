#include "libraries.h"
#include "header.h"

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
                    atsitiktiniai_rez(nd_rezultatas, egz_rez, kiek_nd, naujas_studentas);
                } else if (pasirinkimas2 == 'N' || pasirinkimas2 == 'n') {
                    rasomi_rez(is_naujo2, nd_rezultatas, egz_rez, naujas_studentas);
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

    spausdinti(studentai);

    return 0;
}
