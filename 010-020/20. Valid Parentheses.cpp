class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            if(c=='(' or c=='[' or c=='{') st.push(c);
            else{
                if(st.empty()) return 0;
                char x = st.top();
                if((c==')' and x=='(') or (c=='}' and x=='{') or (c==']' and x=='[')) st.pop(); 
                else return 0;
            }
        }
        return st.empty() ? 1:0;
    }
};