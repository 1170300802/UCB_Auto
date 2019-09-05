#include<iostream>
#include<vector>
#include <Server.h>
#include <math.h>
#include<map>
#define RANGE 1000
using namespace std;
Vehicle:: Vehicle(double x, double y, double yaw, double v_x, double v_y, double yaw_rate){
    this->State.push_back(x);
    this->State.push_back(y);
    this->State.push_back(yaw);
    this->State.push_back(v_x);
    this->State.push_back(v_y);
    this->State.push_back(yaw_rate);
}

Server* Server:: serverInstance(NULL);

Server* Server:: getInstance(){
    if(serverInstance == NULL){
        serverInstance = new Server();
    }
    return serverInstance;
}

void Server:: addCar(Vehicle car){
    this->cars.push_back(car);
}
vector<Vehicle> Server:: getSurroundingVehicles(long id){
    Vehicle *veichle;
    vector<Vehicle> surrounding;
    for(int i = 0; i < cars.size(); i++){
        if(id == cars[i].getId()){
            veichle = &cars[i];
        }
    }
    double center_x = veichle->getState()[0];
    double center_y = veichle->getState()[1];
    for(int i = 0; i < cars.size(); i++){
        if(id != cars[i].getId() && 
        ( (cars[i].getState[0]-center_x)^2 + (cars[i].getState[1]-center_y)^2 <= RANGE ) ) {
            surrounding.push_back(cars[i]);
        }
    }
    surroundings.insert(pair(id, surrounding));
}
int main(){
    cout<<"hello world"<<endl;
}



