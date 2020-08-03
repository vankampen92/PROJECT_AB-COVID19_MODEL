#include <MODEL.h>

double Total_Disease_Prevalence  ( const double * y, Parameter_Table * Table )
{
  int i, j, Q; 
  double Y;
  double N; 
  double Prevalence;

  N = Total_Population (y, Table);
  
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

  Prevalence = Y/N;

  /* else { */
  /*   printf(" Number of substages for the low-infectivity, quasi-latent stage (n_Mu) is %d\n", */
  /* 	   Table->n_Mu); */
  /*   printf(" n_Mu > 1 requires a carefull code implementation (which is in-progress)\n"); */
  /*   printf(" The program will exit\nm"); */
  /*   exit(0); */
  /* } */
  
  return(Prevalence);
}



