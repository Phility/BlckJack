#include "BlackJack.h"

BlackJack::BlackJack(){}

int BlackJack::getPoints(Card c){
    int points[13] = {1,2,3,4,5,6,7,8,9,10,10,10,10};
    return points[c.getValor()-1];
}

int BlackJack::getScore(list<Card> l){
    int score = 0;
    while(!(l.empty())){
        score += getPoints(l.front());
        l.pop_front();
    }
    return score;
}

char BlackJack::getCommand(){
    char c;
    do{
        cout << "Entre d para Draw ou s para Stand: ";
        cin >> c;
    }while(c != 'd' && c != 's');
    return c;
}

list<Card> BlackJack::humanPlayer(Deck d){
    Deck player(true);
    char auxiliar;
    do{
        auxiliar = getCommand();
            if(auxiliar == 'd'){
                player.cl.push_back(d.draw());
                cout << player.toString() << endl;
                cout << getScore(player.cl) << endl;
            }

            if(getScore(player.cl) > 21){
                cout << "You lost, your score is above 21" << endl;
            }
            if(auxiliar == 's'){
                computerPlayer(d, getScore(player.cl));
            }
    }while(auxiliar != 's' && getScore(player.cl) < 21);
    return player.cl;
}

list<Card> BlackJack::computerPlayer(Deck d, int humanScore){
    Deck computer(true);
    do{
        computer.cl.push_back(d.draw());
    }while(getScore(computer.cl) < 21 && getScore(computer.cl) < humanScore);
    cout << computer.toString() << endl;
    cout << getScore(computer.cl) << endl;
    return computer.cl;
}

void BlackJack::game(){
    cout << "*********** BLACK JACK - 21 ***********" << endl;
    cout << endl;
    cout << " PRESSIONE ENTER PARA O JOGO COME�AR ";
    system("PAUSE>>null");

}
