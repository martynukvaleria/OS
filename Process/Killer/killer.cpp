#include <windows.h>
#include <Tlhelp32.h>
#include <winbase.h>
#include <cstring>
#include <string>
#include <locale>
#include <codecvt>

void killProcessById(int ProcessID){
    HANDLE handle = OpenProcess(PROCESS_TERMINATE, FALSE, ProcessID);
    if (handle != nullptr) {
        TerminateProcess(handle, 0);
        CloseHandle(handle);
    }
}

void killProcessByName(const char *filename) {
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(entry);
    BOOL first = Process32First(snapshot, &entry);
    while (first) {
        if (strcmp(entry.szExeFile, filename) == 0) {
            HANDLE process = OpenProcess(PROCESS_TERMINATE, 0, (DWORD) entry.th32ProcessID);
            if (process != nullptr) {
                TerminateProcess(process, 9);
                CloseHandle(process);
            }
        }
        first = Process32Next(snapshot, &entry);
    }
    CloseHandle(snapshot);
}
void killProcessList(char** preyProcesses, int length){
    for (int i = 0; i < length; ++i) {
        if (strcmp(preyProcesses[i], "--name") == 0){
            killProcessByName(preyProcesses[i + 1]);
        }
        if (strcmp(preyProcesses[i], "--id") == 0){
            killProcessById(std::stoi(preyProcesses[i + 1]));
        }
    }
}

void killProcessByEnvironment()
{
    std::wstring buff;
    buff.resize(65535);
    DWORD size = GetEnvironmentVariableW(L"PROC_TO_KILL", &buff[0], size);
    buff.resize(size);
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
    std::string args = converter.to_bytes(buff);
    char *nextPtr = nullptr;
    char *ptr = strtok_s(&args.front(), ",", &nextPtr);
    while (ptr != nullptr)
    {
        killProcessByName(ptr);
        ptr = strtok_s(nullptr, ",", &nextPtr);
    }
}

int main(int argc, char *argv[])
{
    killProcessByEnvironment();
    killProcessList(argv, argc);
    return 0;
}