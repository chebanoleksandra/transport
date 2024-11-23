#include <iostream>
#include <string>
using namespace std;

class Transport
{
protected:
    string name;
    int weight;
    double fuelConp;
public:
    Transport() = default;
    Transport(const char* n, int w, double f)
    {
        name = n;
        weight = w;
        fuelConp = f;
    }
    virtual void deliveryCost()
    {
        cout << "Delivery cost in unknown." << endl;
    }
};

class Car :public Transport
{
public:
    Car() :Transport() {};
    Car(const char* n, int w, double f) :Transport(n, w, f) {};
    void deliveryCost()
    {
        int d;
        cout << "How far is your delivery destination from Odesa? (km) : ";
        cin >> d;
        cout << "Delivery cost = " << d * fuelConp;
    }
};

class Plane :public Transport
{
public:
    Plane() :Transport() {};
    Plane(const char* n, int w, double f) : Transport(n, w, f) {};
    void deliveryCost()
    {
        int d;
        cout << "How far is your delivery destination from Odesa? (km) : ";
        cin >> d;
        cout << "Delivery cost = " << d * fuelConp * 0.1;
    }
};

class Ship :public Transport
{
public:
    Ship() :Transport() {};
    Ship(const char* n, int w, double f) : Transport(n, w, f) {};
    void deliveryCost()
    {
        int d;
        cout << "How far is your delivery destination from Odesa? (km) : ";
        cin >> d;
        cout << "Delivery cost = " << d * fuelConp * 0.001;
    }
};

class Truck :public Transport
{
public:
    Truck() :Transport() {};
    Truck(const char* n, int w, double f) : Transport(n, w, f) {};
    void deliveryCost()
    {
        int d;
        cout << "How far is your delivery destination from Odesa? (km) : ";
        cin >> d;
        cout << "Delivery cost = " << d * fuelConp * 0.5;
    }
};

int main()
{
    Transport* t = nullptr;
    int answ;
    cout << "Choose delivery type: 1 - Car, 2 - Plane, 3 - Ship, 4 - Truck: ";
    cin >> answ;
    switch (answ)
    {
    case(1):
        t = new Car("BMW", 1500, 8.2);
        break;
    case(2):
        t = new Plane("Boeing", 42000, 600);
        break;
    case(3):
        t = new Ship("Marco Polo", 21000000, 150000);
        break;
    case(4):
        t = new Truck("Actros", 8500, 35.5);
        break;
    }
    t->deliveryCost();
}

