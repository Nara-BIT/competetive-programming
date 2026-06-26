class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        vector<int>NGE(n,-1);
        stack<int>st;
        map<int,int>mp;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            NGE[i]=(st.empty()? -1 : st.top());
            st.push(nums2[i]);
        }

        for(int i=0;i<n;i++){
            mp[nums2[i]]=NGE[i];
        }
        vector<int>ans;
        for(int it:nums1){
            ans.push_back(mp[it]);
        }
        return ans;
    }
};