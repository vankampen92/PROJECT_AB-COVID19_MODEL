extern double Kappa  ;   /*  0 */     /* Total (Initial) Population */  
extern double Imm    ;  /*  1 */     /* Total Immigration Rate */  
extern double Beta   ; /*  2 */     /* Contact rate: Total no of contacts an individual has per day   */
extern double b      ;   /*  3 */     /* Infectivity  */ 
extern double Phi    ;  /*  4 */     /* Pre-symptomatic Infectivity Factor */  
extern double Eps_I ; /*  5 */   /* Isolation effectiveness of strong cases */ 
extern double Eps_Y  ;   /*  6 */   /* Isolation effectiveness of serious cases */
extern double Sigma  ;  /*  7 */   /* Rate of the appearance of infectious capacity */
extern double Gamma_1; /*  8 */  /* Rate of the appearance of symptoms  */ 

extern double Alpha  ;   /* 10 */  /* (Age-dependent) Rate of appearence of serious symptoms */     
extern double Delta  ;  /* 11 */  /* (Age-dependent) Disease-Induced Mortality Rate */    
extern double Gamma_2; /* 12 */  /* Rate of Recovery */

/* extern double D_Sigma;      */
/* extern double Sigmoidal_A0; */
/* extern double Sigmoidal_L0; */
/* extern double Sigmoidal_T0; */

extern double N; 

extern double N0;
extern double N1;
extern double N2;
extern double N3;

extern double Beta_00;
extern double Beta_01;
extern double Beta_02;
extern double Beta_03;

extern double Beta_10;
extern double Beta_11;
extern double Beta_12;
extern double Beta_13;

extern double Beta_20;
extern double Beta_21;
extern double Beta_22;
extern double Beta_23;

extern double Beta_30;
extern double Beta_31;
extern double Beta_32;
extern double Beta_33;

extern double Alpha_0;
extern double Alpha_1;
extern double Alpha_2;
extern double Alpha_3;

extern double Delta_0;
extern double Delta_1;
extern double Delta_2;
extern double Delta_3;

extern double p_0   ;    /*  9 */  /* Probability of the appearance of strong symptoms */
extern double p_1   ;    /*  9 */  /* Probability of the appearance of strong symptoms */
extern double p_2   ;    /*  9 */  /* Probability of the appearance of strong symptoms */
extern double p_3   ;    /*  9 */  /* Probability of the appearance of strong symptoms */

extern int No_of_LOCAL_POPULATIONS;

/* Type of model */
#include <include.Type_of_Model.extern.h>
