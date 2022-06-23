class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // two variable i and j for number of ( and number of)
        vector<string> res;
        int z = 2*n;
        string temp = "";
        back(res,temp,0,0,z);
        return res;   
    }
    void back(vector<string>& res,string temp,int i,int j,int z)
    {
        if(i+j==z)
        {
            if(i==j)
                res.push_back(temp);
            return;
        }
        else
        {
            temp+='(';
            back(res,temp,i+1,j,z);
            temp.pop_back();
            if(i>j)
            {
                temp+=')';
                back(res,temp,i,j+1,z);
                temp.pop_back();
            }   
        }
    }
};
// we can have n ( and n ) and always at any moment number of ) is less than or equal to number of (