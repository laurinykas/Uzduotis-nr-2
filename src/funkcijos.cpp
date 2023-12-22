//
// Created by Laurynas on 10/13/2023.
//

#include "../Include/funkcijos.h"

int Studentu_kiekis() {
    int studentu_sk;

    while (true) {
        cout << "Iveskite studentu kieki: ";
        if (cin >> studentu_sk && studentu_sk > 0) {
            return studentu_sk;
        } else {
            cout << "Neteisingai ivestas studentu skaicius, bandykite dar karta" << std::endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}
int Nd_kiekis()  {
    int nd_sk;

    while (true) {
        cout << "Iveskite namu darbu kieki: ";
        if (std::cin >> nd_sk && nd_sk > 0) {
            return nd_sk;
        } else {
            cout << "Neteisingai ivestas namu darbu skaicius, bandykite dar karta" << std::endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}


void studentu_generavimas(int studentu_kiekis, int  namu_d){
    string failo_vardas = "student" + to_string(studentu_kiekis) + ".txt";
    stringstream eilute;
    ofstream out (failo_vardas);
    eilute << "Vardas" << setw(15) << "Pavarde";
    for (int i=0;i < namu_d; i++){
        eilute << setw(15) << "ND" << i+1;


    }
    eilute << setw(15) << "Egz" <<endl;
    srand((unsigned )time(0));
    for(int i=0; i < studentu_kiekis; i++){
        eilute << "Vardas" << i+1 << setw(15) << "Pavarde" << i+1;
        for(int j=0; j<namu_d; j++){
            eilute << setw(15) << (rand() % 10) + 1;

        }
        eilute << setw(15) << (rand() % 10) + 1 <<endl;

    }
    out <<eilute.str();
    eilute.clear();
    out.close();
    cout << "baigtas failo generavimas"<<endl;

}



void Kategorija(int studentu_k, int med_ar_vid ){

            for(int i=0; i <= studentu_k; i++){
                stud[i].Galutinis (med_ar_vid );

            }
}





int Vid_ar_med(){
    int med_ar_vid;
    cout<< "Ar galutiniam balui naudosite vidurki ar mediana(1 - vidurkis, 2 - mediana)?"<<endl; cin>> med_ar_vid;
    do{
        if(med_ar_vid && (med_ar_vid == 1 || med_ar_vid == 2)){
            return med_ar_vid;
        }
        else{
            cout<< "Kladinga ivestis, bandykite dar karta (Iveskite 1 arba 2 )"<<endl;
            cin.clear();
            cin.ignore(10000 , '\n');
            cin >> med_ar_vid;
        }
    }
    while(med_ar_vid != 1 && med_ar_vid != 2);


}







int Konsole_ar_failas (){
    char kons_fail;
    int konsol1_failas2;
    cout<< "Ar noresite isvesti i konsole ar i faila ? (K/F)"<< endl; cin>>kons_fail;
    do{
        if (kons_fail){
            if(kons_fail == 'K'|| kons_fail == 'k'){
                konsol1_failas2 = 1;
                return konsol1_failas2;

            }
            else {
                konsol1_failas2 = 2;
                return konsol1_failas2;
            }

        }else{

            cout<< "Iveskite tinkama ivesti K arba F !"<<endl;cin.clear();cin.ignore(1000, '\n');
            cin>> kons_fail;
        }

    }

    while(kons_fail != 'K' && kons_fail != 'k' && kons_fail != 'f' && kons_fail != 'F');


}


int Isvesties_pasirinkimas (){
    int pasirinkimas;
    cout << "Ar norite vidurkio - 1 , medianos - 2 ar abieju - 3 ? :" << endl;
    cin >> pasirinkimas;
    do{
        if(pasirinkimas &&( pasirinkimas == 1 || pasirinkimas == 2 || pasirinkimas == 3)) {
            return pasirinkimas;
        }
        else{
            cout << "Iveskite nenulini skaiciu, nuo 1 iki 3!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> pasirinkimas;


        }
    }while (pasirinkimas != 1 and pasirinkimas != 2 and pasirinkimas != 3);
}

void Koks_failo_pav (){
    Studentai st;
    system("dir *.txt");
    string failo_pavadinimas;
    std::chrono::duration<double> laikas;
    cout<<"Koki faila noretumete nuskenuoti?"<<endl; cin>> failo_pavadinimas;


        try {
            ifstream fileread(failo_pavadinimas);
            if (!fileread.fail()) {
                auto start  = hrClock::now();
                st.readfromFile(failo_pavadinimas,stud);
                auto end  = hrClock::now();
                laikas = end- start;
                cout << failo_pavadinimas << " studentu failo nuskaitymas uztruko : " << laikas.count()<< "s" << endl;
            }
            else{
                throw std::runtime_error(failo_pavadinimas);

        }

    }
        catch(std::exception &e) {
            cout << "Failas "  << e.what() << "neegzistuoja arba neteisingai irasete pavadinima, paleiskite dar karta programa" << endl;
            std::exit(0);


        }
    }

void Sortingas ( int sortingo_tipas){


        if(sortingo_tipas == 1){// pagal varda
            sort(stud.begin(), stud.end(), palyginimas_vardas);
        }
        else if (sortingo_tipas == 2){// pagal pavarde
            sort(stud.begin(), stud.end(), palyginimas_pavarde);
        }
        else {// pagal galutini
            sort(stud.begin(), stud.end(), palyginimas_galutinis);
        }

    }





int Rusiavimo_tipas() {
    int pasirinkimas;
    cout << "Kaip noresite rusiuoti 1 - pagal varda, 2 - pagal pavarde, 3- pagal galutini bala ? :" << endl;
    cin >> pasirinkimas;
    do{
        if(pasirinkimas &&( pasirinkimas == 1 || pasirinkimas == 2 || pasirinkimas == 3)){
            return pasirinkimas;


        }
        else{
            cout << "Iveskite nenulini skaiciu, nuo 1 iki 3!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> pasirinkimas;


        }
    }while (pasirinkimas != 1 and pasirinkimas != 2 and pasirinkimas != 3);


}





void Skaldymas3() {

        auto partitionPredicate = [](const Studentai& el) {
            return el.getGalutinis() >= 5.00;
        };

        auto partitionPoint = std::partition(stud.begin(), stud.end(), partitionPredicate);


        kieti.assign(stud.begin(), partitionPoint);
        vargsai.assign(partitionPoint, stud.end());
}




void Fake_main(){

    char ranka_failas;
    do {
        cout << "Ar duomenis rasytite ranka , nuskaitysite is failo ar noresite sugeneruoti atsitiktini ar testuoti?(R - ranka, F- is failo, G - generuoti, T - testuoti )?" << endl;
        cin >> ranka_failas;
        Studentai st ;
        if (ranka_failas &&
            (ranka_failas == 'R' || ranka_failas == 'r' || ranka_failas == 'F' || ranka_failas == 'f'|| ranka_failas == 'G'||ranka_failas == 'g' ||ranka_failas == 'T'||ranka_failas == 't')) {
            if (ranka_failas == 'R' || ranka_failas == 'r') {
                int studentu_kiekis = Studentu_kiekis();

                int rusiavimo_tipas =  Rusiavimo_tipas();

                    st.ivedimas(studentu_kiekis);
                    Sortingas(rusiavimo_tipas);
                    char kieti_vargsai;
                    cout << "Ar norite isrusiuoti studentus studentus i vargsus ir kietus ?(T/N)" << endl;
                    cin >> kieti_vargsai;
                    do {
                        if (kieti_vargsai && (kieti_vargsai == 'T' || kieti_vargsai == 't' || kieti_vargsai == 'N' ||
                                              kieti_vargsai == 'n')) {
                            if (kieti_vargsai == 'T' || kieti_vargsai == 't') {
                                int med_ar_int = Vid_ar_med();
                                Kategorija(studentu_kiekis, med_ar_int);
                                Skaldymas3();
                                int konsole_ar_failas = Konsole_ar_failas();
                                if (konsole_ar_failas == 1) {
                                    cout << "Isvesti vargsai studentai" << endl;
                                    st.isvestis(vargsai );
                                    cout << "Isvesti kieti studentai" << endl;
                                    st.isvestis(kieti);
                                } else {
                                    int isvedimas = Isvesties_pasirinkimas();

                                    st.Failu_kurimas(vargsai, "vargsai.txt", isvedimas);
                                    st.Failu_kurimas(kieti, "kieti.txt", isvedimas);

                                }
                            } else {
                                int konsole_ar_failas = Konsole_ar_failas();
                                int isvedimas = Isvesties_pasirinkimas();
                                if (konsole_ar_failas == 1) {

                                    cout << "Isvesti visi studentai :" << endl;
                                    st.isvestis(stud);
                                } else {
                                    cout << "Sukelti i faila studentai.txt. " << endl;
                                    st.Failu_kurimas(stud, "studentai.txt", isvedimas);
                                }
                            }
                        } else {
                            cout << " Neteisinga ivestis, iveskite T arba N !" << endl;
                            cin.clear();
                            cin.ignore(10000, '\n');
                            cin >> kieti_vargsai;
                        }

                    } while (kieti_vargsai != 'T' && kieti_vargsai != 't' && kieti_vargsai != 'N' && kieti_vargsai != 'n');



            }
            else if (ranka_failas == 'g' || ranka_failas == 'G'){
                std::chrono::duration<double> laikas;
                int studentu_mase = Studentu_kiekis();
                int nd_kiekis = Nd_kiekis();
                auto start = hrClock::now();
                studentu_generavimas(studentu_mase, nd_kiekis);
                auto end = hrClock::now();
                laikas = end - start;
                cout << studentu_mase << " studentu failo generavimas uztruko : " << laikas.count()<< "s" << endl;
                Fake_main();
            }

            else if (ranka_failas == 'f' || ranka_failas == 'F') {
                Studentai st;
                stud.push_back(duomenys);
                std::chrono::duration<double> laikas;
                int kons_ar_failas = Konsole_ar_failas();
                int isvedimas = Isvesties_pasirinkimas();
                int med_ar_vid = Vid_ar_med();

                int rusiavimo_tipas = Rusiavimo_tipas();




                    Koks_failo_pav ();// laikas suskaiciuotas
                    studentu_kiekis = stud.size() -1 ;
                    stud.erase(stud.begin());



                    Kategorija(studentu_kiekis,med_ar_vid);
                    auto start = hrClock::now();
                    Sortingas(rusiavimo_tipas);
                    auto end = hrClock::now();laikas = end - start ;
                    cout << studentu_kiekis <<" studentu failo surusiavimas  uztruko : " << laikas.count() << " s"<< endl;
                    start = hrClock::now();

                    Skaldymas3();
                    end = hrClock::now(); laikas= end - start;
                    cout << studentu_kiekis <<" studentu failo surusiavimas i atskirus vektorius uztriko : " << laikas.count() << " s"<< endl;

                    if(kons_ar_failas == 1){
                        start = hrClock ::now();
                        st.isvestis(vargsai);
                        end = hrClock ::now();
                        laikas = end - start; cout << "vargsu isvedimas truko :" << laikas.count()<<" s"<<endl;
                        start = hrClock ::now();
                        st.isvestis(kieti);
                        end = hrClock ::now();laikas = end - start;
                        cout << "kietu isvedimas truko :" << laikas.count()<<" s"<<endl;

                    }
                    else{
                        start = hrClock ::now();
                        st.Failu_kurimas(vargsai,"vargsai.txt",isvedimas);
                        end = hrClock ::now();laikas = end - start;
                        cout << "vargsu isvedimas truko :" << laikas.count()<<" s"<<endl;
                        start = hrClock ::now();
                        st.Failu_kurimas(kieti,"kieti.txt",isvedimas);
                        end = hrClock ::now();laikas = end - start;
                        cout << "kietu isvedimas truko :" << laikas.count()<<" s"<<endl;

                    }


            }
            else if(ranka_failas == 't' || ranka_failas == 'T'){

            // Zmogus z1;
            // cin>> z1;
            // cout<< z1;




            cout<<"Rule of 3 demonstravimas "<<endl;
            Studentai s1;
            cin >> s1;
            cout << s1<< endl;
            Studentai s2(s1);
            cout << s2<< endl;
            Studentai s3 = s1;
            cout << s3 <<endl;


            }






        } else {
            cout << "Iveskite R arba f arba G arba T " << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while (ranka_failas != 'R' and ranka_failas != 'r' and ranka_failas != 'F' and ranka_failas != 'f' and ranka_failas != 'g' and ranka_failas != 'G' and ranka_failas != 'T' and ranka_failas != 't' );


}

















