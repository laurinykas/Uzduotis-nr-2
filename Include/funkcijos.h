//
// Created by Laurynas on 10/13/2023.
//

#ifndef UZDUOTIS_NR_1_FUNKCIJOS_H
#define UZDUOTIS_NR_1_FUNKCIJOS_H


#include "Studentai.h"

//void isvestis (vector<Duomenys> vektorius, int pasirinkimas);
//void isvestis_list (list<Duomenys> listas, int pasirinkimas);
int Studentu_kiekis();
int Nd_kiekis();
//void ivedimas_list ( int studentu_kiekis);
void studentu_generavimas(int st_k, int  namu_d);
void Studentu_skaldymas(int konteineris);
//void readfromFile( string filename, vector<Studentai> &stud, list<Studentai> &stud_list, int konteineris);
//void readfromFileList( string filename, list<Studentai> &stud_list); //listu variantas
void Kategorija(int studentu_k,int med_ar_vid, int konteineris);

//void Failu_kurimas (vector<Duomenys> vektorius, string failo_vardas, int pasirinkimas);
//void Failu_kurimas_list (list<Duomenys> listas, string failo_vardas, int pasirinkimas);
int Konsole_ar_failas ();
int Isvesties_pasirinkimas ();
void Koks_failo_pav (int konteineris);
void Fake_main();
int Vid_ar_med();
int List_Vektor();
void Sortingas (int vek_ar_list, int sortingo_tipas);
int Rusiavimo_tipas();
void Skaldymas2(int konteineris);
void Skaldymas3(int konteineris);
int SkirstymoStrategijosPas();
void MegaSkirstymas(int konteineris , int strategija );




extern vector <Studentai> stud;
extern vector<Studentai> kieti;
extern vector<Studentai> vargsai;
extern Studentai duomenys;
extern list<Studentai> stud_list;
extern list<Studentai> kieti_list;
extern list<Studentai> vargsai_list;
extern int studentu_kiekis ;
extern string failo_pav ;
extern std::chrono::duration<double> laikas_kat;
extern std::chrono::duration<double> laikas_failo;

#endif //UZDUOTIS_NR_1_FUNKCIJOS_H
