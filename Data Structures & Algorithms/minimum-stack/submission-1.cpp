#include <list>
#include <set>
class MinStack {
public:
    MinStack() {
    
    }
    
    void push(int val) {
        _stack.push_back(val);
        _history.insert(val); 
    }
    
    void pop() {
        _history.erase(_history.find(_stack.back()));
        _stack.pop_back();

    }
    
    int top() {
        return _stack.back();
        
    }
    
    int getMin() {
        return *_history.begin();
    }
private:
    list<int> _stack;
    multiset<int> _history;
    int _min = 0;
};
