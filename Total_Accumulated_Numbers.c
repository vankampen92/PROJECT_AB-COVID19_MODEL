#include <MODEL.h>

double Accumulated_Number_of_Detected_Infected ( const double * y, Parameter_Table * Table )
{
  double x;
  int i, Q;
  
  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  if (Table->TYPE_of_MODEL == 0) {
    x = y[aI];
  }
  else if (Table->TYPE_of_MODEL == 1 || Table->TYPE_of_MODEL == 2) {
    x = y[a0I] + y[a1I] + y[a2I] + y[a3I];  
  }
  else if (Table->TYPE_of_MODEL == 3){
    Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; 
    x = 0.0;
    for(i=0; i<Table->No_of_LOCAL_POPULATIONS; i++)
      x += y[Table->a0I+i*Q] + y[Table->a1I+i*Q] + y[Table->a2I+i*Q] + y[Table->a3I+i*Q]; 
  }
  else {
   printf("TYPE_of_MODEL out of range!!!");
    printf("This model identifier has not been setup");
    printf(" The program will exit\n");
    exit(0);
  }

  return (x);
}

double Accumulated_Number_of_Detected_Recovered ( const double * y, Parameter_Table * Table )
{
  double x;
  int i, Q;
  
  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  if (Table->TYPE_of_MODEL == 0) {
    x = y[aR];
  }
  else if (Table->TYPE_of_MODEL == 1 || Table->TYPE_of_MODEL == 2) {
    x = y[a0R] + y[a1R] + y[a2R] + y[a3R];  
  }
  else if (Table->TYPE_of_MODEL == 3){
    Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; 
    x = 0.0;
    for(i=0; i<Table->No_of_LOCAL_POPULATIONS; i++) 
      x += y[Table->a0R+i*Q] + y[Table->a1R+i*Q] + y[Table->a2R+i*Q] + y[Table->a3R+i*Q]; 
  }
  else {
   printf("TYPE_of_MODEL out of range!!!");
    printf("This model identifier has not been setup");
    printf(" The program will exit\n");
    exit(0);
  }

  return (x);
}

double Accumulated_Number_of_Detected_Deaths ( const double * y, Parameter_Table * Table )
{
  double x;
  int i, Q;
  
  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  if (Table->TYPE_of_MODEL == 0) {
    x = y[aD];
  }
  else if (Table->TYPE_of_MODEL == 1 || Table->TYPE_of_MODEL == 2) {
    x = y[a0D] + y[a1D] + y[a2D] + y[a3D]; 
  }
  else if (Table->TYPE_of_MODEL == 3){
    Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; 
    x = 0.0;
    for(i=0; i<Table->No_of_LOCAL_POPULATIONS; i++) 
      x += y[Table->a0D+i*Q] + y[Table->a1D+i*Q] + y[Table->a2D+i*Q] + y[Table->a3D+i*Q]; 
  }
  else {
   printf("TYPE_of_MODEL out of range!!!");
    printf("This model identifier has not been setup");
    printf(" The program will exit\n");
    exit(0);
  }

  return (x);
}





