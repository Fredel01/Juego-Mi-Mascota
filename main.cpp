#include "Mascota.h"

/**
 * @brief Evita acumulaciones. Limpia pantalla
 */
void limpiar_pantalla() { cout << "\033[2J\033[H"; }
    

/**
 * @brief Inicio del pograma
 */ 
int main() {
    int opcion;
    //Para inicializar el nombre de la mascota
    string nombreMascota; 
    
    //Esta es nuestra mascota 
    Mascota perro(nombreMascota, 0, 0, 0); //Inicializamos los atributos
    perro.set_energia(50); perro.set_hambre(50); perro.set_felicidad(50); //establecemos el punto de partida 

    cout << "Ingrese el nombre de su perrito mascota: ";
    cin >> nombreMascota; perro.set_nombre(nombreMascota);
    cout << "\n";

    do {
        limpiar_pantalla();
        perro.estado_de_la_mascota();
        cout << "\n Hola soy " << nombreMascota << " que vamos a hacer hoy? " << endl;
        cout << " __________________________\n"
             << "|       MENU PRINCIPAL     |     / \\__\n"
             << "|__________________________|   ( o.o )\\____\n"  
             << "| 1. Comer  (^o^)          |    /    ) O\n"
             << "| 2. Jugar  (^-^)          |   /   (_____/\n"
             << "| 3. Dormir (-_-)          |   \\_/   U\n"
             << "| 4. Salir                 |\n"
             << "|__________________________|\n";
        

        cout << "Opcion: "; cin >> opcion;
        //Validamos la entrada
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(10000, '\n');
            cout << "Entrada invalida. Intentalo de nuevo.\n"; cin.get();
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
            cout << "Nos vemos pronto..." << endl;
            break;
        default:
            cout << "Intentalo de nuevo" << endl;
            break;
        }
                
    }while(opcion!=4);

    return 0;
}
//FIN 
