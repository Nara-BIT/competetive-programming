class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        int i,n=s.size();
        int flag=0;
        for(i=0;i<n;i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty())
                    return false;
                char c=st.top();
                st.pop();
                if((s[i]==')'&&c=='(')||(s[i]=='}'&&c=='{')||(s[i]==']'&&c=='['))
                    flag=1;
                else
                    return false;

            }
        }
        if(st.empty())
            return true;
        return false;
    }
};