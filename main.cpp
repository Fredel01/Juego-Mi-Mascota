#include "Mascota.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int opcion;
    string nombreMascota;
    
    Mascota perro(nombreMascota, 0, 0, 0);
    perro.setEnergia(50); perro.setHambre(50); perro.setFelicidad(50);

    cout << "Ingrese el nombre de su perrito mascota: ";
    cin >> nombreMascota; perro.setNombre(nombreMascota);
    cout << "\n";

    do {
        perro.limpiar_pantalla();
        perro.estado_de_la_mascota();
        cout << "\n Hola soy " << nombreMascota << " ¿que vamos a hacer hoy? ▼(´ᴥ`)▼" << endl;
        cout << "╔══════════════════════════╗\n"
             << "║       MENÚ PRINCIPAL     ║\n"
             << "╠══════════════════════════╣\n"
             << "║ 1. Comer  (^o^)          ║\n"
             << "║ 2. Jugar  (^-^)          ║\n"
             << "║ 3. Dormir (-_-)          ║\n"
             << "║ 4. Salir                 ║\n"
             << "╚══════════════════════════╝\n";
        cout << "Opcion: \n"; cin >> opcion;

        //Validamos la entrada
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(10000, '\n');
            cout << "Entrada inválida. Inténtalo de nuevo.\n"; cin.get();
            continue;
        }
        switch (opcion) {
        case 1: 
            perro.comer();
            break;
        case 2:
            perro.jugar();
            break;
        case 3: 
            perro.dormir();
            break;
        case 4:
            cout << "Nos vemos pronto （⌒▽⌒）" << endl;
            break;
        default:
            cout << "Intentalo de nuevo" << endl;
            break;
        }
                
    }while(opcion!=4);

    return 0;
}
