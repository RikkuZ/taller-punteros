#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

using namespace std;

// === PUNTO 1: MATRIZ DINÁMICA ===
void punto1() {
    int n, m;
    cout << "\n--- Punto 1: Matriz Dinamica ---\n";
    cout << "Filas (n): "; cin >> n;
    cout << "Columnas (m): "; cin >> m;

    int** matriz = new int*[n];
    for(int i = 0; i < n; i++) matriz[i] = new int[m];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << "Matriz[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        int suma = 0;
        for(int j = 0; j < m; j++) suma += matriz[i][j];
        cout << "Suma fila " << i << ": " << suma << endl;
    }

    // Liberar memoria
    for(int i = 0; i < n; i++) delete[] matriz[i];
    delete[] matriz;
}

// === PUNTO 2: PUNTEROS A FUNCION ===
double cuadrado(double x) { return x * x; }
double doble(double x) { return x * 2; }
double inverso(double x) { return (x != 0) ? 1.0/x : 0; }

void punto2() {
    int tam;
    cout << "\n--- Punto 2: Punteros a Funcion ---\n";
    cout << "Tamano del arreglo: "; cin >> tam;
    double* arr = new double[tam];
    for(int i=0; i<tam; i++) { cout << "Valor " << i << ": "; cin >> arr[i]; }

    cout << "Elija funcion: 1.Cuadrado 2.Doble 3.Inverso: ";
    int op; cin >> op;
    double (*pf)(double) = nullptr;
    if(op==1) pf = cuadrado;
    else if(op==2) pf = doble;
    else pf = inverso;

    for(int i=0; i<tam; i++) cout << pf(arr[i]) << " ";
    cout << endl;
    delete[] arr;
}

// === PUNTO 3 Y 4: LAMBDAS Y BONUS ===
void punto3y4() {
    cout << "\n--- Punto 3 y 4: Lambdas y Bonus ---\n";
    vector<double> arr = {1.0, 2.0, 3.0, 4.0};
    
    // Lambdas
    auto transforma = [](double x) { return x * 2; };
    auto acumula = [](double acc, double val) { return acc + val; };

    // Bonus: Transformaciones encadenadas
    vector<function<double(double)>> pipeline;
    pipeline.push_back([](double x) { return x * 2; }); // x -> x*2
    pipeline.push_back([](double x) { return x + 3; }); // x -> x+3
    pipeline.push_back([](double x) { return pow(x, 2); }); // x -> x^2

    double resultado_final = 0;
    for(double x : arr) {
        double temp = x;
        for(auto& f : pipeline) temp = f(temp);
        resultado_final = acumula(resultado_final, temp);
    }
    cout << "Resultado final encadenado: " << resultado_final << endl;
}

int main() {
    int op;
    do {
        cout << "\n1. Punto 1\n2. Punto 2\n3. Punto 3/4\n4. Salir\nOpcion: ";
        cin >> op;
        if(op==1) punto1();
        else if(op==2) punto2();
        else if(op==3) punto3y4();
    } while(op != 4);
    return 0;
}
