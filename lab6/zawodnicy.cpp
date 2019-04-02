#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <fstream>
#include <istream>
#include <exception>

using namespace std;

class Chomik {};

class Zawodnik{
    friend void zapiszDoPliku(string,vector<Zawodnik*>);
public:
    class Klub;

    Zawodnik(Zawodnik& z);
    ~Zawodnik(){};
    Zawodnik();
    Zawodnik(string,string,int,int,int,string,string);
    void printZawodnik();
    void printResults();
    void setKlub(Klub*);
    Klub* getKlub();

    class Converter;

private:
    Klub* klub;
    string imie;
    string nazwisko;
    int miejsce1;
    int miejsce2;
    int miejsce3;
    string pesel;
    string dataUrodzenia;
};
class Zawodnik::Klub{
    friend class Chomik;

    string name;
public:
    Klub();
    Klub(string);
    string const getName();
    void setName(string);
};

Zawodnik::Klub::Klub() : name("NazwaKlubu") {};
Zawodnik::Klub::Klub(string n) : name(n){};
string const Zawodnik::Klub::getName(){
        return this->name;
}


Zawodnik::Zawodnik() : Zawodnik("John","Doe",1,2,3,"43895389573","21.12.1222"){};
Zawodnik::Zawodnik(string imie,string nazwisko,int miejsce,int miejsce2,int miejsce3,string pesel,string data){
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->miejsce1 = miejsce;
        this->miejsce2 = miejsce2;
        this->miejsce3 = miejsce3;
        this->pesel = pesel;
        this->dataUrodzenia = data;
        this->klub = new Klub();    }
Zawodnik::Zawodnik(Zawodnik& z){
    this->imie = z.imie;
    this->nazwisko = z.nazwisko;
    this->miejsce1 = z.miejsce1;
    this->miejsce2 = z.miejsce2;
    this->miejsce3 = z.miejsce3;
    this->dataUrodzenia = z.dataUrodzenia;
    this->pesel = z.pesel;
    this->klub = z.klub;
}
void Zawodnik::printZawodnik(){
        cout<<this->imie
            <<" "<<this->nazwisko
            <<" "<<this->miejsce1
            <<" "<<this->miejsce2
            <<" "<<this->miejsce3
            <<" "<<this->pesel
            <<" "<<this->klub->getName()
            <<" " <<this->dataUrodzenia<<endl;
    }
void Zawodnik::printResults(){
        int suma = (this->miejsce1)
        +this->miejsce2
        +this->miejsce3;
        cout<<this->nazwisko<<" suma:"<<suma<<endl;
    }

class Zawodnik::Converter{
    public:
        static Zawodnik* convertLineToZawodnik(string,string);
};

Zawodnik* Zawodnik::Converter::convertLineToZawodnik(string line,string delimiter){
    string zbr[7];
    int i = 0;
    size_t pos = 0;
    while((pos = line.find(delimiter)) != string::npos){
        zbr[i++] = line.substr(0,pos);
        line.erase(0,pos + 1);
    }
    zbr[i] = line;
    return new Zawodnik(zbr[0],zbr[1],stoi(zbr[2]),stoi(zbr[3]),stoi(zbr[4]),zbr[5],zbr[6]);
}

vector<Zawodnik*> wczytajZawodnikowZPliku(string fileName){
    vector<Zawodnik*> zawodnicy;
    ifstream input(fileName);
    if(!input.is_open())
        throw exception();

    string line;
    while(!input.eof()){
        input>>line;
        zawodnicy.push_back(Zawodnik::Converter::convertLineToZawodnik(line,";"));
    }

    input.close();

    return zawodnicy;
}

void zapiszDoPliku(string fileName,vector<Zawodnik*> zawodnicy){
    ofstream output(fileName);
    if(!output.is_open())
        throw exception();
    for(auto Zawodnik : zawodnicy)
        output<<Zawodnik->imie
			<<";"<<Zawodnik->nazwisko
			<<";"<<Zawodnik->miejsce1
            <<";"<<Zawodnik->miejsce2
			<<";"<<Zawodnik->miejsce3
			<<";"<<Zawodnik->dataUrodzenia
            <<";"<<Zawodnik->pesel<<endl;
    output.close();
};


void Zawodnik::Klub::setName(string name){
        this->name = name;
}

Zawodnik::Klub* Zawodnik::getKlub(){
    return this->klub;
}

void Zawodnik::setKlub(Klub* klub){
    this->klub = klub;
}

int main(int argc, char** argv) {

    Zawodnik* zawodnik = new Zawodnik();
    zawodnik->setKlub(new Zawodnik::Klub("Hehe"));

    zawodnik->printZawodnik();
}
