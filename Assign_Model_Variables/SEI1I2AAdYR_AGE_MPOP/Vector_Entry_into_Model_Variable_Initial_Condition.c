#include <MODEL.h>

void Vector_Entry_into_Model_Variable_Initial_Condition_Table(double Value,
							      int m, Parameter_Table * Table)
{
  int Q, j, J; 
  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; /* Ex: 11 times 4 */ 
  j = m%Q; /* Stage within a local poulation (Ex: from 0 to 43) */
  J = m/Q; /* J-th Local Population          */

  if(      j == n0S )  Table->n0S___0[J] = Value;
  else if (j == n0E )  Table->n0E___0[J] = Value; 
  else if (j == n0I1)  Table->n0I1___0[J]= Value;
  else if (j == n0I2)  Table->n0I2___0[J]= Value;
  else if (j == n0A )  Table->n0A___0[J] = Value;
  else if (j == n0Ad )  Table->n0Ad___0[J] = Value;
  else if (j == n0Y )  Table->n0Y___0[J] = Value;
  else if (j == n0R )  Table->n0R___0[J] = Value;
  else if (j == a0I )  Table->a0I___0[J] = Value;
  else if (j == a0R )  Table->a0R___0[J] = Value;
  else if (j == a0D )  Table->a0D___0[J] = Value;

  else if( j == n1S )  Table->n1S___0[J] = Value;
  else if (j == n1E )  Table->n1E___0[J] = Value; 
  else if (j == n1I1)  Table->n1I1___0[J]= Value;
  else if (j == n1I2)  Table->n1I2___0[J]= Value;
  else if (j == n1A )  Table->n1A___0[J] = Value;
  else if (j == n1Ad )  Table->n1Ad___0[J] = Value;
  else if (j == n1Y )  Table->n1Y___0[J] = Value;
  else if (j == n1R )  Table->n1R___0[J] = Value;
  else if (j == a1I )  Table->a1I___0[J] = Value;
  else if (j == a1R )  Table->a1R___0[J] = Value;
  else if (j == a1D )  Table->a1D___0[J] = Value;

  else if( j == n2S )  Table->n2S___0[J] = Value;
  else if (j == n2E )  Table->n2E___0[J] = Value; 
  else if (j == n2I1)  Table->n2I1___0[J]= Value;
  else if (j == n2I2)  Table->n2I2___0[J]= Value;
  else if (j == n2A )  Table->n2A___0[J] = Value;
  else if (j == n2Ad )  Table->n2Ad___0[J] = Value;
  else if (j == n2Y )  Table->n2Y___0[J] = Value;
  else if (j == n2R )  Table->n2R___0[J] = Value;
  else if (j == a2I )  Table->a2I___0[J] = Value;
  else if (j == a2R )  Table->a2R___0[J] = Value;
  else if (j == a2D )  Table->a2D___0[J] = Value;

  else if( j == n3S )  Table->n3S___0[J] = Value;
  else if (j == n3E )  Table->n3E___0[J] = Value; 
  else if (j == n3I1)  Table->n3I1___0[J]= Value;
  else if (j == n3I2)  Table->n3I2___0[J]= Value;
  else if (j == n3A )  Table->n3A___0[J] = Value;
  else if (j == n3Ad ) Table->n3Ad___0[J] = Value;
  else if (j == n3Y )  Table->n3Y___0[J] = Value;
  else if (j == n3R )  Table->n3R___0[J] = Value;
  else if (j == a3I )  Table->a3I___0[J] = Value;
  else if (j == a3R )  Table->a3R___0[J] = Value;
  else if (j == a3D )  Table->a3D___0[J] = Value;
  
  else{
    printf(".... INVALID VARIABLE KEY [key = %d]\n", j);
    printf(".... Provided Model Variable Codes have been correcly defined,\n");
    printf(".... the permited correspondences are:\n");
    printf(".... from key = 0 to key = %d\n", Q-1);
    printf(".... The program will exit\n");
    exit(0);
  }
}

void Vector_Entry_into_Model_Variable_Initial_Condition_Model(double Value,
							      int m, Parameter_Model * Table)
{
   int Q, j, J; 
  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; /* Ex: 11 times 4 */ 
  j = m%Q; /* Stage within a local poulation (Ex: from 0 to 43) */
  J = m/Q; /* J-th Local Population          */

  if(      j == n0S )  Table->n0S___0[J] = Value;
  else if (j == n0E )  Table->n0E___0[J] = Value; 
  else if (j == n0I1)  Table->n0I1___0[J]= Value;
  else if (j == n0I2)  Table->n0I2___0[J]= Value;
  else if (j == n0A )  Table->n0A___0[J] = Value;
  else if (j == n0Ad )  Table->n0Ad___0[J] = Value;
  else if (j == n0Y )  Table->n0Y___0[J] = Value;
  else if (j == n0R )  Table->n0R___0[J] = Value;
  else if (j == a0I )  Table->a0I___0[J] = Value;
  else if (j == a0R )  Table->a0R___0[J] = Value;
  else if (j == a0D )  Table->a0D___0[J] = Value;

  else if( j == n1S )  Table->n1S___0[J] = Value;
  else if (j == n1E )  Table->n1E___0[J] = Value; 
  else if (j == n1I1)  Table->n1I1___0[J]= Value;
  else if (j == n1I2)  Table->n1I2___0[J]= Value;
  else if (j == n1A )  Table->n1A___0[J] = Value;
  else if (j == n1Ad )  Table->n1Ad___0[J] = Value;
  else if (j == n1Y )  Table->n1Y___0[J] = Value;
  else if (j == n1R )  Table->n1R___0[J] = Value;
  else if (j == a1I )  Table->a1I___0[J] = Value;
  else if (j == a1R )  Table->a1R___0[J] = Value;
  else if (j == a1D )  Table->a1D___0[J] = Value;

  else if( j == n2S )  Table->n2S___0[J] = Value;
  else if (j == n2E )  Table->n2E___0[J] = Value; 
  else if (j == n2I1)  Table->n2I1___0[J]= Value;
  else if (j == n2I2)  Table->n2I2___0[J]= Value;
  else if (j == n2A )  Table->n2A___0[J] = Value;
  else if (j == n2Ad )  Table->n2Ad___0[J] = Value;
  else if (j == n2Y )  Table->n2Y___0[J] = Value;
  else if (j == n2R )  Table->n2R___0[J] = Value;
  else if (j == a2I )  Table->a2I___0[J] = Value;
  else if (j == a2R )  Table->a2R___0[J] = Value;
  else if (j == a2D )  Table->a2D___0[J] = Value;

  else if( j == n3S )  Table->n3S___0[J] = Value;
  else if (j == n3E )  Table->n3E___0[J] = Value; 
  else if (j == n3I1)  Table->n3I1___0[J]= Value;
  else if (j == n3I2)  Table->n3I2___0[J]= Value;
  else if (j == n3A )  Table->n3A___0[J] = Value;
  else if (j == n3Ad ) Table->n3Ad___0[J] = Value;
  else if (j == n3Y )  Table->n3Y___0[J] = Value;
  else if (j == n3R )  Table->n3R___0[J] = Value;
  else if (j == a3I )  Table->a3I___0[J] = Value;
  else if (j == a3R )  Table->a3R___0[J] = Value;
  else if (j == a3D )  Table->a3D___0[J] = Value;
  
  else{
    printf(".... INVALID VARIABLE KEY [key = %d]\n", j);
    printf(".... Provided Model Variable Codes have been correcly defined,\n");
    printf(".... the permited correspondences are:\n");
    printf(".... from key = 0 to key = %d\n", Q-1);
    printf(".... The program will exit\n");
    exit(0);
  }
}
