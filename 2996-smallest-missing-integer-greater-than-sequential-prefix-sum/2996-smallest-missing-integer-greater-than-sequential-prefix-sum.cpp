class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        long long sum=nums[0];
        unordered_set<int>seen(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
            }
            else{
                break;
            }
        }
        while(seen.count(sum)){
            sum++;
        }
        return sum;
    }
};