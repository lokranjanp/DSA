#include <iostream>
using namespace std;

#define MAX 1000

class Queue {
    int front;
    int back;
    int size;

public:
    int nums[MAX];
    Queue(int capacity)
    {
        front = -1;
        back = -1;
        size = capacity;
    }

    bool enqueue(int num);
    int dequeue();
    int queuefront();
    int queueback();
    bool isempty();
};

bool Queue::enqueue(int num) {
    if (back == size - 1) {
        cout << "Queue max capacity reached" << endl;
        return false;
    }
    if (front == -1) {
        front = 0;
    }
    back++;
    nums[back] = num;
    return true;
}

int Queue::dequeue() {
    if (isempty()) {
        cout << "Empty Queue" << endl;
        return -1;
    }
    int ans = nums[front];
    if (front == back) {
        front = -1;
        back = -1;
    }
    else {
        front++;
    }
    return ans;
}

int Queue::queuefront() {
    if (!isempty()) {
        return nums[front];
    }
    cout << "Empty Queue" << endl;
    return -1;
}

int Queue::queueback() {
    if (!isempty()) {
        return nums[back];
    }
    cout << "Empty Queue" << endl;
    return -1;
}

bool Queue::isempty() {
    return (front == -1);
}

int main() {
    Queue q(2);
    cout << q.enqueue(10) << endl;
    cout << q.enqueue(11) << endl;
    cout << q.enqueue(12) << endl;
    cout << q.queuefront() << endl;
    cout << q.dequeue() << endl;
    cout << q.queueback() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    return 0;
}
