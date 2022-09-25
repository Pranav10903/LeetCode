class MyCircularQueue {
private:
    int rear = 0;
    int front = 0;
    int size = 0;
    int capacity = 0;
    vector<int>arr;
public:
    MyCircularQueue(int k) {
        arr.resize(k);
        capacity =  k;
    }
    bool enQueue(int value) {
       if(isFull()){
           return false;
       }   
       if(isEmpty()){
           front = rear = 0;
           arr[rear] = value;
           size++;
           return true;
       }
       rear++;
       size++;
       rear%=capacity;
       arr[rear] = value;
       return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        arr[front] = -1;
        size--;
        front++;
        front%=capacity;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : arr[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : arr[rear];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */