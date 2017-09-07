class Solution {
public:
    void push(int value) {
        stack1.push(value);
    }
    void pop() {
        stack1.pop();
        
    }
    int top() {
        return stack1.top();
    }
    
    int min() {
        int m=stack1.top();
        stack1.pop();
        stack2.push(m);
        
        while(!stack1.empty()){
            if(m>stack1.top())
                m=stack1.top();
            stack2.push(stack1.top());
            stack1.pop();
        }
        
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return m;
    }
    private:
    stack<int> stack1;
    stack<int> stack2;
};

//O(1)
//实现栈中最小值，给定两个栈，栈1保存当前值，栈2保存当前每次存储的最小值
class Solution {
public:
    void push(int value) {
        stack1.push(value);
        
        if(stack2.size()==0 || value<stack2.top())
            stack2.push(value);
        else
            stack2.push(stack2.top());
    }
    void pop() {

        stack1.pop();
        stack2.pop();
    }
    
    int top() {
        return stack1.top();
    }
    
    int min() {
        
        return stack2.top();
    }
    private:
    stack<int> stack1;
    stack<int> stack2;
};