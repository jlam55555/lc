class Robot {
public:
  int w, h, x, y, d, p, dist;

  Robot(int width, int height) {
    w = width - 1;
    h = height - 1;
    p = 2 * (w + h);
    d = 1;
    x = y = dist = 0;
  }

  void move(int num) {
    dist += num;
    dist %= p;
    if (dist && dist < w + 1) {
      d = 1;
      x = dist;
      y = 0;
    } else if (dist && dist < w + h + 1) {
      d = 0;
      x = w;
      y = dist - x;
    } else if (dist && dist < 2 * w + h + 1) {
      d = 3;
      x = w - (dist - w - h);
      y = h;
    } else {
      d = 2;
      x = 0;
      y = dist ? p - dist : 0;
    }
  }

  vector<int> getPos() { return {x, y}; }

  string getDir() {
    switch (d) {
    case 0:
      return "North";
    case 1:
      return "East";
    case 2:
      return "South";
    case 3:
      return "West";
    }
    throw invalid_argument{""};
  }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
