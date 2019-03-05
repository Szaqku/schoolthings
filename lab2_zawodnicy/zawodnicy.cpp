#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct zawodnik{
    string nazwisko;
    int miejsce1;
    int miejsce2;
    int miejsce3;
};

void info(zawodnik* zawodnik){
    cout<<zawodnik->nazwisko
    <<" "<<zawodnik->miejsce1
    <<" "<<zawodnik->miejsce2
    <<" "<<zawodnik->miejsce3<<endl;
}

void info(zawodnik* zawodnik, char* format){
    printf(format,zawodnik->nazwisko,zawodnik->miejsce1,zawodnik->miejsce2,zawodnik->miejsce3);
}

int info(zawodnik *zawodnik,int nrWyscigu){
    switch(nrWyscigu){
        case 1: return zawodnik->miejsce1; break;
        case 2: return zawodnik->miejsce2; break;
        case 3: return zawodnik->miejsce3; break;
        default: return -1;
    }
}
string info(zawodnik* zawodnik, string prefix){
    return prefix + zawodnik->nazwisko;
}

string info(zawodnik* zawodnik, string prefix, string postfix){
    return prefix + zawodnik->nazwisko + postfix;
}
int suma(zawodnik *zawodnik){
    return zawodnik->miejsce1 + zawodnik->miejsce2 + zawodnik->miejsce3;
}

void printArray(zawodnik* zawodnicy, int n){
    for(int i = 0 ; i < n ; i ++)
        info(&zawodnicy[i]);
}

void printResults(zawodnik* zawodnicy, int n){
    int suma;
    for(int i = 0 ; i < n ; i++){
        suma = (zawodnicy[i].miejsce1)
        +zawodnicy[i].miejsce2
        +zawodnicy[i].miejsce3;
        cout<<zawodnicy[i].nazwisko<<" suma:"<<suma<<endl;
    }
}

int main(int argc, char** argv) {

    cout << "Hello World !"<<endl;

    struct zawodnik* z = new struct zawodnik[1];

    cin>>z->nazwisko;
    cin>>z->miejsce1;
    cin>>z->miejsce2;
    cin>>z->miejsce3;

    info(z);

    int n = 5;

    zawodnik* zawodnicy = new zawodnik[n];

    for(int i = 0 ; i < n ; i ++){
        zawodnicy[i]= {"NazwiskoZawodnika",1,i,5};
    }

    printArray(zawodnicy,n);

    printf("\n");

    printResults(zawodnicy,n);

	return 0;
}
