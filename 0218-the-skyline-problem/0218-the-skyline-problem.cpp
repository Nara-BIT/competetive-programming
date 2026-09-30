class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>>res;
        multiset<int>pq{0};
        vector<pair<int,int>>points;
        for(auto b:buildings){
            points.push_back({b[0],-b[2]});
            points.push_back({b[1],b[2]});
        }
        sort(points.begin(),points.end());
        int height=0;
        for(int i=0;i<points.size();i++){
            int curr=points[i].first;
            int hCurr=points[i].second;
            if(hCurr<0){
                pq.insert(-hCurr);
            }
            else{
                pq.erase(pq.find(hCurr));
            }
            auto pqTop=*pq.rbegin();
            if(height!=pqTop){
                height=pqTop;
                res.push_back({curr,height});
            }
        }
        return res;
    }
};