class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n=numWays.size();
        vector<long long>dp(n+1,0);
        dp[0]=1;
        vector<int>coins;
        for(int i=1;i<=n;i++){
            int target=numWays[i-1];
            if(dp[i]==(long long)target-1){
                coins.push_back(i);
                for(int j=i;j<=n;j++){
                    dp[j]+=dp[j-i];
                }
            }
            if(dp[i]!=target){
                return {};
            }

        }
        return coins;
    }
};