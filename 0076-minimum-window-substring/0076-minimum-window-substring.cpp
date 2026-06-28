class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>smp;
        int m=s.size();
        int n=t.size();
        if(m<n)
            return "";
        for(char c:t){
            smp[c]++;
        }
        int l=0;
        int st=0;
        int mini=INT_MAX;
        int req=t.size();

        for(int r=0;r<m;r++){
            smp[s[r]]--;
            if(smp[s[r]]>=0)
                req--;
            while(req==0){
                if(r-l+1<mini){
                    mini=r-l+1;
                    st=l;
                }
                smp[s[l]]++;
                if(smp[s[l]]>0){
                    req++;
                }
                l++;
            }
        }
        return mini==INT_MAX ? "":s.substr(st,mini);
    }
};