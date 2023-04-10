class Solution {
public:
    bool issafe(int row, int col, vector<string>&t, int n){
        int tr=row;
        int tc=col;
        while(row>=0 and col>=0){
            if(t[row][col]=='Q') return 0;
            row--;
            col--;
        }
        col=tc;
        row=tr;
        while(col>=0){
            if(t[row][col]=='Q') return 0;
            col--;
        }
        col=tc;
        row=tr;
        while(row<n and col>=0){
            if(t[row][col]=='Q') return 0;
            row++;
            col--;
        }
        return 1;
    }
    void rec(int col, vector<string>&t, vector<vector<string>>&a, int n){
        if(col==n){
            a.push_back(t);
            return;
        }
        for(int row=0; row<n; row++){
            if(issafe(row,col,t,n)){
                t[row][col] = 'Q';
                rec(col+1,t,a,n);
                t[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> a;
        vector<string> t(n);
        string s(n,'.');
        for(int i=0; i<n; i++){
            t[i]=s;
        }
        rec(0,t,a,n);
        return a;
    }
};