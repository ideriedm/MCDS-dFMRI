#include "Neuron.h"
#include "dynamic_sphere.h"
#include "constants.h"
#include "Eigen/Dense"
#include <iostream>
#include "simerrno.h"

using namespace Eigen;
using namespace std;

int Neuron::nb_neurons = 0;
Neuron::Neuron()
{
    id = nb_neurons++;
}

Neuron::~Neuron()
{
    nb_neurons--;
}

Neuron::Neuron(std::vector<Axon> dendrites_, Sphere soma_)
{
    id = nb_neurons++;
    dendrites = dendrites_;          
    soma = soma_;
}


Neuron::Neuron(std::vector<Axon> dendrites_, Eigen::Vector3d soma_center, double soma_radius=10e-6)
{
    id = nb_neurons++;
    dendrites = dendrites_;          
    soma = Sphere(soma_center, soma_radius);
}

Neuron::Neuron(const Neuron &neuron)
{
    id = nb_neurons++;
    dendrites = neuron.dendrites;           
    soma = neuron.soma;
}


bool Neuron::checkCollision(Walker &walker, Eigen::Vector3d &step, double &step_lenght, Collision &colision)
{

}

