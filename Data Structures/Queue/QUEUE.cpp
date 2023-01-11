#include<iostream>

class QUEUE{
    private:
        int queue[5], index=-1, temp_element, queue_element, front_element, pop_element, insert_element, customer;
    public:
        void clear(){
            for(int x=0;x<5;x++){
                queue[x]=0;
            }
            index=-1;
        }
        int size(){
            return index;
        }
        void inqueue(int x){
            if(size()!=4){
                index++;
                queue[index]=x;
            }else{
                std::cout << "\nError, Queue is full...";
            }
        }
        void push(int x, int y){
            if(x<=5){
                if(queue[x-1]==0){
                    queue[x-1]=y;
                }else{
                    std::cout << " [Error, slot not available]";
                }
            }else{
                std::cout << " [Error, slot out of reach]";
            }
        }
        int insert(){
            return insert_element;
        }
        void dequeue(){
            front_element=queue[0];
            queue[0]=0;
            index--;
            shift();
        }
        void status(){
            if(size()==4) std::cout << " [Queue is full]";
            else if(size()==-1) std::cout << " [Queue is empty]";
            else std::cout << " [Queue size is " << size()+1 << "]";
        }
        void swap(int x, int y){
            if((x!=0 && x<=4) && (y!=0 && y<=4)){
                temp_element=queue[x-1];
                queue[x-1]=queue[y-1];
                queue[y-1]=temp_element;
            }else{
                std::cout << " [Error, invalid input]\n";
            }
        }
        void change(int x, int y){
            if(x!=0 && x<=5){
                queue[x-1]=y;
            }else{
                std::cout << " [Error, element out of reach]\n";
            }
        }
        void remove(int x){
            if(x>0 && x<=5){
                if(queue[x-1]!=0){
                    pop_element=queue[x-1];
                    queue[x-1]=0;
                    index--;
                }else{
                    std::cout << " [Error, no element value]";
                }
            }else std::cout << " [Error, element out of reach]";
        }
        void shift(){
            for(int x=0;x<5;x++){
                if(queue[x]==0 && queue[x+1]!=0){
                    if(x!=4){
                        queue_element=queue[x+1];
                        queue[x]=queue[x+1];
                        queue[x+1]=0;
                    }
                    else{
                        queue[x]=0;
                    }
                }
            }
        }
        void display(){
            std::cout << "Queue: ";
            for(int x=0;x<5;x++){
                std::cout << queue[x];
            }
        }
        int pop(){
            return pop_element;
        }
        int front(){
            return front_element;
        }
        int back(){
            return queue[size()];
        }
};

int main(){
    QUEUE DS;

    system("cls");

    std::cout << "\nGenerates empty Queue... ";
    DS.clear();
    DS.display();
    
    std::cout << "\nChecks Queue size... ";
    DS.status();
    
    std::cout << "\n\nAdding elements... ";
    for(int x=0;x<5;x++){
        DS.inqueue(x+1);
    }
    DS.display();
    
    std::cout << "\nChecks Queue size... ";
    DS.status();
    
    std::cout << "\n\nOverloading the Queue by adding new element (7)... ";
    DS.inqueue(7);
    
    std::cout << "\n\nRemoving the first element... ";
    DS.dequeue();
    DS.display();

    std::cout << "\nChecks Queue size...";
    DS.status();

    std::cout << "\n\nDislay first and last element... [front: " << DS.front() << " back: " << DS.back() << "]";

    std::cout << "\n\nRemoves the specific element... Removing the (7) element...";
    DS.remove(7);

    std::cout << "\nRemoves the specific element... Removing the (5) element...";
    DS.remove(5);
    
    std::cout << "\nRemoves the specific element... Removing the (1) element...";
    DS.remove(1);
    
    std::cout << " Display the pop element: " << DS.pop() << std::endl;
    DS.display();
    
    std::cout << "\nChecks Queue size...";
    DS.status();

    std::cout << "\n\nSwaping the elements... ";
    std::cout << "\nSwapping 1 and 2 element... swap(1,2) ";
    DS.swap(1,2);
    DS.display();
    
    std::cout << "\nSwapping 1 and 6 element... swap(1,6) ";
    DS.swap(1,6);
    DS.display();

    std::cout << "\n\nChanging the element... change(1 to 8) ";
    DS.change(1,8);
    DS.display();
    
    std::cout << "\nChanging the element... change(6 to 8) ";
    DS.change(6,8);
    DS.display();

    std::cout << "\n\nInserting element... inserting(7 on index 4)... ";
    DS.push(4,7);
    
    std::cout << "\nInserting element... inserting(5 on index 6)... ";
    DS.push(6,5);
    
    std::cout << "\nInserting element... inserting(3 on index 2)... ";
    DS.push(2,3);
    DS.display();

    return 0;
}