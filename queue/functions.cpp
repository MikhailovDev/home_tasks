#include <iostream>

#include "data.hpp"

bool isEmpty(Node* node) {
    return node == NULL;
}

void push(Queue** queue, int data) {
    Node* tmp = new Node;
    tmp->data = data;
    tmp->next = (*queue)->front;

    if (!isEmpty((*queue)->front)) {
        (*queue)->front->previous = tmp;
    }

    (*queue)->front = tmp;

    if (isEmpty((*queue)->back)) {
        (*queue)->back = tmp;
    }
}

void remove(Queue** queue) {
    if (!isEmpty((*queue)->back)) {
        Node* tmp = (*queue)->back;

        if (!isEmpty(tmp->previous)) {
            (*queue)->back = tmp->previous;
            tmp->previous->next = nullptr;
        }
        else {
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
    int i{};

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
    cout << "1. �������� ������� � ������ �������;" << endl;
    cout << "2. ������� ������� �� ����� �������;" << endl;
    cout << "3. �������� ������ ������� �������;" << endl;
    cout << "4. �������� ��������� ������� �������;" << endl;
    cout << "5. ������� ���������� ��������� � �������;" << endl;
    cout << "6. ������� ��� �������� �������;" << endl;
}

void stop() {
    std::cout << "\n������� Enter, ����� ����������.";
    std::cin.get();
    std::cin.get();
}
