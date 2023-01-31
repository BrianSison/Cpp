#ifndef LOGIN_H
#define LOGIN_H

#pragma once

class logIn
{
public:
    logIn();
    void registration(std::string& x, std::string& y, int& z);
    void displayProfile();
    ~logIn();
    
private:
    int size=1;
    std::vector<std::string>user_names;
    std::vector<std::string>pin_code;
    std::vector<int>remaining_balance;
    std::vector<int>user_ID;
};

#endif