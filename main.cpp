#include <iostream>
#include <cstring>
using namespace std;
class Angajat {

    private:
        char nume[50];
        char prenume[50];
        int varsta;

    public:
        // Constructori
        Angajat() {
            strcpy(nume, "");
            strcpy(prenume, "");
            varsta = 0;
        }

        Angajat(char n[], char p[], int v, float s) {
            strcpy(nume, n);
            strcpy(prenume, p);
            varsta = v;
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

        // Metoda pentru afisarea numelui echipei
        void afisareNume() {
            cout << "Nume echipa: " << nume << endl<< endl;
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
int main() {
    cout<<"[-------------------------------------]"<<endl;
    cout<<"[----------Clasa-Angajat--------------]"<<endl;
    cout<<"[-------------------------------------]"<<endl<<endl;

    // Crearea unui obiect Angajat
        char nume[] = "Popescu";
        char prenume[] = "Ion";
        Angajat angajat1(nume, prenume, 30, 2000.0);

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


    // Creare Angajati
        Angajat a1("Popescu", "Ion", 28, 3000);
        Angajat a2("Ionescu", "Maria", 35, 4500);
        Angajat a3("Mihai", "Andrei", 23, 2000);

    // Creare obiect Echipa si adaugare angajati
        Echipa Alpha("Alpha");
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

    return 0;


}
