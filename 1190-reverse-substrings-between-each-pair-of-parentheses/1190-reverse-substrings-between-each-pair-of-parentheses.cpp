class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        vector<int>arr(n),st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push_back(i);
            }
            else if(s[i]==')'){
                arr[i]=st.back();
                arr[arr[i]]=i;
                st.pop_back();
            }
        }
        string ans="";
        for(int i=0,dir=1;i<n;i+=dir){
            if(s[i]>='a'){
                ans+=s[i];
            }
            else{
                i=arr[i];
                dir=-dir;
            }
        }
        return ans;
    }
};