#include <MODEL.h>

extern gsl_rng * r;

void Initial_Condition_from_Parameter_Table(Parameter_Table * Table, double *Y)
{

  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>

  Y[nS]  = Table->nS__0;
  Y[nE]  = Table->nE__0;
  Y[nI1] = Table->nI1__0;
  Y[nI2] = Table->nI2__0;
  Y[nA]  = Table->nA__0;
  Y[nY]  = Table->nY__0;
  Y[nR]  = Table->nR__0;
  
  Y[aI]  = Table->aI__0;
  Y[aR]  = Table->aR__0;
  Y[aD]  = Table->aD__0;
  
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
    
    Table->nS__0  = Y[nS];
    Table->nE__0  = Y[nE];
    Table->nI1__0 = Y[nI1];
    Table->nI2__0 = Y[nI2];
    Table->nA__0  = Y[nA];
    Table->nY__0  = Y[nY];
    Table->nR__0  = Y[nR];
    
    Table->aI__0  = Y[aI];
    Table->aR__0  = Y[aR];
    Table->aD__0  = Y[aD];
}

void Initial_Condition_from_Data_into_Parameter_Table (Parameter_Table * Table, double ** Data)
{
  /* Initial conditions from empirical data at the initial time ( -xn 0 ) */
  
    Table->INITIAL_TOTAL_POPULATION          = Data[0][0];
  
    Table->nS__0  = Table->INITIAL_TOTAL_POPULATION - 1.0;
    Table->nE__0  = 1.0;
    Table->nI1__0 = 0.0;
    Table->nI2__0 = 0.0;
    Table->nA__0  = 0.0;
    Table->nY__0  = 0.0;
    Table->nR__0  = 0.0;
    
    Table->aI__0  = 1.0;
    Table->aR__0  = 0.0;
    Table->aD__0  = 0.0;
}

void Initial_Condition_from_Initial_Values_into_Parameter_Table (Parameter_Table * Table,
								 double Initial_Population,
								 double Initial_Exposed_Population,
								 double Initial_Assymptomatic_Population )
{
  /* Initial conditions from empirical data at the initial time ( -xn 0 ) */
  
    Table->INITIAL_TOTAL_POPULATION          = Initial_Population;
 
    Table->nS__0  = Table->INITIAL_TOTAL_POPULATION - Initial_Exposed_Population - Initial_Assymptomatic_Population;
    Table->nE__0  = Initial_Exposed_Population;
    Table->nI1__0 = 0.0;
    Table->nI2__0 = 0.0;
    Table->nA__0  = Initial_Assymptomatic_Population;
    Table->nY__0  = 0.0;
    Table->nR__0  = 0.0;
    
    Table->aI__0  = 0.0; 
    Table->aR__0  = 0.0;
    Table->aD__0  = 0.0;
    
}

void Initial_Condition_from_Value_into_Parameter_Table (Parameter_Table * Table, double Value)
{
  /* Initial conditions from empirical data at the initial time ( -xn 0 ) */
  /* Value should represent the inital value of exposed individuals in the population */
  
  Table->nS__0  = Table->INITIAL_TOTAL_POPULATION - Value; ;
  Table->nE__0  = Value;
  Table->nI1__0 = 0.0;
  Table->nI2__0 = 0.0;
  Table->nA__0  = 0.0; 
  Table->nY__0  = 0.0;
  Table->nR__0  = 0.0;
    
  Table->aI__0  = 0.0; 
  Table->aR__0  = 0.0;
  Table->aD__0  = 0.0;
}

