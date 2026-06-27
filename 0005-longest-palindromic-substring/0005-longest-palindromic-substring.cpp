class Solution {
public:
    string longestPalindrome(string s) {
        string pali="";
        pali+='#';
        for(char c:s){
            pali+='$';
            pali+=c;
        }
        pali+="$@";
        int n=pali.size();
        vector<int>tab(n,0);
        int c=0;
        int r=0;
        for(int i=1;i<n-1;i++){
            int mirror=2*c-i;
            if(i<r)
                tab[i]=min(r-i,tab[mirror]);

            while(pali[i+(1+tab[i])]==pali[i-(1+tab[i])]){
                tab[i]++;
            }
            if(i+tab[i]>r){
                c=i;
                r=i+tab[i];
            }

        }
        int maxlen=0,cent_ind;
        for(int i=1;i<n-1;i++){
            if(tab[i]>maxlen){
                maxlen=tab[i];
                cent_ind=i;
            }
        }
        int start=(cent_ind-maxlen)/2;
        return s.substr(start,maxlen);
    }
};