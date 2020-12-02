#include <MODEL.h>

double Model_Variable_Initial_Condition_into_Vector_Entry_Table(int m, Parameter_Table * Table)
{
  double Value;
  int Q, j, J; 
  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; /* Ex: 11 times 4 */ 
  j = m%Q; /* Stage within a local poulation (Ex: from 0 to 43) */
  J = m/Q; /* J-th Local Population          */
  
  if(j       == n0S)   Value = Table->n0S___0[J] ;
  else if (j == n0E )  Value = Table->n0E___0[J] ; 
  else if (j == n0I1 ) Value = Table->n0I1___0[J];
  else if (j == n0I2 ) Value = Table->n0I2___0[J];
  else if (j == n0A )  Value = Table->n0A___0[J] ;
  else if (j == n0Ad ) Value = Table->n0Ad___0[J] ;
  else if (j == n0Y )  Value = Table->n0Y___0[J] ;
  else if (j == n0R )  Value = Table->n0R___0[J] ;
  else if (j == a0I )  Value = Table->a0I___0[J] ;
  else if (j == a0R )  Value = Table->a0R___0[J] ;
  else if (j == a0D )  Value = Table->a0D___0[J] ;

  else if(j  == n1S)   Value = Table->n1S___0[J] ;
  else if (j == n1E )  Value = Table->n1E___0[J] ; 
  else if (j == n1I1 ) Value = Table->n1I1___0[J];
  else if (j == n1I2 ) Value = Table->n1I2___0[J];
  else if (j == n1A )  Value = Table->n1A___0[J] ;
  else if (j == n1Ad ) Value = Table->n1Ad___0[J] ;
  else if (j == n1Y )  Value = Table->n1Y___0[J] ;
  else if (j == n1R )  Value = Table->n1R___0[J] ;
  else if (j == a1I )  Value = Table->a1I___0[J] ;
  else if (j == a1R )  Value = Table->a1R___0[J] ;
  else if (j == a1D )  Value = Table->a1D___0[J] ;

  else if(j  == n2S)   Value = Table->n2S___0[J] ;
  else if (j == n2E )  Value = Table->n2E___0[J] ; 
  else if (j == n2I1 ) Value = Table->n2I1___0[J];
  else if (j == n2I2 ) Value = Table->n2I2___0[J];
  else if (j == n2A )  Value = Table->n2A___0[J] ;
  else if (j == n2Ad ) Value = Table->n2Ad___0[J] ;
  else if (j == n2Y )  Value = Table->n2Y___0[J] ;
  else if (j == n2R )  Value = Table->n2R___0[J] ;
  else if (j == a2I )  Value = Table->a2I___0[J] ;
  else if (j == a2R )  Value = Table->a2R___0[J] ;
  else if (j == a2D )  Value = Table->a2D___0[J] ;

  else if(j  == n3S)   Value = Table->n3S___0[J] ;
  else if (j == n3E )  Value = Table->n3E___0[J] ; 
  else if (j == n3I1 ) Value = Table->n3I1___0[J];
  else if (j == n3I2 ) Value = Table->n3I2___0[J];
  else if (j == n3A )  Value = Table->n3A___0[J] ;
  else if (j == n3Ad ) Value = Table->n3Ad___0[J] ;
  else if (j == n3Y )  Value = Table->n3Y___0[J] ;
  else if (j == n3R )  Value = Table->n3R___0[J] ;
  else if (j == a3I )  Value = Table->a3I___0[J] ;
  else if (j == a3R )  Value = Table->a3R___0[J] ;
  else if (j == a3D )  Value = Table->a3D___0[J] ;

  else{
    printf(".... INVALID VARIABLE KEY [key = %d]\n", j);
    printf(".... Provided Model Variable Codes have been correcly defined,\n");
    printf(".... the permited correspondences are:\n");
    printf(".... from key = 0 to key = %d\n", Q-1);
    printf(".... The program will exit\n");
    exit(0);
  }

  return(Value); 
}

double Model_Variable_Initial_Condition_into_Vector_Entry_Model(int m, Parameter_Model * Table)
{
  double Value; 
  
  int Q, j, J; 
  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; /* Ex: 11 times 4 */ 
  j = m%Q; /* Stage within a local poulation (Ex: from 0 to 43) */
  J = m/Q; /* J-th Local Population          */

  if(j       == n0S)   Value = Table->n0S___0[J] ;
  else if (j == n0E )  Value = Table->n0E___0[J] ; 
  else if (j == n0I1 ) Value = Table->n0I1___0[J];
  else if (j == n0I2 ) Value = Table->n0I2___0[J];
  else if (j == n0A )  Value = Table->n0A___0[J] ;
  else if (j == n0Ad ) Value = Table->n0Ad___0[J] ;
  else if (j == n0Y )  Value = Table->n0Y___0[J] ;
  else if (j == n0R )  Value = Table->n0R___0[J] ;
  else if (j == a0I )  Value = Table->a0I___0[J] ;
  else if (j == a0R )  Value = Table->a0R___0[J] ;
  else if (j == a0D )  Value = Table->a0D___0[J] ;

  else if(j  == n1S)   Value = Table->n1S___0[J] ;
  else if (j == n1E )  Value = Table->n1E___0[J] ; 
  else if (j == n1I1 ) Value = Table->n1I1___0[J];
  else if (j == n1I2 ) Value = Table->n1I2___0[J];
  else if (j == n1A )  Value = Table->n1A___0[J] ;
  else if (j == n1Ad ) Value = Table->n1Ad___0[J] ;
  else if (j == n1Y )  Value = Table->n1Y___0[J] ;
  else if (j == n1R )  Value = Table->n1R___0[J] ;
  else if (j == a1I )  Value = Table->a1I___0[J] ;
  else if (j == a1R )  Value = Table->a1R___0[J] ;
  else if (j == a1D )  Value = Table->a1D___0[J] ;

  else if(j  == n2S)   Value = Table->n2S___0[J] ;
  else if (j == n2E )  Value = Table->n2E___0[J] ; 
  else if (j == n2I1 ) Value = Table->n2I1___0[J];
  else if (j == n2I2 ) Value = Table->n2I2___0[J];
  else if (j == n2A )  Value = Table->n2A___0[J] ;
  else if (j == n2Ad ) Value = Table->n2Ad___0[J] ;
  else if (j == n2Y )  Value = Table->n2Y___0[J] ;
  else if (j == n2R )  Value = Table->n2R___0[J] ;
  else if (j == a2I )  Value = Table->a2I___0[J] ;
  else if (j == a2R )  Value = Table->a2R___0[J] ;
  else if (j == a2D )  Value = Table->a2D___0[J] ;

  else if(j  == n3S)   Value = Table->n3S___0[J] ;
  else if (j == n3E )  Value = Table->n3E___0[J] ; 
  else if (j == n3I1 ) Value = Table->n3I1___0[J];
  else if (j == n3I2 ) Value = Table->n3I2___0[J];
  else if (j == n3A )  Value = Table->n3A___0[J] ;
  else if (j == n3Ad ) Value = Table->n3Ad___0[J] ;
  else if (j == n3Y )  Value = Table->n3Y___0[J] ;
  else if (j == n3R )  Value = Table->n3R___0[J] ;
  else if (j == a3I )  Value = Table->a3I___0[J] ;
  else if (j == a3R )  Value = Table->a3R___0[J] ;
  else if (j == a3D )  Value = Table->a3D___0[J] ;
  
  else{
    printf(".... INVALID VARIABLE KEY [key = %d]\n", j);
    printf(".... Provided Model Variable Codes have been correcly defined,\n");
    printf(".... the permited correspondences are:\n");
    printf(".... from key = 0 to key = %d\n", Q-1);
    printf(".... The program will exit\n");
    exit(0);
  }

  return(Value); 
}
