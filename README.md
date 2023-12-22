# Instaliacija 
```
- Instaliuokite "make", jei naudojate MAC ar Linux susiraskite tutorial, jei naudojate Windows galite naudoti šitą nuorodą :
https://earthly.dev/blog/makefiles-on-windows/

- Parsisiųskite ir "išextractinkite" šitą github release

- Aplanke kur yra "extractinti" failai atsidarykite cmd

- cmd suveskite "make" komandą (be kabučių)

- Jūsų aplanke bus sugeneruotas failas "main", kuris jau yra tinkamas naudoti

```
# Naudojimosi instrukcija 
```
- Pirmos programos paleidimo metu rekomenduojama pasirinkti generuoti studentų failą, kad būtų galima sužinoti, kur bus saugomi
sukurti failai (ten bus ir nuskaitomi failai).

- Galima rinktis iš 5 pasirinkimu R- studentų įrašymas ranka, F - nuskaitymas iš failo, G- studentų failo generavimas, T - "RULE OF 3" testavimas,

- Įvedimo metu gali reikti įvesti: studentų skaičių, namų darbų kiekį, norėsite skaičiuoti mediana ar vidurkį, kokią strategiją norėsite naudoti
rūšiuoti vargšus ir kietus, kokį failą norėsite nuskaityti... Tai reiškia jūsų programa prašys ką reikia įvesti.

```
# Uzduotis-nr-2
## v2.0 
### nauji dalykai 
* Sukurta Doxygen dokumentacija
* Sukurtas naujas failas test.cpp, kuris testuoja medianos ir vidurkio funkcijos išvedimą
* Buvo naudota Google Test testavimo framework

### Testų rezultatai
* Buvo rasta, kad Mediana() netinkamai skaičiavo medianas, o tai pastebėjus problema buvo ištaisyta.


## v1.5 
### nauji dalykai 
* Implementuota abstrakti "Zmogus" klasė.
* Ankščiau naudota "Studentai" klasė dabar yra derived tipo klasė

### Naujosios klasės "Zmogus" realizacija 
![Screenshot_2](https://github.com/laurinykas/Uzduotis-nr-2/assets/112711939/4f2c206b-1d7d-4281-9917-1d17a6f4469c)

### Įrodymas, kad "Zmogus" klasės objektų kūrimas yra negalimas
![Screenshot_1](https://github.com/laurinykas/Uzduotis-nr-2/assets/112711939/0b7d5ad9-80b2-4c24-ad8b-934914efcb65)


## v1.2
### nauji dalykai 
* Nebenaudojamas list konteineris
* Realizuota "Rule of 3"
* Sukurti pagal tai išvesties ir įvesties operatoriai  
### Rule of 3 implementacija 
![2](https://github.com/laurinykas/Uzduotis-nr-2/assets/112711939/a6b68eaf-4532-4dcb-af5d-1a8343860eab)
### Rule of 3 demonstravimas 
![4](https://github.com/laurinykas/Uzduotis-nr-2/assets/112711939/4ff5a097-27cd-48f8-9c67-f0a6124e58dd)
### Įvedimas ir išvedimas
![3](https://github.com/laurinykas/Uzduotis-nr-2/assets/112711939/d7075419-00c5-47ae-8a84-d643312ca69f)
### Įvesties operatorius 
![5](https://github.com/laurinykas/Uzduotis-nr-2/assets/112711939/19010912-394a-46c6-aeab-1c3bf496dd43)
### Išvesties operatorius 
![6](https://github.com/laurinykas/Uzduotis-nr-2/assets/112711939/c3303235-1251-4623-9c09-b45952994f00)






## v1.1
### nauji dalykai 
* Pereita iš struktūros į klasę
* Sukurtas naujas Studentai.cpp failas
* Sumažintas metodų ir funkcijų skaičius vector ir list konteinerių atvejų (subendrinta)

### sruct ir class greičio analizė (naudojant compiler optimisation flags(O1, O2, O3))
 EXE Failų dydžiai :

 
![Screenshot_3](https://github.com/laurinykas/Uzduotis-nr-2/assets/112711939/0e9b151c-6bfc-4938-94e0-66df9b7312e8)

Struktūrų ir klasių programos veikimo trukmė naudojant 1M ir 10M dydžio failus taip pat naudojant flagus:
![Screenshot_1](https://github.com/laurinykas/Uzduotis-nr-2/assets/112711939/be58dfcd-4baf-474f-a088-4b1c754bfe66)


# Uzduotis-nr-1
## v1.0 
### nauji dalykai
* Galima rūšiuoti pagal vardą, pavardę ir galutinį balą.
* Galima pasirinkti 3 studentų rūšiavimo į vargšus ir kietus studentus. 
* Galima testuoti failus pagal rūšiavimo strategiją.
* Galima įdiegti failą naudojant Makefile.

### Strategiju testavimo rezultatai sekundėmis
* Apdorota Excel lentelė


![Screenshot_2](https://github.com/laurinykas/Uzduotis-nr-1/assets/112711939/c1684dd1-0538-4a1d-83ae-7ef2aeb150de)
* Raw kodo išvedimas
![Screenshot_1](https://github.com/laurinykas/Uzduotis-nr-1/assets/112711939/5d3602ba-938d-4483-98ca-e528e362dc54)
* Konteinerių vidurkiai atskiriant strategijas

![image](https://github.com/laurinykas/Uzduotis-nr-1/assets/112711939/e34e6e45-8d56-4801-934b-e19126dbf0c5)






## v0.3 
### nauji dalykai
* Implementuotas std::list konteineris.
* Pasirinkus studento rašymo ranka funckiją galima taip pat gaunamas objekto adresas.
* Įdėta galimybė testuoti konteinerių greitį.
* Galima pasirinkti į kokį konteinerį įrašysite duomenis.
  
### std::vector ir std::list konteinerių palyginimo rezultatai

![Screenshot_1](https://github.com/laurinykas/Uzduotis-nr-1/assets/112711939/d1e92756-5aa9-4eb6-b7c0-dcac1237d786)
![image](https://github.com/laurinykas/Uzduotis-nr-1/assets/112711939/d26ef658-e736-4783-aee6-975f88f91c5d)

* Vidutinis laikas 1k studentų : 0.0110898 s.
* Vidutinis laikas 10k studentų : 0.12564285 s.
* Vidutinis laikas 100k studentų : 1.57843795 s.
* Vidutinis laikas 1mil. studentų : 18.1561645 s.
* Vidutinis laikas 10mil. studentų : 202.8593495 s. 
### Testavimui buvo naudoti:
*  CPU : AMD Ryzen 7 5800H
* RAM : 16.0 GB 3200 MHz
* SSD: 475 GB
  

## v0.2.1
* Galima generuoti daug kartų studentų failus.
* Galima pasirinkti, kokius failus nori naudotojas nuskaityti.

## v0.2 
* Galimybė sugeneruoti atsitiktinius studentus į failą.
* Yra studentų vektoriaus rūšiavimas į kietus ir vargšus studentus
  (studentai, kurių galutinis balas yra didesnis ar lygus 5 yra skaitomi kietais studentas, o tų kurių mažesnis - vargšais).
* Galimybė išrašyti studentų galutinius balus į failus.
* Dabar yra matuojami įvairūs programos procesai (studentus generuojančio failo kūrimas, failo nuskaitymas, studentų rūšiavimas, naujų failų kūrimas).

### Programos greičiai su skirtingais studentų kiekiais
* Kai studentų yra 1 tūkst. ir namų darbų kiekis - 6
![1k_6nd](https://github.com/laurinykas/Uzduotis-nr-1/assets/112711939/ef805dd6-036c-40a2-a704-5f26f6ad0f52)
* Kai studentų yra 10 tūkst. ir namų darbų kiekis - 6
![10k_6nd](https://github.com/laurinykas/Uzduotis-nr-1/assets/112711939/436c36b9-466d-4a25-8381-f326903b8f51)
* Kai studentų yra 100 tūkst. ir namų darbų kiekis - 6
![100k_6nd](https://github.com/laurinykas/Uzduotis-nr-1/assets/112711939/68b93e4f-1c8e-4110-91bc-df5de26c32c8)
* Kai studentų yra 1 mil. ir namų darbų kiekis - 6
![1mil_6nd](https://github.com/laurinykas/Uzduotis-nr-1/assets/112711939/56e4f1ea-1a90-4463-aaa1-07558df7fe6a)
* Kai studentų yra 10 mil. ir namų darbų kiekis - 6
![10mil_6_nd](https://github.com/laurinykas/Uzduotis-nr-1/assets/112711939/e4da4830-9bad-4926-afce-0569ca2a4e4f)


## v0.1.1
* Galimybė nuskaityti studentus iš failo.
* Įdėta naudotojo apsauga, jei failas neegzistuotų.
* Studentai dabar yra ir rūšiuojami.

## v.pradine 
### Programos galimybės
* Programa paima studentų vardus ir pavardes, surenka namų  darbų pažymius, bei egzamino balą ir apskaičiuoją medianą su vidurkiu.
* Šitoje galima duomenis suvesti ranka, bet kai kuriuos duomenis(namų darbų balus ir egzamino balą) sugeneruoti atsitiktinai.
* Yra įdėti saugumo garantai, kad programa veiktų tvarkingai( pažymiai yra visada skaičiai nuo 1 iki 10 ir t.t).
* Galima suvesti neribotą kiekį namų darbų ir studentų .
