#include <list>
class MinStack {
public:
    MinStack() {
    
    }
    
    void push(int val) {
        _stack.push_back(val);
        if (_history.empty())
            _history.push_back(val); 
        else _history.push_back(min(val, _history.back()));
    }
    
    void pop() {
        _stack.pop_back();
        _history.pop_back();

    }
    
    int top() {
        return _stack.back();
        
    }
    
    int getMin() {
        return _history.back();
    }
private:
    list<int> _stack;
    list<int> _history;
    int _min = 0;
};
