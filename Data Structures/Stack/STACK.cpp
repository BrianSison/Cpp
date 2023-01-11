#include<iostream>

class STACK{
    private:
        int container[6], item, element, index=-1;
    public:
        void tempElements(){
            for(int x=0;x<6;x++){
                container[x]=0;
            }
        }
        void push(int x){
            item = x;
            index++;
            container[index]=x;
        }
        void display(){
            std::cout << std::endl;
            for(int x=0;x<6;x++){
                std::cout << container[x] << " ";
            }
        }
        int pop(){
            if(index==-1) return 0;
            element = container[index];
            container[index]=0;
            index--;
            return element;
        }
        int peek(int x){
            if(container[x]==0) return 0;
            return container[x-1];
        }
        int change(int x, int y){
            container[x-1]=y;
            return container[x-1];
        }
        void checker(){
            if(index==-1) std::cout << "\nArray is empty!";
            else if(index==5) std::cout << "\nArray is full!";
        }
};

int main(){
    STACK DS;

    int remove, element;

    DS.tempElements();
    DS.checker();         
    DS.display();     

    for(int x=0;x<6;x++){
        DS.push(x+1);
        DS.display();
    }

    DS.checker();
    remove = DS.pop();

    DS.display();
    element = DS.peek(1);

    DS.change(1, 2);
    DS.display();

    return 0;
}