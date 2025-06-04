#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include "Insect.h"
#include "Wings.h"
#include "Wingless.h"
using namespace std;

template<typename T>
bool readInput(T& value, const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    
    if (input.empty()) {
        return false;
    }
    
    istringstream iss(input);
    iss >> value;
    return true;
}

void showActionsMenu(Insect* insect) {
    int action;
    do {
        cout << "\nВыберите действие:\n";
        cout << "1. Показать характеристики\n";
        cout << "2. Издать звук\n";
        cout << "3. Двигаться\n";
        cout << "4. Поесть\n";
        cout << "5. Увидеть\n";
        
        if (dynamic_cast<Wingless*>(insect)) {
            cout << "6. Плести паутину\n";
            cout << "7. Охотиться\n";
        } else if (dynamic_cast<Wings*>(insect)) {
            cout << "6. Опылять\n";
            cout << "7. Размножаться\n";
        }
        
        cout << "0. Назад\n> ";
        cin >> action;
        cin.ignore();

        switch(action) {
            case 1: {
                cout << "\nХарактеристики:\n";
                cout << "Лапок: " << insect->getTarsus() << endl;
                cout << "Брюшко: " << (insect->getAbdomen() ? "есть" : "нет") << endl;
                
                if (Wingless* wl = dynamic_cast<Wingless*>(insect)) {
                    cout << "Тип: Бескрылое\n";
                    cout << "Скорость: " << wl->getSpeed() << endl;
                    cout << "Размер: " << wl->getSize() << endl;
                } else if (Wings* w = dynamic_cast<Wings*>(insect)) {
                    cout << "Тип: Крылатое\n";
                    cout << "Крыльев: " << w->getWingCount() << endl;
                    cout << "Вес: " << w->getWeight() << endl;
                }
                break;
            }
            case 2: insect->Sound(); break;
            case 3: insect->Movement(); break;
            case 4: insect->Eat(); break;
            case 5: insect->See(); break;
            case 6: {
                if (Wingless* wl = dynamic_cast<Wingless*>(insect)) {
                    wl->Weave();
                } else if (Wings* w = dynamic_cast<Wings*>(insect)) {
                    w->Pollinate();
                }
                break;
            }
            case 7: {
                if (Wingless* wl = dynamic_cast<Wingless*>(insect)) {
                    wl->Hunting();
                } else if (Wings* w = dynamic_cast<Wings*>(insect)) {
                    w->Reproduction();
                }
                break;
            }
            case 0: break;
            default: cout << "Неверный выбор!\n";
        }
    } while(action != 0);
}

void displayAllInsects(const vector<unique_ptr<Insect>>& insects) {
    if (insects.empty()) {
        cout << "Нет созданных насекомых.\n";
        return;
    }
    
    cout << "\nСписок всех насекомых:\n";
    for (size_t i = 0; i < insects.size(); ++i) {
        cout << i + 1 << ". ";
        insects[i]->DisplayType();
    }
}

int main() {
    vector<unique_ptr<Insect>> insects;
    int choice;
    
    do {
        cout << "\nМеню:\n";
        cout << "1. Создать бескрылое\n";
        cout << "2. Создать крылатое\n";
        cout << "3. Показать всех насекомых\n";
        cout << "4. Удалить насекомое\n";
        cout << "5. Действия с насекомым\n";
        cout << "6. Выход\n> ";
        cin >> choice;
        cin.ignore();
        
        switch(choice) {
            case 1: {
                auto wingless = make_unique<Wingless>();
                int speed;
                if (readInput(speed, "Скорость (нажмите Enter чтобы пропустить): ")) {
                    wingless->setSpeed(speed);
                }
                
                float size;
                if (readInput(size, "Размер (нажмите Enter чтобы пропустить): ")) {
                    wingless->setSize(size);
                }
                
                insects.push_back(move(wingless));
                cout << "Бескрылое насекомое создано!\n";
                break;
            }
            case 2: {
                auto wings = make_unique<Wings>();
                int wingsCount;
                if (readInput(wingsCount, "Крылья (нажмите Enter чтобы пропустить): ")) {
                    wings->setWingCount(wingsCount);
                }
                
                float weight;
                if (readInput(weight, "Вес (нажмите Enter чтобы пропустить): ")) {
                    wings->setWeight(weight);
                }
                
                insects.push_back(move(wings));
                cout << "Крылатое насекомое создано!\n";
                break;
            }
            case 3: {
                displayAllInsects(insects);
                break;
            }
            case 4: {
                if (insects.empty()) {
                    cout << "Нет насекомых для удаления.\n";
                    break;
                }
                
                displayAllInsects(insects);
                cout << "Введите номер насекомого для удаления: ";
                size_t index;
                cin >> index;
                cin.ignore();
                
                if (index > 0 && index <= insects.size()) {
                    insects.erase(insects.begin() + index - 1);
                    cout << "Насекомое удалено.\n";
                } else {
                    cout << "Неверный номер!\n";
                }
                break;
            }
            case 5: {
                if (insects.empty()) {
                    cout << "Сначала создайте насекомое!\n";
                    break;
                }
                
                displayAllInsects(insects);
                cout << "Выберите насекомое: ";
                size_t index;
                cin >> index;
                cin.ignore();
                
                if (index > 0 && index <= insects.size()) {
                    showActionsMenu(insects[index - 1].get());
                } else {
                    cout << "Неверный номер!\n";
                }
                break;
            }
            case 6: {
                cout << "Выход\n";
                break;
            }
            default:
                cout << "Неверный выбор!\n";
        }
    } while(choice != 6);
    
    return 0;
}