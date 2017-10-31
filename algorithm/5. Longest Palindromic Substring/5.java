class Solution {
    public String longestPalindrome(String s) {
        int len = s.length(), start = 0, max = 0;
        for(int i = 0; i < len; i++)
        {
            int j = i - 1, k = i + 1;
            while(j >= 0 && k < len && s.charAt(j) == s.charAt(k))
            {
                j--;
                k++;
            }
            j++;
            k--;
            if(k - j + 1 > max)
            {
                max = k - j + 1;
                start = j;
            }
        }
        for(int i = 0; i < len; i++)
        {
            int j = i, k = i + 1;
            while(j >= 0 && k < len && s.charAt(j) == s.charAt(k))
            {
                j--;
                k++;
            }
            j++;
            k--;
            if(k - j + 1 > max)
            {
                max = k - j + 1;
                start = j;
            }
        }
        if(max == 0)
            return "";
        else
            return s.substring(start, start + max);
    }
}
