#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <fstream>
#include <istream>
#include <exception>

using namespace std;

class Osoba{
    friend ostream& operator<<(ostream& o, Osoba& z);

    string imie;
    string nazwisko;
    int wiek;

    public:
    Osoba(string imie,string nazwisko,int wiek);
    virtual void info(){
        cout<<imie<<" "<<nazwisko<<" "<<wiek<<endl;
    }
    virtual ~Osoba(){};
};

ostream& operator<<(ostream& o, Osoba& z){
    return o<<z.imie<<" "<<z.nazwisko<<" "<<z.wiek<<endl;
}

Osoba::Osoba(string imie,string nazwisko,int wiek){
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->wiek = wiek;
}

class Zawodnik : public Osoba{
    friend ostream& operator<<(ostream& o, Zawodnik& z);
    string nazwaKlubu;

    public:
    Zawodnik(string imie,string nazwisko,int wiek, string nazwa);
    void info();
    ~Zawodnik(){};
};

Zawodnik::Zawodnik(string imie,string nazwisko,int wiek, string nazwa) : Osoba(imie,nazwisko,wiek){
    this->nazwaKlubu = nazwa;
}

void Zawodnik::info(){
    Osoba::info();
    cout<<nazwaKlubu<<endl;
}

ostream& operator<<(ostream& o, Zawodnik& z){
       return o<<(static_cast <Osoba &>( z ))<<z.nazwaKlubu<<endl;
}

class Trener : public Osoba{
    friend ostream& operator<<(ostream& o, Trener& z);
    double pensja;

public:
        Trener(string imie,string nazwisko,int wiek, double pensja);
        ~Trener(){};
        void info();
};

Trener::Trener(string imie,string nazwisko,int wiek, double pensja) : Osoba(imie,nazwisko,wiek), pensja(pensja){};

void Trener::info(){
    Osoba::info();
    cout<<"Pensja: "<<pensja<<endl;
}

ostream& operator<<(ostream& o, Trener& z){
       return o<<(static_cast <Osoba &>( z ))<<z.pensja<<endl;
}

int main(int argc, char** argv) {
    vector<Osoba*> osoby;

    Osoba* os = new Osoba("John","Doe",23);
    Zawodnik* z = new Zawodnik("Bob","Nowakowski",11,"Klub2");
    Trener* t = new Trener("Jane","Doe",65,236847.0);

    cout<<(*os)<<(*z)<<(*t)<<endl;

    osoby.push_back(os);
    osoby.push_back(z);
    osoby.push_back(t);

    for(auto os: osoby)
        os->info();
}
