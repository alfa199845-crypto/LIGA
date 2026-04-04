#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {

    // ================= CONFIG =================
    ifstream file("data/config.txt");

    if (!file.is_open()) {
        cout << "Error: no se pudo abrir config.txt\n";
        return 1;
    }

    string nombre;
    int puntosVictoria = 0;
    int puntosEmpate = 0;
    int puntosDerrota = 0;
    vector<string> equipos;

    string linea;

    while (getline(file, linea)) {

        if (linea == "" || linea[0] == '#') continue;

        stringstream ss(linea);
        string clave, valor;

        getline(ss, clave, '=');
        getline(ss, valor);

        if (clave == "nombre") nombre = valor;
        else if (clave == "puntos_victoria") puntosVictoria = stoi(valor);
        else if (clave == "puntos_empate") puntosEmpate = stoi(valor);
        else if (clave == "puntos_derrota") puntosDerrota = stoi(valor);
        else if (clave == "equipo") equipos.push_back(valor);
    }

    file.close();

    // ======= MENU =====
    int opcion;

    do {
        cout << "\n=== " << nombre << " ===\n"; 
        cout << "1. Ver tabla\n";
        cout << "2. Registrar partido\n";
        cout << "3. Ver jornadas\n";
        cout << "4. Ver partidos\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";

        cin >> opcion;

        if (opcion == 1) {
            cout << "Aqui se mostrara la tabla\n";
        }
        else if (opcion == 2) {
            cout << "Aqui se registrara un partido\n";
        }
        else if (opcion == 3) {
            cout << "Aqui se veran las jornadas\n";
        }
        else if (opcion == 4) {
            cout << "Aqui se veran los partidos\n";
        }

    } while (opcion != 5);

    cout << "Saliendo del programa...\n";

    return 0;
}
