/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                             David Alonso, 2010 (c)                        */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <MODEL.h>

double Imm_Preassure(Parameter_Table * Table, int nS, int a, int x);

void Temporal_Dynamics(Community ** My_Community, Parameter_Table * Table, Stochastic_Rate * Rate)
{
  int i,j,k;
  Community * P;
  int MODEL_STATE_VARIABLES;
  int No_of_LOCAL_POPULATIONS;
  int No_of_EVENTS;
  double Lambda_0, Lambda_1, Lambda_2, Lambda_3;  /* Foces of Infection at every age class */
  double OutMigration_0, OutMigration_1, OutMigration_2, OutMigration_3;
  
  Parameter_Model * pa  = Table->P;

  /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>
  
  P = My_Community[0]; /* P could be used as a pointer to the zero-th to be incremented 
			  if necessary (not used like that in this implementation) 
		       */
  Rate->max_Probability = 0.0;
  Rate->Total_Rate      = 0.0;
  
  No_of_LOCAL_POPULATIONS = pa->No_of_LOCAL_POPULATIONS;
  MODEL_STATE_VARIABLES   = pa->MODEL_STATE_VARIABLES;

  No_of_EVENTS          = pa->TOTAL_No_of_EVENTS; /* Total No of Events 
						     within each local population */  

  Immigration_Preassure_on_Focal_Patch_Initialization( My_Community, pa ); 			  

  for(i=0; i<No_of_LOCAL_POPULATIONS; i++){
    
    P = My_Community[i];

    Lambda_0 = Force_of_Infection_Sto( P, P->n, 0, Table );
    Lambda_1 = Force_of_Infection_Sto( P, P->n, 1, Table );
    Lambda_2 = Force_of_Infection_Sto( P, P->n, 2, Table );
    Lambda_3 = Force_of_Infection_Sto( P, P->n, 3, Table );

    OutMigration_0 = P->Total_Per_Capita_Out_Migration_Rate[0]; 
    OutMigration_1 = P->Total_Per_Capita_Out_Migration_Rate[1]; 
    OutMigration_2 = P->Total_Per_Capita_Out_Migration_Rate[2]; 
    OutMigration_3 = P->Total_Per_Capita_Out_Migration_Rate[3]; 
        
    /* Total Vilage Transition Rate: (ratePatch) */  
    P->ratePatch = 0.0;
    
    /* Probability rate for each of the events */

    /* AGE 0 --------------------------------------------------------------------------*/
    /* --------------------------------------------------------------------------------*/
    /* 0 (Age 0): Infection (S --> S-1 and E --> E + 1) */ 
    P->rate[0] = Lambda_0;           P->rToI[0] = Lambda_0 * (double)P->n[n0S];

    /* 1 (Age 0): Out-Migration (S --> S-1) and some other patch gains one */ 
    P->rate[1] = OutMigration_0;     P->rToI[1]  = OutMigration_0 * (double)P->n[n0S];

    /* 2 (Age 0): In-Migration (S --> S+1) and some other patch loses one */
                                     k           = n0S%Table->TOTAL_No_of_DISEASE_STAGES;
    P->rate[2] = pa->Imm;            P->rToI[2]  = P->Total_Imm_Rate_Preassure[0][k]; 


    /* 3 (Age 0):  Exposed into Infectious (E --> E-1 and I1 --> I1 + 1)*/
    P->rate[3] = pa->Sigma;          P->rToI[3] = pa->Sigma * (double)P->n[n0E];

    /* 4 (Age 0): Out-Migration (E --> E-1) and some other patch gains one */ 
    P->rate[4] = OutMigration_0;     P->rToI[4]  = OutMigration_0 * (double)P->n[n0E];

    /* 5 (Age 0): In-Migration (E --> E+1) and some other patch loses one */
                                     k          = n0E%Table->TOTAL_No_of_DISEASE_STAGES; 
    P->rate[5] = pa->Imm;            P->rToI[5] = P->Total_Imm_Rate_Preassure[0][k]; 


    /* 6 (Age 0): Pre-Symptomatic into Infectious (I1 --> I1-1 and I2 --> I2 + 1)  */
    /*                                                         and AI --> AI + 1 */              
    P->rate[6] = pa->p_0*pa->Gamma_1; P->rToI[6] = pa->p_0*pa->Gamma_1 * (double)P->n[n0I1];

    /* 7 (Age 0): Pre-Symptomatic into A-symptomatic (I1 --> I1-1 and A --> A+1) */
    P->rate[7] = (1.0-pa->p_0)*pa->Gamma_1;
    P->rToI[7] = (1.0-pa->p_0)*pa->Gamma_1*(double)P->n[n0I1];

    /* 8 (Age 0): Out-Migration (I1 --> I1-1) and some other patch gains one */ 
    P->rate[8] = OutMigration_0;      P->rToI[8] = OutMigration_0 * (double)P->n[n0I1];

    /* 9 (Age 0): In-Migration (I1 --> I1+1) and some other patch loses one */
                                      k          = n0I1%Table->TOTAL_No_of_DISEASE_STAGES; 
    P->rate[9] = pa->Imm;             P->rToI[9] = P->Total_Imm_Rate_Preassure[0][k]; 


    /* 10 (Age 0): Infectious I2 into Recovered (I2 -> I2-1 and R --> R+1) */
    /*                                                    and AR --> AR + 1 */              
    P->rate[10] = pa->Gamma_2;       P->rToI[10] = pa->Gamma_2 * (double)P->n[n0I2];  
  
    /* 11 (Age 0): Infectious I2 into severe symptoms */
    P->rate[11] = pa->Alpha_0;       P->rToI[11] = pa->Alpha_0 * (double)P->n[n0I2];    

    /* 12 (Age 0): Out-Migration (I2 --> I2-1) and some other patch gains one */ 
    P->rate[12] = (1.0-pa->Eps_I)*OutMigration_0;
    P->rToI[12] = (1.0-pa->Eps_I)*OutMigration_0 * (double)P->n[n0I2];

    /* 13 (Age 0): In-Migration (I2 --> I1 + 1) and some other patch loses one */ 
    P->rate[13] = pa->Imm;
    k           = n0I2%Table->TOTAL_No_of_DISEASE_STAGES; 
    P->rToI[13] = (1.0-pa->Eps_I)*P->Total_Imm_Rate_Preassure[0][k]; 


    /* 14 (Age 0): Assymptomatic into Recovered (A -> A-1 and R --> R + 1)    */
    /* We don't consider accumulating these recovered (AR --> AR + 1)        
       because they have not been detected by the system                      */  
    P->rate[14] = pa->Gamma_2;         P->rToI[14] = pa->Gamma_2 * (double)P->n[n0A];

    /* 15 (Age 0): Assymptomatic are detected   (A -> A-1 and Ad --> Ad + 1)  */
    /*                                                    and AI --> AI + 1   */              
    P->rate[15] = pa->Kappa;           P->rToI[15] = pa->Kappa * (double)P->n[n0A];

    /* 16 (Age 0): Out-Migration (A --> A-1) and some other patch gains one */ 
    P->rate[16] = OutMigration_0;      P->rToI[16]  = OutMigration_0 * (double)P->n[n0A];

    /* 17 (Age 0): In-Migration (A --> A +1) and some other patch loses one */
                                       k           = n0A%Table->TOTAL_No_of_DISEASE_STAGES; 
    P->rate[17] = pa->Imm;             P->rToI[17] = P->Total_Imm_Rate_Preassure[0][k]; 


    /* 18 (Age 0): Detected Assymtomatic are recovered (Ad -> Ad-1 and R --> R + 1) */
    /*                                                            and AR --> AR + 1 */            
    P->rate[18] = pa->Gamma_2;         P->rToI[18] = pa->Gamma_2 * (double)P->n[n0Ad];
    
    /* 19 (Age 0): Out-Migration (Ad --> Ad-1) and some other patch gains one */ 
    P->rate[19] = (1.0-pa->Eps_I)*OutMigration_0;
    P->rToI[19] = (1.0-pa->Eps_I)*OutMigration_0 * (double)P->n[n0Ad];

    /* 20 (Age 0): In-Migration (Ad --> Ad +1) and some other patch loses one */ 
    P->rate[20] = pa->Imm;
    k           = n0Ad%Table->TOTAL_No_of_DISEASE_STAGES; 
    P->rToI[20]  = (1.0-pa->Eps_I)*P->Total_Imm_Rate_Preassure[0][k]; 

    
    /* 21 (Age 0): Severe Infecious recover (Y --> Y-1 and R --> R + 1) */
    /*                                                 and AR --> AR + 1   */              
    P->rate[21] = pa->Gamma_2;         P->rToI[21] = pa->Gamma_2 * (double)P->n[n0Y];

    /* 22 (Age 0): Severe Infecious die (Y --> Y-1 and D --> D + 1 */
    P->rate[22] = pa->Delta_0;         P->rToI[22] = pa->Delta_0 * (double)P->n[n0Y];
    

    /* 23 (Age 0): Recovered individuals move (R --> R-1 and some other patch gains one) */
    P->rate[23] = OutMigration_0;      P->rToI[23] = OutMigration_0 * (double)P->n[n0R];

    /* 24 (Age 0): In-Migration (R --> R + 1) and some other patch loses one */
                                       k           = n0R%Table->TOTAL_No_of_DISEASE_STAGES; 
    P->rate[24] = pa->Imm;             P->rToI[24] = P->Total_Imm_Rate_Preassure[0][k]; 

  
    /* AGE 1 --------------------------------------------------------------------------*/
    /* --------------------------------------------------------------------------------*/
    /* 25 (Age 1): Infection (S --> S-1 and E --> E + 1) */ 
    P->rate[25] = Lambda_1;           P->rToI[25] = Lambda_1 * (double)P->n[n1S];

    /* 26 (Age 1): Out-Migration (S --> S-1) and some other patch gains one */ 
    P->rate[26] = OutMigration_1;     P->rToI[26]  = OutMigration_1 * (double)P->n[n1S];
    
    /* 27 (Age 1): In-Migration (S --> S+1) and some other patch loses one */
                                      k           = n1S%Table->TOTAL_No_of_DISEASE_STAGES; 
    P->rate[27] = pa->Imm;            P->rToI[27] = P->Total_Imm_Rate_Preassure[1][k]; 


    /* 28 (Age 1):  Exposed into Infectious (E --> E-1 and I1 --> I1 + 1)*/ 
    P->rate[28] = pa->Sigma;          P->rToI[28] = pa->Sigma * (double)P->n[n1E];

    /* 29 (Age 1): Out-Migration (E --> E-1) and some other patch gains one */ 
    P->rate[29] = OutMigration_1;     P->rToI[29]  = OutMigration_1 * (double)P->n[n1E];

    /* 30 (Age 1): In-Migration (E --> E+1) and some other patch loses one */
                                      k           = n1E%Table->TOTAL_No_of_DISEASE_STAGES; 
    P->rate[30] = pa->Imm;            P->rToI[30] = P->Total_Imm_Rate_Preassure[1][k]; 


    /* 31 (Age 1): Pre-Symptomatic into Infectious (I1 --> I1-1 and I2 --> I2 + 1)  */
    /*                                                         and AI --> AI + 1 */              
    P->rate[31] = pa->p_1*pa->Gamma_1; P->rToI[31] = pa->p_1*pa->Gamma_1 * (double)P->n[n1I1];

    /* 32 (Age 1): Pre-Symptomatic into A-symptomatic (I1 --> I1-1 and A --> A+1) */
    P->rate[32] = (1.0-pa->p_1)*pa->Gamma_1;
    P->rToI[32] = (1.0-pa->p_1)*pa->Gamma_1*(double)P->n[n1I1];

    /* 33 (Age 1): Out-Migration (I1 --> I1-1) and some other patch gains one */ 
    P->rate[33] = OutMigration_1;      P->rToI[33] = OutMigration_1 * (double)P->n[n1I1];

    /* 34 (Age 1): In-Migration (I1 --> I1+1) and some other patch loses one */
                                      k            = n1I1%Table->TOTAL_No_of_DISEASE_STAGES; 
    P->rate[34] = pa->Imm;            P->rToI[34]  = P->Total_Imm_Rate_Preassure[1][k]; 


    /* 35 (Age 1): Infectious I2 into Recovered (I2 -> I2-1 and R --> R+1) */
    /*                                                    and AR --> AR + 1 */              
    P->rate[35] = pa->Gamma_2;         P->rToI[35] = pa->Gamma_2 * (double)P->n[n1I2];  
  
    /* 36 (Age 1): Infectious I2 into severe symptoms */
    P->rate[36] = pa->Alpha_1;         P->rToI[36] = pa->Alpha_1 * (double)P->n[n1I2];    

    /* 37 (Age 1): Out-Migration (I2 --> I2-1) and some other patch gains one */ 
    P->rate[37] = (1.0-pa->Eps_I)*OutMigration_1;
    P->rToI[37] = (1.0-pa->Eps_I)*OutMigration_1 * (double)P->n[n1I2];

    /* 38 (Age 1): In-Migration (I2 --> I2 + 1) and some other patch loses one */ 
    P->rate[38] = pa->Imm;
    k           = n1I2%Table->TOTAL_No_of_DISEASE_STAGES; 
    P->rToI[38] = (1.0-pa->Eps_I)*P->Total_Imm_Rate_Preassure[1][k]; 


    /* 39 (Age 1): Assymptomatic into Recovered (A -> A-1 and R --> R + 1)    */
    /* We don't consider accumulating these recovered (AR --> AR + 1)        
       because they have not been detected by the system                      */  
    P->rate[39] = pa->Gamma_2;         P->rToI[39] = pa->Gamma_2 * (double)P->n[n1A];

    /* 40 (Age 1): Assymptomatic are detected   (A -> A-1 and Ad --> Ad + 1)  */
    /*                                                    and AI --> AI + 1   */              
    P->rate[40] = pa->Kappa;           P->rToI[40] = pa->Kappa * (double)P->n[n1A];

    /* 41 (Age 1): Out-Migration (A --> A-1) and some other patch gains one */ 
    P->rate[41] = OutMigration_1;      P->rToI[41]  = OutMigration_1 * (double)P->n[n1A];

    /* 42 (Age 1): In-Migration (A --> A +1) and some other patch loses one */
                                       k            = n1A%Table->TOTAL_No_of_DISEASE_STAGES;
    P->rate[42] = pa->Imm;             P->rToI[42]  = P->Total_Imm_Rate_Preassure[1][k]; 


    /* 43 (Age 1): Detected Assymtomatic are recovered (Ad -> Ad-1 and R --> R + 1) */
    /*                                                            and AR --> AR + 1 */            
    P->rate[43] = pa->Gamma_2;         P->rToI[43] = pa->Gamma_2 * (double)P->n[n1Ad];
    
    /* 44 (Age 1): Out-Migration (Ad --> Ad-1) and some other patch gains one */ 
    P->rate[44] = (1.0-pa->Eps_I)*OutMigration_1;
    P->rToI[44] = (1.0-pa->Eps_I)*OutMigration_1 * (double)P->n[n1Ad];

    /* 45 (Age 1): In-Migration (Ad --> Ad +1) and some other patch loses one */
    P->rate[45] = pa->Imm;
    k            = n1Ad%Table->TOTAL_No_of_DISEASE_STAGES;
    P->rToI[45] = (1.0-pa->Eps_I)*P->Total_Imm_Rate_Preassure[1][k]; 

    /* 46 (Age 1): Severe Infecious recover (Y --> Y-1 and R --> R + 1) */
    /*                                                 and AR --> AR + 1   */              
    P->rate[46] = pa->Gamma_2;         P->rToI[46] = pa->Gamma_2 * (double)P->n[n1Y];

    /* 47 (Age 1): Severe Infecious die (Y --> Y-1 and D --> D + 1 */
    P->rate[47] = pa->Delta_1;         P->rToI[47] = pa->Delta_1 * (double)P->n[n1Y];
    /* .. (Age 1): Severe Infectious don't move!!! */


    /* 48 (Age 1): Recovered individuals move (R --> R-1 and some other patch gains one) */
    P->rate[48] = OutMigration_1;      P->rToI[48] = OutMigration_1 * (double)P->n[n1R];

    /* 49 (Age 1): In-Migration (R --> R + 1) and some other patch loses one */
                                       k            = n1R%Table->TOTAL_No_of_DISEASE_STAGES;
    P->rate[49] = pa->Imm;             P->rToI[49]  = P->Total_Imm_Rate_Preassure[1][k]; 

    
    /* AGE 2 --------------------------------------------------------------------------*/
    /* --------------------------------------------------------------------------------*/
    /* 50 (Age 2): Infection (S --> S-1 and E --> E + 1) */ 
    P->rate[50] = Lambda_2;           P->rToI[50] = Lambda_2 * (double)P->n[n2S];

    /* 51 (Age 2): Out-Migration (S --> S-1) and some other patch gains one */ 
    P->rate[51] = OutMigration_2;     P->rToI[51]  = OutMigration_2 * (double)P->n[n2S];
    
    /* 52 (Age 2): In-Migration (S --> S+1) and some other patch loses one */
                                      k            = n2S%Table->TOTAL_No_of_DISEASE_STAGES;
    P->rate[52] = pa->Imm;            P->rToI[52]  = P->Total_Imm_Rate_Preassure[2][k]; 


    /* 53 (Age 2):  Exposed into Infectious (E --> E-1 and I1 --> I1 + 1)*/ 
    P->rate[53] = pa->Sigma;          P->rToI[53] = pa->Sigma * (double)P->n[n2E];

    /* 54 (Age 2): Out-Migration (E --> E-1) and some other patch gains one */ 
    P->rate[54] = OutMigration_2;     P->rToI[54]  = OutMigration_2 * (double)P->n[n2E];

    /* 55 (Age 2): In-Migration (E --> E+1) and some other patch loses one */
                                      k            = n2E%Table->TOTAL_No_of_DISEASE_STAGES;
    P->rate[55] = pa->Imm;            P->rToI[55]  = P->Total_Imm_Rate_Preassure[2][k]; 


    /* 56 (Age 2): Pre-Symptomatic into Infectious (I1 --> I1-1 and I2 --> I2 + 1)  */
    /*                                                         and AI --> AI + 1 */              
    P->rate[56] = pa->p_2*pa->Gamma_1; P->rToI[56] = pa->p_2*pa->Gamma_1 * (double)P->n[n2I1];

    /* 57 (Age 2): Pre-Symptomatic into A-symptomatic (I1 --> I1-1 and A --> A+1) */
    P->rate[57] = (1.0-pa->p_2)*pa->Gamma_1;
    P->rToI[57] = (1.0-pa->p_2)*pa->Gamma_1*(double)P->n[n2I1];

    /* 58 (Age 2): Out-Migration (I1 --> I1-1) and some other patch gains one */ 
    P->rate[58] = OutMigration_2;      P->rToI[58] = OutMigration_2 * (double)P->n[n2I1];

    /* 59 (Age 2): In-Migration (I1 --> I1+1) and some other patch loses one */
                                      k            = n2I1%Table->TOTAL_No_of_DISEASE_STAGES;
    P->rate[59] = pa->Imm;            P->rToI[59]  = P->Total_Imm_Rate_Preassure[2][k]; 


    /* 60 (Age 2): Infectious I2 into Recovered (I2 -> I2-1 and R --> R+1) */
    /*                                                    and AR --> AR + 1 */              
    P->rate[60] = pa->Gamma_2;         P->rToI[60] = pa->Gamma_2 * (double)P->n[n2I2];  
  
    /* 61 (Age 2): Infectious I2 into severe symptoms */
    P->rate[61] = pa->Alpha_2;         P->rToI[61] = pa->Alpha_2 * (double)P->n[n2I2];
    
    /* 62 (Age 2): Out-Migration (I2 --> I2-1) and some other patch gains one */ 
    P->rate[62] = (1.0-pa->Eps_I)*OutMigration_2;
    P->rToI[62] = (1.0-pa->Eps_I)*OutMigration_2 * (double)P->n[n2I2];

    /* 63 (Age 2): In-Migration (I2 --> I1 + 1) and some other patch loses one */ 
    P->rate[63] = pa->Imm;
    k           = n2I2%Table->TOTAL_No_of_DISEASE_STAGES;
    P->rToI[63] = (1.0-pa->Eps_I)*P->Total_Imm_Rate_Preassure[2][k]; 


    /* 64 (Age 2): Assymptomatic into Recovered (A -> A-1 and R --> R + 1)    */
    /* We don't consider accumulating these recovered (AR --> AR + 1)        
       because they have not been detected by the system                      */  
    P->rate[64] = pa->Gamma_2;         P->rToI[64] = pa->Gamma_2 * (double)P->n[n2A];

    /* 65 (Age 2): Assymptomatic are detected   (A -> A-1 and Ad --> Ad + 1)  */
    /*                                                    and AI --> AI + 1   */              
    P->rate[65] = pa->Kappa;           P->rToI[65] = pa->Kappa * (double)P->n[n2A];

    /* 66 (Age 2): Out-Migration (A --> A-1) and some other patch gains one */ 
    P->rate[66] = OutMigration_2;      P->rToI[66]  = OutMigration_2 * (double)P->n[n2A];

    /* 67 (Age 2): In-Migration (A --> A +1) and some other patch loses one */
                                        k           = n2A%Table->TOTAL_No_of_DISEASE_STAGES;
    P->rate[67] = pa->Imm;              P->rToI[67] = P->Total_Imm_Rate_Preassure[2][k]; 


    /* 68 (Age 2): Detected Assymtomatic are recovered (Ad -> Ad-1 and R --> R + 1) */
    /*                                                            and AR --> AR + 1 */            
    P->rate[68] = pa->Gamma_2;         P->rToI[68] = pa->Gamma_2 * (double)P->n[n2Ad];
    
    /* 69 (Age 2): Out-Migration (Ad --> Ad-1) and some other patch gains one */ 
    P->rate[69] = (1.0-pa->Eps_I)*OutMigration_2;
    P->rToI[69] = (1.0-pa->Eps_I)*OutMigration_2 * (double)P->n[n2Ad];

    /* 70 (Age 2): In-Migration (Ad --> Ad +1) and some other patch loses one */ 
    P->rate[70] = pa->Imm;
    k           = n2Ad%Table->TOTAL_No_of_DISEASE_STAGES;
    P->rToI[70] = (1.0-pa->Eps_I)*P->Total_Imm_Rate_Preassure[2][k]; 

    
    /* 71 (Age 2): Severe Infecious recover (Y --> Y-1 and R --> R + 1) */
    /*                                                 and AR --> AR + 1   */              
    P->rate[71] = pa->Gamma_2;         P->rToI[71] = pa->Gamma_2 * (double)P->n[n2Y];

    /* 72 (Age 2): Severe Infecious die (Y --> Y-1 and D --> D + 1 */
    P->rate[72] = pa->Delta_2;         P->rToI[72] = pa->Delta_2 * (double)P->n[n2Y];
    /* .. (Age 2): Severe Infectious don't move!!! */


    /* 73 (Age 2): Recovered individuals move (R --> R-1 and some other patch gains one) */
    P->rate[73] = OutMigration_2;      P->rToI[73] = OutMigration_2 * (double)P->n[n2R];

    /* 74 (Age 2): In-Migration (R --> R + 1) and some other patch loses one */
                                       k            = n2R%Table->TOTAL_No_of_DISEASE_STAGES; 
    P->rate[74] = pa->Imm;             P->rToI[74]  = P->Total_Imm_Rate_Preassure[2][k]; 

    
    /* AGE 3 --------------------------------------------------------------------------*/
    /* --------------------------------------------------------------------------------*/
    /* 75 (Age 3): Infection (S --> S-1 and E --> E + 1) */ 
    P->rate[75] = Lambda_3;           P->rToI[75] = Lambda_3 * (double)P->n[n3S];

    /* 76 (Age 3): Out-Migration (S --> S-1) and some other patch gains one */ 
    P->rate[76] = OutMigration_3;     P->rToI[76]  = OutMigration_3 * (double)P->n[n3S];
    
    /* 77 (Age 3): In-Migration (S --> S+1) and some other patch loses one */
                                      k            = n3S%Table->TOTAL_No_of_DISEASE_STAGES;
    P->rate[77] = pa->Imm;            P->rToI[77]  = P->Total_Imm_Rate_Preassure[3][k]; 


    /* 78 (Age 3):  Exposed into Infectious (E --> E-1 and I1 --> I1 + 1)*/ 
    P->rate[78] = pa->Sigma;          P->rToI[78] = pa->Sigma * (double)P->n[n3E];

    /* 79 (Age 3): Out-Migration (E --> E-1) and some other patch gains one */ 
    P->rate[79] = OutMigration_3;     P->rToI[79]  = OutMigration_3 * (double)P->n[n3E];

    /* 80 (Age 3): In-Migration (E --> E+1) and some other patch loses one */
                                      k            = n3E%Table->TOTAL_No_of_DISEASE_STAGES;
    P->rate[80] = pa->Imm;            P->rToI[80]  = P->Total_Imm_Rate_Preassure[3][k]; 


    /* 81 (Age 3): Pre-Symptomatic into Infectious (I1 --> I1-1 and I2 --> I2 + 1)  */
    /*                                                         and AI --> AI + 1 */              
    P->rate[81] = pa->p_3*pa->Gamma_1; P->rToI[81] = pa->p_3*pa->Gamma_1 * (double)P->n[n3I1];

    /* 82 (Age 3): Pre-Symptomatic into A-symptomatic (I1 --> I1-1 and A --> A+1) */
    P->rate[82] = (1.0-pa->p_3)*pa->Gamma_1;
    P->rToI[82] = (1.0-pa->p_3)*pa->Gamma_1*(double)P->n[n3I1];

    /* 83 (Age 3): Out-Migration (I1 --> I1-1) and some other patch gains one */ 
    P->rate[83] = OutMigration_3;      P->rToI[83] = OutMigration_3 * (double)P->n[n3I1];

    /* 84 (Age 3): In-Migration (I1 --> I1+1) and some other patch loses one */
                                      k            = n3I1%Table->TOTAL_No_of_DISEASE_STAGES;
    P->rate[84] = pa->Imm;            P->rToI[84]  = P->Total_Imm_Rate_Preassure[3][k]; 


    /* 85 (Age 3): Infectious I2 into Recovered (I2 -> I2-1 and R --> R+1) */
    /*                                                    and AR --> AR + 1 */              
    P->rate[85] = pa->Gamma_2;         P->rToI[85] = pa->Gamma_2 * (double)P->n[n3I2];  
  
    /* 86 (Age 3): Infectious I2 into severe symptoms */
    P->rate[86] = pa->Alpha_3;         P->rToI[86] = pa->Alpha_3 * (double)P->n[n3I2];    

    /* 87 (Age 3): Out-Migration (I2 --> I2-1) and some other patch gains one */ 
    P->rate[87] = (1.0-pa->Eps_I)*OutMigration_3;
    P->rToI[87] = (1.0-pa->Eps_I)*OutMigration_3 * (double)P->n[n3I2];

    /* 88 (Age 3): In-Migration (I2 --> I2 + 1) and some other patch loses one */
    P->rate[88] = pa->Imm;
    k           = n3I2%Table->TOTAL_No_of_DISEASE_STAGES;
    P->rToI[88] = (1.0-pa->Eps_I)*P->Total_Imm_Rate_Preassure[3][k]; 


    /* 89 (Age 3): Assymptomatic into Recovered (A -> A-1 and R --> R + 1)    */
    /* We don't consider accumulating these recovered (AR --> AR + 1)        
       because they have not been detected by the system                      */  
    P->rate[89] = pa->Gamma_2;         P->rToI[89] = pa->Gamma_2 * (double)P->n[n3A];

    /* 90 (Age 3): Assymptomatic are detected   (A -> A-1 and Ad --> Ad + 1)  */
    /*                                                    and AI --> AI + 1   */              
    P->rate[90] = pa->Kappa;           P->rToI[90] = pa->Kappa * (double)P->n[n3A];

    /* 91 (Age 3): Out-Migration (A --> A-1) and some other patch gains one */ 
    P->rate[91] = OutMigration_3;      P->rToI[91]  = OutMigration_3 * (double)P->n[n3A];

    /* 92 (Age 3): In-Migration (A --> A +1) and some other patch loses one */
                                       k           = n3A%Table->TOTAL_No_of_DISEASE_STAGES;
    P->rate[92] = pa->Imm;             P->rToI[92] = P->Total_Imm_Rate_Preassure[3][k]; 


    /* 93 (Age 3): Detected Assymtomatic are recovered (Ad -> Ad-1 and R --> R + 1) */
    /*                                                            and AR --> AR + 1 */            
    P->rate[93] = pa->Gamma_2;         P->rToI[93] = pa->Gamma_2 * (double)P->n[n3Ad];
    
    /* 94 (Age 3): Out-Migration (Ad --> Ad-1) and some other patch gains one */ 
    P->rate[94] = (1.0-pa->Eps_I)*OutMigration_3;
    P->rToI[94] = (1.0-pa->Eps_I)*OutMigration_3 * (double)P->n[n3Ad];

    /* 95 (Age 3): In-Migration (Ad --> Ad +1) and some other patch loses one */ 
    P->rate[95] = pa->Imm;
    k           = n3Ad%Table->TOTAL_No_of_DISEASE_STAGES;
    P->rToI[95] = (1.0-pa->Eps_I)*P->Total_Imm_Rate_Preassure[3][k]; 

    
    /* 96 (Age 3): Severe Infecious recover (Y --> Y-1 and R --> R + 1) */
    /*                                                 and AR --> AR + 1   */              
    P->rate[96] = pa->Gamma_2;         P->rToI[96] = pa->Gamma_2 * (double)P->n[n3Y];

    /* 97 (Age 3): Severe Infecious die (Y --> Y-1 and D --> D + 1 */
    P->rate[97] = pa->Delta_3;         P->rToI[97] = pa->Delta_3 * (double)P->n[n3Y];
    /* .. (Age 3): Severe Infectious don't move!!! */


    /* 98 (Age 3): Recovered individuals move (R --> R-1 and some other patch gains one) */
    P->rate[98] = OutMigration_3;      P->rToI[98] = OutMigration_3 * (double)P->n[n3R];

    /* 99 (Age 3): In-Migration (R --> R + 1) and some other patch loses one */
                                       k           = n3R%Table->TOTAL_No_of_DISEASE_STAGES;
    P->rate[99] = pa->Imm;             P->rToI[99] = P->Total_Imm_Rate_Preassure[3][k]; 
    
     
    P->ratePatch = 0; 
    for(j=0; j < No_of_EVENTS; j++)  P->ratePatch += P->rToI[j];

    Rate->Total_Rate += P->ratePatch;
    Rate->max_Probability = MAX( Rate->max_Probability, P->ratePatch );
  }

  if(Rate->Total_Rate <= 0.0){
      printf("\n");
      printf(" R is the total temporal rate of system configuration change\n");
      printf(" R = %g\n", Rate->Total_Rate );
      printf(" As R is zero or negative, no change is possible\n");
      printf(" R shouldn't be negative. If it is, there are definitely some errors in the code\n");
      printf("\n");
      if( Rate->Total_Rate < 0.0 ) exit(0);
  }
}

double Imm_Preassure(Parameter_Table * Table, int nS, int a, int x)
{
  /* This is the probability rate of some immigration occuring into focal patch x
     coming from its patch neighborhood. 
  */
  double Total_Rate;
  int k;
  
  Community ** Patch = Table->Patch_System;
  
  k = nS%Table->TOTAL_No_of_DISEASE_STAGES; 
  Total_Rate = Patch[x]->Total_Imm_Rate_Preassure[a][k]; 
  
  return(Total_Rate);
}
