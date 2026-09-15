class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j+i<=n;j++){
                int right=j+i-1;
                if((s[j]==s[right])&&(i<=2 || dp[j+1][right-1]))
                    dp[j][right]=true;
            }
        }

        vector<int>ans(n+1);
        for(int i=1;i<=n;i++){
            ans[i]=ans[i-1];
            for(int j=0;j+k<=i;j++){
                if(dp[j][i-1])
                    ans[i]=max(ans[i],ans[j]+1);
            }
        }
        return ans[n];
    }
};