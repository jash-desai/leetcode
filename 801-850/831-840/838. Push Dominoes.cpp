class Solution {
public:
    string pushDominoes(string dominoes) {
        int left = 0, right = 0;
        while(right < dominoes.size()){
            if(dominoes[right] == 'L'){
                if(dominoes[left] == 'R'){
                    helper(dominoes, left+1, right-1);
                    left = right;
                }else{
                    while(left < right){
                        dominoes[left] = 'L';
                        left++;
                    }
                }
            }else if(dominoes[right] == 'R'){
                if(dominoes[left] == 'R'){
                    while(left < right){
                        dominoes[left] = 'R';
                        left++;
                    }
                }else{
                    left = right;
                }
            }
            right++;
        }
        if(dominoes[left] == 'R'){
            while(left < dominoes.size()){
                dominoes[left] = 'R';
                left++;
            }
        }
        return dominoes;
    }
    void helper(string& d, int i, int j){
        while(i < j){
            d[i] = 'R';
            d[j] = 'L';
            i++;
            j--;
        }
    }
};
