#include <MODEL.h>

double Force_of_Infection_Sto ( Community * P, int * y, int age, Parameter_Table * Table )
{
  /* This function calculates the force of infection for a given age in a patch characterized  
     by y[] as the state vector in that patch. 
  */
  int i, j, Q; 
  double Y;
  double Force;

  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  switch(age)
    {
    case 0: 
      Force = (Table->Beta_00 * Table->b / (double)P->N0 * (Table->Phi * y[n0I1] + y[n0A] + (1.0-Table->Eps_I) * (y[n0I2]+y[n0Ad]) + (1.0-Table->Eps_Y) * y[n0Y] ) +
               Table->Beta_01 * Table->b / (double)P->N1 * (Table->Phi * y[n1I1] + y[n1A] + (1.0-Table->Eps_I) * (y[n1I2]+y[n1Ad]) + (1.0-Table->Eps_Y) * y[n1Y] ) +
               Table->Beta_02 * Table->b / (double)P->N2 * (Table->Phi * y[n2I1] + y[n2A] + (1.0-Table->Eps_I) * (y[n2I2]+y[n2Ad]) + (1.0-Table->Eps_Y) * y[n2Y] ) +
               Table->Beta_03 * Table->b / (double)P->N3 * (Table->Phi * y[n3I1] + y[n3A] + (1.0-Table->Eps_I) * (y[n3I2]+y[n3Ad]) + (1.0-Table->Eps_Y) * y[n3Y] )
	       );
      break;
    case 1:
      Force = (Table->Beta_10 * Table->b / (double)P->N0 * (Table->Phi * y[n0I1] + y[n0A] + (1.0-Table->Eps_I) * (y[n0I2]+y[n0Ad]) + (1.0-Table->Eps_Y) * y[n0Y] ) +
               Table->Beta_11 * Table->b / (double)P->N1 * (Table->Phi * y[n1I1] + y[n1A] + (1.0-Table->Eps_I) * (y[n1I2]+y[n1Ad]) + (1.0-Table->Eps_Y) * y[n1Y] ) +
               Table->Beta_12 * Table->b / (double)P->N2 * (Table->Phi * y[n2I1] + y[n2A] + (1.0-Table->Eps_I) * (y[n2I2]+y[n2Ad]) + (1.0-Table->Eps_Y) * y[n2Y] ) +
               Table->Beta_13 * Table->b / (double)P->N3 * (Table->Phi * y[n3I1] + y[n3A] + (1.0-Table->Eps_I) * (y[n3I2]+y[n3Ad]) + (1.0-Table->Eps_Y) * y[n3Y] )
	       );
      break;
    case 2:
      Force = ( Table->Beta_20 * Table->b / (double)P->N0 * (Table->Phi * y[n0I1] + y[n0A] + (1.0-Table->Eps_I) * (y[n0I2]+y[n0Ad]) + (1.0-Table->Eps_Y) * y[n0Y] ) +
                Table->Beta_21 * Table->b / (double)P->N1 * (Table->Phi * y[n1I1] + y[n1A] + (1.0-Table->Eps_I) * (y[n1I2]+y[n1Ad]) + (1.0-Table->Eps_Y) * y[n1Y] ) +
                Table->Beta_22 * Table->b / (double)P->N2 * (Table->Phi * y[n2I1] + y[n2A] + (1.0-Table->Eps_I) * (y[n2I2]+y[n2Ad]) + (1.0-Table->Eps_Y) * y[n2Y] ) +
                Table->Beta_23 * Table->b / (double)P->N3 * (Table->Phi * y[n3I1] + y[n3A] + (1.0-Table->Eps_I) * (y[n3I2]+y[n3Ad]) + (1.0-Table->Eps_Y) * y[n3Y] )
		);
      break;
    case 3:
      Force = ( Table->Beta_30 * Table->b / (double)P->N0 * (Table->Phi * y[n0I1] + y[n0A] + (1.0-Table->Eps_I) * (y[n0I2]+y[n0Ad]) + (1.0-Table->Eps_Y) * y[n0Y] ) +
		Table->Beta_31 * Table->b / (double)P->N1 * (Table->Phi * y[n1I1] + y[n1A] + (1.0-Table->Eps_I) * (y[n1I2]+y[n1Ad]) + (1.0-Table->Eps_Y) * y[n1Y] ) +
		Table->Beta_32 * Table->b / (double)P->N2 * (Table->Phi * y[n2I1] + y[n2A] + (1.0-Table->Eps_I) * (y[n2I2]+y[n2Ad]) + (1.0-Table->Eps_Y) * y[n2Y] ) +
		Table->Beta_33 * Table->b / (double)P->N3 * (Table->Phi * y[n3I1] + y[n3A] + (1.0-Table->Eps_I) * (y[n3I2]+y[n3Ad]) + (1.0-Table->Eps_Y) * y[n3Y] )
		);
      break;
      
    default:
      printf(" This code can only consider 4 different age classes\n");
      printf(" age can be between 0 and 3, but age = %d\n", age);
      Press_Key();
    }
      
  return(Force);
}

