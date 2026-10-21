class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>>res(n,vector<int>(n));
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                res[r][c]=grid[(r+colShift[c])%n][(c+rowShift[(r+colShift[c])%n])%n];
            }
        }
        return res;
    }
};