#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;


class zawodnik{
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


int main(int argc, char** argv) {

    int n = 5;
    vector<zawodnik*> zawodnicy;
    for(int i = 0 ; i < n ; i++){

        zawodnicy.push_back(new zawodnik("Jan"+to_string(i),"Nazwisko",1,2,3,"345353553","12.12.2012"));
    }

    zawodnik* z = new zawodnik();
    zawodnicy.push_back(z);
    zawodnik* z1 = new zawodnik(*z);
    zawodnicy.push_back(z1);

    for(auto zawodnik: zawodnicy)
        zawodnik->printZawodnik();

	return 0;
}
