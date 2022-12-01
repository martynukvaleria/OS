#include <iostream>
#include <sstream>

int main() {
    const int n = 7;
    std::string string;
    std::getline(std::cin, string);
    std::stringstream ss(string);
    int num;
    while (ss >> num) {
        std::cout << num * n << ' ';
    }
    std::cout << std::endl;
    return 0;
}
