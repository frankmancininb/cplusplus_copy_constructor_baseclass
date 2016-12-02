// ConsoleApplication15.cpp : Defines the entry point for the console application.
//Write a Named Point class with three members: two floating point values for the coordinates on an X-Y plane, 
//and a name represented as a 'char *'. Assume that this class will be used for some sort of wargame or 
//simulation program that treats the world as flat 
//and that these named points will be used to represent things like cities, battlefields, etc.

#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
class point {
private:
	unsigned int x, y;
	char *name;

public:
	point(int xin, int yin, char *namein) {
		x = xin;
		y = yin;
		this->name = namein;
	}
	point(const point & obj) {
		x = obj.x;
		y = obj.y;
		this->name = obj.name;
	}
	
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	char *getName() {
		return name;
	}
	void setName(char *reset_name) {
		name = reset_name;
	}

	

};
class city :public point {
private:
	char * cityname, *newtest;

public:
	//city(int x, int y, char * name):point( x, y, name ) {
		
	//}
	city(int x, int y, char *cityName):point( x, y, cityname)
	{
		 
		cityname = (char  *)calloc(strlen(cityName) + 1, sizeof(char));
		strcpy_s(cityname, sizeof( cityname ) +1, cityName);
		setName(cityname);

		newtest = new char[sizeof(cityname) + 1];

		strcpy_s(newtest, sizeof(cityname) + 1, cityName);
	}
	city(const city &obj) :point(obj) {
		cityname = (char  *)calloc(strlen(obj.cityname) + 1, sizeof(char));
		strcpy_s(cityname, sizeof(cityname) + 1, obj.cityname);
		setName(cityname);

		newtest = new char[sizeof(cityname) + 1];

		strcpy_s(newtest, sizeof(cityname) + 1, obj.cityname);

	}
	~city() {
		free( cityname );
		delete newtest;
	}
};

int main()
{

	point p( 1, 2, "lalal" ), *p_ptr = NULL;
	p_ptr = new point(1, 2, "lala");

	delete p_ptr;

	city city1(2, 4, "pppp");

	city *city2 = new city(city1);

	//delete city1;
	delete city2;

}

