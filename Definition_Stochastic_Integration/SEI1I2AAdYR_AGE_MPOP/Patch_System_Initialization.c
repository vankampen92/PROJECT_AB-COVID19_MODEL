#include <MODEL.h>

void Patch_System_Initialization (Community ** PATCH, Parameter_Table * Table, double * y_INI)
{
  int i,j; 
  Parameter_Model * P = Table->P;
  int N               = P->No_of_LOCAL_POPULATIONS;

  /* Populations are initialized in agreement with y_INI. If the system is multipatch all patches
     are initialized with the same populations */
  
  /* Table->C is the label of last human class        */
  /* Table->K is the label of the last mosquito class */ 

  if ( N == 1 ) {

    PATCH[0]->H_POPULATION = 0;
    for(i=0; i <= Table->C; i++) {
      PATCH[0]->n[i] = (int)y_INI[i];

      Table->Vector_Model_Int_Variables[i] = (int)y_INI[i];
      Table->Vector_Model_Variables[i]     = y_INI[i];
      
      PATCH[0]->H_POPULATION += (int)y_INI[i];
    }
    Table->H_POPULATION = PATCH[0]->H_POPULATION;
    P->H_POPULATION     = PATCH[0]->H_POPULATION;       
    
    PATCH[0]->M_POPULATION = 0;
    for(i = Table->C+1; i <= Table->K; i++) {
      PATCH[0]->n[i] = (int)y_INI[i];

      Table->Vector_Model_Int_Variables[i] = (int)y_INI[i];
      Table->Vector_Model_Variables[i]     = y_INI[i];
      
      PATCH[0]->M_POPULATION += (int)y_INI[i];
    }
    Table->M_POPULATION = PATCH[0]->M_POPULATION;
    P->M_POPULATION     = PATCH[0]->M_POPULATION;
  
  }
  else {
    int * N_J = (int *)calloc( P->MODEL_STATE_VARIABLES, sizeof(int) ); 

    for (j = 0; j < N; j++) {
   
      PATCH[j]->H_POPULATION = 0;
      for(i=0; i <= Table->C; i++) {
	PATCH[j]->n[i] = (int)y_INI[i];
	PATCH[j]->H_POPULATION += (int)y_INI[i];
	N_J[i] += (int)y_INI[i];
      }
      
      PATCH[j]->M_POPULATION = 0;
      for(i = Table->C+1; i <= Table->K; i++) {
	PATCH[j]->n[i] = (int)y_INI[i];
	PATCH[j]->M_POPULATION += (int)y_INI[i];
	N_J[i] += (int)y_INI[i];
      }
    }
    
    /* Total Populations */
    for (j = 0; j < N; j++) {
      for(i=0; i < P->MODEL_STATE_VARIABLES; i++) {
	Table->Vector_Model_Int_Variables[i] = N_J[i];
	Table->Vector_Model_Variables[i] = (double)N_J[i];
      }
    }
    
    free(N_J); 
  }
}
