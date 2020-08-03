#include <MODEL.h>

/* 
   This function poses the PATCH system at the initial configuration and calculates
   the initial rate at which the total system may change from this initial configuration 
   to any possible alternative one.
*/
#ifndef VERBOSE
#define STAT_BOOL_VERBOSE 0
#else
#define STAT_BOOL_VERBOSE 1
#endif

void Initial_Conditions_Stochastic_Dynamics( Parameter_Table * Table, double * y_INI )  
{
  Parameter_Model * P = Table->P;
  Community ** PATCH  = Table->Patch_System; 
  
  if(Table->TYPE_of_INITIAL_CONDITION == 0) {
    Print_Press_Key (STAT_BOOL_VERBOSE, 0, 
	  "Initial Conditions are defined from command line or by default values\n");
    Initial_Condition_from_Parameter_Table(Table, y_INI);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    /* Global number of individuals give by the y_INI vectrp are used to initialized the 
       first patch. The other patches are initialized as emptey 
    */
    Patch_System_Initialization (PATCH, Table, y_INI);
  }
  else if (Table->TYPE_of_INITIAL_CONDITION == 1) {
    Print_Press_Key (STAT_BOOL_VERBOSE, 0, 
	  "Random Initial Conditions are defined within some boundary values\n");
    Random_Initial_Condition(Table, y_INI);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    /* Global number of individuals give by the y_INI vectrp are used to initialized the 
       first patch. The other patches are initialized as emptey 
    */
    Patch_System_Initialization (PATCH, Table, y_INI);
  }
  else {
    printf(" Attention: Initial Condition Value is undefined:\n");
    printf(" Allows values are 0, 1, and 2, but TYPE_of_INITIAL_CONDITION = %d\n",
	   Table->TYPE_of_INITIAL_CONDITION );
    exit(0); 
  }
}


