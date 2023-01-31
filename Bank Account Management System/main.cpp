#include<iostream>
#include<string>
#include<vector>

#include"logIn.h"
#include"login.cpp"

class registrationForm{
    private:
        std::string username;
        std::string pin_code;
        int balance;
    public:
        void get_detailes(){
            std::cout << "Username: "; getline(std::cin, username);
            std::cout << "Pin code: "; std::cin >> pin_code;
            std::cout << "Balance: "; std::cin >> balance;
        }
        std::string set_username(){
            return username;
        }
        std::string set_pincode(){
            return pin_code;
        }
        int set_balance(){
            return balance;
        }
};

int main(){
    logIn LG;
    registrationForm RF;

    RF.get_detailes();
 
    std::string username = RF.set_username();
    std::string pincode = RF.set_pincode();
    int balance = RF.set_balance();

    LG.registration(username, pincode, balance);
    LG.displayProfile();
}