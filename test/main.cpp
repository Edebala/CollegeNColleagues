#include <iostream>
#include <vector>
#include "../include/creature.h"

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
    cout << "Human hp after attack: " << human->getHp() << endl << endl;
    Weapon * magicWeapon = new Weapon("Magic staff", 2, 60);
    human->setWeapon(magicWeapon);
    Fireball * fire = new Fireball(1);
    human->addSpell(fire);
    Fireball* fireball = ((Fireball*)human->getSpells().at(0));
    fireball->cast(human, creature);
    cout << "Creature hp after fireball: " << creature->getHp() << endl;
    PoisonGas * poison = new PoisonGas(3);
    creature->addSpell(poison);
    PoisonGas * poisonGas = ((PoisonGas*)creature->getSpells().at(0));
    poisonGas->cast(creature, human);
    cout << "Human hp after poison gas: " << human->getHp() << endl;
    return 0;
}