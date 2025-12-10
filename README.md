# TSP-Exact-Solver-CPP

A C++ brute-force solver for the Traveling Salesperson Problem (TSP) in 3D space.  
It guarantees the globally optimal path by evaluating all possible permutations (**Complexity: O(N!)**).

## 🚀 Getting Started

### Prerequisites
- A C++ compiler (GCC/G++ recommended)

### Compilation
Navigate to the project root and compile the source code:
```bash
g++ src/main.cpp -o tsp_solver
```

Usage
You can run the program interactively or pass an input file:

✅ Verification & Testing
To ensure the reliability of the algorithm, the output has been validated using known geometrical patterns.

Test Case: Linear Check (Sanity Test)
Scenario: Points are arranged on a straight line along the X-axis. The algorithm must visit them in order of distance (from closest to farthest) to minimize travel.

Input Data: You can find this dataset in tests/linear_test.txt:
Start:(0, 0, 0)
P1: (10, 0, 0)
P2: (5, 0, 0)
P3: (20, 0, 0)

Expected Output:
Path: Start -> P2 (5) -> P1 (10) -> P3 (20)
Distance: 20.00

Actual Output:
Optimal Path found!
Start: (0, 0, 0)
 -> (5.00, 0.00, 0.00) -> (10.00, 0.00, 0.00) -> (20.00, 0.00, 0.00)

Total Minimum Distance: 20.00
Status: PASSED


🛠 Technologies
Language: C++
Libraries: STL (vector, algorithm, cmath, iomanip)
Method: Brute-force (Permutations)

📄 License
This project is licensed under the MIT License - see the LICENSE file for details.
