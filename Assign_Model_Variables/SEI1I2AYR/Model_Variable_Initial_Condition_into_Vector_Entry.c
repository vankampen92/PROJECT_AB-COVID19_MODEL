#include <MODEL.h>

double Model_Variable_Initial_Condition_into_Vector_Entry_Table(int j, Parameter_Table * Table)
{
  double Value; 
  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  if(j       == nS)   Value = Table->nS__0 ;
  else if (j == nE )  Value = Table->nE__0 ; 
  else if (j == nI1 ) Value = Table->nI1__0;
  else if (j == nI2 ) Value = Table->nI2__0;
  else if (j == nA )  Value = Table->nA__0 ;
  else if (j == nY )  Value = Table->nY__0 ;
  else if (j == nR )  Value = Table->nR__0 ;
  else if (j == aI )  Value = Table->aI__0 ;
  else if (j == aR )  Value = Table->aR__0 ;
  else if (j == aD )  Value = Table->aD__0 ;
  
  /* if(j == X0S)         Value = Table->X0S__0 ; */
  /* else if (j == X0I )  Value = Table->X0E__0 ; */
  /* else if (j == X0L )  Value = Table->X0I1__0; */
  /* else if (j == X0D )  Value = Table->X0I2__0; */
  /* else if (j == W0S )  Value = Table->X0A__0 ; */
  /* else if (j == W0I )  Value = Table->X0Y__0 ; */
  /* else if (j == W0L )  Value = Table->X0R__0 ; */

  else{
    printf(".... INVALID VARIABLE KEY [key = %d]\n", j);
    printf(".... Provided Model Variable Codes have been correcly defined,\n");
    printf(".... the permited correspondences are:\n");
    printf(".... from key = 0 to key = %d\n", Table->MODEL_STATE_VARIABLES-1);
    printf(".... The program will exit\n");
    exit(0);
  }

  return(Value); 
}

double Model_Variable_Initial_Condition_into_Vector_Entry_Model(int j, Parameter_Model * Table)
{
  double Value; 
  
  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  if(j       == nS)   Value = Table->nS__0 ;
  else if (j == nE )  Value = Table->nE__0 ; 
  else if (j == nI1 ) Value = Table->nI1__0;
  else if (j == nI2 ) Value = Table->nI2__0;
  else if (j == nA )  Value = Table->nA__0 ;
  else if (j == nY )  Value = Table->nY__0 ;
  else if (j == nR )  Value = Table->nR__0 ;
  else if (j == aI )  Value = Table->aI__0 ;
  else if (j == aR )  Value = Table->aR__0 ;
  else if (j == aD )  Value = Table->aD__0 ;

  else{
    printf(".... INVALID VARIABLE KEY [key = %d]\n", j);
    printf(".... Provided Model Variable Codes have been correcly defined,\n");
    printf(".... the permited correspondences are:\n");
    printf(".... from key = 0 to key = %d\n", Table->MODEL_STATE_VARIABLES-1);
    printf(".... The program will exit\n");
    exit(0);
  }

  return(Value); 
}
