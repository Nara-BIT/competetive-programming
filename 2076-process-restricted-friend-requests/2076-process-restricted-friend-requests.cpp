class Solution {
public:
    vector<int>parent;
    int findParent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        vector<bool>result;
        for(const auto& it:requests){
            int u=it[0];
            int v=it[1];
            int rootU=findParent(u);
            int rootV=findParent(v);

            if(rootU==rootV){
                result.push_back(true);
                continue;
            }
            bool canMerge=true;
            for(const auto& itr:restrictions){
                int resX=findParent(itr[0]);
                int resY=findParent(itr[1]);
                if((rootU==resX && rootV==resY) || (rootU==resY && rootV==resX)){
                    canMerge=false;
                }
            }
            if(canMerge){
                parent[rootU]=rootV;
                result.push_back(true);


            }
            else{
                result.push_back(false);
            }
        }
        return result;

    }
};