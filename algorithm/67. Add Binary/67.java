class Solution {
    public String addBinary(String a, String b) {
        int m = a.length() - 1, n = b.length() -1 , c = 0;
        StringBuilder sb = new StringBuilder();
        while(m>=0||n>=0||c>0)
        {
            c += (m>=0)?a.charAt(m--) - '0':0;
            c += (n>=0)?(b.charAt(n--) - '0'):0;
            sb.append(c%2);
            c/=2;
        }
        return sb.reverse().toString();
    }
}
