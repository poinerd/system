#include <iostream>




int addNumbers(int a, int b){
    return int(a+b);
}
int main() {
    // Print text to the terminal, followed by a new line
    std::cout << "Hello, World! Welcome to C++ systems programming.\n";
    int adder = addNumbers(2,3);
    std::cout << "The result of additon is "
    // Return 0 to tell the Operating System that the program executed successfully
    return 0;
}