#include "Game.h"
#include "creature.h"

using namespace std;

int fight(Creature *player, Creature *enemy);

bool useSpell(Creature *player, Creature *enemy);

bool useItem(Creature *player, Creature *enemy);

int getPlayersMove();

int getSpellToCast();

int getItemToUse();
