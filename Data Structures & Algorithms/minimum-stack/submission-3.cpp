class MinStack {
public:

    //idea: use 2 stacks, 1 has actual values & 2 tracks the smallest value when #
    //is added to the first stack

    stack<int> staxx;
    stack<int> min_staxx;

    MinStack() {
        
    }
    
    void push(int val) {
        staxx.push(val);   
        if (min_staxx.empty()){
            min_staxx.push(val);
            return;
        }

        int min = min_staxx.top();
        //top of  stack is latest min val. if curr val < last then replace last
        if (val < min){
            min_staxx.push(val);
        }
        else{
            
            min_staxx.push(min);
        }

    }
    
    void pop() {
        staxx.pop();
        min_staxx.pop();
    }
    
    int top() {
        return staxx.top();
    }
    
    int getMin() {
        return min_staxx.top();
    }
};
