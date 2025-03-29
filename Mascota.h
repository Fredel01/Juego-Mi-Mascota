#ifndef MASCOTA_H
#define MASCOTA_H
#include <iostream>
#include <windows.h>

using namespace std;

class Mascota {
private:
    string nombre;
    int energia;
    int hambre;
    int felicidad;

public:
    // Constructor
    Mascota(string, int, int, int);

    // Getters
    string getNombre() const;
    int getEnergia();
    int getHambre();
    int getFelicidad();

    // Setters individuales con validaciones
    void setNombre(string);
    void setEnergia(int); 
    void setHambre(int);
    void setFelicidad(int);
    //Metodos de la Mascota
    void estado_de_la_mascota();
    void comer();
    void jugar();
    void dormir();
    void limpiar_pantalla();
};

//Constructor de la clase Mascota
Mascota::Mascota(string _nombre, int _energia, int _hambre, int _felicidad) {
    nombre = _nombre;
    energia = _energia;
    hambre = _hambre;
    felicidad = _felicidad;
}

// Getters
string getNombre(string nombre) { return nombre; }
int getEnergia(int energia) { return energia; }
int getHambre(int hambre) { return hambre; }
int getFelicidad(int felicidad) { return felicidad; }

void Mascota::setNombre(string _nombre) { 
    Mascota::nombre = _nombre; 
}
void Mascota::setEnergia(int nuevaEnergia) { 
    if (nuevaEnergia < 0) Mascota::energia = 0; 
    else if (nuevaEnergia > 100) Mascota::energia = 100;
    else Mascota::energia = nuevaEnergia;
}
void Mascota::setHambre(int nuevoHambre) { 
    if (nuevoHambre < 0) Mascota::hambre = 0;   // Evita valores negativos
    else if (nuevoHambre > 100) Mascota::hambre = 100; // Límite máximo
    else Mascota::hambre = nuevoHambre;
}    
void Mascota::setFelicidad(int nuevaFelicidad) { 
    if (nuevaFelicidad < 0) Mascota::felicidad = 0;
    else if (nuevaFelicidad > 100) Mascota::felicidad = 100;
    else Mascota::felicidad = nuevaFelicidad;
}
// Método para mostrar el estado de la mascota
void Mascota::estado_de_la_mascota() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "Nombre: " << nombre << endl
         << "Energia: " << energia << endl 
         << "Hambre: " << hambre << endl
         << "Felicidad: " << felicidad << endl;
    if (hambre > 80) cout << "\nTengo hambre (ᗒᗣᗕ)՞" << endl;
    if (energia < 10) cout << "\nEstoy muy cansado (｡•́︿•̀｡)" << endl;
    if (felicidad < 10) cout << "\nJuguemos (◞ ‸ ◟)" << endl;
}
void Mascota::comer() {
    int opcion;
    
    if (hambre == 0) {
        cout << "\nTu mascota no tiene hambre en este momento. Vuelve mas tarde \n Presiona Enter para continuar... \n";
        cin.ignore();
        cin.get();
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
        cout << "Entrada inválida. Inténtalo de nuevo.\n";
        return;
    }

    switch (opcion) {
        case 1: setHambre(hambre - 10); setEnergia(energia + 10); break;
        case 2: setHambre(hambre - 30); setEnergia(energia + 30); break;
        case 3: setHambre(hambre - 5); setEnergia(energia + 5); break;
        case 4: setHambre(hambre - 50); setEnergia(energia + 50); break;
        default:
            cout << "Opción no válida. Inténtalo de nuevo (Presiona 'Enter' para continuar...\n";
            cin.ignore(); cin.get();
            break;
    }
    cout << "\nGracias por alimentarme (^o^)\n"; cout << "Presiona 'Enter' para continuar...\n";
    cin.ignore(); cin.get();
}
void Mascota::jugar() {
    if (energia <= 15) { cout << nombre << " esta muy cansado. Vuelve mas tarde... \n" << endl; cin.ignore();
        cin.get(); return; }
    if (hambre >= 80) { cout << nombre << " tiene mucha hambre :( \n" << endl; cin.ignore(); cin.get(); return; }

    int opcion;
    cout << "\n¿Que vamos a jugar hoy ✧*｡٩(ˊᗜˋ*)و✧*｡?" << endl;
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
        setFelicidad(felicidad + 30); setHambre(hambre +10); setEnergia(energia - 25);break;
    case 2: 
        setFelicidad(felicidad + 40); setHambre(hambre +20); setEnergia(energia - 50);break;
    case 3:
        setFelicidad(felicidad + 20); setHambre(hambre +10); setEnergia(energia - 15);break;
    default:
        cout << "\nOpcion invalida. Por favor intentalo de nuevo\n";
        break;
    }
} 
void Mascota::dormir() {
    if (energia == 100) { cout << nombre << " no tiene sueño... "; cin.ignore(); cin.get(); return; }
    cout << nombre << " esta durmiendo..." << endl;
    energia = 100;
    cout << "Presiona Enter para continuar";
    cin.ignore();
    cin.get();
}
void Mascota::limpiar_pantalla() { cout << "\033[2J\033[H"; }
#endif
