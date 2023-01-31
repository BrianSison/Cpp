#include<iostream>

class Queue{
    private:
        int* queue = new int[size];
        int size, temp, pop, insert, front, back, element;
    public:
        void set(){
            for(int x=0;x<5;x++){
                queue[x]=0;
            }
            size=0;
        }
        int Size(){
            return size;
        }
        void inqueue(int x){
            if(size!=5){
                queue[size]=x;
                size++;
            }else{
                std::cout << "\nError, Queue is full...";
            }
        }
        void dequeue(){
            if(queue[0]!=0){
                front=queue[0];
                queue[0]=0;
                size--;
                shift();
            }
            else{
                shift();
            }
        }
        void pushBack(int x, int y){
            if(x<=5 && x!=0){
                if(queue[x-1]==0){
                    size++;
                    queue[x-1]=y;
                }else{
                    std::cout << " [Error, slot not available]";
                }
            }else{
                std::cout << " [Error, slot out of reach]";
            }
        }
        int Insert(){
            return insert;
        }
        void Swap(int x, int y){
            if((x!=0 && x<=5) && (y!=0 && y<=5)){
                temp=queue[x-1];
                if(queue[x-1]!=0 && queue[y-1]!=0){
                    queue[x-1]=queue[y-1];
                    queue[y-1]=temp;
                }
                else{
                    std::cout << " [Error, No element exist\n";
                }
            }
            else{
                std::cout << " [Error, invalid input]\n";
            }
        }
        void Change(int x, int y){
            if(x!=0 && x<=5){
                queue[x-1]=y;
            }else{
                std::cout << " [Error, element out of reach]\n";
            }
        }
        void remove(int x){
            if(x!=0 && x<=5){
                if(queue[x-1]!=0){
                    pop=queue[x-1];
                    queue[x-1]=0;
                    size--;
                    shift();
                }else{
                    std::cout << " [Error, no element value]";
                }
            }else std::cout << " [Error, element out of reach]";
        }
        int Pop(){
            return pop;
        }
        int Front(){
            return front;
        }
        int Back(){
            if(Size()!=0){
                return queue[Size()-1];
            }
            return queue[0];
        }
        void shift(){
            for(int x=0;x<5;x++){
                if(queue[x]==0 && queue[x+1]!=0){
                    if(x!=4){
                        element=queue[x+1];
                        queue[x]=queue[x+1];
                        queue[x+1]=0;
                    }
                    else{
                        queue[x]=0;
                    }
                }
            }
        }
        void status(){
            if(size==5) std::cout << " [Queue is full]";
            else if(size==0) std::cout << " [Queue is empty]";
            else std::cout << " [Queue size is " << size << "]\n";
        }
        void display(){
            for(int x=0;x<5;x++){
                /*if(queue[x]==0){
                    continue;
                }
                else{
                    std::cout << queue[x]<< " ";
                }*/
                std::cout << queue[x]<< " ";
            }
        }
        ~Queue(){
            delete[] queue;
        }
};

int main(){
    Queue DS;

    system("cls");

    std::cout << "\nGenerates empty Queue... ";
    DS.set();
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

    std::cout << DS.Size();
    std::cout << "\n\nDislay first and last element... [front: " << DS.Front() << " back: " << DS.Back() << "]";

    std::cout << "\n\nRemoves the specific element... Removing the (7) element...";
    DS.remove(7);
    std::cout << "\nRemoves the specific element... Removing the (5) element...";
    DS.remove(5);
    std::cout << "\nRemoves the specific element... Removing the (1) element...";
    DS.remove(1);
    std::cout << "\nRemoves the specific element... Removing the (2) element...";
    DS.remove(2);
    std::cout << " Display the pop element: " << DS.Pop() << std::endl;
    DS.display();
    std::cout << "\nChecks Queue size...";
    DS.status();

    /*std::cout << "\n\nDequeue";
    DS.dequeue();
    DS.status();
    DS.display();
    */
    std::cout << "\n\nSwaping the elements... ";
    std::cout << "\nSwapping 1 and 2 element... swap(1,2) ";
    DS.Swap(1,2);
    DS.display();
    std::cout << "\nSwapping 1 and 5 element... swap(1,5) ";
    DS.Swap(1,2);
    DS.display();
    std::cout << "\nSwapping 1 and 6 element... swap(1,6) ";
    DS.Swap(1,6);
    DS.display();

    std::cout << "\n\nChanging the element... change(1 to 8) ";
    DS.Change(1,8);
    DS.display();
    std::cout << "\nChanging the element... change(6 to 8) ";
    DS.Change(6,8);
    DS.display();

    std::cout << "\n\nInserting element... inserting(7 on index 4)... ";
    DS.pushBack(4,7);
    std::cout << "\nInserting element... inserting(5 on index 6)... ";
    DS.pushBack(6,5);
    std::cout << "\nInserting element... inserting(3 on index 2)...";
    DS.pushBack(2,3);
    DS.status();
    DS.display();

    std::cout << "\n\nClearing Queue...";
    DS.set();
    DS.status();

    return 0;
}