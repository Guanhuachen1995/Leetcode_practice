/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    void cleanRoom(Robot& robot) {
        unordered_set<string> set;
        DFS(robot, 0, 0, 0, set);
    }
    
    void DFS(Robot& robot, int i, int j, int dir, unordered_set<string> &set) {
        string temp = to_string(i) + " " + to_string(j);
        if(set.find(temp) != set.end()) return;
        robot.clean();
        set.insert(temp);
        #cout<<temp<<endl;
        for(int n = 0; n < 4; n++) {
            if(robot.move()) {
                pair<int, int> move = checkdir(dir);
                
                DFS(robot, i + move.first, j + move.second, dir, set);
                robot.turnLeft();
    			robot.turnLeft();
    			robot.move();
    			robot.turnRight();
    			robot.turnRight();
            }
            
            dir += 90;
            dir %= 360;
            robot.turnRight();
        }
        
    }
    
    pair<int, int>  checkdir(int dir) {
        if(dir == 0)    return {-1, 0};
        else if(dir == 90) return {0, 1};
        else if(dir == 180) return {1, 0};
        else if(dir == 270) return {0, -1};
    }
};
