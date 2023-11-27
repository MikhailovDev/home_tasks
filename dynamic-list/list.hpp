#ifndef LIST_HPP
#define LIST_HPP

#include "node.hpp"

struct List {
   public:
    List() : front(nullptr), back(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void pushBack(const int value) {
        Node* tmp = new Node(value);

        if (isEmpty()) {
            front = tmp;
            back = tmp;
        } else {
            back->next = tmp;
            back = tmp;
        }
    }

    void printAll() {
        if (isEmpty()) {
            printListIsEmpty();
            return;
        }

        Node* tmp = front;
        do {
            std::cout << tmp->value << " ";
        } while (tmp = tmp->next);

        std::cout << std::endl;
    }

    void removeFirst() {
        if (isEmpty()) {
            printListIsEmpty();
            return;
        } else if (front == back) {
            delete front;
            front = nullptr;
            back = nullptr;
            return;
        }

        Node* tmp = front;
        front = front->next;
        delete tmp;
    }

    void removeBack() {
        if (isEmpty()) {
            printListIsEmpty();
            return;
        } else if (front == back) {
            removeFirst();
            return;
        }

        Node* tmp = back;
        back = getPrev(back);
        back->next = nullptr;
        delete tmp;
    }

    void removeByValue(const int value) {
        if (isEmpty()) {
            return;
        } else if (front->value == value) {
            removeFirst();
            return;
        } else if (back->value == value) {
            removeBack();
            return;
        }

        Node* tmp = front;
        while ((tmp = tmp->next) && (tmp)->value != value);

        if (!tmp) {
            printValueDoesntExist(value);
            return;
        }

        Node* tmpPrev = getPrev(tmp);
        tmpPrev->next = tmp->next;
        delete tmp;
    }

    void pushAfterValue(const int searchValue, const int value) {
        if (isEmpty() || back->value == searchValue) {
            pushBack(value);
            return;
        }

        Node* searchedNode = getNodeByValue(searchValue);
        if (!searchedNode) {
            printValueDoesntExist(searchValue);
            return;
        }

        Node* tmp = new Node(value);
        tmp->next = searchedNode->next;
        searchedNode->next = tmp;
    }
    
    void pushBeforeValue(const int searchValue, const int value) {
        if (isEmpty()) {
            pushBack(value);
            return;
        } else if (front->value == searchValue) {
            Node* tmp = new Node(value);
            tmp->next = front;
            front = tmp;
            return;
        }

        Node* searchedNode = getNodeByValue(searchValue);
        if (!searchedNode) {
            printValueDoesntExist(searchValue);
            return;
        }

        Node* prevNode = getPrev(searchedNode);
        Node* tmp = new Node(value);
        tmp->next = prevNode->next;
        prevNode->next = tmp;
    }

    void printListIsEmpty() {
        std::cout << "РЎРїРёСЃРѕРє РїСѓСЃС‚!" << std::endl;
    }

    void printValueDoesntExist(const int value) {
        std::cout << "Р—РЅР°С‡РµРЅРёСЏ " << value << " РЅРµС‚ РІ СЃРїРёСЃРєРµ!" << std::endl;
    }

   private:
    Node* front;
    Node* back;

    Node* getPrev(Node* node) {
        if (isEmpty() || front == back) {
            return nullptr;
        }

        Node* first = front->next;
        Node* second = front;
        while (first && first != node) {
            first = first->next;
            second = second->next;
        }

        return first ? second : nullptr;
    }

    Node* getNodeByValue(const int value) {
        if (isEmpty()) {
            return nullptr;
        }

        Node* tmp = front;
        // while ((tmp = tmp->next) && (tmp)->value != value) - but also we can do that;
        while (tmp && (tmp)->value != value) { 
            tmp = tmp->next;
        }

        return tmp;
    }
};

#endif
