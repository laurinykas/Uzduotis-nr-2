#include "../Include/funkcijos.h"

void Studentai::Galutinis (int input ){
    if(input == 1){
        setGalutinis(getVid()) ;
    }
    else {
        setGalutinis(getMed());
    }

}

void Studentai::Vidurkis() {

    double sum_vid = 0;
    if (getNdSize() == 0) {
        setVid(  0.6 * getEgzaminas() ) ;
    } else {
        for (int i = 0; i < getNdSize(); i++) sum_vid += getNd(i);
        setVid(((sum_vid / getNdSize()) * 0.4) + (0.6 * getEgzaminas()));
    }
}
void Studentai::Mediana() {
    int n = getNdSize();
    if (n >= 1) {
        sortNd();
        if (n % 2 == 0) {
            // For an even number of elements, the median is the average of the two middle elements
            setMed((Cnd[n / 2 - 1] + Cnd[n / 2]) / 2.0);
        } else {
            // For an odd number of elements, the median is the middle element
            setMed(Cnd[n / 2]);
        }
        // Adjusting the median based on the exam score
        setMed(0.4 * getMed() + 0.6 * getEgzaminas());
    } else {
        // If there are no elements, set the median to 0 (or some other default value)
        setMed(0);
        setMed(0.4 * getMed() + 0.6 * getEgzaminas());
    }
}
std::istream& operator>>(std::istream& in,Studentai& s ){

    char bent_vienas_nd_ranka;
    cout << "Iveskite studento varda : " << endl;
    string vardas;
    in >> vardas;
    s.setVardas(vardas);
    cout << "Iveskite studento pavarde : " << endl;
    string pavarde;
    in >> pavarde;
    s.setPavarde(pavarde);
    do {
        cout << "Ar bus bent 1 namu darbas?(T/N)" << endl;in >> bent_vienas_nd_ranka;
        if (bent_vienas_nd_ranka && (bent_vienas_nd_ranka == 'T' || bent_vienas_nd_ranka == 't' || bent_vienas_nd_ranka == 'N' ||bent_vienas_nd_ranka == 'n')) {
            if (bent_vienas_nd_ranka == 'N' || bent_vienas_nd_ranka == 'n') {
                continue;
            } else {
                char ranka_auto;

                cout << "Kaip ivesite pazymius (jeigu ranka rasykite R, jei auto rasykite A :" << endl;
                in >> ranka_auto;
                do {
                    if (ranka_auto and
                        (ranka_auto == 'R' or ranka_auto == 'r' or ranka_auto == 'A' or ranka_auto == 'a')) {
                        continue;
                    } else {
                        cout << "Irasykite R arba A !" << endl;
                        in.clear();
                        in.ignore(10000, '\n');
                        in >> ranka_auto;
                    }
                } while (!(ranka_auto and
                           (ranka_auto == 'R' or ranka_auto == 'r' or ranka_auto == 'A' or ranka_auto == 'a')));
                char tp;
                int uzsibaigimas = 0;
                if (ranka_auto == 'R' or ranka_auto == 'r') {


                    while (uzsibaigimas == 0) {
                        int namu_d = 0;

                        do {
                            int namu_d_eile = s.getNdSize();
                            cout << "Iveskite nr. " << namu_d_eile + 1 << " pazymi: " << endl;
                            in >> namu_d;
                            //if(namu_d != 0){
                            if (namu_d > 0 and namu_d <= 10) {
                                s.addNd(namu_d);
                                cout << "Ar bus dar pazymiu ? (T/N)" << endl;
                                in >> tp;
                                do {
                                    if (tp and (tp == 'T' or tp == 't' or tp == 'n' or tp == 'N')) {
                                        if (tp == 'T' or tp == 't') {
                                            continue;
                                        }
                                        if (tp == 'n' or tp == 'N') {
                                            uzsibaigimas = 1;
                                        }
                                    } else {
                                        cout << "Iveskite tinkama atsakyma T arba N !" << endl;
                                        in.clear();
                                        in.ignore(10000, '\n');
                                    }
                                } while (tp != 'T' and tp != 't' and tp != 'n' and tp != 'N');
                            } else {
                                cout << "Iveskite tinkama skaicius nuo 1 iki 10!" << endl;
                                in.clear();
                                in.ignore(10000, '\n');
                            }


                        } while (namu_d == 0);
                    }
                }

                else{
                    int nd_skaicius = 0;
                    int sk = 0;
                    // random gen

                    do {
                        cout << "Iveskite kiek namu darbu noresite sugeneruoti" << endl;
                        in >> nd_skaicius;
                        srand((unsigned) time(0));
                        if (nd_skaicius and nd_skaicius > 0) {
                            for (int e = 0; e < nd_skaicius; e++) {
                                sk = (rand() % 10) + 1;
                                s.addNd(sk);

                            }

                        } else {
                            cout << "Iveskite skaiciu didesni nei 1! : " << endl;
                            in.clear();
                            in.ignore(10000, '\n');
                        }
                    } while (nd_skaicius < 0 or nd_skaicius == 0);
                }

            }

        }

        else{
            cout << "Iveskite T arba N !" << endl;
            in.clear();
            in.ignore(10000, '\n');
        }
    }while(bent_vienas_nd_ranka && (bent_vienas_nd_ranka != 'T' and bent_vienas_nd_ranka != 'N' and bent_vienas_nd_ranka != 'n' and bent_vienas_nd_ranka != 't'));
    char bent_vienas_egz;

    do{
        cout<<" Ar turi studentas egzamino rezultata (T/N)?"<<endl; in>>bent_vienas_egz;
        if (bent_vienas_egz == 'T'|| bent_vienas_egz == 't'|| bent_vienas_egz == 'N' || bent_vienas_egz == 'n'){
            if (bent_vienas_egz == 'T'|| bent_vienas_egz == 't'){

                char egz_ivedimas; int egz = 0 ;
                cout << "Ar norite ranka ivesti egzamina ar auto (R/A)"<<endl; in>> egz_ivedimas;
                do{
                    if(egz_ivedimas and( egz_ivedimas == 'R'|| egz_ivedimas == 'r'|| egz_ivedimas == 'A' || egz_ivedimas == 'a')){
                        if (egz_ivedimas=='R' or egz_ivedimas == 'r' )
                        {

                            do{
                                cout << "Iveskite egzamino rezultata:"<< endl ; in>> egz;
                                if(egz and egz > 0 and egz <=10){
                                    s.setEgzaminas(egz);

                                }
                                else{
                                    cout<< "Iveskite nenulini skaiciu, nuo 1 iki 10!"<<endl ;in.clear();
                                    in.ignore(10000, '\n'); }}
                            while(!egz or egz > 10 or egz <0 );

                        }
                        else{
                            srand((unsigned )time(0));
                            egz = (rand() % 10) + 1;
                            s.setEgzaminas(egz);
                        }
                    }
                    else{
                        cout<<"Iveskite tinkama pasirinkima (R/A)!"<<endl;
                        in.clear();
                        in.ignore(10000, '\n');
                        in >> egz;

                    }


                }while(egz_ivedimas != 'A' && egz_ivedimas != 'a' && egz_ivedimas != 'R' && egz_ivedimas != 'r');
            }
            else {
                s.setEgzaminas(0);
            }
        }
        else{
            cout<< "Iveskite T arba N! "<<endl; in.clear();in.ignore(10000,'\n');
        }
    }
    while(bent_vienas_egz != 'T' and bent_vienas_egz != 't' and bent_vienas_egz != 'N' and  bent_vienas_egz != 'n');

    s.Vidurkis();
    s.Mediana(); //skirta nuskaityti ranka
    //stud.push_back(s);
    return in;
}

void Studentai::ivedimas(int studentu_kiekis) {

    for (int i = 0; i < studentu_kiekis; i++) {
        Studentai s;
        cin >> s ;  // This will call the overloaded operator>> for Student
        stud.push_back(s);

    }




}

void Studentai::isvestis (vector<Studentai> vectorius ) {

   // stringstream buffer;


    cout << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(17) << "Galutinis(vid)" << setw(20)
           << "Galutinis(med)" << setw(20)
           << "Objekto adresas" << endl;
    cout << "___________________________________________________________________________________________" << endl;
    for (const auto& student : vectorius) {
        cout << student;  // Using the overloaded operator<< for individual Studentai objects
    }
}

std::ostream& operator<<(std::ostream& out, const Studentai& student) {
        out << std::setw(20) << student.getVardas() << std::setw(20) << student.getPavarde();

        out << std::setw(17) << std::fixed << std::setprecision(2) << student.getVid()
            << std::setw(17) << student.getMed();

        out << std::setw(23) << std::addressof(student) << std::endl;

        return out;
    }

 void Studentai :: readfromFile( string filename, vector<Studentai> &stud){
    try {
        ifstream fileread(filename);
        if (!fileread.fail()) {

            ifstream fileread(filename);
            int sk;
            string line;
            string temp,pirmaEil;
            int kiekNd = -3;
            getline(fileread >> std::ws, pirmaEil);
            stringstream iss(pirmaEil);
            while(iss >> temp)
            {

                kiekNd++;
            }
            while((std::getline(fileread >> std::ws, line))){
                Studentai s ;
                stringstream iss(line);
                iss >> temp;
                s.setVardas(temp);
                iss >> temp;
                s.setPavarde(temp);
                for(int i = 0; i < kiekNd; i++){
                    iss>> sk;
                    s.addNd(sk);
                }
                iss >> sk;
                s.setEgzaminas(sk);
                s.Vidurkis();
                s.Mediana();
                studentu_kiekis++;

                stud.push_back(s);

            }
        }else{

            throw std::runtime_error(filename);

        }


    } catch(std::exception &e) {
        cout << "Failas "  << e.what() << "neegzistuoja arba neteisingai irasete pavadinima, paleiskite dar karta programa" << endl;
        std::exit(0);

    }

}
bool palyginimas_vardas( Studentai a, Studentai b){
    if (a.getVardas() == b.getPavarde()){

        return a.getPavarde() < b.getPavarde();}

    return a.getVardas() < b.getVardas();
}
bool palyginimas_pavarde( Studentai a, Studentai b){
    if (a.getPavarde() == b.getPavarde()){

        return a.getVardas() < b.getVardas();}

    return a.getPavarde() < b.getPavarde();
}
bool palyginimas_galutinis( Studentai a, Studentai b){
    if (a.getGalutinis() == b.getGalutinis()){

        return a.getVardas() < b.getVardas();}

    return a.getGalutinis() < b.getGalutinis();
}

void Studentai::Failu_kurimas (vector<Studentai> vektorius ,string failo_vardas, int pasirinkimas) {


    ofstream out(failo_vardas);
    stringstream eilute;
    if (pasirinkimas == 1) {
        eilute << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(17) << "Galutinis(vid)" << endl;
        eilute << left << "______________________________________________________________________________" << endl;
        for (int i = 0; i < vektorius.size(); i++) {
            eilute << left << setw(20) << vektorius[i].getVardas() << setw(20) << vektorius[i].getPavarde() << setw(17)
                   << std::fixed
                   << std::setprecision(2) << vektorius[i].getVid() << setw(17) << endl;


        }


    } else if (pasirinkimas == 2) {
        eilute << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(17) << "Galutinis(med)" << endl;
        eilute << left << "________________________________________________________________________________" << endl;
        for (int i = 0; i < vektorius.size(); i++) {
            eilute << left << setw(20) << vektorius[i].getVardas() << setw(20) << vektorius[i].getPavarde() << setw(17)
                   << std::fixed
                   << std::setprecision(2) << vektorius[i].getMed() << setw(17) << endl;


        }


    } else {
        eilute << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(17) << "Galutinis(vid)"
               << setw(20) << "Galutinis(med)" << endl;
        eilute << left << "________________________________________________________________________" << endl;
        for (int i = 0; i < vektorius.size(); i++) {
            eilute << left << setw(20) << vektorius[i].getVardas() << setw(20) << vektorius[i].getPavarde() << setw(17)
                   << std::fixed
                   << std::setprecision(2) << vektorius[i].getVid() << setw(17) << vektorius[i].getMed() << endl;

        }

    }

    out << eilute.str();
    eilute.clear();
    out.close();

}

