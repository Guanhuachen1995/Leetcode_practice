class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        int max = 0, last = -1;
        for(int i = 0; i < s.length(); i++)
        {
            if(map.containsKey(s.charAt(i)) && map.get(s.charAt(i)) > last)
                last = map.get(s.charAt(i));
            if(max < i - last)
                max = i - last;
            map.put(s.charAt(i), i);
        }
        return max;
    }
}
