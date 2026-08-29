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
    void unite(int i,int j){
        int u=findPar(i);
        int v=findPar(j);
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
        return;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        parent.resize(n);
        size.assign(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<pair<char,int>>temp;
        for(int i=0;i<n;i++){
            temp.push_back({s[i],i});
        }
        sort(temp.begin(),temp.end());
        for(auto it:pairs){
            int x=it[0];
            int y=it[1];
            unite(x,y);
        }
        map<int,vector<pair<char,int>>>mpp;
        for(int i=0;i<n;i++){
            int p=findPar(i);
            mpp[p].push_back({s[i],i});
        }
        string ans=s;
        for(auto it:mpp){
            vector<pair<char,int>>temp=it.second;
            vector<char>a;
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