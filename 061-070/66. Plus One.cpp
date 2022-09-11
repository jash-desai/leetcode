class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
         int len = digits.size();
        bool ninePlaces = true;
        int i = 0;
        for(; i<len; i++){
            if( digits[i] != 9 ){
                ninePlaces = false;
                break;
            }
        }
        if( ninePlaces ){
            digits.clear();
            int l = len+1;
            while(l>0){
                if( l==len+1){
                   digits.push_back(1); 
                }else{
                    digits.push_back(0);
                }
                l--;
            }
        }else{
            bool needToAdd=true;
            int currIndex = len-1;
            while( needToAdd ){
                int digit = digits[currIndex];
                if( digit!=9){
                    needToAdd=false;
                    digits[currIndex] = digit + 1;
                }else{
                    digits[currIndex] = 0;
                    currIndex--;
                }
                
            }
            
        }
        
        return digits;
    }
};