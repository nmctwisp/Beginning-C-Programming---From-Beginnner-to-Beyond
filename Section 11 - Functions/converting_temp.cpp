#include <iostream>
#include <cmath>
using namespace std;

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR FUNCTION PROTOTYPES BELOW THIS LINE----
double fahrenheit_to_celsius(double fahrenheit_temperature);
double fahrenheit_to_kelvin(double fahrenheit_temperature);

//----WRITE YOUR FUNCTION PROTOTYPES ABOVE THIS LINE----
//----DO NOT MODIFY THE CODE BELOW THIS LINE----

void temperature_conversion(double fahrenheit_temperature) {
    
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR FUNCTION CALLS BELOW THIS LINE----
    
    double celsius_temperature = fahrenheit_to_celsius(fahrenheit_temperature);
    double kelvin_temperature = fahrenheit_to_kelvin(fahrenheit_temperature);
    
    //----WRITE YOUR FUNCTION CALLS ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    
    cout << "The fahrenheit temperature " << fahrenheit_temperature << " degrees is equivalent to " << celsius_temperature << " degrees celsius and " << kelvin_temperature << " degrees kelvin.";
}

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR FUNCTION DEFINITIONS BELOW THIS LINE----

double fahrenheit_to_celsius(double fahrenheit_temperature) {
    double ctemp = (5.0/9.0) * (fahrenheit_temperature - 32);
    return round(ctemp);
}

double fahrenheit_to_kelvin(double fahrenheit_temperature) {
    double ktemp = fahrenheit_to_celsius(fahrenheit_temperature) + 273;
    return round(ktemp);
}


