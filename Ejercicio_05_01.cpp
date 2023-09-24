// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 22/09/2023

// Fecha modificación: 22/09/2023

// Número de ejericio: 1

// Problema planteado: La información de todos los empleados de la UCB se almacena en una variable tipo
// struct llamada “empleado”.
// La información con que se cuenta es: nombre, ci, departamento y salario.
// Realizar un programa en C++ que lea un array de estructura de los datos de N
// empleados e imprima los siguiente:
// • Empleado con mayor salario
// • Empleado con menor salario
// • Promedio salarial
// • Promedio por departamento
// • Departamento con mayor salario en promedio
// • Departamento con menor salario en promedio
double average(int *s, int n);
void salav(Employee *e, double *salsAv, string *deps);
int lowest(int *x);
int lowest(double *x);
int highest(int *x);
int highest(double *x);
void fillstruct(Employee *e);

#include <iostream>
#include <string>

using namespace std;
int n;

// Estructura con los datos de los empleados
struct Employee{
    int id, salary;
    string name, dep;
};

// Calcula el promedio de los valores de un arreglo
double average(int *s, int n){
    double av = 0;
    for(int i = 0; i < n; i++){
        av += s[i];
    }
    av /= n;
    return av;
}

// Calcula el salario promedio por departamento
void salav(Employee *e, double *salsAv, string *deps){
    int counts[n] = {};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(e[i].dep == e[j].dep){
                salsAv[j] += e[i].salary;
                counts[j]++;
                deps[j] = e[i].dep;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(counts[i] != 0){
            salsAv[i] /= counts[i];
        }
    }
}

// Encuentra la posicion del valor menor de un arreglo
int lowest(int *x){
    int l = 100000, pos;
    for(int i = 0; i < n; i++){
        if(x[i] < l && x[i] > 0){
            l = x[i];
            pos = i;
        }
    }
    return pos;
}

// Encuentra la posicion del valor menor de un arreglo
int lowest(double *x){
    int l = 100000, pos;
    for(int i = 0; i < n; i++){
        if(x[i] < l && x[i] > 0){
            l = x[i];
            pos = i;
        }
    }
    return pos;
}

// Encuentra la posicion del valor mayor de un arreglo
int highest(int *x){
    int h = -1, pos;
    for(int i = 0; i < n; i++){
        if(x[i] > h){
            h = x[i];
            pos = i;
        }
    }
    return pos;
}

// Encuentra la posicion del valor mayor de un arreglo
int highest(double *x){
    int h = -1, pos;
    for(int i = 0; i < n; i++){
        if(x[i] > h){
            h = x[i];
            pos = i;
        }
    }
    return pos;
}

// Llena los datos de n empleados
void fillstruct(Employee *e){
    for(int i = 0; i < n; i++){
        cout << "\nEmpleado #" << i + 1 << endl;
        cout << "Nombre: ";
        cin.ignore(256, '\n');
        getline(cin, e[i].name);
        cout << "CI: ";
        cin >> e[i].id;
        cout << "Departamento: ";
        cin.ignore(256, '\n');
        getline(cin, e[i].dep);
        cout << "Salario: ";
        cin >> e[i].salary;
    }
}

int main(){
    cout << "Ingrese el numero de empleados: ";
    cin >> n;

    Employee e[n];
    
    fillstruct(e);
    int salaries[n];

    for(int i = 0; i < n; i++){
        salaries[i] = e[i].salary; // Guarda los salarios de los empleados
    }    
    
    int hsal = highest(salaries); // Encuentra el salario mayor
    int lsal = lowest(salaries); // Encuentra el salario menor

    double salsAv[n] = {};
    string deps[n] = {};
    salav(e, salsAv, deps); // Encuentra el salario promedio por departamento

    int hav = highest(salsAv);
    int lav = lowest(salsAv);

    cout << "\n\n***REPORTE***" << endl;
    cout << "\nEmpleado con mayor salario: " << e[hsal].name << ", CI: " << e[hsal].id << endl;
    cout << "Empleado con menor salario: " << e[lsal].name << ", CI: " << e[lsal].id << endl;
    cout << "\nPromedio salarial: " << average(salaries, n) << " Bs." << endl;
    cout << "\nPromedio por departamento: " << endl;
    for(int i = 0; i < n; i++){
        if(salsAv[i] != 0){
            cout << "- Departamento " << deps[i] << ": " << salsAv[i] << " Bs." << endl;
        }
    }
    cout << "\nDepartamento con mayor salario en promedio: " << deps[hav] << endl;
    cout << "Departamento con menor salario en promedio: " << deps[lav] << endl;
    return 0;
}