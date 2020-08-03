#include <MODEL.h>

double Total_Infected_Population  ( const double * y, Parameter_Table * Table )
{
  int i, j, Q; 
  double Y;
  double Infection;

  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>
  
  if (Table->TYPE_of_MODEL == 0) {
    Y = 0.0;
    for (i=LI0; i<=LI; i++) Y += y[i]; 
  }
  else if (Table->TYPE_of_MODEL == 1 || Table->TYPE_of_MODEL == 2) {
    Y = 0.0;
    for (i=L0I0; i<=L0I; i++) Y += y[i];
    for (i=L1I0; i<=L1I; i++) Y += y[i];
    for (i=L2I0; i<=L2I; i++) Y += y[i];
    for (i=L3I0; i<=L3I; i++) Y += y[i];
  }
  else if (Table->TYPE_of_MODEL == 3){
    Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; 
    Y = 0.0;
    for(i=0; i<Table->No_of_LOCAL_POPULATIONS; i++) {
      for (j=Table->L_0I0[i]; j<=Table->L_0I[i]; j++) Y += y[j];
      for (j=Table->L_1I0[i]; j<=Table->L_1I[i]; j++) Y += y[j];
      for (j=Table->L_2I0[i]; j<=Table->L_2I[i]; j++) Y += y[j];
      for (j=Table->L_3I0[i]; j<=Table->L_3I[i]; j++) Y += y[j];
    }
  }
  else {
    printf("TYPE_of_MODEL out of range!!!");
    printf("This model identifier has not been setup");
    printf(" The program will exit\n");
    exit(0);
  }

  Infection = Y;

  return(Infection);
}

double Total_Detected_Infected_Population  ( const double * y, Parameter_Table * Table )
{
  int i, Q; 
  double Y;
  double Infection;

  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>
  
  if (Table->TYPE_of_MODEL == 0) {
    Y = y[nI2] + y[nY]; /* Strong and Severe Hospital Cases */ 
  }
  else if (Table->TYPE_of_MODEL == 1) {
    Y=0.0;
    Y += y[n0I2] + y[n0Y];
    Y += y[n1I2] + y[n1Y];
    Y += y[n2I2] + y[n2Y];
    Y += y[n3I2] + y[n3Y];
  }
  else if (Table->TYPE_of_MODEL == 2) {
    Y=0.0;
    Y += y[n0I2] + y[n0Y] + y[n0Ad];
    Y += y[n1I2] + y[n1Y] + y[n1Ad];
    Y += y[n2I2] + y[n2Y] + y[n2Ad];
    Y += y[n3I2] + y[n3Y] + y[n3Ad];
  }
  else if (Table->TYPE_of_MODEL == 3){
    Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; 
    Y = 0.0;
    for(i=0; i<Table->No_of_LOCAL_POPULATIONS; i++) {
      Y += y[Table->n0I2+i*Q] + y[Table->n0Y+i*Q] + y[Table->n0Ad+i*Q];
      Y += y[Table->n1I2+i*Q] + y[Table->n1Y+i*Q] + y[Table->n1Ad+i*Q];
      Y += y[Table->n2I2+i*Q] + y[Table->n2Y+i*Q] + y[Table->n2Ad+i*Q];
      Y += y[Table->n3I2+i*Q] + y[Table->n3Y+i*Q] + y[Table->n3Ad+i*Q];
    }
  }
  else {
    printf("TYPE_of_MODEL out of range!!!");
    printf("This model identifier has not been setup");
    printf(" The program will exit\n");
    exit(0);
  }

  Infection = Y;
  
  return(Infection);
}


