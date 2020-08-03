#include <MODEL.h>

extern gsl_rng * r;

void Initial_Condition_from_Parameter_Table(Parameter_Table * Table, double *Y)
{

  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  Y[n0S]  = Table->n0S__0;
  Y[n0E]  = Table->n0E__0;
  Y[n0I1] = Table->n0I1__0;
  Y[n0I2] = Table->n0I2__0;
  Y[n0A]  = Table->n0A__0;
  Y[n0Y]  = Table->n0Y__0;
  Y[n0R]  = Table->n0R__0;
  Y[a0I]  = Table->a0I__0;
  Y[a0R]  = Table->a0R__0;
  Y[a0D]  = Table->a0D__0;

  Y[n1S]  = Table->n1S__0;
  Y[n1E]  = Table->n1E__0;
  Y[n1I1] = Table->n1I1__0;
  Y[n1I2] = Table->n1I2__0;
  Y[n1A]  = Table->n1A__0;
  Y[n1Y]  = Table->n1Y__0;
  Y[n1R]  = Table->n1R__0;
  Y[a1I]  = Table->a1I__0;
  Y[a1R]  = Table->a1R__0;
  Y[a1D]  = Table->a1D__0;

  Y[n2S]  = Table->n2S__0;
  Y[n2E]  = Table->n2E__0;
  Y[n2I1] = Table->n2I1__0;
  Y[n2I2] = Table->n2I2__0;
  Y[n2A]  = Table->n2A__0;
  Y[n2Y]  = Table->n2Y__0;
  Y[n2R]  = Table->n2R__0;
  Y[a2I]  = Table->a2I__0;
  Y[a2R]  = Table->a2R__0;
  Y[a2D]  = Table->a2D__0;

  Y[n3S]  = Table->n3S__0;
  Y[n3E]  = Table->n3E__0;
  Y[n3I1] = Table->n3I1__0;
  Y[n3I2] = Table->n3I2__0;
  Y[n3A]  = Table->n3A__0;
  Y[n3Y]  = Table->n3Y__0;
  Y[n3R]  = Table->n3R__0;
  Y[a3I]  = Table->a3I__0;
  Y[a3R]  = Table->a3R__0;
  Y[a3D]  = Table->a3D__0;
  
  if(Table->RESCALING_INITIAL_TOTAL_POPULATION == 1)
    R_E_S_C_A_L_I_N_G___I_N_I_T_I_A_L___C_O_N_D_I_T_I_O_N_S ( Table, Y );

}

void R_E_S_C_A_L_I_N_G___I_N_I_T_I_A_L___C_O_N_D_I_T_I_O_N_S ( Parameter_Table * Table, double * Y)
{
    int i;
    double g_H, E_x, x, y;

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
  
    Table->n0S__0  =  Y[n0S];
    Table->n0E__0  =  Y[n0E];
    Table->n0I1__0  =  Y[n0I1];
    Table->n0I2__0  =  Y[n0I2];
    Table->n0A__0  =  Y[n0A];
    Table->n0Y__0  =  Y[n0Y];
    Table->n0R__0  =  Y[n0R];
    Table->a0I__0  =  Y[a0I];
    Table->a0R__0  =  Y[a0R];
    Table->a0D__0  =  Y[a0D];

    Table->n1S__0  =  Y[n1S];
    Table->n1E__0  =  Y[n1E];
    Table->n1I1__0  =  Y[n1I1];
    Table->n1I2__0  =  Y[n1I2];
    Table->n1A__0  =  Y[n1A];
    Table->n1Y__0  =  Y[n1Y];
    Table->n1R__0  =  Y[n1R];
    Table->a1I__0  =  Y[a1I];
    Table->a1R__0  =  Y[a1R];
    Table->a1D__0  =  Y[a1D];

    Table->n2S__0  =  Y[n2S];
    Table->n2E__0  =  Y[n2E];
    Table->n2I1__0  =  Y[n2I1];
    Table->n2I2__0  =  Y[n2I2];
    Table->n2A__0  =  Y[n2A];
    Table->n2Y__0  =  Y[n2Y];
    Table->n2R__0  =  Y[n2R];
    Table->a2I__0  =  Y[a2I];
    Table->a2R__0  =  Y[a2R];
    Table->a2D__0  =  Y[a2D];
    
    Table->n3S__0  =  Y[n3S];
    Table->n3E__0  =  Y[n3E];
    Table->n3I1__0  =  Y[n3I1];
    Table->n3I2__0  =  Y[n3I2];
    Table->n3A__0  =  Y[n3A];
    Table->n3Y__0  =  Y[n3Y];
    Table->n3R__0  =  Y[n3R];
    Table->a3I__0  =  Y[a3I];
    Table->a3R__0  =  Y[a3R];
    Table->a3D__0  =  Y[a3D];
}

void Initial_Condition_from_Data_into_Parameter_Table (Parameter_Table * Table, double ** Data)
{
  /* Initial conditions from empirical data at the initial time ( -xn 0 ) */
  
    Table->INITIAL_TOTAL_POPULATION          = Data[0][0];
  
    Table->n0S__0  = Table->INITIAL_TOTAL_POPULATION - 1.0;
    Table->n0E__0  = 1.0;
    Table->n0I1__0 = 0.0;
    Table->n0I2__0 = 0.0;
    Table->n0A__0  = 0.0;
    Table->n0Y__0  = 0.0;
    Table->n0R__0  = 0.0;
    Table->a0I__0  = 1.0;
    Table->a0R__0  = 0.0;
    Table->a0D__0  = 0.0;

    Table->n1S__0  = Table->INITIAL_TOTAL_POPULATION - 1.0;
    Table->n1E__0  = 1.0;
    Table->n1I1__0 = 0.0;
    Table->n1I2__0 = 0.0;
    Table->n1A__0  = 0.0;
    Table->n1Y__0  = 0.0;
    Table->n1R__0  = 0.0;
    Table->a1I__0  = 1.0;
    Table->a1R__0  = 0.0;
    Table->a1D__0  = 0.0;

    Table->n2S__0  = Table->INITIAL_TOTAL_POPULATION - 1.0;
    Table->n2E__0  = 1.0;
    Table->n2I1__0 = 0.0;
    Table->n2I2__0 = 0.0;
    Table->n2A__0  = 0.0;
    Table->n2Y__0  = 0.0;
    Table->n2R__0  = 0.0;
    Table->a2I__0  = 1.0;
    Table->a2R__0  = 0.0;
    Table->a2D__0  = 0.0;

    Table->n3S__0  = Table->INITIAL_TOTAL_POPULATION - 1.0;
    Table->n3E__0  = 1.0;
    Table->n3I1__0 = 0.0;
    Table->n3I2__0 = 0.0;
    Table->n3A__0  = 0.0;
    Table->n3Y__0  = 0.0;
    Table->n3R__0  = 0.0;
    Table->a3I__0  = 1.0;
    Table->a3R__0  = 0.0;
    Table->a3D__0  = 0.0;
}

void Initial_Condition_from_Initial_Values_into_Parameter_Table (Parameter_Table * Table,
								 double Initial_Population,
								 double Initial_Exposed_Population,
								 double Initial_Assymptomatic_Population )
{
  /* Initial conditions from empirical data at the initial time ( -xn 0 ) */
  
    Table->INITIAL_TOTAL_POPULATION          = Initial_Population;
 
    Table->n0S__0  = Table->INITIAL_TOTAL_POPULATION - Initial_Exposed_Population - Initial_Assymptomatic_Population;
    Table->n0E__0  = Initial_Exposed_Population;
    Table->n0I1__0 = 0.0;
    Table->n0I2__0 = 0.0;
    Table->n0A__0  = Initial_Assymptomatic_Population;
    Table->n0Y__0  = 0.0;
    Table->n0R__0  = 0.0;
    Table->a0I__0  = 0.0; 
    Table->a0R__0  = 0.0;
    Table->a0D__0  = 0.0;

    Table->n1S__0  = Table->INITIAL_TOTAL_POPULATION - Initial_Exposed_Population - Initial_Assymptomatic_Population;
    Table->n1E__0  = Initial_Exposed_Population;
    Table->n1I1__0 = 0.0;
    Table->n1I2__0 = 0.0;
    Table->n1A__0  = Initial_Assymptomatic_Population;
    Table->n1Y__0  = 0.0;
    Table->n1R__0  = 0.0;
    Table->a1I__0  = 0.0; 
    Table->a1R__0  = 0.0;
    Table->a1D__0  = 0.0;

    Table->n2S__0  = Table->INITIAL_TOTAL_POPULATION - Initial_Exposed_Population - Initial_Assymptomatic_Population;
    Table->n2E__0  = Initial_Exposed_Population;
    Table->n2I1__0 = 0.0;
    Table->n2I2__0 = 0.0;
    Table->n2A__0  = Initial_Assymptomatic_Population;
    Table->n2Y__0  = 0.0;
    Table->n2R__0  = 0.0;
    Table->a2I__0  = 0.0; 
    Table->a2R__0  = 0.0;
    Table->a2D__0  = 0.0;

    Table->n3S__0  = Table->INITIAL_TOTAL_POPULATION - Initial_Exposed_Population - Initial_Assymptomatic_Population;
    Table->n3E__0  = Initial_Exposed_Population;
    Table->n3I1__0 = 0.0;
    Table->n3I2__0 = 0.0;
    Table->n3A__0  = Initial_Assymptomatic_Population;
    Table->n3Y__0  = 0.0;
    Table->n3R__0  = 0.0;
    Table->a3I__0  = 0.0; 
    Table->a3R__0  = 0.0;
    Table->a3D__0  = 0.0;
    
}

void Initial_Condition_from_Value_into_Parameter_Table (Parameter_Table * Table, double Value)
{
  /* Initial conditions from empirical data at the initial time ( -xn 0 ) */

  /* Value should represent the inital value of exposed individuals in the first age class */

  Table->n0S__0  = Table->N0 - Value; 
  Table->n0E__0  = Value;
  Table->n0I1__0 = 0.0;
  Table->n0I2__0 = 0.0;
  Table->n0A__0  = 0.0; 
  Table->n0Y__0  = 0.0;
  Table->n0R__0  = 0.0;   
  Table->a0I__0  = 0.0; 
  Table->a0R__0  = 0.0;
  Table->a0D__0  = 0.0;

  Table->n1S__0  = Table->N1;
  Table->n1E__0  = 0.0;
  Table->n1I1__0 = 0.0;
  Table->n1I2__0 = 0.0;
  Table->n1A__0  = 0.0; 
  Table->n1Y__0  = 0.0;
  Table->n1R__0  = 0.0;   
  Table->a1I__0  = 0.0; 
  Table->a1R__0  = 0.0;
  Table->a1D__0  = 0.0;

  Table->n2S__0  = Table->N2 ;
  Table->n2E__0  = 0.0;
  Table->n2I1__0 = 0.0;
  Table->n2I2__0 = 0.0;
  Table->n2A__0  = 0.0; 
  Table->n2Y__0  = 0.0;
  Table->n2R__0  = 0.0;   
  Table->a2I__0  = 0.0; 
  Table->a2R__0  = 0.0;
  Table->a2D__0  = 0.0;

  Table->n3S__0  = Table->N3;
  Table->n3E__0  = 0.0;
  Table->n3I1__0 = 0.0;
  Table->n3I2__0 = 0.0;
  Table->n3A__0  = 0.0; 
  Table->n3Y__0  = 0.0;
  Table->n3R__0  = 0.0;   
  Table->a3I__0  = 0.0; 
  Table->a3R__0  = 0.0;
  Table->a3D__0  = 0.0;
}

