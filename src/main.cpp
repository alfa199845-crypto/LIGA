#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {

    ifstream fileConfig("data/config.txt");

    if (!fileConfig.is_open()) {
        cout << "Error: no se pudo abrir config.txt\n";
        return 1;
    }

    string nombre;
    vector<string> equipos;
    string linea;

    while (getline(fileConfig, linea)) {

        if (linea == "" || linea[0] == '#') continue;

        stringstream ss(linea);
        string clave, valor;

        getline(ss, clave, '=');
        getline(ss, valor);

        if (clave == "nombre") nombre = valor;
        else if (clave == "equipo") equipos.push_back(valor);
    }

    fileConfig.close();

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

            string fecha, local, visitante;
            int golesLocal, golesVisitante;

            cout << "Fecha (YYYY-MM-DD): ";
            cin >> fecha;
            
            cout << "Equipos disponibles:\n";
            for (int i = 0; i < equipos.size(); i++) {
                cout << "- " << equipos[i] << endl;
            }

            cout << "Equipo local: ";
            cin >> local;

            cout << "Equipo visitante: ";
            cin >> visitante;

            bool existeLocal = false;
            bool existeVisitante = false;

            for (int i = 0; i < equipos.size(); i++) {
                if (equipos[i] == local) {
                    existeLocal = true;
                }
                if (equipos[i] == visitante) {
                    existeVisitante = true;
                }
            }

            if (!existeLocal || !existeVisitante) {
                cout << "Error: equipo no existe en la liga\n";
                continue;
            }

            if (local == visitante) {
                cout << "Error: equipos iguales\n";
                continue;
            }

            cout << "Goles local: ";
            cin >> golesLocal;

            cout << "Goles visitante: ";
            cin >> golesVisitante;

            ofstream file("data/partidos.txt", ios::app);

            if (!file.is_open()) {
                cout << "Error al abrir partidos.txt\n";
                continue;
            }

            file << fecha << "|"
                 << local << "|"
                 << visitante << "|"
                 << golesLocal << "|"
                 << golesVisitante << "\n";

            file.close();

            cout << "Partido guardado correctamente\n";
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
