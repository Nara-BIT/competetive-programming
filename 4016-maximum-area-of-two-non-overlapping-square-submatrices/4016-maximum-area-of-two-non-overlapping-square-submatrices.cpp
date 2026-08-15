class Solution {
public:
    int marr(vector<int>&nums){
        map<int,int>freq;
        int ans=0;
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            int num=nums[i];
            for(int j=i+num;j<n;j++){
                if(nums[j]>=nums[i]){
                    ans=max(ans,nums[i]);
                }
            }
        }
        return ans;
    }
    int maxArea(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]!=0){
                    dp[i+1][j+1]=1+min(dp[i][j],min(dp[i+1][j],dp[i][j+1]));
                }
            }
        }
        vector<int>matX;
        vector<int>matY;
        for(int i=0;i<n;i++){
            int ans=0;
            for(int j=0;j<m;j++){
                ans=max(ans,dp[i+1][j+1]);
            }
            matY.push_back(ans);
        }
        for(int j=0;j<m;j++){
            int ans=0;
            for(int i=0;i<n;i++){
                ans=max(ans,dp[i+1][j+1]);
            }
            matX.push_back(ans);
        }
        int X=marr(matX);
        int Y=marr(matY);
        return max(pow(X,2),pow(Y,2));
    }
};