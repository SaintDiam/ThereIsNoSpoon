/* Finds the greatest difference between two numbers in an ordered list
 * without actually using a list, because lists are for squares, like pants.
 */

#include <iostream>

int main() {
    int size, value, max = 0, solution = 0;
    std::cin >> size; std::cin.ignore();
    
    for (int i = 0; i < size; i++) {
        std::cin >> value; std::cin.ignore();
        if (value > max) { max = value; }
        if ((value - max) < solution) { solution = value - max; }
    }
    std::cout << solution << std::endl;
}
