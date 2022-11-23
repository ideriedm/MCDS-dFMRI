//!  CylinderGammaDistribution Class =============================================================/
/*!
*   \details   Class to construct a substrate taken from a Gamma distribution of radiis placed in
*              a single voxel structure.
*   \author    Jasmine Nguyen-Duc
*   \date      Septembre 2022
*   \version   0.2
=================================================================================================*/

#ifndef AXONGAMMADISTRIBUTION_H
#define AXONGAMMADISTRIBUTION_H

#include "Eigen/Core"
#include <vector>
#include "constants.h"
#include "simerrno.h"
#include <iostream>
#include "Axon.h"
#include "dynamic_sphere.h"


class AxonGammaDistribution 
{
public:

    double dyn_perc;                                /*!< Percentage of dynamic cylinders that swell                                 */ 
    double volume_inc_perc;                         /*!< Percentage of Volume increase of cylinders that start to swell       */                                       
    std::vector<Axon> axons;    /*!< Cylinder vector                                                            */
    unsigned num_obstacles;                         /*!< number of cylnders fit inside the substrate                                */
    double alpha;                                   /*!< alpha coefficient of the Gamma distribution                                */
    double beta;                                    /*!< beta coefficient of the gamma distribution                                 */
    double icvf;                                    /*!< Achieved intra-celular volum fraction in the substrate                     */
    float min_radius;                                /*!< Minimum radius to be sampled from the gamma distribution                  */

    Eigen::Vector3d min_limits;                     /*!< voxel min limits (if any) (bottom left corner)                             */
    Eigen::Vector3d max_limits;                     /*!< voxel max limits (if any)                                                  */
    

    /*!
     *  \param P_ Cylinder origin
     *  \param Q_ cylinder direction.
     *  \param radius_ cylinder's radius
     *  \param scale scale factor for the values passed. Useful when reading a file.
     *  \brief Initialize everything.
     */
    AxonGammaDistribution (){}

    /*!
     *  \param P_ Cylinder origin
     *  \param Q_ cylinder direction.
     *  \param radius_ cylinder's radius
     *  \param scale scale factor for the values passed. Useful when reading a file.
     *  \brief Initialize everything.
     */
    AxonGammaDistribution(double, double, unsigned, double, double,double,Eigen::Vector3d &,Eigen::Vector3d &, float min_radius = 0.001);
     
     /*!
     *  \brief Shows a small histogram of the gamma distribution
    */
    void displayGammaDistribution();
    /*!
     *  \brief Samples and constructs a Gamma distribution
    */
    void createGammaSubstrate();

    void updateGammaSubstrate();

    /*!
     *  \brief Prints the cylinders positions in a file or output stream.
     *  \param out ostream where to write the info.
    */
    void printSubstrate(std::ostream& out);

private:

    /*!
     *  \brief Checks for collision between inside a voxel (with periodic boundaries)
     *  \param cyl cylinder to check collision with
     *  \param min_limits Voxel min limits.
     *  \param max_limits Voxel max limits.
     *  \param cylinders_list cylinders already added.
     *  \param min_distance that two cylinders can be close to.
    */
    bool checkForCollition(Axon ax, Eigen::Vector3d min_limits, Eigen::Vector3d max_limits, std::vector<Axon>& axons_list, double &min_distance);

    /*!
     *  \brief Auxiliary function to check the BOundary collision
     *  \param cyl cylinder to check collision with.
     *  \param min_limits Voxel min limits.
     *  \param max_limits Voxel max limits.
     *  \param cylinders_list cylinders already added.
    */
    void checkBoundaryConditions(Axon ax, std::vector<Axon>& axons_list, Eigen::Vector3d min_limits, Eigen::Vector3d max_limits);

    /*!
     *  \brief Computes Intra Celular Volum Fraction given the voxel limits and the list of added cylinders.
     *  \param cylinders List of included cylinders.
     *  \param min_limits voxel min limits.
     *  \param max_limits voxel max limits.
    */
    double  computeICVF(std::vector<Axon> &axons, Eigen::Vector3d &min_limits, Eigen::Vector3d &max_limits, int &num_no_repeat);

    void computeMinimalSize(std::vector<double> radiis, double icvf_, Eigen::Vector3d& l);


};

#endif // AXONGAMMADISTRIBUTION_H
