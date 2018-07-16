class Solution {
    public int[] advantageCount(int[] A, int[] B) {
        Arrays.sort(A);
        int[] res = new int[A.length];
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a,b) -> b[0] - a[0]);
        for(int i = 0; i < B.length; i++) pq.add(new int[]{B[i], i});
        int l = 0, r = A.length - 1;
        while(l <= r) {
            int[] cur = pq.poll();
            if(A[r] > cur[0])  res[cur[1]] = A[r--];
            else    res[cur[1]] = A[l++];
        }
        return res;
    }
}
