class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //use stack to track # tokens. when operand appears take the last 2 entries
        //and perform arithmetic 

        stack<int> staxx;
        int result, num1, num2;

        for (const auto& t : tokens) {
            
            if (t == "+"){
                int num1 = staxx.top();
                staxx.pop();
                int num2 = staxx.top();
                staxx.pop();
                result = num1 + num2;
                staxx.push(result);
            }
            else if (t == "-"){
                num1 = staxx.top();
                staxx.pop();
                num2 = staxx.top();
                staxx.pop();
                result = num2 - num1;
                staxx.push(result);
            }
            else if (t == "/"){
                num1 = staxx.top();
                staxx.pop();
                num2 = staxx.top();
                staxx.pop();
                result = num2 / num1;
                staxx.push(result);
            }
            else if (t == "*"){
                num1 = staxx.top();
                staxx.pop();
                num2 = staxx.top();
                staxx.pop();
                result = num1 * num2;
                staxx.push(result);
            }
            else {
                staxx.push(stoi(t));
            }
        }

        return staxx.top();
    }
};
