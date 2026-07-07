class Solution {
public:
    int LCS(int i,int j,string text1, string text2,vector<vector<int>> &dp) {
        if(i<0)
            return j+1;
        if(j<0)
            return i+1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(text1[i]==text2[j]){
            return dp[i][j]=LCS(i-1,j-1,text1,text2,dp);

        }
        
        return dp[i][j]=1+min(LCS(i-1,j,text1,text2,dp),
                    min(LCS(i,j-1,text1,text2,dp),
                        LCS(i-1,j-1,text1,text2,dp)
                    )
                 );

    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return LCS(n-1,m-1,word1,word2,dp);
    }
};