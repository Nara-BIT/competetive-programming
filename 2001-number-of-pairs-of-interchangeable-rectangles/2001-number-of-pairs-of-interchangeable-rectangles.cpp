class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<double,int>freq;
        long long cnt=0;
        int n=rectangles.size();
        for(int i=0;i<n;i++){
            auto it=rectangles[i];
            double div=((double)it[0]/(double)it[1]);
            cnt+=freq[div];
            freq[div]++;
        }
        return cnt;
    }
};