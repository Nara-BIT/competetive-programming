class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int ans=0;
        int n=s.size();
        int left=0;
        for(int right=0;right<n;right++){
            char cr=s[right];
            while(mp[cr]>0){
                char cl=s[left];
                mp[cl]--;
                if(mp[cl]==0){
                    mp.erase(cl);
                }
                left++;
            }
            mp[cr]++;
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};