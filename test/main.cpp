#include <iostream>
#include <vector>
#include "../include/creature.h"
#include <variant>

using namespace std;

int main(){
    //Creature tests

        // Testing Creature classes instances with non-magical Weapon(magic adjust = 0) and Armor instances

	Weapon * weapon = new Weapon("Sword", 100);
    Armor * armor = new Armor("Lionskin", 40);
    Humanoid * human = new Humanoid("Jeff", 400, 800, 80, armor, weapon);
    Creature * creature = new Creature("Shrek", 600, 1000, 80);

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

        // Testing WeaponBuffPotion instance with Weapon instance

    WeaponBuffPotion * weaponBuffPotion = new WeaponBuffPotion("Rampage", 1, 60);
    weaponBuffPotion->use(human->getWeapon());
    cout << "Humans weapon damage after buff: " << human->getWeapon()->getDamage() << endl;

        // Testing ArmorBuffPotion instance with Armor instance

    ArmorBuffPotion * armorBuffPotion = new ArmorBuffPotion("The best defense", 1, 50);
    armorBuffPotion->use(human->getArmor());
    cout << "Humans armor defense after buff: " << human->getArmor()->getDefense() << endl;

        // Testing StrengthenPotion instance on Creature instance

    StrengthenPotion * strengthenPotion = new StrengthenPotion("Lion heart", 1, 70);
    strengthenPotion->use(creature);
    cout << "Creature strength after strengthen potion: " << creature->getStrength() << endl << endl;

    // Inventory tests

        // Testing inventory adding

        Inventory * inventory = new Inventory();
        inventory->addElement(fire);
        inventory->addElement(poison);
        inventory->addElement(healingPotion);
        inventory->addElement(weaponBuffPotion);

        human->setInventory(inventory);

        cout << "Infos about human inventory elements: ";

        for(MultiType element : human->getInventory()->getElements())
            switch (element.index()){
                case 7: cout << get<Fireball*>(element)->getDamage() << " "; break;
                case 8: cout << get<PoisonGas*>(element)->getDamage() << " ";break;
                case 3: cout << get<HealingPotion*>(element)->getHp() << " "; break;
                case 4: cout << get<WeaponBuffPotion*>(element)->getAmount() << " "; break;
            }

        cout << endl;


        //Testing Erase spell

//    Erase * erase = new Erase(1);
//    erase->cast(creature, human);
//
//    Inventory * testInv = human->getInventory();
//
//    cout << "Human inventory contains after Erase: ";
//
//    for(MultiType element : human->getInventory()->getElements())
//        switch (element.index()){
//            case 7: cout << get<Fireball*>(element)->getDamage() << " "; break;
//            case 8: cout << get<PoisonGas*>(element)->getDamage() << " ";break;
//            case 3: cout << get<HealingPotion*>(element)->getHp() << " "; break;
//            case 4: cout << get<WeaponBuffPotion*>(element)->getAmount() << " "; break;
//        }
//
//    cout << endl;

        // Testing use element by index function

    human->useElementFromInventoryByIndex(0, human, creature);

    cout << "Creature hp after using fireball from inv: " << creature->getHp() << endl;

    human->useElementFromInventoryByIndex(2, human, creature);

    cout << "Human weapon damage after healing potion from inv: " << human->getHp() << endl;
    
    return 0;
}