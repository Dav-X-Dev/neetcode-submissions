class Solution {
public:
    bool isValid(string s) {
        //latest bracket open must be the first one closed
        //add bracket to stack->when matching LAST close bracket closes pop
        //if stack isn't empty return false, true otherwise

        stack<char> staxx;

        //iter s->push open brack->if latest one has matching close then close

        for (const auto c : s){
            if (c == '(' || c == '{' || c == '['){
                staxx.push(c);
            }
            else {
                if (staxx.empty()){
                    return false;
                }
                
                if (c == '}' && staxx.top() == '{'){
                    staxx.pop();
                }
                else if (c == ')' && staxx.top() == '('){
                    staxx.pop();
                }
                else if (c == ']' && staxx.top() == '['){
                    staxx.pop();
                }
                else{
                    return false;
                }
            }
        }

        return staxx.empty();

    }
};
