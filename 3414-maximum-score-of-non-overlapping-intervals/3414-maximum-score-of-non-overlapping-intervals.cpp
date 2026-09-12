class Solution {
public:
    bool comparator(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int>order(n);
        for(int i=0;i<n;i++){
            order[i]=i;
        }
        sort(order.begin(),order.end(),[&](int a,int b){
            return intervals[a][1]<intervals[b][1];
        });
        vector<int>rights(n);
        for(int p=0;p<n;p++){
            rights[p]=intervals[order[p]][1];
        }
        using State=pair<long long,vector<int>>;
        vector<State>prev(n+1,{0,{}});
        for(int k=0;k<4;k++){
            vector<State>curr(n+1,{0,{}});
            for(int p=1;p<=n;p++){
                int i=order[p-1];
                int l=intervals[i][0];
                int w=intervals[i][2];
                int j=lower_bound(rights.begin(),rights.end(),l)-rights.begin();
                State take=prev[j];
                take.first-=w;
                take.second.insert(upper_bound(take.second.begin(),take.second.end(),i),i);
                curr[p]=min(take,curr[p-1]);
            }
            prev=move(curr);
        }
        return prev[n].second;

    }
};