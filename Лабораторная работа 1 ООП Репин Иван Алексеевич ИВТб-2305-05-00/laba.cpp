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
        cout << "\n�롥�� ����⢨�:\n";
        cout << "1. �������� �ࠪ���⨪�\n";
        cout << "2. ������ ���\n";
        cout << "3. ���������\n";
        cout << "4. ������\n";
        cout << "5. �������\n";
        
        if (dynamic_cast<Wingless*>(insect)) {
            cout << "6. ����� ���⨭�\n";
            cout << "7. �������\n";
        } else if (dynamic_cast<Wings*>(insect)) {
            cout << "6. ������\n";
            cout << "7. ������������\n";
        }
        
        cout << "0. �����\n> ";
        cin >> action;
        cin.ignore();

        switch(action) {
            case 1: {
                cout << "\n��ࠪ���⨪�:\n";
                cout << "�����: " << insect->getTarsus() << endl;
                cout << "���誮: " << (insect->getAbdomen() ? "����" : "���") << endl;
                
                if (Wingless* wl = dynamic_cast<Wingless*>(insect)) {
                    cout << "���: ����뫮�\n";
                    cout << "�������: " << wl->getSpeed() << endl;
                    cout << "������: " << wl->getSize() << endl;
                } else if (Wings* w = dynamic_cast<Wings*>(insect)) {
                    cout << "���: ��뫠⮥\n";
                    cout << "���쥢: " << w->getWingCount() << endl;
                    cout << "���: " << w->getWeight() << endl;
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
            default: cout << "������ �롮�!\n";
        }
    } while(action != 0);
}

void displayAllInsects(const vector<unique_ptr<Insect>>& insects) {
    if (insects.empty()) {
        cout << "��� ᮧ������ ��ᥪ����.\n";
        return;
    }
    
    cout << "\n���᮪ ��� ��ᥪ����:\n";
    for (size_t i = 0; i < insects.size(); ++i) {
        cout << i + 1 << ". ";
        insects[i]->DisplayType();
    }
}

int main() {
    vector<unique_ptr<Insect>> insects;
    int choice;
    
    do {
        cout << "\n����:\n";
        cout << "1. ������� ����뫮�\n";
        cout << "2. ������� ��뫠⮥\n";
        cout << "3. �������� ��� ��ᥪ����\n";
        cout << "4. ������� ��ᥪ����\n";
        cout << "5. ����⢨� � ��ᥪ���\n";
        cout << "6. ��室\n> ";
        cin >> choice;
        cin.ignore();
        
        switch(choice) {
            case 1: {
                auto wingless = make_unique<Wingless>();
                int speed;
                if (readInput(speed, "������� (������ Enter �⮡� �ய�����): ")) {
                    wingless->setSpeed(speed);
                }
                
                float size;
                if (readInput(size, "������ (������ Enter �⮡� �ய�����): ")) {
                    wingless->setSize(size);
                }
                
                insects.push_back(move(wingless));
                cout << "����뫮� ��ᥪ���� ᮧ����!\n";
                break;
            }
            case 2: {
                auto wings = make_unique<Wings>();
                int wingsCount;
                if (readInput(wingsCount, "����� (������ Enter �⮡� �ய�����): ")) {
                    wings->setWingCount(wingsCount);
                }
                
                float weight;
                if (readInput(weight, "��� (������ Enter �⮡� �ய�����): ")) {
                    wings->setWeight(weight);
                }
                
                insects.push_back(move(wings));
                cout << "��뫠⮥ ��ᥪ���� ᮧ����!\n";
                break;
            }
            case 3: {
                displayAllInsects(insects);
                break;
            }
            case 4: {
                if (insects.empty()) {
                    cout << "��� ��ᥪ���� ��� 㤠�����.\n";
                    break;
                }
                
                displayAllInsects(insects);
                cout << "������ ����� ��ᥪ����� ��� 㤠�����: ";
                size_t index;
                cin >> index;
                cin.ignore();
                
                if (index > 0 && index <= insects.size()) {
                    insects.erase(insects.begin() + index - 1);
                    cout << "��ᥪ���� 㤠����.\n";
                } else {
                    cout << "������ �����!\n";
                }
                break;
            }
            case 5: {
                if (insects.empty()) {
                    cout << "���砫� ᮧ���� ��ᥪ����!\n";
                    break;
                }
                
                displayAllInsects(insects);
                cout << "�롥�� ��ᥪ����: ";
                size_t index;
                cin >> index;
                cin.ignore();
                
                if (index > 0 && index <= insects.size()) {
                    showActionsMenu(insects[index - 1].get());
                } else {
                    cout << "������ �����!\n";
                }
                break;
            }
            case 6: {
                cout << "��室\n";
                break;
            }
            default:
                cout << "������ �롮�!\n";
        }
    } while(choice != 6);
    
    return 0;
}