class Solution
{//用两个栈实现队列的弹入弹出
public:
    void push(int node) {//栈1进入元素
        stack1.push(node);
    }

    int pop() {
        if(stack2.size()<=0){//当栈2空的时候，
            while(stack1.size()>0){//并且栈1不为空的时候，将栈1的元素输出到栈2中，实现一次逆转，下次输出栈2时，即为先进先出
                int data = stack1.top();
                stack1.pop();
                stack2.push(data);
            }
        }
        
        int pdata=stack2.top();//栈2弹出元素
        stack2.pop();
        return pdata;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};