//
// Created by Zosia Zakrzewska on 17/06/2022.
//

#include "Player.h"

Player::Player(){
    Player::name = "";
    Player::current = 0;
    Player::difficulty = 0;
}

Player::Player(std::string name, std::vector<Creature> team, int difficulty, std::vector<Creature> selection){
    Player::name = name;
    Player::team = team;
    Player::current = 0;
    Player::difficulty = difficulty;
    Player::selection = selection;
}

Creature Player::getCurrent(){
    return team.at(Player::current);
}

int Player::getIndex(){
    return Player::current;
}

std::string Player::getName(){
    return Player::name;
}

void Player::swap(int index){
    if(team.at(index).checkState() == 0)
        std::cout << "zmiana niemozliwa - wybrany stworek zemdlal..." << std::endl;
    else {
        std::cout << "stworek zostal zmieniony!";
        Player::current = index;
    }
}

void Player::reset(){
    for(size_t a = 0; a < team.size(); a++){
        team.at(a).reset();
    }
}

void Player::save(std::vector<Creature> team){
    std::fstream fileOut;
    fileOut.open("zapis.txt", std::ios::out);

    if(fileOut.is_open()){
        fileOut << Player::name << "\n";
        fileOut << Player::difficulty << "\n";

        for(size_t a = 0; a < team.size(); a++){
            fileOut << team.at(a).getIndex(selection) << "\n";
        }
    }

    fileOut.close();
}

void Player::load(std::vector<Creature> team){
    std::fstream fileIn;
    fileIn.open("zapis.txt", std::ios::in);
    int index;

    if(fileIn.is_open()){
        fileIn >> Player::name;
        fileIn >> Player::difficulty;

        for(size_t a = 0; a < 6; a++){
            fileIn >> index;
            team.push_back(selection.at(index));
        }
    }

    fileIn.close();
}