class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int res = 0;
        for(int i = 0; i < A.size(); i++) {
            int left = i-1;
            int right = i+1;
            while(left >= 0 && A[left] >= A[i])
                left--;
            while(right < A.size() && A[right] > A[i])
                right++;
            res += A[i]*(i-left)*( right - i);
            if(res > 1000000007)
                res %= 1000000007;
        }
        return res;
    }
};
