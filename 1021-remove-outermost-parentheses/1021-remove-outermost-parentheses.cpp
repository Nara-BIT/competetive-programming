class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        int n=s.size();
        int left=0;
        int right=0;
        int i=0;
        string res="";
        for(i=0;i<n;i++){
            if(s[i]=='('){
                if(count>0){
                    res+='(';
                    
                }
                count++;

            }
            if(s[i]==')'){
                if(count>1){
                    res+=')';
                }
                count--;
            }
            
            
        }
        return res;
    }
};