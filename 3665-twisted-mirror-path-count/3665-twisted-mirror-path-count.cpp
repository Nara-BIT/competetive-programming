class Solution {
public:
    const int MOD=1e9+7;
    int dp[500][500][2];
    
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<array<long long,2>>>f(n,vector<array<long long,2>>(m,{0,0}));
        f[0][0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(i>0){
                    if(grid[i-1][j]==0){
                        f[i][j][0]=(f[i-1][j][0]+f[i-1][j][1])%MOD;
                    }
                    else{
                        f[i][j][0]=f[i-1][j][1];
                    }

                }
                if(j>0 ){
                    if(grid[i][j-1]==0){
                        f[i][j][1]=(f[i][j - 1][0] + f[i][j - 1][1])%MOD;
                    }
                    else{
                        f[i][j][1]=f[i][j-1][0];
                    }
                }
            }
        }
        return (f[n-1][m-1][0]+f[n-1][m-1][1])%MOD;
    }
};