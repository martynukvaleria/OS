#include <cstring>
#include <string>
#include <locale>
#include <codecvt>
#include <sstream>

void killProcessById(int processId){
    system(("kill" + std::to_string(processId)).c_str());
}

void killProcessByName(const char *filename) {
    system(("killall " + std::string(filename)).c_str());
}
void kill(char** preyProcesses, int length){
    for (int i = 0; i < length; i++) {
        if (strcmp(preyProcesses[i], "--name") == 0) {
            killProcessByName(preyProcesses[i + 1]);
        } else if (strcmp(preyProcesses[i], "--id") == 0) {
            killProcessById(std::stoi(preyProcesses[i + 1]));
        }
    }
}

int main(int length, char *argv[])
{
    kill(argv, length);
    char buff[100];
    if (getenv("PROC_TO_KILL") == nullptr){
        return 0;
    }

    strcpy(buff, getenv("PROC_TO_KILL"));
    std::stringstream ss(buff);
    while (ss.getline(buff, sizeof(buff), ',')) {
        killProcessByName(buff);
    }
    return 0;
}