class Spell{
public:
    int Cast(Creature *caster, Creature* enemy) = 0;
};

class Fireball: public Spell{
public:
    int Cast(Creature *caster, Creature* enemy){
		enemy->damage(5*caster.tool.getMagicAdjust());
	}
}

class PoisonGas: public Spell{
public:
	int Cast(Creature *caster, Creature* enemy){
		enemy->damage(2*caster.tool.getMagicAdjust());
	}
}

