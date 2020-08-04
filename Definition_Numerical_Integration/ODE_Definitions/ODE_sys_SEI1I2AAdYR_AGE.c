#include <MODEL.h>

#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv.h>

int function (double t, const double y[], double dydt[], void *params)
{
  int i,k;
  double X, Y;
  double Force_of_Infection_0;
  double Force_of_Infection_1;
  double Force_of_Infection_2;
  double Force_of_Infection_3; 
  
  Parameter_Table * Table = (Parameter_Table *)params;

  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  /* Total human population */
  Table->N0 = Total_Population_N0( y, Table );
  Table->N1 = Total_Population_N1( y, Table );
  Table->N2 = Total_Population_N2( y, Table );
  Table->N3 = Total_Population_N3( y, Table );

  Force_of_Infection_0 = (Table->Beta_00 * Table->b / Table->N0 * (Table->Phi * y[n0I1] + y[n0A] + (1.0-Table->Eps_I) * (y[n0I2]+y[n0Ad]) + (1.0-Table->Eps_Y) * y[n0Y] ) +
			    Table->Beta_01 * Table->b / Table->N1 * (Table->Phi * y[n1I1] + y[n1A] + (1.0-Table->Eps_I) * (y[n1I2]+y[n1Ad]) + (1.0-Table->Eps_Y) * y[n1Y] ) +
			    Table->Beta_02 * Table->b / Table->N2 * (Table->Phi * y[n2I1] + y[n2A] + (1.0-Table->Eps_I) * (y[n2I2]+y[n2Ad]) + (1.0-Table->Eps_Y) * y[n2Y] ) +
			    Table->Beta_03 * Table->b / Table->N3 * (Table->Phi * y[n3I1] + y[n3A] + (1.0-Table->Eps_I) * (y[n3I2]+y[n3Ad]) + (1.0-Table->Eps_Y) * y[n3Y] )
			    );
    
  Force_of_Infection_1 = (Table->Beta_10 * Table->b / Table->N0 * (Table->Phi * y[n0I1] + y[n0A] + (1.0-Table->Eps_I) * (y[n0I2]+y[n0Ad]) + (1.0-Table->Eps_Y) * y[n0Y] ) +
			  Table->Beta_11 * Table->b / Table->N1 * (Table->Phi * y[n1I1] + y[n1A] + (1.0-Table->Eps_I) * (y[n1I2]+y[n1Ad]) + (1.0-Table->Eps_Y) * y[n1Y] ) +
			  Table->Beta_12 * Table->b / Table->N2 * (Table->Phi * y[n2I1] + y[n2A] + (1.0-Table->Eps_I) * (y[n2I2]+y[n2Ad]) + (1.0-Table->Eps_Y) * y[n2Y] ) +
			  Table->Beta_13 * Table->b / Table->N3 * (Table->Phi * y[n3I1] + y[n3A] + (1.0-Table->Eps_I) * (y[n3I2]+y[n3Ad]) + (1.0-Table->Eps_Y) * y[n3Y] )
			  );
  
  Force_of_Infection_2 = ( Table->Beta_20 * Table->b / Table->N0 * (Table->Phi * y[n0I1] + y[n0A] + (1.0-Table->Eps_I) * (y[n0I2]+y[n0Ad]) + (1.0-Table->Eps_Y) * y[n0Y] ) +
			   Table->Beta_21 * Table->b / Table->N1 * (Table->Phi * y[n1I1] + y[n1A] + (1.0-Table->Eps_I) * (y[n1I2]+y[n1Ad]) + (1.0-Table->Eps_Y) * y[n1Y] ) +
			   Table->Beta_22 * Table->b / Table->N2 * (Table->Phi * y[n2I1] + y[n2A] + (1.0-Table->Eps_I) * (y[n2I2]+y[n2Ad]) + (1.0-Table->Eps_Y) * y[n2Y] ) +
			   Table->Beta_23 * Table->b / Table->N3 * (Table->Phi * y[n3I1] + y[n3A] + (1.0-Table->Eps_I) * (y[n3I2]+y[n3Ad]) + (1.0-Table->Eps_Y) * y[n3Y] )
			   );
  
  Force_of_Infection_3 = ( Table->Beta_30 * Table->b / Table->N0 * (Table->Phi * y[n0I1] + y[n0A] + (1.0-Table->Eps_I) * (y[n0I2]+y[n0Ad]) + (1.0-Table->Eps_Y) * y[n0Y] ) +
			   Table->Beta_31 * Table->b / Table->N1 * (Table->Phi * y[n1I1] + y[n1A] + (1.0-Table->Eps_I) * (y[n1I2]+y[n1Ad]) + (1.0-Table->Eps_Y) * y[n1Y] ) +
			   Table->Beta_32 * Table->b / Table->N2 * (Table->Phi * y[n2I1] + y[n2A] + (1.0-Table->Eps_I) * (y[n2I2]+y[n2Ad]) + (1.0-Table->Eps_Y) * y[n2Y] ) +
			   Table->Beta_33 * Table->b / Table->N3 * (Table->Phi * y[n3I1] + y[n3A] + (1.0-Table->Eps_I) * (y[n3I2]+y[n3Ad]) + (1.0-Table->Eps_Y) * y[n3Y] )
			   );
  
  #include <include.ODE_sys_SEI1I2AAdYR_AGE.c>
  
  return GSL_SUCCESS;
}
