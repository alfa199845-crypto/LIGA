#include <iostream>

using namespace std;

int main() {

    int opcion;

    do {
        cout << "\n=== liga mg ===\n";
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
