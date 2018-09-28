class Solution {
public:
    /**
     * @param L: Given n pieces of wood with length L[i]
     * @param k: An integer
     * @return: The maximum length of the small pieces
     */
    int woodCut(vector<int> &L, int k) {
        // write your code here
        if(L.size() == 0)   return 0;
        int l = 1, r = 0;
        for(auto l:L)
            r = max(r, l);
        while(l + 1 < r) {
            int mid = l + (r - l)/2;
            if(countpiece(mid, L) < k) 
                r = mid;
            else
                l = mid;
        }
        if(countpiece(r, L) >= k)
            return r;
        if(countpiece(l, L) >= k)
            return l;
        return 0;
    }
    
    int countpiece(int mid, vector<int> &L) {
        int count = 0;
        for(auto l:L)
            count += l/mid;
        return count;
    }
};
