#include <MODEL.h>

void Vector_Entry_into_Model_Variable_Initial_Condition_Table(double Value,
							      int j, Parameter_Table * Table)
{
  
  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  if(      j == nS )  Table->nS__0 = Value;
  else if (j == nE )  Table->nE__0 = Value; 
  else if (j == nI1)  Table->nI1__0= Value;
  else if (j == nI2)  Table->nI2__0= Value;
  else if (j == nA )  Table->nA__0 = Value;
  else if (j == nY )  Table->nY__0 = Value;
  else if (j == nR )  Table->nR__0 = Value;
  else if (j == aI )  Table->aI__0 = Value;
  else if (j == aR )  Table->aR__0 = Value;
  else if (j == aD )  Table->aD__0 = Value;
  
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

  if      (j == nS )  Table->nS__0 = Value;
  else if (j == nE )  Table->nE__0 = Value; 
  else if (j == nI1)  Table->nI1__0= Value;
  else if (j == nI2)  Table->nI2__0= Value;
  else if (j == nA )  Table->nA__0 = Value;
  else if (j == nY )  Table->nY__0 = Value;
  else if (j == nR )  Table->nR__0 = Value;
  else if (j == aI )  Table->aI__0 = Value;
  else if (j == aR )  Table->aR__0 = Value;
  else if (j == aD )  Table->aD__0 = Value;
  
  else{
    printf(".... INVALID VARIABLE KEY [key = %d]\n", j);
    printf(".... Provided Model Variable Codes have been correcly defined,\n");
    printf(".... the permited correspondences are:\n");
    printf(".... from key = 0 to key = %d\n", Table->MODEL_STATE_VARIABLES-1);
    printf(".... The program will exit\n");
    exit(0);
  }
}
