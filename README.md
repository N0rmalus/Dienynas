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

## v0.4
Nuo šios versijos vartotojas gali pats generuoti failus įrašydamas norimą mokinių ir namų darbų rezultatų kiekį. Taip pat, skaičiuojamas programos ir jos pagrindinių funkcijų veikimo laikas.

**main.cpp** - pagrindinė programos dalis.

**alternative.cpp** - papildoma programos dalis, kurioje laikomi funkcijų aprašymai.

**generator.cpp** - papildoma programos dalis, kurioje laikoma failo generavimo funkcija.

**header.h** - antraštinis failas, kuriame laikoma studento struktūra ir funkcijų antraštės.

### Programos sparta

|  Įrašų skaičius  |  Generavimas  |  Nuskaitymas  |  Rūšiavimas  |  Spausdinimas  |     Viso     |
|------------------|---------------|---------------|--------------|----------------|--------------|
|  **1 000**       |  0.017005s    |  0.005989s    |  0.000266    |  0.020997s     |  0.029998s   |
|  **10 000**      |  0.181041s    |  0.049003s    |  0.184041s   |  0.184041s     |  0.275053s   |
|  **100 000**     |  1.90779s     |  0.488099s    |  0.488099s   |  1.83541s      |  2.86863s    |
|  **1 000 000**   |  16.0106s     |  4.68205s     |  4.68205s    |  18.5489s      |  29.3834s    |

---

**libraries.h** - failas, kuriame saugomos visos bibliotekos ir jų pagrindinės funkcijos, kurios yra reikalingos šiai programai veikti.
