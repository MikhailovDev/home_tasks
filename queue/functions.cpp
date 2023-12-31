#include <iostream>

#include "data.hpp"

bool isEmpty(Node* node) {
    return node == NULL;
}

void push(Queue** queue, int data) {
    Node* tmp = new Node;
    tmp->data = data;
    tmp->next = nullptr;

    if (!isEmpty((*queue)->back)) {
        (*queue)->back->next = tmp;
    }

    (*queue)->back = tmp;

    if (isEmpty((*queue)->front)) {
        (*queue)->front = tmp;
    }
}

void remove(Queue** queue) {
    if (!isEmpty((*queue)->front)) {
        Node* tmp = (*queue)->front;

        if (!isEmpty(tmp->next)) {
            (*queue)->front = tmp->next;
        } else {
            (*queue)->front = nullptr;
            (*queue)->back = nullptr;
        }

        delete tmp;
    }
}

int getFront(Queue* queue) {
    return queue->front->data;
}

int getBack(Queue* queue) {
    return queue->back->data;
}

int getSize(Node* node) {
    int i {};

    while (node != NULL) {
        i++;
        node = node->next;
    }

    return i;
}

void print(Node* node) {
    while (node != NULL) {
        std::cout << node->data << " ";
        node = node->next;
    }
}

void printActions() {
    using std::cout, std::endl;
    cout << "1. Добавить элемент в начало очереди;" << endl;
    cout << "2. Удалить элемент из конца очереди;" << endl;
    cout << "3. Получить первый элемент очереди;" << endl;
    cout << "4. Получить последний элемент очереди;" << endl;
    cout << "5. Вывести количество элементов в очереди;" << endl;
    cout << "6. Вывести все элементы очереди;" << endl;
}

void stop() {
    std::cout << "\nНажмите Enter, чтобы продолжить.";
    std::cin.get();
    std::cin.get();
}
