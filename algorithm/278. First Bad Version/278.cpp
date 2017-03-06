// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int tem,start=0,end=n;
        while(end-start>1)
        {
            tem=start+(end-start)/2;
            if(isBadVersion(tem))
            {
                end=tem;
            }
            else
            {
                start=tem;
            }
            
        }
        return end;
    }
};
