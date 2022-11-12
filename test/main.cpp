#include <iostream>
#include "creature.h"
#include <vector>

using namespace std;

int main(){
	Weapon * weapon = new Weapon("Kard", 100);
    Armor * armor = new Armor("Oroszlanbor", 40);
    vector<Effect> effects;
    Humanoid human("Jeff", 400, 800, 80, effects, armor, weapon);
    cout << human.getHp() << endl;
    return 0;
}