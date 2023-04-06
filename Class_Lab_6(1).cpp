#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;


class Stack {
private:
    int top;
    int *arr;
    int max_size;
public:
    Stack(int size) {
        top = -1;
        max_size = size;
        arr = new int[max_size];
    }

    ~Stack() {
        delete[] arr;
    }

    bool is_empty() {
        return top == -1;
    }

    bool is_full() {
        return top == max_size - 1;
    }

    void push(int x) {
        if (is_full()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
        //cout << x << " pushed into stack\n";
        display();
    }

    int pop() {
        if (is_empty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        int x = arr[top--];
        return x;
        display();
    }

    int peek() {
        if (is_empty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top];
    }

    int size() {
        return top + 1;
    }

    void display() {
        if (is_empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size,choice,value,count = 0;
    cout << "Enter the size of the stack: ";
    cin >> size;
    Stack s(size);

    cout<<"1) Push in stack"<<endl;
    cout<<"2) Pop from stack"<<endl;
    cout<<"3) Display stack"<<endl;
    cout<<"4) Exit"<<endl;
    
    auto start = high_resolution_clock::now();
    do {
      cout<<"Enter choice: "<<endl;
      cin>>choice;
      switch(choice) {
         case 1: {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>value;
            s.push(value);
            break;
         }
         case 2: {
            s.pop();
            break;
         }
         case 3: {
            s.display();
            break;
         }
         case 4: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
      count++;
      //cout << count << "\n";
   }while(choice != 4);
   
   auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Time taken by function: "<< duration.count()/1000.0 << " microseconds" << endl;
    
    return 0;
}

