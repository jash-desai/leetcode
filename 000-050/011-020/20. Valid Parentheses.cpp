class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(char c : s){
            switch(c){
                case '(':
                case '{':
                case '[':
                    stack.push(c);
                break;

                case ')':
                case '}':
                case ']': {
                    if(stack.empty()) return false;
                    char compli;
                    if(c == ')') compli = '(';
                    if(c == '}') compli = '{';
                    if(c == ']') compli = '[';
                    if(stack.top() == compli){
                        stack.pop();
                    }else{
                        return false;
                    }
                }
                break;

                default:
                return false;
            }
        
        }
        return stack.empty();
    }
};