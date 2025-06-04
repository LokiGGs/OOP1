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
        cout << "Крылатое насекомое жужжит\n";
    }

    void Movement() override {
        cout << "Крылатое насекомое летает\n";
    }

    void Pollinate(){
        cout << "Крылатое насекомое опыляет цветок\n";
    }

    void Reproduction(){
        cout << "Крылатое насекомое размножается в воде\n";
    }
    
    void DisplayType() override {
        cout << "Тип: Крылатое насекомое\n";
    }
};