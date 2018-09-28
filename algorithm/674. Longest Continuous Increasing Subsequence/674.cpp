class Solution {
public:
    int findLengthOfLCIS(vector<int>& A) {
        if(A.size() == 0) return 0;
        int res = 1, countIn = 1;
        for(int i = 1; i < A.size(); i++) {
            if(A[i] > A[i-1]) {
                countIn++;
                res = max(res, countIn);
            }  else {
                countIn = 1;
            }
        }
        return res;
    }
};
