class DSU{
   
public:
    vector<int>parent,rank,size;
    DSU(int n){
        rank.resize(n+1);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            rank[i]=0;
            size[i]=1;
        }
    }
    int findParent(int node){
        if(node==parent[node])
            return node;
        return parent[node]=findParent(parent[node]);
    }
    void unionByRank(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);
        
        if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else if(rank[v]<rank[u]){
            parent[v]=u;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    void unionBySize(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv)
            return;
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    bool isValid(int row,int col, int n){
        if(row<0 || row>=n || col<0 || col>=n)
            return false;
        return true;
    }
    void createIslands(DSU &D,vector<vector<int>>& grid){
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)
                    continue;
                int node=i*n+j;
                for(int k=0;k<4;k++){
                    int nrow=i+dr[k];
                    int ncol=j+dc[k];
                    if(isValid(nrow,ncol,n) && grid[nrow][ncol]==1){
                        int adjNode=nrow*n+ncol;
                        D.unionBySize(node,adjNode);
                    }
                }
            }
        }
        
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int k=n*n;
        DSU D(k);
        createIslands(D,grid);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum=0;
                set<int>st;
                if(grid[i][j]==0){
                    int node=i*n+j;
                    for(int k=0;k<4;k++){
                        int nrow=i+dr[k];
                        int ncol=j+dc[k];
                        if(isValid(nrow,ncol,n) && grid[nrow][ncol]==1){
                            int adjNode=nrow*n+ncol;
                            int par=D.findParent(adjNode);
                            st.insert(par);
                        }
                    }
                    for(int it:st){
                    sum+=D.size[it];
                    }
                ans=max(ans,1+sum);
                }
                
                
            }
        }
        for(int c=0;c<n*n;c++){
            ans=max(ans,D.size[D.findParent(c)]);
        }
        return ans;

    }
};