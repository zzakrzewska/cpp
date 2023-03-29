//
// Created by Zosia Zakrzewska on 17/06/2022.
//

#ifndef PROJEKT_PLAYER_H
#define PROJEKT_PLAYER_H

#include <vector>
#include <string>
#include <fstream>
#include "Creature.h"


class Player {
    std::string name;
    std::vector<Creature> team;
    std::vector<Creature> selection;
    int current;
    int difficulty;

public:
    /*konstruktory*/
    Player();
    Player(std::string name, std::vector<Creature> team, int difficulty, std::vector<Creature> selection);
    /*zwraca obecnie wybranego stworka*/
    Creature getCurrent();
    /*zwraca index obecnie wybranego stworka*/
    int getIndex();
    /*zwraca imie gracza*/
    std::string getName();
    /*zmienia wybranego stworka*/
    void swap(int index);
    /*zapisuje dane*/
    void save(std::vector<Creature> team);
    /*wczytuje dane*/
    void load(std::vector<Creature> team);
    /*resetuje wszystkie stworki*/
    void reset();
};


#endif //PROJEKT_PLAYER_H
