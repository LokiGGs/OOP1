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
        cout << "Насекомое ест..\n";
    }

    void See(){
        cout << "Насекомое вас заметило..\n";
    }

    virtual void Sound(){
        cout << "Насекомое издало звук..\n";
    }

    virtual void Movement(){
        cout << "Насекомое ползёт..\n";
    }
    
    virtual void DisplayType() = 0;
};