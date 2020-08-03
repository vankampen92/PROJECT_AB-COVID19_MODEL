#include <MODEL.h>

void AssignSymbol_to_Model_Variables(int j, char * Label, Parameter_Table * Table)
{
  char *pFile;
  Label[0]='\0';

  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  if(      j == nS )  pFile = strcat(Label, "nS"); 
  else if (j == nE )  pFile = strcat(Label, "nE"); 
  else if (j == nI1)  pFile = strcat(Label, "nI1");
  else if (j == nI2)  pFile = strcat(Label, "nI2");
  else if (j == nA )  pFile = strcat(Label, "nA"); 
  else if (j == nY )  pFile = strcat(Label, "nY"); 
  else if (j == nR )  pFile = strcat(Label, "nR");
  else if (j == aI )  pFile = strcat(Label, "aI"); 
  else if (j == aR )  pFile = strcat(Label, "aR"); 
  else if (j == aD )  pFile = strcat(Label, "aD");
  
  else{
    printf(".... INVALID VARIABLE KEY [key = %d]\n", j);
    printf(".... Provided Model Variable Codes have been correcly defined,\n");
    printf(".... the permited correspondences are:\n");
    printf(".... from key = 0 to key = %d\n", Table->MODEL_STATE_VARIABLES-1);
    printf(".... The program will exit\n");
    exit(0);
  }
}
