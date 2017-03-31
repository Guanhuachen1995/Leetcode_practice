// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int gun,higher=n,lower=1;
        while(lower<higher)
        {
            gun=(higher-lower)/2+lower;
            if(guess(gun)==1)
            {
                lower=gun+1;
            }
            else
                higher=gun;
        }
        return lower;
    }
};
