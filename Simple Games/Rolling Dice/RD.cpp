#include<iostream>
#include<cstdlib>
#include<ctime>

class RollingDice{
    private:
        int pScore=0, cScore=0, pNum=0, cNum=0, pRolls[6], cRolls[6];
        std::string gameWinner;
    public:
        void display(){
            system("cls");
            std::cout << ">>> [Roll the DICE] <<< \n";
            std::cout << "A game where the participant with most number of even numbers wins!\n";
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
            std::cout << "\nComputer Rolls: ";
            for(int x=0;x<6;x++){
                std::cout << cRolls[x] << " ";
            }
            std::cout << "\nPlayer Rolls: ";
            for(int x=0;x<6;x++){
                std::cout << pRolls[x] << " ";
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

            std::cout << "\n\nMatch Result: " << gameWinner;
            std::cout << "Computer even numbers: " << cNum << " Player even numbers: " << pNum;
            std::cout << "\nComputer Score: " << x << " Player Score: " << y;
            
            cNum = 0, pNum = 0;
        }
};

int main(){
    int cScore, pScore, win;
    char play;

    RollingDice RD;
    RD.display();

    do{
        if(cScore == 3 || pScore == 3) break;
        
        std::cout << "\nWould you like to continue? : Y/N : "; std::cin >> play;
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
