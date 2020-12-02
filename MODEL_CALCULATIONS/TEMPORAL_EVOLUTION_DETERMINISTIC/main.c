/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                            David Alonso, 2018 (c)                         */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <Include/MODEL.h>

#include "global.h"

gsl_rng * r; /* Global generator defined in main.c */

/* This code calculates ODE model temporal evolution for a range of sexual-transmitted AIDS-HIV models

   Compilation (example 1):

   . ~$ make MODEL=SEI1I2AYR

   Typical Parameters Values:

   / -I0 0   -H0 1.0   -m0 0.8   -M0 1.2     -A0 0.01      // Parameter: Kappa
   / -I1 1   -H1 100.0  -m1 96.0  -M1 120.0   -A1 0.1      // Parameter: Mu
   / -I2 2   -H2 100.0  -m2 96.0  -M2 120.0   -A2 0.1      // Parameter: Beta
   / -I3 3   -H3 9.0   -m3 0.0   -M3 19.0    -A3 0.01      // Parameter: b
   / -I4 4   -H4 9.0   -m4 0.0   -M4 100.0   -A4 0.01      // Parameter: Phi
   / -I5 5   -H5 0.1   -m5 0.0   -M5 0.99    -A5 0.01      // Parameter: Eps_I
   / -I6 6   -H6 0.7   -m6 0.0   -M6 0.99    -A6 0.01      // Parameter: Eps_Y
   / -I7 7   -H7 0.003  -m7 0.0   -M7 0.015   -A7 0.0001   // Parameter: Sigma
   / -I8 8   -H8 0.001  -m8 0.0   -M8 0.005   -A8 0.0001   // Parameter: Gamma_1
   / -I9 9   -H9 2.0    -m9 0.5   -M9 4.0     -A9 0.1      // Parameter: p_0
   / -I10 10 -H10 0.2    -m10 0.05 -M10 0.2    -A10 0.01   // Parameter: Alpha
   / -I11 11 -H11 5.0   -m11 1.0  -M11 50.0   -A11 0.1     // Parameter: Delta
   / -I12 12 -H12  0.01 -m12 0.0  -M12 0.05   -A12 0.01    // Parameter: Gamma_2
   
   Exectution:

   a. No time dependence (-t4 0):

   . ~$ ./SEI1I2AYR -y0 0 -HN 1 -n 9 -v0 0 -v1 1 -v2 2 -v3 6 -v4 7 -v5 8 -v6 9 -v7 10 -v8 12 -G0 3 -G1 3 -tn 5000 -t0 0.0 -t1 50.0 -t4 0 -xn 0 -xN 1000000 

   . ~$ ./SEI1I2AYR_AGE -y0 1 -HN 1 -n 6 -v0 0 -v1 1 -v2 8 -v3 9 -v4 10 -v5 12 -G0 3 -G1 2 -tn 5000 -t0 0.0 -t1 50.0 -t4 0 -xn 0 -xN 1000000 

   . ~$ ./SEI1I2AAdYR_AGE -y0 2 -HN 1 -n 6 -v0 8 -v1 9 -v2 10 -v3 7 -v4 12 -v5 13 -G0 2 -G1 3 -tn 500 -t0 0.0 -t1 50.0 -t4 0 -xn 0 -xN 1000000  -H2 4.0

   . ~$ ./SEI1I2AAdYR_AGE_MPOP -y0 3 -HN 5 -n 6 -v0 8 -v1 9 -v2 10 -v3 7 -v4 12 -v5 13 -G0 3 -G1 2 -tn 500 -t0 0.0 -t1 50.0 -t4 0 -xn 0 -xN 1000000 -H2 4.0

   . ~S ./SEI1I2AYR -y0 0 -sP 20 -I0 21 -H21 1.0 -m0 0.8 -M0 1.2 -A0 0.01  -I1 0 -H0 90.0 -m1 96.0 -M1 120.0 -A1 0.1  -I2 8 -H8 100.0 -m2 96.0 -M2 120.0 -A2 0.1  -I3 12 -H12 9  -m3 1.0 -M3 20.0  -A3 0.01  -I4 7  -H7  9.0  -m4 0.0 -M4 100.0 -A4 0.01  -y0 1 -n 6 -v0 7 -v1 8 -v2 9 -v3 10 -v4 11 -v5 12 -G0 3 -G1 2 -tn 100 -t0 2000.0 -t1 2250 -t4 0 -xn 0 -xN 1.0E+05 -G5 1 -G6 0.0 -G7 0.3

   b. Time-dependent parameters (-t4 1):

   -xn TYPE of INITIAL CONDITION (0 from default values or Input Args; 1 at Random; 2 from fixed/stationary Point)
   -xN INITIAL TOTAL POPULATION SIZE at t0.
   -t4 TYPE of TIME DEPENDENCE (0, no parameter time dependence). If the TYPE of TIME DEPENDENCE input argument is greater than 0, time dependence parameters are at play.
   See, for instance, ./Definition_Numerical_Integration/XWSILD-YSILD/deterministic_time_dynamics.c

   See file definition_OutPut_Variables.c for full -v?? input argument code definitions. Examples are:

    -v0  13 Total Population 
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
    printf(" Borth Time_Control and Time_Dependence_Control structures have been\n");
    printf(" correctly allocated and set up\n");
  }

  /* B E G I N : Re-allocating Time Control for interpolating more points in numerical
                 integration. Time_0 and Time_1 are not allowed to chage. Only I_Time         */
  /* T_I_M_E___C_O_N_T_R_O_L___F_R_E_E( &Time, &Table );                                      */
  /* I_Time = 100;                                                                            */
  /* for (i=0; i<SUB_OUTPUT_VARIABLES; i++) {                                                 */
  /*   free(Table.Matrix_Output_Variables[i]);                                                */
  /*   Table.Matrix_Output_Variables[i] = (double *)malloc( I_Time * sizeof(double) );        */
  /* }                                                                                        */
  /* printf("\n");                                                                            */
  /* printf(" Time_Control structure will be re-allocated for longer numerical integration: \n"); */
  /* printf(" (between %g and %g)\n", Time_0, Time_1);                                        */
  /* printf(" %d output variables of length %d points will be allocated\n",                   */
  /* 	   SUB_OUTPUT_VARIABLES, I_Time);                                                     */
  /* T_I_M_E___C_O_N_T_R_O_L___A_L_L_O_C( &Time, &Table, I_Time);                             */
  /* T_I_M_E___C_O_N_T_R_O_L___U_P_L_O_A_D( &Time, &Table, I_Time);                           */
  /* printf(" Time_Control structure has been correctly re-allocated and set up\n");          */
  /*     E N D : ---------------------------------------------------------------------------- */

#if defined CPGPLOT_REPRESENTATION
  Table.CPG = A_C_T_I_V_A_T_E___C_P_G_P_L_O_T ( SUB_OUTPUT_VARIABLES, I_Time, 0, CPG_DRIVER_NAME);
  printf(" Parameter_CPGPLOT plotting structure has been correctly allocated and initiated\n");
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

  /* Initial conditions from values at the initial time ( -xn 0 ) */

  // double Initial_Population = Table.N; 
  double Initial_Exposed_Population = 1.0; 
  // double Initial_Assymptomatic_Population = 1.0; 
  Initial_Condition_from_Value_into_Parameter_Table (&Table, Initial_Exposed_Population); 
    /* Initial_Condition_from_Initial_Values_into_Parameter_Table (&Table,                        */
    /* 							     Initial_Population,                  */
    /* 							     Initial_Exposed_Population,          */
    /* 							     Initial_Assymptomatic_Population );  */
  M_O_D_E_L( &Table );

  /* BEGIN : --------------------------------------------------------------------------------
     Reading and plotting empirical population evolution
  */
  /* int No_of_Rows;                                                                       */
  /* char ** Name_of_Rows;                                                                 */
  /* double ** City_Data  = (double **)calloc(1,  sizeof(double *) );                      */
  /*        City_Data[0]  = (double * )calloc(16,  sizeof(double  ) );                     */
  /* double * Time_Vector = (double * )calloc(16, sizeof(double  ) );                      */
  /* Reading_Standard_Data_Matrix_from_File( "City_Population_1955_2018_Antananarivo.dat", */
  /* 					  City_Data,                                       */
  /* 					  &No_of_Rows, 16,                                 */
  /* 					  0, Name_of_Rows,                                 */
  /* 					  1, Time_Vector );                                */
  /* Table.CPG->type_of_Symbol = 24;                                                       */
  /* Table.CPG->color_Index    = 3;      // 3: green                                       */
  /* int SAME = 1; */
  /* CPGPLOT___X_Y___S_C_A_T_T_E_R_E_D___S_A_M_E___P_L_O_T ( Table.CPG, SAME,              */
  /* 							  16, Time_Vector, City_Data[0],   */
  /* 							  "Year",                          */
  /* 							  "Total Population",              */
  /* 							  "",                              */
  /* 							  Table.CPG->CPG_SCALE_X,          */
  /* 							  Table.CPG->CPG_SCALE_Y );        */
  /* free(Time_Vector); free(City_Data[0]); free(City_Data);                               */
  /* END: -----------------------------------------------------------------------------------
   */
  /* BEGIN : -------------------------------------------------------------------------
     Redimensioning Index vector to include and save the full list of model parameters
     Redefinition of Parameter Space structure to allocate the whole parameter space
     This operation can only be done at the end of a main file (before freeing memmory
     and ending).
  */
  /* Parameter_Space_Free(Space, No_of_PARAMETERS); free(Space);  */

  /* No_of_PARAMETERS = MODEL_PARAMETERS_MAXIMUM; */
  /* for(i=0; i<No_of_PARAMETERS; i++) Table.Index[i] = i; */

  /* Space = (Parameter_Space *)calloc(1, sizeof(Parameter_Space)); */
  /* Parameter_Space_Alloc( Space, No_of_PARAMETERS, d); */
  /* Parameter_Space_Initialization( Space, No_of_PARAMETERS, TOLERANCE, MAX_No_of_ITERATIONS, */
  /* 				  d, Index, Ranges, Acc); */
  /* printf(" Parameter_Space structure has been correctly allocated and initiated\n"); */

  char boundary_File[80];
  sprintf(boundary_File, "Parameter_Model_Boundary.c");
  write_Parameter_Table___RANGES___VALUES___LATEX ( "Latex_Parameter_Table.tex",
                                                    boundary_File,
                                                    &Table,
                                                    Space->P_MAX->data,
                                                    Space->P_min->data, Space->No_of_PARAMETERS );
  /*  END : ------------------------------------------------------------------------*/

  /* BEGIN : Freeing All Memmory * * * * * * * * * * * * * * */
#if defined CPGPLOT_REPRESENTATION
  P_A_R_A_M_E_T_E_R___C_P_G_P_L_O_T___F_R_E_E( Table.CPG, SUB_OUTPUT_VARIABLES );
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
