#include <iostream>
#include <iomanip>



template<class T>
struct DT{
    T data;
    DT<T>* next;

};

template<class T>
class Stack {

private:
    //* stackArray;
    int stackSize;
    DT<T>* Top;

public:
    //constructor
    Stack(int);

    //destructor
    ~Stack();

    void push(DT<T>*);
    DT<T>* pop();
    DT<T>* top();
    int length();
    void Empty();
    T index(int);

    //exception class
    class isEmpty{};
    class isFull{};
   // class IllegalMove{};

    //friend function
 //   friend void Display(Stack<T> S1, Stack<T> S2, Stack<T> S3, int size1, int size2, int size3);
//        std::cout<<std::setw(2)<<std::endl;
//        std::cout<<"Pole 1  Pole2  Pole 3"<<std::endl;
//        for (int i = 0;i<size1;i++) {
//            if(S1.Top != NULL){
//                std::cout<<S1.index(i)<<" ";
//            }
//            else{
//                std::cout<<"|";
//        }
//        }
//        for(int i = 0; i<size2; i++){

//            if(S2.Top != NULL){
//                    std::cout<<S2.index(i)<<" ";
//                }
//            else{
//                std::cout<<" |";
//            }
//        }
//        for(int i = 0; i<size3; i++){
//                    if(S3.Top != NULL){
//                        std::cout<<S3.index(i)<<" ";
//                    }
//                else{
//                    std::cout<<"|"<<std::endl;

//                }
//        }
//                    std::cout<<"-----------------------------------";


//}
};

void Display(Stack<int> S1, Stack<int> S2, Stack<int> S3, int size1, int size2, int size3);

template<class T>
Stack<T>::Stack(int size) {

    stackSize = size;
    Top = NULL;
}

template<class T>
Stack<T>::~Stack() {

}

template<class T>
void Stack<T>::push(DT<T>* num) {
    if (Top == NULL) {
        Top = num;
    }
    else if(this->length() >= this->stackSize){
        throw isFull();
    }
    else{
    DT<T>* temp;
    temp = Top;
    Top = num;
    Top->next = temp;
    }
}

template<class T>
DT<T>* Stack<T>::pop() {
    if (Top == NULL) {
        throw isEmpty();
    }
    else {
        DT<T>* temp;
        temp = Top;
        Top = temp->next;


        return temp;
    }
}

template<class T>
DT<T>* Stack<T>::top() {
    return Top;
}

template<class T>
int Stack<T>::length() {
    int num = 1;
    DT<T>* current;
    current = Top;
    if(Top == NULL){
        return 0;
    }
    else {
        while(current->next != NULL){
            current = current->next;
            num++;
        }

    return num;
    }
}

template <class T>
T Stack<T>::index(int pos){
    DT<T>* temp;
    temp = Top;
    for(int i = 0; i<pos; i++){
        temp = temp->next;
    }
    return temp->data;
}

template<class T>
void Stack<T>::Empty() {
    if(Top == NULL){
        throw isEmpty();
    }
    else{
        while(Top!=NULL){
            pop();
            Top--;
        }
    }

}

void Display(Stack<int> S1, Stack<int> S2, Stack<int> S3, int size1, int size2, int size3){

        DT<int> *P1;
        DT<int> *P2;
        DT<int> *P3;
        P1 = S1.top();
        P2 = S2.top();
        P3 = S3.top();
        std::cout<<"-------------------------------------"<<std::endl;
        std::cout<<"Pole1: ";
        if(S1.top() == NULL){
            std::cout<<" "<<std::endl;
        }
        else{
            while(P1 != NULL) {

                    std::cout<<P1->data<<" ";
                    P1 = P1->next;
            }
        }
        std::cout<<std::endl;

        std::cout<<"Pole2: ";
        if(S2.top() == NULL){
             std::cout<<" "<<std::endl;
        }
        else{
        while(P2 != NULL){
                std::cout<<P2->data<<" ";
                P2 = P2->next;
            }
        }
        std::cout<<std::endl;

        std::cout<<"Pole3: ";
        if(S3.top() == NULL){
             std::cout<<" "<<std::endl;
        }
        else{
        while(P3 != NULL){
                std::cout<<P3->data<<" ";
                P3 = P3->next;
            }
        }

        std::cout<<std::endl;


         std::cout<<"-------------------------------------"<<std::endl;

}

//void PrintStack(Stack<int> S1, Stack<int> S2, Stack<int> S3, int size);





int main() {
    int nosize;
    //int pop;

    std::cout << "Pick a disk size: ";
    std::cin >> nosize;

    Stack <int> S1 = Stack <int>(nosize);
    Stack <int> S2 = Stack <int>(nosize);
    Stack <int> S3 = Stack <int>(nosize);

    int size1 = nosize, size2= nosize, size3= nosize;

    for(int i = nosize; i>0; i--){

        DT<int>* temp = new DT<int>;
        temp->data = i;
        temp->next = NULL;
        S1.push(temp);
        std::cout<<temp->data;
    }
    std::cout<<std::endl;
    std::cout<<std::endl;

    Display(S1, S2, S3, size1, size2, size3);


    int pole, pole2;

    bool win = false;

    do{

       // Display(S1, S2, S3, size1, size2, size3);
        std::cout<<std::endl;
        std::cout<<"Pick a source poele 1, 2, or 3: "<<std::endl;
        std::cin>>pole;
        std::cout<<"Pick a destination pole 1, 2, or3: ";
        std::cin>>pole2;

        DT<int> *S = new DT<int>;


            if(pole == 1&&pole2==2){
                try{
                if(S2.top() != NULL && (S1.top()->data>S2.top()->data)){
                    std::cout<<std::endl;
                    std::cout<<"Error!! Illegal move. PIck another move."<<std::endl;
                    std::cout<<std::endl;
                }
                else{
                    S = S1.pop();
                    size1--;
                    S->next = NULL;
                    S2.push(S);
                    size2++;

                }

        } catch (Stack<int>::isFull) {
                std::cout<<"Error!! Stack is full"<<std::endl;
                std::cout<<std::endl;
        } catch(Stack<int>::isEmpty){
                std::cout<<"Error!! Stack is empty"<<std::endl;
                std::cout<<std::endl;
        }
            }

//        if(pole == 1&&pole2==2){
//            if(S2.top() != NULL && (S1.top()->data>S2.top()->data)){
//                std::cout<<std::endl;
//                std::cout<<"Error!! Illegal move. PIck another move."<<std::endl;
//                std::cout<<std::endl;
//            }
//            else{
//                try {
//                    S = S1.pop();
//                    size1--;
//                    S->next = NULL;
//                } catch (Stack<int>::isEmpty) {
//                    std::cout<<"Error!! Stack is empty"<<std::endl;
//                    std::cout<<std::endl;
//                }
//                try{
//                    S2.push(S);
//                    size2++;

//                 }catch (Stack<int>::isFull) {
//                    std::cout<<"Error!! Stack is full"<<std::endl;
//                    std::cout<<std::endl;
//                }
//                }


        else if(pole == 1&&pole2==3){
            if(S3.top()!=NULL && (S1.top()->data>S3.top()->data)){
                std::cout<<std::endl;
                std::cout<<"Error!!Illegal move. PIck another move."<<std::endl;
                std::cout<<std::endl;
            }
            else{
                try {
                    S = S1.pop();
                    size1--;
                    S->next = NULL;
                    S3.push(S);
                    size3++;
                    if(S3.length() == nosize){
                        win = true;
                        break;
                    }
                } catch (Stack<int>::isEmpty) {
                    std::cout<<"Stack is empty"<<std::endl;
                } catch (Stack<int>::isFull) {
                    std::cout<<"Stack is full"<<std::endl;

                }

            }
        }

        else if(pole == 2&&pole2==1){
            if(S1.top()!=NULL && (S2.top()->data>S1.top()->data)){
                std::cout<<std::endl;
                std::cout<<"Error!!Illegal move. PIck another move."<<std::endl;
                std::cout<<std::endl;
            }
            else{
                try {
                    S = S2.pop();
                    size2--;
                    S->next = NULL;
                    S1.push(S);
                    size1++;
                } catch (Stack<int>::isEmpty) {
                    std::cout<<"Stack is empty"<<std::endl;
                } catch (Stack<int>::isFull) {
                    std::cout<<"Stack is full"<<std::endl;

                }

            }
        }

        else if(pole == 2&&pole2==3){
            if(S3.top()!=NULL && (S2.top()->data>S3.top()->data)){
                std::cout<<std::endl;
                std::cout<<"Error!!Illegal move. PIck another move."<<std::endl;
                std::cout<<std::endl;
            }
            else{
                try {
                    S = S2.pop();
                    size2--;
                    S->next = NULL;
                    S3.push(S);
                    size3++;
                    if(S3.length() == nosize){
                        win = true;
                        break;
                    }
                } catch (Stack<int>::isEmpty) {
                    std::cout<<"Stack is empty"<<std::endl;
                } catch (Stack<int>::isFull) {
                    std::cout<<"Stack is full"<<std::endl;

                }
            }
        }

        else if(pole == 3&&pole2==1){
            if(S1.top()!=NULL && (S3.top()->data>S1.top()->data)){
                std::cout<<std::endl;
                std::cout<<"Error!!Illegal move. PIck another move."<<std::endl;
                std::cout<<std::endl;
            }
            else{
                try {
                    S = S3.pop();
                    size3--;
                    S->next = NULL;
                    S1.push(S);
                    size1++;
                } catch (Stack<int>::isEmpty) {
                    std::cout<<"Stack is empty"<<std::endl;
                } catch (Stack<int>::isFull) {
                    std::cout<<"Stack is full"<<std::endl;

                }

            }
        }

        else if(pole == 3&&pole2==2){
            if(S2.top()!=NULL && (S3.top()->data>S2.top()->data)){
                std::cout<<std::endl;
                std::cout<<"Error!!Illegal move. PIck another move."<<std::endl;
                std::cout<<std::endl;
            }
            else{
                try {
                    S = S3.pop();
                    size3--;
                    S->next = NULL;
                    S2.push(S);
                    size2++;
                } catch (Stack<int>::isEmpty) {
                    std::cout<<"Stack is empty"<<std::endl;
                } catch (Stack<int>::isFull) {
                    std::cout<<"Stack is full"<<std::endl;

                }

            }
        }
        else{
            std::cout<<"Pick 1, 2, or 3"<<std::endl;

        }
        Display(S1, S2, S3, size1, size2, size3);

    }while(!win);
    std::cout<<std::endl;
    std::cout<<"You win!!!!"<<std::endl;
    std::cout<<std::endl;


    return 0;
}

void PrintStack(Stack<int> S1, Stack<int> S2, Stack<int> S3, int size){

    for (int i = 0;i<size;i++) {
        if(S1.length()>=size-1){
            std::cout<<S1.index(S1.length()-size+i)<<" ";
        }
    else{
        std::cout<<" ";
    }
            if(S2.length()>=size-1){
                std::cout<<S2.index(S2.length()-size+i)<<" ";
            }
        else{
            std::cout<<" ";
        }
                if(S3.length()>=size-1){
                    std::cout<<S3.index(S3.length()-size+i)<<" ";
                }
            else{
                std::cout<<" "<<std::endl;

            }
    }
                std::cout<<"-----------------------------------";


}

