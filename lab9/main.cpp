#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Osoba{
    string imie;
    string nazwisko;
    int wiek;

public:
    Osoba(string imie,string nazwisko,int wiek);
    virtual void display(){
        cout<<imie<<" "<<nazwisko<<" "<<wiek;
    }
    virtual ~Osoba(){};
};

Osoba::Osoba(string imie,string nazwisko,int wiek){
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->wiek = wiek;
}

class Zawodnik : public Osoba{
    string nazwaKlubu;

public:
    Zawodnik(string imie,string nazwisko,int wiek, string nazwa);
    void display();
    ~Zawodnik(){};
};

Zawodnik::Zawodnik(string imie,string nazwisko,int wiek, string nazwa) : Osoba(imie,nazwisko,wiek){
    this->nazwaKlubu = nazwa;
}

void Zawodnik::display(){
    Osoba::display();
    cout<<" "<<nazwaKlubu;
}

class Trener : public Osoba{
    double pensja;

public:
    Trener(string imie,string nazwisko,int wiek, double pensja);
    ~Trener(){};
    void display();
};

Trener::Trener(string imie,string nazwisko,int wiek, double pensja) : Osoba(imie,nazwisko,wiek), pensja(pensja){};

void Trener::display(){
    Osoba::display();
    cout<<" "<<pensja;
}

class Sport {
protected:
    string disciplineName;
public:
    virtual int getDurationOfTraining() = 0;
    virtual string getName(){
        return disciplineName;
    }
};

class Archery : public Sport {
    string placeOfTraining;
public:
    Archery(){this->disciplineName = "Archery"; this->placeOfTraining = "Binowo";}
    int getDurationOfTraining() override {
        return 213;
    }
    string getPlaceOfTraining(){
        return placeOfTraining;
    }
};
class Golf : public Sport {
    string placeOfTraining;
public:
    Golf(){this->disciplineName = "Golf"; this->placeOfTraining = "Stare Czarnowo";}
    int getDurationOfTraining() override {
        return 321;
    }
    string getPlaceOfTraining(){
        return placeOfTraining;
    }
};

int main() {
    vector<Osoba*> osoby;
    osoby.push_back(new Osoba("John","Doe",20));
    osoby.push_back(new Zawodnik("Jane","Doe",22,"Gryffindor"));
    osoby.push_back(new Trener("Tom","Doe",23,19283.0));

    for(auto o : osoby) {
        o->display();
        cout<<endl;
    }

    cout<<setw(20)<<setfill('-')<<"\0";
    cout<<endl;
    static_cast<Osoba*>(osoby[1])->display();
    cout<<endl;
    static_cast<Osoba*>(osoby[2])->display();
    cout<<endl;
    static_cast<Trener*>(osoby[1])->display();
    cout<<endl<<setw(20)<<setfill('-')<<"\0"<<endl;

    vector<Sport*> sports;
    sports.push_back(new Archery);
    sports.push_back(new Golf);

    for(auto s : sports) {
        cout<<s->getName()<<" "
        <<s->getDurationOfTraining();
        if(Archery* a = dynamic_cast<Archery*>(s)) {
            a->getPlaceOfTraining();
            cout<<endl;
        }
        if(Golf* g = dynamic_cast<Golf*>(s))
            g->getPlaceOfTraining();
    }

    return 0;
}