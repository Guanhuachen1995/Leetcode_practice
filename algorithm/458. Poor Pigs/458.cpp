class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int times = minutesToTest/minutesToDie + 1;
        int testnum = 1;
        int pig = 0;
        while( testnum < buckets)
        {
            pig++;
            testnum *= times;
        }
        return pig;
    }
};
