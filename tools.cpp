#include "tools.h"
#include <iostream>
#include <SFML/Graphics.hpp>

void wait(int milliseconds) {
    sf::Clock clock;
    while (clock.getElapsedTime().asMilliseconds() < milliseconds) {}
}

void print_help(){
    std::cout << "Usage:\n";
    std::cout << "\t--insert\tinsertion sort\n";
    std::cout << "\t--merge \tmerge sort\n";
}
