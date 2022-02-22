#include <iostream>
#include <fstream>
using namespace std;
#include <cstring>

// This file is ONLY an example of how to load a struct from a file



// Creates the struct 
struct CarName{
  enum {MAX_CHAR_LEN=100};
char CarN[100];
double MPG;
int Cylinders;
double Displacement;
double Horsepower;
double Weight;
double Acceleration;
int Model;
char Origin[100];
bool ValidEntry;
bool isValid;

    CarName();
};
//prints all the cars in the file
void printcar(CarName car);
const int MAX_CAR=500;
//constructor
CarName:: CarName() {

  for  (int x =0 ; x <100; x++){
    CarN[x] = '\0';
    Origin[x] = '\0';
  }
  MPG = 0;
 Cylinders = 0;
 Displacement = 0;
 Horsepower = 0;
 Weight = 0;
 Acceleration = 0;
Model = 0;


}
//Readas cars from file
CarName readcar(ifstream &inFile){
  
    CarName car; 
    inFile.get(car.CarN,(CarName::MAX_CHAR_LEN),';');
    inFile.ignore(100,';');
    inFile >>(car.MPG);
    inFile.ignore(100,';');
    inFile >>(car.Cylinders);
    inFile.ignore(100,';');
    inFile >>(car.Displacement);
    inFile.ignore(100,';');
    inFile >>(car.Horsepower);
    inFile.ignore(100,';');
    inFile >>(car.Weight);
    inFile.ignore(100,';');
    inFile >>(car.Acceleration);
    inFile.ignore(100,';');
    inFile >>(car.Model);
    inFile.ignore(100,';');
    inFile >>(car.Origin);
    inFile.ignore(100,'\n');
   
    
    
    
    // If we reached the end of the file while reading, then the entry is not valid
  car.isValid = !inFile.eof();
    return(car);
}

// Reads int
int readInt(const char prompt[]){
    int temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}
// Reads double 
double readDouble (const char prompt[]){ 
    double temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;

}
// reads all the cars in the file
int readCars(CarName Cars[]) {
    ifstream carFile("cars.txt");
    int numcar = 0;
    
    while(carFile.peek() != EOF && numcar < MAX_CAR) {
        Cars[numcar] = readcar(carFile);
        numcar++;
    }
    return numcar;
    
}
// Prints the information of a single car
 void printcar(CarName car) 
 {
   

    cout << car.CarN << ';' << car.MPG << ';' << car.Cylinders << ';' << car.Displacement << ';' <<car.Horsepower << ';' <<car.Weight << ';' <<car.Acceleration << ';' << car.Model << ';' << car.Origin  << ';';
    
}
//prints all the cars

void printcars (CarName car[]){
  for (int x = 0; x < 406; x++){
   if (car[x].isValid == true){
    cout << "Index: " << x << " ";
    printcar(car[x]);
    cout << endl;
   }
  }
}
// prints all the cars 
void printCarsByOrigin (CarName car[]){
  string Eorigin = "";
  cout <<"Enter origin place: ";
  cin >> Eorigin;

  for (int x = 0; x < 407; x++){
   
    if (car[x].Origin == Eorigin){
    printcar(car[x]);
    cout << endl;
    }
    
  }
}
// removesCar
void removeCar (CarName car[]){
  int num = -1;
  while ( num < 0 || num > 500 ){ 
  num = readInt("Enter index to delete: ");
 
  }
   car[num].isValid = false;
  }


// adds car
void addCar (CarName car1[]){
 


  for (int x = 0; x < MAX_CAR; x++){
   
    if (car1[x].isValid == false){
cout << "Enter the details of the car" << endl;
cout << "Car Name :";
//cin.ignore(100, '\n');
cin.getline(car1[x].CarN,MAX_CAR);



car1[x].MPG = readInt ("Enter MPG of the car: ");
car1[x].Cylinders = readInt ("Car Cylinders :");
car1[x].Displacement = readInt ("Car's traveled distance :");
car1[x].Horsepower = readInt ("Car's Horsepower :");
car1[x].Weight = readInt ("Car's Weight :");
car1[x].Acceleration = readInt ("Car's Acceleration :");
car1[x].Model = readInt ("Car's Model :");


cout << "Car's origin :";
cin.ignore(100, '\n');
cin.getline(car1[x].Origin,MAX_CAR);

break;
   
 
    }
  }
}
// main
int main() {
  CarName car[MAX_CAR]; 
    int num = readCars(car);
    cout << "Nums: " << num << endl;
    
 
  
   int numb = 0;
   while (numb != -1){
    cout << '\n';
    cout << "Enter 1 to remove car" << endl;
    cout << "Enter 2 to add car" << endl;
     cout << "Enter 3 to display cars by origin" << endl;
     cout << "Enter 4 to display cars" << endl;
     numb = readInt( "Enter -1 to leave");
     cout << endl;
     cin.ignore(100,'\n');

if (numb == 1){
  removeCar(car);
} else if (numb == 2){
addCar(car);
} else if (numb == 3){
  printCarsByOrigin(car);
} else if ( numb == -1){
  break;
} else  if (numb == 4) {

  printcars(car);
} else {
  cout <<"invalid function";
}




  }
    return 0;
}
