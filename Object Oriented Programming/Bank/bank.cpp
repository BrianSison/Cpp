#include<iostream>

class BANK{
    private:
        std::string name;
        int balance, age;
    public:
        BANK(){
            getName(name);
            getAge(age);
            getAccount(balance);
        }
        void getName(std::string x){
            name=x;
        }
        std::string displayName(){
            return name;
        }
        void getAge(int x){
            age=x;
        }
        int displayAge(){
            return age;
        }
        void getAccount(int x){
            balance=x;
        }
        int displayAccount(){
            return balance;
        }
        void displayInformation(){
            std::cout << "\nName: " << displayName();
            std::cout << "\nAge: " << displayAge();
            std::cout << "\nBalance: " << displayAccount() << std::endl; 
        }

};
int main(){
    BANK user;

    std::string names[3]={"John Ambrose", "Dean Cena", "AJ Owens"};
    
    int balance[3]={1023, 423269, 12923};
    int age[3]={21, 22, 32};

    for(int x=0;x<3;x++){
        user.getName(names[x]);
        user.getAge(age[x]);
        user.getAccount(balance[x]);
        user.displayInformation();
    }

    return 0;
}