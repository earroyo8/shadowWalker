#include <GL/gl.h>
#include <GL/glx.h>
#include <X11/Xlib.h>
#include <X11/X.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

// Define Tile class to represent each tile in the map
class Tile {
public:
    int x;
    int y;
    int g; // G cost
    int h; // H cost
    int f; // Total cost (g + h)
    Tile* parent;

    // Constructor
    Tile(int x, int y) : x(x), y(y), g(0), h(0), f(0), parent(nullptr) {}

    // Function to calculate the total cost
    void calculateTotalCost() {
        f = g + h;
    }
};

// Define functor for comparing Tile* objects based on their total cost (f) values
struct CompareTiles {
    bool operator()(const Tile* t1, const Tile* t2) const {
        return t1->f > t2->f;
    }
};

// Define function to calculate Manhattan distance between two tiles
int ManhattanDistance(const Tile* t1, const Tile* t2) {
    return abs(t1->x - t2->x) + abs(t1->y - t2->y);
}

bool isValidPosition(int x, int y) {
    // Assuming map is a 2D grid with dimensions mapWidth and mapHeight
    int mapWidth = /* Add map width here */;
    int mapHeight = /* Add map height here */;

    // Check if (x, y) is within map bounds
    if (x >= 0 && x < mapWidth && y >= 0 && y < mapHeight) {
        return true;
    } else {
        return false;
    }
}

bool isTraversable(const vector<vector<Tile>>& map, int x, int y) {
    // Assuming the map is a 2D grid of Tile objects, where map[i][j] represents the tile at (i, j)
    // Check if (x, y) is within map bounds
    if (isValidPosition(x, y)) {
        // Check if the tile at (x, y) is traversable
        if (map[x][y].isTraversable()) {
            return true;
        } else {
            return false;
        }
    } else {
        // If (x, y) is outside map bounds, it is considered not traversable
        return false;
    }
}

bool isTileInPriorityQueue(const priority_queue<Tile*, vector<Tile*>, CompareTiles>& pq, const Tile* tile) {
    // Create a copy of the priority queue to avoid modifying the original priority queue
    priority_queue<Tile*, vector<Tile*>, CompareTiles> pqCopy = pq;

    // Loop through the copied priority queue to check if the tile is present
    while (!pqCopy.empty()) {
        const Tile* currentTile = pqCopy.top();
        pqCopy.pop();

        // Compare the memory addresses of the tiles to check for presence in the priority queue
        if (currentTile == tile) {
            return true;
        }
    }

    // If tile is not found in the priority queue, return false
    return false;
}

vector<Tile*> calculateAStarPath(const vector<vector<Tile>>& map, int startX, int startY, int targetX, int targetY) {
    priority_queue<Tile*, vector<Tile*>, CompareTiles> openList;

    set<Title*> closedList;

    Tile* startTile = &map[startX][startY];
    Tile* targetTile = &map[targetX][targetY];

    openList.push(startTile);

    while (!openList.empty()) {
        Tile* currentTile = openList.top();
        openList.pop();

        closedList.insert(currentTile);

        if (currentTile == targetTile) {
            //target tile found, construct and return the path
            vector<Tile*> path;
            while (current != nullptr) {
                path.push_back(currentTile);
                currentTile = currentTile->parent;
            }

            reverse(path.begin(), path.end());
            return path;
        }
        vector<Tile*> neighbors;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                //skip the current tile itself
                if (dx == 0 && dy == 0) {
                    continue;
                }

                int nx = currentTile->x + dx;
                int ny = currentTile->y + dy;

                //check if neighbor is within bounds
                if (!isValidPosition(nx, ny)) {
                    continue;
                }

                if (!isTraversible(map, nx, ny)) {
                    continue;
                }

                Tile* neighborTile = &map[nx][ny];
                neighbors.push_back(neighborTile);
            }
        }

        //evaluate each neighbor
        for (Tile* neighborTile : neighbors) {
            //skip neighbor if closed
            if (closedList.find(neighborTile) != closedList.end()) {
                continue;
            }

            int tentativeG = current->g + 1;
            bool isInOpenList = isTileInPriorityQueue(openList, neighborTile);

            if (!isInOpenList || tentativeG < neighborTile->g) {
                neighborTile->g = tentativeG;
                neighborTile->h = ManhattanDistance(neighborTile, targetTile);
                neighborTile->calculateTotalCost();
                neighborTile->parent = currentTile;

                if (!isInOpenList) {
                    openList.push(neighborTile);
                }
            }
        }
    }
}

// no path
return vector<Tile*>();
