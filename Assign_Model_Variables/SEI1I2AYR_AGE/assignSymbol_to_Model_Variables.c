#include <MODEL.h>

void AssignSymbol_to_Model_Variables(int j, char * Label, Parameter_Table * Table)
{
  char *pFile;
  Label[0]='\0';

  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  if(      j == n0S )  pFile = strcat(Label, "n0S"); 
  else if (j == n0E )  pFile = strcat(Label, "n0E"); 
  else if (j == n0I1)  pFile = strcat(Label, "n0I1");
  else if (j == n0I2)  pFile = strcat(Label, "n0I2");
  else if (j == n0A )  pFile = strcat(Label, "n0A"); 
  else if (j == n0Y )  pFile = strcat(Label, "n0Y"); 
  else if (j == n0R )  pFile = strcat(Label, "n0R");
  else if (j == a0I )  pFile = strcat(Label, "a0I"); 
  else if (j == a0R )  pFile = strcat(Label, "a0R"); 
  else if (j == a0D )  pFile = strcat(Label, "a0D");

  else if(      j == n1S )  pFile = strcat(Label, "n1S"); 
  else if (j == n1E )  pFile = strcat(Label, "n1E"); 
  else if (j == n1I1)  pFile = strcat(Label, "n1I1");
  else if (j == n1I2)  pFile = strcat(Label, "n1I2");
  else if (j == n1A )  pFile = strcat(Label, "n1A"); 
  else if (j == n1Y )  pFile = strcat(Label, "n1Y"); 
  else if (j == n1R )  pFile = strcat(Label, "n1R");
  else if (j == a1I )  pFile = strcat(Label, "a1I"); 
  else if (j == a1R )  pFile = strcat(Label, "a1R"); 
  else if (j == a1D )  pFile = strcat(Label, "a1D");

  else if(      j == n2S )  pFile = strcat(Label, "n2S"); 
  else if (j == n2E )  pFile = strcat(Label, "n2E"); 
  else if (j == n2I1)  pFile = strcat(Label, "n2I1");
  else if (j == n2I2)  pFile = strcat(Label, "n2I2");
  else if (j == n2A )  pFile = strcat(Label, "n2A"); 
  else if (j == n2Y )  pFile = strcat(Label, "n2Y"); 
  else if (j == n2R )  pFile = strcat(Label, "n2R");
  else if (j == a2I )  pFile = strcat(Label, "a2I"); 
  else if (j == a2R )  pFile = strcat(Label, "a2R"); 
  else if (j == a2D )  pFile = strcat(Label, "a2D");

  else if(      j == n3S )  pFile = strcat(Label, "n3S"); 
  else if (j == n3E )  pFile = strcat(Label, "n3E"); 
  else if (j == n3I1)  pFile = strcat(Label, "n3I1");
  else if (j == n3I2)  pFile = strcat(Label, "n3I2");
  else if (j == n3A )  pFile = strcat(Label, "n3A"); 
  else if (j == n3Y )  pFile = strcat(Label, "n3Y"); 
  else if (j == n3R )  pFile = strcat(Label, "n3R");
  else if (j == a3I )  pFile = strcat(Label, "a3I"); 
  else if (j == a3R )  pFile = strcat(Label, "a3R"); 
  else if (j == a3D )  pFile = strcat(Label, "a3D");
  
  else{
    printf(".... INVALID VARIABLE KEY [key = %d]\n", j);
    printf(".... Provided Model Variable Codes have been correcly defined,\n");
    printf(".... the permited correspondences are:\n");
    printf(".... from key = 0 to key = %d\n", Table->MODEL_STATE_VARIABLES-1);
    printf(".... The program will exit\n");
    exit(0);
  }
}
