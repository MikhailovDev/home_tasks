#ifndef TESTING_DATA_HPP
#define TESTING_DATA_HPP

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* front{};
    Node* back{};
};

#endif
