#include <iostream>
#include <vector>
#include "creature.h"

using namespace std;

int main(){
	Weapon * weapon = new Weapon("Kard", 100);
    Armor * armor = new Armor("Oroszlanbor", 40);
    vector<Effect> effects = vector<Effect>();
    Humanoid * human = new Humanoid("Jeff", 400, 800, 80, effects, armor, weapon);
    Creature * creature = new Creature("Shrek", 600, 1000, 80, effects);
    cout << "Creature hp before attack: " << creature->getHp() << endl;
    human->attack(creature);
    cout << "Creature hp after attack: " << creature->getHp() << endl;
    cout << "Human hp before attack: " << human->getHp() << endl;
    creature->attack(human);
    cout << "Human hp after attack: " << human->getHp() << endl;
    return 0;
}