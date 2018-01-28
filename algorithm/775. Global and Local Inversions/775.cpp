class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int k = 0;
        for(int i = 2; i < (int)A.size(); i++)
        {
            if(A[k] > A[i])
                return 0;
            if(A[i-1]> A[i - 2])
            {
                k = i -1;
            }
        }

        return 1;
    }
};
