#ifndef LIST_H
#define LIST_H

#include <stdexcept>
#include <initializer_list>

template<typename T>
class list {
private:
    struct Node;
public:
    class Iterator {
    private:
        Node* current;
    public:
        Iterator(Node* node);
        Iterator& operator++();
        T& operator*();
        bool operator!=(const Iterator& other);
    };

private:
    struct Node {
        T data;
        Node* next;
        Node(const T& elem, Node* next_node = nullptr) : data(elem), next(next_node) {}
    };

    Node* head;
    int length;

public:
    using value_type = T;
    using size_type = std::size_t;
    using iterator = Iterator;
    using const_iterator = const Iterator;

    list();
    list(const list<T>& lst);
    list(list<T>&& lst);
    list(std::initializer_list<T> lst);
    ~list();

    list<T>& operator=(const list<T>& lst);
    T& operator[](int index);

    int get_length() const;

    void add(const T& elem);
    void add_range(const list<T>& lst);
    void add_range(T* arr, int size);
    void set_elem(int index, const T& elem);
    T& get_elem(int index);
    void remove_elem(int index);
    list<T> combine(const list<T>& lst);
    void sort(int (*comp)(const T& r1, const T& r2));

    iterator begin() {
        return Iterator(head);
    }

    iterator end() {
        return Iterator(nullptr);
    }

    const_iterator begin() const {
        return Iterator(head);
    }

    const_iterator end() const {
        return Iterator(nullptr);
    }

    bool empty() const {
        return length == 0;
    }

    size_type size() const {
        return length;
    }

    void push_back(const T& elem) {
        add(elem);
    }

    void pop_back() {
        remove_elem(length - 1);
    }

    T& front() {
        return get_elem(0);
    }

    const T& front() const {
        return get_elem(0);
    }

    T& back() {
        return get_elem(length - 1);
    }

    const T& back() const {
        return get_elem(length - 1);
    }
};

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
list<T>::list(const list<T>& lst) : head(nullptr), length(0) {
    for (Node* curr = lst.head; curr != nullptr; curr = curr->next) {
        add(curr->data);
    }
}

template<typename T>
list<T>::list(list<T>&& lst) : head(lst.head), length(lst.length) {
    lst.head = nullptr;
    lst.length = 0;
}

template<typename T>
list<T>::list(std::initializer_list<T> lst) : head(nullptr), length(0) {
    for (const T& elem : lst) {
        add(elem);
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
    for (int i = size - 1; i >= 0; --i) {
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
    Node* curr = head;
    if (index == 0) {
        head = head->next;
        delete curr;
    } else {
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
    list<T> result(*this);
    result.add_range(lst);
    return result;
}

template<typename T>
void list<T>::sort(int (*comp)(const T& r1, const T& r2)) {
    for (Node* curr1 = head; curr1 != nullptr; curr1 = curr1->next) {
        for (Node* curr2 = curr1->next; curr2 != nullptr; curr2 = curr2->next) {
            if (comp(curr2->data, curr1->data) < 0) {
                std::swap(curr1->data, curr2->data);
            }
        }
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

#endif // LIST_H
