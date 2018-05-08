#include "MotorVehicle.h"
#include <string>


//Make the motorvehicle object. Then assign it's variables that it's passed through

MotorVehicle::MotorVehicle(Category vehicleType, unsigned int numDoors,
                 unsigned int maxPassengers, double engineHP,
                 std::string licensePlate) : vehicleType(vehicleType), doors(numDoors), maxPassengers(maxPassengers), plate(licensePlate)
		{			
			//Non const variables are being assigned here because... I can ;)
			currentPassengers = 0;
			horsepower = engineHP;
		};

    bool MotorVehicle::addPassenger(bool overrideLimit)
    {
	if(getSpotsRemaining() >= 1 || overrideLimit)	//If the number of spots is bigger than 0 OR if overrideLimit is true
	{
		currentPassengers += 1;			//Add passengers
		return true;				//And return true
	}else
	{
		return false;				//Else the function is gonna be false
	}
	
    }

    
    // Gets max passengers of car
    unsigned int MotorVehicle::getMaxPassengers() const
    {
	return maxPassengers;
    }

    // Returns the current passengers in the car
    unsigned int MotorVehicle::getNumPassengers() const
    {
	return currentPassengers;
    }

    // Finds out how many seats are left in the car
    int MotorVehicle::getSpotsRemaining() const
    {
	return maxPassengers - currentPassengers;
    }

    // Returns the number of doors the car has
    unsigned int MotorVehicle::getNumDoors() const 
    {
	return doors;
    }

    // Returns the car's horse power
    double MotorVehicle::getHorsepower() const
    {
	return horsepower;
    }

    // Changes the horse power of the engine
    void MotorVehicle::setHorsepower(double newHP)
    {
	horsepower = newHP;
    }

    //! What is the vehicle license plate?
    std::string MotorVehicle::getLicense() const
    {
	return plate;
    }
