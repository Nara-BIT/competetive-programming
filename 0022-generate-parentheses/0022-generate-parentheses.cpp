class Solution {
public:
    void backtrack(int open,int close,vector<string>&res,string par,int n){
        if(open==n&&close==n){
            res.push_back(par);
            return;
        }
        if(open<n){
            par.push_back('(');
            backtrack(open+1,close,res,par,n);
            par.pop_back();
        }
        if(close<open){
            par.push_back(')');
            backtrack(open,close+1,res,par,n);
            par.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        int open=0;
        int close=0;
        string par="";
        backtrack(open,close,res,par,n);
        return res;


    }
};