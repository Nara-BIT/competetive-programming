class Solution {
public:
    int largestInteger(int num) {
    
        int number=num;
        string s;
        s=to_string(number);
    
        int n=s.size();
        string even="";
        string odd="";
        string ans="";
        int i,j;
        for(i=0;i<n;i++){
            if(isdigit(s[i])&&(s[i]-'0')%2==0){
                even+=s[i];
            }
            else
                odd+=s[i];
        }
        sort(even.begin(),even.end(),greater<char>());
        sort(odd.begin(),odd.end(),greater<char>());
        int l=0,m=0;
        for(i=0;i<n;i++){
            if(isdigit(s[i])&&(s[i]-'0')%2==0){
                ans[i]+=even[l++];
            }
            else
                ans[i]+=odd[m++];
        }
        int num1=stoi(ans);
        return num1;
    }
};