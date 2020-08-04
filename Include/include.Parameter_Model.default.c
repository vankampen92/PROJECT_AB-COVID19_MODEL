 Kappa  = 0.05;   /*  0 */     /* */  
 Imm    = 5.0 ;  /*  1 */     /* Total Immigration Rate */  
 Beta   = 5.0 ; /*  2 */     /* Contact rate: Total no of contacts an individual has per day   */
 b      = 0.8 ;   /*  3 */     /* Infectivity  */ 
 Phi    = 0.5 ;  /*  4 */     /* Pre-symptomatic Infectivity Factor */  
 Eps_I = 0.1 ; /*  5 */   /* Isolation effectiveness of strong cases */ 
 Eps_Y  = 0.9 ;   /*  6 */   /* Isolation effectiveness of serious cases */
 Sigma  = 0.25 ;  /*  7 */   /* Rate of the appearance of infectious capacity */
 Gamma_1= 0.25 ; /*  8 */  /* Rate of the appearance of symptoms  */ 

 Alpha  = 0.5 ;   /* 10 */  /* (Age-dependent) Rate of appearence of serious symptoms */     
 Delta  = 0.25 ;  /* 11 */  /* (Age-dependent) Disease-Induced Mortality Rate */    
 Gamma_2= 0.1 ; /* 12 */  /* Rate of Recovery */

 N  = 100000.0; 

 N0 = 10000.0;
 N1 = 20000.0 ;
 N2 = 70000.0 ;
 N3 = 10000.0 ;

 Beta_00 = 5.0;
 Beta_01 = 5.0;
 Beta_02 = 5.0;
 Beta_03 = 5.0;

 Beta_10 = 5.0;
 Beta_11 = 5.0;
 Beta_12 = 5.0;
 Beta_13 = 5.0;

 Beta_20 = 5.0;
 Beta_21 = 5.0;
 Beta_22 = 5.0;
 Beta_23 = 5.0;

 Beta_30 = 5.0;
 Beta_31 = 5.0;
 Beta_32 = 5.0;
 Beta_33 = 5.0;

 Alpha_0 = 0.01 ;
 Alpha_1 = 0.01 ;
 Alpha_2 = 0.1 ;
 Alpha_3 = 0.2 ;
  
 Delta_0 = 0.25 ;
 Delta_1 = 0.25 ;
 Delta_2 = 0.25 ;
 Delta_3 = 0.25 ;

 p_0   = 0.1 ;    /*  9 */  /* Probability of the appearance of strong symptoms */
 p_1   = 0.1 ;    /*  9 */  /* Probability of the appearance of strong symptoms */
 p_2   = 0.3 ;    /*  9 */  /* Probability of the appearance of strong symptoms */
 p_3   = 0.5 ;    /*  9 */  /* Probability of the appearance of strong symptoms */

/* D_Sigma  = 0.0;   /\* Parameter introducing time-dependence in Sigma_0 and Sigma_1 *\/ */
/* Sigmoidal_A0 = 0.0;   /\* Parameter introducing time-dependence in Sigma_0 and Sigma_1 *\/;   */
/* Sigmoidal_L0 = 0.0;   /\* Parameter introducing time-dependence in Sigma_0 and Sigma_1 *\/ */
/* Sigmoidal_T0 = 0.0;   /\* Parameter introducing time-dependence in Sigma_0 and Sigma_1 *\/ */

 No_of_LOCAL_POPULATIONS = No_of_LOCAL_POPULATIONS_MAXIMUM; 

#include <include.Type_of_Model.default.c>
