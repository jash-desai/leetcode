// class Solution {
// public:
//     bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//         stack<int> st;
//         int j = 0; 
//         for(auto val : pushed){
//             st.push(val); 
//             while(st.size()>0 and st.top() == popped[j]){
//                 st.pop();
//                 j++;
//             }
//         }
//         return (st.size() == 0);
//     }
// };
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        int j = 0;
        
        for(auto val : pushed){
            pushed[i++] = val;
            while(i>0 and pushed[i-1]==popped[j]){
                i--;
                j++;
            }
        }
        return (i==0);
    }
};