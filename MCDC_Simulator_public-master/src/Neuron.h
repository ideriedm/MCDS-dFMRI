//!  Class to declare several types of neurons =============================================================/
/*!
*   \details   Class derived from an Obstacle. Defines neurons
*   \author    Inès de Riedmatten
*   \date      January 2023 
*   \version   1.42
=================================================================================================*/


#ifndef NEURON_H
#define NEURON_H

#include "Axon.h"
#include "sphere.h"
#include "simerrno.h"
#include <iostream>
using namespace std;

/// @brief 
class Neuron : public Obstacle
{
public:

    static int nb_neurons;                  /* Number of neurons in the simulation*/
    std::vector<Axon> dendrites;            /* Contains all the dendrites of the neuron*/
    Sphere soma;                            /* Soma of the neuron */

    Neuron();

    ~Neuron();

    Neuron(std::vector<Axon> dendrites, Sphere soma);
    Neuron(std::vector<Axon> dendrites, Eigen::Vector3d soma_center, double soma_radius);
    
    /* Copy constructor */
    Neuron(Neuron const &neuron);

    friend std::ostream& operator<<(std::ostream& os, const Neuron& neuron)
    {
        os << "Neuron radius: " << neuron.soma.radius << ', center:' << neuron.soma.center << ', nb: ' << neuron.nb_neurons;
        return os;
    }


    bool checkCollision(Walker &walker, Eigen::Vector3d &step, double &step_lenght, Collision &colision);

};


#endif // NEURON_H
