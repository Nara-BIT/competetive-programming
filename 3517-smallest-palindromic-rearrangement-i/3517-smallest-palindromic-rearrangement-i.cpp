class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        string temp=s;
        int half=n/2;
        if(n==1)
            return s;
        if(n%2==1){
            sort(temp.begin(),temp.begin()+half);
            sort(temp.begin()+half+1,temp.end(),greater<char>());
        }
        else{
            sort(temp.begin(),temp.begin()+half);
            sort(temp.begin()+half,temp.end(),greater<char>());
        }
        return temp;
    }
};