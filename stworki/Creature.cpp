//
// Created by Zosia Zakrzewska on 16/06/2022.
//

#include "Creature.h"

Creature::Creature(int type, int atk, int hp, int dext, std::string name, int ability){
    Creature::type = type;
    Creature::atk = atk;
    Creature::atkTemp = atk;
    Creature::maxHp = hp;
    Creature::hp = hp;
    Creature::dext = dext;
    Creature::dextTemp = dext;
    Creature::name = name;
    Creature::state = 1;
    Creature::exp = 0;
    Creature::ability = ability;
    Creature::cooldown = 0;
}

std::string Creature::typeName() const{
    switch(Creature::type){
        case 0:
            return "woda";
        case 1:
            return "ziemia";
        case 2:
            return "powietrze";
        case 3:
            return "ogien";
        case 4:
            return "lod";
        case 5:
            return "stal";
        default:
            return "";
    }
}

void Creature::show(){
    std::cout << name << " | typ - " << typeName() << std::endl;
    std::cout << "statystyki: atak: " << Creature::atk << std::endl;
    std::cout << "\t" << "\t" << "\t" << "hp: " << Creature::hp << std::endl;
    std::cout << "\t" << "\t" << "\t" << "zwinnosc: " << Creature::dext << "\n" << std::endl;
}

void Creature::showShort(){
    std::cout << Creature::name << " | atak: " << Creature::atk << " | hp: " << Creature::hp << " | zwinnosc: " << Creature::dext << " |" << std::endl;
}

void Creature::showName(){
    std::cout << Creature::name;
}

int Creature::getIndex(std::vector<Creature> selection){
    int index;

    for(size_t a = 0; a < selection.size(); a++)
        if(Creature::name == selection.at(a).name)
            index = a;

    return index;
}

void Creature::statsUp(){
    Creature::atk += 5;
    Creature::maxHp += 10;
}

void Creature::gainExp() {
    Creature::exp += 1;
}

void Creature::evolve(){
    if(Creature::exp >= 10){
        std::cout << "stworek " << Creature::name << " ewoluuje!" << std::endl;
        statsUp();
        std::cout << "statystyki zwiekszone!" << std::endl;
        Creature::exp = 0;
    } else
        std::cout << "stworek " << Creature::name << " ma o " << 10-Creature::exp <<
            " za malo punktow exp zeby ewoluowac" << std::endl;
}

int Creature::affinity(Creature* opponent) const{
    switch(Creature::type){
        case 0: //woda
            if(opponent->type == 0 || opponent->type == 3 || opponent->type == 4)
                return 0;
            else if(opponent-> type == 5)
                return 2;
            else
                return 1;
        case 1: //ziemia
            if(opponent->type == 2 || opponent->type == 3)
                return 0;
            else if(opponent->type == 0 || opponent->type == 4)
                return 2;
            else
                return 1;
        case 2: //powietrze
            if(opponent->type == 1)
                return 0;
            else if(opponent->type == 5)
                return 2;
            else
                return 1;
        case 3: //ogien
            if(opponent->type == 4 || opponent->type == 5)
                return 0;
            else if(opponent->type == 0 || opponent->type == 1)
                return 2;
            else
                return 1;
        case 4: // lod
            if(opponent->type == 4)
                return 0;
            else if(opponent->type == 1 || opponent->type == 2 || opponent->type == 3)
                return 2;
            else
                return 1;
        case 5: // stal
            if(opponent->type == 2 || opponent->type == 5)
                return 0;
            else if(opponent->type == 1 || opponent->type == 3)
                return 2;
            else
                return 1;
        default:
            return 1;
    }
}

void Creature::damage(int dmg){
    Creature::hp -= dmg;
}

int Creature::checkState(){
    if(Creature::hp <= 0) {
        Creature::state = 0;
        return 0;
    }
    else {
        Creature::state = 1;
        return 1;
    }
}

int Creature::attack(Creature* opponent, double modifier) const{
    int dmg;
    std::cout << Creature::name << " atakuje przeciwnika " << opponent->name << "!" << std::endl;

    int dex = opponent->dext;
    int dodge = (std::rand()%10)+1;

    if(dex >= dodge) {
        std::cout << opponent->name << " uniknal ataku!" << std::endl;
        return 0;
    }

    if(affinity(opponent) == 0) {
        std::cout << "efektywnosc ataku zmniejszona..." << std::endl;
        dmg = Creature::atk * modifier * 0.8;
    } else if(affinity(opponent) == 2) {
        std::cout << "efektywnosc ataku zwiekszona!" << std::endl;
        dmg = Creature::atk * modifier * 1.2;
    } else {
        dmg = Creature::atk * modifier;
    }

    std::cout << Creature::name << " zadaje " << dmg << " obrazen przeciwnikowi " << opponent->name << "!" << std::endl;
    opponent->damage(dmg);
    opponent->checkState();
    return dmg;
}

spec Creature::special(Creature* opponent){

    Creature::cooldown = 1;

    switch(Creature::type){
        case 0: //wodne

            if(Creature::ability == 0) { //leczy 10hp
                std::cout << Creature::name << " uzywa specjalnej umiejetnosci: kropla zycia" << std::endl;
                Creature::hp += 10;
                std::cout << Creature::name << " wyleczyl " << 10 << " hp." << std::endl;
                return {0, 0, 0};

            } else if(Creature::ability == 1) { //ignoruje typ
                std::cout << Creature::name << " uzywa specjalnej umiejetnosci: tsunami" << std::endl;
                std::cout << Creature::name << " ignoruje typ przceciwnika, zadajac mu " << Creature::atk << " obrazen!" << std::endl;
                opponent->damage(Creature::atk);
                return {Creature::atk, 0, 0};
            }

        case 1: //ziemia

            if(Creature::ability == 0) { //atk+5
                std::cout << Creature::name << " uzywa specjalnej umiejetnosci: fotosynteza" << std::endl;
                std::cout << "atak stworka " << Creature::name << " zwieksza sie o 5 na 3 kolejki!" << std::endl;
                return {-1, 2, 5};

            } else if(Creature::ability == 1) { //trucizna - dmg na 3 kolejki
                int dmg = Creature::atk*0.2;
                std::cout << Creature::name << " uzywa specjalnej umiejetnosci: trucizna" << std::endl;
                std::cout << Creature::name << " zatruwa przeciwnika, co bedzie zadawalo mu dodatkowe " << dmg << " obrazen przez 3 kolejki!" << std::endl;
                return {dmg, 2, 0};
            }

        case 2: //powietrze

            if(Creature::ability == 0) { //tornado
                int dmg = Creature::atk*1.4;
                std::cout << Creature::name << " uzywa specjalnej umiejetnosci: tornado" << std::endl;
                std::cout << Creature::name << " atakuje za 1.4x swojego ataku, zadajac " << dmg << " obrazen!" << std::endl;
                attack(opponent, 1.4);
                return {dmg, 0, 0};

            } else if(Creature::ability == 1) { //dext+1
                std::cout << Creature::name << " uzywa specjalnej umiejetnosci: powiew" << std::endl;
                std::cout << "szansa na unikniecie ataku przeciwnika " << Creature::name << " zwieksza sie o 10% na 3 kolejki!" << std::endl;
                return {-3, 2, 1};
            }

        case 3: //ogien

            if(Creature::ability == 0) { //kula ognia
                int dmg = Creature::atk*1.5;
                std::cout << Creature::name << " uzywa specjalnej umiejetnosci: kula ognia" << std::endl;
                std::cout << Creature::name << " atakuje za 1.5x swojego ataku, zadajac " << dmg << " obrazen!" << std::endl;
                attack(opponent, 1.5);
                return {dmg, 0, 0};

            } else if(Creature::ability == 1) { //dodatkowe obrazenia przez 3 kolejki
                int dmg = Creature::atk*0.2;
                std::cout << Creature::name << " uzywa specjalnej umiejetnosci: podpalenie" << std::endl;
                std::cout << Creature::name << " podpala przeciwnika, co bedzie zadawalo mu dodatkowe " << dmg << " obrazen przez 3 kolejki!" << std::endl;
                return {dmg, 2, 0};
            }

        case 4: //lod

            if(Creature::ability == 0) { //burza sniezna
                int dmg = Creature::atk*1.5;
                std::cout << Creature::name << " uzywa specjalnej umiejetnosci: burza sniezna" << std::endl;
                std::cout << Creature::name << " atakuje za 1.5x swojego ataku, zadajac " << dmg << " obrazen!" << std::endl;
                attack(opponent, 1.5);
                return {dmg, 0, 0};

            } else if(Creature::ability == 1) { //zmrozenie
                std::cout << Creature::name << " uzywa specjalnej umiejetnosci: zamrozenie" << std::endl;
                std::cout << Creature::name << " zmniejsza atak przeciwnika " << opponent->name << " o 3 na 3 kolejki!" << std::endl;
                return {-11, 3, -3};
            }

        case 5: //stal

            if(Creature::ability == 0) { //kowadlo
                int dmg = Creature::atk*1.2;
                std::cout << Creature::name << " uzywa specjalnej umiejetnosci: kowadlo" << std::endl;
                std::cout << Creature::name << " atakuje kowadlem za 1.1x swojego ataku, zadajac " << dmg << " obrazen!" << std::endl;
                attack(opponent, 1.1);
                return{dmg, 0, 0};

            } else if(Creature::ability == 1) { //stalowa skora
                std::cout << Creature::name << " uzywa specjalnej umiejetnosci: stalowa skora" << std::endl;
                Creature::hp += 15;
                std::cout << Creature::name << " wyleczyl sie za " << 15 << " hp." << std::endl;
                return {0, 0, 0};
            }

        default:
            return {0, 0, 0};
    }
}

bool Creature::onCooldown(){
    if(Creature::cooldown == 0)
        return false;
    else
        return true;
}

void Creature::increaseAtk(int modifier) {
    Creature::atkTemp = Creature::atk;
    std::cout << "atak stworka " << Creature::name << " zmieniony o " << modifier << "!" << std::endl;
    Creature::atk += modifier;
}

void Creature::resetAtk() {
    Creature::atk = Creature::atkTemp;
    std::cout << "atak stworka " << Creature::name << " przywrocony do " << Creature::atkTemp << "." << std::endl;
}

void Creature::increaseDext(int modifier) {
    Creature::dextTemp = Creature::dext;
    std::cout << "zwinnosc stworka " << Creature::name << " zmieniona o " << modifier << "!" << std::endl;
    Creature::dext += modifier;
}

void Creature::resetDext() {
    Creature::dext = Creature::dextTemp;
    std::cout << "zwinnosc stworka " << Creature::name << " przywrocona do " << Creature::dextTemp << "." << std::endl;
}


void Creature::reset() {
    Creature::hp = Creature::maxHp;
    Creature::cooldown = 0;
    Creature::state = 1;
}