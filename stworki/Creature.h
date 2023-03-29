//
// Created by Zosia Zakrzewska on 16/06/2022.
//

#ifndef PROJEKT_CREATURE_H
#define PROJEKT_CREATURE_H
#include <iostream>
#include <ctime>
#include <vector>

struct spec{
    int dmg;
    int turns;
    int modifier;
};

class Creature {
    int type;
    std::string name;
    int state;
    int atk;
    int atkTemp;
    int maxHp;
    int hp;
    int dext;
    int dextTemp;
    int exp;
    int ability;
    int cooldown;

public:
    /*konstruktor*/
    Creature(int type, int atk, int hp, int dext, std::string name, int ability);
    /*wypisuje nazwe typu stworka*/
    std::string typeName() const;
    /*pokazuje informacje o stworku*/
    void show();
    /*pokazuje skrocone informacje o stworku*/
    void showShort();
    /*wypisuje nazwe stworka*/
    void showName();
    /*zwraca index stworka w ogolnym wektorze dostepnych stworkow*/
    int getIndex(std::vector<Creature> selection);
    /*zwieksza statystyki stworka*/
    void statsUp();
    /*dodaje exp stworkowi*/
    void gainExp();
    /*sprawdza czy stworek moze ewoluowac*/
    void evolve();
    /*sprawdza modyfikator obrazen w zaleznosci od typu swojego i przeciwnika*/
    int affinity(Creature* opponent) const;
    /*zadaje obrazenia niezaleznie od typu*/
    void damage(int dmg);
    /*sprawdza czy stworek zemdlal*/
    int checkState();
    /*zadaje obrazenia zaleznie od typu*/
    int attack(Creature* opponent, double modifier) const;
    /*definiuje+wybiera atak specjalny w zaleznosci od typu i rodzaju ataku*/
    spec special(Creature* opponent);
    /*zwraca czy umiejetnosc specjalna byla juz uzyta w tej rundzie*/
    bool onCooldown();
    /*modyfikuje atak stworka*/
    void increaseAtk(int modifier);
    /*modyfikuje zwinnosc stworka*/
    void increaseDext(int modifier);
    /*resetuje atak stworka*/
    void resetAtk();
    /*resetuje zwinnosc stworka*/
    void resetDext();
    /*resetuje stworka*/
    void reset();
};


#endif //PROJEKT_CREATURE_H
