class Solution {
public:
    vector<pair<int,int>> non_zero(vector<vector<int>>&img){
        vector<pair<int,int>>ret;
        for(int i=0;i<img.size();i++){
            for(int j=0;j<img.size();j++){
                if(img[i][j]==1){
                    ret.push_back({i,j});
                }
            }
        }
        return ret;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<pair<int,int>>A_ones=non_zero(img1);
        vector<pair<int,int>>B_ones=non_zero(img2);
        int cnt=0;
        map<pair<int,int>,int>transform_count;
        for(auto &[xa,ya]:A_ones){
            for(auto& [xb,yb]:B_ones){
                pair<int,int> it={xb-xa,yb-ya};
                transform_count[it]++;
                cnt=max(cnt,transform_count[it]);
            }
        }
        return cnt;
    }
};