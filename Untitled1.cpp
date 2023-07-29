#include <iostream>
#include <cstring>
using namespace std;

class person {
protected:
    char name[20];
    int code;

public:
    person(char n[], int c) {
        strcpy(name, n);
        code = c;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Code: " << code << endl;
    }
};

class account : virtual public person {
protected:
    float pay;

public:
    account(char n[], int c, float p) : person(n, c) {
        pay = p;
    }

    void display() {
        person::display();
        cout << "Pay amount: " << pay << endl;
    }
};

class admin : virtual public person {
protected:
    char experience[20];

public:
    admin(char n[], int c, char e[]) : person(n, c) {
        strcpy(experience, e);
    }

    void display() {
        person::display();
        cout << "Experiences: " << experience << endl;
    }
};

class master : virtual public account, virtual public admin {
public:
    master(char n[], int c, char e[], float p) : person(n, c), account(n, c, p), admin(n, c, e) {}

    void display() {
        person::display();
        cout << "Experienced: " << experience << endl;
        cout << "Pay: " << pay << endl;
    }
};

int main() {
    master m("Abhinav", 450, "teaching", 124000);
    m.display();
    return 0;
}

