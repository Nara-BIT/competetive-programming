class Solution {
public:
    int calc(int num){
        string s=to_string(num);
        int ans=0;
        for(char c:s){
            ans+=(c-'0');
        }
        return ans;
    }
    int smallestIndex(vector<int>& nums) {
        int res=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(calc(nums[i])==i){
                res=i;
                break;
            }
        }
        return res;
    }
};