#include <MODEL.h>

double definition_Scan_Function( Parameter_Table * P )
{
  double x;
  double * y;

  int j = P->OUTPUT_VARIABLE_INDEX[0];

  x = definition_OutPut_Variables( j, y, 0.0, P );

  return (x);
}

double definition_OutPut_Variables(int j, double * y, const double t, Parameter_Table * Table)
{
  int i;
  double x = 0.0;

  /* Definition of the numerical order, from 0 to n, of model variables */
  #include <Model_Variables_Code.Include.c>

  /* Genuine output variables are those that derive from the state of the system and,
   * therefore, should be evaluated as a funcion of system state variables
   */
  if (j < OUTPUT_VARIABLES_GENUINE) {
    /* Derived output variables from model dynamic variables and parameters */
    switch(j)
    {
    case 0:  x = Fraction_of_Susceptible_Population ( y, Table );
      break;
    case 1:  x = Fraction_of_Exposed_Population( y, Table );
      break;
    case 2:  x = Fraction_of_Pre_Symptomatic_Population( y, Table );
      break;
    case 3:  x = Fraction_of_Strongly_Infected_Population( y, Table );
      break;
    case 4:  x = Fraction_of_A_Symptomatic_Population( y, Table );
      break;
    case 5:  x = Fraction_of_Seriously_Infected_Population( y, Table );
      break;
    case 6:  x = Fraction_of_Recovered_Population( y, Table );
      break;
    case 7:  x = Total_Disease_Prevalence( y, Table ); /* 7: Disease Prevalence or Fraction of Total Infected Population */
      break;
    case 8:  x = Accumulated_Number_of_Detected_Infected( y, Table );
      break;
    case 9:  x = Accumulated_Number_of_Detected_Recovered( y, Table );
      break;
    case 10: x = Accumulated_Number_of_Detected_Deaths( y, Table );
      break;
    case 11: x = Total_Infected_Population( y, Table );
      break;
    case 12: x = Total_Detected_Infected_Population( y, Table );
      break;
    case 13: x = Total_Population( y, Table );
      break;
    
    default:
      printf(" INVALID VARIABLE CODE in ./definition_OutPut_Variables.c (variable = %d)\n", j);
      printf(" Output Variables range from 0 to 12: Program will exit!  ");
      printf(" Press any key..."); getchar();
      exit(0);
    }
  }
  /* The last MODEL_STATE_VARIABLES output variables are the MODEL_STATE_VARIABLES */
  else {
    j -= OUTPUT_VARIABLES_GENUINE; /* #defined in MODEL.h */
    assert( j < Table->MODEL_STATE_VARIABLES );
    x = y[j];
  }

  return (x);
}
