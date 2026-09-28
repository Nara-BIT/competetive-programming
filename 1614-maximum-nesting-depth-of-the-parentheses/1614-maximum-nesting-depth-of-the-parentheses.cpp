class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int ans=0;
        char prev;
        int i,n=s.size();
        for(i=0;i<n;i++){
            if(s[i]=='('){
                count++;
            }
            ans=max(ans,count);
            if(s[i]==')')
                count--;
                
        }
        return ans;
    }
};