/* Notice that Parameter_Table Struct depends and relies
   on the correct previous defintion of the structures
   Time_Control, Parameter_Model, and Parameter_Space
*/
typedef struct Parameter_Tableinfo
{
  /* Boolean Variable (see Time_Dependence_Control.c) */
  bool x_Bool; 

  /* Stochastic Realizations */
  int Realizations;

  /* * * Parameter Time Dependence Driven Dynamics * * */
  //#include "include.global.RainTemp.h"
  // RainTemp * R_T;

  //"include.Trend_Control.global.h"
  Trend_Control * Tr;

  /* * * Time_Control * * * */
  Time_Control * T;

  /* * * Time_Dependence_Control * * * */
  Time_Dependence_Control * TDC;

  /* * * Parameter_Model * * * */
  #include "include.Parameter_Model.global.h"
  Parameter_Model * P;
  //#include "include.Type_of_Model.global.h" /* Included within include.Parameter_Model.global.h" */

  #include "include.Initial_Conditions.global.h"
  Parameter_Space * IC_Space;

  #include "include.Error_Control.global.h"
  Parameter_Space * E_Space; 

  /* * * Parameter_Space * * * */
  /* Total Number of Input Model Parameters (as in assign....c and boundary_*.c functions) */
  int MODEL_INPUT_PARAMETERS;
  char ** Name_Parameters; // Name_Parameters  : Name Model Input Parameters
  char ** Code_Parameters;
  char ** Symbol_Parameters;
  char ** Symbol_Parameters_Greek_CPGPLOT;
  
  double * Default_Vector_Parameters;

  /* What follows defines a parameter sub-space within
     the whole parameter space
  */
  int * Index;             // Vector defining the parameter subset to explore   */
  double * Vector_Parameters;
  //#include <include.PARAMETER_SPACE.global.h>
  Parameter_Space * S;
  /* * * * * * * * * */

  /* Total Number of Model Output Variables (in defintion_OutPut_Variables.c file) */
  int MODEL_OUTPUT_VARIABLES;
  char ** Output_Variable_Name;
  char ** Output_Variable_Symbol;
  double * Default_Vector_Output_Variables;
  /* Subset of Output Variables */
  /* What follows defines a subset of output variables that will be saved, represented, etc
   */
  int SUB_OUTPUT_VARIABLES;
  int * OUTPUT_VARIABLE_INDEX;
  double * Vector_Output_Variables;
  double ** Matrix_Output_Variables;
  /* * * * * * * * * */

  /* Model Dynamic Variables */
  int TOTAL_No_of_DISEASE_STAGES;  /* Ex: 11 for SEI1I2AAdYR */
  int TOTAL_No_of_AGE_CLASSES;     /* Ex: 4                  */
  int No_of_DISEASE_STAGES;        /* Ex: 8 (without counting acummulating variables) */
  
  int MODEL_STATE_VARIABLES;
  char ** Model_Variable_Name;
  char ** Model_Variable_Symbol;

  int nS, nE, nI1, nI2, nA, nY, nR;
  int aI, aR, aD;

  int n0S, n0E, n0I1, n0I2, n0A, n0Ad, n0Y, n0R;
  int a0I, a0R, a0D;
  
  int n1S, n1E, n1I1, n1I2, n1A, n1Ad, n1Y, n1R;
  int a1I, a1R, a1D;
  
  int n2S, n2E, n2I1, n2I2, n2A, n2Ad, n2Y, n2R;
  int a2I, a2R, a2D;
  
  int n3S, n3E, n3I1, n3I2, n3A, n3Ad, n3Y, n3R;
  int a3I, a3R, a3D;
  
  int nTS, nTE, nTI1, nTI2, nTA, nTY, nTR;
  
  int K;
  
  int LI0;  /* First Infected Class */
  int LI;   /* Last Infected Class  */

  int L0I0;  /* First Infected Class */
  int L0I;   /* Last Infected Class  */

  int L1I0;  /* First Infected Class */
  int L1I;   /* Last Infected Class  */

  int L2I0;  /* First Infected Class */
  int L2I;   /* Last Infected Class  */

  int L3I0;  /* First Infected Class */
  int L3I;   

  int * L_0I0;   /* Label first infected class  (0: Children) */
  int * L_0I;    /* Label last infected  class  */
	  
  int * L_1I0;   /* Label first infected class  (1: Students) */
  int * L_1I;    /* Label last infected  class  */
	  
  int * L_2I0;   /* Label first infected class  (2: Workers) */
  int * L_2I;    /* Label last infected  class  */
  
  int * L_3I0;   /* Label first infected class  (3: Seniors) */
  int * L_3I;    /* Last Infected Class  */   
  
  double * Vector_Model_Variables;
  double * Vector_Model_Variables_Time_0;
  double * Vector_Model_Variables_Stationarity;
  double ** Vector_Model_Variables_MultiStability;
  int * Vector_Model_Int_Variables;               /* Stochastic Dynamics */
  int * Vector_Model_Int_Variables_Time_0;        /* Stochastic Dynamics */

  double *** Metapop_Connectivity_Matrix; 

  /*
     Evaluation of the largest (xmax) and the tiniest (xmin)
     numbers my machine can handle
  */
  float nr___x_min;
  float nr___x_MAX;

  double DETERMINISTIC_CASES; // Need by Error_Function.c 
  /* * * C P G   P L O T * * */

#if defined CPGPLOT_REPRESENTATION
#include <include.CPG.global.h>
  Parameter_CPGPLOT * CPG;
#endif

  int No_of_NEIGHBORS;
  int TYPE_of_NETWORK;
  int TOTAL_No_of_EVENTS;
  /* Total Number of Events within a patch, i.e., 25 * 4 = 100 */
  int No_of_EVENTS;
  
}Parameter_Table;

// void P_A_R_A_M_E_T_E_R___T_A_B_L_E___A_L_L_O_C( Parameter_Table * );

// void P_A_R_A_M_E_T_E_R___T_A_B_L_E___U_P_L_O_A_D( Parameter_Table *, int * );

// void Parameter_Values_into_Parameter_Table(Parameter_Table * );

// void values_TempDependency(double Temp, Parameter_Table *); ???

// void P_A_R_A_M_E_T_E_R___T_A_B_L_E___F_R_E_E( Parameter_Table * );


