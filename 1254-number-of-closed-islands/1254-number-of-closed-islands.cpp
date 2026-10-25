class Solution {
public:
    vector<int>dr={0,1,0,-1};
    vector<int>dc={-1,0,1,0};
    bool bfs(int r,int c,int m,int n,vector<vector<int>>& grid, vector<vector<bool>>& visit){
        queue<pair<int,int>>q;
        q.push({r,c});
        visit[r][c]=true;
        bool isClosed=true;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr=x+dr[i];
                int nc=y+dc[i];
                if(nr<0 || nr>=m || nc<0 || nc>=n){
                    isClosed=false;
                }
                else if(grid[nr][nc]==0 && !visit[nr][nc]){
                    q.push({nr,nc});
                    visit[nr][nc]=true;
                }
            }
        }
        return isClosed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visit(m,vector<bool>(n));

        int cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && !visit[i][j] && bfs(i,j,m,n,grid,visit)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};