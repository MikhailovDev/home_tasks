#ifndef TESTING_FUNCTIONS_HPP
#define TESTING_FUNCTIONS_HPP
#include "data.hpp"

bool isEmpty(Node* node);

void push(Queue** queue, int data);
void remove(Queue** queue);

int getFront(Queue* queue);
int getBack(Queue* queue);
int getSize(Node* node);

void print(Node* node);
void printActions();
void stop();

#endif
