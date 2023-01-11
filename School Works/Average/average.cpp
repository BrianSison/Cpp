#include<iostream>

int main(){
    double grades[6]={0},average,temp, grade;
    int i=0;

    while(i<6){
        std::cout << "\nInput the student grade: "; std::cin >> grade;
        grades[i]=grade;

        std::cout << " >> Input grade is : " << grades[i];
        temp+=grade;
        i++;
    }
    average=temp/6;
    std::cout << "\nAverage is " << average;
    return 0;
}