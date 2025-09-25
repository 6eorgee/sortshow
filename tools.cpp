#include <iostream>
#include <thread>
#include <chrono>

void Wait(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void PrintHelp()
{
    std::cout << "Usage:\n";
    std::cout << "\t--insert\tinsertion sort\n";
    std::cout << "\t--merge \tmerge sort\n";
}
