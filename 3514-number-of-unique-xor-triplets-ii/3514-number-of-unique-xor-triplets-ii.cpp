class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int m=*max_element(nums.begin(),nums.end());
        int u=1;
        while(u<=m){
            u<<=1;
        }
        vector<int>t(u),s(u);
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                t[nums[i]^nums[j]]=1;
            }
        }
        for(int x=0;x<u;x++){
            if(!t[x]){
                continue;
            }
            for(int v:nums){
                s[x^v]=1;
            }
        }
        int ans=0;
        for(int i=0;i<u;i++){
            if(s[i])
                ans++;
        }
        return ans;
    }
};