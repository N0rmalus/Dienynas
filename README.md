#  Dienynas

Tai paprasta C++ programa, kurioje vartotojas įrašinėja arba skaito (nuo v0.2) iš failo naujus mokinius. Mokinių duomenys susideda iš namų darbų ir egzamino rezultatų. Vartotojas turi galimybę pasirinkti, ar mokinio rezultatai bus išrašomi atsitiktinai, ar rankiniu būdu. Galiausiai, mokiniai yra išrašomi lentelėje su galutiniais balais, kurie apskaičiuojami dviem būdais, pagal vartotojo pasirinkimą.

## v0.1
Programa susideda iš dviejų dalių:

**mainVector.cpp** - programos versija, kurioje studentų duomenys saugomi vektoriuose.

**mainArray.cpp** - programos versija, kurioje studentų duomenys saugomi masyvuose.

## v0.2
Ši programos versija nuo šiol turi tik vieną programos faila **main.cpp**, kurioje mokinių duomenys saugomi vektoriuose.

Vartotojas taip pat turi galimybę ne tik pridėti naujų mokinių rankiniu būdu, bet ir skaityti juos iš failų, tokių kaip **kursiokai.txt**.

## v0.3
Ši programos versija veikia taip pat kaip ir senesnė (v0.2) versija, tačiau šįkart ji parskirstyta po kelis failus:

**main.cpp** - pagrindinė programos dalis.

**alternative.cpp** - papildoma programos dalis, kurioje laikomi funkcijų aprašymai.

**header.h** - antraštinis failas, kuriame laikoma studento struktūra ir funkcijų antraštės.

---

**libraries.h** - failas, kuriame saugomos visos bibliotekos ir jų pagrindinės funkcijos, kurios yra reikalingos šiai programai veikti.
