//Number Guessing Game

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;

class NumberGuessingGame{
    private:
        int attempts, pScore, cNumber, pInput;
        int randNum[10], pArray[10], tDisplay[10], pDisplay[10], cDisplay[10] = {0,0,0,0,0,0,0,0,0,0};   
    public:
        NumberGuessingGame(){
            pScore=0, attempts=3;
        }
        void gameIntro(){
            system("cls");
            cout << "\n--->>[Number Guessing Game]<<---\n\n[Game Rules]\n";
            cout << " >> Player will input the number of column presented on table he/she wants to guess.";
            cout << "\nThe same thing goes to the player guess input number(1-10).";
            cout << "\nFor every successful guess, the number of attempts and score will increase.";
            cout << "\nThe game will end if the player successfully guess three numbers or used all of the attempts.";
            cout << "\n >> Note: The correct guess numbers will be save at [Correct Guesses Table].\n";
        }
        void numGen(){
            srand(time(0));
            for(int x=0;x<10;x++){
                int randNumber = 1 + rand() % 10;
                randNum[x]= randNumber;
            }
        } 
        void displayTable(){
            cout << "\nTable : ";
            for(int x=0;x<10;x++){
                tDisplay[x] = x+1;
                cout << tDisplay[x] << " ";
            }
            cout << endl;
        } // testing purposes only
        void displayNum(){
            cout << "\nRandom Numbers: ";
            for(int x=0;x<10;x++){
                cout << randNum[x] << " ";
            }
        }
        void guessPicker(int x, int y){
            system("cls");
            cout << "\n--->>[Number Guessing Game]<<---\n";
            pArray[x-1] = y;
            if(pArray[x-1] == randNum[x-1]){
                if(pArray[x-1] != pDisplay[x-1]){
                    attempts++;
                    pScore++;
                    pDisplay[x-1] = pArray[x-1];
                    cDisplay[x-1] = pArray[x-1];
                    cout << "\nYou have guess the number correctly!\n\n >> Player Score: " << pScore << " Attempts : " << attempts;
                }
                else cout << "\nNumber already Guess!\n";
            }
            else{
                attempts--;
                cout << "\nIncorrect Guess! Try again!\n\n >> Player Score: " << pScore << " Attempts : " << attempts;
                if(y < randNum[x-1]) cout << "\nHint: You are close to the random number!\n";
                else cout << "\nHint: You are far from the random number!\n";    
            }
        }
        void displayGuess(){
            cout << "\nCorrect Guess Table: ";
            for(int x=0;x<10;x++){
                cout << cDisplay[x] << " ";
            }
            cout << endl;
        }
        bool gameEnder(){
            if(attempts == 0 || pScore == 3) return true;
            return false;
        }
};
int main(){
    bool gameEnds;    
    int pPicks, cNumber;
    NumberGuessingGame NGG;

    NGG.gameIntro();
    NGG.numGen();
    do{
        if(gameEnds == true )break;
        NGG.displayTable();
        NGG.displayNum();

        cout << "\nPut the number of column: "; cin >> cNumber;
        cout << "\nPut the number you guess: "; cin >> pPicks;

        NGG.guessPicker(cNumber, pPicks);
        NGG.displayGuess();

        gameEnds = NGG.gameEnder();
    }while(gameEnds!= true);
    return 0;
}