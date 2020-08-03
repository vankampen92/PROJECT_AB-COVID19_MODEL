#include <MODEL.h>

#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv.h>

int function (double t, const double y[], double dydt[], void *params)
{
  int i,k, j;
  int Q; 
  
  Parameter_Table * Table = (Parameter_Table *)params;

  Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; /* Ex: 11 times 4 */

  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  for (j=0; j<Table->No_of_LOCAL_POPULATIONS; j++) { 
    /* Total human local population j-th */
    
    Table->N0 = Total_Local_Population_N0( y, j, Table );
    Table->N1 = Total_Local_Population_N1( y, j, Table );
    Table->N2 = Total_Local_Population_N2( y, j, Table );
    Table->N3 = Total_Local_Population_N3( y, j, Table );

    n0S = Table->n0S+j*Q; n0E = Table->n0E+j*Q;   n0I1 = Table->n0I1+j*Q; n0I2 = Table->n0I2+j*Q;
    n0A = Table->n0A+j*Q; n0Ad = Table->n0Ad+j*Q; n0Y = Table->n0Y+j*Q; n0R = Table->n0R+j*Q;
    a0I = Table->a0I+j*Q; a0R = Table->a0R+j*Q;   a0D  = Table->a0D+j*Q;

    n1S = Table->n1S+j*Q; n1E = Table->n1E+j*Q;   n1I1 = Table->n1I1+j*Q; n1I2 = Table->n1I2+j*Q;
    n1A = Table->n1A+j*Q; n1Ad = Table->n1Ad+j*Q; n1Y = Table->n1Y+j*Q; n1R = Table->n1R+j*Q;
    a1I = Table->a1I+j*Q; a1R = Table->a1R+j*Q;   a1D  = Table->a1D+j*Q;

    n2S = Table->n2S+j*Q; n2E = Table->n2E+j*Q;   n2I1 = Table->n2I1+j*Q; n2I2 = Table->n2I2+j*Q;
    n2A = Table->n2A+j*Q; n2Ad = Table->n2Ad+j*Q; n2Y = Table->n2Y+j*Q; n2R = Table->n2R+j*Q;
    a2I = Table->a2I+j*Q; a2R = Table->a2R+j*Q;   a2D  = Table->a2D+j*Q;

    n3S = Table->n3S+j*Q; n3E = Table->n3E+j*Q; n3I1 = Table->n3I1+j*Q; n3I2 = Table->n3I2+j*Q;
    n3A = Table->n3A+j*Q; n3Ad = Table->n3Ad+j*Q;   n3Y = Table->n3Y+j*Q; n3R = Table->n3R+j*Q;
    a3I = Table->a3I+j*Q; a3R = Table->a3R+j*Q; a3D  = Table->a3D+j*Q;

    #include <include.ODE_sys_SEI1I2AAdYR_AGE.c>

    #include <include.ODE_sys_SEI1I2AAdYR_AGE_MPOP.c>
  }
  
  return GSL_SUCCESS;
}
