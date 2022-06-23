class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return {};
        unordered_map<char,string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        vector<string> res;
        string temp = "";
        //int index = 0;
        rec(res,temp,digits,0,m);
        return res;
        
        
        
    }
    void rec(vector<string>& res,string& temp,string digits,int index,unordered_map<char,string> m)
    {
        if(index==digits.size())
            res.push_back(temp);
        else
        {
            for(int i = 0;i<m[digits[index]].size();i++)
            {
                temp+=m[digits[index]][i];
                rec(res,temp,digits,index+1,m);
                temp.pop_back();
            }
        }
    }
};