class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        m = s.size();
        n = 2 * power2_ceil(s.size()) - 1;
        lc = vector<char>(n, '$');
        rc = vector<char>(n, '$');
        ls = vector<int>(n, 0);
        rs = vector<int>(n, 0);
        longest = vector<int>(n, 0);

        setup(s);
        
        int q = queryCharacters.size();
        vector<int> ans(q);
        for (int i = 0; i < q; ++i) {
            update(s, queryIndices[i] + n / 2, queryCharacters[i], 1);
            ans[i] = longest[0];
        }
        
        return ans;
    }

private:
    void setup(string& s) {
        for (int i = 0; i < m; ++i) {
            update(s, i + n / 2, s[i], 1);
        }
    }
    void update(string& s, int i, char c, int size) {
        if (i < n / 2) {
            int i2 = 2 * i + 1, i3 = 2 * i + 2;
            lc[i] = lc[i2], rc[i] = rc[i3];
            if (rc[i2] == lc[i3]) {
                ls[i] = ls[i2] + (rs[i2] == size / 2 ? ls[i3] : 0);
                rs[i] = rs[i3] + (ls[i3] == size / 2 ? rs[i2] : 0);
                longest[i] = max({longest[i2], longest[i3], rs[i2] + ls[i3]});
            } else {
                ls[i] = ls[i2], rs[i] = rs[i3];
                longest[i] = max(longest[i2], longest[i3]);
            }
        } else {
            lc[i] = rc[i] = c;
            ls[i] = rs[i] = longest[i] = 1;
        }
        if (i) {
            update(s, (i - 1) / 2, c, size * 2);
        }
    }
    int power2_ceil(int n) {
        for (int i = 0; i < 31; ++i) {
            if ((1 << i) >= n) {
                return 1 << i;
            }
        }
        return -1;
    }
    int m, n;
    vector<char> lc, rc;
    vector<int> ls, rs, longest;
};