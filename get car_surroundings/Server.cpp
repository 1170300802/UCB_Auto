#include<iostream>
#include<vector>
#include"Server.h"
#include <math.h>
#include<map>
#define RANGE 100
using namespace std;
Vehicle::Vehicle(long id, double x, double y, double yaw, double v_x, double v_y, double yaw_rate) {
	this->State.push_back(x);
	this->State.push_back(y);
	this->State.push_back(yaw);
	this->State.push_back(v_x);
	this->State.push_back(v_y);
	this->State.push_back(yaw_rate);
	this->id = id;
}
bool Vehicle:: operator==(Vehicle& vehicle){
	if (this->id == vehicle.id)
        {
            return true;
        }
        return false;
}

Server* Server::serverInstance(NULL);

const long Vehicle::getId() {
	return id;
}

const vector<double> Vehicle:: getState() {
	return State;
}

Vehicle Server::getCar(long id) {
	return cars[id];
}

Server* Server::getInstance() {
	if (serverInstance == NULL) {
		serverInstance = new Server();
	}
	return serverInstance;
}

void Server::addCar(Vehicle car) {
	this->cars.push_back(car);
}
vector<Vehicle> Server::getSurroundingVehicles(long id) {
	if(surroundings.find(id) != surroundings.end()){
		return surroundings.at(id);
	}
	Vehicle *veichle = NULL;
	vector<Vehicle> surrounding;
	for (int i = 0; i < cars.size(); i++) {
		if (id == cars[i].getId()) {
			veichle = &cars[i];
		}
	}
	double center_x = veichle->getState()[0];
	double center_y = veichle->getState()[1];
	for (int i = 0; i < cars.size(); i++) {
		if (id != cars[i].getId() &&
			(fabs(pow((double)(cars[i].getState()[0] - center_x), 2.0) + pow((double)(cars[i].getState()[1] - center_y), 2.0) - RANGE) <= 1e-4)) {
			surrounding.push_back(cars[i]);
		}
	}
	surroundings.insert(pair<long, vector<Vehicle> >(id, surrounding));
	return surrounding;
}
int main() {
	cout << "hello world" << endl;
}
