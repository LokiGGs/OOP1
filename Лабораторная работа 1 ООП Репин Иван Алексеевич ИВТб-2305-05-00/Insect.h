#include <iostream>
using namespace std;

class Insect {
private:
    int tarsus;
    bool abdomen;

protected:

public:
    Insect(){
        tarsus = 6;
        abdomen = true;
    }

    void setTarsus(int a){
        tarsus = a;
    }

    void setAbdomen(bool a){
        abdomen = a;
    }

    int getTarsus(){
        return tarsus;
    }

    bool getAbdomen(){
        return abdomen;
    }

    void Eat(){
        cout << "��ᥪ���� ���..\n";
    }

    void See(){
        cout << "��ᥪ���� ��� ����⨫�..\n";
    }

    virtual void Sound(){
        cout << "��ᥪ���� ������ ���..\n";
    }

    virtual void Movement(){
        cout << "��ᥪ���� ������..\n";
    }
    
    virtual void DisplayType() = 0;
};