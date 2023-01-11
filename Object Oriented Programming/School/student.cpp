#include<iostream>

class STUDENT{
    private:
        int average, age;
        std::string name;
    public:
        STUDENT(){
            getInformation(name, age, average);
        } 
        void getInformation(std::string x, int a, int b){
            name=x;
            average=b;
            age=a;
        }
        std::string displayName(){
            return name;
        }
        int displayAge(){
            return age;
        }
        int displayGrades(){
            return average;
        }
        std::string achievement(){
            if(average>=90) return "With Honor";
            else if(average>=95) return "With High honor";
            else if(average>=98) return "With Highest honor";
            else return "No awards";
        }
        void displayInformation(){
            std::cout << "\n\nName: " << displayName();
            std::cout << "\nAge: " << displayAge();
            std::cout << "\nGeneral Average: " << displayGrades();
            std::cout << "\nAwards: " << achievement();
        }
};

int main(){
    STUDENT IT;

    std::string names[3]={"John Ambrose", "Randy Styles", "Aj Orton"};

    int grades[3][6]={ {86,87,85,92,96,91}, {87,88,91,90,81,85}, {98,91,95,92,93,97}, };
    int age[3]={12,13,16};
    int sum=0, average;

    for(int x=0;x<3;x++){
        for(int i=0;i<6;i++){
            sum+=grades[x][i];
        }
        average=sum/6;
        IT.getInformation(names[x],age[x],average);
        IT.displayInformation();
        sum=0;
    }
    return 0;
}