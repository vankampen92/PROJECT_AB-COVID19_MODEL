#include <MODEL.h>

double Model_Variable_Initial_Condition_into_Vector_Entry_Table(int j, Parameter_Table * Table)
{
  double Value; 
  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  if(j       == n0S)   Value = Table->n0S__0 ;
  else if (j == n0E )  Value = Table->n0E__0 ; 
  else if (j == n0I1 ) Value = Table->n0I1__0;
  else if (j == n0I2 ) Value = Table->n0I2__0;
  else if (j == n0A )  Value = Table->n0A__0 ;
  else if (j == n0Y )  Value = Table->n0Y__0 ;
  else if (j == n0R )  Value = Table->n0R__0 ;
  else if (j == a0I )  Value = Table->a0I__0 ;
  else if (j == a0R )  Value = Table->a0R__0 ;
  else if (j == a0D )  Value = Table->a0D__0 ;

  else if(j  == n1S)   Value = Table->n1S__0 ;
  else if (j == n1E )  Value = Table->n1E__0 ; 
  else if (j == n1I1 ) Value = Table->n1I1__0;
  else if (j == n1I2 ) Value = Table->n1I2__0;
  else if (j == n1A )  Value = Table->n1A__0 ;
  else if (j == n1Y )  Value = Table->n1Y__0 ;
  else if (j == n1R )  Value = Table->n1R__0 ;
  else if (j == a1I )  Value = Table->a1I__0 ;
  else if (j == a1R )  Value = Table->a1R__0 ;
  else if (j == a1D )  Value = Table->a1D__0 ;

  else if(j  == n2S)   Value = Table->n2S__0 ;
  else if (j == n2E )  Value = Table->n2E__0 ; 
  else if (j == n2I1 ) Value = Table->n2I1__0;
  else if (j == n2I2 ) Value = Table->n2I2__0;
  else if (j == n2A )  Value = Table->n2A__0 ;
  else if (j == n2Y )  Value = Table->n2Y__0 ;
  else if (j == n2R )  Value = Table->n2R__0 ;
  else if (j == a2I )  Value = Table->a2I__0 ;
  else if (j == a2R )  Value = Table->a2R__0 ;
  else if (j == a2D )  Value = Table->a2D__0 ;

  else if(j  == n3S)   Value = Table->n3S__0 ;
  else if (j == n3E )  Value = Table->n3E__0 ; 
  else if (j == n3I1 ) Value = Table->n3I1__0;
  else if (j == n3I2 ) Value = Table->n3I2__0;
  else if (j == n3A )  Value = Table->n3A__0 ;
  else if (j == n3Y )  Value = Table->n3Y__0 ;
  else if (j == n3R )  Value = Table->n3R__0 ;
  else if (j == a3I )  Value = Table->a3I__0 ;
  else if (j == a3R )  Value = Table->a3R__0 ;
  else if (j == a3D )  Value = Table->a3D__0 ;

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

  if(j       == n0S)   Value = Table->n0S__0 ;
  else if (j == n0E )  Value = Table->n0E__0 ; 
  else if (j == n0I1 ) Value = Table->n0I1__0;
  else if (j == n0I2 ) Value = Table->n0I2__0;
  else if (j == n0A )  Value = Table->n0A__0 ;
  else if (j == n0Y )  Value = Table->n0Y__0 ;
  else if (j == n0R )  Value = Table->n0R__0 ;
  else if (j == a0I )  Value = Table->a0I__0 ;
  else if (j == a0R )  Value = Table->a0R__0 ;
  else if (j == a0D )  Value = Table->a0D__0 ;

  else if(j       == n1S)   Value = Table->n1S__0 ;
  else if (j == n1E )  Value = Table->n1E__0 ; 
  else if (j == n1I1 ) Value = Table->n1I1__0;
  else if (j == n1I2 ) Value = Table->n1I2__0;
  else if (j == n1A )  Value = Table->n1A__0 ;
  else if (j == n1Y )  Value = Table->n1Y__0 ;
  else if (j == n1R )  Value = Table->n1R__0 ;
  else if (j == a1I )  Value = Table->a1I__0 ;
  else if (j == a1R )  Value = Table->a1R__0 ;
  else if (j == a1D )  Value = Table->a1D__0 ;

  else if(j       == n2S)   Value = Table->n2S__0 ;
  else if (j == n2E )  Value = Table->n2E__0 ; 
  else if (j == n2I1 ) Value = Table->n2I1__0;
  else if (j == n2I2 ) Value = Table->n2I2__0;
  else if (j == n2A )  Value = Table->n2A__0 ;
  else if (j == n2Y )  Value = Table->n2Y__0 ;
  else if (j == n2R )  Value = Table->n2R__0 ;
  else if (j == a2I )  Value = Table->a2I__0 ;
  else if (j == a2R )  Value = Table->a2R__0 ;
  else if (j == a2D )  Value = Table->a2D__0 ;

  else if(j       == n3S)   Value = Table->n3S__0 ;
  else if (j == n3E )  Value = Table->n3E__0 ; 
  else if (j == n3I1 ) Value = Table->n3I1__0;
  else if (j == n3I2 ) Value = Table->n3I2__0;
  else if (j == n3A )  Value = Table->n3A__0 ;
  else if (j == n3Y )  Value = Table->n3Y__0 ;
  else if (j == n3R )  Value = Table->n3R__0 ;
  else if (j == a3I )  Value = Table->a3I__0 ;
  else if (j == a3R )  Value = Table->a3R__0 ;
  else if (j == a3D )  Value = Table->a3D__0 ;
  
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
