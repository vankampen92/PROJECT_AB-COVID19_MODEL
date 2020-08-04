#include "./Include/MODEL.h"

/* void Parameter_Model_Initialization( Parameter_Model * P,    */
/* 				      double * p_Delta,         */
/* 				      double * p_Alpha_0,       */
/* 				      double * p_Alpha_1,       */
/* 				      double * p_Lambda_0,      */
/* 				      double * p_Lambda_1,      */
/* 				      double * p_f,             */
/* 				      double * p_gap )          */
/* { */
/*   P->Delta    = * p_Delta;       /\* Key 0 *\/               */
/*   P->Alpha_0  = * p_Alpha_0;     /\* Key 1 *\/               */
/*   P->Alpha_1  = * p_Alpha_1;     /\* Key 2 *\/               */
/*   P->Lambda_0 = * p_Lambda_0;    /\* Key 3 *\/               */
/*   P->Lambda_1 = * p_Lambda_1;    /\* Key 4 *\/               */
/*   P->f        = * p_f;           /\* Key 5 *\/               */
/*   P->gap      = * p_gap;         /\* Key 6 *\/               */

/*   P->MODEL_PARAMETERS = No_of_True_Parameters;               */
/* } */

void Parameter_Model_Copy (Parameter_Model * P_Destination, Parameter_Model * P_Source)
{

  P_Destination->N0      = P_Source->N0;    /*  0 */     /* Total (Initial) Population, but then dynamically evolve */
  P_Destination->N1      = P_Source->N1;    /*  0 */     /* Total (Initial) Population, but then dynamically evolve */
  P_Destination->N2      = P_Source->N2;    /*  0 */     /* Total (Initial) Population, but then dynamically evolve */
  P_Destination->N3      = P_Source->N3;    /*  0 */     /* Total (Initial) Population, but then dynamically evolve */  
 
  P_Destination->N      = P_Source->N;    

  P_Destination->Kappa  = P_Source->Kappa; /*  0 */     /* Percapita detectability rate (A) */  
  P_Destination->Imm    = P_Source->Imm;  /*  1 */     /* Total Immigration Rate */  
  P_Destination->Beta   = P_Source->Beta; /*  2 */     /* Contact rate: Total no of contacts an individual has per day   */
  P_Destination->b      = P_Source->b;    /*  3 */     /* Infectivity  */ 
  P_Destination->Phi    = P_Source->Phi;  /*  4 */     /* Pre-symptomatic Infectivity Factor */  
  P_Destination->Eps_I = P_Source->Eps_I; /*  5 */   /* Isolation effectiveness of strong cases */ 
  P_Destination->Eps_Y  = P_Source->Eps_Y;  /*  6 */   /* Isolation effectiveness of serious cases */
  P_Destination->Sigma  = P_Source->Sigma;  /*  7 */   /* Rate of the appearance of infectious capacity */
  P_Destination->Gamma_1= P_Source->Gamma_1; /*  8 */  /* Rate of the appearance of symptoms  */ 
  P_Destination->Alpha  = P_Source->Alpha;   /* 10 */  /* (Age-dependent) Rate of appearence of serious symptoms */     
  P_Destination->Delta  = P_Source->Delta;   /* 11 */  /* (Age-dependent) Disease-Induced Mortality Rate */    
  P_Destination->Gamma_2= P_Source->Gamma_2; /* 12 */  /* Rate of Recovery */  

  P_Destination->Beta_00 = P_Source->Beta_00;
  P_Destination->Beta_01 = P_Source->Beta_01;
  P_Destination->Beta_02 = P_Source->Beta_02;
  P_Destination->Beta_03 = P_Source->Beta_03;
  
  P_Destination->Beta_10 = P_Source->Beta_10;
  P_Destination->Beta_11 = P_Source->Beta_11;
  P_Destination->Beta_12 = P_Source->Beta_12;
  P_Destination->Beta_13 = P_Source->Beta_13;

  P_Destination->Beta_20 = P_Source->Beta_20;
  P_Destination->Beta_21 = P_Source->Beta_21;
  P_Destination->Beta_22 = P_Source->Beta_22;
  P_Destination->Beta_23 = P_Source->Beta_23;
  
  P_Destination->Beta_30 = P_Source->Beta_30;
  P_Destination->Beta_31 = P_Source->Beta_31;
  P_Destination->Beta_32 = P_Source->Beta_32;
  P_Destination->Beta_33 = P_Source->Beta_33;
   
  P_Destination->Alpha_0 = P_Source->Alpha_0;
  P_Destination->Alpha_1 = P_Source->Alpha_1;
  P_Destination->Alpha_2 = P_Source->Alpha_2;
  P_Destination->Alpha_3 = P_Source->Alpha_3;
  
  P_Destination->Delta_0 = P_Source->Delta_0;
  P_Destination->Delta_1 = P_Source->Delta_1;
  P_Destination->Delta_2 = P_Source->Delta_2;
  P_Destination->Delta_3 = P_Source->Delta_3;
   
  P_Destination->p_0   = P_Source->p_0;    /*  9 */  /* Probability of the appearance of strong symptoms */
  P_Destination->p_1   = P_Source->p_1;
  P_Destination->p_2   = P_Source->p_2;
  P_Destination->p_3   = P_Source->p_3;
  
  /* Parameters related to the initial conditions: */
  P_Destination->nS__0  = P_Source->nS__0;
  P_Destination->nE__0  = P_Source->nE__0;
  P_Destination->nI1__0 = P_Source->nI1__0;
  P_Destination->nI2__0 = P_Source->nI2__0;
  P_Destination->nA__0  = P_Source->nA__0;
  P_Destination->nY__0  = P_Source->nY__0;
  P_Destination->nR__0  = P_Source->nR__0;
  P_Destination->aI__0  = P_Source->aI__0;
  P_Destination->aR__0  = P_Source->aR__0;
  P_Destination->aD__0  = P_Source->aD__0;

  P_Destination->n0S__0  = P_Source->n0S__0;
  P_Destination->n0E__0  = P_Source->n0E__0;
  P_Destination->n0I1__0 = P_Source->n0I1__0;
  P_Destination->n0I2__0 = P_Source->n0I2__0;
  P_Destination->n0A__0  = P_Source->n0A__0;
  P_Destination->n0Ad__0  = P_Source->n0Ad__0;
  P_Destination->n0Y__0  = P_Source->n0Y__0;
  P_Destination->n0R__0  = P_Source->n0R__0;
  P_Destination->a0I__0  = P_Source->a0I__0;
  P_Destination->a0R__0  = P_Source->a0R__0;
  P_Destination->a0D__0  = P_Source->a0D__0;

  P_Destination->n1S__0  = P_Source->n1S__0;
  P_Destination->n1E__0  = P_Source->n1E__0;
  P_Destination->n1I1__0 = P_Source->n1I1__0;
  P_Destination->n1I2__0 = P_Source->n1I2__0;
  P_Destination->n1A__0  = P_Source->n1A__0;
  P_Destination->n1Ad__0  = P_Source->n1Ad__0;
  P_Destination->n1Y__0  = P_Source->n1Y__0;
  P_Destination->n1R__0  = P_Source->n1R__0;
  P_Destination->a1I__0  = P_Source->a1I__0;
  P_Destination->a1R__0  = P_Source->a1R__0;
  P_Destination->a1D__0  = P_Source->a1D__0;

  P_Destination->n2S__0  = P_Source->n2S__0;
  P_Destination->n2E__0  = P_Source->n2E__0;
  P_Destination->n2I1__0 = P_Source->n2I1__0;
  P_Destination->n2I2__0 = P_Source->n2I2__0;
  P_Destination->n2A__0  = P_Source->n2A__0;
  P_Destination->n2Ad__0  = P_Source->n2Ad__0;
  P_Destination->n2Y__0  = P_Source->n2Y__0;
  P_Destination->n2R__0  = P_Source->n2R__0;
  P_Destination->a2I__0  = P_Source->a2I__0;
  P_Destination->a2R__0  = P_Source->a2R__0;
  P_Destination->a2D__0  = P_Source->a2D__0;

  P_Destination->n3S__0  = P_Source->n3S__0;
  P_Destination->n3E__0  = P_Source->n3E__0;
  P_Destination->n3I1__0 = P_Source->n3I1__0;
  P_Destination->n3I2__0 = P_Source->n3I2__0;
  P_Destination->n3A__0  = P_Source->n3A__0;
  P_Destination->n3Ad__0  = P_Source->n3Ad__0;
  P_Destination->n3Y__0  = P_Source->n3Y__0;
  P_Destination->n3R__0  = P_Source->n3R__0;
  P_Destination->a3I__0  = P_Source->a3I__0;
  P_Destination->a3R__0  = P_Source->a3R__0;
  P_Destination->a3D__0  = P_Source->a3D__0;

  /* Assigning Initial Condition pointers to the corresponding Parameter_Table pointers */
  P_Destination->n0S___0  = P_Source->n0S___0;
  P_Destination->n0E___0  = P_Source->n0E___0;
  P_Destination->n0I1___0 = P_Source->n0I1___0;
  P_Destination->n0I2___0 = P_Source->n0I2___0;
  P_Destination->n0A___0  = P_Source->n0A___0;
  P_Destination->n0Ad___0 = P_Source->n0Ad___0;
  P_Destination->n0Y___0  = P_Source->n0Y___0;
  P_Destination->n0R___0  = P_Source->n0R___0;
  P_Destination->a0I___0  = P_Source->a0I___0;
  P_Destination->a0R___0  = P_Source->a0R___0;
  P_Destination->a0D___0  = P_Source->a0D___0;
  
  P_Destination->n1S___0  = P_Source->n1S___0;
  P_Destination->n1E___0  = P_Source->n1E___0;
  P_Destination->n1I1___0 = P_Source->n1I1___0;
  P_Destination->n1I2___0 = P_Source->n1I2___0;
  P_Destination->n1A___0  = P_Source->n1A___0;
  P_Destination->n1Ad___0 = P_Source->n1Ad___0;
  P_Destination->n1Y___0  = P_Source->n1Y___0;
  P_Destination->n1R___0  = P_Source->n1R___0;
  P_Destination->a1I___0  = P_Source->a1I___0;
  P_Destination->a1R___0  = P_Source->a1R___0;
  P_Destination->a1D___0  = P_Source->a1D___0;
  
  P_Destination->n2S___0  = P_Source->n2S___0;
  P_Destination->n2E___0  = P_Source->n2E___0;
  P_Destination->n2I1___0 = P_Source->n2I1___0;
  P_Destination->n2I2___0 = P_Source->n2I2___0;
  P_Destination->n2A___0  = P_Source->n2A___0;
  P_Destination->n2Ad___0 = P_Source->n2Ad___0;
  P_Destination->n2Y___0  = P_Source->n2Y___0;
  P_Destination->n2R___0  = P_Source->n2R___0;
  P_Destination->a2I___0  = P_Source->a2I___0;
  P_Destination->a2R___0  = P_Source->a2R___0;
  P_Destination->a2D___0  = P_Source->a2D___0;
  
  P_Destination->n3S___0  = P_Source->n3S___0;
  P_Destination->n3E___0  = P_Source->n3E___0;
  P_Destination->n3I1___0 = P_Source->n3I1___0;
  P_Destination->n3I2___0 = P_Source->n3I2___0;
  P_Destination->n3A___0  = P_Source->n3A___0;
  P_Destination->n3Ad___0 = P_Source->n3Ad___0;
  P_Destination->n3Y___0  = P_Source->n3Y___0;
  P_Destination->n3R___0  = P_Source->n3R___0;
  P_Destination->a3I___0  = P_Source->a3I___0;
  P_Destination->a3R___0  = P_Source->a3R___0;
  P_Destination->a3D___0  = P_Source->a3D___0;
  
  P_Destination->N_0 = P_Source->N_0;
  P_Destination->N_1 = P_Source->N_1;
  P_Destination->N_2 = P_Source->N_2;
  P_Destination->N_3 = P_Source->N_3;
  
  P_Destination->No_of_IC = P_Source->No_of_IC;
  P_Destination->TYPE_of_INITIAL_CONDITION = P_Source->TYPE_of_INITIAL_CONDITION;
  P_Destination->INITIAL_TOTAL_POPULATION  = P_Source->INITIAL_TOTAL_POPULATION;
  P_Destination->RESCALING_INITIAL_TOTAL_POPULATION = P_Source->RESCALING_INITIAL_TOTAL_POPULATION;

  P_Destination->TYPE_of_ERROR_FUNCTION = P_Source->TYPE_of_ERROR_FUNCTION;
  P_Destination->No_of_ERROR_PARAMETERS = P_Source->No_of_ERROR_PARAMETERS;

  P_Destination->Error_Parameter_0 = P_Source->Error_Parameter_0;
  P_Destination->Error_Parameter_1 = P_Source->Error_Parameter_1;

  P_Destination->Err_0 = P_Source->Err_0;
  P_Destination->Err_1 = P_Source->Err_1;
  P_Destination->Err_2 = P_Source->Err_2;
  P_Destination->Err_3 = P_Source->Err_3;
  P_Destination->Err_4 = P_Source->Err_4;
  P_Destination->Err_5 = P_Source->Err_5;
  P_Destination->Err_6 = P_Source->Err_6;
  P_Destination->Err_7 = P_Source->Err_7;
  P_Destination->Err_8 = P_Source->Err_8;
  P_Destination->Err_9 = P_Source->Err_9;
  P_Destination->Err_10 = P_Source->Err_11;
  P_Destination->Err_11 = P_Source->Err_11;
  P_Destination->Err_12 = P_Source->Err_12;
  P_Destination->Err_13 = P_Source->Err_13;
  P_Destination->Err_14 = P_Source->Err_14;
  P_Destination->Err_15 = P_Source->Err_15;
  P_Destination->Err_16 = P_Source->Err_16;
  
  P_Destination->MODEL_OUTPUT_VARIABLES = P_Source->MODEL_OUTPUT_VARIABLES;   /* Actual no of MODEL (output) VARIABLES */
  P_Destination->MODEL_INPUT_PARAMETERS = P_Source->MODEL_INPUT_PARAMETERS;  /* Actual no of MODEL (input) PARAMETERS */
  P_Destination->MODEL_STATE_VARIABLES  = P_Source->MODEL_STATE_VARIABLES;  /* Actual no of MODEL (state) VARIABLES  */

  P_Destination->TYPE_of_MODEL        = P_Source->TYPE_of_MODEL;
  P_Destination->Growth_Function_Type = P_Source->Growth_Function_Type;

  //P_Destination->Time_Scale_Unit      = Table->T->Time_Scale_Unit;

  P_Destination->No_of_LOCAL_POPULATIONS    = P_Source->No_of_LOCAL_POPULATIONS;

  P_Destination->TOTAL_No_of_DISEASE_STAGES = P_Source->TOTAL_No_of_DISEASE_STAGES;
  /* Ex: 11 for SEI1I2AAdYR */
  P_Destination->TOTAL_No_of_AGE_CLASSES    = P_Source->TOTAL_No_of_AGE_CLASSES;
  /* Ex: 4                  */
  P_Destination->No_of_DISEASE_STAGES       = P_Source->No_of_DISEASE_STAGES;
  /* Ex: 8 (without acummulating variables) */
  P_Destination->No_of_NEIGHBORS            = P_Source->No_of_NEIGHBORS;
  P_Destination->TYPE_of_NETWORK            = P_Source->TYPE_of_NETWORK;
  P_Destination->TOTAL_No_of_EVENTS         = P_Source->TOTAL_No_of_EVENTS;
  /* Total Number of Events within a patch, i.e., 25 * 4 = 100 */
  P_Destination->No_of_EVENTS               = P_Source->No_of_EVENTS;
  /* Number of Events within an age class, i.e., 25           */

  P_Destination->Metapop_Connectivity_Matrix = P_Source->Metapop_Connectivity_Matrix; 
}

void  P_A_R_A_M_E_T_E_R___I_N_I_T_I_A_L_I_Z_A_T_I_O_N ( Parameter_Table * Table,
							Parameter_Model * P )
{
  /* This function transfer a subset of table parameters
     into the Parameter_Model structure. Parameter_Model parameters
     control the dynamical model.
  */
  P->N0      = Table->N0; /*  0 */ /* Total (Initial) Population, but then dynamically evolve */
  P->N1      = Table->N1; /*  1 */ /* Total (Initial) Population, but then dynamically evolve */
  P->N2      = Table->N2; /*  2 */ /* Total (Initial) Population, but then dynamically evolve */
  P->N3      = Table->N3; /*  3 */ /* Total (Initial) Population, but then dynamically evolve */
  
  P->N      = Table->N;    /*  0 */     /* Total (Initial) Population */

  P->Kappa  = Table->Kappa; 
  P->Imm    = Table->Imm;  /*  1 */     /* Total Immigration Rate */  
  P->Beta   = Table->Beta; /*  2 */     /* Contact rate: Total no of contacts an individual has per day   */
  P->b      = Table->b;    /*  3 */     /* Infectivity  */ 
  P->Phi    = Table->Phi;  /*  4 */     /* Pre-symptomatic Infectivity Factor */  
  P->Eps_I = Table->Eps_I; /*  5 */   /* Isolation effectiveness of strong cases */ 
  P->Eps_Y  = Table->Eps_Y;  /*  6 */   /* Isolation effectiveness of serious cases */
  P->Sigma  = Table->Sigma;  /*  7 */   /* Rate of the appearance of infectious capacity */
  P->Gamma_1= Table->Gamma_1; /*  8 */  /* Rate of the appearance of symptoms  */ 
  P->Alpha  = Table->Alpha;   /* 10 */  /* (Age-dependent) Rate of appearence of serious symptoms */ 
  P->Delta  = Table->Delta;   /* 11 */  /* (Age-dependent) Disease-Induced Mortality Rate */    
  P->Gamma_2= Table->Gamma_2; /* 12 */  /* Rate of Recovery */

  P->Beta_00 = Table->Beta_00;
  P->Beta_01 = Table->Beta_01;
  P->Beta_02 = Table->Beta_02;
  P->Beta_03 = Table->Beta_03;
  
  P->Beta_10 = Table->Beta_10;
  P->Beta_11 = Table->Beta_11;
  P->Beta_12 = Table->Beta_12;
  P->Beta_13 = Table->Beta_13;

  P->Beta_20 = Table->Beta_20;
  P->Beta_21 = Table->Beta_21;
  P->Beta_22 = Table->Beta_22;
  P->Beta_23 = Table->Beta_23;
  
  P->Beta_30 = Table->Beta_30;
  P->Beta_31 = Table->Beta_31;
  P->Beta_32 = Table->Beta_32;
  P->Beta_33 = Table->Beta_33;
   
  P->Alpha_0 = Table->Alpha_0;
  P->Alpha_1 = Table->Alpha_1;
  P->Alpha_2 = Table->Alpha_2;
  P->Alpha_3 = Table->Alpha_3;
  
  P->Delta_0 = Table->Delta_0;
  P->Delta_1 = Table->Delta_1;
  P->Delta_2 = Table->Delta_2;
  P->Delta_3 = Table->Delta_3;

  P->p_0   = Table->p_0;    /*  9 */  /* Probability of the appearance of strong symptoms */
  P->p_1   = Table->p_1;
  P->p_2   = Table->p_2;
  P->p_3   = Table->p_3;
  /* P->D_Sigma  = Table->D_Sigma;  /\* Parameter introducing time-dependence in Sigma_0 and Sigma_1 *\/ */
  /* P->Sigmoidal_A0 = Table->Sigmoidal_A0; /\* Parameter introducing time-dependence in Sigma_0 and Sigma_1 *\/  */
  /* P->Sigmoidal_L0 = Table->Sigmoidal_L0; /\* Parameter introducing time-dependence in Sigma_0 and Sigma_1 *\/ */
  /* P->Sigmoidal_T0 = Table->Sigmoidal_T0; /\* Parameter introducing time-dependence in Sigma_0 and Sigma_1*\/ */
  
  /* Parameters related to the initial conditions: */
  P->nS__0  = Table->nS__0;
  P->nE__0  = Table->nE__0;
  P->nI1__0 = Table->nI1__0;
  P->nI2__0 = Table->nI2__0;
  P->nA__0  = Table->nA__0;
  P->nY__0  = Table->nY__0;
  P->nR__0  = Table->nR__0;
  P->aI__0  = Table->aI__0;
  P->aR__0  = Table->aR__0;
  P->aD__0  = Table->aD__0;

  P->n0S__0  = Table->n0S__0;
  P->n0E__0  = Table->n0E__0;
  P->n0I1__0 = Table->n0I1__0;
  P->n0I2__0 = Table->n0I2__0;
  P->n0A__0  = Table->n0A__0;
  P->n0Ad__0  = Table->n0Ad__0;
  P->n0Y__0  = Table->n0Y__0;
  P->n0R__0  = Table->n0R__0;
  P->a0I__0  = Table->a0I__0;
  P->a0R__0  = Table->a0R__0;
  P->a0D__0  = Table->a0D__0;

  P->n1S__0  = Table->n1S__0;
  P->n1E__0  = Table->n1E__0;
  P->n1I1__0 = Table->n1I1__0;
  P->n1I2__0 = Table->n1I2__0;
  P->n1A__0  = Table->n1A__0;
  P->n1Ad__0  = Table->n1Ad__0;
  P->n1Y__0  = Table->n1Y__0;
  P->n1R__0  = Table->n1R__0;
  P->a1I__0  = Table->a1I__0;
  P->a1R__0  = Table->a1R__0;
  P->a1D__0  = Table->a1D__0;

  P->n2S__0  = Table->n2S__0;
  P->n2E__0  = Table->n2E__0;
  P->n2I1__0 = Table->n2I1__0;
  P->n2I2__0 = Table->n2I2__0;
  P->n2A__0  = Table->n2A__0;
  P->n2Ad__0  = Table->n2Ad__0;
  P->n2Y__0  = Table->n2Y__0;
  P->n2R__0  = Table->n2R__0;
  P->a2I__0  = Table->a2I__0;
  P->a2R__0  = Table->a2R__0;
  P->a2D__0  = Table->a2D__0;

  P->n3S__0  = Table->n3S__0;
  P->n3E__0  = Table->n3E__0;
  P->n3I1__0 = Table->n3I1__0;
  P->n3I2__0 = Table->n3I2__0;
  P->n3A__0  = Table->n3A__0;
  P->n3Ad__0  = Table->n3Ad__0;
  P->n3Y__0  = Table->n3Y__0;
  P->n3R__0  = Table->n3R__0;
  P->a3I__0  = Table->a3I__0;
  P->a3R__0  = Table->a3R__0;
  P->a3D__0  = Table->a3D__0;

  /* Assigning Initial Condition pointers to the corresponding Parameter_Table pointers */
  P->n0S___0  = Table->n0S___0;
  P->n0E___0  = Table->n0E___0;
  P->n0I1___0 = Table->n0I1___0;
  P->n0I2___0 = Table->n0I2___0;
  P->n0A___0  = Table->n0A___0;
  P->n0Ad___0 = Table->n0Ad___0;
  P->n0Y___0  = Table->n0Y___0;
  P->n0R___0  = Table->n0R___0;
  P->a0I___0  = Table->a0I___0;
  P->a0R___0  = Table->a0R___0;
  P->a0D___0  = Table->a0D___0;
  
  P->n1S___0  = Table->n1S___0;
  P->n1E___0  = Table->n1E___0;
  P->n1I1___0 = Table->n1I1___0;
  P->n1I2___0 = Table->n1I2___0;
  P->n1A___0  = Table->n1A___0;
  P->n1Ad___0 = Table->n1Ad___0;
  P->n1Y___0  = Table->n1Y___0;
  P->n1R___0  = Table->n1R___0;
  P->a1I___0  = Table->a1I___0;
  P->a1R___0  = Table->a1R___0;
  P->a1D___0  = Table->a1D___0;
  
  P->n2S___0  = Table->n2S___0;
  P->n2E___0  = Table->n2E___0;
  P->n2I1___0 = Table->n2I1___0;
  P->n2I2___0 = Table->n2I2___0;
  P->n2A___0  = Table->n2A___0;
  P->n2Ad___0 = Table->n2Ad___0;
  P->n2Y___0  = Table->n2Y___0;
  P->n2R___0  = Table->n2R___0;
  P->a2I___0  = Table->a2I___0;
  P->a2R___0  = Table->a2R___0;
  P->a2D___0  = Table->a2D___0;
  
  P->n3S___0  = Table->n3S___0;
  P->n3E___0  = Table->n3E___0;
  P->n3I1___0 = Table->n3I1___0;
  P->n3I2___0 = Table->n3I2___0;
  P->n3A___0  = Table->n3A___0;
  P->n3Ad___0 = Table->n3Ad___0;
  P->n3Y___0  = Table->n3Y___0;
  P->n3R___0  = Table->n3R___0;
  P->a3I___0  = Table->a3I___0;
  P->a3R___0  = Table->a3R___0;
  P->a3D___0  = Table->a3D___0;
  
  P->N_0 = Table->N_0;
  P->N_1 = Table->N_1;
  P->N_2 = Table->N_2;
  P->N_3 = Table->N_3;
  
  P->No_of_IC = Table->No_of_IC;
  P->TYPE_of_INITIAL_CONDITION = Table->TYPE_of_INITIAL_CONDITION;
  P->INITIAL_TOTAL_POPULATION  = Table->INITIAL_TOTAL_POPULATION;
  P->RESCALING_INITIAL_TOTAL_POPULATION = Table->RESCALING_INITIAL_TOTAL_POPULATION;

  P->TYPE_of_ERROR_FUNCTION = Table->TYPE_of_ERROR_FUNCTION;
  P->No_of_ERROR_PARAMETERS = Table->No_of_ERROR_PARAMETERS;
  P->Error_Parameter_0 = Table->Error_Parameter_0;
  P->Error_Parameter_1 = Table->Error_Parameter_1;
  
  P->Err_0 = Table->Err_0;
  P->Err_1 = Table->Err_1;
  P->Err_2 = Table->Err_2;
  P->Err_3 = Table->Err_3;
  P->Err_4 = Table->Err_4;
  P->Err_5 = Table->Err_5;
  P->Err_6 = Table->Err_6;
  P->Err_7 = Table->Err_7;
  P->Err_8 = Table->Err_8;
  P->Err_9 = Table->Err_9;
  P->Err_10 = Table->Err_11;
  P->Err_11 = Table->Err_11;
  P->Err_12 = Table->Err_12;
  P->Err_13 = Table->Err_13;
  P->Err_14 = Table->Err_14;
  P->Err_15 = Table->Err_15;
  P->Err_16 = Table->Err_16;

  P->MODEL_OUTPUT_VARIABLES = Table->MODEL_OUTPUT_VARIABLES;   /* Actual no of MODEL (output) VARIABLES */
  P->MODEL_INPUT_PARAMETERS = Table->MODEL_INPUT_PARAMETERS;  /* Actual no of MODEL (input) PARAMETERS */
  P->MODEL_STATE_VARIABLES  = Table->MODEL_STATE_VARIABLES;  /* Actual no of MODEL (state) VARIABLES  */

  P->TYPE_of_MODEL        = Table->TYPE_of_MODEL;
  P->Growth_Function_Type = Table->Growth_Function_Type;

  //P->Time_Scale_Unit      = Table->T->Time_Scale_Unit;

  P->No_of_LOCAL_POPULATIONS = Table->No_of_LOCAL_POPULATIONS;

  P->TOTAL_No_of_DISEASE_STAGES = Table->TOTAL_No_of_DISEASE_STAGES;  /* Ex: 11 for SEI1I2AAdYR */
  P->TOTAL_No_of_AGE_CLASSES    = Table->TOTAL_No_of_AGE_CLASSES;     /* Ex: 4                  */
  P->No_of_DISEASE_STAGES       = Table->No_of_DISEASE_STAGES;
  /* Ex: 8 (without acummulating variables) */
  P->No_of_NEIGHBORS            = Table->No_of_NEIGHBORS;
  P->TYPE_of_NETWORK            = Table->TYPE_of_NETWORK;
  P->TOTAL_No_of_EVENTS         = Table->TOTAL_No_of_EVENTS;
  /* Total Number of Events within a patch, i.e., 18 * 4 = 72 */
  P->No_of_EVENTS               = Table->No_of_EVENTS;
  /* Number of Events within an age class, i.e., 18           */

  P->Metapop_Connectivity_Matrix = Table->Metapop_Connectivity_Matrix; 
}

void Parameter_Model_Copy_into_Parameter_Table (Parameter_Table * P_Destination, Parameter_Model * P_Source)
{
  P_Destination->N0      = P_Source->N0;    /*  0 */     /* Total (Initial) Population, but then dynamically evolve */
  P_Destination->N1      = P_Source->N1;    /*  0 */     /* Total (Initial) Population, but then dynamically evolve */
  P_Destination->N2      = P_Source->N2;    /*  0 */     /* Total (Initial) Population, but then dynamically evolve */
  P_Destination->N3      = P_Source->N3;    /*  0 */     /* Total (Initial) Population, but then dynamically evolve */  
  
  P_Destination->N      = P_Source->N;    

  P_Destination->Kappa  = P_Source->Kappa; /*  0 */     /* Percapita detectability rate (A) */  
  P_Destination->Imm    = P_Source->Imm;  /*  1 */     /* Total Immigration Rate */  
  P_Destination->Beta   = P_Source->Beta; /*  2 */     /* Contact rate: Total no of contacts an individual has per day   */
  P_Destination->b      = P_Source->b;    /*  3 */     /* Infectivity  */ 
  P_Destination->Phi    = P_Source->Phi;  /*  4 */     /* Pre-symptomatic Infectivity Factor */  
  P_Destination->Eps_I = P_Source->Eps_I; /*  5 */   /* Isolation effectiveness of strong cases */ 
  P_Destination->Eps_Y  = P_Source->Eps_Y;  /*  6 */   /* Isolation effectiveness of serious cases */
  P_Destination->Sigma  = P_Source->Sigma;  /*  7 */   /* Rate of the appearance of infectious capacity */
  P_Destination->Gamma_1= P_Source->Gamma_1; /*  8 */  /* Rate of the appearance of symptoms  */ 
  P_Destination->Alpha  = P_Source->Alpha;   /* 10 */  /* (Age-dependent) Rate of appearence of serious symptoms */     
  P_Destination->Delta  = P_Source->Delta;   /* 11 */  /* (Age-dependent) Disease-Induced Mortality Rate */    
  P_Destination->Gamma_2= P_Source->Gamma_2; /* 12 */  /* Rate of Recovery */  

  P_Destination->Beta_00 = P_Source->Beta_00;
  P_Destination->Beta_01 = P_Source->Beta_01;
  P_Destination->Beta_02 = P_Source->Beta_02;
  P_Destination->Beta_03 = P_Source->Beta_03;
  
  P_Destination->Beta_10 = P_Source->Beta_10;
  P_Destination->Beta_11 = P_Source->Beta_11;
  P_Destination->Beta_12 = P_Source->Beta_12;
  P_Destination->Beta_13 = P_Source->Beta_13;

  P_Destination->Beta_20 = P_Source->Beta_20;
  P_Destination->Beta_21 = P_Source->Beta_21;
  P_Destination->Beta_22 = P_Source->Beta_22;
  P_Destination->Beta_23 = P_Source->Beta_23;
  
  P_Destination->Beta_30 = P_Source->Beta_30;
  P_Destination->Beta_31 = P_Source->Beta_31;
  P_Destination->Beta_32 = P_Source->Beta_32;
  P_Destination->Beta_33 = P_Source->Beta_33;
   
  P_Destination->Alpha_0 = P_Source->Alpha_0;
  P_Destination->Alpha_1 = P_Source->Alpha_1;
  P_Destination->Alpha_2 = P_Source->Alpha_2;
  P_Destination->Alpha_3 = P_Source->Alpha_3;
  
  P_Destination->Delta_0 = P_Source->Delta_0;
  P_Destination->Delta_1 = P_Source->Delta_1;
  P_Destination->Delta_2 = P_Source->Delta_2;
  P_Destination->Delta_3 = P_Source->Delta_3;
   
  P_Destination->p_0   = P_Source->p_0;    /*  9 */  /* Probability of the appearance of strong symptoms */
  P_Destination->p_1   = P_Source->p_1;
  P_Destination->p_2   = P_Source->p_2;
  P_Destination->p_3   = P_Source->p_3;
    
  /* Parameters related to the initial conditions: */
  P_Destination->nS__0  = P_Source->nS__0;
  P_Destination->nE__0  = P_Source->nE__0;
  P_Destination->nI1__0 = P_Source->nI1__0;
  P_Destination->nI2__0 = P_Source->nI2__0;
  P_Destination->nA__0  = P_Source->nA__0;
  P_Destination->nY__0  = P_Source->nY__0;
  P_Destination->nR__0  = P_Source->nR__0;
  P_Destination->aI__0  = P_Source->aI__0;
  P_Destination->aR__0  = P_Source->aR__0;
  P_Destination->aD__0  = P_Source->aD__0;

  P_Destination->n0S__0  = P_Source->n0S__0;
  P_Destination->n0E__0  = P_Source->n0E__0;
  P_Destination->n0I1__0 = P_Source->n0I1__0;
  P_Destination->n0I2__0 = P_Source->n0I2__0;
  P_Destination->n0A__0  = P_Source->n0A__0;
  P_Destination->n0Ad__0  = P_Source->n0Ad__0;
  P_Destination->n0Y__0  = P_Source->n0Y__0;
  P_Destination->n0R__0  = P_Source->n0R__0;
  P_Destination->a0I__0  = P_Source->a0I__0;
  P_Destination->a0R__0  = P_Source->a0R__0;
  P_Destination->a0D__0  = P_Source->a0D__0;

  P_Destination->n1S__0  = P_Source->n1S__0;
  P_Destination->n1E__0  = P_Source->n1E__0;
  P_Destination->n1I1__0 = P_Source->n1I1__0;
  P_Destination->n1I2__0 = P_Source->n1I2__0;
  P_Destination->n1A__0  = P_Source->n1A__0;
  P_Destination->n1Ad__0  = P_Source->n1Ad__0;
  P_Destination->n1Y__0  = P_Source->n1Y__0;
  P_Destination->n1R__0  = P_Source->n1R__0;
  P_Destination->a1I__0  = P_Source->a1I__0;
  P_Destination->a1R__0  = P_Source->a1R__0;
  P_Destination->a1D__0  = P_Source->a1D__0;

  P_Destination->n2S__0  = P_Source->n2S__0;
  P_Destination->n2E__0  = P_Source->n2E__0;
  P_Destination->n2I1__0 = P_Source->n2I1__0;
  P_Destination->n2I2__0 = P_Source->n2I2__0;
  P_Destination->n2A__0  = P_Source->n2A__0;
  P_Destination->n2Ad__0  = P_Source->n2Ad__0;
  P_Destination->n2Y__0  = P_Source->n2Y__0;
  P_Destination->n2R__0  = P_Source->n2R__0;
  P_Destination->a2I__0  = P_Source->a2I__0;
  P_Destination->a2R__0  = P_Source->a2R__0;
  P_Destination->a2D__0  = P_Source->a2D__0;

  P_Destination->n3S__0  = P_Source->n3S__0;
  P_Destination->n3E__0  = P_Source->n3E__0;
  P_Destination->n3I1__0 = P_Source->n3I1__0;
  P_Destination->n3I2__0 = P_Source->n3I2__0;
  P_Destination->n3A__0  = P_Source->n3A__0;
  P_Destination->n3Ad__0  = P_Source->n3Ad__0;
  P_Destination->n3Y__0  = P_Source->n3Y__0;
  P_Destination->n3R__0  = P_Source->n3R__0;
  P_Destination->a3I__0  = P_Source->a3I__0;
  P_Destination->a3R__0  = P_Source->a3R__0;
  P_Destination->a3D__0  = P_Source->a3D__0;

   /* Assigning Initial Condition pointers to the corresponding Parameter_Table pointers */
  P_Destination->n0S___0  = P_Source->n0S___0;
  P_Destination->n0E___0  = P_Source->n0E___0;
  P_Destination->n0I1___0 = P_Source->n0I1___0;
  P_Destination->n0I2___0 = P_Source->n0I2___0;
  P_Destination->n0A___0  = P_Source->n0A___0;
  P_Destination->n0Ad___0 = P_Source->n0Ad___0;
  P_Destination->n0Y___0  = P_Source->n0Y___0;
  P_Destination->n0R___0  = P_Source->n0R___0;
  P_Destination->a0I___0  = P_Source->a0I___0;
  P_Destination->a0R___0  = P_Source->a0R___0;
  P_Destination->a0D___0  = P_Source->a0D___0;
  
  P_Destination->n1S___0  = P_Source->n1S___0;
  P_Destination->n1E___0  = P_Source->n1E___0;
  P_Destination->n1I1___0 = P_Source->n1I1___0;
  P_Destination->n1I2___0 = P_Source->n1I2___0;
  P_Destination->n1A___0  = P_Source->n1A___0;
  P_Destination->n1Ad___0 = P_Source->n1Ad___0;
  P_Destination->n1Y___0  = P_Source->n1Y___0;
  P_Destination->n1R___0  = P_Source->n1R___0;
  P_Destination->a1I___0  = P_Source->a1I___0;
  P_Destination->a1R___0  = P_Source->a1R___0;
  P_Destination->a1D___0  = P_Source->a1D___0;
  
  P_Destination->n2S___0  = P_Source->n2S___0;
  P_Destination->n2E___0  = P_Source->n2E___0;
  P_Destination->n2I1___0 = P_Source->n2I1___0;
  P_Destination->n2I2___0 = P_Source->n2I2___0;
  P_Destination->n2A___0  = P_Source->n2A___0;
  P_Destination->n2Ad___0 = P_Source->n2Ad___0;
  P_Destination->n2Y___0  = P_Source->n2Y___0;
  P_Destination->n2R___0  = P_Source->n2R___0;
  P_Destination->a2I___0  = P_Source->a2I___0;
  P_Destination->a2R___0  = P_Source->a2R___0;
  P_Destination->a2D___0  = P_Source->a2D___0;
  
  P_Destination->n3S___0  = P_Source->n3S___0;
  P_Destination->n3E___0  = P_Source->n3E___0;
  P_Destination->n3I1___0 = P_Source->n3I1___0;
  P_Destination->n3I2___0 = P_Source->n3I2___0;
  P_Destination->n3A___0  = P_Source->n3A___0;
  P_Destination->n3Ad___0 = P_Source->n3Ad___0;
  P_Destination->n3Y___0  = P_Source->n3Y___0;
  P_Destination->n3R___0  = P_Source->n3R___0;
  P_Destination->a3I___0  = P_Source->a3I___0;
  P_Destination->a3R___0  = P_Source->a3R___0;
  P_Destination->a3D___0  = P_Source->a3D___0;
  
  P_Destination->N_0 = P_Source->N_0;
  P_Destination->N_1 = P_Source->N_1;
  P_Destination->N_2 = P_Source->N_2;
  P_Destination->N_3 = P_Source->N_3;
  
  P_Destination->No_of_IC = P_Source->No_of_IC;
  P_Destination->TYPE_of_INITIAL_CONDITION = P_Source->TYPE_of_INITIAL_CONDITION;
  P_Destination->INITIAL_TOTAL_POPULATION  = P_Source->INITIAL_TOTAL_POPULATION;
  P_Destination->RESCALING_INITIAL_TOTAL_POPULATION = P_Source->RESCALING_INITIAL_TOTAL_POPULATION;

  P_Destination->TYPE_of_ERROR_FUNCTION = P_Source->TYPE_of_ERROR_FUNCTION;
  P_Destination->No_of_ERROR_PARAMETERS = P_Source->No_of_ERROR_PARAMETERS;
  P_Destination->Error_Parameter_0 = P_Source->Error_Parameter_0;
  P_Destination->Error_Parameter_1 = P_Source->Error_Parameter_1;
  
  P_Destination->Err_0 = P_Source->Err_0;
  P_Destination->Err_1 = P_Source->Err_1;
  P_Destination->Err_2 = P_Source->Err_2;
  P_Destination->Err_3 = P_Source->Err_3;
  P_Destination->Err_4 = P_Source->Err_4;
  P_Destination->Err_5 = P_Source->Err_5;
  P_Destination->Err_6 = P_Source->Err_6;
  P_Destination->Err_7 = P_Source->Err_7;
  P_Destination->Err_8 = P_Source->Err_8;
  P_Destination->Err_9 = P_Source->Err_9;
  P_Destination->Err_10 = P_Source->Err_11;
  P_Destination->Err_11 = P_Source->Err_11;
  P_Destination->Err_12 = P_Source->Err_12;
  P_Destination->Err_13 = P_Source->Err_13;
  P_Destination->Err_14 = P_Source->Err_14;
  P_Destination->Err_15 = P_Source->Err_15;
  P_Destination->Err_16 = P_Source->Err_16; 
  
  P_Destination->MODEL_OUTPUT_VARIABLES = P_Source->MODEL_OUTPUT_VARIABLES;   /* Actual no of MODEL (output) VARIABLES */
  P_Destination->MODEL_INPUT_PARAMETERS = P_Source->MODEL_INPUT_PARAMETERS;  /* Actual no of MODEL (input) PARAMETERS */
  P_Destination->MODEL_STATE_VARIABLES  = P_Source->MODEL_STATE_VARIABLES;  /* Actual no of MODEL (state) VARIABLES  */

  P_Destination->TYPE_of_MODEL        = P_Source->TYPE_of_MODEL;
  P_Destination->Growth_Function_Type = P_Source->Growth_Function_Type;

  //P->Time_Scale_Unit      = Table->T->Time_Scale_Unit;
  
  P_Destination->No_of_LOCAL_POPULATIONS = P_Source->No_of_LOCAL_POPULATIONS;

  P_Destination->TOTAL_No_of_DISEASE_STAGES = P_Source->TOTAL_No_of_DISEASE_STAGES;
  /* Ex: 11 for SEI1I2AAdYR */
  P_Destination->TOTAL_No_of_AGE_CLASSES    = P_Source->TOTAL_No_of_AGE_CLASSES;
  /* Ex: 4                  */
  P_Destination->No_of_DISEASE_STAGES       = P_Source->No_of_DISEASE_STAGES;
  /* Ex: 8 (without acummulating variables) */
  P_Destination->No_of_NEIGHBORS            = P_Source->No_of_NEIGHBORS;
  P_Destination->TYPE_of_NETWORK            = P_Source->TYPE_of_NETWORK;
  P_Destination->TOTAL_No_of_EVENTS         = P_Source->TOTAL_No_of_EVENTS;
  /* Total Number of Events within a patch, i.e., 18 * 4 = 72 */
  P_Destination->No_of_EVENTS               = P_Source->No_of_EVENTS;
  /* Number of Events within an age class, i.e., 18           */
}

void Parameter_Table_Copy_into_Parameter_Model (Parameter_Model * P_Destination, Parameter_Table * P_Source)
{

  P_Destination->N0      = P_Source->N0;    /*  0 */     /* Total (Initial) Population, but then dynamically evolve */
  P_Destination->N1      = P_Source->N1;    /*  0 */     /* Total (Initial) Population, but then dynamically evolve */
  P_Destination->N2      = P_Source->N2;    /*  0 */     /* Total (Initial) Population, but then dynamically evolve */
  P_Destination->N3      = P_Source->N3;    /*  0 */     /* Total (Initial) Population, but then dynamically evolve */  
 
  P_Destination->N      = P_Source->N;    

  P_Destination->Kappa  = P_Source->Kappa; /*  0 */     /* Percapita detectability rate (A) */  
  P_Destination->Imm    = P_Source->Imm;  /*  1 */     /* Total Immigration Rate */  
  P_Destination->Beta   = P_Source->Beta; /*  2 */     /* Contact rate: Total no of contacts an individual has per day   */
  P_Destination->b      = P_Source->b;    /*  3 */     /* Infectivity  */ 
  P_Destination->Phi    = P_Source->Phi;  /*  4 */     /* Pre-symptomatic Infectivity Factor */  
  P_Destination->Eps_I = P_Source->Eps_I; /*  5 */   /* Isolation effectiveness of strong cases */ 
  P_Destination->Eps_Y  = P_Source->Eps_Y;  /*  6 */   /* Isolation effectiveness of serious cases */
  P_Destination->Sigma  = P_Source->Sigma;  /*  7 */   /* Rate of the appearance of infectious capacity */
  P_Destination->Gamma_1= P_Source->Gamma_1; /*  8 */  /* Rate of the appearance of symptoms  */ 
  P_Destination->Alpha  = P_Source->Alpha;   /* 10 */  /* (Age-dependent) Rate of appearence of serious symptoms */     
  P_Destination->Delta  = P_Source->Delta;   /* 11 */  /* (Age-dependent) Disease-Induced Mortality Rate */    
  P_Destination->Gamma_2= P_Source->Gamma_2; /* 12 */  /* Rate of Recovery */  

  P_Destination->Beta_00 = P_Source->Beta_00;
  P_Destination->Beta_01 = P_Source->Beta_01;
  P_Destination->Beta_02 = P_Source->Beta_02;
  P_Destination->Beta_03 = P_Source->Beta_03;
  
  P_Destination->Beta_10 = P_Source->Beta_10;
  P_Destination->Beta_11 = P_Source->Beta_11;
  P_Destination->Beta_12 = P_Source->Beta_12;
  P_Destination->Beta_13 = P_Source->Beta_13;

  P_Destination->Beta_20 = P_Source->Beta_20;
  P_Destination->Beta_21 = P_Source->Beta_21;
  P_Destination->Beta_22 = P_Source->Beta_22;
  P_Destination->Beta_23 = P_Source->Beta_23;
  
  P_Destination->Beta_30 = P_Source->Beta_30;
  P_Destination->Beta_31 = P_Source->Beta_31;
  P_Destination->Beta_32 = P_Source->Beta_32;
  P_Destination->Beta_33 = P_Source->Beta_33;
   
  P_Destination->Alpha_0 = P_Source->Alpha_0;
  P_Destination->Alpha_1 = P_Source->Alpha_1;
  P_Destination->Alpha_2 = P_Source->Alpha_2;
  P_Destination->Alpha_3 = P_Source->Alpha_3;
  
  P_Destination->Delta_0 = P_Source->Delta_0;
  P_Destination->Delta_1 = P_Source->Delta_1;
  P_Destination->Delta_2 = P_Source->Delta_2;
  P_Destination->Delta_3 = P_Source->Delta_3;
   
  P_Destination->p_0   = P_Source->p_0;    /*  9 */  /* Probability of the appearance of strong symptoms */
  P_Destination->p_1   = P_Source->p_1;
  P_Destination->p_2   = P_Source->p_2;
  P_Destination->p_3   = P_Source->p_3;
    
  /* Parameters related to the initial conditions: */
  P_Destination->nS__0  = P_Source->nS__0;
  P_Destination->nE__0  = P_Source->nE__0;
  P_Destination->nI1__0 = P_Source->nI1__0;
  P_Destination->nI2__0 = P_Source->nI2__0;
  P_Destination->nA__0  = P_Source->nA__0;
  P_Destination->nY__0  = P_Source->nY__0;
  P_Destination->nR__0  = P_Source->nR__0;
  P_Destination->aI__0  = P_Source->aI__0;
  P_Destination->aR__0  = P_Source->aR__0;
  P_Destination->aD__0  = P_Source->aD__0;

  P_Destination->n0S__0  = P_Source->n0S__0;
  P_Destination->n0E__0  = P_Source->n0E__0;
  P_Destination->n0I1__0 = P_Source->n0I1__0;
  P_Destination->n0I2__0 = P_Source->n0I2__0;
  P_Destination->n0A__0  = P_Source->n0A__0;
  P_Destination->n0Ad__0  = P_Source->n0Ad__0;
  P_Destination->n0Y__0  = P_Source->n0Y__0;
  P_Destination->n0R__0  = P_Source->n0R__0;
  P_Destination->a0I__0  = P_Source->a0I__0;
  P_Destination->a0R__0  = P_Source->a0R__0;
  P_Destination->a0D__0  = P_Source->a0D__0;

  P_Destination->n1S__0  = P_Source->n1S__0;
  P_Destination->n1E__0  = P_Source->n1E__0;
  P_Destination->n1I1__0 = P_Source->n1I1__0;
  P_Destination->n1I2__0 = P_Source->n1I2__0;
  P_Destination->n1A__0  = P_Source->n1A__0;
  P_Destination->n1Ad__0  = P_Source->n1Ad__0;
  P_Destination->n1Y__0  = P_Source->n1Y__0;
  P_Destination->n1R__0  = P_Source->n1R__0;
  P_Destination->a1I__0  = P_Source->a1I__0;
  P_Destination->a1R__0  = P_Source->a1R__0;
  P_Destination->a1D__0  = P_Source->a1D__0;

  P_Destination->n2S__0  = P_Source->n2S__0;
  P_Destination->n2E__0  = P_Source->n2E__0;
  P_Destination->n2I1__0 = P_Source->n2I1__0;
  P_Destination->n2I2__0 = P_Source->n2I2__0;
  P_Destination->n2A__0  = P_Source->n2A__0;
  P_Destination->n2Ad__0  = P_Source->n2Ad__0;
  P_Destination->n2Y__0  = P_Source->n2Y__0;
  P_Destination->n2R__0  = P_Source->n2R__0;
  P_Destination->a2I__0  = P_Source->a2I__0;
  P_Destination->a2R__0  = P_Source->a2R__0;
  P_Destination->a2D__0  = P_Source->a2D__0;

  P_Destination->n3S__0  = P_Source->n3S__0;
  P_Destination->n3E__0  = P_Source->n3E__0;
  P_Destination->n3I1__0 = P_Source->n3I1__0;
  P_Destination->n3I2__0 = P_Source->n3I2__0;
  P_Destination->n3A__0  = P_Source->n3A__0;
  P_Destination->n3Ad__0  = P_Source->n3Ad__0;
  P_Destination->n3Y__0  = P_Source->n3Y__0;
  P_Destination->n3R__0  = P_Source->n3R__0;
  P_Destination->a3I__0  = P_Source->a3I__0;
  P_Destination->a3R__0  = P_Source->a3R__0;
  P_Destination->a3D__0  = P_Source->a3D__0;
  
   /* Assigning Initial Condition pointers to the corresponding Parameter_Table pointers */
  P_Destination->n0S___0  = P_Source->n0S___0;
  P_Destination->n0E___0  = P_Source->n0E___0;
  P_Destination->n0I1___0 = P_Source->n0I1___0;
  P_Destination->n0I2___0 = P_Source->n0I2___0;
  P_Destination->n0A___0  = P_Source->n0A___0;
  P_Destination->n0Ad___0 = P_Source->n0Ad___0;
  P_Destination->n0Y___0  = P_Source->n0Y___0;
  P_Destination->n0R___0  = P_Source->n0R___0;
  P_Destination->a0I___0  = P_Source->a0I___0;
  P_Destination->a0R___0  = P_Source->a0R___0;
  P_Destination->a0D___0  = P_Source->a0D___0;
  
  P_Destination->n1S___0  = P_Source->n1S___0;
  P_Destination->n1E___0  = P_Source->n1E___0;
  P_Destination->n1I1___0 = P_Source->n1I1___0;
  P_Destination->n1I2___0 = P_Source->n1I2___0;
  P_Destination->n1A___0  = P_Source->n1A___0;
  P_Destination->n1Ad___0 = P_Source->n1Ad___0;
  P_Destination->n1Y___0  = P_Source->n1Y___0;
  P_Destination->n1R___0  = P_Source->n1R___0;
  P_Destination->a1I___0  = P_Source->a1I___0;
  P_Destination->a1R___0  = P_Source->a1R___0;
  P_Destination->a1D___0  = P_Source->a1D___0;
  
  P_Destination->n2S___0  = P_Source->n2S___0;
  P_Destination->n2E___0  = P_Source->n2E___0;
  P_Destination->n2I1___0 = P_Source->n2I1___0;
  P_Destination->n2I2___0 = P_Source->n2I2___0;
  P_Destination->n2A___0  = P_Source->n2A___0;
  P_Destination->n2Ad___0 = P_Source->n2Ad___0;
  P_Destination->n2Y___0  = P_Source->n2Y___0;
  P_Destination->n2R___0  = P_Source->n2R___0;
  P_Destination->a2I___0  = P_Source->a2I___0;
  P_Destination->a2R___0  = P_Source->a2R___0;
  P_Destination->a2D___0  = P_Source->a2D___0;
  
  P_Destination->n3S___0  = P_Source->n3S___0;
  P_Destination->n3E___0  = P_Source->n3E___0;
  P_Destination->n3I1___0 = P_Source->n3I1___0;
  P_Destination->n3I2___0 = P_Source->n3I2___0;
  P_Destination->n3A___0  = P_Source->n3A___0;
  P_Destination->n3Ad___0 = P_Source->n3Ad___0;
  P_Destination->n3Y___0  = P_Source->n3Y___0;
  P_Destination->n3R___0  = P_Source->n3R___0;
  P_Destination->a3I___0  = P_Source->a3I___0;
  P_Destination->a3R___0  = P_Source->a3R___0;
  P_Destination->a3D___0  = P_Source->a3D___0;
  
  P_Destination->N_0 = P_Source->N_0;
  P_Destination->N_1 = P_Source->N_1;
  P_Destination->N_2 = P_Source->N_2;
  P_Destination->N_3 = P_Source->N_3;

  P_Destination->No_of_IC = P_Source->No_of_IC;
  P_Destination->TYPE_of_INITIAL_CONDITION = P_Source->TYPE_of_INITIAL_CONDITION;
  P_Destination->INITIAL_TOTAL_POPULATION  = P_Source->INITIAL_TOTAL_POPULATION;
  P_Destination->RESCALING_INITIAL_TOTAL_POPULATION = P_Source->RESCALING_INITIAL_TOTAL_POPULATION;

  P_Destination->TYPE_of_ERROR_FUNCTION = P_Source->TYPE_of_ERROR_FUNCTION;
  P_Destination->No_of_ERROR_PARAMETERS = P_Source->No_of_ERROR_PARAMETERS;
  P_Destination->Error_Parameter_0 = P_Source->Error_Parameter_0;
  P_Destination->Error_Parameter_1 = P_Source->Error_Parameter_1;

  P_Destination->Err_0 = P_Source->Err_0;
  P_Destination->Err_1 = P_Source->Err_1;
  P_Destination->Err_2 = P_Source->Err_2;
  P_Destination->Err_3 = P_Source->Err_3;
  P_Destination->Err_4 = P_Source->Err_4;
  P_Destination->Err_5 = P_Source->Err_5;
  P_Destination->Err_6 = P_Source->Err_6;
  P_Destination->Err_7 = P_Source->Err_7;
  P_Destination->Err_8 = P_Source->Err_8;
  P_Destination->Err_9 = P_Source->Err_9;
  P_Destination->Err_10 = P_Source->Err_11;
  P_Destination->Err_11 = P_Source->Err_11;
  P_Destination->Err_12 = P_Source->Err_12;
  P_Destination->Err_13 = P_Source->Err_13;
  P_Destination->Err_14 = P_Source->Err_14;
  P_Destination->Err_15 = P_Source->Err_15;
  P_Destination->Err_16 = P_Source->Err_16;

  P_Destination->MODEL_OUTPUT_VARIABLES = P_Source->MODEL_OUTPUT_VARIABLES;   /* Actual no of MODEL (output) VARIABLES */
  P_Destination->MODEL_INPUT_PARAMETERS = P_Source->MODEL_INPUT_PARAMETERS;  /* Actual no of MODEL (input) PARAMETERS */
  P_Destination->MODEL_STATE_VARIABLES  = P_Source->MODEL_STATE_VARIABLES;  /* Actual no of MODEL (state) VARIABLES  */

  P_Destination->TYPE_of_MODEL        = P_Source->TYPE_of_MODEL;
  P_Destination->Growth_Function_Type = P_Source->Growth_Function_Type;

  //P->Time_Scale_Unit      = Table->T->Time_Scale_Unit;

  P_Destination->No_of_LOCAL_POPULATIONS = P_Source->No_of_LOCAL_POPULATIONS;

  P_Destination->TOTAL_No_of_DISEASE_STAGES = P_Source->TOTAL_No_of_DISEASE_STAGES;
  /* Ex: 11 for SEI1I2AAdYR */
  P_Destination->TOTAL_No_of_AGE_CLASSES    = P_Source->TOTAL_No_of_AGE_CLASSES;
  /* Ex: 4                  */
  P_Destination->No_of_DISEASE_STAGES       = P_Source->No_of_DISEASE_STAGES;
  /* Ex: 8 (without acummulating variables) */
  P_Destination->No_of_NEIGHBORS            = P_Source->No_of_NEIGHBORS;
  P_Destination->TYPE_of_NETWORK            = P_Source->TYPE_of_NETWORK;
  P_Destination->TOTAL_No_of_EVENTS         = P_Source->TOTAL_No_of_EVENTS;
  /* Total Number of Events within a patch, i.e., 18 * 4 = 72 */
  P_Destination->No_of_EVENTS               = P_Source->No_of_EVENTS;
  /* Number of Events within an age class, i.e., 18           */
  
  P_Destination->Metapop_Connectivity_Matrix = P_Source->Metapop_Connectivity_Matrix; 
}

void Vector_Entries_into_Parameter_Model ( const gsl_vector * X, Parameter_Model * P,
					   int * Parameter_Index, int No_of_PARAMETERS )
{
  int i;
  int key;
  double value;

  for( i=0; i<No_of_PARAMETERS; i++) {
    key = Parameter_Index[i];
    value = gsl_vector_get(X, i);
    Vector_Entry_into_Parameter_Model ( value, key, P );
  }
}

void Vector_Entry_into_Parameter_Model ( double value, int key, Parameter_Model * P )
{

  switch (key) {
    
    case  0: P->Kappa = value;   /* Detectability Rate */                             /*  0 */
      break;
    case  1: P->Imm = value;     /* Total Immigration Rate */                             /*  1 */
      break;
    case  2: P->Beta = value;    /* Contact rate: Total no of contacts an individual has per day   *//*  2 */
      break;
    case  3: P->b = value;       /* Infectivity  */                                        /*  3 */
      break;
    case  4: P->Phi = value;     /* Pre-symptomatic Infectivity Factor */                  /*  4 */
      break;
    case  5: P->Eps_I = value;  /* Isolation effectiveness of strong cases */            /*  5 */
      break;
    case  6: P->Eps_Y = value;   /* Isolation effectiveness of serious cases */            /*  6 */
      break;
    case  7: P->Sigma = value;   /* Rate of the appearance of infectious capacity */       /*  7 */
      break;
    case  8: P->Gamma_1 = value;  /* Rate of the appearance of symptoms  */                /*  8 */
      break; 
    case  9: P->p_0 = value;     /* Probability of the appearance of strong symptoms */   /*  9 */
      break;
    case 10: P->Alpha = value;    /* (Age-dependent) Rate of appearence of serious symptoms */           /* 10 */
      break;
    case 11: P->Delta = value;    /* (Age-dependent) Disease-Induced Mortality Rate */                   /* 11 */
      break;
    case 12: P->Gamma_2 = value;  /* Rate of Recovery */                                  /* 12 */
      break;

    case 13:  P->Beta_00 = value;
      break;
    case 14:  P->Beta_01 = value;
      break;
    case 15:  P->Beta_02 = value;
      break;
    case 16:  P->Beta_03 = value;
      break;

    case 17:  P->Beta_10 = value;
      break;
    case 18:  P->Beta_11 = value;
      break;
    case 19:  P->Beta_12 = value;
      break;
    case 20:  P->Beta_13 = value;
      break;

    case 21:  P->Beta_20 = value;
      break;
    case 22:  P->Beta_21 = value;
      break;
    case 23:  P->Beta_22 = value;
      break;
    case 24:  P->Beta_23 = value;
      break;

    case 25:  P->Beta_30 = value;
      break;
    case 26:  P->Beta_31 = value;
      break;
    case 27:  P->Beta_32 = value;
      break;
    case 28:  P->Beta_33 = value;
      break;

    case 29:  P->Alpha_0 = value;
      break;  
    case 30:  P->Alpha_1 = value;
      break;
    case 31:  P->Alpha_2 = value;
      break;
    case 32:  P->Alpha_3 = value;
      break;

    case 33:  P->Delta_0 = value;
      break;
    case 34:  P->Delta_1 = value;
      break;
    case 35:  P->Delta_2 = value;
      break;
    case 36:  P->Delta_3 = value;
      break;

    case 37:  P->p_1 = value;
      break;
    case 38:  P->p_2 = value;
      break;
    case 39:  P->p_3 = value;
      break;
      
    default:
      printf(".... INVALID PARAMETER KEY (key = %d)\n", key);
      printf(" The maximum number of parameters is Number_PAR_MAX\n");
      printf(" The permited number of keys go from 0, to %d\n", MODEL_PARAMETERS_MAXIMUM-1);

      exit(0);
  }
}

void Parameter_Model_into_Vector_Entries ( Parameter_Model * P, gsl_vector * X,
					   int * Parameter_Index, int No_of_PARAMETERS )
{
  int i;
  int key;
  double value;

  for( i=0; i<No_of_PARAMETERS; i++) {
    key = Parameter_Index[i];
    value = Parameter_Model_into_Vector_Entry( key, P );
    gsl_vector_set(X, i, value);
  }
}

double Parameter_Model_into_Vector_Entry ( int key, Parameter_Model * P )
{
  double value;

  switch (key) {

    case  0: value = P->Kappa;   /* Detectability Rate  */                          /*  0 */
      break;
    case  1: value = P->Imm;    /* Total Immigration Ratge */                             /*  1 */
      break;
    case  2: value = P->Beta;   /* Contact rate: Total no of contacts an individual has per day   *//*  2 */
      break;
    case  3: value = P->b;      /* Infectivity  */                                        /*  3 */
      break;
    case  4: value = P->Phi;    /* Pre-symptomatic Infectivity Factor */                  /*  4 */
      break;
    case  5: value = P->Eps_I; /* Isolation effectiveness of strong cases */            /*  5 */
      break;
    case  6: value = P->Eps_Y;  /* Isolation effectiveness of serious cases */            /*  6 */
      break;
    case  7: value = P->Sigma;  /* Rate of the appearance of infectious capacity */       /*  7 */
      break;
    case  8: value = P->Gamma_1; /* Rate of the appearance of symptoms  */                /*  8 */
      break; 
    case  9: value = P->p_0;    /* Probability of the appearance of strong symptoms */   /*  9 */
      break;
    case 10: value = P->Alpha;   /* (Age-dependent) Rate of appearence of serious symptoms */           /* 10 */
      break;
    case 11: value = P->Delta;   /* (Age-dependent) Disease-Induced Mortality Rate */                   /* 11 */
      break;
    case 12: value = P->Gamma_2; /* Rate of Recovery */                                  /* 12 */
      break;

    case 13: value = P->Beta_00;
      break;
    case 14: value = P->Beta_01;
      break;
    case 15: value = P->Beta_02;
      break;
    case 16: value = P->Beta_03;
      break;

    case 17: value = P->Beta_10;
      break;
    case 18: value = P->Beta_11;
      break;
    case 19: value = P->Beta_12;
      break;
    case 20: value = P->Beta_13;
      break;

    case 21: value = P->Beta_20;
      break;
    case 22: value = P->Beta_21;
      break;
    case 23: value = P->Beta_22;
      break;
    case 24: value = P->Beta_23;
      break;

    case 25: value = P->Beta_30;
      break;
    case 26: value = P->Beta_31;
      break;
    case 27: value = P->Beta_32;
      break;
    case 28: value = P->Beta_33;
      break;

    case 29: value = P->Alpha_0;
      break;  
    case 30: value = P->Alpha_1;
      break;
    case 31: value = P->Alpha_2;
      break;
    case 32: value = P->Alpha_3;
      break;

    case 33: value = P->Delta_0;
      break;
    case 34: value = P->Delta_1;
      break;
    case 35: value = P->Delta_2;
      break;
    case 36: value = P->Delta_3;
      break;

    case 37: value = P->p_1;
      break;
    case 38: value = P->p_2;
      break;
    case 39: value = P->p_3;
      break;
  
    default:
      printf(".... INVALID PARAMETER KEY (key = %d)\n", key);
      printf(" The maximum number of parameters is Number_PAR_MAX\n");
      printf(" The permited number of keys go from 0, to %d\n", MODEL_PARAMETERS_MAXIMUM-1);

      exit(0);
  }

  return(value);
}

void P_A_R_A_M_E_T_E_R___M_O_D_E_L___F_R_E_E( Parameter_Model * P)
{
  free ( P );
}
