class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        int m=2*n;
        int i;
        stack<int>st;
        vector<int>NGE(n,-1);
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && nums[i%n]>=st.top()){
                st.pop();
            }
            if(i<n){
                NGE[i%n]=(st.empty()?-1:st.top());
            }
            st.push(nums[i%n]);
        }
        return NGE;

    }
};