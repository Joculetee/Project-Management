#include <iostream>
#include <cstring>
#include <exception>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Angajat {

    protected:
        char nume[50];
        char prenume[50];
        int varsta;
        static int numarAngajati;

    public:
        // Constructori
        Angajat() {
            strcpy(nume, "");
            strcpy(prenume, "");
            varsta = 0;
            numarAngajati++;
        }

        Angajat(char n[], char p[], int v) {
            strcpy(nume, n);
            strcpy(prenume, p);
            varsta = v;
            numarAngajati++;
        }

        // metoda statica pentru returnarea numarului total de angajati
        static int getNumarAngajati() {
            return numarAngajati;
        }
        static void MottoAngajare(string mesaj) {
            cout << mesaj << endl << endl;
        }
        // Metodele de setare a valorilor membrilor
        void setNume(char n[]) {
            strcpy(nume, n);
        }

        void setPrenume(char p[]) {
            strcpy(prenume, p);
        }

        void setVarsta(int v) {
            varsta = v;
        }

        // Metodele de returnare a valorilor membrilor
        char* getNume() {
            return nume;
        }

        char* getPrenume() {
            return prenume;
        }

        int getVarsta() {
            return varsta;
        }

        // Metoda pentru afisarea informatiilor despre angajat
        void afisare() {
            cout << "Nume: " << nume << " ";
            cout << "Prenume: " << prenume << " ";
            cout << "Varsta: " << varsta << endl<<endl;
        }
};
class Manager : public Angajat {
    protected:
        int nivel;
        bool esteManager;

    public:
        // constructor cu parametri, care apeleaza constructorul din clasa de baza folosind o lista de initializare
        Manager(char n[], char p[], int v, int nivel, bool esteManager)
            : Angajat(n, p, v), nivel(nivel), esteManager(esteManager) {}

        // metoda protejata care modifica nivelul
        void setNivel(int nivel) {
            this->nivel = nivel;
        }

        // metoda de afisare a informatiilor despre manager
        void afisare() {
            Angajat::afisare();
            cout << "Nivel: " << nivel << endl;
            cout << "Este manager: " << esteManager << endl << endl;
        }
};
class Junior : public Angajat {

    protected:
        int nivel;

    public:
        Junior() : Angajat() {
            nivel = 0;
        }

        Junior(char n[], char p[], int v, int nv): Angajat(n, p, v) {
            nivel = nv;
        }

        // Metoda pentru afisarea informatiilor despre junior
        void afisare() {
            Angajat::afisare();
            cout << "Nivel: " << nivel << endl<<endl;
        }
};
class Senior : public Angajat {

    protected:
        int nivel;

    public:
        Senior() : Angajat() {
            nivel = 0;
        }

        Senior(char n[], char p[], int v, int nv) : Angajat(n, p, v) {
            nivel = nv;
        }

        // Metoda pentru afisarea informatiilor despre senior
        void afisare() {
            Angajat::afisare();
            cout << "Nivel: " << nivel << endl<<endl;
        }
};
class Task {
    private:
        char id[20];
        char descriere[50];
        bool finalizat;

    public:
        // Constructori
        Task() {
            strcpy(id, "");
            strcpy(descriere, "");
            finalizat = false;
        }

        Task(char id[], char d[], bool f) {
            strcpy(this->id, id);
            strcpy(descriere, d);
            finalizat = f;
        }

        // Metodele de setare a valorilor membrilor
        void setId(char id[]) {
            strcpy(this->id, id);
        }

        void setDescriere(char d[]) {
            strcpy(descriere, d);
        }

        void setFinalizat(bool f) {
            finalizat = f;
        }

        // Metodele de returnare a valorilor membrilor
        char* getId() {
            return id;
        }

        char* getDescriere() {
            return descriere;
        }

        bool getFinalizat() {
            return finalizat;
        }

        // Metoda pentru afisarea informatiilor despre task
        void afisare() {
            cout << "ID: " << id << endl<<endl;
            cout << "Descriere: " << descriere << endl<<endl;
            cout << "Finalizat: " << (finalizat ? "Da" : "Nu") << endl << endl;
        }
        //Supraincarcarea operatorului "<<"
        void taskID(int i){
            cout<< "ID:" << i << endl<<endl;
        }
        void taskID(char* c){
            cout<< "ID:" << c << endl;
        }
};
class Echipa {
    private:
        char nume[50];
        int nrAngajati;
        Angajat angajati[5];
        Task* tasks[10];
        int nrTasks;

    public:
        // Constructori
        Echipa() {
            strcpy(nume, "");
            nrAngajati = 0;
            nrTasks = 0;
        }

        Echipa(char n[]) {
            strcpy(nume, n);
            nrAngajati = 0;
            nrTasks = 0;
        }
        string getNume() const {
            return nume;
        }
        // Metoda pentru afisarea numelui echipei
        void afisareNume() const {
            cout << "Nume echipa: " << nume << endl;
        }

        // Metode pentru adaugarea si stergerea angajatilor din echipa
        void adaugaAngajat(Angajat a) {
            if(nrAngajati < 5) {
                angajati[nrAngajati++] = a;
            } else {
                cout << "Echipa este plina!\n" << endl;
            }
        }

       void stergeUltimulAngajat() {
           cout << "STERGERE ULTIMUL ANGAJAT\n" << endl;
            if (nrAngajati > 0) {
            nrAngajati--;
            cout << "Angajatul a fost sters cu succes!\n" << endl;
            }
            else {
            cout << "Nu exista angajati in echipa!\n" << endl;
            }
        }
        void afisareAngajati() {
            cout << "AFISARE ANGAJATI\n" << endl;
            cout << "Angajatii echipei " << nume << " sunt:" << endl<< endl;
            for(int i = 0; i < nrAngajati; i++) {
                angajati[i].afisare();
            }
        }

        // Metoda pentru adaugarea unui task in echipa
        void adaugaTask(Task* t) {
            if(nrTasks < 10) {
                tasks[nrTasks++] = t;
            } else {
                cout << "Nu se mai pot adauga task-uri!" << endl;
            }
        }

        // Metoda pentru afisarea informatiilor despre toate task-urile din echipa
        void afisareTasks() {
            cout << "Task-urile echipei " << nume << " sunt:" << endl;
            for(int i = 0; i < nrTasks; i++) {
                tasks[i]->afisare();
            }
        }

        // Metoda pentru a marca un task ca finalizat
        void finalizeazaTask(char* taskId) {
            for(int i = 0; i < nrTasks; i++) {
                if(strcmp(tasks[i]->getId(), taskId) == 0) {
                    tasks[i]->setFinalizat(true);
                    cout << "Task-ul " << taskId << " a fost marcat ca finalizat!" << endl;
                    return;
                }
            }
            cout << "Nu s-a gasit niciun task cu id-ul " << taskId << " in echipa!" << endl;
        }

};
ostream& operator<<(ostream& os, const Echipa& echipa) {
    os << echipa.getNume();
    return os;
}
class Observer {
public:
    virtual void notificare(const string& numeEchipa) = 0;
};
template<typename T>
class Proiect {
private:
    string nume;
    vector<T> echipe;
    vector<Observer*> observatori;

public:
    Proiect(const string& n) : nume(n) {}
    void notificaObservatori(const string& numeEchipa) {
        for (auto observator : observatori) {
            observator->notificare(numeEchipa);
        }
    }
    void inregistreazaObservator(Observer* observator) {
        observatori.push_back(observator);
    }
    void adaugaEchipa(const T& echipa) {
        echipe.push_back(echipa);
        notificaObservatori(echipa);
    }

    void afisareEchipe() const {
        cout << "Echipele proiectului " << nume << " sunt:" << endl;
        for (const auto& echipa : echipe) {
            cout << echipa << endl;
        }
    }

    vector<T>& getEchipe() {
        return echipe;
    }
};

class EchipaObservator : public Observer {
public:
    void notificare(const string& numeEchipa) override {
        cout << "Echipa " << numeEchipa << " a fost adaugata sau stearsa din proiect." << endl;
    }
};
// Specializare pentru clasa Echipa
template<>
class Proiect<Echipa> {
private:
    string nume;
    vector<Echipa> echipe;

public:
    Proiect(const string& n) : nume(n) {}

    void adaugaEchipa(const Echipa& echipa) {
        echipe.push_back(echipa);
    }

    void afisareEchipe() const {
        cout << "Echipele proiectului " << nume << " sunt:" << endl;
        for (const auto& echipa : echipe) {
            cout << echipa << endl;
        }
    }
};
class Buget {
private:
    float* valoare;

public:
    Buget() {
        valoare = new float(0.0);
    }

    Buget(float v) {
        valoare = new float(v);
    }

    Buget(const Buget& b) {
        valoare = new float(*b.valoare);
    }

    ~Buget() {
        delete valoare;
    }

    void setValoare(float v) {
        *valoare = v;
    }

    float getValoare() {
        return *valoare;
    }

    void afisare() {
        cout << "Buget: " << *valoare << endl;
    }
};
class TermenLimita {
  private:
    char data[11];
    char ora[6];

  public:
    TermenLimita() {
        strcpy(data, "01/01/2000");
        strcpy(ora, "00:00");
    }

    TermenLimita(char d[], char o[]) {
        strcpy(data, d);
        strcpy(ora, o);
    }

    void setData(char d[]) {
        strcpy(data, d);
    }

    void setOra(char o[]) {
        strcpy(ora, o);
    }

    char* getData() {
        return data;
    }

    char* getOra() {
        return ora;
    }

    void afisare() {
        cout << "Termen limită: " << data << " " << ora << endl;
    }
};
class EroarePersonalizata : public exception {
public:
const char* what() const throw() {
return "Aceasta este o eroare personalizata";
}
};
// Functia 1 arunca o exceptie de tip runtime_error cu un mesaj specificat
void functie1() {
    throw runtime_error("Aceasta este o eroare de timp de executie");
}

// Functia 2 primeste un numar si arunca o exceptie de tip out_of_range daca numarul este negativ
void functie2(int numar) {
if (numar < 0) {
    throw out_of_range("Numarul trebuie sa fie pozitiv");
}
}

// Functia 3 arunca o exceptie de tip logic_error cu un mesaj specificat
void functie3() {
    throw logic_error("Aceasta este o eroare logica");
}

// Functia 4 arunca o exceptie de tip EroarePersonalizata
void functie4() {
    throw EroarePersonalizata();
}

// Functia 5 contine un bloc try-catch si apeleaza functia 1, prinzand si afisand mesajul unei exceptii daca aceasta apare
void functie5() {
    try {
        functie1();
    }
    catch (exception& e) {
        cout << "Exceptie prinsa in functie5: " << e.what() << endl;
    }
}

// Functia 6 contine un bloc try-catch si apeleaza functia 3, prinzand si afisand mesajul unei exceptii daca aceasta apare, apoi arunca o exceptie de tip EroarePersonalizata
void functie6() {
    try {
        functie3();
    }
    catch (exception& e) {
        cout << "Exceptie prinsa in functie6: " << e.what() << endl;
    throw EroarePersonalizata();
    }
}
int Angajat::numarAngajati = 0;
int main() {
    cout<<"[-------------------------------------]"<<endl;
    cout<<"[----------Clasa-Angajat--------------]"<<endl;
    cout<<"[-------------------------------------]"<<endl<<endl;

    // Crearea unui obiect Angajat
        char nume[] = "Popescu";
        char prenume[] = "Ion";
        Angajat angajat1(nume, prenume, 30);

    // Afisarea informatiilor despre angajat
        angajat1.afisare();

    // Setarea valorilor membrilor
        char nume2[] = "Ionescu";
        char prenume2[] = "Maria";
        angajat1.setNume(nume2);
        angajat1.setPrenume(prenume2);
        angajat1.setVarsta(25);

    // Returnarea valorilor membrilor
        cout << "Nume: " << angajat1.getNume() <<" ";
        cout << "Prenume: " << angajat1.getPrenume() <<" ";
        cout << "Varsta: " << angajat1.getVarsta() << endl<<endl;

    // Afisarea noilor informatii despre angajat
        angajat1.afisare();
    // Creare Angajati
        Angajat a1("Popescu", "Ion", 28);
        Angajat a2("Ionescu", "Maria", 35);
        Angajat a3("Mihai", "Andrei", 23);
    // afisare numar total angajati
        cout << "Numar total angajati: " << Angajat::getNumarAngajati() << endl;
    //afisare motto
        Angajat::MottoAngajare("Veniti in echipa noastra de game-development!");


    cout<<"[-------------------------------------]"<<endl;
    cout<<"[----------Clasa-Task-----------------]"<<endl;
    cout<<"[-------------------------------------]"<<endl<<endl;

    // creare task-uri folosind constructorul implicit
        Task task1("T1", "Implementare functie de autentificare", false);
        Task task2("T2", "Design meniu principal", false);
    //Finalizarea unui task
        task1.setFinalizat(true);
    // Afișarea informațiilor despre obiectul task1 utilizând metoda afisare
        task1.afisare();
    // Afișarea informațiilor despre obiectul task2 utilizând metoda afisare
        task2.afisare();
    //Afisare supraincarcarii operatorului <<
        Task ID;
        ID.taskID(5);
        ID.taskID("A");

    cout<<"[-------------------------------------]"<<endl;
    cout<<"[----------Clasa-Echipa---------------]"<<endl;
    cout<<"[-------------------------------------]"<<endl<<endl;

    // Creare obiect Echipa si adaugare angajati
        Echipa Alpha("Alpha");
        Echipa Beta("Beta");
        Alpha.adaugaAngajat(a1);
        Alpha.adaugaAngajat(a2);
        Alpha.adaugaAngajat(a3);

    // Stergere angajat
        Alpha.stergeUltimulAngajat();
    // Afișarea informațiilor despre obiectul task1 utilizând metoda afisare
        task1.afisare();
    // Afișarea informațiilor despre obiectul task2 utilizând metoda afisare
        task2.afisare();

    // atribuire task-uri la echipa
        Alpha.adaugaTask(&task1);
        Alpha.adaugaTask(&task2);

    // afisare informatii despre echipa si task-uri
        Alpha.afisareNume();
        Alpha.afisareAngajati();
        Alpha.afisareTasks();

    cout<<"[-------------------------------------]"<<endl;
    cout<<"[----------Clasa-Buget----------------]"<<endl;
    cout<<"[-------------------------------------]"<<endl<<endl;
        Buget b1(100.0);
        Buget b2;
        b2 = b1;
        b1.afisare();
        b2.afisare();
        b1.setValoare(200.0);
        b1.afisare();
        b2.afisare();


    cout<<"[-------------------------------------]"<<endl;
    cout<<"[----------Clasa-TermenLimita---------]"<<endl;
    cout<<"[-------------------------------------]"<<endl<<endl;

     //creare deadline
    TermenLimita d1("10.04.2023", "12:00");

    //afisare deadline
    d1.afisare();

    //setare data
    d1.setData("12.04.2023");

    //setare ora
    d1.setOra("18:00");

    //afisare deadline actualizat
    d1.afisare();

    cout<<"[-------------------------------------]"<<endl;
    cout<<"[----------Exceptia-Custom------------]"<<endl;
    cout<<"[-------------------------------------]"<<endl<<endl;

    try {
        functie1();
    }
    catch (runtime_error& e) {
        cout << "Exceptie prinsa in main: " << e.what() << endl;
    }

    try {
        functie2(-1);
    }
    catch (out_of_range& e) {
        cout << "Exceptie prinsa in main: " << e.what() << endl;
    }

    try {
        functie4();
    }
    catch (EroarePersonalizata& e) {
        cout << "Exceptie prinsa in main: " << e.what() << endl;
    }

    try {
        functie5();
    }
    catch (exception& e) {
        cout << "Exceptie prinsa in main: " << e.what() << endl;
    }

    try {
        functie6();
    }
    catch (EroarePersonalizata& e) {
        cout << "Exceptie prinsa in main: " << e.what() << endl<<endl;
    }
    cout<<"[-------------------------------------]"<<endl;
    cout<<"[-----Clasa-Junior-Senior-Manager-----]"<<endl;
    cout<<"[-------------------------------------]"<<endl<<endl;

    Manager manager1("Ionescu", "Maria", 40, 3, true);
    Junior junior1("Georgescu", "Andrei", 25, 1);
    Senior senior1("Stoica", "Cristina", 30, 2);
    manager1.afisare();
    junior1.afisare();
    senior1.afisare();
    cout<<"[-------------------------------------]"<<endl;
    cout<<"[------------Clasa-Proiect------------]"<<endl;
    cout<<"[-------------------------------------]"<<endl<<endl;

    // Exemplu utilizare pentru clasa Proiect cu tip de date generic
    Proiect<string> proiect1("Proiect 1");
    // Crearea observer-ului
    EchipaObservator observer;

    // Adăugarea observer-ului la subiect
    proiect1.inregistreazaObservator(&observer);
    proiect1.adaugaEchipa("Echipa A");
    proiect1.adaugaEchipa("Echipa B");
    proiect1.afisareEchipe();


    // Exemplu utilizare pentru clasa Proiect cu specializare pentru Echipa
    Proiect<Echipa> proiect2("Proiect 2");
    proiect2.adaugaEchipa(Alpha);
    proiect2.adaugaEchipa(Beta);
    proiect2.afisareEchipe();

    vector<string>& echipe = proiect1.getEchipe();

    // Utilizarea functiei utilitare sort din biblioteca standard
    sort(echipe.begin(), echipe.end());

    proiect1.afisareEchipe();

    // Utilizarea functiei utilitare reverse din biblioteca standard
    reverse(echipe.begin(), echipe.end());

    proiect1.afisareEchipe();

    cout << endl;



    return 0;


}
