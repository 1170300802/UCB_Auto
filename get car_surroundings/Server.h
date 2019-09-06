# include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
#include <iostream>
#ifndef VEHICLE_H
#define VEHICLE_H
class Vehicle {
public:
	Vehicle(long id, double x, double y, double yaw, double v_x, double v_y, double yaw_rate);
	const long getId();
	const vector<double> getState();
	bool operator==(Vehicle& vehicle);
private:
	long id;
	vector<double> State;//С����״̬��ĿǰĬ��
};
#endif;
#ifndef SERVER_H
#define SERVER_H
class Server {
private:
	Server() {}
	static Server * serverInstance;
	map<long, vector<Vehicle> >  surroundings;//һ��map��������ÿ��С������Ϣ�洢����
	vector<Vehicle> cars;//�洢����С��
public:
	static Server* getInstance();
	vector<Vehicle> getSurroundingVehicles(long id);
	Vehicle getCar(long id);
	void addCar(Vehicle car);//����С��
};
#endif
