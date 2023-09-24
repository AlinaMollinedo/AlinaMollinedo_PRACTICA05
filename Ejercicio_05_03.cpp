// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 22/09/2023

// Fecha modificación: 22/09/2023

// Número de ejericio: 3

// Problema planteado: Realice un programa en C++ con funciones y estructuras para el estacionamiento del
// Multicine.
// Este estacionamiento cuenta con 4 pisos, cada piso tiene distintas capacidades de
// autos
// Piso 1 – 50 autos
// Piso 2 – 40 autos
// Piso 3 – 30 autos
// Piso 4 – 45 autos
// El estacionamiento debe recibir varios tipos de autos (vagoneta, camionetas,
// automóviles, minivans y motocicletas), marca del auto, modelo del auto y color del
// auto.
// Escribir un programa en C++ utilizando funciones y estructuras para:
// • Simular la entrada de vehículos, el programa debe pedir la cantidad de
// vehículos ingresados y el programa debe simular los tipos de vehículo, la
// marca, el modelo, el color y en que piso se han estacionado.
// • La simulación puede repetirse varias veces hasta que el usuario ingrese el valor
// de 0 (cero) en la cantidad de vehículos. La cantidad de vehículos debe se
// incremental.
// • Luego de cada ingreso de vehículos se desea saber cuantos hay estacionado en
// cada piso.
// • Cuantos son vagoneta, camionetas, automóviles, minivans y motocicletas.
// • Hacer un reporte por colores de autos, modelo y marca.
// • La simulación debe determinar cuando el parqueo se ha llenado.
// • La simulación debe determinar cuántos espacios libres queda.

#include <iostream>
#include <string>

using namespace std;
int n, total = 165, cc = 0;
void printv(string *v, int *c);
void count(string *v, int *c);
void merge(Car *all, Car *cars);
bool verifyFloor(Floor *f, int ff);
int verifyParking(int n);
void fillstruct(Car *c, Floor *f);

// Estrcutura para guardar los datos de un piso
struct Floor{
    int capacity, cars = 0;
};

// Estructura para guardar los datos de un auto
struct Car{
    string type, brand, model, color;
    Floor floor;
};

// Imprime los datos de vehiculos y cuantas veces se repite en el estacionamiento
void printv(string *v, int *c){
    for(int i = 0; i < cc; i++){
        if(c[i] != 0){
            cout << v[i] << ": " << c[i] << endl;
        }
    }
}

// Cuenta los tipos, modelos, marcas y colores de vehiculos 
void count(string *v, int *c){\
    for(int i = 0; i < cc; i++){
        for(int j = 0; j < cc; j++){
            if(v[i] == v[j]){
                c[j]++;
                break;
            }
        }
    }
}

// Coloca todos los vehiculos ingresados en un solo arreglo
void merge(Car *all, Car *cars){
    for(int i = cc; i < cc + n; i++){
        all[i] = cars[i - cc];
    }
    cc += n;
}

// Verifica que el piso ingresado tenga espacios libres
bool verifyFloor(Floor *f, int ff){
    if(f[ff].capacity - f[ff].cars == 0){
        cout << "Piso lleno. Intente otro piso.";
        return false;
    }
    else{
        return true;
    }
}

// Verifica que el estacionamiento no este lleno
int verifyParking(int n){
    if(total - n < 0){
        cout << "Solo quedan " << total << " espacios. ";
        n = total;
        cout << "Ingresando " << n << " vehiculos." << endl;
    }
    return n;
}

// Llena los datos de n vehiculos
void fillstruct(Car *c, Floor *f){
    int ff;
    for(int i = 0; i < n; i++){
        cout << "\nAuto #" << i + 1 << endl;
        cout << "Tipo: ";
        cin.ignore(256, '\n');
        getline(cin, c[i].type);
        cout << "Modelo: ";
        getline(cin, c[i].model);
        cout << "Marca: ";
        getline(cin, c[i].brand);
        cout << "Color: ";
        getline(cin, c[i].color);
    
        do{
            cout << "En que piso se va a estacionar?: ";
            cin >> ff;
        }
        while(!verifyFloor(f, ff));
        f[ff - 1].cars++;
    }
}

int main(){
    Floor f[4];
    f[0].capacity = 50;
    f[1].capacity = 40;
    f[2].capacity = 30;
    f[3].capacity = 45;

    Car all[165] = {};

    do{
        if(total != 0){
            cout << "\nCuantos vehiculos van a ingresar?: ";
            cin >> n;
            n = verifyParking(n);
        }
        else{
            cout << "Parqueo lleno." << endl;
            break;
        }
        total -=n;
        Car cars[n];
        fillstruct(cars, f);
        merge(all, cars);
    }
    while(n != 0);
    
    string types[5] = {}, models[cc] = {}, brands[cc] = {}, colors[cc] = {};
    for(int i = 0; i < cc; i ++){
        types[i] = all[i].type;
        models[i] = all[i].model;
        brands[i] = all[i].brand;
        colors[i] = all[i].color;
    }

    int ctypes[cc] = {}, cmodels[cc] = {}, cbrands[cc] = {}, ccolors[cc] = {};
    count(types, ctypes);
    count(models, cmodels);
    count(brands, cbrands);
    count(colors, ccolors);

    cout << "\n\n***REPORTE***" << endl;
    cout << "\nVehiculos estacionado por piso: " << endl;
    for(int i = 0; i < 4; i++){
        cout << "- Piso " << i + 1 << ": " << f[i].cars << endl;
    }
    cout << "\nTipos de vehiculos: " << endl;
    printv(types, ctypes);
    cout << "\nModelos de vehiculos: " << endl;
    printv(models, cmodels);
    cout << "\nMarcas de vehiculos: " << endl;
    printv(brands, cbrands);
    cout << "\nColores de vehiculos: " << endl;
    printv(colors, ccolors);
    cout << "\nEspacios libres: " << total << endl;
    return 0;
}