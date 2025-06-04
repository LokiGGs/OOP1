#include <iostream>
using namespace std;

class Wingless : public Insect {
private:
    int speed;
    float size;

protected:

public:
    Wingless():speed(0), size(0){};

    void setSpeed(int a){
        speed = a;
    }

    void setSize(float a){
        size = a;
    }

    int getSpeed(){
        return speed;
    }

    float getSize(){
        return size;
    }

    void Sound() override {
        cout << "����뫮� ��ᥪ���� ����\n";
    }

    void Movement() override {
        cout << "����뫮� ��ᥪ���� �������\n";
    }

    void Weave(){
        cout << "����뫮� ��ᥪ���� ������ ���⨭�\n";
    }

    void Hunting(){
        cout << "����뫮� ��ᥪ���� ������ ��� �����\n";
    }
    
    void DisplayType() override {
        cout << "���: ����뫮� ��ᥪ����\n";
    }
};