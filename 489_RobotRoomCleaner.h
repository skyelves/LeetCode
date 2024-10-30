//
// Created by Ke Wang on 10/29/24.
//

#ifndef INC_489_ROBOTROOMCLEANER_H
#define INC_489_ROBOTROOMCLEANER_H

#include "solution.h"

class RobotRoomCleaner : public solution {
private:
    class Robot {
    public:
        // Returns true if the cell in front is open and robot moves into the cell.
        // Returns false if the cell in front is blocked and robot stays in the current cell.
        bool move();

        // Robot will stay in the same cell after calling turnLeft/turnRight.
        // Each turn will be 90 degrees.
        void turnLeft();

        void turnRight();

        // Clean the current cell.
        void clean();
    };

    vector<vector<int> > dir{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // up, right, down, left

public:
    void cleanRoom(Robot &robot) {
        set<pair<int, int> > visited;
        dfs(0, 0, 0, robot, visited);
    }

    void dfs(int x, int y, int currDir, Robot &robot, set<pair<int, int> > &visited) {
        if (visited.find({x, y}) != visited.end()) {
            robot.turnRight();
            robot.turnRight();
            robot.move();
            return;
        }
        visited.insert({x, y});
        robot.clean();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[currDir][0];
            int ny = y + dir[currDir][1];
            if (robot.move()) {
                dfs(nx, ny, currDir, robot, visited);
                robot.turnRight();
                robot.turnRight();
            }
            robot.turnRight();
            ++currDir;
            currDir %= 4;
        }

        robot.turnRight();
        robot.turnRight();
        robot.move();
    }
};

#endif //INC_489_ROBOTROOMCLEANER_H
