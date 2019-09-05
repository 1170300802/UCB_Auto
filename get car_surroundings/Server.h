# include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
#include <iostream>
#ifndef VEHICLE_H
#define VEHICLE_H
class Vehicle{
    public:
        Vehicle(double x, double y, double yaw, double v_x, double v_y, double yaw_rate);
        const long getId();
        const vector<double> getState();
    private:
        long id;
        vector<double> State;//小车的状态，目前默认
};
#endif;
#ifndef SERVER_H
#define SERVER_H
class Server{
    private:
        Server(){}
        static Server * serverInstance;
        map<long,  vector<Vehicle>>  surroundings;//一个map容器，将每个小车的信息存储起来
        vector<Vehicle> cars;//存储所有小车
    public:
        static Server* getInstance();
        vector<Vehicle> getSurroundingVehicles(long id);
        Vehicle getCar(long id);
        void addCar(Vehicle car);//添加小车
};
#endif