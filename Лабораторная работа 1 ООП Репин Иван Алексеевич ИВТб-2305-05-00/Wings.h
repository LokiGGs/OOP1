#include <iostream>
using namespace std;

class Wings : public Insect {
private:
    int wingCount;
    float weight;

protected:

public:
    Wings(): wingCount(0), weight(0){}

    void setWingCount(int a){
        wingCount = a;
    }

    void setWeight(float a){
        weight = a;
    }

    int getWingCount(){
        return wingCount;
    }

    float getWeight(){
        return weight;
    }

    void Sound() override {
        cout << "��뫠⮥ ��ᥪ���� �㦦��\n";
    }

    void Movement() override {
        cout << "��뫠⮥ ��ᥪ���� ��⠥�\n";
    }

    void Pollinate(){
        cout << "��뫠⮥ ��ᥪ���� ����� 梥⮪\n";
    }

    void Reproduction(){
        cout << "��뫠⮥ ��ᥪ���� ࠧ��������� � ����\n";
    }
    
    void DisplayType() override {
        cout << "���: ��뫠⮥ ��ᥪ����\n";
    }
};