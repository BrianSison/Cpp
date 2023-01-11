#include<iostream>

int main(){
    int sum=0, average;
    int grades[3][6]={
        {86,87,85,92,96,91},
        {87,88,91,90,81,85},
        {98,91,95,92,93,97},
    };

    for(int x=0;x<3;x++){
        for(int i=0;i<6;i++){
            std::cout << grades[x][i] << " ";
            sum+=grades[x][i];
        }
        average=sum/6;
        std::cout << "\nAverage: " << average;
        sum=0;
        std::cout << std::endl;
    }

    return 0;
}