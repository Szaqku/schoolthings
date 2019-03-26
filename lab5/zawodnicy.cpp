#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <fstream>
#include <istream>
#include <exception>

using namespace std;


class zawodnik{
    friend void zapiszDoPliku(string,vector<zawodnik*>);
    private:
    string imie;
    string nazwisko;
    int miejsce1;
    int miejsce2;
    int miejsce3;
    string pesel;
    string dataUrodzenia;

public:
    zawodnik(zawodnik& z);
    ~zawodnik(){};
    zawodnik() : zawodnik("John","Doe",1,2,3,"43895389573","21.12.1222"){};
    zawodnik(string imie,string nazwisko,int miejsce,int miejsce2,int miejsce3,string pesel,string data){
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->miejsce1 = miejsce;
        this->miejsce2 = miejsce2;
        this->miejsce3 = miejsce3;
        this->pesel = pesel;
        this->dataUrodzenia = data;
    }
    void printZawodnik(){
        cout<<this->imie
            <<" "<<this->nazwisko
            <<" "<<this->miejsce1
            <<" "<<this->miejsce2
            <<" "<<this->miejsce3
            <<" "<<this->pesel
            <<" " <<this->dataUrodzenia<<endl;
    }
    void printResults(){
        int suma = (this->miejsce1)
        +this->miejsce2
        +this->miejsce3;
        cout<<this->nazwisko<<" suma:"<<suma<<endl;
    }

    class Converter{
    public:
        static zawodnik* convertLineToZawodnik(string line){
            string zbr[7];
            int i = 0;
            string delimiter = ";";
            size_t pos = 0;
            while((pos = line.find(delimiter)) != string::npos){
                zbr[i++] = line.substr(0,pos);
                line.erase(0,pos + 1);
            }
            zbr[i] = line;
            return new zawodnik(zbr[0],zbr[1],stoi(zbr[2]),stoi(zbr[3]),stoi(zbr[4]),zbr[5],zbr[6]);
        }
    };
};

zawodnik::zawodnik(zawodnik& z){
    this->imie = z.imie;
    this->nazwisko = z.nazwisko;
    this->miejsce1 = z.miejsce1;
    this->miejsce2 = z.miejsce2;
    this->miejsce3 = z.miejsce3;
    this->dataUrodzenia = z.dataUrodzenia;
    this->pesel = z.pesel;
}

vector<zawodnik*> wczytajZawodnikowZPliku(string fileName){
    vector<zawodnik*> zawodnicy;
    ifstream input(fileName);
    if(!input.is_open())
        throw exception();

    string line;
    while(!input.eof()){
        input>>line;
        zawodnicy.push_back(zawodnik::Converter::convertLineToZawodnik(line));
    }

    input.close();

    return zawodnicy;
}

void zapiszDoPliku(string fileName,vector<zawodnik*> zawodnicy){
    ofstream output(fileName);
    if(!output.is_open())
        throw exception();
    for(auto zawodnik : zawodnicy)
        output<<zawodnik->imie<<";"<<zawodnik->nazwisko<<";"<<zawodnik->miejsce1
            <<";"<<zawodnik->miejsce2<<";"<<zawodnik->miejsce3<<";"<<zawodnik->dataUrodzenia
            <<";"<<zawodnik->pesel<<endl;
    output.close();
};

int main(int argc, char** argv) {

    vector<zawodnik*> zawodnicy = wczytajZawodnikowZPliku("input.txt");

    for(auto z : zawodnicy)
        z->printZawodnik();

        zawodnicy.push_back(new zawodnik());
    zapiszDoPliku("output.txt",zawodnicy);

//    int n = 5;
//    vector<zawodnik*> zawodnicy;
//    for(int i = 0 ; i < n ; i++){
//
//        zawodnicy.push_back(new zawodnik("Jan"+to_string(i),"Nazwisko",1,2,3,"345353553","12.12.2012"));
//    }
//
//    zawodnik* z = new zawodnik();
//    zawodnicy.push_back(z);
//    zawodnik* z1 = new zawodnik(*z);
//    zawodnicy.push_back(z1);
//
//    for(auto zawodnik: zawodnicy)
//        zawodnik->printZawodnik();
//
//	return 0;


}
