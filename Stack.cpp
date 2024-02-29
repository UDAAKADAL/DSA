// USING PREDEFINE STACK

#include<iostream>
#include<stack>
using namespace std;


int main(){
    //create stack
    stack<int> st;

    //insert element
    st.push(5);
    st.push(10);
    st.push(15);
    st.push(20);
    st.push(25);
    //print top element
    cout<<st.top()<<endl;

    //print all element of stack
    cout<<"*****************print all element of stack******************";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    //remove element
    st.pop();
    st.pop();

    //after remove print top element
    cout<<"after remove  top element is: "<<st.top()<<endl;

    //check empty or not
    if(st.empty()){
        cout<<"it is empty";
    }else{
        cout<<"it is not empty";
    }

}


//USING USER DEFINE STACK

#include<iostream>
using namespace std;

class Stack{
    private:
    int * arr;
    int size;
    int top;
    
    public:
    Stack(int size){
        arr=new int[size];
        this->size=size;
        top=-1;
    }
    //function
    void push(int data){
        if(size-(top)<=1){
            cout<<"overflow"<<endl;
        }else{
            top ++;
            arr[top]=data;
        }
    }

    void pop(){
        if(top==-1){
            cout<<"underflow"<<endl;
        }else{
            top--;
        }
    }
    void peek(){
        for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";
       }
    }

    int maxstack(){
        int max;
        for(int i=0;i<size;i++){
            // cout<<arr[i]<<" ";
            // cout<<arr[i+1]<<" ";
            if(arr[i]>arr[i+1]){
                max=arr[i];
            }else{
                max=arr[i+1];
            }
           
          
        }
        cout<< max;
    }

    int gettop(){
        if(top==-1){
            cout<<"stack is empty"<<endl;
        }else{
            return arr[top];
        }
    }

    int getsize(){
        return top+1;
    }

    bool isempty(){
        if(top==-1){
            return true;
        }else{
            return false;
        }
    }
   
};

int main(){
    Stack s(10);
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    s.push(25);
    s.push(30);
    s.peek();
    
    
    cout<<endl;
    cout<<"size: "<<s.getsize()<<endl;
    cout<<"top element: "<<s.gettop()<<endl;
        // print all element
    while(!s.isempty()){
        cout<<s.gettop()<<" ";
        s.pop();
    }
    cout<<endl;
    s.gettop();
}




//TWO STACK IN ONE ARRAY

#include<iostream>
using namespace std;

class Stack{
    private:
    int *arr;
    int size;
    int top1;
    int top2;
    public:
    Stack(int size){
        arr=new int [size];
        this->size=size;
        top1=-1;
        top2=size;
    }

    void push1(int data){
        if(top2-top1==1){
            cout<<"overflow"<<endl;
        }else{
            top1++;
            arr[top1]=data;
        }
    }

    void push2(int data ){
         if(top2-top1==1){
            cout<<"overflow"<<endl;
        }else{
            top2--;
            arr[top2]=data;
        }
    }

    void pop1(){
        if(top1==-1){
            cout<<"underflow"<<endl;
        }else{
            arr[top1]=0;
            top1--;
        }
    }

     void pop2(){
        if(top2==size){
            cout<<"underflow"<<endl;
        }else{
            arr[top2]=0;
            top2++;
        }
    }
    
    int peek(){
        cout<<endl;
        cout<<"top1: "<<top1<<endl;
        cout<<"top2: "<<top2<<endl;
        for(int i =0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};  


int main(){
    Stack s(10);
    s.push1(2);
    s.peek();
    s.push1(4);
    s.peek();
    s.push1(6);
    s.peek();
    s.push1(8);
    s.peek();
    s.push1(10);
    s.peek();
    s.push1(12);
    s.peek();
    s.push1(14);
    s.peek();
    

    s.push2(3);
    s.peek();
    s.push2(4);
    s.peek();
    s.push2(5);
    s.peek();
    s.pop1();
    s.peek();
    s.pop2();
    s.peek();
  return 0;
}

//REVERSE THE STRING USING STACK
#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<char> arr;
    string str;
    cout<<"ENTER ANY NAME:";
    cin>>str;
    for(int i=0;i<str.size();i++){
        arr.push(str[i]);
    }
    while (!arr.empty())
    {
        cout<<arr.top();
        arr.pop();
        
    }
    return 0;
}

// FIND MIDDLE ELEMENT USING STACK
#include <iostream>
#include <stack>
using namespace std;

int midstack(stack<int> &st, int totalsize)
{
    if (totalsize == 0)
    {
        cout << "There is no element:" << endl;
        return 0;
    }
    // base case
    if (totalsize / 2 + 1 == st.size())
    {
        cout << "middle element is: " << st.top();
    }

    int temp = st.top();
    st.pop();
    // recusive call
    midstack(st, totalsize);
    // backtracking
    st.push(temp);
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(35);
    st.push(65);
    st.push(2);
    st.push(44);
    midstack(st, st.size());
    return 0;
}