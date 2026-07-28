class Solution {
public:
    string LPS(string s){
        string str="";
        str+='#';
        for(char c:s){
            str+='$';
            str+=c;
        }
        str+='$';
        str+='@';

        int n=str.size();
        vector<int>tab(n,0);
        int rb=0;
        int c=0;
        int max_len=0;
        for(int i=1;i<n-1;i++){
            int mirror=2*c-i;
            if(i<rb){
                tab[i]=min(rb-i,tab[mirror]);
            }
            while(str[i+(1+tab[i])]==str[i-(1+tab[i])]){
                tab[i]++;
            }
            if(i+tab[i]>rb){
                rb=i+tab[i];
                c=i;
            }
            if(i-tab[i]==1){
                max_len=max(max_len,tab[i]);
            }
        }
        string suf=s.substr(max_len);
        reverse(suf.begin(),suf.end());
        return suf+s;
    }
    string shortestPalindrome(string s) {
        return LPS(s);
    }
};