#ifndef MASCOTA_H
#define MASCOTA_H
#include <iostream>
#include <ctime>
using namespace std;
/**
 * @class Mascota
 * @brief Implementa el simulador de Mascota
 */
class Mascota {
private:
    string nombre;
    int energia;
    int hambre;
    int felicidad;

    time_t ultimaHambre;
    time_t ultimaEnergia;
    time_t ultimaFelicidad;
public:
    // Constructor
    Mascota(string, int, int, int);

    // Getters
    string get_nombre() const;
    int get_energia();
    int get_hambre();
    int get_felicidad();

    // Setters individuales con validaciones
    void set_nombre(string);
    void set_energia(int); 
    void set_hambre(int);
    void set_felicidad(int);
    //Metodos de la Mascota
    void estado_de_la_mascota();
    void comer();
    void jugar();
    void dormir();
    //Otros
    void actualizar_estado_mascota();
    void esperar(int);
   
};

//Constructor de la clase Mascota
Mascota::Mascota(string _nombre, int _energia, int _hambre, int _felicidad) {
    nombre = _nombre;
    energia = _energia;
    hambre = _hambre;
    felicidad = _felicidad;
    time(&ultimaHambre);
    time(&ultimaEnergia);
    time(&ultimaFelicidad);
}

// Getters
string get_nombre(string nombre) { return nombre; }
int get_energia(int energia) { return energia; }
int get_hambre(int hambre) { return hambre; }
int get_felicidad(int felicidad) { return felicidad; }

void Mascota::set_nombre(string _nombre) { 
    Mascota::nombre = _nombre; 
}
/**
 * @brief verificamos para modificar los valores
 * @param nuevaEnergia ingresada por el usuario
 */
void Mascota::set_energia(int nuevaEnergia) { 
    if (nuevaEnergia < 0) Mascota::energia = 0; //Evita valores negativos
    else if (nuevaEnergia > 100) Mascota::energia = 100; // Limite maximo
    else Mascota::energia = nuevaEnergia; //se asigna el nuevo valor
}
/**
 * @brief verificamos para modificar los valores
 * @param nuevoHambre ingresada por el usuario
 */
void Mascota::set_hambre(int nuevoHambre) { 
    if (nuevoHambre < 0) Mascota::hambre = 0;   
    else if (nuevoHambre > 100) Mascota::hambre = 100; 
    else Mascota::hambre = nuevoHambre;
}    
//para modificar la felicidad
void Mascota::set_felicidad(int nuevaFelicidad) { 
    if (nuevaFelicidad < 0) Mascota::felicidad = 0;
    else if (nuevaFelicidad > 100) Mascota::felicidad = 100;
    else Mascota::felicidad = nuevaFelicidad;
}
/**
 * @brief Método para mostrar y actualizar el estado de la mascota
 */
void Mascota::estado_de_la_mascota() {
    actualizar_estado_mascota();
    //Este condicional hace que la mascota juegue automaticamente
    if (felicidad <= 40) { set_felicidad(felicidad + 2); set_energia(energia - 4);
        set_hambre(hambre + 3); cout << "\n " 
        << nombre << " ha jugado solo!\n"; }
    cout << "\nNombre: " << nombre << endl
         << "Energia: " << energia << endl 
         << "Hambre: " << hambre << endl
         << "Felicidad: " << felicidad << endl;
    if (hambre >= 80) cout << "\nTengo hambre (T_T)" << endl;
    if (energia <= 10) cout << "\nEstoy muy cansado (-_-)" << endl;
    if (felicidad <= 15) cout << "\nJuguemos (^o^)" << endl;
}
/**
 * @brief Permite seleccionar que alimento dar a la mascota
 * @return al menu principal
 */
void Mascota::comer() {
    int opcion; //Variable para manejar la opcion del usuario
    
    if (hambre == 0) { //Verificar que no sea 0 antes de comer
        cout << "\nTu mascota no tiene hambre en este momento. Vuelve mas tarde \n Presiona Enter para continuar... \n";
        esperar(2000);
        return;
    }
    
    cout << "\nAlimentos disponibles:\n";
    cout << "1. Banano (-10 hambre, +10 energia)\n";
    cout << "2. Tarta de jamon (-30 hambre, +30 energia)\n";
    cout << "3. Tortillas (-5 hambre, +5 energia)\n";
    cout << "4. Concentrado (-50 hambre, +50 energia)\n";

    cout << "Selecciona una opcion (1-4): ";
    cin >> opcion;

    // Validación de entrada
    if (cin.fail()) {
        cin.clear();  // Restablece el estado de cin
        cin.ignore(10000, '\n');  // Limpia el buffer de entrada
        cout << "Entrada invalida. Intentalo de nuevo.\n";
        return;
    }

    switch (opcion) {
        case 1: set_hambre(hambre - 10); set_energia(energia + 10); break;
        case 2: set_hambre(hambre - 30); set_energia(energia + 30); break;
        case 3: set_hambre(hambre - 5); set_energia(energia + 5); break;
        case 4: set_hambre(hambre - 50); set_energia(energia + 50); break;
        default:
            cout << "Opcion no valida. Intentalo de nuevo...\n";
            esperar(2000);
            break;
    }
    cout << "\nGracias por alimentarme (^o^)\n"; esperar(2000);
}
/**
 * @brief Permite jugar con la mascota
 */
void Mascota::jugar() {
    if (energia <= 15) { cout << nombre << " esta muy cansado. Vuelve mas tarde... \n" << endl; cin.ignore();
        cin.get(); return; }
    if (hambre >= 80) { cout << nombre << " tiene mucha hambre :( \n" << endl; cin.ignore(); cin.get(); return; }

    int opcion; //tambien manejamos la opcion del usuario con switch
    cout << "\nQue vamos a jugar hoy? (^o^)" << endl;
    cout << "\n1. Atrapar la pelota (+30 felicidad, +10 hambre, -25 energia)" << endl;
    cout << "2. Perseguir gallinas (+40 felicidad, +20 hambre, -50 energia)\n";
    cout << "3. Escondidas (+20 felicidad, +10 hambre, -15 energia)\n";
    cin >> opcion; 

    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Valor no reconocido. Intentalo de nuevo" << endl;
    }
    switch (opcion) {
    case 1:
        set_felicidad(felicidad + 30); set_hambre(hambre +10); set_energia(energia - 25);break;
    case 2: 
        set_felicidad(felicidad + 40); set_hambre(hambre +20); set_energia(energia - 50);break;
    case 3:
        set_felicidad(felicidad + 20); set_hambre(hambre +10); set_energia(energia - 15);break;
    default:
        cout << "\nOpcion invalida. Por favor intentalo de nuevo\n";
        break;
    }
} 
/**
 * @brief Permite recuperar energias durmiendo
 */
void Mascota::dormir() {
    if (energia == 100) { cout << nombre << " no tiene sueño... "; esperar(3000); return; }
    cout << nombre << " esta durmiendo..." << endl;
    energia = 100; //si tiene las energias al 100 no tiene por qué dormir
    esperar(2000);
}
/** 
 * @brief Permite que la mascota interactue 
 * automaticamente conforme al tiempo
 */
void Mascota::actualizar_estado_mascota() {
    time_t ahora;
    time(&ahora); //Tiempo real
    if (difftime(ahora, ultimaHambre) >= 5.0) { //si pasan 5 segundos aumentar hambre
        set_hambre(hambre + 5);
        time(&ultimaHambre); //Se reinicia 
    }
    if (difftime(ahora, ultimaEnergia) >= 5.0) {
        set_energia(energia - 5);
        time(&ultimaEnergia);
    }
    if (difftime(ahora, ultimaFelicidad) >=5.0) {
        set_felicidad(felicidad - 5);
        time(&ultimaFelicidad);
    }
}
/** 
 * @brief Permite realizar pausas en el tiempo
*/
void Mascota::esperar(int ms) { for(clock_t t=clock(); (clock()-t)*1000/CLOCKS_PER_SEC < ms;); }
#endif
