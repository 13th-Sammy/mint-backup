#include<iostream>
#include<string>
using namespace std;
class Vehicle{
    public:
    string color; int maxSpeed;
    Vehicle(string c, int ms){
        color = c;
        maxSpeed = ms;
    }   
    void displayDetails(){
        cout << "Color - " << color << endl;
        cout << "Max Speed - " << maxSpeed << endl;
    }
    void honkHorn(){
        cout << "HONK!!!\n";
    }
};
class Car:public Vehicle{
    public:
    string transmissionType; int numDoors;
    Car(string c, int ms, string tt, int nd):Vehicle(c, ms){
        transmissionType = tt;
        numDoors = nd;
    }
    void displayCarDetails(){
        cout << "Color - " << color << endl;
        cout << "Max Speed - " << maxSpeed << endl;
        cout << "Transmission type - " << transmissionType << endl;
        cout << "Number of Doors - " << numDoors << endl;
    }
};
class Motorcycle:public Vehicle{
    public:
    int engineCapacity;
    Motorcycle(string c, int ms, int ec):Vehicle(c, ms){
        engineCapacity = ec;
    }
    void displayMotorcycleDetails(){
        cout << "Color - " << color << endl;
        cout << "Max Speed - " << maxSpeed << endl;
        cout << "Engine Capacity - " << engineCapacity << endl;
    }
};
int main(){
    Car car("Red", 150, "type1", 4);
    Motorcycle bike("Black", 120, 10);
    car.honkHorn();
    bike.honkHorn();
    car.displayCarDetails();
    car.displayDetails();
    bike.displayMotorcycleDetails();
    bike.displayDetails();
    return 0;
}