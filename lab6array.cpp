template <class T>
class Stack{
private:
    int size;
    T** stackArray;
    int Top;

public:
    template <typename X>
    friend void Display(Stack<X>);
//    int size;
//    T** stackArray;
//    int Top;

    Stack(int num){
        size = num;
        Top = -1;
        stackArray = new T* [size];
    }
    ~Stack(){
        delete stackArray;
    }

    void push(T* num){
        if(length() == size){
            throw "Full";
        }

        else {
            Top++;
            stackArray[Top]= num;
        }
    }

    T* pop(T* N){
        T* temp;
        if(length() == 0){
            throw "Empty";
        }
        else{
            temp = stackArray[Top];
            stackArray[Top] = 0;
            Top--;

        }
        return temp;


    }

    T* top(){
        return stackArray[Top];
    }

    int length(){
        return Top + 1;
    }

    bool isFull(){
        bool full;
        if(length()==size){
            full = true;
        }
        else {
            return false;
        }
    }
    bool isEmpty(){
        bool empty;
        if(length() == 0){
            empty = true;
        }
    }


};
