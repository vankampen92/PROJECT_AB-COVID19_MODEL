#include <MODEL.h>

void Vector_Entry_into_Model_Variable_Initial_Condition_Table(double Value,
							      int j, Parameter_Table * Table)
{
  
  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  if(      j == n0S )  Table->n0S__0 = Value;
  else if (j == n0E )  Table->n0E__0 = Value; 
  else if (j == n0I1)  Table->n0I1__0= Value;
  else if (j == n0I2)  Table->n0I2__0= Value;
  else if (j == n0A )  Table->n0A__0 = Value;
  else if (j == n0Y )  Table->n0Y__0 = Value;
  else if (j == n0R )  Table->n0R__0 = Value;
  else if (j == a0I )  Table->a0I__0 = Value;
  else if (j == a0R )  Table->a0R__0 = Value;
  else if (j == a0D )  Table->a0D__0 = Value;

  else if( j == n1S )  Table->n1S__0 = Value;
  else if (j == n1E )  Table->n1E__0 = Value; 
  else if (j == n1I1)  Table->n1I1__0= Value;
  else if (j == n1I2)  Table->n1I2__0= Value;
  else if (j == n1A )  Table->n1A__0 = Value;
  else if (j == n1Y )  Table->n1Y__0 = Value;
  else if (j == n1R )  Table->n1R__0 = Value;
  else if (j == a1I )  Table->a1I__0 = Value;
  else if (j == a1R )  Table->a1R__0 = Value;
  else if (j == a1D )  Table->a1D__0 = Value;

  else if( j == n2S )  Table->n2S__0 = Value;
  else if (j == n2E )  Table->n2E__0 = Value; 
  else if (j == n2I1)  Table->n2I1__0= Value;
  else if (j == n2I2)  Table->n2I2__0= Value;
  else if (j == n2A )  Table->n2A__0 = Value;
  else if (j == n2Y )  Table->n2Y__0 = Value;
  else if (j == n2R )  Table->n2R__0 = Value;
  else if (j == a2I )  Table->a2I__0 = Value;
  else if (j == a2R )  Table->a2R__0 = Value;
  else if (j == a2D )  Table->a2D__0 = Value;

  else if( j == n3S )  Table->n3S__0 = Value;
  else if (j == n3E )  Table->n3E__0 = Value; 
  else if (j == n3I1)  Table->n3I1__0= Value;
  else if (j == n3I2)  Table->n3I2__0= Value;
  else if (j == n3A )  Table->n3A__0 = Value;
  else if (j == n3Y )  Table->n3Y__0 = Value;
  else if (j == n3R )  Table->n3R__0 = Value;
  else if (j == a3I )  Table->a3I__0 = Value;
  else if (j == a3R )  Table->a3R__0 = Value;
  else if (j == a3D )  Table->a3D__0 = Value;
  
  else{
    printf(".... INVALID VARIABLE KEY [key = %d]\n", j);
    printf(".... Provided Model Variable Codes have been correcly defined,\n");
    printf(".... the permited correspondences are:\n");
    printf(".... from key = 0 to key = %d\n", Table->MODEL_STATE_VARIABLES-1);
    printf(".... The program will exit\n");
    exit(0);
  }
}

void Vector_Entry_into_Model_Variable_Initial_Condition_Model(double Value,
							      int j, Parameter_Model * Table)
{
  
  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>
  
  if(      j == n0S )  Table->n0S__0 = Value;
  else if (j == n0E )  Table->n0E__0 = Value; 
  else if (j == n0I1)  Table->n0I1__0= Value;
  else if (j == n0I2)  Table->n0I2__0= Value;
  else if (j == n0A )  Table->n0A__0 = Value;
  else if (j == n0Y )  Table->n0Y__0 = Value;
  else if (j == n0R )  Table->n0R__0 = Value;
  else if (j == a0I )  Table->a0I__0 = Value;
  else if (j == a0R )  Table->a0R__0 = Value;
  else if (j == a0D )  Table->a0D__0 = Value;

  else if( j == n1S )  Table->n1S__0 = Value;
  else if (j == n1E )  Table->n1E__0 = Value; 
  else if (j == n1I1)  Table->n1I1__0= Value;
  else if (j == n1I2)  Table->n1I2__0= Value;
  else if (j == n1A )  Table->n1A__0 = Value;
  else if (j == n1Y )  Table->n1Y__0 = Value;
  else if (j == n1R )  Table->n1R__0 = Value;
  else if (j == a1I )  Table->a1I__0 = Value;
  else if (j == a1R )  Table->a1R__0 = Value;
  else if (j == a1D )  Table->a1D__0 = Value;

  else if( j == n2S )  Table->n2S__0 = Value;
  else if (j == n2E )  Table->n2E__0 = Value; 
  else if (j == n2I1)  Table->n2I1__0= Value;
  else if (j == n2I2)  Table->n2I2__0= Value;
  else if (j == n2A )  Table->n2A__0 = Value;
  else if (j == n2Y )  Table->n2Y__0 = Value;
  else if (j == n2R )  Table->n2R__0 = Value;
  else if (j == a2I )  Table->a2I__0 = Value;
  else if (j == a2R )  Table->a2R__0 = Value;
  else if (j == a2D )  Table->a2D__0 = Value;

  else if( j == n3S )  Table->n3S__0 = Value;
  else if (j == n3E )  Table->n3E__0 = Value; 
  else if (j == n3I1)  Table->n3I1__0= Value;
  else if (j == n3I2)  Table->n3I2__0= Value;
  else if (j == n3A )  Table->n3A__0 = Value;
  else if (j == n3Y )  Table->n3Y__0 = Value;
  else if (j == n3R )  Table->n3R__0 = Value;
  else if (j == a3I )  Table->a3I__0 = Value;
  else if (j == a3R )  Table->a3R__0 = Value;
  else if (j == a3D )  Table->a3D__0 = Value;

  else{
    printf(".... INVALID VARIABLE KEY [key = %d]\n", j);
    printf(".... Provided Model Variable Codes have been correcly defined,\n");
    printf(".... the permited correspondences are:\n");
    printf(".... from key = 0 to key = %d\n", Table->MODEL_STATE_VARIABLES-1);
    printf(".... The program will exit\n");
    exit(0);
  }
}
