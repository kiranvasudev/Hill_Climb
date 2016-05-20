/*
 * Daniel Vázquez, Kiran Vasudev, Patrick Nagel
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
#include <math.h>

Agent::Agent(vector<City> cities) :
		cities(cities) {

}

Agent::~Agent() {

}

void Agent::run() {
	//example
	//print_cities(cities);
	//save_cities_image(cities, 1);

	random_restart_hill_climb();
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
	City start_city = cities[0];
	vector<City> journeyPath;

	journeyPath.push_back(cities[0]);

	double min;
	int minIndex;
	double totalDistance = 0;

	while (cities.size() != 1) {
		min = calculateDistance(cities[0].get_x(), cities[0].get_y(),
				cities[1].get_x(), cities[1].get_y());
		minIndex = 1;
		for (std::vector<City>::iterator it = cities.begin() + 2;
				it != cities.end(); ++it) {
			double distance = calculateDistance(cities[0].get_x(),
					cities[0].get_y(), (*it).get_x(), (*it).get_y());
			if (distance < min) {
				min = distance;
				minIndex = it - cities.begin();
			}
		}

		totalDistance += min;

		iter_swap(cities.begin(), cities.begin() + minIndex);
		journeyPath.push_back(cities[0]);
		cities.erase(cities.begin() + minIndex);
	}

	double lastDistance = abs(
			(journeyPath.back().get_x() - cities[0].get_x())
					+ (journeyPath.back().get_y() - cities[0].get_y()));
	cities.erase(cities.begin());
	totalDistance += lastDistance;

	cout << journeyPath.size() << endl;
	cout << "total distance " << totalDistance << endl;

//	for (std::vector<City>::iterator it = journeyPath.begin();
//						it != journeyPath.end(); ++it) {
//			cout << (*it).get_name() << endl;
//		}

	return journeyPath;
}

double Agent::calculateDistance(double lon1, double lat1, double lon2,
		double lat2) {
	double r = 6372.8;
	lat1 = (lat1 * M_PI) / 180.;
	lat2 = (lat2 * M_PI) / 180.;
	double dLat = lat2 - lat1;
	double dLon = ((lon2 * M_PI) / 180.) - ((lon1 * M_PI) / 180.);
	double a = pow(sin(dLat / 2), 2)
			+ pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
	double c = 2 * asin(sqrt(a));
	return r * c;
}

void Agent::random_restart_hill_climb() {

	//TODO
	//HINT:
	//		std::srand ( unsigned ( std::time(0) ) );

	int counter = 0;
	while (counter != 20) {
		random_shuffle(cities.begin(), cities.end());

		vector<City> journeyPath = hillClimb(cities);

		for (std::vector<City>::iterator it = journeyPath.begin();
				it != journeyPath.end(); ++it) {
			cout << (*it).get_name() << endl;
		}
		cout << cities.size() << endl;
		cout << "-------------------------------------------" << endl;

		print_cities(journeyPath);
		counter += 1;
	}
}
