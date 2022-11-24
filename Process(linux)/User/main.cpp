#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sys/wait.h>
#include <algorithm>

const std::string PATH_TO_KILLER = "../../Killer/cmake-build-debug/killer.exe";

char **getArgs(const std::vector<std::string> &killProcessByName, const std::vector<int> &killProcessById) {
    int argc = killProcessByName.size() + killProcessById.size() + 2;
    char **argv = new char *[argc + 1];

    argv[0] = new char[sizeof("--name")];
    strcpy(argv[0], "--name");
    int i = 1;
    for (auto &name: killProcessByName) {
        argv[i] = new char[name.length() + 1];
        strcpy(argv[i], name.c_str());
        ++i;
    }
    argv[i] = new char[sizeof("--id")];
    strcpy(argv[i], "--id");
    i++;
    for (auto id: killProcessById) {
        std::string str = std::to_string(id);
        argv[i] = new char[str.length() + 1];
        strcpy(argv[i], str.c_str());
        ++i;
    }
    return argv;
}

std::string join(const std::vector<std::string> &vector, const std::string &delimiter) {
    std::string result;
    for (auto i = 0; i < vector.size(); ++i) {
        result += vector[i];
        if (i != vector.size() - 1) {
            result += delimiter;
        }
    }
    return result;
}

void KillProcesses(const std::vector<std::string> &killProcessByName,
             const std::vector<int> &killProcessById,
             const std::vector<std::string> &killProcessByEnvironment) {
    std::string env_var = join(killProcessByEnvironment, ",");
    char buff[8841];
    strcpy(buff, env_var.c_str());
    setenv("PROC_TO_KILL", buff, 1);
    int pid = fork();


    if (pid == 0) {
        int argc = killProcessByName.size() + killProcessById.size() + 2;
        char **argv = getArgs(killProcessByName, killProcessById);
        execv(PATH_TO_KILLER.c_str(), argv);
        for (int i = 0; i < argc; ++i) {
            delete[] argv[i];
        }
        delete[] argv;
        exit(0);
    } else if (pid == -1) {
        unsetenv("PROC_TO_KILL");
        exit(pid);
    }
    int status;
    waitpid(pid, &status, 0);
    unsetenv("PROC_TO_KILL");
}

int main() {
    std::vector<std::string> killProcessByName = {"telegram-desktop"};
    std::vector<int> killProcessById = {6346};
    std::vector<std::string> killProcessByEnvironment = {"firefox"};
    system("top");
    std::cout << "Killing...\n";
    KillProcesses(killProcessByName, killProcessById, killProcessByEnvironment);
    sleep(1);
    system("top");
    return 0;
}