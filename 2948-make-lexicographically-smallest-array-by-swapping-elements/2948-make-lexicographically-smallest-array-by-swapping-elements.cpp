class Solution {
public:
    vector<int>parent;
    vector<int>size;
    int findPar(int i){
        if(i==parent[i]){
            return i;
        }
        return parent[i]=findPar(parent[i]);
    }
    void unionBySize(int i,int j){
        int u,v;
        u=findPar(i);
        v=findPar(j);
        if(u==v){
            return;
        }
        if(size[u]>=size[v]){
            parent[v]=u;
            size[u]+=size[v];
        }
        else{
            parent[u]=v;
            size[v]+=size[u];
        }
    }
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>>temp;
        int n=nums.size();
        parent.resize(n);
        size.assign(n,1);
        for(int i=0;i<n;i++){
            temp.push_back({nums[i],i});
            parent[i]=i;
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<n-1;i++){
            int x=temp[i].first;
            int xi=temp[i].second;
            int y=temp[i+1].first;
            int yi=temp[i+1].second;

            if(abs(x-y)<=limit){
                unionBySize(xi,yi);
            }
        }
        map<int,vector<pair<int,int>>>mpp;
        for(int i=0;i<n;i++){
            int p=findPar(i);
            mpp[p].push_back({nums[i],i});
        }
        vector<int>ans=nums;
        for(auto it:mpp){
            vector<pair<int,int>>temp=it.second;
            vector<int>a;
            vector<int>b;
            for(auto itr:temp){
                a.push_back(itr.first);
                b.push_back(itr.second);
            }
            sort(a.begin(),a.end());
            sort(b.begin(),b.end());
            for(int i=0;i<a.size();i++){
                ans[b[i]]=a[i];
            }
        }
        return ans;

    }
};