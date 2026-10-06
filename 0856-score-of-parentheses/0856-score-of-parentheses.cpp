class Solution {
public:
    int scoreOfParentheses(string s) {
        int balance=0;
        int cnt=0;
        int max_cnt=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                balance++;
            }
            else{
                balance--;
                if(s[i-1]=='('){
                    cnt=cnt+pow(2,balance);
                }
            }
        }
        
        return cnt;
    }
};