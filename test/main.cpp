#include <iostream>
#include <vector>
#include "../include/creature.h"

using namespace std;

int main(){
    //Creature tests

        // Testing Creature classes instances with non-magical Weapon(magic adjust = 0) and Armor instances

	Weapon * weapon = new Weapon("Kard", 100);
    Armor * armor = new Armor("Oroszlanbor", 40);
    vector<Effect> effects = vector<Effect>();
    Humanoid * human = new Humanoid("Jeff", 400, 800, 80, effects, armor, weapon);
    Creature * creature = new Creature("Shrek", 600, 1000, 80, effects);

        //Testing Creature classes instances attack function

    cout << "Creature hp before attack: " << creature->getHp() << endl;
    human->attack(creature);
    cout << "Creature hp after attack: " << creature->getHp() << endl;
    cout << "Human hp before attack: " << human->getHp() << endl;
    creature->attack(human);
    cout << "Human hp after attack: " << human->getHp() << endl << endl;

    // Spell tests

        // Testing damaging Spell instances

    Fireball * fire = new Fireball(1);
    human->addSpell(fire);
    Fireball* fireball = ((Fireball*)human->getSpells().at(0));
    fireball->cast(human, creature);
    cout << "Creature hp after fireball: " << creature->getHp() << endl;
    PoisonGas * poison = new PoisonGas(3);
    creature->addSpell(poison);

        // Testing damaging Spell instances with magical Weapon instance(magic adjust > 0)

    Weapon * magicWeapon = new Weapon("Magic staff", 2, 60);
    human->setWeapon(magicWeapon);
    PoisonGas * poisonGas = ((PoisonGas*)creature->getSpells().at(0));
    poisonGas->cast(creature, human);
    cout << "Human hp after poison gas: " << human->getHp() << endl << endl;

    // Throwable tests

    Throwable * throwable = new Throwable("Shuriken", 4);
    human->useThrowable(throwable, creature);
    cout  << "Creature hp after throwable: " << creature->getHp() << endl;
    if (throwable->getDamage() == 0)
        cout << "Item used!" << endl << endl;
    else
        cout << "Item unused!" << endl << endl;

    //Potion tests



    return 0;
}