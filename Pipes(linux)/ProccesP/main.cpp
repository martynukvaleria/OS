#include <iostream>
#include <sstream>

int main() {
    std::string string;
    std::getline(std::cin, string);
    std::stringstream ss(string);
    int num;
    while (ss >> num) {
        std::cout << num * num * num << ' ';
    }
    std::cout << std::endl;
    return 0;
}