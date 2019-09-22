#include<iostream>
#include<vector>
#include"Server.h"
#include <math.h>
#include<map>
#define RANGE 10
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

Server* Server::serverInstance(NULL);

const long Vehicle::getId() {
	return id;
}

const vector<double> Vehicle:: getState() {
	return State;
}

Vehicle Server::getCar(long id) {
	for (int i = 0; i <cars.size();i++){
        if(cars[i].getId() == id){
            return cars[i];
        }
    }
    throw "there does not exist such a car!";
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
	Vehicle *veichle = NULL;
	vector<Vehicle> surrounding;
	for (int i = 0; i < cars.size(); i++) {
		if (id == cars[i].getId()) {
			veichle = &cars[i];
		}
	}
	double center_x = veichle->getState()[0];
	cout << (veichle->getState()[1] )<< endl;
	double center_y = veichle->getState()[1];
	for (int i = 0; i < cars.size(); i++) {
		if (id != cars[i].getId() &&
			(sqrt(pow(cars[i].getState()[0] - center_x, 2.0) + pow(cars[i].getState()[1] - center_y, 2.0) )<= RANGE) ) {
			surrounding.push_back(cars[i]);
		}
	}
	surroundings.insert(pair<long, vector<Vehicle> >(id, surrounding));
	return surrounding;
}
int main() {
	cout << "hello world" << endl;
	Server* ser = Server::getInstance();
	Vehicle* car1 = new Vehicle(1,0,0,0,0,0,0);
	ser->addCar(*car1);
	Vehicle* car2 = new Vehicle(2,11,0,0,0,0,0);
	ser->addCar(*car2);
	Vehicle* car3 = new Vehicle(3,9,0,0,0,0,0);
	ser->addCar(*car3);
	cout << (ser->getSurroundingVehicles(1).size() )<< endl;
	system("pause");
}
