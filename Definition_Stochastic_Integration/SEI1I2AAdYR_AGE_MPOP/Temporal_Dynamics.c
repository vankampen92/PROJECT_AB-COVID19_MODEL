/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                             David Alonso, 2010 (c)                        */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <MODEL.h>

void Temporal_Dynamics(Community ** My_Community, Parameter_Table * Table, Stochastic_Rate * Rate)
{
  int i,j,k;
  Community * P;
  int MODEL_STATE_VARIABLES;
  int No_of_PATCHES;
  int No_of_EVENTS;
  double y; 
  Parameter_Model * pa  = Table->P;

  /// M_O_D_E_L___V_A_R_I_A_B_L_E_S___C_O_D_E ( Table );
  int S, I, C;
  int X, W, K;
  S = Table->S; I = Table->I;
  X = Table->X; W = Table->W; 
  C = Table->C; K = Table->K;
  
  /* P = My_Community[0]; P is a pointer to zero-th patch 
                             and will be incremented     */  
  // for(i=0; i<No_of_PATCHES; i++, P++){

  Rate->max_Probability = 0.0;
  Rate->Total_Rate      = 0.0;
  
  No_of_PATCHES         = pa->No_of_PATCHES;
  MODEL_STATE_VARIABLES = pa->MODEL_STATE_VARIABLES;
  No_of_EVENTS          = pa->No_of_EVENTS;
  
  for(i=0; i<No_of_PATCHES; i++){
    
    P = My_Community[i];

    y = (double)P->n[I]/(double)P->H_POPULATION; 

    // pa->H_Beta = Beta_Function_Local(My_Community, i);
    pa->H_Beta = pa->M_a*pa->M_b * (double)P->n[W]/(double)P->H_POPULATION + pa->Imm; 
    pa->H_Recov = Queu_Function_Recovery_Integer(Table, P->n[W], pa->H_Recov_0, pa->W_Recov);
    
    /* Vilage Transition Rate */  
    P->ratePatch = 0.;
    /* Probability rate for each of the events */
    /* 0: Death (S --> S-1) */ 
    P->rate[0] = pa->H_Delta;        P->rToI[0] = pa->H_Delta * (double)P->n[S];

    /* 1: Birth (S --> S+1) */ 
    P->rate[1] = pa->H_Birth;        P->rToI[1] = pa->H_Birth * (double)P->H_POPULATION;

    /* 2: Death (I --> I-1) */ 
    P->rate[2] = pa->H_Delta;        P->rToI[2] = pa->H_Delta * (double)P->n[I];

    /* 3: Infection (S --> S-1 and I --> I+1) */ 
    P->rate[3] = pa->H_Beta;         P->rToI[3] = pa->H_Beta * (double)P->n[S];

    /* 4: Recovery (S --> S+1  and I --> I-1) */ 
    P->rate[4] = pa->H_Recov;        P->rToI[4] = pa->H_Recov * (double)P->n[I];  

    /* 5: Mosquito Infection (X --> X-1 and W ---> W+1) */ 
    P->rate[5] = pa->M_a*pa->M_c*y;  P->rToI[5] = pa->M_a*pa->M_c*y * (double)P->n[X];  

    /* 6: Mosquito Birth (X --> X+1) */   /* M_Delta = M_Fecundity */
    P->rate[6] = pa->M_Delta;        P->rToI[6] = pa->M_Delta * (double)P->M_POPULATION;  

    /* 7: Death (X --> X-1) */ 
    P->rate[7] = pa->M_Delta;        P->rToI[7] = pa->M_Delta * (double)P->n[X];  
    
    
    /* 8: Death (W --> W-1) */       
    P->rate[8] = pa->M_Delta;        P->rToI[8] = pa->M_Delta * (double)P->n[W];  
   
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


