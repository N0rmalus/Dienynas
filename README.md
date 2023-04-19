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
|  **1 000**       |  0.017002s    |  0.005s       |  0.001001s   |  0.020004s     |  0.031007s   |
|  **10 000**      |  0.190043s    |  0.050011s    |  0.007001s   |  0.199047s     |  0.302068s   |
|  **100 000**     |  1.60836s     |  0.519117s    |  0.08402s    |  1.78757s      |  2.94994s    |
|  **1 000 000**   |  20.2245s     |  5.04763s     |  0.922206s   |  18.4402s      |  30.9805s    |

---

**libraries.h** - failas, kuriame saugomos visos bibliotekos ir jų pagrindinės funkcijos, kurios yra reikalingos šiai programai veikti.
