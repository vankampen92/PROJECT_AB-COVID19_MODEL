#include <MODEL.h>

double Fraction_of_Susceptible_Population ( const double * y, Parameter_Table * Table )
{
  double x;
  double N;
  int i, Q;

  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  N = Total_Population (y, Table);

  if (Table->TYPE_of_MODEL == 0) {
    x = y[nS]/N;
  }
  else if (Table->TYPE_of_MODEL == 1 || Table->TYPE_of_MODEL == 2) {
    x = (y[n0S] + y[n1S] + y[n2S] + y[n3S])/N;
  }
  else if (Table->TYPE_of_MODEL == 3){
    Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; 
    x = 0.0;
    for(i=0; i<Table->No_of_LOCAL_POPULATIONS; i++)
      x += (y[Table->n0S+i*Q] + y[Table->n1S+i*Q] + y[Table->n2S+i*Q] + y[Table->n3S+i*Q])/N; 
  }
  else {
   printf("TYPE_of_MODEL out of range!!!");
    printf("This model identifier has not been setup");
    printf(" The program will exit\n");
    exit(0);
  }

  return (x);
}

double Fraction_of_Exposed_Population ( const double * y, Parameter_Table * Table )
{
  double x;
  double N;
  int i, Q;;

  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  N = Total_Population (y, Table);

  if (Table->TYPE_of_MODEL == 0) {
    x = y[nE]/N;
  }
  else if (Table->TYPE_of_MODEL == 1 || Table->TYPE_of_MODEL == 2) {
    x = (y[n0E] + y[n1E] + y[n2E] + y[n3E])/N;
  }
  else if (Table->TYPE_of_MODEL == 3){
    Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; 
    x = 0.0;
    for(i=0; i<Table->No_of_LOCAL_POPULATIONS; i++)
      x += (y[Table->n0E+i*Q] + y[Table->n1E+i*Q] + y[Table->n2E+i*Q] + y[Table->n3E+i*Q])/N; 
  }
  else {
   printf("TYPE_of_MODEL out of range!!!");
    printf("This model identifier has not been setup");
    printf(" The program will exit\n");
    exit(0);
  }

  return (x);
}

double Fraction_of_Pre_Symptomatic_Population ( const double * y, Parameter_Table * Table )
{
  double x;
  double N;
  int i, Q;

  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  N = Total_Population (y, Table);

  if (Table->TYPE_of_MODEL == 0) {
    x = y[nI1]/N;
  }
  else if (Table->TYPE_of_MODEL == 1 || Table->TYPE_of_MODEL == 2) {
    x = (y[n0I1] + y[n1I1] + y[n2I1] + y[n3I1] )/N;
  }
  else if (Table->TYPE_of_MODEL == 3){
    Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; 
    x = 0.0;
    for(i=0; i<Table->No_of_LOCAL_POPULATIONS; i++) 
      x += (y[Table->n0I1+i*Q] + y[Table->n1I1+i*Q] + y[Table->n2I1+i*Q] + y[Table->n3I1+i*Q])/N; 
  }
  else {
   printf("TYPE_of_MODEL out of range!!!");
    printf("This model identifier has not been setup");
    printf(" The program will exit\n");
    exit(0);
  }

  return (x);
}

double Fraction_of_Strongly_Infected_Population ( const double * y, Parameter_Table * Table )
{
  double x;
  double N;
  int i, Q;

  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  N = Total_Population (y, Table);

  if (Table->TYPE_of_MODEL == 0) {
    x = y[nI2]/N;
  }
  else if (Table->TYPE_of_MODEL == 1 || Table->TYPE_of_MODEL == 2) {
    x = (y[n0I2] + y[n1I2] + y[n2I2] + y[n3I2])/N;
  }
  else if (Table->TYPE_of_MODEL == 3){
    Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; 
    x = 0.0;
    for(i=0; i<Table->No_of_LOCAL_POPULATIONS; i++) 
      x += (y[Table->n0I2+i*Q] + y[Table->n2I2+i*Q] + y[Table->n2I2+i*Q] + y[Table->n3I2+i*Q])/N; 
  }
  else {
   printf("TYPE_of_MODEL out of range!!!");
    printf("This model identifier has not been setup");
    printf(" The program will exit\n");
    exit(0);
  }

  return (x);
}

double Fraction_of_A_Symptomatic_Population ( const double * y, Parameter_Table * Table )
{
  double x;
  double N;
  int i, Q;

  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  N = Total_Population (y, Table);

  if (Table->TYPE_of_MODEL == 0) {
    x = y[nA]/N;
  }
  else if (Table->TYPE_of_MODEL == 1) {
    x = (y[n0A] + y[n1A] + y[n2A] + y[n3A])/N;
  }
  else if (Table->TYPE_of_MODEL == 2) {
    x = (y[n0A]+y[n0Ad] + y[n1A]+y[n1Ad] + y[n2A]+y[n2Ad] + y[n3A]+y[n3Ad])/N;
  }
  else if (Table->TYPE_of_MODEL == 3){
    Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; 
    x = 0.0;
    for(i=0; i<Table->No_of_LOCAL_POPULATIONS; i++) 
      x += (y[Table->n0A+i*Q]+y[Table->n0Ad+i*Q] + y[Table->n1A+i*Q]+y[Table->n1Ad+i*Q] + y[Table->n2A+i*Q]+y[Table->n2Ad+i*Q] + y[Table->n3A+i*Q]+y[Table->n3Ad+i*Q])/N; 
  }
  else {
   printf("TYPE_of_MODEL out of range!!!");
    printf("This model identifier has not been setup");
    printf(" The program will exit\n");
    exit(0);
  }

  return (x);
}

double Fraction_of_Seriously_Infected_Population ( const double * y, Parameter_Table * Table )
{
  double x;
  double N;
  int i, Q;

  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  N = Total_Population (y, Table);

  if (Table->TYPE_of_MODEL == 0) {
    x = y[nY]/N;
  }
  else if (Table->TYPE_of_MODEL == 1 || Table->TYPE_of_MODEL == 2) {
    x = (y[n0Y] + y[n1Y] + y[n2Y] + y[n3Y])/N;
  }
  else if (Table->TYPE_of_MODEL == 3){
    Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; 
    x = 0.0;
    for(i=0; i<Table->No_of_LOCAL_POPULATIONS; i++) 
      x += (y[Table->n0Y+i*Q] + y[Table->n2Y+i*Q] + y[Table->n2Y+i*Q] + y[Table->n3Y+i*Q])/N; 
  }
  else {
   printf("TYPE_of_MODEL out of range!!!");
    printf("This model identifier has not been setup");
    printf(" The program will exit\n");
    exit(0);
  }

  return (x);
}

double Fraction_of_Recovered_Population ( const double * y, Parameter_Table * Table )
{
  double x;
  double N;
  int i, Q;

  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  N = Total_Population (y, Table);

  if (Table->TYPE_of_MODEL == 0) {
    x = y[nR]/N;
  }
  else if (Table->TYPE_of_MODEL == 1 || Table->TYPE_of_MODEL == 2) {
    x = (y[n0R] + y[n1R] + y[n2R] + y[n3R])/N;
  }
  else if (Table->TYPE_of_MODEL == 3){
    Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; 
    x = 0.0;
    for(i=0; i<Table->No_of_LOCAL_POPULATIONS; i++) 
      x += (y[Table->n0R+i*Q] + y[Table->n2R+i*Q] + y[Table->n2R+i*Q] + y[Table->n3R+i*Q])/N; 
  }
  else {
   printf("TYPE_of_MODEL out of range!!!");
    printf("This model identifier has not been setup");
    printf(" The program will exit\n");
    exit(0);
  }

  return (x);
}



