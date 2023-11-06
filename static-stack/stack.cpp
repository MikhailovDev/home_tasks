#include <Windows.h>

#include <iostream>

void add(int** arrPtr, int& pos, int value, int count, bool startPosition);
void remove(int** arrPtr, int& pos, int count, bool startPosition);
void print(int** arrPtr, int count);
void fill(int** arrPtr, int count, int value);

int getUserChoise();

void stop();

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int count;
    std::cout << "Введите количество элементов в массиве: ";
    std::cin >> count;

    int position = 0, endPosition = count - 1;
    int* array = new int[count];
    fill(&array, count, 0);

    int userInput;

    do {
        std::cout << "0. Выход." << std::endl;
        std::cout << "1. Добавить элемент." << std::endl;
        std::cout << "2. Удалить элемент." << std::endl;
        std::cout << "3. Вывести массив." << std::endl;

        std::cin >> userInput;

        int choise;
        switch (userInput) {
            case 1:
                choise = getUserChoise();

                switch (choise) {
                    case 1:
                        std::cout << "Введите число: ";
                        std::cin >> choise;

                        add(&array, position, choise, count, true);
                        break;
                    case 2:
                        std::cout << "Введите количество элементов: ";
                        std::cin >> choise;

                        for (int i = 0; i < choise && position < count; i++) {
                            add(&array, position, rand(), count, true);
                        }
                        break;
                    case 3:
                        std::cout << "Введите число: ";
                        std::cin >> choise;

                        add(&array, endPosition, choise, count, false);
                        break;
                    case 4:
                        std::cout << "Введите количество элементов: ";
                        std::cin >> choise;

                        for (int i = 0; i < choise && endPosition >= 0; i++) {
                            add(&array, endPosition, rand(), count, false);
                        }
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                std::cout << "С какой стороны удалим элемент: с начала (1) или "
                             "конца (2)? ";
                std::cin >> choise;

                if (choise == 1) {
                    remove(&array, position, count, true);
                } else if (choise == 2) {
                    remove(&array, endPosition, count, false);
                }

                break;
            case 3:
                print(&array, endPosition == count - 1 ? position : count);
                stop();
                break;
            default:
                break;
        }

        system("cls");
        std::cout << "position: " << position << std::endl;
        std::cout << "endPosition: " << endPosition << std::endl;
    } while (userInput != 0);
}

int getUserChoise() {
    int choise;

    std::cout
        << "С какой стороны добавим элемент: с начала (1) или конца (2)? ";
    std::cin >> choise;

    if (choise == 1) {
        std::cout << "Какой метод добавления вы выберете: самостоятельное "
                     "добавление элемента (1), или добавление определенного "
                     "количества рандомных элементов (2)? ";
        std::cin >> choise;

        if (choise == 1) {
            return 1;
        } else if (choise == 2) {
            return 2;
        }

    } else if (choise == 2) {
        std::cout << "Какой метод добавления вы выберете: самостоятельное "
                     "добавление элемента (1), или добавление определенного "
                     "количества рандомных элементов (2)? ";
        std::cin >> choise;

        if (choise == 1) {
            return 3;
        } else if (choise == 2) {
            return 4;
        }
    }
}

void add(int** arrPtr, int& pos, int value, int count, bool startPosition) {
    if (startPosition && pos < count && (*arrPtr)[pos] == 0) {
        (*arrPtr)[pos] = value;

        if (pos + 1 < count && (*arrPtr)[pos + 1] == 0) {
            pos++;
        }
    } else if (!startPosition && pos >= 0 && (*arrPtr)[pos] == 0) {
        (*arrPtr)[pos] = value;

        if (pos - 1 >= 0 && (*arrPtr)[pos - 1] == 0) {
            pos--;
        }
    }
}

void remove(int** arrPtr, int& pos, int count, bool startPosition) {
    if (startPosition && pos >= 0) {
        (*arrPtr)[pos] = 0;

        if (pos - 1 >= 0) {
            pos--;
        }
    } else if (!startPosition && pos < count) {
        (*arrPtr)[pos + 1] = 0;

        if (pos + 1 < count) {
            pos++;
        }
    }
}

void print(int** arrPtr, int count) {
    for (int i = 0; i < count; i++) {
        if ((*arrPtr)[i] == 0) {
            std::cout << "* ";
        } else {
            std::cout << (*arrPtr)[i] << " ";
        }
    }

    std::cout << std::endl;
}

void fill(int** arrPtr, int count, int value) {
    for (int i = 0; i < count; i++) {
        (*arrPtr)[i] = value;
    }
}

void stop() {
    std::cout << "*Нажмите Enter*";
    getchar();
    getchar();
}
