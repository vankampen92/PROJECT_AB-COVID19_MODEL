/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                            David Alonso, 2018 (c)                         */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <Include/MODEL.h>

#include "global.h"

gsl_rng * r; /* Global generator defined in main.c */

/* This code calculates ODE model temporal evolution for a range of sexual-transmitted AIDS-HIV models

   Compilation:

   . ~$ make

   Exectution:
   Important Notice: X and Y ranges are given as input parameters. If they are not conveniently 
   chosen, you may not see the plot, because the plot functions never plot out of ranges values.  
   
   Execution example just one plot (No of infectious bites per human per year, EIR):

   . ~$ ./SI-XW -S0 4 -n 1 -v0 12 -tn 60 -t0 0.0 -t1 150.0 -t4 0 -tR 10 -xn 0 -H3 50000 -M4 2.0 -G0 1 -G1 1 -G2 1 -G3 0.0 -G4 150.0 -G5 1 -G6 0.0 -G7 150.0

   Execution example plotting the full list of model state variables (First example showing demographic stochasticity is not relevant at all. Second example showing its relevance!) 
   
   . ~$ ./SI-XW -S0 4 -n 4 -v0 0 -v1 1 -v2 2 -v3 3 -tn 100 -t0 0.0 -t1 100.0 -t4 0 -tR 10 -xn 0 -H3 50000 -M4 2.0 -G0 2 -G1 2 -G2 1 -G3 0.0 -G4 100.0 -G5 1 -G6 0.0 -G7 100000.0

   . ~$ ./SI-XW -S0 4 -n 4 -v0 0 -v1 1 -v2 2 -v3 3 -tn 500 -t0 0.0 -t1 2000.0 -t4 0 -tR 10 -xn 0 -H3 25000 -M4 0.4 -M0 0.15 -M3 0.2 -G0 2 -G1 2 -G2 1 -G3 0.0 -G4 2000.0 -G5 1 -G6 0.0 -G7 1000.0
   
   Execution example plotting only infectious humans and mosquitoes: 

   . ~$ ./SI-XW -S0 4 -n 2 -v0 1 -v2 3 -tn 100 -t0 0.0 -t1 100.0 -t4 0 -tR 10 -xn 0 -H3 50000 -M4 2.0 -G0 1 -G1 2 -G2 1 -G3 0.0 -G4 100.0 -G5 1 -G6 0.0 -G7 100000. (litte stochaticity)

   . ~$ ./SI-XW -S0 4 -n 2 -v0 1 -v1 3 -tn 100 -t0 0.0 -t1 10000.0 -t4 0 -tR 10 -xn 0 -H3 250000 -M4 0.4 -M0 0.15 -M3 0.2 -G0 1 -G1 2 -G2 1 -G3 0.0 -G4 10000.0 -G5 1 -G6 0.0 -G7 65000.0 (a lot of stochasticity)
   
   Execution example plotting the temporal evolution of the full list of output variables (non-model state variables): 
   
   . ~$ ./SI-XW -S0 4 -n 9 -v0 4 -v1 5 -v2 6 -v3 7 -v4 8 -v5 9 -v6 10 -v7 11 -v8 12 -G0 3 -G1 3 -tn 100 -t0 0.0 -t1 5000.0 -t4 0 -tR 10 -xn 0 -H3 25000 -M4 0.4 -M0 0.15 -M3 0.2 -G2 1 -G3 0.0 -G4 5000.0 -G5 1 -G6 0.0 -G7 1.5  (a lot of stochasticity)

   . ~$ ./SI-XW -S0 4 -n 9 -v0 4 -v1 5 -v2 6 -v3 7 -v4 8 -v5 9 -v6 10 -v7 11 -v8 12 -G0 3 -G1 3 -tn 100 -t0 0.0 -t1 300.0 -t4 0 -tR 10 -xn 0 -H3 50000 -M4 2.0 -G2 1 -G3 0.0 -G4 300.0 -G5 1 -G6 0.0 -G7 10.0 (litte stochaticity)

   -S0 SUB_MODEL_PARAMETERS to define a subparameter space to explore  
   -xn TYPE of INITIAL CONDITION (0 from default values or Input Args; 
                                  1 at Random; 
                                  2 from fixed Point) 
   -xH INITIAL TOTAL POPULATION SIZE (controled also by -H3) 
   -t4 TYPE of TIME DEPENDENCE (0, no parameter time dependence). If the TYPE of TIME DEPENDENCE input argument is greater than 0, different types of parameter time dependence are at play. See, for instance, ./Definition_Numerical_Integration/deterministic_time_dynamics.c

   See denition_OutPut_Variables.c (Genuine/Derived Output Variable): 
    -v0 0+4   Fraction of Infectious Humans (Disease Prevalence)
    -v1 1+4   Fraction of Infectious Mosquitoes
    -v2 2+4   Total Human Population
    -v3 3+4   Total Mosquito Population
    -v4 4+4   R_0
    -v5 5+4   Mosquito Vectorial Capacity
    -v6 6+4   Total Mosquitoes Density per Human
    -v7 7+4   Infectious Mosquitoes Density per Human
    -v8 8+4   Entomological Inoculation Rate (EIR). 
*/

int main(int argc, char **argv)
{
  int i; 
  Parameter_Space Space;
  Parameter_Table Table;
  Time_Control Time;
  Trend_Control * Tr;
  P_ARG = &Table;

#include "default.c"
  
  /* Command line arguments */
  if(argc>1) ArgumentControl(argc,argv);

  INITIAL_TOTAL_POPULATION    = H;                            
  INITIAL_MOSQUITO_POPULATION = m * INITIAL_TOTAL_POPULATION; 
  /* The two previous code lines overwrite any choice for -xH and -xM (initial values */ 
  /* for human and mosquito populations, respectively) from the list of  input        */
  /* arguments in favor of -H3 and -M4 arguments, which total human population        */
  /* (H), and density of mosquitoes per human (m), respectively.                      */ 
  P_A_R_A_M_E_T_E_R___T_A_B_L_E___A_L_L_O_C(   &Table );
  P_A_R_A_M_E_T_E_R___T_A_B_L_E___U_P_L_O_A_D( &Table );
  printf(" Parameter_Table structure has been correctly allocated and initiated\n");

  P_A_R_A_M_E_T_E_R___S_P_A_C_E___A_L_L_O_C( &Space, &Table );
  P_A_R_A_M_E_T_E_R___S_P_A_C_E___U_P_L_O_A_D( &Space, &Table, A_n, A_d);
  printf(" Parameter_Space structure has been correctly allocated and initiated\n");

  /* It the dynamics is temperature/rainful driven, the corresponding
     data structure should be also allocated and initiated here
     (at least, after initiating Parameter_Table structure)
  *//* */
  printf(" Time_Control structure will be allocated: \n");
  printf(" %d output variables of length %d points will be allocated\n",
	 SUB_OUTPUT_VARIABLES, I_Time);
  T_I_M_E___C_O_N_T_R_O_L___A_L_L_O_C( &Time, &Table, I_Time);
  T_I_M_E___C_O_N_T_R_O_L___U_P_L_O_A_D( &Time, &Table, I_Time);
  printf(" Time_Control structure has been correctly allocated and initiated\n");
  
  printf(" Trend_Control structure will be allocated: \n");
  Tr = (Trend_Control *)malloc( 1 * sizeof(Trend_Control) );
  T_R_E_N_D___C_O_N_T_R_O_L___U_P_L_O_A_D( Tr, &Table);
  int Input_Parameter = Tr->Tr_Input_Parameter;
  S_E_T_U_P___T_R_E_N_D___F_R_E_E___T_R_I_A_N_G_L_E (Tr, &Time, Input_Parameter );
  printf(" Trend_Control structure has been correctly allocated and initiated\n");

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
  
  /* Deterministic Time Dynamics */
  M_O_D_E_L( &Table );

  /* Stochastic Time Dynamics: A number of stochastic realizations     */
  values_Parameter_Model(&Table); /* Back to input argument parameters */ 
  M_O_D_E_L___S_T_O( &Table );
  
  /* BEGIN : -------------------------------------------------------------------------
   *  Redimensioning Index vector to include and save the full list of model parameters
   *  Redefinition of Parameter Space structure to allocate the whole parameter space
   *  Important note: 
   *  This operation can only be done at the end of a main file (before freeing mem-
   *  mory and ending). 
   */
  printf("Redimensioning Index vector to include and save the full list of model parameters.\n");
  printf("Accoringly, Parameter Space Struct is redefined to allocate the whole parameter space.\n");
  printf("Important note:\n"); 
  printf("\t\tThis operation can only be done at the end of a main file (before freeing mem-\n");
  printf("\t\tmory and ending).\n");
  printf("A latex table will be generated.\n"); 
  free(Table.Index);
  Table.Index = (int *)calloc( MODEL_PARAMETERS_MAXIMUM, sizeof(int) ); 
  P_A_R_A_M_E_T_E_R___S_P_A_C_E___F_R_E_E( &Space );
  SUB_MODEL_PARAMETERS = MODEL_PARAMETERS_MAXIMUM;
  P_A_R_A_M_E_T_E_R___S_P_A_C_E___A_L_L_O_C( &Space, &Table );
  P_A_R_A_M_E_T_E_R___S_P_A_C_E___U_P_L_O_A_D( &Space, &Table, A_n, A_d);
  char boundary_File[80];
  sprintf(boundary_File, "boundary_Model_Parameter.c");
  write_Parameter_Table___RANGES___VALUES___LATEX ( "Latex_Parameter_Table.tex",
                                                    boundary_File,
						    &Table,
						    Space.P_MAX->data,
						    Space.P_min->data, Space.nPar );
  /*  END : ------------------------------------------------------------------------*/

  /* BEGIN : Freeing All Memmory * * * * * * * * * * * * * * */
#if defined CPGPLOT_REPRESENTATION
  P_A_R_A_M_E_T_E_R___C_P_G_P_L_O_T___F_R_E_E( Table.CPG, SUB_OUTPUT_VARIABLES );
  P_A_R_A_M_E_T_E_R___C_P_G_P_L_O_T___F_R_E_E( Table.CPG_STO, SUB_OUTPUT_VARIABLES );
  cpgclos();
#endif
  T_R_E_N_D___C_O_N_T_R_O_L___F_R_E_E( Tr );
  T_I_M_E___C_O_N_T_R_O_L___F_R_E_E( &Time, &Table );
  P_A_R_A_M_E_T_E_R___S_P_A_C_E___F_R_E_E( &Space );
  P_A_R_A_M_E_T_E_R___T_A_B_L_E___F_R_E_E( &Table );
  /*  END : Freeing  All Memmory * * * * * * * * * * * * * * */

  printf("\nEnd of progam\n");
  return (0);
}
