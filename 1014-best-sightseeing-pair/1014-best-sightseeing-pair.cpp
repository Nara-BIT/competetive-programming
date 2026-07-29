class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int lr=0;
        int maxi=0;
        int n=values.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,lr+values[i]-i);
            lr=max(lr,values[i]+i);
        }
        return maxi;
    }
};