class Solution {
public:
    vector<int> arrNSE(vector<int>& nums){
        int i;
        int n=nums.size();
        stack<int>st;
        vector<int>NSE(n,n);
        for(i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty())
                NSE[i]=st.top();
            st.push(i);
        }
        return NSE;
    }
    vector<int> arrPSE(vector<int>&nums){
        int i,m=nums.size();
        stack<int>pst;
        vector<int>PSE(m,-1);
        for(i=0;i<m;i++){
            while(!pst.empty()&&nums[pst.top()]>nums[i]){
                pst.pop();
            }
            if(!pst.empty())
                PSE[i]=pst.top();
            pst.push(i);
        }
        return PSE;                     
    }
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        int i;
        int n=heights.size();
        vector<int>PSE=arrPSE(heights);
        vector<int>NSE=arrNSE(heights);
        for(i=0;i<n;i++){
            ans=max(ans,(heights[i]*(NSE[i]-PSE[i]-1)));
        }
        return ans;
    }
};