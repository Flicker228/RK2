#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <Windows.h> 


class Vehicle {
protected:
    std::string mark, model;
public:
    Vehicle(const std::string& mark, const std::string& model) : mark(mark), model(model) {}
    ~Vehicle() {}

    void setMark(const std::string& newMark) {
        mark = newMark;
    }

    void setModel(const std::string& newModel) {
        model = newModel;
    }     

    virtual void displayInfo() const {
        std::cout << "Марка: " << mark << ", модель: " << model << std::endl;
    }
};

class Car : public Vehicle {
private:
    int doorQuantity;
public:
    Car(const std::string& mark, const std::string& model, int doorQuantity) : Vehicle(mark, model), doorQuantity(doorQuantity) {}

    void displayInfo() const override {
        std::cout << "Макрка автомобиля: " << mark << ", модель автомобиля: " << model << ", количество дверей: " << doorQuantity << std::endl;
    }
    ~Car() {};
};

class Motocycle : public Vehicle {
private:
    std::string type;
public:
    Motocycle(const std::string& mark, const std::string& model, const std::string& type) : Vehicle(mark, model), type(type) {}
    void displayInfo() const override {
        std::cout << "Макрка мотоцикла: " << mark << ", модель мотоцикла: " << model << ", тип мотоцикла: " << type << std::endl;
    }
    ~Motocycle() {};
};

void modifyVehicle(Vehicle* vehicle, const std::string& newMark, const std::string& newModel) {
    vehicle->setMark(newMark);
    vehicle->setModel(newModel);
}


int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Vehicle veh1("BMW", "model1");
    Car* car1 = new Car("BMW", "model1", 4);
    Car* car2 = new Car("Volvo", "model2", 4);
    Motocycle* moto1 = new Motocycle("Kavasaki", "model3", "racing");
    Motocycle* moto2 = new Motocycle("Cargo", "model4", "racing");
    std::list<Vehicle*> vehicles = { car1, car2, moto1, moto2 };

    modifyVehicle(car1, "Opel", "model5");

    for (const auto it : vehicles) {
        it->displayInfo();
    }

    return 0;
}
