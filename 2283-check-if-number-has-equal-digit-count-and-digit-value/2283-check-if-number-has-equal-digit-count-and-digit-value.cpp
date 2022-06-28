class Solution {
public:
    bool digitCount(string num) {
      unordered_map<char,int> mp;
        for(int i=0;i<num.length();i++)
        {
             mp[num[i]]++;
        }
        for(auto ele: mp)
        {
            
            if(ele.second!=num[ele.first-'0']-'0')
                return false;
        }
        return true;
        
    }
};