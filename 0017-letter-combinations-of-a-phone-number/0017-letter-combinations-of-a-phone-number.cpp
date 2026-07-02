class Solution {
public:
    map<char,string>KeyPad={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string>res;
    vector<string>tempstr;
    void backtrack(int index,string temp){
        if(index==tempstr.size()){
            res.push_back(temp);
            return;
        }
        for(char c:tempstr[index]){
            temp.push_back(c);
            backtrack(index+1,temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int k=digits.size();
        if(digits.empty())
            return {};
        for(char it:digits){
            tempstr.push_back(KeyPad[it]);
        }
        string temp="";
        backtrack(0,temp);
        return res;
        
    }
};