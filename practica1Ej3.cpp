#include <iostream>
#include <sys/wait.h>
int main() {
pid_t pid;
for (int i = 0; i < 3; i++) {
pid = fork();
if (pid == 0) {
std::cout << "Soy el proceso con PID " << getpid()
<< " y mi padre tiene el PID " << getppid() << std::endl;
break;
}
}
if (pid != 0) {
//Hemos quitado el sleep para que no tarde en loggear el fin del proceso
for (int i = 0; i < 3; i++) {
std::cout << "Fin del proceso de PID " << wait(0)
<< std::endl;
}
}
return 0;
}