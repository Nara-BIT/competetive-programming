class Solution {
public:
    int maxRepOpt1(string text) {
        map<int,int>freq;
        for(char c:text){
            freq[c-'a']++;
        }
        int left=0,right;
        int len=0;
        int n=text.size();
        for(int i='a';i<='z';i++){
            int l=0;
            int cnt=0;
            int lmax=0;
            for(int r=0;r<n;r++){
                if(text[r]==i){
                    cnt++;
                }
                while(r-l+1>cnt+1){
                    if(text[l]==i){
                        cnt--;
                    }
                    l++;
                }
                lmax=min(r-l+1,freq[i-'a']);
                len=max(len,lmax);
            }
        }
        return len;
    }
};