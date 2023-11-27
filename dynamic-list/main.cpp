#include <Windows.h>

#include <iostream>
#include <locale>

#include "list.hpp"

int main() {
    setlocale(LC_ALL, "ru");
    List* list = new List;

    int choise {-1};

    do {
        std::cout << "0 - Р—Р°РІРµСЂС€РёС‚СЊ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹;" << std::endl;
        std::cout << "1 - Р”РѕР±Р°РІРёС‚СЊ РЅРѕРІС‹Р№ СЌР»РµРјРµРЅС‚ РІ СЃРїРёСЃРѕРє;" << std::endl;
        std::cout << "2 - РЈРґР°Р»РёС‚СЊ РїРµСЂРІС‹Р№ СЌР»РµРјРµРЅС‚ РёР· СЃРїРёСЃРєР°;" << std::endl;
        std::cout << "3 - РЈРґР°Р»РёС‚СЊ РїРѕСЃР»РµРґРЅРёР№ СЌР»РµРјРµРЅС‚ РёР· СЃРїРёСЃРєР°;" << std::endl;
        std::cout << "4 - РЈРґР°Р»РёС‚СЊ СЌР»РµРјРµРЅС‚ РёР· СЃРїРёСЃРєР° РїРѕ РµРіРѕ Р·РЅР°С‡РµРЅРёСЋ;"
                  << std::endl;
        std::cout << "5 - Р’СЃС‚Р°РІРёС‚СЊ СЌР»РµРјРµРЅС‚ РїРѕСЃР»Рµ Р·Р°РґР°РЅРЅРѕРіРѕ С‡РёСЃР»Р°;"
                  << std::endl; // Write this!
        std::cout << "6 - Р’СЃС‚Р°РІРёС‚СЊ СЌР»РµРјРµРЅС‚ РїРµСЂРµРґ Р·Р°РґР°РЅРЅС‹Рј С‡РёСЃР»РѕРј;"
                  << std::endl; // Write this!
        std::cout << "7 - Р’С‹РІРµСЃС‚Рё РІСЃРµ СЌР»РµРјРµРЅС‚С‹ СЃРїРёСЃРєР°;" << std::endl;

        int value;
        int searchValue;
        std::cout << "Р’Р°С€ РІС‹Р±РѕСЂ: ";
        (std::cin >> choise).get();
        switch (choise) {
            case 1:
                std::cout << "Р’РІРµРґРёС‚Рµ С‡РёСЃР»Рѕ: ";
                (std::cin >> value).get();
                list->pushBack(value);
                break;
            case 2:
                list->removeFirst();
                break;
            case 3:
                list->removeBack();
                break;
            case 4:
                if (list->isEmpty()) {
                    list->printListIsEmpty();
                    break;
                }
                std::cout << "Р’РІРµРґРёС‚Рµ Р·РЅР°С‡РµРЅРёРµ: ";
                (std::cin >> value).get();
                list->removeByValue(value);
                break;
            case 5:
                std::cout << "Р’РІРµРґРёС‚Рµ С‡РёСЃР»Рѕ, РїРѕСЃР»Рµ РєРѕС‚РѕСЂРѕРіРѕ РЅРµРѕР±С…РѕРґРёРјРѕ РІСЃС‚Р°РІРёС‚СЊ РЅРѕРІРѕРµ Р·РЅР°С‡РµРЅРёРµ: ";
                (std::cin >> searchValue).get();
                std::cout << "Р’РІРµРґРёС‚Рµ С‡РёСЃР»Рѕ, РєРѕС‚РѕСЂРѕРµ РЅСѓР¶РЅРѕ РІСЃС‚Р°РІРёС‚СЊ: ";
                (std::cin >> value).get();
                list->pushAfterValue(searchValue, value);
                break;
            case 6:
                std::cout << "Р’РІРµРґРёС‚Рµ С‡РёСЃР»Рѕ, РїРµСЂРµРґ РєРѕС‚РѕСЂС‹Рј РЅРµРѕР±С…РѕРґРёРјРѕ "
                             "РІСЃС‚Р°РІРёС‚СЊ РЅРѕРІРѕРµ Р·РЅР°С‡РµРЅРёРµ: ";
                (std::cin >> searchValue).get();
                std::cout << "Р’РІРµРґРёС‚Рµ С‡РёСЃР»Рѕ, РєРѕС‚РѕСЂРѕРµ РЅСѓР¶РЅРѕ РІСЃС‚Р°РІРёС‚СЊ: ";
                (std::cin >> value).get();
                list->pushBeforeValue(searchValue, value);
                break;
            case 7:
                list->printAll();
                break;
        }
        std::cout << "РќР°Р¶РјРёС‚Рµ РЅР° Enter, С‡С‚РѕР±С‹ РїСЂРѕРґРѕР»Р¶РёС‚СЊ.";
        std::cin.get();
        system("cls");
    } while (choise != 0);

    return 0;
}
