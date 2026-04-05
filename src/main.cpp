#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Equipo {
    string nombre;
    int PJ = 0;
    int PG = 0;
    int PE = 0;
    int PP = 0;
    int GF = 0;
    int GC = 0;
    int DG = 0;
    int PTS = 0;
};

bool comparar(Equipo a, Equipo b) {
    if (a.PTS != b.PTS)
        return a.PTS > b.PTS;
    return a.DG > b.DG;
}

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

            vector<Equipo> tabla;

            for (int i = 0; i < equipos.size(); i++) {
                Equipo e;
                e.nombre = equipos[i];
                tabla.push_back(e);
            }

            ifstream file("data/partidos.txt");

            if (!file.is_open()) {
                cout << "No se pudo abrir partidos.txt\n";
                continue;
            }

            string linea;

            while (getline(file, linea)) {

                stringstream ss(linea);
                string fecha, local, visitante, gL, gV;

                getline(ss, fecha, '|');
                getline(ss, local, '|');
                getline(ss, visitante, '|');
                getline(ss, gL, '|');
                getline(ss, gV, '|');

                int golesLocal = stoi(gL);
                int golesVisitante = stoi(gV);

                for (int i = 0; i < tabla.size(); i++) {

                    if (tabla[i].nombre == local) {
                        tabla[i].PJ++;
                        tabla[i].GF += golesLocal;
                        tabla[i].GC += golesVisitante;

                        if (golesLocal > golesVisitante) {
                            tabla[i].PG++;
                            tabla[i].PTS += 3;
                        } else if (golesLocal == golesVisitante) {
                            tabla[i].PE++;
                            tabla[i].PTS += 1;
                        } else {
                            tabla[i].PP++;
                        }
                    }

                    if (tabla[i].nombre == visitante) {
                        tabla[i].PJ++;
                        tabla[i].GF += golesVisitante;
                        tabla[i].GC += golesLocal;

                        if (golesVisitante > golesLocal) {
                            tabla[i].PG++;
                            tabla[i].PTS += 3;
                        } else if (golesVisitante == golesLocal) {
                            tabla[i].PE++;
                            tabla[i].PTS += 1;
                        } else {
                            tabla[i].PP++;
                        }
                    }
                }
            }

            file.close();
            
            for (int i = 0; i < tabla.size(); i++) {
                tabla[i].DG = tabla[i].GF - tabla[i].GC;
            }

            sort(tabla.begin(), tabla.end(), comparar);

            cout << "\nTABLA DE POSICIONES:\n";

            ofstream fileTabla("data/tabla.txt");

            if (!fileTabla.is_open()) {
                cout << "No se pudo guardar tabla.txt\n";
            }

            for (int i = 0; i < tabla.size(); i++) {

                string linea = tabla[i].nombre + " " +
                               "PJ:" + to_string(tabla[i].PJ) + " " +
                               "PG:" + to_string(tabla[i].PG) + " " +
                               "PE:" + to_string(tabla[i].PE) + " " +
                               "PP:" + to_string(tabla[i].PP) + " " +
                               "GF:" + to_string(tabla[i].GF) + " " +
                               "GC:" + to_string(tabla[i].GC) + " " +
                               "DG:" + to_string(tabla[i].DG) + " " +
                               "PTS:" + to_string(tabla[i].PTS);

                cout << linea << endl;

                if (fileTabla.is_open()) {
                    fileTabla << linea << endl;
                }
            }

            if (fileTabla.is_open()) {
                fileTabla.close();
            }
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
                if (equipos[i] == local) existeLocal = true;
                if (equipos[i] == visitante) existeVisitante = true;
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

            ifstream file("data/partidos.txt");

            if (!file.is_open()) {
                cout << "No se pudo abrir partidos.txt\n";
                continue;
            }

            string linea;

            cout << "\nPARTIDOS REGISTRADOS:\n";

            while (getline(file, linea)) {
                cout << linea << endl;
            }

            file.close();
        }

    } while (opcion != 5);

    cout << "Saliendo del programa...\n";

    return 0;
}
