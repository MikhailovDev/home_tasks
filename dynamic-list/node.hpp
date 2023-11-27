#ifndef NODE_HPP
#define NODE_HPP

struct Node {
    int value;
    Node* next;

    Node(int value) : value(value), next(nullptr) {}
};

#endif
