class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int>freq;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            cnt+=freq[nums[i]];
            freq[nums[i]]++;
        }
        return cnt;
    }
};