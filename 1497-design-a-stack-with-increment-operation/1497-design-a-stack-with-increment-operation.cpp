class CustomStack {
public:
    int top;
    int* arr; 
    int size;
    CustomStack(int maxSize) {
        size = maxSize;
        arr = new int[size];
        top = -1;
    }
    
    void push(int x) {
        if(top == size - 1)
            return;
        else{
            top++;
            arr[top] = x;
        }    
    }
    
    int pop() {
        if(top == -1) 
            return -1;
        else{
            int n = arr[top];
            top--;
            return n;
        }    
    }
    
    void increment(int k, int val) {
        int i = 0;
        while(i < k && i <= top) {
            arr[i] += val;
            i++; 
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */