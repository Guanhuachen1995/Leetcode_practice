class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        ud = lr = 0
        for i in range(0, len(moves)):
            if moves[i] == 'U':
                ud += 1
            elif moves[i] == 'D':
                ud -= 1
            elif moves[i] == 'L':
                lr += 1
            else:
                lr -= 1
        return (lr == 0) and (ud == 0)
