#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
    MinStack() {
        _min_val = 0;
    }
    
    void push(int val) {
        if(_stk.size() == 0){
            _min_val = val;
            _stk.push(0);
            return;
        }
        long long diff = val - _min_val;
        if(diff < 0){
            _min_val = val;
        }
        _stk.push(diff);
    }
    
    void pop() {
        int diff = _stk.top();
        _stk.pop();
        if(diff < 0){
            _min_val = _min_val - diff;
        }
    
    }
    
    int top() {
        int diff = _stk.top();
        if(diff < 0){
            return _min_val;
        }else{
            return _min_val + diff;
        }
    }
    
    int getMin() {
        return _min_val;
    }

private:
    stack<int> _stk;
    int _min_val;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */