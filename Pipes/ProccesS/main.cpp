#include <iostream>
#include <sstream>

int main() {
    int sum = 0;
    std::string string;
    std::getline(std::cin, string);
    std::stringstream ss(string);
    int num;
    while(ss >> num){
        sum += num;
    }
    std::cout << sum << std::endl;
    return 0;
}


