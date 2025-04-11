#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sstream>

using namespace std;

void getCPUUsage(){

    string line;
    ifstream file("/proc/stat");

    if(file.is_open()){
        getline(file, line);
        file.close();

        istringstream stream(line);
        string cpu;

        long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;

        // Extraçao dos dados da linha
        stream>>cpu>>user>>nice>>system>>idle>>iowait>>irq>>softirq>>steal>>guest>>guest_nice;

        long totalTime = user+nice+system+idle+iowait+irq+softirq+steal;
        long activeTime = user+nice+system+irq+softirq+steal;

        //Calcula o uso da CPU como percentagem

        float usage = (float) activeTime / totalTime * 100;

        //Exibe o uso da CPU
        cout << "Uso da CPU: "<< usage << "%" <<endl;
    }else{
        cerr << "Erro ao abrir o arquivo /proc/stat"<<endl; // Casa o arquivo nao seja aberto corretamente
    }
}

int main(){
    while (true)
    {
        getCPUUsage(); // Chama a funcao de monitoramento
        sleep(1); // Espera 1 segundo antes de atualizar
    }
    
    return  0;
}