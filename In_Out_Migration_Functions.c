#include <MODEL.h>

double In_Mu(Parameter_Table * Table, int m, int a, int J, const double * y)
{
  /* Input: 
     ------
     . m: Equation index
     . a: Age group
     . J: Index of the population receiveing immigrants. 
         (K: Index of the population from which immigrants come)
     . y: State vector 
     
     Output:
     -------
     . Mu: Number of immigrations arriving to local popualtion J from all other populations
     per unit time
  */
  
  int K;
  double Mu;
  int i,k, n, Q;

  /*
     J: Index for the J-th population 
     K: Index for the K-th population 
  */
  

  Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; /* Ex: 11 times 4 */ 
  k = m%Q;

  assert(m/Q == J); 

  i = k%Table->TOTAL_No_of_DISEASE_STAGES;  /* Ex: 11 */
    
  Mu = 0.0;
  
  if ( i < Table->No_of_DISEASE_STAGES ) {  /* Ex: 8: i=0, ..., 7 */
    
    for( K=0; K<Table->No_of_LOCAL_POPULATIONS; K++) {

      n   = k + Q*K;

      if( K != J ) Mu += Table->Metapop_Connectivity_Matrix[a][J][K] * y[n];
      
    }
  }

  return (Mu); 
}

double Out_Mu_Per_Capita(Parameter_Table * Table, int a, int J)
{
  
  /* Input: 
     ------
     . a: Age group
     . J: Index of the population exporting individuals over all other local populations. 
     
     Output:
     -------
     . Mu: Per Capita emigration rate from the J-th population over all other local population 
  */
  double Mu;
  int K; 
  
  Mu = 0.0;
  for( K=0; K<Table->No_of_LOCAL_POPULATIONS; K++) {

    if( K != J ) Mu += Table->Metapop_Connectivity_Matrix[a][K][J];
    
  }
  
  return (Mu);
}
