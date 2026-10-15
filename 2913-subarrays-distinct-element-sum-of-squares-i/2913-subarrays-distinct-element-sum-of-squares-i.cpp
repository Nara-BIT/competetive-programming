class Solution {
public:
    int sumCounts(vector<int>& nums) {
        long long ans=0;
        int cnt;

        int n=nums.size();
        for(int i=0;i<n;i++){
            
            for(int j=i;j<n;j++){
                set<int>st;
                for(int k=i;k<=j;k++){
                    st.insert(nums[k]);
                }
                cnt=st.size();
                st.clear();
                ans+=(cnt*cnt);
            }
            
        }
        return ans;
    }
};