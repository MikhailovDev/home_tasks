#include <Windows.h>

#include <iostream>

#include "data.hpp"
#include "functions.hpp"

int main(void) {
    setlocale(LC_ALL, "ru");

    using std::cout, std::cin, std::endl;

    Queue* queue = new Queue;

    int choise{ -1 };
    do {
        printActions();
        cout << "��� �����: ";
        cin >> choise;

        switch (choise) {
        case 1:
            cout << "������� �����: ";
            int n;
            cin >> n;
            push(&queue, n);
            break;
        case 2:
            remove(&queue);
            break;
        case 3:
            if (!isEmpty(queue->front)) {
                std::cout << "������ ������� �������: " << getFront(queue)
                    << endl;
            }
            else {
                std::cout << "������� �����." << endl;
            }
            break;
        case 4:
            if (!isEmpty(queue->back)) {
                std::cout << "��������� ������� �������: " << getBack(queue)
                    << endl;
            }
            else {
                std::cout << "������� �����." << endl;
            }
            break;
        case 5:
            std::cout << "���������� ��������� � �������: "
                << getSize(queue->front) << endl;
            break;
        case 6:
            if (!isEmpty(queue->back)) {
                print(queue->front);
            }
            else {
                std::cout << "������� �����." << endl;
            }

            break;
        }
        stop();

        system("cls");
    } while (choise != 0);

    return 0;
}
