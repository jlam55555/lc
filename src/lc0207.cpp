struct Node {
  int in = 0;
  list<int> out;
};

// 6    1    7
//  \ / | \ / \
//   2  3  4   7
//        /
//      5
//     /
//    6

// 1 3 4 2 5
// 1 2 3 4 5
// 1 4 3 2 5

// 4 -> 5
// 1 -> 2
// 1 -> 4
// 1 -> 3
// 6 -> 2
// 5 -> 6
// 5 -> 1

// -- N1: out has len 3, in = 0
// -- N2: out has len 0, in = 0
// -- N3: out has len 0, in = 0
// -- N4: out has len 1, in = 0
// -- N5: out has len 0, in = 0
// -- N6: out has len 1, in = 0

// 0 -> 1
// 1 -> 0

// N0:

// orphans: N6 N1 N3 N4 N5

class Solution {
public:
  // returns true if loop found, false otherwise
  bool dfs(vector<Node> &courses, vector<bool> &temp_visited,
           vector<bool> &visited, int index) {
    // if already completely explored, then we know there's no loop
    if (visited[index]) {
      return false;
    }
    // if already visited on this path, then we know there's a loop
    if (temp_visited[index]) {
      return true;
    }

    temp_visited[index] = true;

    for (auto edge : courses[index].out) {
      if (dfs(courses, temp_visited, visited, edge)) {
        return true;
      }
    }

    // now we've reached the end of a graph
    temp_visited[index] = false;
    visited[index] = true;
    return false;
  }

  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {

    // generate digraph
    vector<Node> courses(numCourses);
    vector<bool> temp_visited(numCourses, false);
    vector<bool> visited(numCourses, false);

    for (auto it : prerequisites) {
      courses[it[1]].out.push_back(it[0]);
    }

    for (int i = 0; i < numCourses; ++i) {
      if (dfs(courses, temp_visited, visited, i)) {
        return false;
      }
    }

    return true;
  }
  //     Kahn's algorithm
  //     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

  //         // generate digraph
  //         vector<Node> courses(numCourses);

  //         for (auto it : prerequisites) {
  //             courses[it[1]].out.push_back(it[0]);
  //             ++courses[it[0]].in;
  //         }

  //         // topological sort
  //         queue<int> orphans;
  //         int accounted_for = 0;
  //         for (int i = 0; i < numCourses; ++i) {
  //             if (!courses[i].in) {
  //                 orphans.push(i);
  //                 ++accounted_for;
  //             }
  //         }

  //         while (!orphans.empty()) {
  //             Node course = courses[orphans.front()];
  //             orphans.pop();
  //             for (auto dep_course : course.out) {
  //                 if (!--courses[dep_course].in) {
  //                     orphans.push(dep_course);
  //                     ++accounted_for;
  //                 }
  //             }
  //         }

  //         return accounted_for == numCourses;

  //     }
};
