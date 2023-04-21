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
|  **1 000**       |  0.017004s    |  0.005s       |  0.001s      |  0.019004s     |  0.030006s   |
|  **10 000**      |  0.177039s    |  0.051011s    |  0.006001s   |  0.185308s     |  0.290332s   |
|  **100 000**     |  1.58336s     |  0.522118s    |  0.074017s   |  1.83231s      |  3.01666s    |
|  **1 000 000**   |  17.3813s     |  4.81674s     |  0.887493s   |  17.82s        |  29.9599s    |

**std::list**
|  Įrašų skaičius  |  Generavimas  |  Nuskaitymas  |  Rūšiavimas  |  Spausdinimas  |     Viso     |
|------------------|---------------|---------------|--------------|----------------|--------------|
|  **1 000**       |  0.017003s    |  0.005001s    |  0s          |  0.017663s     |  0.02773s    |
|  **10 000**      |  0.187042s    |  0.04601s     |  0.004994s   |  0.188046s     |  0.262065s   |
|  **100 000**     |  1.87843s     |  0.48611s     |  0.068015s   |  1.78275s      |  2.53592s    |
|  **1 000 000**   |  15.3204s     |  4.57347s     |  0.697947s   |  17.775s       |  25.496s     |

**std::deque**
|  Įrašų skaičius  |  Generavimas  |  Nuskaitymas  |  Rūšiavimas  |  Spausdinimas  |     Viso     |
|------------------|---------------|---------------|--------------|----------------|--------------|
|  **1 000**       |  0.022005s    |  0.005001s    |  0s          |  0.019433s     |  0.029436s   |
|  **10 000**      |  0.201045s    |  0.04601s     |  0.004s      |  0.183041s     |  0.282065s   |
|  **100 000**     |  1.58602s     |  0.462868s    |  0.042011s   |  1.99253s      |  3.10711s    |
|  **1 000 000**   |  20.3368s     |  4.60403s     |  0.489109s   |  17.7685s      |  29.7822s    |

### Sistemos parametrai

**Processor**	AMD Ryzen 7 2700X Eight-Core Processor, 3700 Mhz, 8 Core(s), 16 Logical Processor(s)
**SSD**     	XPG GAMMIX S11 Pro PCIe Gen3x4 M.2 2280
**RAM**         16,0GB DDR4 Dual-Channel VENGEANCE® LPX @ 1064MHz

---

**libraries.h** - failas, kuriame saugomos visos bibliotekos ir jų pagrindinės funkcijos, kurios yra reikalingos šiai programai veikti.
