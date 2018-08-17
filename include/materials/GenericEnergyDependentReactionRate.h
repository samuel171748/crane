/****************************************************************/
/*                      DO NOT MODIFY THIS HEADER               */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*              (c) 2010 Battelle Energy Alliance, LLC          */
/*                      ALL RIGHTS RESERVED                     */
/*                                                              */
/*              Prepared by Battelle Energy Alliance, LLC       */
/*              Under Contract No. DE-AC07-05ID14517            */
/*              With the U. S. Department of Energy             */
/*                                                              */
/*              See COPYRIGHT for full restrictions             */
/****************************************************************/
#ifndef GENERICENERGYDEPENDENTREACTIONRATE_H_
#define GENERICENERGYDEPENDENTREACTIONRATE_H_

#include "Material.h"
/* #include "LinearInterpolation.h" */
#include "SplineInterpolation.h"

class GenericEnergyDependentReactionRate;

template <>
InputParameters validParams<GenericEnergyDependentReactionRate>();

class GenericEnergyDependentReactionRate : public Material
{
public:
  GenericEnergyDependentReactionRate(const InputParameters & parameters);

protected:
  virtual void computeQpProperties();

  SplineInterpolation _coefficient_interpolation;

  Real _r_units;
  MaterialProperty<Real> & _reaction_rate;
  MaterialProperty<Real> & _d_k_d_en;
  std::string _sampling_format;
  const MaterialProperty<Real> & _reduced_field;
};

#endif // GenericEnergyDependentReactionRate_H_
