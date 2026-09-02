class Solution {
public:
    /*void BSF(vector<int>& edges){
        int n=edges.size();
        for(int i=0;i<n;i++){

        }
    }*/
    int edgeScore(vector<int>& edges) {
        int n=edges.size();
        vector<long long>weight(n,0);
        for(int i=0;i<n;i++){
            weight[edges[i]]+=i;
        }
        vector<pair<long long,int>>wt;
        long long maxi=0;
        for(int i=0;i<n;i++){
            wt.push_back({weight[i],i});
            maxi=max(maxi,weight[i]);
        }
        sort(wt.begin(),wt.end());
        int index=1e9;
        for(int i=0;i<n;i++){
            if(wt[i].first==maxi){
                index=min(index,wt[i].second);
            }
        }
        return index;

    }
};