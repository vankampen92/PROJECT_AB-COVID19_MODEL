#include <MODEL.h>

#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv.h>

int function (double t, const double y[], double dydt[], void *params)
{
  int i,k;
  double X, Y;

  Parameter_Table * Table = (Parameter_Table *)params;

  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  /* Total human population */
  Table->N0 = Total_Population_N0( y, Table );
  Table->N1 = Total_Population_N1( y, Table );
  Table->N2 = Total_Population_N2( y, Table );
  Table->N3 = Total_Population_N3( y, Table );
  
  #include <include.ODE_sys_SEI1I2AAdYR_AGE.c>
  
  return GSL_SUCCESS;
}
