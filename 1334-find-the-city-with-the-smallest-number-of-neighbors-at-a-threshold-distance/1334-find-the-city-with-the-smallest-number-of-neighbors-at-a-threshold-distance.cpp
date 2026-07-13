class Solution {
public:
    int dijkstra(vector<vector<pair<int,int>>>& adj,int threshold,int src,int n){
        vector<int>dist(n,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            auto [currWt,currNode]=pq.top();
            pq.pop();
            if(currWt>dist[currNode])
                continue;
            for(auto& itr:adj[currNode]){
                int nbrNode=itr.first;
                int nbrWt=itr.second;
                
                if(nbrWt+currWt<dist[nbrNode]){
                    pq.push({nbrWt+currWt,nbrNode});
                    dist[nbrNode]=nbrWt+currWt;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(i!=src && dist[i]<=threshold){
                
                cnt++;
            }
        }
        return cnt;

    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<vector<int>>res;
        int minCityCount=n;
        int optimalCity=-1;
        for(int i=0;i<n;i++){
            int cnt=dijkstra(adj,distanceThreshold,i,n);
            if(cnt <= minCityCount){
                minCityCount = cnt;
                optimalCity = i;
            }
        }
        
        return optimalCity;
    }
};