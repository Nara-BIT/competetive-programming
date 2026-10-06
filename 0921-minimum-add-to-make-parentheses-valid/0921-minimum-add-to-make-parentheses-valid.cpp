class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0;
        int balance=0;
        for(char c:s){
            if(c=='('){
                balance++;
            }
            else{
                if(balance>0){
                    balance--;
                }
                else{
                    cnt++;
                }
            }
        }
        return cnt+balance;
    }
};