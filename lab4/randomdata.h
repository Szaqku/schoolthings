#ifndef RANDOMDATA_H
#define RANDOMDATA_H


class RandomData{
    static vector<string> names = {"John"};
    static vector<string> surrnames = {"Doe"};
    static vector<string> emailPrefixes = {"gmail.com"};
    int min;
    int max;

    public:
        RandomData();
        virtual ~RandomData();

        string getRandomName();
        string getRandomSurrname();
        string getRandomEmail();


};

#endif // RANDOMDATA_H
