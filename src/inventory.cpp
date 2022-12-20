#include "../include/inventory.h"

long unsigned int Inventory::maxSize = 20;

Inventory::Inventory() {};

void Inventory::setElements(vector<MultiType> elements) {
    this->elements = elements;
}

vector<MultiType> Inventory::getElements() const {
    return this->elements;
}

bool Inventory::addElement(MultiType element){
    if(this->elements.size() < maxSize) {
        this->elements.emplace_back(element);
        return true;
    }
    return false;
}

void Inventory::deleteElementByIndex(int index){
    if(this->elements.size() > 0)
        this->elements.erase(this->elements.begin() + index);
}

void Inventory::useElementByIndex(int index, Humanoid *player, Creature *enemy) {
    auto hPlayer = (Humanoid*) player;
    MultiType element = player->getInventory()->getElements().at(index);
    int typeIndex = player->getInventory()->getElements().at(index).index();
    bool isUsable = false;

    switch (typeIndex){
        case 2: get<Throwable*>(element)->use(enemy); isUsable = true; break;
        case 3: get<HealingPotion*>(element)->use(player); isUsable = true; break;
        case 4: if(hPlayer->getWeapon() != nullptr) get<WeaponBuffPotion*>(element)->use(hPlayer->getWeapon()); isUsable = true; break;
        case 5: if(hPlayer->getArmor() != nullptr) get<ArmorBuffPotion*>(element)->use(hPlayer->getArmor()); isUsable = true; break;
        case 6: get<StrengthenPotion*>(element)->use(player); isUsable = true; break;
        case 7: get<Fireball*>(element)->cast(player, enemy); break;
        case 8: get<PoisonGas*>(element)->cast(player, enemy); break;
        case 9: get<Debuff*>(element)->cast(player, enemy); break;
        case 10: get<Erase*>(element)->cast(player, enemy); break;
    }

    if(isUsable) {
        Inventory * newInv = player->getInventory();
        newInv->deleteElementByIndex(index);
        player->setInventory(newInv);
    }
}

