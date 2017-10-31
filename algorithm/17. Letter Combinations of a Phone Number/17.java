class Solution {
    public List<String> letterCombinations(String digits) {
        LinkedList<String> ans = new LinkedList<String>();
        String[] mapping = new String[] {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if(digits.length() == 0)    return ans;
        ans.add("");
        for(int i =0; i<digits.length();i++){
            int size = ans.size();
            for(int k = 0; k < size; k++)
            {
                int x = Character.getNumericValue(digits.charAt(i));
                String t = ans.remove();
                for(char s : mapping[x].toCharArray())
                    ans.add(t+s);
            }
            
        }
        return ans;
    }
}
