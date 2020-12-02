double Kappa; 
double Imm    ;  /*  1 */     /* Total Immigration Rate */
double Beta   ; /*  2 */     /* Contact rate: Total no of contacts an individual has per day   */
double b      ;   /*  3 */     /* Infectivity  */
double Phi    ;  /*  4 */     /* Pre-symptomatic Infectivity Factor */
double Eps_I ; /*  5 */   /* Isolation effectiveness of strong cases */
double Eps_Y  ;   /*  6 */   /* Isolation effectiveness of serious cases */
double Sigma  ;  /*  7 */   /* Rate of the appearance of infectious capacity */
double Gamma_1; /*  8 */  /* Rate of the appearance of symptoms  */

double Alpha  ;   /* 10 */  /* (Age-dependent) Rate of appearence of serious symptoms */
double Delta  ;  /* 11 */  /* (Age-dependent) Disease-Induced Mortality Rate */
double Gamma_2; /* 12 */  /* Rate of Recovery */

double D_Sigma;
double Sigmoidal_A0;
double Sigmoidal_L0;
double Sigmoidal_T0;

double N      ;   /*  0 */     /* Total (Initial) Population */

double N0;
double N1;
double N2;
double N3;

double Beta_00;
double Beta_01;
double Beta_02;
double Beta_03;

double Beta_10;
double Beta_11;
double Beta_12;
double Beta_13;

double Beta_20;
double Beta_21;
double Beta_22;
double Beta_23;

double Beta_30;
double Beta_31;
double Beta_32;
double Beta_33;

double Alpha_0;
double Alpha_1;
double Alpha_2;
double Alpha_3;

double Delta_0;
double Delta_1;
double Delta_2;
double Delta_3;

double p_0   ;    /*  9 */  /* Probability of the appearance of strong symptoms */
double p_1   ;    /*  9 */  /* Probability of the appearance of strong symptoms */
double p_2   ;    /*  9 */  /* Probability of the appearance of strong symptoms */
double p_3   ;    /*  9 */  /* Probability of the appearance of strong symptoms */

int No_of_LOCAL_POPULATIONS; 

/* Type of model */
#include <include.Type_of_Model.global.h>
