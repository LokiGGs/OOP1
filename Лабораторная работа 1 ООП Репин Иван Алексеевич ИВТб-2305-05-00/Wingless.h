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
        cout << "Бескрылое насекомое пищит\n";
    }

    void Movement() override {
        cout << "Бескрылое насекомое ползает\n";
    }

    void Weave(){
        cout << "Бескрылое насекомое плетёт паутину\n";
    }

    void Hunting(){
        cout << "Бескрылое насекомое охотится под землёй\n";
    }
    
    void DisplayType() override {
        cout << "Тип: Бескрылое насекомое\n";
    }
};