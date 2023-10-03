#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <functional>   // std::less_equal, std::bind2nd
#include <algorithm>    // std::count_if

// base abstract class
class Animal {
protected:
    // data field
    int id;
    int age =5;
    std::string name;
    int idAddres;

public:

    std::set<int> talents;


    void setAge(int age) {
        if (age > 15) age = 15;
        this->age = age;
    }

    Animal(int id, std::string name, int age, int idAddres) {
        this->id = id;
        this->name = name;
        this->idAddres = idAddres;
        setAge(age);
    }

    Animal() : Animal(0,"",0,0) {};

    // удаление виртуальных классов
    virtual ~Animal() {}

    int getAge() const {
        return age;
    }

    // голос
    virtual void voice() {};

    void show() {
        std::cout << id << " " << name << ", " << getAge() << std::endl;
    }
};

class Dog : public Animal {
public:
    // constructor
    Dog() : Animal() {}
    Dog(int id, std::string name, int age, int idAddres) : Animal(id, name, age, idAddres) {}

    // here we implement 
    void voice() override {
        if (age <= 1)
            std::cout << name << "\tPii!" << std::endl;
        else
            std::cout << name << "\tGaff!" << std::endl;
    }

};

class Cat : public Animal {
public:
    Cat() : Animal() {}
    Cat(int id, std::string name, int age, int idAddres) : Animal(id, name, age, idAddres) {}

    void voice() override {
        if (age <= 1)
            std::cout << name << "\tMiy!" << std::endl;
        else
            std::cout << name << "\tMoww!" << std::endl;
    }
};

class Address {
public:
    int id;
    std::string street;
    std::string home;
    std::string flat;
    std::string contact;
    std::string name;
    Address(int iid, std::string istreet, std::string ihome,
        std::string iflat, std::string icontact, std::string iname) :
        id(iid), street(istreet), home(ihome), flat(iflat), contact(icontact), name(iname) {}

    Address() {}

};

class Talent {

public:
    int id;
    std::string ability;

    Talent(int iid, std::string iability) :  id(iid), ability(iability) {}

    void show() {
        std::cout << "Я умею " << ability << "\n";
    }

    int getId() {
        return id;
    }

    std::string getAbility() {
        return ability;
    }

};

int main() {

    using namespace std;
    //setlocale(LC_ALL, "Ru"); 

    system("chcp 1251");

    vector <Animal*> an;
    vector <Address> ad;
    vector <Talent> tl;

    int id, idAddres, age;
    string name, ability;

    ifstream  textFile("addres.txt");
    Address a;
    if (textFile) {
        while (!textFile.eof()) {
            textFile >> a.id >> a.street >> a.home >> a.flat >> a.contact >> a.name;
            if (!textFile.eof()) {
                ad.push_back(a);
            }
        }
        textFile.close();
    }
    cout << "------------  Address  --------\n";
    for (auto a: ad)
        cout << a.id << " " << a.street << " " << a.home << " " << a.flat 
             << " " << a.contact << " " << a.name << " " << "\n";


    textFile.open("dogs.txt");
    if (textFile) {
        while (!textFile.eof()) {
            textFile >> id >> name >> age >> idAddres;
            if (!textFile.eof()) {
                an.push_back(new Dog(id, name, age, idAddres));
            }
        }
        textFile.close();
    }

    textFile.open("cats.txt");
    if (textFile) {
        while (!textFile.eof()) {
            textFile >> id >> name >> age >> idAddres;
            if (!textFile.eof()) {
                an.push_back(new Cat(id, name, age, idAddres));
            }
        }
        textFile.close();
    }

    cout << "------------  Animals  --------\n";
    for (int i = 0; i < an.size(); i++)
        an[i]->voice();

    textFile.open("talent.txt");
    tl.push_back(Talent(0, "None"));
    if (textFile) {
        while (!textFile.eof()) {
            textFile >> id >> ability;
            if (!textFile.eof()) {
                tl.push_back(Talent(id, ability));
            }
        }
        textFile.close();
    }

    cout << "------------  Talents  --------\n";
    for (auto a : tl) {
        cout << a.getId() << ": " << a.getAbility() << "\n";
    }

   // init talents
   
    for (auto p : an) {
        for (int i(0); i < rand() % 6; i++) 
            p->talents.insert(1 + (rand() % 6)); 

        for(auto it = p->talents.begin(); it != p->talents.end(); it++)
            cout << *it << ","; 

        cout <<  "  ";
    }


    cout << "\n";

    cout << "Id talent ";
    int tlnt;  cin >> tlnt;

    for (auto p : an) 
        if (p->talents.count(tlnt) != 0)           
           p->show();


    cout << "\n";
   
;

    //int minFlat, maxFlat;
    //cout << "Введите минимальный И максимальный номера квартиры :"; cin >> minFlat >> maxFlat;

    //for (int i = 0; i < cat.size(); i++) {
    //    if (cat.at(i).flat >= minFlat && cat.at(i).flat < maxFlat) {
    //        cat[i].show();
    //        vc.push_back(cat[i].getAge());
    //    }
    //}

    //cout << endl;

    //auto cx = count_if(vc.begin(), vc.end(), bind2nd(less_equal<int>(), 1));
    //cout << "\nКоличество котят до 2-х лет : " << cx << endl;

    //copy(vc.begin(), vc.end(), ostream_iterator<int>(cout, " "));

    return 0;
}