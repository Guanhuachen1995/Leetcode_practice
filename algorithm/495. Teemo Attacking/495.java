class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        int result = 0, time = -1;
        for(int i = 0; i < timeSeries.length; i++)
        {
            if(timeSeries[i] >= time)
            {
                result += duration;
            }
            else
                result += timeSeries[i] - timeSeries[i-1];
            time = timeSeries[i] + duration;
        }
        return result;
    }
}
