#pragma once
#include "Business.h"

int fight(Creature *player, Creature *enemy) {
    bool dead = false;

    while (true) {
        // humaniod's turn
        if (!dead) {
            switch (getPlayersMove()) {
                case 1:
                    dead = player->attack(enemy)}
                    break;
                case 2:
                    dead = useSpell(player, enemy);
                    break;
                case 3:
                    dead = useItem();
                    break;
                default:
                    break;
            }
        }

        // creature/enemy's turn
        if (!dead)
            dead = enemy->attack(player);
    }
}

/*
 * number 1     ->      Attack
 * number 2     ->      use Spell
 * number 3     ->      use Item
*/
int getPlayersMove() {
    int moveNr = 1;
    // TODO: bind a key to the players choice
    return moveNr;
}

/*
 * number 1     ->      Fireball
 * number 2     ->      Poison gas
 * number 3     ->      Debuff
 * number 4     ->      ????? buff/erase or what
*/
int getSpellToCast() {
    int spellNr = 1;
    // TODO: bind a key to the players choice
    return spellNr;
}

/*
 * number 1     ->      Throwable
 * number 2     ->      Healing Potion
 * number 3     ->      Weapon Buff
 * number 4     ->      Armor Buff
 * number 5     ->      Strengthen
 */
int getItemToUse() {
    int itemNr = 1;
    // TODO: bind a key to the players choice
    return itemNr;
}

bool useSpell(Creature *player, Creature *enemy) {
    bool dead = false;
    switch (getSpellToCast()) {
        case 1: {
            Fireball *fire = new Fireball(1);
            if (fire->cast(player, enemy)) { dead = true; }
            break;
        }
        case 2: {
            PoisonGas *poison = new PoisonGas(3);
            if (poison->cast(player, enemy)) { dead = true; }
            break;
        }
        case 3: {
            Debuff *debuff = new Debuff(1, 20, 300);
            debuff->cast(player, enemy);
            break;
        }
        case 4: {
            // buff == erase
            break;
        }
        default: {
            break;
        }
    }
    return dead;
}

bool useItem(Creature *player, Creature *enemy) {
    bool dead = false;
    switch (getItemToUse()) {
        case 1: {
            Throwable *throwable = new Throwable("Shuriken", 4);
            throwable->use(enemy);
            break;
        }
        case 2: {
            HealingPotion *healingPotion = new HealingPotion("Maiden tears", 1, 50);
            healingPotion->use(player);
            break;
        }
        case 3: {
            WeaponBuffPotion *equipmentBuffPotion = new WeaponBuffPotion("Rampage", 1, 60);
            equipmentBuffPotion->use(player->getWeapon());
            break;
        }
        case 4: {
            ArmorBuffPotion *armorBuffPotion = new ArmorBuffPotion("The best defense", 1, 50);
            armorBuffPotion->use(player->getArmor());
            break;
        }
        case 5: {
            StrengthenPotion *strengthenPotion = new StrengthenPotion("Lion heart", 1, 70);
            strengthenPotion->use(player);
            break;
        }
        default: {
            break;
        }
    }
}
