#include<iostream>

int main(){
    double weight, height, BMI;

    std::cout << "Put your weight in Kg: "; std::cin >> weight;
    std::cout << "Put your height in m: "; std::cin >> height;

    BMI = weight/(height*2);

    if(BMI<18.5) std::cout << BMI << " Underweight...";
    else if(BMI>=18.5 && BMI<=24.9) std::cout << BMI << " Normal...";
    else if(BMI>=25 && BMI <=29.9) std::cout << BMI << " Overweight...";
    else std::cout << BMI << " Obesity...";
   
    return 0;
}
