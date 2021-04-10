//Задание 2. Реализовать сруктуру "Автомобиль" (длина,
//клиренс (высота посадки), объем двигателя, мощность
//двигателя, диаметр колёс, цвет, тип коробки передач).
//Создайте функции для задания значений, отображения
//значений, поиска значений.

#include <iostream>
#include <string>

struct Car {
    std::string model;
    int length;
    int clearance;
    int engineVolume;
    int enginePower;
    int wheelDiameter;
    std::string color;
    std::string transmission;
};

struct Garage {
    Car *garage;
};

Car setupCar(Car*);  //прототип функции задания значений для структур типа Car
void showCar(Car);  //прототип функции для показа переменных структур типа Car
void searchCar(Garage, int);    //прототип функции для объединения функций поиска по структурам Car
//прототипы функций поиска
void searchModel(Garage, int);  
void searchLength(Garage, int);
void searchClearance(Garage, int);
void searchEngineVolume(Garage, int);
void searchEnginePower(Garage, int);
void searchWheelDiameter(Garage, int);
void searchColor(Garage, int);
void searchTransmission(Garage, int);

int main() {

    int size;
    std::cout << "Enter the number of cars: ";
    std::cin >> size;
    std::cout << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //пропуск симфолов для корректного использования функции getline 

    //создаём ссылочную переменную на ссылочную переменную структуры Garage, для удобного хранения и доступа к множеству экземпляров структуры Car 
    Garage garageOne;
    Car* garage = new Car[size];
    garageOne.garage = garage;

    //инициализация структур Car
    for (int i = 0; i < size; i++) {
        garage[i] = setupCar(&garage[i]);
        showCar(garage[i]);
    }

    searchCar(garageOne, size);
   
    return 0;
}

Car setupCar(Car *car) {

    std::cout << "Enter the car model: ";
    std::getline(std::cin, car -> model);
    
    std::cout << "Enter the car length (in centimeters): ";
    std::cin >> car -> length;

    std::cout << "Enter the car clearance (in centimeters): ";
    std::cin >> car -> clearance;

    std::cout << "Enter the car engine volume (in cubic centimeters): ";
    std::cin >> car -> engineVolume;

    std::cout << "Enter the car engine power (in horsepower): ";
    std::cin >> car -> enginePower;

    std::cout << "Enter the car wheel diameter (in centimeters): ";
    std::cin >> car -> wheelDiameter;

    std::cout << "Enter the car color: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, car -> color);
    
    std::cout << "Enter the car transmission (manual, automatic): ";
    std::getline(std::cin, car -> transmission);

    return *car;
}

void showCar(Car car) {

    std::cout << std::endl;
    std::cout << "\t Model - " << car.model << std::endl;
    std::cout << "Length:\t\t" << car.length << " centimeters." << std::endl;
    std::cout << "Clearance:\t" << car.clearance << " centimeters." << std::endl;
    std::cout << "Engine volume:\t" << car.engineVolume << " cubic centimeters." << std::endl;
    std::cout << "Engine power:\t" << car.enginePower << " HP." << std::endl;
    std::cout << "Wheel diameter:\t" << car.wheelDiameter << " centimeters." << std::endl;
    std::cout << "Color:\t\t" << car.color << std::endl;
    std::cout << "Transmission:\t" << car.transmission << std::endl;
    std::cout << std::endl;

}

void searchCar(Garage garage, int size) {

    bool play = true;
    int c;

    while (play) {
        std::cout << "Search mode:" << std::endl;
        std::cout << "\t1.By model. " << std::endl;
        std::cout << "\t2.By length. " << std::endl;
        std::cout << "\t3.By clearance. " << std::endl;
        std::cout << "\t4.By engine volume. " << std::endl;
        std::cout << "\t5.By engine power. " << std::endl;
        std::cout << "\t6.By wheel diameter. " << std::endl;
        std::cout << "\t7.By color. " << std::endl;
        std::cout << "\t8.By transmission. " << std::endl;
        std::cout << "\t0.Exit. " << std::endl;
        std::cin >> c;

        switch (c) {
            case 1:
                searchModel(garage, size);
                break;
            case 2:
                searchLength(garage, size);
                break;
            case 3:
                searchClearance(garage, size);
                break;
            case 4:
                searchEngineVolume(garage, size);
                break;
            case 5:
                searchEnginePower(garage, size);
                break;
            case 6:
                searchWheelDiameter(garage, size);
                break;
            case 7:
                searchColor(garage, size);
                break;
            case 8:
                searchTransmission(garage, size);
                break;
            case 0:
            play = false;
                break;
        default:
            std::cout << "Error!" << std::endl;
            break;
        }
    }
}
//поиск по модели
void searchModel(Garage garage, int size) {

    std::string str;
    bool cond = false;

    std::cout << "Enter model: ";
    std::cin >> str;
    
    std::cout << "Result: " << std::endl;

    for (int i = 0; i < size; i++) {
        if (garage.garage[i].model == str) {
            showCar(garage.garage[i]);
            cond = true;
        }
    }

    if (!cond) {
        std::cout << "There are no such models!" << std::endl;
    }
}
//поиск по длине
void searchLength(Garage garage, int size) {
    int n;
    bool cond = false;

    std::cout << "Enter length: ";
    std::cin >> n;

    std::cout << "Result: " << std::endl;

    for (int i = 0; i < size; i++) {
        if (garage.garage[i].length == n) {
            showCar(garage.garage[i]);
            cond = true;
        }
    }

    if (!cond) {
        std::cout << "There are no cars with this length!" << std::endl;
    }
}
//поиск по высоте клиренса
void searchClearance(Garage garage, int size) {
    int n;
    bool cond = false;

    std::cout << "Enter clearance: ";
    std::cin >> n;

    std::cout << "Result: " << std::endl;

    for (int i = 0; i < size; i++) {
        if (garage.garage[i].clearance == n) {
            showCar(garage.garage[i]);
            cond = true;
        }
    }

    if (!cond) {
        std::cout << "There are no cars with this clearance!" << std::endl;
    }
}
//поиск по объему двигателя
void searchEngineVolume(Garage garage, int size) {
    int n;
    bool cond = false;

    std::cout << "Enter engine volume: ";
    std::cin >> n;

    std::cout << "Result: " << std::endl;

    for (int i = 0; i < size; i++) {
        if (garage.garage[i].engineVolume == n) {
            showCar(garage.garage[i]);
            cond = true;
        }
    }

    if (!cond) {
        std::cout << "There are no cars with this engine volume!" << std::endl;
    }
}
//поик по мощности двигателя
void searchEnginePower(Garage garage, int size) {
    int n;
    bool cond = false;

    std::cout << "Enter engine power: ";
    std::cin >> n;

    std::cout << "Result: " << std::endl;

    for (int i = 0; i < size; i++) {
        if (garage.garage[i].enginePower == n) {
            showCar(garage.garage[i]);
            cond = true;
        }
    }

    if (!cond) {
        std::cout << "There are no cars with this engine power!" << std::endl;
    }
}
//поиск по диаметру колёс
void searchWheelDiameter(Garage garage, int size) {
    int n;
    bool cond = false;

    std::cout << "Enter wheel diameter: ";
    std::cin >> n;

    std::cout << "Result: " << std::endl;

    for (int i = 0; i < size; i++) {
        if (garage.garage[i].wheelDiameter == n) {
            showCar(garage.garage[i]);
            cond = true;
        }
    }

    if (!cond) {
        std::cout << "There are no cars with this wheel diameter!" << std::endl;
    }
}
//поиск по цвету
void searchColor(Garage garage, int size) {
    std::string str;
    bool cond = false;

    std::cout << "Enter color: ";
    std::cin >> str;

    std::cout << "Result: " << std::endl;

    for (int i = 0; i < size; i++) {
        if (garage.garage[i].color == str) {
            showCar(garage.garage[i]);
            cond = true;
        }
    }

    if (!cond) {
        std::cout << "There are no cars with this color!" << std::endl;
    }
}
//поиск по типу коробки передач
void searchTransmission(Garage garage, int size) {
    std::string str;
    bool cond = false;

    std::cout << "Enter transmission type: ";
    std::cin >> str;

    std::cout << "Result: " << std::endl;

    for (int i = 0; i < size; i++) {
        if (garage.garage[i].transmission == str) {
            showCar(garage.garage[i]);
            cond = true;
        }
    }

    if (!cond) {
        std::cout << "There are no cars with this transmission type!" << std::endl;
    }
}