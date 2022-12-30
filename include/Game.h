#pragma once
class Slot;
class Item;
class Armor;
class Weapon;
class Inventory;
class Creature;
class Humanoid;
class Throwable;
class Potion;

enum MoveType{MOVE_IDLE,MOVE_JUMP_RIGHT,MOVE_JUMP_LEFT,MOVE_JUMP_UP,MOVE_JUMP_DOWN};

using namespace std;
#include <iostream>
#include <unistd.h>
#include <sstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Slot.h"
#include "items.h"
#include "Armor.h"
#include "Weapon.h"
#include "Potion.h"
#include "creature.h"
#include "inventory.h"
#include "Business.h"
#include "spells.h"
#include "Map.h"
#include "Entity.h"
#include "Camera.h"
#include "Character.h"
#include "TextureUnit.h"
#include "Frame.h"
#include "Animation.h"
#include "MapRendering.h"
#include "TimeManager.h"
#include "TextLine.h"
#include "UIBox.h"
#include "FightLog.h"
#include "Teleporter.h"
