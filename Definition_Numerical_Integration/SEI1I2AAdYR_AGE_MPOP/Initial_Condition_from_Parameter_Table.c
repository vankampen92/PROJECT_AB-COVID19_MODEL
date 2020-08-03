#include <MODEL.h>

extern gsl_rng * r;

void Initial_Condition_from_Parameter_Table(Parameter_Table * Table, double *Y)
{
  int J, Q;
  
  Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; /* Ex: 11 times 4 */
  
  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>
  
  for (J=0; J<Table->No_of_LOCAL_POPULATIONS; J++) {

    n0S = Table->n0S+J*Q; n0E = Table->n0E+J*Q;   n0I1 = Table->n0I1+J*Q; n0I2 = Table->n0I2+J*Q;
    n0A = Table->n0A+J*Q; n0Ad = Table->n0Ad+J*Q; n0Y = Table->n0Y+J*Q; n0R = Table->n0R+J*Q;
    a0I = Table->a0I+J*Q; a0R = Table->a0R+J*Q;   a0D  = Table->a0D+J*Q;

    n1S = Table->n1S+J*Q; n1E = Table->n1E+J*Q;   n1I1 = Table->n1I1+J*Q; n1I2 = Table->n1I2+J*Q;
    n1A = Table->n1A+J*Q; n1Ad = Table->n1Ad+J*Q; n1Y = Table->n1Y+J*Q; n1R = Table->n1R+J*Q;
    a1I = Table->a1I+J*Q; a1R = Table->a1R+J*Q;   a1D  = Table->a1D+J*Q;

    n2S = Table->n2S+J*Q; n2E = Table->n2E+J*Q;   n2I1 = Table->n2I1+J*Q; n2I2 = Table->n2I2+J*Q;
    n2A = Table->n2A+J*Q; n2Ad = Table->n2Ad+J*Q; n2Y = Table->n2Y+J*Q; n2R = Table->n2R+J*Q;
    a2I = Table->a2I+J*Q; a2R = Table->a2R+J*Q;   a2D  = Table->a2D+J*Q;

    n3S = Table->n3S+J*Q; n3E = Table->n3E+J*Q; n3I1 = Table->n3I1+J*Q; n3I2 = Table->n3I2+J*Q;
    n3A = Table->n3A+J*Q; n3Ad = Table->n3Ad+J*Q;   n3Y = Table->n3Y+J*Q; n3R = Table->n3R+J*Q;
    a3I = Table->a3I+J*Q; a3R = Table->a3R+J*Q; a3D  = Table->a3D+J*Q;

    Y[n0S]  = Table->n0S___0[J];
    Y[n0E]  = Table->n0E___0[J];
    Y[n0I1] = Table->n0I1___0[J];
    Y[n0I2] = Table->n0I2___0[J];
    Y[n0A]  = Table->n0A___0[J];
    Y[n0Ad] = Table->n0Ad___0[J];
    Y[n0Y]  = Table->n0Y___0[J];
    Y[n0R]  = Table->n0R___0[J];
    Y[a0I]  = Table->a0I___0[J];
    Y[a0R]  = Table->a0R___0[J];
    Y[a0D]  = Table->a0D___0[J];
    
    Y[n1S]  = Table->n1S___0[J];
    Y[n1E]  = Table->n1E___0[J];
    Y[n1I1] = Table->n1I1___0[J];
    Y[n1I2] = Table->n1I2___0[J];
    Y[n1A]  = Table->n1A___0[J];
    Y[n1Ad] = Table->n1Ad___0[J];
    Y[n1Y]  = Table->n1Y___0[J];
    Y[n1R]  = Table->n1R___0[J];
    Y[a1I]  = Table->a1I___0[J];
    Y[a1R]  = Table->a1R___0[J];
    Y[a1D]  = Table->a1D___0[J];

    Y[n2S]  = Table->n2S___0[J];
    Y[n2E]  = Table->n2E___0[J];
    Y[n2I1] = Table->n2I1___0[J];
    Y[n2I2] = Table->n2I2___0[J];
    Y[n2A]  = Table->n2A___0[J];
    Y[n2Ad] = Table->n2Ad___0[J];
    Y[n2Y]  = Table->n2Y___0[J];
    Y[n2R]  = Table->n2R___0[J];
    Y[a2I]  = Table->a2I___0[J];
    Y[a2R]  = Table->a2R___0[J];
    Y[a2D]  = Table->a2D___0[J];
    
    Y[n3S]  = Table->n3S___0[J];
    Y[n3E]  = Table->n3E___0[J];
    Y[n3I1] = Table->n3I1___0[J];
    Y[n3I2] = Table->n3I2___0[J];
    Y[n3A]  = Table->n3A___0[J];
    Y[n3Ad] = Table->n3Ad___0[J];
    Y[n3Y]  = Table->n3Y___0[J];
    Y[n3R]  = Table->n3R___0[J];
    Y[a3I]  = Table->a3I___0[J];
    Y[a3R]  = Table->a3R___0[J];
    Y[a3D]  = Table->a3D___0[J];
  }

  if(Table->RESCALING_INITIAL_TOTAL_POPULATION == 1)
    R_E_S_C_A_L_I_N_G___I_N_I_T_I_A_L___C_O_N_D_I_T_I_O_N_S ( Table, Y );

}

void R_E_S_C_A_L_I_N_G___I_N_I_T_I_A_L___C_O_N_D_I_T_I_O_N_S ( Parameter_Table * Table, double * Y)
{
    int i;
    double g_H, E_x, x, y;
    int J, Q;

    Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; /* Ex: 11 times 4 */
    
    /* Definition of the state vector numerical order, from 0 to K, of model variables */
    #include <Model_Variables_Code.Include.c>

    y = 0.0;
    for( i = 0; i <= K; i++ ) y += Y[i];
    for( i = 0; i <= K; i++ ) Y[i] = Y[i]/y * Table->INITIAL_TOTAL_POPULATION;

    /* g_H  = Table->n_H * Table->H_Gamma /(Table->n_H * Table->H_Gamma + Table->H_Delta);             */
    /* x    = ( 1.0 - g_H) / ( 1.0 - pow(g_H, (double)(Table->n_H)) ) ;                                */
    /* E_x  = Y[E] * x;                                                                                */

    /* Y[E] = E_x;                                                    /\* E_1 *\/                      */
    /* for(i=1+E; i < I; i++) Y[i] = pow(g_H, (double)(i-1)) * E_x;  /\* E_n *\/                       */

    /* Rescaled (Corrected) Initial Conditions */
    for (J=0; J<Table->No_of_LOCAL_POPULATIONS; J++) {

      n0S = Table->n0S+J*Q; n0E = Table->n0E+J*Q;   n0I1 = Table->n0I1+J*Q; n0I2 = Table->n0I2+J*Q;
      n0A = Table->n0A+J*Q; n0Ad = Table->n0Ad+J*Q; n0Y = Table->n0Y+J*Q; n0R = Table->n0R+J*Q;
      a0I = Table->a0I+J*Q; a0R = Table->a0R+J*Q;   a0D  = Table->a0D+J*Q;

      n1S = Table->n1S+J*Q; n1E = Table->n1E+J*Q;   n1I1 = Table->n1I1+J*Q; n1I2 = Table->n1I2+J*Q;
      n1A = Table->n1A+J*Q; n1Ad = Table->n1Ad+J*Q; n1Y = Table->n1Y+J*Q; n1R = Table->n1R+J*Q;
      a1I = Table->a1I+J*Q; a1R = Table->a1R+J*Q;   a1D  = Table->a1D+J*Q;

      n2S = Table->n2S+J*Q; n2E = Table->n2E+J*Q;   n2I1 = Table->n2I1+J*Q; n2I2 = Table->n2I2+J*Q;
      n2A = Table->n2A+J*Q; n2Ad = Table->n2Ad+J*Q; n2Y = Table->n2Y+J*Q; n2R = Table->n2R+J*Q;
      a2I = Table->a2I+J*Q; a2R = Table->a2R+J*Q;   a2D  = Table->a2D+J*Q;

      n3S = Table->n3S+J*Q; n3E = Table->n3E+J*Q; n3I1 = Table->n3I1+J*Q; n3I2 = Table->n3I2+J*Q;
      n3A = Table->n3A+J*Q; n3Ad = Table->n3Ad+J*Q;   n3Y = Table->n3Y+J*Q; n3R = Table->n3R+J*Q;
      a3I = Table->a3I+J*Q; a3R = Table->a3R+J*Q; a3D  = Table->a3D+J*Q;

      Table->n0S___0[J]  =  Y[n0S];
      Table->n0E___0[J]  =  Y[n0E];
      Table->n0I1___0[J]  =  Y[n0I1];
      Table->n0I2___0[J]  =  Y[n0I2];
      Table->n0A___0[J]  =  Y[n0A];
      Table->n0Ad___0[J]  =  Y[n0Ad];
      Table->n0Y___0[J]  =  Y[n0Y];
      Table->n0R___0[J]  =  Y[n0R];
      Table->a0I___0[J]  =  Y[a0I];
      Table->a0R___0[J]  =  Y[a0R];
      Table->a0D___0[J]  =  Y[a0D];
      
      Table->n1S___0[J]  =  Y[n1S];
      Table->n1E___0[J]  =  Y[n1E];
      Table->n1I1___0[J]  =  Y[n1I1];
      Table->n1I2___0[J]  =  Y[n1I2];
      Table->n1A___0[J]  =  Y[n1A];
      Table->n1Ad___0[J]  =  Y[n1Ad];
      Table->n1Y___0[J]  =  Y[n1Y];
      Table->n1R___0[J]  =  Y[n1R];
      Table->a1I___0[J]  =  Y[a1I];
      Table->a1R___0[J]  =  Y[a1R];
      Table->a1D___0[J]  =  Y[a1D];
      
      Table->n2S___0[J]  =  Y[n2S];
      Table->n2E___0[J]  =  Y[n2E];
      Table->n2I1___0[J]  =  Y[n2I1];
      Table->n2I2___0[J]  =  Y[n2I2];
      Table->n2A___0[J]  =  Y[n2A];
      Table->n2Ad___0[J]  =  Y[n2Ad];
      Table->n2Y___0[J]  =  Y[n2Y];
      Table->n2R___0[J]  =  Y[n2R];
      Table->a2I___0[J]  =  Y[a2I];
      Table->a2R___0[J]  =  Y[a2R];
      Table->a2D___0[J]  =  Y[a2D];
      
      Table->n3S___0[J]  =  Y[n3S];
      Table->n3E___0[J]  =  Y[n3E];
      Table->n3I1___0[J]  =  Y[n3I1];
      Table->n3I2___0[J]  =  Y[n3I2];
      Table->n3A___0[J]  =  Y[n3A];
      Table->n3Ad___0[J]  =  Y[n3Ad];
      Table->n3Y___0[J]  =  Y[n3Y];
      Table->n3R___0[J]  =  Y[n3R];
      Table->a3I___0[J]  =  Y[a3I];
      Table->a3R___0[J]  =  Y[a3R];
      Table->a3D___0[J]  =  Y[a3D];
    }
}

void Initial_Condition_from_Data_into_Parameter_Table (Parameter_Table * Table, double ** Data)
{
  /* Initial conditions from empirical data at the initial time ( -xn 0 ) */
  
  int J;
      
  Table->INITIAL_TOTAL_POPULATION          = Data[0][0];

  for (J=0; J<Table->No_of_LOCAL_POPULATIONS; J++) {
      Table->n0S___0[J]  = Table->INITIAL_TOTAL_POPULATION - 1.0;
      Table->n0E___0[J]  = 1.0;
      Table->n0I1___0[J] = 0.0;
      Table->n0I2___0[J] = 0.0;
      Table->n0Y___0[J]  = 0.0;
      Table->n0A___0[J]  = 0.0;
      Table->n0Ad___0[J]  = 0.0;
      Table->n0R___0[J]  = 0.0;
      Table->a0I___0[J]  = 1.0;
      Table->a0R___0[J]  = 0.0;
      Table->a0D___0[J]  = 0.0;
      
      Table->n1S___0[J]  = Table->INITIAL_TOTAL_POPULATION - 1.0;
      Table->n1E___0[J]  = 1.0;
      Table->n1I1___0[J] = 0.0;
      Table->n1I2___0[J] = 0.0;
      Table->n1A___0[J]  = 0.0;
      Table->n1Ad___0[J]  = 0.0;
      Table->n1Y___0[J]  = 0.0;
      Table->n1R___0[J]  = 0.0;
      Table->a1I___0[J]  = 1.0;
      Table->a1R___0[J]  = 0.0;
      Table->a1D___0[J]  = 0.0;
      
      Table->n2S___0[J]  = Table->INITIAL_TOTAL_POPULATION - 1.0;
      Table->n2E___0[J]  = 1.0;
      Table->n2I1___0[J] = 0.0;
      Table->n2I2___0[J] = 0.0;
      Table->n2A___0[J]  = 0.0;
      Table->n2Ad___0[J]  = 0.0;
      Table->n2Y___0[J]  = 0.0;
      Table->n2R___0[J]  = 0.0;
      Table->a2I___0[J]  = 1.0;
      Table->a2R___0[J]  = 0.0;
      Table->a2D___0[J]  = 0.0;
      
      Table->n3S___0[J]  = Table->INITIAL_TOTAL_POPULATION - 1.0;
      Table->n3E___0[J]  = 1.0;
      Table->n3I1___0[J] = 0.0;
      Table->n3I2___0[J] = 0.0;
      Table->n3A___0[J]  = 0.0;
      Table->n3Ad___0[J]  = 0.0;
      Table->n3Y___0[J]  = 0.0;
      Table->n3R___0[J]  = 0.0;
      Table->a3I___0[J]  = 1.0;
      Table->a3R___0[J]  = 0.0;
      Table->a3D___0[J]  = 0.0;
    }
}

void Initial_Condition_from_Initial_Values_into_Parameter_Table (Parameter_Table * Table,
								 double Initial_Population,
								 double Initial_Exposed_Population,
								 double Initial_Assymptomatic_Population )
{
  /* Initial conditions from empirical data at the initial time ( -xn 0 ) */
  
   int J;


   for (J=0; J<Table->No_of_LOCAL_POPULATIONS; J++) {
    
    Table->n0S___0[J]  = Table->INITIAL_TOTAL_POPULATION - Initial_Exposed_Population - Initial_Assymptomatic_Population;
    Table->n0E___0[J]  = Initial_Exposed_Population;
    Table->n0I1___0[J] = 0.0;
    Table->n0I2___0[J] = 0.0;
    Table->n0Y___0[J]  = 0.0;
    Table->n0A___0[J]  = Initial_Assymptomatic_Population;
    Table->n0Ad___0[J]  = 0.0;
    Table->n0R___0[J]  = 0.0;
    Table->a0I___0[J]  = 0.0; 
    Table->a0R___0[J]  = 0.0;
    Table->a0D___0[J]  = 0.0;

    Table->n1S___0[J]  = Table->INITIAL_TOTAL_POPULATION - Initial_Exposed_Population - Initial_Assymptomatic_Population;
    Table->n1E___0[J]  = Initial_Exposed_Population;
    Table->n1I1___0[J] = 0.0;
    Table->n1I2___0[J] = 0.0;
    Table->n1A___0[J]  = Initial_Assymptomatic_Population;
    Table->n1Ad___0[J]  = 0.0;
    Table->n1Y___0[J]  = 0.0;
    Table->n1R___0[J]  = 0.0;
    Table->a1I___0[J]  = 0.0; 
    Table->a1R___0[J]  = 0.0;
    Table->a1D___0[J]  = 0.0;

    Table->n2S___0[J]  = Table->INITIAL_TOTAL_POPULATION - Initial_Exposed_Population - Initial_Assymptomatic_Population;
    Table->n2E___0[J]  = Initial_Exposed_Population;
    Table->n2I1___0[J] = 0.0;
    Table->n2I2___0[J] = 0.0;
    Table->n2A___0[J]  = Initial_Assymptomatic_Population;
    Table->n2Ad___0[J]  = 0.0;
    Table->n2Y___0[J]  = 0.0;
    Table->n2R___0[J]  = 0.0;
    Table->a2I___0[J]  = 0.0; 
    Table->a2R___0[J]  = 0.0;
    Table->a2D___0[J]  = 0.0;

    Table->n3S___0[J]  = Table->INITIAL_TOTAL_POPULATION - Initial_Exposed_Population - Initial_Assymptomatic_Population;
    Table->n3E___0[J]  = Initial_Exposed_Population;
    Table->n3I1___0[J] = 0.0;
    Table->n3I2___0[J] = 0.0;
    Table->n3A___0[J]  = Initial_Assymptomatic_Population;
    Table->n3Ad___0[J]  = 0.0;
    Table->n3Y___0[J]  = 0.0;
    Table->n3R___0[J]  = 0.0;
    Table->a3I___0[J]  = 0.0; 
    Table->a3R___0[J]  = 0.0;
    Table->a3D___0[J]  = 0.0;
  } 
}

void Initial_Condition_from_Value_into_Parameter_Table (Parameter_Table * Table, double Value)
{
  /* Initial conditions from empirical data at the initial time ( -xn 0 ) */

  /* Value should represent the inital value of exposed individuals in the first age class */

  int J;
  
   for (J=0; J<Table->No_of_LOCAL_POPULATIONS; J++) {
  
     Table->n0S___0[J]  = Table->N_0[J] - Value;
     Table->n0E___0[J]  = Value;
     Table->n0I1___0[J] = 0.0;
     Table->n0I2___0[J] = 0.0;
     Table->n0A___0[J]  = 0.0; 
     Table->n0Ad___0[J]  = 0.0;
     Table->n0Y___0[J]  = 0.0;
     Table->n0R___0[J]  = 0.0;   
     Table->a0I___0[J]  = 0.0; 
     Table->a0R___0[J]  = 0.0;
     Table->a0D___0[J]  = 0.0;
     
     Table->n1S___0[J]  = Table->N_1[J];
     Table->n1E___0[J]  = 0.0;
     Table->n1I1___0[J] = 0.0;
     Table->n1I2___0[J] = 0.0;
     Table->n1A___0[J]  = 0.0; 
     Table->n1Ad___0[J]  = 0.0; 
     Table->n1Y___0[J]  = 0.0;
     Table->n1R___0[J]  = 0.0;   
     Table->a1I___0[J]  = 0.0; 
     Table->a1R___0[J]  = 0.0;
     Table->a1D___0[J]  = 0.0;
     
     Table->n2S___0[J]  = Table->N_2[J];
     Table->n2E___0[J]  = 0.0;
     Table->n2I1___0[J] = 0.0;
     Table->n2I2___0[J] = 0.0;
     Table->n2A___0[J]  = 0.0; 
     Table->n2Ad___0[J]  = 0.0; 
     Table->n2Y___0[J]  = 0.0;
     Table->n2R___0[J]  = 0.0;   
     Table->a2I___0[J]  = 0.0; 
     Table->a2R___0[J]  = 0.0;
     Table->a2D___0[J]  = 0.0;
     
     Table->n3S___0[J]  = Table->N_3[J];
     Table->n3E___0[J]  = 0.0;
     Table->n3I1___0[J] = 0.0;
     Table->n3I2___0[J] = 0.0;
     Table->n3A___0[J]  = 0.0; 
     Table->n3Ad___0[J]  = 0.0; 
     Table->n3Y___0[J]  = 0.0;
     Table->n3R___0[J]  = 0.0;   
     Table->a3I___0[J]  = 0.0; 
     Table->a3R___0[J]  = 0.0;
     Table->a3D___0[J]  = 0.0;
   }
}
