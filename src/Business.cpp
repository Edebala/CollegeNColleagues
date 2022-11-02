#include "classes.h"
#include <string>

int fight(Creature *player, Creature *enemy) {
    bool playerTurn = true;
    int done;
    while (player.getHp() > 0 && enemy.getHp() > 0) {
        if (playerTurn) {
            // move 1 -> fight/attack
            // move 2 -> cast spell
            // move 3 -> use item
            int move = getMove();
            switch (move) {
                case 1:
                    done = attack(Creature* player, Creature* enemy);
            }
        } else {

        }
    }
}
int Creature::attack(Creature* player, Creature *enemy) {
    int enemyHP = enemy.getHp();
    int strength = player.getStrength();
    int weaponDMG = player.getWeaponDmg();
    int armorHP = enemy.getArmor();
    int damage = 2 * strength * weaponDMG / armorHP;
    if(enemy)

    int newEnemyHp = enem
}
