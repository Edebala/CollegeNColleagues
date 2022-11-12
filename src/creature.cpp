Creature::Creature(const string& name, int hp, int maxHp, int strength, vector<Effect> effect){
    this->name = name;
    this->hp = hp;
    this->maxHp = maxHp;
    this->strength = strength;
    this->effect = effect;
}

void Creature::setName(const string& name){
    this->name = name;
}

void Creature::setHp(int hp){
    this->hp = hp;
}

void Creature::setMaxHp(int maxHp){
    this->maxHp = maxHp;
}

void Creature::setStrength(int strength){
    this->strength = strength;
}

void Creature::setEffect(vector<Effect> effect){
    this->effect = effect;
}

string Creature::getName(){
    return this->name;
}

int Creature::getHp() const{
    return this->hp;
}

int Creature::getMaxHp() const{
    return this->maxHp;
}

int Creature::getStrength() const {
    return this->strength;
}

vector<Effect> Creature::getEffect() const {
    return this->effect;
}

bool Creature::attack(Humanoid* enemy) const{
    int enemyHp = enemy->getHp();
    int strength = this->getStrength();
    int armor = enemy->getArmor()->getDefense();
    int damage = 2 * strength / armor;

    int newEnemyHp;
    if(enemyHp > damage)
        newEnemyHp = enemyHp - damage;
    else
        newEnemyHp = 0;

    enemy->setHp(newEnemyHp);

    if(enemyHp != enemy->getHp())
        return true;
    else
        return false;
}

// Humanoid functions implementation

Humanoid::Humanoid(const string& name, int hp, int maxHp, int strength, vector<Effect> effect, Armor *armor, Weapon *weapon){
    this->name = name;
    this->hp = hp;
    this->maxHp = maxHp;
    this->strength = strength;
    this->effect = effect;
    this->armor = armor;
    this->weapon = weapon;
}

void Humanoid::setName(const string &name) {
    this->name = name;
}

void Humanoid::setHp(int hp){
    this->hp = hp;
}

void Humanoid::setMaxHp(int maxHp) {
    this->maxHp = maxHp;
}

void Humanoid::setStrength(int strength) {
    this->strength = strength;
}

void Humanoid::setEffect(vector<Effect> effect) {
    this->effect = effect;
}

void Humanoid::setArmor(Armor* armor){
    this->armor = armor;
}

void Humanoid::setWeapon(Weapon* weapon){
    this->weapon = weapon;
}

int Humanoid::getHp() const{
    return this->hp;
}

int Humanoid::getStrength() const{
    return this->strength;
}

Weapon* Humanoid::getWeapon() const{
    return this->weapon;
}

Armor* Humanoid::getArmor() const{
    return this->armor;
}

bool Humanoid::attack(Creature *enemy) const {
    int enemyHp = enemy->getHp();
    int strength = this->getStrength();
    int weaponDamage = this->weapon->getDamage();
    int damage = 2 * strength * weaponDamage;

    int newEnemyHp;
    if(enemyHp > damage)
        newEnemyHp = enemyHp - damage;
    else
        newEnemyHp = 0;

    enemy->setHp(newEnemyHp);

    if(enemyHp != enemy->getHp())
        return true;
    else
        return false;
}
