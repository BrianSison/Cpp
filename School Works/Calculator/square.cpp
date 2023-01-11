#include<iostream>

int main(){
    
    int length, width, area;

    std::cout << "Calculate the area of square\n";
    std::cout << "Input your length: "; std::cin >> length;
    std::cout << "Input your width: "; std::cin >> width;

    area=length*width;

    std::cout << "Area is " << area;
    return 0;
}