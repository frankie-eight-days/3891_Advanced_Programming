/*!
 * @file      MotorVehicle.h
 * @brief     Declaration of the MotorVehicle class.
 *
 * @author    Andrew House <andrew.w.h.house@mun.ca>
 * @copyright (c) 2017 Andrew House. All rights reserved.
 * @license   Apache License, Version 2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License.  You may obtain a copy
 * of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

// The following lines are "header guards": they prevent us from redefining the
// Course class if we include this header file more than once. They effectively
// tell the pre-processor, "only pay attention to the contents of this file if
// you haven't seen them before".
#if !defined(MOTORVEHICLE_H)
#define MOTORVEHICLE_H

#include <string>

/**
 * A basic representation of a motor vehicle that could be
 * used for a traffic simulation or video game.
 */
class MotorVehicle
{
public:
    enum class Category
    {
        Motorcycle,
        Car,
        SUV,
        Jeep,
        Pickup,
        Bus,
        Tractor,
        Semi
    };

    MotorVehicle(Category vehicleType, unsigned int numDoors,
                 unsigned int maxPassengers, double engineHP,
                 std::string licensePlate);


    bool addPassenger(bool overrideLimit = false);

    unsigned int getMaxPassengers() const;

    unsigned int getNumPassengers() const;

    int getSpotsRemaining() const;

    unsigned int getNumDoors() const;

    double getHorsepower() const;

    void setHorsepower(double newHP);

    std::string getLicense() const;

private:
    const Category vehicleType;
    const unsigned int maxPassengers;
    const unsigned int doors;
    const std::string plate;
    double horsepower;
    unsigned int currentPassengers;
};

#endif // the end of the MOTORVEHICLE_H header guard

