#include <iostream>
#include "test.h"

int main() {
    if (run_list_tests()) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }

    return 0;
}
