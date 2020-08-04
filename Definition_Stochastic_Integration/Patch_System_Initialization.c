#include <MODEL.h>

void Patch_System_Initialization (Community ** PATCH, Parameter_Table * Table, double * y_INI)
{
  int i,j, Q; 
  int N0, N1, N2, N3;
  
  /* Populations are initialized in agreement with y_INI  */

  /* Q is the number of variables required to define the state of a single patch */
  Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; /* Ex: 11 times 4 */

  for (j = 0; j < Table->No_of_LOCAL_POPULATIONS; j++) {

    N0 = 0; N1 = 0; N2 = 0; N3= 0;
    for(i=0; i<Q; i++) {
      
      PATCH[j]->n[i] = (int)y_INI[i + j*Q]; 

      if (i >= Table->n0S && i<= Table->n0R ) N0 += (int)y_INI[i + j*Q]; 
      if (i >= Table->n1S && i<= Table->n1R ) N1 += (int)y_INI[i + j*Q]; 
      if (i >= Table->n2S && i<= Table->n2R ) N2 += (int)y_INI[i + j*Q]; 
      if (i >= Table->n3S && i<= Table->n3R ) N3 += (int)y_INI[i + j*Q]; 

    }
    PATCH[j]->N0 = N0;
    PATCH[j]->N1 = N1;
    PATCH[j]->N2 = N2;
    PATCH[j]->N3 = N3;

  }  
}
