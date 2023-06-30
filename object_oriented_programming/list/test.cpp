#include "test.h"
#include "list.h"
#include <iostream>

void test_list_add() {
    list<int> my_list;

    my_list.add(1);
    my_list.add(2);
    my_list.add(3);

    std::cout << "List contents after adding elements: ";
    for (const auto& elem : my_list) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void test_list_copy() {
    list<int> my_list;

    my_list.add(1);
    my_list.add(2);
    my_list.add(3);

    list<int> copy_of_list = my_list;

    std::cout << "Copy of list contents: ";
    for (const auto& elem : copy_of_list) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void test_list_move() {
    list<int> my_list;

    my_list.add(1);
    my_list.add(2);
    my_list.add(3);

    list<int> moved_list = std::move(my_list);

    std::cout << "Moved list contents: ";
    for (const auto& elem : moved_list) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void test_list_add_range() {
    list<int> my_list;

    my_list.add(1);
    my_list.add(2);
    my_list.add(3);

    int arr[] = {4, 5, 6};
    my_list.add_range(arr, 3);

    std::cout << "List contents after adding range: ";
    for (const auto& elem : my_list) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void test_list_remove_elem() {
    list<int> my_list;

    my_list.add(1);
    my_list.add(2);
    my_list.add(3);

    my_list.remove_elem(1);

    std::cout << "List contents after removing element: ";
    for (const auto& elem : my_list) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void test_list_combine() {
    list<int> my_list;

    my_list.add(1);
    my_list.add(2);
    my_list.add(3);

    list<int> another_list;
    another_list.add(7);
    another_list.add(8);

    list<int> combined_list = my_list.combine(another_list);

    std::cout << "Combined list contents: ";
    for (const auto& elem : combined_list) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void test_list_sort() {
    list<int> my_list;

    my_list.add(3);
    my_list.add(2);
    my_list.add(1);

    my_list.sort([](const int& a, const int& b) {
        if (a < b) {
            return -1;
        } else if (a > b) {
            return 1;
        } else {
            return 0;
        }
    });

    std::cout << "Sorted list contents: ";
    for (const auto& elem : my_list) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void test_list_set_elem() {
    list<int> my_list;

    my_list.add(1);
    my_list.add(2);
    my_list.add(3);

    my_list.set_elem(0, 10);

    std::cout << "List contents after changing element value: ";
    for (const auto& elem : my_list) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void test_list_get_elem() {
    list<int> my_list;

    my_list.add(1);
    my_list.add(2);
    my_list.add(3);

    int elem = my_list.get_elem(1);

    std::cout << "Value of element at index 1: " << elem << std::endl;
}

void test_list_indexing() {
    list<int> my_list;

    my_list.add(1);
    my_list.add(2);
    my_list.add(3);

    std::cout << "List contents using operator[]: ";
    for (int i = 0; i < my_list.get_length(); i++) {
        std::cout << my_list[i] << " ";
    }
    std::cout << std::endl;
}

bool run_list_tests() {
    test_list_add();
    test_list_copy();
    test_list_move();
    test_list_add_range();
    test_list_remove_elem();
    test_list_combine();
    test_list_sort();
    test_list_set_elem();
    test_list_get_elem();
    test_list_indexing();

    return true;
}
