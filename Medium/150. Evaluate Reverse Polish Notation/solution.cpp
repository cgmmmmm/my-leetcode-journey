class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stk;
        for (std::string& s : tokens)
        {
            if (s == "+")
            {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                stk.push(b + a);
            }
            else if (s == "-")
            {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                stk.push(b - a);
            }
            else if (s == "*")
            {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                stk.push(b * a);
            }
            else if (s == "/")
            {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                stk.push(b / a);
            }
            else
            {
                stk.push(std::stoi(s));
            }
        }
        return stk.top();
    }
};