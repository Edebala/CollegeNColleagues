#include "Game.h"

long unsigned int Inventory::maxSize = 20;

Inventory::Inventory() {}

void Inventory::setElements(vector<Slot*> elements) {
    this->elements = elements;
}

vector<Slot*> Inventory::getElements() const {
    return this->elements;
}

bool Inventory::addElement(Slot* element){
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
    Slot* element = player->getInventory()->getElements()[index];
		player->getInventory()->deleteElementByIndex(index);
}

