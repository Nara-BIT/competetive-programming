class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n<=1) 
        return 0;

        sort(intervals.begin(), intervals.end());

        int i=1,j=0,cnt=0;

        while(i<n) {
            if(intervals[i][0] < intervals[j][1]) {
                cnt++;
                if(intervals[i][1] < intervals[j][1]) {
                    j = i;
                }
            } 
            else{
                j = i;
            }
            i++;
        }

        return cnt;
    }
};