#include <MODEL.h>

void Patch_System_Initialization (Community ** PATCH, Parameter_Table * Table, double * y_INI)
{
  int i,j, Q; 
  Parameter_Model * P = Table->P;

  /* Populations are initialized in agreement with y_INI  */

  /* Q is the number of variables required to define the state of a single patch */
  Q = P->TOTAL_No_of_DISEASE_STAGES * P->TOTAL_No_of_AGE_CLASSES; /* Ex: 11 times 4 */

  for (j = 0; j < Table->No_of_LOCAL_POPULATIONS; j++) {
   
    PATCH[j]->N0 = P->N0;
    PATCH[j]->N1 = P->N1;
    PATCH[j]->N2 = P->N2;
    PATCH[j]->N3 = P->N3;

    for(i=0; i<Q; i++)
      PATCH[j]->n[i] = (int)y_INI[i + j*Q]; 
      
  }
}
