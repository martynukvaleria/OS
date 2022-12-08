#include <unistd.h>
#include <sys/wait.h>

void process(int in, int out, const char* pathProcess){
    if (fork() == 0) {
        dup2(in, STDIN_FILENO);
        dup2(out, STDOUT_FILENO);
        close(in);
        close(out);
        execl(pathProcess, nullptr);
        _exit(0);
    }
}

int main()
{
    const char *pathM = "../../ProccesM/cmake-build-debug/M";
    const char *pathA = "../../ProccesA/cmake-build-debug/A";
    const char *pathP = "../../ProccesP/cmake-build-debug/P";
    const char *pathS = "../../ProccesS/cmake-build-debug/S";

    int pipeMA[2];
    int pipeAP[2];
    int pipePS[2];
    int status;

    pipe(pipeMA);
    pipe(pipeAP);
    pipe(pipePS);

    int in = dup(STDIN_FILENO);
    int out = dup(STDOUT_FILENO);
    close(STDIN_FILENO);

    process(in, pipeMA[1], pathM);
    process(pipeMA[0], pipeAP[1], pathA);
    process(pipeAP[0], pipePS[1], pathP);
    process(pipePS[0], out, pathS);

    for (int i = 0; i < 4; ++i) {
        wait(&status);
    }
}