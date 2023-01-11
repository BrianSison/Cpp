#include<iostream>

void InputChecker(){
    std::cout << "\nInvalid input\n";
    std::cin.clear();
    std::cin.ignore();
}
int main(){
    double firstNum, secondNum, answer=0;
    char newOperator, Operator='1';

    do{
        std::cout << "\nDecimal calculator... \nInput 0 to exit";
        std::cout << "\nPut your first number: "; std::cin >> firstNum;
        if(std::cin.fail()){
            InputChecker();
        }
        else{
            std::cout << "Put your second number: "; std::cin >> secondNum;
            if(std::cin.fail()){
                InputChecker();
            }
            else{
                std::cout << "Operators: \n+\n-\n*\n/\nSelect your operator: "; std::cin >> newOperator;
                if(std::cin.fail()){
                    InputChecker();
                }
                else{
                    system("cls");
                    switch(newOperator){
                        case '0':
                            std::cout << "exit...";
                            Operator=0;
                            break;
                        case '+':
                            answer = firstNum+secondNum;
                            std::cout << "Answer: " << answer;
                            break;
                        case '-':
                            answer = firstNum-secondNum;
                            std::cout << "Answer: " << answer;
                            break;
                        case '*':
                            answer = firstNum*secondNum;
                            std::cout << "Answer: " << answer;
                            break;
                        case '/':
                            answer = firstNum/secondNum;
                            std::cout << "Answer: " << answer;
                            break;
                        default:
                            std::cout << "\nInvalid input";
                    }
                }
            }
        }
    }while(Operator!=0);
    return 0;
}