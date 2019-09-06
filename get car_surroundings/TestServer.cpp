#include <gtest/gtest.h>
#include "Server.h"
TEST(Server_test, get_surroundings){
    Server* server = Server::getInstance();
    Vehicle *v1 = new Vehicle(1, 0, 0, 20, 0, 0, 0);
    Vehicle *v2 = new Vehicle(2, 0, 150, 20, 0, 0, 0);
    Vehicle *v3 = new Vehicle(3, 0, 100, 20, 0, 0, 0);
    Vehicle *v4 = new Vehicle(4, 50, 50, 20, 0, 0, 0);
    Vehicle *v5 = new Vehicle(5, 40, 40, 20, 0, 0, 0);
    Vehicle *v6 = new Vehicle(6, 30, 10, 20, 0, 0, 0);
    server->addCar(*v1);
    server->addCar(*v2);
    server->addCar(*v3);
    server->addCar(*v4);
    server->addCar(*v5);
    server->addCar(*v6);
    vector<Vehicle> surrounding;
    surrounding.push_back(*v3);
    surrounding.push_back(*v6);
    ASSERT_EQ(surrounding, server->getSurroundingVehicles(1));
    
}