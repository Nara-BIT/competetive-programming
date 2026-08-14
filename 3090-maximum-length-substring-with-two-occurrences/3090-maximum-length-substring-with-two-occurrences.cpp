class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans=0;
        map<char,int>freq;
        int n=s.size();
        int l=0,r=0;
        for(int i=0;i<n;i++){
            char c=s[i];
            freq[c]++;
            while(freq[c]>2 && l<=i){
                char cl=s[l];
                freq[cl]--;
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};