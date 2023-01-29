#include<iostream>

class Queue{
    private:
        int frontElement, backElement, popElement, peekElement, tempElement, insertElement, queueElemet, size = 1;
        int* queue=new int[size];
    public:
        void clearQueue(){
            delete[] queue;
            size=1;
        }
        void queueSize(){
            if(size==1){
                std::cout << "\nQueue is empty...\n";
            }
            else{
                std::cout << "\nQueue size is " << size-1<< std::endl;
            }
        }
        void inqueue(int x){
            queue[size-1]=x;
            queue[size]=0;
            size++;
        }
        void dequeue(){
            frontElement=queue[0];
            size--;
            queue[0]=0;
            shift();
        }
        void shift(){
            int x=0;
            do{
                if(queue[x]==0){
                    tempElement=queue[x+1];
                    queue[x]=tempElement;
                    queue[x+1]=0;
                }
                x++;
            }while(x<size);
        }
        void display(){
            std::cout << "\nQueue: ";
            for(int x=0;x<size;x++){
                if(queue[x]==0) continue;
                else std::cout << queue[x] << " ";
            }
            std::cout << std::endl;
        }
        int frontQueue(){
            frontElement=queue[0];
            return frontElement;
        }
        int backQueue(){
            if(size!=1){
                backElement=queue[size-2];
            }
            else{
                backElement=queue[size-1];
            }
            return backElement;
        }
        void remove(int x){
            size--;
            popElement = queue[x-1];
            queue[x-1]=0;
            shift();
        }
        int popQueue(){
            return popElement;
        }
        void swap(int x, int y){
            if((x!=0 && x<size) && (y!=0 && y<size)){
                tempElement=queue[x-1];
                queue[x-1]=queue[y-1];
                queue[y-1]=tempElement;
            }
            else{
                std::cout << "Error, invalid input\n";
            }
        }
        void change(int x, int y){
            if((x!=0 && x<size) && y!=0){
                queue[x-1]=y;
            }
            else{
                std::cout << "Error, invalid input\n";
            }
        }
        void peekQueue(int x){
            if(x!=0 && x<size){
                peekElement = queue[x-1];
            }
            else{
                peekElement=0;
                std::cout << "Error, invalid input\n";
            }
        }
        int peek(){
            return peekElement;
        }
};  

int main(){
    Queue DS;

    std::cout << "\"Generating Queue\"\n";
    DS.clearQueue();
    DS.queueSize();

    std::cout << "\"Inqueue\"\n";
    for(int x=0;x<10;x++){
        DS.inqueue(x+1);
    }
    DS.display();
    DS.queueSize();
    std::cout << "front: " << DS.frontQueue() << " back: " << DS.backQueue() << std::endl;

    std::cout << "\n\"Dequeue\"";
    //1
    DS.dequeue();
    DS.display();
    std::cout << "front: " << DS.frontQueue() << " back: " << DS.backQueue();

    //2
    DS.dequeue();
    DS.display();
    std::cout << "front: " << DS.frontQueue() << " back: " << DS.backQueue();

    //3
    DS.dequeue();
    DS.display();
    std::cout << "front: " << DS.frontQueue() << " back: " << DS.backQueue();

    //4
    DS.dequeue();
    DS.display();
    std::cout << "front: " << DS.frontQueue() << " back: " << DS.backQueue();

    //5
    std::cout << "\n\n\"Remove\"";
    DS.remove(6);
    DS.display();
    std::cout << "front: " << DS.frontQueue() << " back: " << DS.backQueue() << std::endl;
    std::cout << "Pop: " << DS.popQueue() << std::endl;

    //6
    std::cout << "\n\n\"Swap\"";
    DS.swap(1,2);
    DS.display();
    DS.swap(1,10);
    DS.display();
    std::cout << "front: " << DS.frontQueue() << " back: " << DS.backQueue() << std::endl;

    //7
    std::cout << "\n\n\"Change\"";
    DS.change(5,110);
    DS.display();
    DS.change(6,100);
    DS.display();
    std::cout << "front: " << DS.frontQueue() << " back: " << DS.backQueue() << std::endl;

    //8
    std::cout << "\n\"Peek\"";
    DS.peekQueue(1);
    std::cout << "\nPeek: " << DS.peek() << std::endl;
    DS.peekQueue(100);
    std::cout << "Peek: " << DS.peek() << std::endl;

    DS.clearQueue();
}
