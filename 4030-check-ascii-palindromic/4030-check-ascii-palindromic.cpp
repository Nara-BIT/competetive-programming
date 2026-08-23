class Solution {
public:
    string d2b(int n){
        if(n==0){
            return "0";
        }
        string bin="";
        while(n>0){
            if(n%2==1){
                bin+='1';
            }
            else{
                bin+='0';
            }
            n=n/2;
        }
        reverse(bin.begin(),bin.end());
        if(bin.size()<8){
            string ans="";
            for(int i=0;i<8-bin.size();i++){
                ans+='0';
            }
            ans+=bin;
            return ans;
        }
        return bin;
    }
    bool check_palindrome(string bin){
        int left=0;
        int right=bin.size()-1;
        while(left<right){
            if(bin[left]!=bin[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    bool isPalindromic(string s) {
        string res="";
        for(char c:s){
            res+=d2b(int(c));
        }
        return check_palindrome(res);
    }
};