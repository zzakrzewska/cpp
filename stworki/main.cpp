#include "Creature.h"
#include "Player.h"
#include <iostream>
#include <ctime>

int main() {

    srand(time(NULL));
    std::vector<Creature> selection;
    std::vector<Creature> selected;
    Player player;

    int woda = 0;
    int ziemia = 0;
    int powietrze = 0;
    int ogien = 0;
    int lod = 0;
    int stal = 0;

    //woda
    Creature kropelka = {0, 15, 35, 3, "kropelka", 0};
    selection.push_back(kropelka);
    woda++;
    Creature wodnik = {0, 12, 35, 4, "wodnik", 1};
    selection.push_back(wodnik);
    woda++;
    Creature osmiorniczka = {0, 18, 37, 3, "osmiorniczka", 1};
    selection.push_back(osmiorniczka);
    woda++;
    //ziemia
    Creature wiosna = {1, 18, 35, 3, "wiosna", 0};
    selection.push_back(wiosna);
    ziemia++;
    Creature krzak = {1, 10, 30, 2, "krzak", 1};
    selection.push_back(krzak);
    ziemia++;
    Creature kwiatek{1, 18, 30, 2, "kwiatek", 0};
    selection.push_back(kwiatek);
    ziemia++;
    //powietrze
    Creature nietoperz = {2, 20, 20, 5, "nietoperz", 0};
    selection.push_back(nietoperz);
    powietrze++;
    Creature chmurka = {2, 25, 30, 2, "chmurka", 1};
    selection.push_back(chmurka);
    powietrze++;
    //ogien
    Creature slonce = {3, 25, 35, 0, "slonce", 0};
    selection.push_back(slonce);
    ogien++;
    Creature plomien = {3, 20, 30, 2, "plomien", 1};
    selection.push_back(plomien);
    ogien++;
    Creature swieca = {3, 23, 28, 1, "swieca", 1};
    selection.push_back(swieca);
    ogien++;
    //lod
    Creature balwanek = {4, 20, 35, 2, "balwanek", 0};
    selection.push_back(balwanek);
    lod++;
    Creature lody = {4, 15, 30, 1, "lody", 1};
    selection.push_back(lody);
    lod++;
    //stal
    Creature kwadrat = {5, 6, 45, 0, "kwadrat", 0};
    selection.push_back(kwadrat);
    stal++;
    Creature metal = {5, 9, 40, 1, "metal", 1};
    selection.push_back(metal);
    stal++;

    int action;
    std::cout << "co chcesz zrobic?" << std::endl;
    std::cout << "1. nowa gra" << std::endl;
    std::cout << "2. wczytaj gre" << std::endl;
    std::cin >> action;

    if(action == 1){

        size_t a = 0;

        std::string name;
        std::cout << "wpisz swoje imie: ";
        std::cin >> name;
        std::cout << std::endl;

        int diff;
        std::cout << "wybierz poziom trudnosci:" << std::endl;
        std::cout << "1 - latwy" << std::endl;
        std::cout << "2 - sredni" << std::endl;
        std::cout << "3 - trudny" << std::endl;
        std::cin >> diff;

        std::cout << "wybierz swoja druzyne: " << "\n" << std::endl;

        std::cout << "TYP: WODA" << std::endl;
        for (a; a < woda; a++) {
            std::cout << a << ". ";
            selection.at(a).showShort();
        }
        std::cout << std::endl;

        ziemia += woda;
        std::cout << "TYP: ZIEMIA" << std::endl;
        for (a; a < ziemia; a++) {
            std::cout << a << ". ";
            selection.at(a).showShort();
        }
        std::cout << std::endl;

        powietrze += ziemia;
        std::cout << "TYP: POWIETRZE" << std::endl;
        for (a; a < powietrze; a++) {
            std::cout << a << ". ";
            selection.at(a).showShort();
        }
        std::cout << std::endl;

        ogien += powietrze;
        std::cout << "TYP: OGIEN" << std::endl;
        for (a; a < ogien; a++) {
            std::cout << a << ". ";
            selection.at(a).showShort();
        }
        std::cout << std::endl;

        lod += ogien;
        std::cout << "TYP: LOD" << std::endl;
        for (a; a < lod; a++) {
            std::cout << a << ". ";
            selection.at(a).showShort();
        }
        std::cout << std::endl;

        stal += lod;
        std::cout << "TYP: STAL" << std::endl;
        for (a; a < stal; a++) {
            std::cout << a << ". ";
            selection.at(a).showShort();
        }
        std::cout << std::endl;

        int index;

        for (int x = 0; x < 6; x++) {
            std::cout << "wybierz numer stworka nr " << x << ": ";
            std::cin >> index;
            selected.push_back(selection.at(index));
        }

        if (diff >= 2)
            for (size_t x = 0; a < selection.size(); a++)
                selection.at(a).statsUp();
        if (diff == 3)
            for (size_t x = 0; a < selection.size(); a++)
                selection.at(a).statsUp();

        player = {name, selected, diff, selection};

    } else if(action == 2){
        player.load(selection);
    }

    int select = 1;
    int round = 0;
    int opp = 0;
    bool alive = true;
    int playerSpecialDuration = -1;
    int playerSpecialDamage;
    int playerSpecialType;

    while(select != 0) {
        std::cout << "RUNDA " << round << std::endl;
        std::vector<Creature> opponents = {};

        for(int x = 0; x < 4; x++) {
            int index = (std::rand()%15);
            opponents.push_back(selection.at(index));
        }

        while(opp<4 && alive){

            std::cout << "walka: ";
            player.getCurrent().showName();
            std::cout << " vs ";
            opponents.at(opp).showName();
            std::cout << std::endl;

            std::cout << "co chcesz zrobic?" << std::endl;
            std::cout << "1. zmien stworka | obecnie aktywny: ";
            player.getCurrent().showName();
            std::cout << std::endl;
            std::cout << "2. atak" << std::endl;

            if (!player.getCurrent().onCooldown()) {
                std::cout << "3. umiejetnosc specjalna" << std::endl;
            }

            std::cin >> select;

            switch (select) {
                case 1:
                    int swap;
                    for (size_t x = 0; x < selected.size(); x++) {
                        std::cout << x << ". ";
                        selected.at(x).showShort();
                    }
                    std::cout << "wpisz numer stworka, ktorego chcesz wystawic: ";
                    std::cin >> swap;
                    player.swap(swap);
                    break;
                case 2:
                    player.getCurrent().attack(&opponents.at(opp), 1);
                    break;
                case 3:
                    if (!player.getCurrent().onCooldown()) {
                        spec special = player.getCurrent().special(&opponents.at(opp));
                        if (special.dmg < 0) {
                            switch (special.dmg) {
                                case -1:
                                    player.getCurrent().increaseAtk(special.modifier);
                                    playerSpecialDuration = special.turns;
                                    playerSpecialType = 1;
                                case -3:
                                    player.getCurrent().increaseDext(special.modifier);
                                    playerSpecialDuration = special.turns;
                                    playerSpecialType = 2;
                                case -11:
                                    opponents.at(opp).increaseAtk(special.modifier);
                                    playerSpecialDuration = special.turns;
                                    playerSpecialType = -1;
                            }
                        } else if (special.dmg > 0 && special.turns > 0) {
                            playerSpecialDuration = special.turns;
                            playerSpecialDamage = special.dmg;
                            playerSpecialType = 0;
                        }
                    } else
                        std::cout << "umiejetnosc specjalna zostala juz uzyta w tej walce przez tego stworka!";
                    break;
                default:
                    std::cout << "wybrano nieprawidlowy numer" << std::endl;
                    break;
            }

            if(playerSpecialDuration > 0){
                if(playerSpecialType == 0)
                    opponents.at(opp).damage(playerSpecialDamage);
                playerSpecialDuration--;
            }

            if(playerSpecialDuration == 0){
                if(playerSpecialType == 1)
                    player.getCurrent().resetAtk();
                else if(playerSpecialType == 2)
                    player.getCurrent().resetDext();
                else if(playerSpecialType == -1)
                    opponents.at(opp).resetAtk();

                playerSpecialDuration--;
            }

            opponents.at(opp).attack(&selected.at(player.getIndex()), 1);

            if (opponents.at(opp).checkState() == 0) {
                std::cout << "stworek ";
                opponents.at(opp).showName();
                std::cout << " zemdlal!" << std::endl;
                opp++;
                player.getCurrent().gainExp();
            }

            alive = false;
            for (size_t x = 0; x < selected.size(); x++) {
                if(selected.at(x).checkState() == 1)
                    alive = true;
            }

            if(selected.at(player.getIndex()).checkState() == 0){
                std::cout << "stworek ";
                player.getCurrent().showName();
                std::cout << " zemdlal!" << std::endl;
                int swap;
                for (size_t x = 0; x < selected.size(); x++)
                    if (selected.at(x).checkState() == 1) {
                        std::cout << x << ". ";
                        selected.at(x).showShort();
                    }
                std::cout << "wpisz numer stworka, ktorego chcesz wystawic: ";
                std::cin >> swap;
                player.swap(swap);
            }

        }

        if(!alive)
            std::cout << "gracz " << player.getName() << " przegral!";
        else if(opp>=4)
            std::cout << "gracz " << player.getName() << " wygral!";
        std::cout << std::endl;

        int act;
        std::cout << "co chcesz zrobic?" << std::endl;
        std::cout << "0. zakoncz" << std::endl;
        std::cout << "1. kontynuuj" << std::endl;
        std::cout << "2. zapisz i wyjdz" << std::endl;
        std::cin >> act;

        switch(act){
            case 0:
                select = 0;
                break;
            case 1:
                round++;
                player.reset();
                select = 1;
                break;
            case 2:
                player.save(selected);
                select = 0;
                break;
            default:
                select = 0;
                break;
        }

    }

    return 0;
}