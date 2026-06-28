class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0;
        int r=0;
        map<int,int>freq;
        int ans=0;
        while(r<n){
            char c=s[r];
            freq[c]++;
            char ch;
            while(freq[c]>1 && l<r){
                ch=s[l];
                freq[ch]--;
                l++;
                
            }
            
            ans=max(ans,r-l+1);

            r++;
        }
        return ans;

    }
};