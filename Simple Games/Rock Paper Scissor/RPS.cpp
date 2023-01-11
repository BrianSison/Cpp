//Simple Rock Paper Scissors Game

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

class rockpaperscissors{

    private:
        char difficulty;

        int randNum, cPick, pPick, cScore, pScore;

        int rock[10]={2,2,2,2,2,3,1,2,1,2,};
        int paper[10]={3,2,3,3,3,3,2,2,1,3};
        int scissor[10]={1,1,3,1,1,1,1,1,2,1};

        string displayDiff;

    public:
        rockpaperscissors(){
            cScore = 0, pScore = 0;
        }
        void input_diff(char x){
            difficulty = x;
        }
        void input_pPick(int x){
            pPick = x;
        }
        int return_cPick(char diff){
            srand(time(0));
            if(diff == 'E' || diff == 'e'){
                displayDiff = "Easy]\n";
                cPick = 1 + rand() % 3;
            }
            else{
                displayDiff = "Hard]\n";
                randNum = rand() % 10;
                if(pPick == 1) cPick=rock[randNum];
                else if(pPick == 2) cPick = paper[randNum];
                else cPick = scissor[randNum];
            }
            return cPick;
        }
        int checker(){
            if(pPick == 1 && cPick == 2) return 1;
            else if(pPick == 1 && cPick == 3) return 2;
            else if(pPick == 2 && cPick == 1) return 2;
            else if(pPick == 2 && cPick == 3) return 1;
            else if(pPick == 3 && cPick == 1) return 1;
            else if(pPick == 3 && cPick == 2) return 2;
            return 3;
        }
        int cScore_func(int x){
            if(x == 1) cScore++;
            return cScore;
        }
        int pScore_func(int x){
            if(x == 2) pScore++;
            return pScore;
        }
        void results(){
            cout << "\n [Difficulty: " << displayDiff;
            cout << "\nComputer Picks: " << cPick << " Player Picks: " << pPick;
            cout << "\nComputer Score: " << cScore << " Player Score: " << pScore << endl;
        }
        void display(int x){
            system("cls");
            if(x == 1){
                cout << "\n [Match Result: Computer wins]\n";
                results();
            }
            else if(x == 2){
                cout << "\n [Match Result: Player wins]\n";
                results();
            }
            else{
                cout << "\n [Match Result: Draw]\n";
                results();
            }
        }
};

int main(){

    rockpaperscissors gameBegins;

    char diff, newDiff;

    int pScore, cScore, pPick, winner;

    system("cls");
    cout << "Choose your difficulty\n >> E for Easy\n >> H for Hard\n Your Pick: "; cin >> diff;
 
    if(diff == 'E' || diff == 'e' || diff == 'H' || diff == 'h'){
        do{
            if(pScore == 3 || cScore == 3) break;
            cout << "\n[Options]\n >> 1 Rock\n >> 2 Paper\n >> 3 Scissors\n >>Your Pick: "; cin >> pPick;
        
            gameBegins.input_pPick(pPick);
            gameBegins.return_cPick(diff);

            winner = gameBegins.checker();
            cScore = gameBegins.cScore_func(winner);
            pScore = gameBegins.pScore_func(winner);
        
            gameBegins.display(winner);
        
        }while(pScore!=3 || cScore!= 3);
    }
    else{
        cout << "\nInvalid difficulty!";
    }
    return 0;
}