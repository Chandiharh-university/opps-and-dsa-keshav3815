 #include <iostream>
#define MAX 100 

class Queue {
private:
    int arr[MAX];  
    int front;     
    int rear;     

public:
     
    Queue() {
        front = -1;
        rear = -1;
    }
    void enqueue(int value) {
        if (rear >= MAX - 1) {
            std::cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) {
            front = 0;  
        }
        arr[++rear] = value;
        std::cout << value << " added to the queue\n";
    }
    int dequeue() {
        if (front == -1 || front > rear) {
            std::cout << "Queue Underflow\n";
            return -1; 
        }
        int value = arr[front++];
        std::cout << value << " removed from the queue\n";
        if (front > rear) {  
            front = -1;
            rear = -1;
        }
        return value;
    }
    bool isEmpty() {
        return front == -1;
    }
    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Front element is " << q.getFront() << "\n";

    q.dequeue();
    q.dequeue();

    if (q.isEmpty()) {
        std::cout << "Queue is Empty\n";
    } else {
        std::cout << "Queue is not Empty\n";
    }

    return 0;
}
