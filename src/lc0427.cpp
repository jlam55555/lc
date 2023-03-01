/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/

class Solution {
  using Board = std::vector<std::vector<int>>;

public:
  Node *construct(Board &grid, int r, int c, int s) {
    for (int i{}; i < s; ++i) {
      for (int j{}; j < s; ++j) {
        if (grid[r + i][c + j] != grid[r][c]) {
          s >>= 1;
          return new Node{
              false,
              false,
              construct(grid, r, c, s),
              construct(grid, r, c + s, s),
              construct(grid, r + s, c, s),
              construct(grid, r + s, c + s, s),
          };
        }
      }
    }

    return new Node{
        !!grid[r][c],
        true,
    };
  }

  Node *construct(Board &grid) { return construct(grid, 0, 0, grid.size()); }
};
