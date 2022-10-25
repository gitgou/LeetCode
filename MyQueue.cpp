#include<stack>
#include<iostream>

class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        _left.push(x);
    }
    void leftToRight()
    {
        while(!_left.empty()){
            _right.push(_left.top());
            _left.pop();
        }

    }

    int pop() {
        if(empty()){
            return 0;
        }

        if(_right.empty())
        {
            leftToRight();
        }

        int res = _right.top();
        _right.pop();
        return res;
    }
    
    int peek() {
        if(empty())
            return 0;

        if(_right.empty()){
            leftToRight();
        }

        return _right.top();
    }
    
    bool empty() {
        return _left.empty() && _right.empty();
    }

    std::stack<int> _left;
    std::stack<int> _right;
};