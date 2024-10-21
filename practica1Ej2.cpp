#include <iostream>
#include <sys/wait.h>
#include <array>
#include <unistd.h>

using namespace std;

int main() {
    array<int, 30> numeros = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                             11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                             21, 22, 23, 24, 25, 26, 27, 28, 29, 30};

    pid_t pid;
    int inicio = 0;
    int limite = 10;

    for (int i = 0; i < 3; i++) {
        pid = fork();
        if (pid == 0) { // Proceso hijo
            int suma = 0;
            for (int j = inicio; j < limite; j++) {
                suma += numeros[j];
            }
            cout << "Soy el proceso hijo con PID " << getpid()
                 << " y la suma de mis números es: " << suma << endl;
            exit(0); // Termina el proceso hijo
        }
        inicio += 10; // Actualiza el inicio para el próximo hijo
        limite += 10;
    }

    // Proceso padre espera a los hijos
    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }

    cout << "Proceso padre con PID " << getpid() << ": Todos mis hijos han terminado." << endl;

    return 0;
}