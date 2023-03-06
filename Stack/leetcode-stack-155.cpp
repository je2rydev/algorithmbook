/*
    155. Min Stack
    30 mins
*/

class MinStack {
private:
    // int max = 30001;
    int count = -1;
    long long minValue = 9223372036854775807;
    vector<int> stack;
public:
    MinStack() {
        
    }
    void sorted(){
        minValue = 9223372036854775807;
        for(int i=0; i<stack.size(); i++){
            if(stack[i] < minValue)
                minValue = stack[i];
            
        }
    }
    
    void push(int val) {
        stack.push_back(val);
        if(val < minValue)
            minValue = val;
        count++;
    }
    
    void pop() {
        stack.pop_back();
        sorted();
        count--;
    }
    
    int top() {
        return stack[count];
    }
    
    
    int getMin() {
        return minValue;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */