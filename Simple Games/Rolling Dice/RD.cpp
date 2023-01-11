//Rolling Dice
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class RollingDice{
    private:
        int pScore=0, cScore=0, pNum=0, cNum=0, pRolls[6], cRolls[6];
        std::string gameWinner;
    public:
        void display(){
            system("cls");
            cout << ">>> [Roll the DICE] <<< \n";
            cout << "A game where the participant with most number of even numbers wins!\n";
        }
        void Rolls(){
            srand(time(0));
            for(int a=0;a<6;a++){
                cRolls[a] = 2 + rand() % 11;
            }
            for(int a=0;a<6;a++){
                pRolls[a] = 2 + rand() % 11;
            }
        }
        void checker(){
            for(int x=0;x<6;x++){
                if(pRolls[x]%2 == 0){
                    pNum++;
                }
            }
            for(int x=0;x<6;x++){
                if(cRolls[x]%2 == 0){
                    cNum++;
                }
            }
        }
        void displayRolls(){
            system("cls");
            cout << "\nComputer Rolls: ";
            for(int x=0;x<6;x++){
                cout << cRolls[x] << " ";
            }
            cout << "\nPlayer Rolls: ";
            for(int x=0;x<6;x++){
                cout << pRolls[x] << " ";
            }
        }
        int winner(){
            if(cNum>pNum) return 1;
            else if(pNum>cNum) return 2;
            return 3;
        }
        int computerScore(int x){
            if(x==1) cScore++;
            return cScore;
        }
        int playerScore(int x){
            if(x==2) pScore++;
            return pScore;
        }
        void displayOutcome(int x, int y, int z){
            if(z == 1) gameWinner = "Computer Wins!\n";
            else if(z == 2) gameWinner = "Player Wins!\n";
            else gameWinner = "No Winner!\n";

            cout << "\n\nMatch Result: " << gameWinner;
            cout << "Computer even numbers: " << cNum << " Player even numbers: " << pNum;
            cout << "\nComputer Score: " << x << " Player Score: " << y;
            
            cNum = 0, pNum = 0;
        }
};

int main(){
    RollingDice RD;
    int cScore, pScore, win;
    char play;

    RD.display();
    do{
        if(cScore == 3 || pScore == 3) break;
        
        cout << "\nWould you like to continue? : Y/N : "; cin >> play;
        if(play!='Y') break;
        else{
            RD.Rolls();
            RD.checker();
            RD.displayRolls();
            win = RD.winner();
            pScore = RD.playerScore(win);
            cScore = RD.computerScore(win);
            RD.displayOutcome(cScore, pScore, win);
        }
    }while(cScore!=3 || pScore!=3);

    return 0;
}
