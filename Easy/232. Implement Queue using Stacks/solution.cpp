class MyQueue {
private:
    std::stack<int> stk;

public:
    MyQueue() 
    {}
    
    void push(int x) 
    {
        stk.push(x);
    }
    
    int pop() 
    {
        std::stack<int> tmp;
        int res = stk.top();
        while (!stk.empty())
        {
            res = stk.top();
            tmp.push(res);
            stk.pop();
        }
        tmp.pop();
        while (!tmp.empty())
        {
            stk.push(tmp.top());
            tmp.pop();
        }
        return res;
    }
    
    int peek() 
    {
        std::stack<int> tmp = stk;
        int res = tmp.top();
        while (!tmp.empty())
        {
            res = tmp.top();
            tmp.pop();
        }
        return res;
    }
    
    bool empty() 
    {
        return stk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */