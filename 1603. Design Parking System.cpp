class ParkingSystem {
public:
    int car[3];
    ParkingSystem(int a, int b, int c) {
        car[0]=a; car[1]=b; car[2]=c;

    }
    
    bool addCar(int k) {
        if(car[k-1]>0){
            car[k-1]--;
            return 1;
        }
        return 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */