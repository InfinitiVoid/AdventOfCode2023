#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

string numb[10] = {"one","two","three","four","five","six","seven","eight","nine"};

int main(){
    string line;
    int totalValue = 0;
    fstream plik;
    plik.open("input.txt", ios::in);
    int h = 0;
    while(!plik.eof()){
        int first = -192, last = -132;
        plik >> line;
        for(int i = 0; i < line.length(); i++){
            int v = line[i]-48;
            if(v >= 0 && v <= 9){
                if(first == -192){
                    first = v;
                } else if(last == -132){
                    last = v;
                } else{
                    last = v;
                }
            } else{
                for(int k = 0; k < 9; k++){
                    if(numb[k][0] == line[i]){
                        int aaa = numb[k].length();
                        int b = numb[k].length();
                        for(int j = 0; j < b; j++){
                            if(numb[k][j] == line[i+j]){
                                aaa--;
                            }
                        }
                        
                        if(aaa == 0){
                            if(first == -192){
                                first = k+1;
                            } else if(last == -132){
                                last = k+1;
                            } else{
                                last = k+1;
                            }
                            break;
                        }
                    }
                }
            }
        }
        if(last == -132){
            totalValue += first*10 + first;
        } else {
            totalValue += first*10 + last;
        }
        h++;
    }
    plik.close();
    cout << totalValue << endl;
    return 0;
}