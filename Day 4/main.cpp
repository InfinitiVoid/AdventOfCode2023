#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

class Scrachcard{
    public:
        int onCard[10];
        int yourNumb[25];
        void count();
        int matches;
};

void Scrachcard::count(){
    for(int i = 0; i<25;i++){
            for(int j = 0; j < 10; j++){
                if(this -> yourNumb[i] == this -> onCard[j]){
                    this -> matches++;
                }
            }
        }
}

int yourPoints = 0;
int totalCards = 193;

Scrachcard cards[193];

void moreCards(int start, int amount){
    for(int i = 0; i < amount; i++){
        int k = start+i;
        if(cards[k].matches != 0){
            totalCards += cards[k].matches;
            moreCards(k+1, cards[k].matches);
        }
    }
}

int main(){
    string tmp;
    fstream plik;
    int h = 0;
    plik.open("input.txt", ios::in);
    while(!plik.eof()){
        int cardPoints = 0;
        plik >> tmp >> tmp;
        for(int i = 0; i < 10; i++){
            plik >> cards[h].onCard[i];
        }
        plik >> tmp;
        for(int i = 0; i < 25; i++){
            plik >> cards[h].yourNumb[i];
        }
        cards[h].count();
        if(cards[h].matches != 0){
            cardPoints = pow(2, cards[h].matches-1);
            yourPoints+=cardPoints; 
        }
        h++;
    }
    cout << yourPoints << endl;

    for(int i = 0; i < 193; i++){
        if(cards[i].matches != 0){
            totalCards += cards[i].matches;

            moreCards(i+1, cards[i].matches);
        }
    }

    cout << totalCards << endl;
    return 0;
}