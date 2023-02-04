class ParkingSystem {
  int spots_[4]{};

public:
  ParkingSystem(int big, int medium, int small) {
    spots_[1] = big;
    spots_[2] = medium;
    spots_[3] = small;
  }

  bool addCar(int carType) { return --spots_[carType] >= 0; }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
