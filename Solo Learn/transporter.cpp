/*
!Problem
!Difficulty: Easy

You are making a program for a bus service. 
A bus can transport 50 passengers at once. 
Given the number of passengers waiting in the bus station as input,
you need to calculate and output how many empty seats the last bus will have.

Sample Input:
126

Sample Output: 
24

Explanation: The first bus will transport 50 passengers, leaving 126-50=76 in the station.
The next one will leave 26 in the station, thus, the last bus will take all of the 26 passengers,
having 50-26=24 seats left empty.
*/
#include<iostream>

int main(){
    int passengers, seats=50, remains;
    std::cin>>passengers;
    remains=passengers%seats;
    std::cout<<seats-remains;
    return 0;
}

/*
!Explanation
The bus has default value(number of seats) 50;
The % ,takes remainder(51.5%50, r=1.5) in decimal form
by subtracting the remainder on number of seats the remaining number of seats will be displayed
bus-remainder(50-1) = 49 
*/