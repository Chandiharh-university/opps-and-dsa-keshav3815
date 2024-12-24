 #include <iostream>
#define MAX 100 

class Stack {
private:
    int arr[MAX];  
    int top;     
public:
    Stack() { top = -1; }
    void push(int value) {
        if (top >= MAX - 1) {
            std::cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
        std::cout << value << " pushed onto stack\n";
    }
    int pop() {
        if (top < 0) {
            std::cout << "Stack Underflow\n";
            return -1; 
        }
        int value = arr[top--];
        std::cout << value << " popped from stack\n";
        return value;
    }
    int peek() {
        if (top < 0) {
            std::cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }
    bool isEmpty() {
        return top < 0;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Top element is " << s.peek() << "\n";

    s.pop();
    s.pop();

    if (s.isEmpty()) {
        std::cout << "Stack is Empty\n";
    } else {
        std::cout << "Stack is not Empty\n";
    }

    return 0;
}
