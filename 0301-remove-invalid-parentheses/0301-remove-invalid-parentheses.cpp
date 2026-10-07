class Solution {
public:
    void forward(string s, vector<string>& res,int fi, int fj){
        int bal=0;
        for(int i=fi;i<s.length();i++){
            if(s[i]=='('){
                bal++;
            }
            else if(s[i]==')'){
                bal--;
            }
            if(bal>=0){
                continue;
            }
            for(int j=fj;j<=i;j++){
                if(s[j]==')' && (j==fj || s[j-1]!=')')){
                    forward(s.substr(0,j)+s.substr(j+1),res,i,j);
                }
            }
            return;
        }
        backward(s,res,s.length()-1,s.length()-1);
    }
    void backward(string s,vector<string>& res,int bi,int bj){
        int bal=0;
        for(int i=bi;i>=0;i--){
            if(s[i]==')'){
                bal++;
            }
            else if(s[i]=='('){
                bal--;
            }
            if(bal>=0){
                continue;
            }
            for(int j=bj;j>=i;j--){
                if(s[j]=='(' && (j==bj || s[j+1]!='(')){
                    backward(s.substr(0,j)+s.substr(j+1),res,i-1,j-1);
                }
            }
            return;
        }
        
        res.push_back(s);
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string>res;
        forward(s,res,0,0);
        return res;
    }
};