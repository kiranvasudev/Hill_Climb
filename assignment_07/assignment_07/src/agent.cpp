/*
 * Daniel Vázquez
 * Aritificial Intelligence for Robotics
 * SS 2016
 * Assignment 7
 *
 * agent.cpp
 * */
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <agent.hpp>
#include <matplotlibcpp.h>

Agent::Agent(vector<City> cities):cities(cities)
{
	
    
}

Agent::~Agent()
{

}

void Agent::run()
{
	//example
    print_cities(cities);
    save_cities_image(cities, 1);
    
    //TODO
}

void Agent::print_cities(vector<City>& cities) {
    
    std::vector<double> x, y;
    for (int i = 0; i < cities.size(); i++) {
         x.push_back(cities[i].get_x());
         y.push_back(cities[i].get_y());
    }
    
    // Plot line from given x and y data. 
    matplotlibcpp::plot(x, y);
    matplotlibcpp::show();
}

void Agent::save_cities_image(vector<City>& cities, int file_counter) {

    std::vector<double> x, y;
    for (int i = 0; i < cities.size(); i++) {
         x.push_back(cities[i].get_x());
         y.push_back(cities[i].get_y());
    }
    
    // Plot line from given x and y data. 
    matplotlibcpp::plot(x, y);
    string file = "salesman_" + to_string(file_counter) + ".png";
    matplotlibcpp::save(file);
}



vector<City> Agent::hillClimb(vector<City> cities) {
    //TODO
}

void Agent::random_restart_hill_climb() {

   //TODO 
   //HINT: 
   //		std::srand ( unsigned ( std::time(0) ) );
   //		random_shuffle(cities.begin(), cities.end());

        
}
