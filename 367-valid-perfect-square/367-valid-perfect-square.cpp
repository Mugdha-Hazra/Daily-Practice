class Solution {
public:
    bool isPerfectSquare(int n) {
        int p=sqrt(n);
        return p*p==n;
    }
};