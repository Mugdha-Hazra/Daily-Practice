int tar;

class Solution {
public:
    void tryForm(int idx, vector<int>& mat, int sum, vector<int>& row, int mask, int pre) {
        if (sum == tar) {
            row.push_back(mask);
            return;
        }
        
        if (sum > tar or idx == -1) {
            return;
        }
        
        if ((mask & (1<<idx)) > 0 or mat[idx] == pre) {
            tryForm(idx-1, mat, sum, row, mask, pre);
        } else {
            int nextMask = (mask | (1<<idx));
            tryForm(idx-1, mat, sum + mat[idx], row, nextMask, pre);
            tryForm(idx-1, mat, sum, row, mask, mat[idx]);
        }
    }
    
    bool dfs(int pos, int mask, vector<int>& mat) {
        if (pos == 3) {
            return true;
        }
        
        vector<int> v;
        int sum = 0, idx = 0, nextMask = mask;
        for (int i = mat.size()-1; i >=0; i--) {
            if ((mask & (1<<i)) == 0) {
                sum += mat[i];
                idx = i-1;
                nextMask |= (1<<i);
                break;
            }
        }
        
        tryForm(idx, mat, sum, v, nextMask, -1);
        int res = false;

        for (int i = 0; i < v.size(); i++) {
            res = (res or dfs(pos+1, v[i], mat));
            if (res) return true;
        }
    
        return false;
    }
    
    
    bool makesquare(vector<int>& mat) {
        int n =  mat.size();
        if (n < 4) return false;
        sort(mat.begin(), mat.end());
        int sum = 0;
        for (auto& m : mat) sum += m;
        if (sum % 4 != 0) return false;
        tar = sum / 4;

        return dfs(0, 0, mat);
    }
};