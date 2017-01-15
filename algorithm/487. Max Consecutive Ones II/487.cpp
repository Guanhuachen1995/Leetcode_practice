class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=0;
        int tem=0;
        vector<int> a;
        for (int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                tem++;
            }
            else
            {
                if(tem!=0)
                    a.push_back(tem);
                a.push_back(0);
                tem=0;
            }
        }
        if(tem!=0)
            a.push_back(tem);
        for (int i =0;i<a.size();i++)
        {
            if(i+2<a.size())
                a[i]=a[i]+a[i+1]+a[i+2]+1;
            else if(i+1<a.size())
                a[i]=a[i]+a[i+1]+1;
            else if(a[i]==0)
                a[i]=1;
        }
        sort(a.begin(),a.end());
        return a[a.size()-1];
        
    }
};
