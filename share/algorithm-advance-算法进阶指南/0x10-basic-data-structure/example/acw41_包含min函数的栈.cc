#include <stack>

class MinStack {
public:
    /** initialize your data structure here. */
    std::stack<int> stk, min_stk;
    MinStack() {
        stk.push(0x7fffffff);
        min_stk.push(0x7fffffff);
    }
    
    void push(int x) {
        stk.push(x);
        // 只保存对最小值有影响的值
        if (x <= min_stk.top()) min_stk.push(x);
    }
    
    void pop() {
        if (stk.top() == min_stk.top()) min_stk.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */