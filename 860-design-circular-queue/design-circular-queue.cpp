class MyCircularQueue {
    int * arr;
    int capacity;
    int currSize;

    int f, r;

public:
    MyCircularQueue(int k) {
        capacity = k;
        arr = new int[capacity];
        currSize = 0;

        f = 0;
        r = -1;
        
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        
        r = (r + 1) % capacity;
        arr[r] = value;
        currSize++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        f = (f + 1) % capacity;
        currSize--;
        return true;
        
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return arr[f];
        
    }
    
    int Rear() {
        if(isEmpty()) return -1;

        return arr[r];
        
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
    
    bool isFull() {

        return capacity  == currSize;
        
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