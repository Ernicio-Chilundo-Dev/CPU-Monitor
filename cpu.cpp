#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sstream>

using namespace std;

void getCPUUsage(){

    string line;
    fstream file("/proc/stat");

    if(file.is_open()){
        getLine(file, line);
        file.close();

        istringstream stream(line);
        string cpu;

        long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    }
}

int main(){
    return  0;
}