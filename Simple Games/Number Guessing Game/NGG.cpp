#include<iostream>
#include<cstdlib>
#include<ctime>

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
            std::cout << "\n--->>[Number Guessing Game]<<---\n\n[Game Rules]\n";
            std::cout << " >> Player will input the number of column presented on table he/she wants to guess.";
            std::cout << "\nThe same thing goes to the player guess input number(1-10).";
            std::cout << "\nFor every successful guess, the number of attempts and score will increase.";
            std::cout << "\nThe game will end if the player successfully guess three numbers or used all of the attempts.";
            std::cout << "\n >> Note: The correct guess numbers will be save at [Correct Guesses Table].\n";
        }
        void numGen(){
            srand(time(0));
            for(int x=0;x<10;x++){
                int randNumber = 1 + rand() % 10;
                randNum[x]= randNumber;
            }
        } 
        void displayTable(){
            std::cout << "\nTable : ";
            for(int x=0;x<10;x++){
                tDisplay[x] = x+1;
                std::cout << tDisplay[x] << " ";
            }
            std::cout << std::endl;
        } // testing purposes only
        void displayNum(){
            std::cout << "\nRandom Numbers: ";
            for(int x=0;x<10;x++){
                std::cout << randNum[x] << " ";
            }
        }
        void guessPicker(int x, int y){
            system("cls");
            std::cout << "\n--->>[Number Guessing Game]<<---\n";
            pArray[x-1] = y;
            if(pArray[x-1] == randNum[x-1]){
                if(pArray[x-1] != pDisplay[x-1]){
                    attempts++;
                    pScore++;
                    pDisplay[x-1] = pArray[x-1];
                    cDisplay[x-1] = pArray[x-1];
                    std::cout << "\nYou have guess the number correctly!\n\n >> Player Score: " << pScore << " Attempts : " << attempts;
                }
                else std::cout << "\nNumber already Guess!\n";
            }
            else{
                attempts--;
                std::cout << "\nIncorrect Guess! Try again!\n\n >> Player Score: " << pScore << " Attempts : " << attempts;
                if(y < randNum[x-1]) std::cout << "\nHint: You are close to the random number!\n";
                else std::cout << "\nHint: You are far from the random number!\n";    
            }
        }
        void displayGuess(){
            std::cout << "\nCorrect Guess Table: ";
            for(int x=0;x<10;x++){
                std::cout << cDisplay[x] << " ";
            }
            std::cout << std::endl;
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

        std::cout << "\nPut the number of column: "; std::cin >> cNumber;
        std::cout << "\nPut the number you guess: "; std::cin >> pPicks;

        NGG.guessPicker(cNumber, pPicks);
        NGG.displayGuess();

        gameEnds = NGG.gameEnder();

    }while(gameEnds!= true);

    return 0;
}