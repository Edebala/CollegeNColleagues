class Spell;

class Fireball: public Spell{
	int Cast(Creature *caster, Creature* enemy){
		enemy.damage(5*caster.tool.getMagicAdjust());
	}
}

class PoisonGas: public Spell{
	int Cast(Creature *caster, Creature* enemy){

		enemy.damage(5*caster.tool.getMagicAdjust());
	}
}

