#include "logIn.h"
#include<vector>

logIn::logIn(){
} 

void logIn::registration(std::string& x, std::string& y, int& z){
    user_names.push_back(x);
    pin_code.push_back(y);
    remaining_balance.push_back(z);
}

void logIn::displayProfile(){
    std::cout << "\nUser Profile\n";
    std::cout << "\nUsername: " << user_names[0];
    std::cout << "\nPin code: " << pin_code[0];
    std::cout << "\nBalance: " << remaining_balance[0];
}
logIn::~logIn(){

}