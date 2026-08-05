class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n=monsters.size();
        vector<long long>diff(n+1,0);
        for(auto it:boosts){
            int x=it[0];
            int y=it[1];
            int v=it[2];
            diff[x]+=v;
            diff[y+1]-=v;

        }
        long long ans=0,ps=0,sum=0;
        for(int i=0;i<n;i++){
            ps+=diff[i];
            if(monsters[i]>ps){
                ans=max(ans,sum+monsters[i]-ps);
            }
            sum+=monsters[i];
        }
        return ans;

    }
};