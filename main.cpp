#include <string_view>
#include "renderer.h"
#include "tools.h"
#include "sorts.h"

int main(int argc, char** argv) {
    if (argv[1] == nullptr) {
        print_help();
        return 0;
    }
    std::string_view cmdline(argv[1]);
    SortStrategy* s;

    if (cmdline.find("insert") != std::string_view::npos) {
        s = new InsertionSort();
    } else if (cmdline.find("merge") != std::string_view::npos) {
        s = new MergeSort();
    } else {
        print_help();
        return 0;
    }

    Renderer* r = new Renderer(800, 600);
    s->setRenderer(r);

    int arr[] = {157, 81, 77, 195, 47, 117, 122, 41, 36, 196, 64, 147, 128, 69, 46, 188, 84, 
                 0, 93, 78, 163, 146, 151, 28, 140, 30, 193, 147, 81, 125, 70, 186, 163, 32, 
                 41, 180, 112, 16, 31, 65, 78, 55, 127, 70, 58, 181, 69, 95, 78, 7, 80, 76, 
                 185, 97, 196, 39, 52, 151, 156, 178, 179, 19, 182, 13, 153, 156, 24, 88, 134, 
                 97, 87, 137, 121, 82, 39, 176, 101, 95, 169, 178, 123, 122, 64, 172, 90, 134, 
                 174, 55, 41, 172, 187, 28, 88, 122, 159, 155, 137, 40, 76, 79, 142, 2, 89, 
                 39, 134, 48, 54, 88, 28, 24, 43, 107, 23, 77, 168, 53, 145, 35, 46, 2, 199, 
                 13, 151, 73, 14, 136, 84, 185, 83, 164, 196, 79, 73, 62, 86, 25, 13, 36, 33, 
                 99, 91, 39, 138, 12, 81, 144, 151, 122, 162, 124, 98, 53, 152, 155, 46, 154, 
                 162, 121, 76, 120, 198, 168, 17, 22, 96, 115, 186, 35, 157, 141, 154, 157, 
                 60, 143, 183, 196, 79, 167, 73, 108, 189, 79, 143, 128, 86, 75, 105, 172, 
                 147, 171, 48, 108, 168, 69, 166, 157, 136, 77, 94, 54};
    int size = sizeof(arr)/sizeof(arr[0]);

    r->DrawArray(arr, size);
    r->Display();
    wait(1000);

    s->Sort(arr, size);

    while (r->isOpen()) {
        sf::Event event;
        while (r->pollEvent(&event)) {
            if (event.type == sf::Event::Closed)
                r->Close();
        }
    }

    return 0;
}