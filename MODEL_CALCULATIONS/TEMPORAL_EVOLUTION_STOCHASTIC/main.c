/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                            David Alonso, 2018 (c)                         */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <Include/MODEL.h>

#include "global.h"


gsl_rng * r; /* Global generator defined in main.c */

/* This code calculates ODE model temporal evolution for a range COVID19 models

   Compilation (see makefile variable MODEL):

   . ~$ make 

   Exectution:
   
   Execution example plotting the temporal evolution of the full list of output variables (non-model state variables): 
   
   . ~$ ./SEI1I2AAdYR_AGE_MPOP -y0 3 -HN 1 -n 4 -v0 8 -v1 9 -v2 10 -v3 12 -G0 2 -G1 2 -tn 50 -t0 0.0 -t1 50.0 -t4 0 -tR 10 -tE 0.1 -xn 0 -xN 10000 -G2 1 -G3 0.0 -G4 50.0 -G5 1 -G6 0.0 -G7 6000.0 -H2 4.0 -H0 0.01 -H1 0.3 -H9 0.0001 -H37 0.001 -H38 0.05 -H39 0.2

    . ~$ ./SEI1I2AAdYR_AGE_MPOP -y0 3 -HN 4 -n 8 -v0 0 -v1 1 -v2 2 -v3 3 -v4 4 -v5 5 -v6 6 -v7 7 -G0 4 -G1 2 -tn 50 -t0 0.0 -t1 50.0 -t4 0 -tR 10 -tE 0.1 -xn 0 -xN 10000 -G2 1 -G3 0.0 -G4 50.0 -G5 1 -G6 0.0 -G7 1.0 -H2 4.0 -H0 0.01 -H1 0.3 -H9 0.0001 -H37 0.001 -H38 0.05 -H39 0.2

   -H0 [Kappa] -H1 [Beta] -H9 [p_0] -H37 [p_1] -H38 [p_2] -H39 [p_3]
   -xn TYPE of INITIAL CONDITION (0 from default values or Input Args; 
                                  1 at Random; 
                                  2 from fixed Point) 
   -xH INITIAL TOTAL POPULATION SIZE (controled also by -H3) 
   -t4 TYPE of TIME DEPENDENCE (0, no parameter time dependence). 

   See denition_OutPut_Variables.c (Genuine/Derived Output Variable): 
    -v0  
*/


int main(int argc, char **argv)
{
  int i; 
  Parameter_Table Table;
  Time_Control Time;
  Time_Dependence_Control Time_Dependence;
  P_ARG = &Table;

#include "default.c"
  
  /* Command line arguments */
  if(argc>1) ArgumentControl(argc,argv);

  /* Just to try an homogeneous contact matrix */ 
  Beta_00 = Beta;
  Beta_01 = Beta;
  Beta_02 = Beta;
  Beta_03 = Beta;
  
  Beta_10 = Beta;
  Beta_11 = Beta;
  Beta_12 = Beta;
  Beta_13 = Beta;
  
  Beta_20 = Beta;
  Beta_21 = Beta;
  Beta_22 = Beta;
  Beta_23 = Beta;
  
  Beta_30 = Beta;
  Beta_31 = Beta;
  Beta_32 = Beta;
  Beta_33 = Beta;

  #include "include.Output_Variables.default.aux.c"
  P_A_R_A_M_E_T_E_R___T_A_B_L_E___A_L_L_O_C(   &Table );
  P_A_R_A_M_E_T_E_R___T_A_B_L_E___U_P_L_O_A_D( &Table, Index_Output_Variables );
  printf(" Parameter_Table structure has been correctly allocated and initiated\n");

  /* B E G I N : Reserving memmory for Parameter Space */
  #include <include.Parameter_Space.default.aux.c>
  Parameter_Space * Space = (Parameter_Space *)calloc(1, sizeof(Parameter_Space));
  Parameter_Space_Alloc( Space, No_of_PARAMETERS, d);
  Parameter_Space_Initialization( Space, No_of_PARAMETERS, TOLERANCE, MAX_No_of_ITERATIONS,
    d, Index, Ranges, Acc);
  Parameter_Table_Index_Update(Index, No_of_PARAMETERS, &Table);
  Table.S = Space;
  printf(" Parameter_Space structure has been correctly allocated and initiated\n");
  /*     E N D : ------------------------------------- */

  if (TYPE_of_TIME_DEPENDENCE == 0) {
    printf(" Time_Control structure will be allocated: \n");
    printf(" %d output variables of length %d points will be allocated\n",
	   SUB_OUTPUT_VARIABLES, I_Time);
    T_I_M_E___C_O_N_T_R_O_L___A_L_L_O_C( &Time, &Table, I_Time);
    T_I_M_E___C_O_N_T_R_O_L___U_P_L_O_A_D( &Time, &Table, I_Time);
    printf(" Time_Control structure has been correctly allocated and set up\n");
  }
  else {
    #include <include.Time_Dependence_Control.default.aux.c>
    printf(" Time_Dependence_Control and Time_Control structures will be allocated: \n");
    printf(" %d output variables of length %d points will be allocated\n",
    SUB_OUTPUT_VARIABLES, I_Time);
    Time_Dependence_Control_Alloc(&Time, &Time_Dependence, &Table,
				  I_Time, TIME_DEPENDENT_PARAMETERS, No_of_COVARIATES);

    int No_of_EMPIRICAL_TIMES = 17;
    // Number of columns in the data files of time-dependent parameters
    Time_Dependence_Control_Upload(&Time, &Time_Dependence, &Table,
				   I_Time, No_of_EMPIRICAL_TIMES,
				   TIME_DEPENDENT_PARAMETERS, TYPE_of_TIME_DEPENDENCE,
				   TYPE_0_PARAMETERS, TYPE_1_PARAMETERS, TYPE_2_PARAMETERS,
				   No_of_COVARIATES,
				   dependent_parameter, forcing_pattern,
				   "File_of_Covariates.dat", Name_of_FILE[0] );
    printf(" Both Time_Control and Time_Dependence_Control structures have been\n");
    printf(" correctly allocated and set up\n");
  }
  
#if defined CPGPLOT_REPRESENTATION
  Table.CPG = A_C_T_I_V_A_T_E___C_P_G_P_L_O_T ( SUB_OUTPUT_VARIABLES, I_Time, 0, CPG_DRIVER_NAME);
  Table.CPG_STO = A_C_T_I_V_A_T_E___C_P_G_P_L_O_T (SUB_OUTPUT_VARIABLES, I_Time, 0, CPG_DRIVER_NAME);
  printf(" Two Parameter_CPGPLOT plotting structures have been correctly allocated and initiated\n");
  printf(" These will open two windows (or two ploting devices of the same kind)\n"); 
  printf(" Table.CPG will store deterministic dynamic variables to plot\n");
  printf(" Table.CPG_STO will store stochastic dynamic variables to plot\n");
  printf(" As a consquence, deterministic and stochastic dynamics can be plotted\n");
  printf(" on the same device to compare (as it is done here), or on the two different\n");
  printf(" devices (two different pdf files, for instance) if required.\n"); 
#endif

#include <gsl_random_number_Setup.c>
#if defined VERBOSE
  /* BEGIN: Checking Random Number Generator Setup */
  for(i=0; i<10; i++){
    printf( "f(%d)=%g, ", i, gsl_rng_uniform(r) );
    printf( "f_GAUS(%d)=%g\n", i, gsl_ran_gaussian(r, 1.0) );
  }
  printf("\n");//Press_Key();
  /*   END: Checking Random Number Generator Setup */
#endif

  double Initial_Exposed_Population = 100.0; 
  Initial_Condition_from_Value_into_Parameter_Table (&Table, Initial_Exposed_Population); 
  
  /* Deterministic Time Dynamics */
  M_O_D_E_L( &Table );

  /* Stochastic Time Dynamics: A number of stochastic realizations     */
  Parameter_Values_into_Parameter_Table(&Table);
  M_O_D_E_L___S_T_O( &Table );
  
  /* BEGIN : -------------------------------------------------------------------------
   *  You may need to redimension Index vector to include and save the full list of 
   *  model parameters.
   *  Redefinition of Parameter Space structure to allocate the whole parameter space
   *  Important note: 
   *  This operation can only be done at the end of a main file before freeing all mem-
   *  mory and ending. 
   *  (See also ./TEMPORAL_EVOLUTION_DETERMINISTIC/main.c) 
   */
  char boundary_File[80];
  sprintf(boundary_File, "boundary_Model_Parameter.c");
  write_Parameter_Table___RANGES___VALUES___LATEX ( "Latex_Parameter_Table.tex",
                                                    boundary_File,
						    &Table,
						    Space->P_MAX->data,
						    Space->P_min->data, Space->No_of_PARAMETERS);
  /*  END : ------------------------------------------------------------------------*/

  /* BEGIN : Freeing All Memmory * * * * * * * * * * * * * * */
#if defined CPGPLOT_REPRESENTATION
  P_A_R_A_M_E_T_E_R___C_P_G_P_L_O_T___F_R_E_E( Table.CPG, SUB_OUTPUT_VARIABLES );
  P_A_R_A_M_E_T_E_R___C_P_G_P_L_O_T___F_R_E_E( Table.CPG_STO, SUB_OUTPUT_VARIABLES );
  cpgclos();
#endif
  
#include <include.Parameter_Space.default.free.c>
  Parameter_Space_Free(Space, No_of_PARAMETERS); free( Space );

#include <include.Initial_Conditions.default.free.c>

#include <include.Output_Variables.default.free.c>
  
#include <include.Time_Dependence_Control.default.free.c>
  if (TYPE_of_TIME_DEPENDENCE == 0) T_I_M_E___C_O_N_T_R_O_L___F_R_E_E( &Time, &Table );
  else                        Time_Dependence_Control_Free( &Time_Dependence, &Table );
  
  P_A_R_A_M_E_T_E_R___T_A_B_L_E___F_R_E_E( &Table );
  /*  END : Freeing  All Memmory * * * * * * * * * * * * * * */

  printf("\nEnd of progam\n");
  return (0);
}
