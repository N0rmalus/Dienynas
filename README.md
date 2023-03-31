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

## v0.5
Ši programos versija nesiskiria nuo praeitos (v0.4) versijos, tačiau šįkart studentų duomenys saugojami skirtingų tipų konteineriuose:

- std::vector
- std::list
- std::deque

**mainVector.cpp** - programos versija, kurioje studentų duomenys saugomi vektoriuose.
**mainList.cpp** - programos versija, kurioje studentų duomenys saugomi sąraše (list).
**mainDeque.cpp** - programos versija, kurioje studentų duomenys saugomi deque'uose.

### Programos sparta 

**std::vector**
|  Įrašų skaičius  |  Generavimas  |  Nuskaitymas  |  Rūšiavimas  |  Spausdinimas  |     Viso     |
|------------------|---------------|---------------|--------------|----------------|--------------|
|  **1 000**       |  0.017005s    |  0.005989s    |  0.000266s   |  0.020997s     |  0.029998s   |
|  **10 000**      |  0.181041s    |  0.049003s    |  0.002421s   |  0.184041s     |  0.275053s   |
|  **100 000**     |  1.90779s     |  0.488099s    |  0.488099s   |  1.83541s      |  2.86863s    |
|  **1 000 000**   |  16.0106s     |  4.68205s     |  4.68205s    |  18.5489s      |  29.3834s    |

**std::list**
|  Įrašų skaičius  |  Generavimas  |  Nuskaitymas  |  Rūšiavimas  |  Spausdinimas  |     Viso     |
|------------------|---------------|---------------|--------------|----------------|--------------|
|  **1 000**       |  0.023005s    |  0.00501s     |  0.000266s   |  0.025012s     |  0.034022s   |
|  **10 000**      |  0.210036s    |  0.050011s    |  0.184041s   |  0.196045s     |  0.294067s   |
|  **100 000**     |  1.79341s     |  0.478097s    |  0.488099s   |  1.8444s       |  2.85963s    |
|  **1 000 000**   |  16.6378s     |  5.07014s     |  4.68205s    |  19.6112s      |  31.1641s    |

**std::deque**
|  Įrašų skaičius  |  Generavimas  |  Nuskaitymas  |  Rūšiavimas  |  Spausdinimas  |     Viso     |
|------------------|---------------|---------------|--------------|----------------|--------------|
|  **1 000**       |  0.016996s    |  0.005009s    |  0.000266s   |  0.021007s     |  0.030017s   |
|  **10 000**      |  0.17804s     |  0.051012s    |  0.184041s   |  0.195044s     |  0.293066s   |
|  **100 000**     |  1.67038s     |  0.532112s    |  0.488099s   |  1.85442s      |  2.96366s    |
|  **1 000 000**   |  16.5889s     |  4.84109s     |  4.68205s    |  18.852s       |  29.8365s    |

### Sistemos parametrai

**Processor**	AMD Ryzen 7 2700X Eight-Core Processor, 3700 Mhz, 8 Core(s), 16 Logical Processor(s)
**SSD**     	XPG GAMMIX S11 Pro
**RAM**         16,0GB DDR4 Dual-Channel VENGEANCE® LPX @ 1064MHz

---

**libraries.h** - failas, kuriame saugomos visos bibliotekos ir jų pagrindinės funkcijos, kurios yra reikalingos šiai programai veikti.
