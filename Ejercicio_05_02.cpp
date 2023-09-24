// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 22/09/2023

// Fecha modificación: 22/09/2023

// Número de ejericio: 2

// Problema planteado: De acuerdo con la siguiente estructura, realice en C++ un programa que lea N atletas y
// nos devuelva el país que mayor número de medallas ha ganado.


#include <iostream>
int n;

using namespace std;
int highest(Athlete *atl);
void fillstruct(Athlete *atl);

// Estrcutura de los datos personales del atleta
struct Data{
    char name[40];
    char country[25];
};

// Estructura de los datos del atleta
struct Athlete{
    char sport[30];
    Data pers;
    int medals;
};

// Encuentra la posicion del aleta que tiene mas medallas
int highest(Athlete *atl){
    int h = -1, pos;
    for(int i = 0; i < n; i++){
        if(atl[i].medals > h){
            h = atl[i].medals;
            pos = i;
        }
    }
    return pos;
}

// Llena los datos de n atletas
void fillstruct(Athlete *atl){
    for(int i = 0; i < n; i++){
        cout << "\nAtleta #" << i + 1 << endl;
        cout << "Nombre: ";
        cin.ignore(256, '\n');
        cin.getline(atl[i].pers.name, 40);
        cout << "Pais: ";
        cin.getline(atl[i].pers.country, 40);
        cout << "Deporte: ";
        cin.getline(atl[i].sport, 30);
        cout << "Medallas ganadas: ";
        cin >> atl[i].medals;
    }
}

int main(){
    cout << "Ingrese el numero de atletas: ";
    cin >> n;

    Athlete atl[n];
    fillstruct(atl);
    
    cout << "\n***DATOS DEL ATLETA CON MAS MEDALLAS***" << endl;
    int pos = highest(atl);

    cout << "Nombre: " << atl[pos].pers.name << endl;
    cout << "Pais: " << atl[pos].pers.country << endl;
    cout << "Deporte: " << atl[pos].sport << endl;
    cout << "Numero de medallas: " << atl[pos].medals << endl;
    return 0;
}