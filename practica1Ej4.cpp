#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>

using namespace std;


struct Nodo {
    int num_hijos;                
    vector<int> niveles_hijos;     
}

vector<Nodo> nodos = {
    {4, {1, 2, 0, 0}}, 
    {3, {2, 1, 0}},    
    {2, {1, 0}},       
    {0, {}},          
    {0, {}},          
    {2, {0, 0}},      
    {1, {0}},         
    {0, {}},          
    {1, {0}},         
    {0, {}},         
    {0, {}},         
    {0, {}},         
    {0, {}},          
    {0, {}}           
};


void crear_hijos(int nivel_actual, int indice_nodo) {
    pid_t pid; 
    const Nodo& nodo = nodos[indice_nodo]; 

   
    for (int i = 0; i < nodo.num_hijos; ++i) {
        pid = fork(); 
        if (pid == 0) { 
            cout << "Nodo: " << indice_nodo + 1 << ", Nivel: " << nivel_actual
                 << ", PID: " << getpid() << ", Padre: " << getppid() << endl;
            
            crear_hijos(nodo.niveles_hijos[i], i + 1 + indice_nodo);
            exit(0); 
        }
    }
}

int main() {
    pid_t pid = fork(); // Crear el proceso raíz
    if (pid == 0) { // Proceso hijo (raíz)
        cout << "Nodo: 0, Nivel: 0, PID: " << getpid() << ", Padre: " << getppid() << endl;
        crear_hijos(1, 0); // Comienza desde el nivel 1 y el nodo 0
    } else { // Proceso padre
        wait(NULL); // Espera a que todos los hijos terminen
        cout << "Proceso padre terminado." << endl;
    }
    return 0; // Fin del programa
}

