/*
 * Project: TSP Exact Solver (3D)
 * Author: SalvatoreDev15
 * Description:
 * Brute-force implementation of the Traveling Salesperson Problem (TSP) in a 3D space.
 * It calculates the shortest possible route that visits each point exactly once and returns to the origin.
 *
 * Complexity: O(n!) - Suitable for small datasets (n <= 12).
 * Tech Stack: C++, STL (vector, algorithm, cmath).
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip> //For nice output formatting

using namespace std;

//Represents a point in 3D space
class Point3D {

    public:
        Point3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

        double getX() const { return x; }
        double getY() const { return y; }
        double getZ() const { return z; }

        //Overload < operator for lexicographical sorting (required by next_permutation)
        bool operator<(const Point3D& other) const {
            if (x != other.x) return x < other.x;
            if (y != other.y) return y < other.y;
            return z < other.z;
    }
    
    private:
        double x, y, z;
};

//Structure to hold the result of the algorithm
struct TSPResult {
    double minDistance;
    vector<Point3D> bestPath;
};

//Calculates the Euclidean distance between two points in 3D space
double calcDistance(const Point3D& a, const Point3D& b) {
    double dx = a.getX() - b.getX();
    double dy = a.getY() - b.getY();
    double dz = a.getZ() - b.getZ();

    // Using Pythagoras theorem: sqrt(dx^2 + dy^2 + dz^2)
    return std::sqrt(dx*dx + dy*dy + dz*dz);
}

/**
 * Solves the TSP problem using a brute-force approach (O(n!)).
 * @param start: The starting point (Player).
 * @param points: The list of destinations to visit.
 * @return TSPResult containing the shortest distance and the ordered path.
*/
TSPResult solveTSP(const Point3D& start, vector<Point3D>& points) {
    double minDistance = numeric_limits<double>::max();
    vector<Point3D> bestPath;

    //Sort points to prepare for next_permutation
    //(Start with the lexicographically smallest permutation)
    sort(points.begin(),points.end());

    do {
        double currentDistance = calcDistance(start, points[0]);
        
        // Sum distances between consecutive points in the current permutation
        for (size_t i = 0; i < points.size() - 1; ++i) {
            currentDistance += calcDistance(points[i], points[i + 1]);
        }

        // Update minimum if current path is better
        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            bestPath = points;
        }

    } while (next_permutation(points.begin(), points.end()));

    return {minDistance, bestPath};
}

//Handles user interaction to get the list of points
vector<Point3D> getPointsFromUser() {
    int numPoints;
    vector<Point3D> points;

    cout << "Enter number of points to visit: ";
    //Basic validation loop
    while (!(cin >> numPoints) || numPoints < 1) {
        cin.clear(); //Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Discard invalid input
        cerr << "Invalid input. Please enter an integer > 0: ";
    }

    cout << "Enter coordinates for " << numPoints << " points (x y z):" << endl;
    for (int i = 0; i < numPoints; ++i) {
        double x, y, z;
        cout << "Point " << (i + 1) << ": ";
        //We could add validation here too, but let's keep it simple for now
        cin >> x >> y >> z;
        points.emplace_back(x, y, z);
    }
    
    return points;
}

void printResults(const TSPResult& result) {
    cout << "---------------------------" << endl;
    cout << fixed << setprecision(2);
    cout << "Optimal Path found!" << endl;
    cout << "Start: (0, 0, 0)" << endl; //Assuming origin for now
    
    for (const auto& p : result.bestPath) {
        cout << " -> (" << p.getX() << ", " << p.getY() << ", " << p.getZ() << ")";
    }
    cout << "\n\nTotal Minimum Distance: " << result.minDistance << endl;
    cout << "---------------------------" << endl;
}

int main(int argc, char const *argv[]){
   
    cout << "=== 3D TSP Exact Solver ===" << endl;
    cout << "Complexity: O(n!). Recommended n <= 12.\n" << endl;

    Point3D player(0.0, 0.0, 0.0);
    vector<Point3D> targets = getPointsFromUser();

    cout << "\nComputing shortest path..." << endl;

    TSPResult result = solveTSP(player, targets);

    printResults(result);
    return 0;
}

