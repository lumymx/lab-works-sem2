#include "list.h"
#include <algorithm>

template<typename T>
list<T>::list() : head(nullptr), length(0) {}

template<typename T>
list<T>::~list() {
    while (head != nullptr) {
        Node* temp = head->next;
        delete head;
        head = temp;
    }
}

template<typename T>
list<T>& list<T>::operator=(const list<T>& lst) {
    if (this != &lst) {
        list<T> temp(lst);
        std::swap(head, temp.head);
        std::swap(length, temp.length);
    }
    return *this;
}

template<typename T>
T& list<T>::operator[](int index) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }
    Node* curr = head;
    for (int i = 0; i < index; ++i) {
        curr = curr->next;
    }
    return curr->data;
}

template<typename T>
int list<T>::get_length() const {
    return length;
}

template<typename T>
void list<T>::add(const T& elem) {
    Node* newNode = new Node(elem);
    newNode->next = head;
    head = newNode;
    ++length;
}

template<typename T>
void list<T>::add_range(const list<T>& lst) {
    for (Node* curr = lst.head; curr != nullptr; curr = curr->next) {
        add(curr->data);
    }
}

template<typename T>
void list<T>::add_range(T* arr, int size) {
    for (int i = 0; i < size; ++i) {
        add(arr[i]);
    }
}

template<typename T>
void list<T>::set_elem(int index, const T& elem) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }
    Node* curr = head;
    for (int i = 0; i < index; ++i) {
        curr = curr->next;
    }
    curr->data = elem;
}

template<typename T>
T& list<T>::get_elem(int index) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }
    Node* curr = head;
    for (int i = 0; i < index; ++i) {
        curr = curr->next;
    }
    return curr->data;
}

template<typename T>
void list<T>::remove_elem(int index) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    else {
        Node* curr = head;
        for (int i = 0; i < index - 1; ++i) {
            curr = curr->next;
        }
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
    --length;
}

template<typename T>
list<T> list<T>::combine(const list<T>& lst) {
    list<T> result;
    for (Node* curr = head; curr != nullptr; curr = curr->next) {
        result.add(curr->data);
    }
    for (Node* curr = lst.head; curr != nullptr; curr = curr->next) {
        result.add(curr->data);
    }
    return result;
}

template<typename T>
void list<T>::sort(int (*comp)(const T& r1, const T& r2)) {
    Node* curr = head;
    Node* prev = nullptr;
    while (curr != nullptr) {
        Node* next = curr->next;
        while (next != nullptr && comp(curr->data, next->data) > 0) {
            T temp = curr->data;
            curr->data = next->data;
            next->data = temp;

            if (prev != nullptr) {
                prev->next = next;
            } else {
                head = next;
            }

            prev = next;
            next = next->next;
        }

        curr = next;
    }
}


template<typename T>
list<T>::Iterator::Iterator(Node* node) : current(node) {}

template<typename T>
typename list<T>::Iterator& list<T>::Iterator::operator++() {
    current = current->next;
    return *this;
}

template<typename T>
T& list<T>::Iterator::operator*() {
    return current->data;
}

template<typename T>
bool list<T>::Iterator::operator!=(const Iterator& other) {
    return current != other.current;
}

template<typename T>
typename list<T>::Iterator list<T>::begin() {
    return Iterator(head);
}

template<typename T>
typename list<T>::Iterator list<T>::end() {
    return Iterator(nullptr);
}
