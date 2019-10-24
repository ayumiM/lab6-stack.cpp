#include <iostream>
#include "stack.h"

using namespace std;

template <class T>
class Stack{
private:
    int size;
    T** stackArray;
    int Top;

public:
    template <typename X>
    friend void Display(Stack<X>);
    class Full{};
    class Empty{};

    //constructor
    Stack(int num){
        size = num;
        Top = -1;
        //stackArray = new T*[size];
        stackArray = new T*[num];
    }

    //destructor
    ~Stack(){
        delete [] stackArray;
    }

    //push function
    void push(T* num){
        if(length() == size){
            throw Full();
        }

        else {
            Top++;
            stackArray[Top]= num;
        }
    }

    //pop function
    T* pop(){
        T* temp = NULL;
        if(length() == 0){
            throw Empty();
        }
        else{
            temp = stackArray[Top];
            //*stackArray[Top] = 0;
            Top--;

        }
        return temp;

    }

    //top function
    T* top(){
        return stackArray[Top];
    }

    //length function
    int length(){
        return Top + 1;
    }


    bool isFull(){
        bool full;
        if(Top ==size-1){
            return true;
        }
        else {
            return false;
        }
    }
    bool isEmpty(){
        if(Top == -1){
            return true;
        }
        else{
           return false;
        }
    }

    void empty(){
        delete stackArray;
        size = 0;
        Top = -1;
    }

};

template <typename X>
void Display(Stack<X> s){
    for (int i = 0; i<=s.Top; i++) {
        cout<<*s.stackArray[i]<<" ";

    }
    cout<<endl;

}

int main()
{
    int size;

    int pole1, pole2;
    bool win = false;

    //hold number for pop function
    int* NumPop;

    std::cout << "Pick a disk size: ";
    std::cin >> size;

    //create 3 stacks
//    Stack<int> S1 = Stack<int>(size);
//    Stack<int> S2 = Stack<int>(size);
//    Stack<int> S3 = Stack<int>(size);

    Stack<int> S1(size);
    Stack<int> S2(size);
    Stack<int> S3(size);

    //stack class array
    Stack<int> Game[3] = {S1, S2, S3};


    int *num = new int [size];
    for(int i = size; i>0; i--){
        num[i]= i;
        Game[0].push(&num[i]);
       //cout<<num[i]<<endl;

    }

//    for(int i = size; i>0; i--){
//        num[i]= i;
//        S1.push(&num[i]);
//       //cout<<num[i]<<endl;

//    }


//    int *t = Game[0].top();
//    cout<<*t<<endl;

    //for loop to display stacks
    for(int i = 0; i<size; i++){
        cout<<"Pole "<<i+1<<": ";
        Display(Game[i]);
        cout<<endl;
    }




//    Game[0].pop();

//    cout<<"Pole 1: ";
//    Display<int>(S1);
//    cout<<"Pole 2: ";
//    Display<int>(S2);
//    cout<<"Pole 3: ";
//    Display<int>(S3);

    //Stack<int> *S;


    while(!win){
        cout<<"Pick the source pole: ";
        cin>>pole1;


        //NumPop = Game[pole1-1].top();
        //cout<<&NumPop<<endl;

        try {
            NumPop = Game[pole1-1].pop();
            for(int i = 0; i<size; i++){
                cout<<"Pole "<<i+1<<": ";
                Display(Game[i]);
                cout<<endl;
            }

        } catch (Stack<int>::Empty) {
            cout<<endl;
            cout<<"Error. The pole is empty."<<endl;
            cout<<endl;
        }


        cout<<"Pick the destination pole: ";
        cin>>pole2;
        try {
            if(Game[pole2-1].isEmpty()){
                Game[pole2-1].push(NumPop);
            }
            else if(Game[pole1-1].top()<Game[pole2-2].top()){
                Game[pole2-1].push(NumPop);
                if(Game[2].length()==size){
                    win = true;
                    break;
                }
            }
            else {
                cout<<"Illegal Move"<<endl;
                continue;
            }
        } catch (Stack<int>::Full) {
            cout<<endl;
            cout<<"The pole is full"<<endl;
        }

        for(int i = 0; i<size; i++){
            cout<<"Pole "<<i+1<<": ";
            Display(Game[i]);
            cout<<endl;
        }

    }






    return 0;
}
