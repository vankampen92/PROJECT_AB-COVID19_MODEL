#include <MODEL.h>

double Total_Population ( const double * y, Parameter_Table * Table )
{
  double x;
  int i,j,  Q;

  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  if (Table->TYPE_of_MODEL == 0) {
    x = 0.0;
    for (i=0; i<=nR; i++) x += y[i];
  }
  else if (Table->TYPE_of_MODEL == 1 || Table->TYPE_of_MODEL == 2) {
    x = 0.0;
    for (i=n0S; i<=n0R; i++) x += y[i];
    for (i=n1S; i<=n1R; i++) x += y[i];
    for (i=n2S; i<=n2R; i++) x += y[i];
    for (i=n3S; i<=n3R; i++) x += y[i];
  }
  else if (Table->TYPE_of_MODEL == 3){
    Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; 
    x = 0.0;
    for(i=0; i<Table->No_of_LOCAL_POPULATIONS; i++) {
      for (j=Table->n0S+i*Q; j<=Table->n0R+i*Q; j++) x += y[j];
      for (j=Table->n1S+i*Q; j<=Table->n1R+i*Q; j++) x += y[j];
      for (j=Table->n2S+i*Q; j<=Table->n2R+i*Q; j++) x += y[j];
      for (j=Table->n3S+i*Q; j<=Table->n3R+i*Q; j++) x += y[j];
    }
  }
  else {
    printf("TYPE_of_MODEL out of range!!!");
    printf("This model identifier has not been setup");
    printf(" The program will exit\n");
    exit(0);
  }
 
  return (x);
}

double Total_Population_N0 ( const double * y, Parameter_Table * Table )
{
  double x;
  int i, j, Q;

  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  if (Table->TYPE_of_MODEL == 1 || Table->TYPE_of_MODEL == 2) {
    x = 0.0;

    for (i=n0S; i<=n0R; i++) x += y[i];
  }
  else if (Table->TYPE_of_MODEL == 3){
    Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; 
    x = 0.0;
    for(i=0; i<Table->No_of_LOCAL_POPULATIONS; i++) 
      for (j=Table->n0S+i*Q; j<=Table->n0R+i*Q; j++) x += y[j];
  }
  else {
    printf("TYPE_of_MODEL out of range (Total_Population_N0 function)!!!");
    printf("This model identifier has not been setup");
    printf(" The program will exit\n");
    exit(0);
  }
 
  return (x);
}

double Total_Population_N1 ( const double * y, Parameter_Table * Table )
{
  double x;
  int i, j, Q;

  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  if (Table->TYPE_of_MODEL == 1 || Table->TYPE_of_MODEL == 2) {
    x = 0.0;
    
    for (i=n1S; i<=n1R; i++) x += y[i];
  }
  else if (Table->TYPE_of_MODEL == 3){
    Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; 
    x = 0.0;
    for(i=0; i<Table->No_of_LOCAL_POPULATIONS; i++) 
      for (j=Table->n1S+i*Q; j<=Table->n1R+i*Q; j++) x += y[j];
  }
  else {
    printf("TYPE_of_MODEL out of range (Total_Population_N1 function)!!!");
    printf("This model identifier has not been setup");
    printf(" The program will exit\n");
    exit(0);
  }
 
  return (x);
}

double Total_Population_N2 ( const double * y, Parameter_Table * Table )
{
  double x;
  int i, j, Q;

  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  if (Table->TYPE_of_MODEL == 1 || Table->TYPE_of_MODEL == 2) {
    x = 0.0;
    
    for (i=n2S; i<=n2R; i++) x += y[i];
  }
  else if (Table->TYPE_of_MODEL == 3){
    Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; 
    x = 0.0;
    for(i=0; i<Table->No_of_LOCAL_POPULATIONS; i++) 
      for (j=Table->n2S+i*Q; j<=Table->n2R+i*Q; j++) x += y[j];
  }
  else {
    printf("TYPE_of_MODEL out of range (Total_Population_N2 function)!!!");
    printf("This model identifier has not been setup");
    printf(" The program will exit\n");
    exit(0);
  }
 
  return (x);
}

double Total_Population_N3 ( const double * y, Parameter_Table * Table )
{
  double x;
  int i, j, Q;

  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  if (Table->TYPE_of_MODEL == 0 || Table->TYPE_of_MODEL == 2) {
    x = 0.0;
    
    for (i=n3S; i<=n3R; i++) x += y[i];
  }
  else if (Table->TYPE_of_MODEL == 3){
    Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; 
    x = 0.0;
    for(i=0; i<Table->No_of_LOCAL_POPULATIONS; i++) 
      for (j=Table->n3S+i*Q; j<=Table->n3R+i*Q; j++) x += y[j];
  }
  else {
    printf("TYPE_of_MODEL out of range (Total_Population_N3 function)!!!");
    printf("This model identifier has not been setup");
    printf(" The program will exit\n");
    exit(0);
  }
 
  return (x);
}

double Total_Local_Population( const double * y, int n, Parameter_Table * Table )
{
  int i, j, Q;
  double x;
  
  Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; 
  x = 0.0;
  
  for (j=Table->n0S+n*Q; j<=Table->n0R+n*Q; j++) x += y[j];
  for (j=Table->n1S+n*Q; j<=Table->n1R+n*Q; j++) x += y[j];
  for (j=Table->n2S+n*Q; j<=Table->n2R+n*Q; j++) x += y[j];
  for (j=Table->n3S+n*Q; j<=Table->n3R+n*Q; j++) x += y[j];

  return (x); 
}

double Total_Local_Population_N0( const double * y, int n, Parameter_Table * Table )
{
  int i, j, Q;
  double x;
  
  Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; 
  x = 0.0;
  
  for (j=Table->n0S+n*Q; j<=Table->n0R+n*Q; j++) x += y[j];
  

  return (x); 
}

double Total_Local_Population_N1( const double * y, int n, Parameter_Table * Table )
{
  int i, j, Q;
  double x;
  
  Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; 
  x = 0.0;
  
  for (j=Table->n1S+n*Q; j<=Table->n1R+n*Q; j++) x += y[j];

  return (x); 
}

double Total_Local_Population_N2( const double * y, int n, Parameter_Table * Table )
{
  int i, j, Q;
  double x;
  
  Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; 
  x = 0.0;
 
  for (j=Table->n2S+n*Q; j<=Table->n2R+n*Q; j++) x += y[j];
  
  return (x); 
}

double Total_Local_Population_N3( const double * y, int n, Parameter_Table * Table )
{
  int i, j, Q;
  double x;
  
  Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; 
  x = 0.0;
 
  for (j=Table->n3S+n*Q; j<=Table->n3R+n*Q; j++) x += y[j];

  return (x); 
}
