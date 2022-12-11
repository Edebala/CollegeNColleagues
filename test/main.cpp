#include <iostream>
#include <vector>
#include "../include/creature.h"

using namespace std;


int main(){
    //Creature tests

        // Testing Creature classes instances with non-magical Weapon(magic adjust = 0) and Armor instances

	Weapon * weapon = new Weapon("Sword", 100);
    Armor * armor = new Armor("Lionskin", 40);
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
    fire->cast(human, creature);
    cout << "Creature hp after fireball: " << creature->getHp() << endl;

        // Testing damaging Spell instances with magical Weapon instance(magic adjust > 0)

    PoisonGas * poison = new PoisonGas(3);
    Weapon * magicWeapon = new Weapon("Magic staff", 2, 60);
    human->setWeapon(magicWeapon);
    poison->cast(creature, human);
    cout << "Human hp after poison gas: " << human->getHp() << endl;

        // Testing Debuff instance with magical Weapon instance(magic adjust > 0)

    Debuff * debuff = new Debuff(1, 20, 300);
    debuff->cast(human, creature);
    cout << "Creature strength after debuff: " << creature->getStrength() << endl;
    cout << "Creature max hp after debuff: " << creature->getMaxHp() << endl;
    cout << "Creature hp after debuff: " << creature->getHp() << endl << endl;

    // Throwable tests

        // Testing Throwable instance with Creature instance

    Throwable * throwable = new Throwable("Shuriken", 4);
    throwable->use(creature);
    cout  << "Creature hp after throwable: " << creature->getHp() << endl;
    if (throwable->getDamage() == 0)
        cout << "Item used!" << endl << endl;
    else
        cout << "Item unused!" << endl << endl;

    // Potion tests

        // Testing HealingPotion instance with Humanoid instance

    HealingPotion * healingPotion = new HealingPotion("Maiden tears", 1, 50);
    healingPotion->use(human);
    cout << "Human hp after healing: " << human->getHp() << endl;

        // Testing EquipmentBuffPotion instance with Weapon instance

    EquipmentBuffPotion * equipmentBuffPotion = new EquipmentBuffPotion("Rampage", 1, 60);
    equipmentBuffPotion->use(human->getWeapon());
    cout << "Humans weapon damage after buff: " << human->getWeapon()->getDamage() << endl;

        // Testing StrengthenPotion instance on Creature instance

    StrengthenPotion * strengthenPotion = new StrengthenPotion("Lion heart", 1, 70);
    strengthenPotion->use(creature);
    cout << "Creature strength after strengthen potion: " << creature->getStrength() << endl;

    return 0;
}