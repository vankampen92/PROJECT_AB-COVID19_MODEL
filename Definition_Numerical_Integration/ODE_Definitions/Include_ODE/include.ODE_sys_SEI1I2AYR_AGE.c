/* c: Children (0-5) */
dydt[n0S] = - (Table->Beta_00 * Table->b / Table->N0 * (Table->Phi * y[n0I1] + y[n0A] + (1.0-Table->Eps_I) * y[n0I2] + (1.0-Table->Eps_Y) * y[n0Y] ) +                        
	       Table->Beta_01 * Table->b / Table->N1 * (Table->Phi * y[n1I1] + y[n1A] + (1.0-Table->Eps_I) * y[n1I2] + (1.0-Table->Eps_Y) * y[n1Y] ) +                       
	       Table->Beta_02 * Table->b / Table->N2 * (Table->Phi * y[n2I1] + y[n2A] + (1.0-Table->Eps_I) * y[n2I2] + (1.0-Table->Eps_Y) * y[n2Y] ) +                       
	       Table->Beta_03 * Table->b / Table->N3 * (Table->Phi * y[n3I1] + y[n3A] + (1.0-Table->Eps_I) * y[n3I2] + (1.0-Table->Eps_Y) * y[n3Y] )                        
	      )  * y[n0S];                                                                                                                                                   /* n0S */
dydt[n0E] =   (Table->Beta_00 * Table->b / Table->N0 * (Table->Phi * y[n0I1] + y[n0A] + (1.0-Table->Eps_I) * y[n0I2] + (1.0-Table->Eps_Y) * y[n0Y] ) +                       
	       Table->Beta_01 * Table->b / Table->N1 * (Table->Phi * y[n1I1] + y[n1A] + (1.0-Table->Eps_I) * y[n1I2] + (1.0-Table->Eps_Y) * y[n1Y] ) +                        
	       Table->Beta_02 * Table->b / Table->N2 * (Table->Phi * y[n2I1] + y[n2A] + (1.0-Table->Eps_I) * y[n2I2] + (1.0-Table->Eps_Y) * y[n2Y] ) +                        
	       Table->Beta_03 * Table->b / Table->N3 * (Table->Phi * y[n3I1] + y[n3A] + (1.0-Table->Eps_I) * y[n3I2] + (1.0-Table->Eps_Y) * y[n3Y] )                         
	      ) * y[n0S] - Table->Sigma * y[n0E];                                                                                                                            /* n0E */

dydt[n0I1] = Table->Sigma * y[n0E] - Table->Gamma_1 * y[n0I1];                                                                                                               /* n0I1 */

dydt[n0I2] = Table->p_0 * Table->Gamma_1 * y[n0I1] - Table->Gamma_2 * y[n0I2]  - Table->Alpha_0 * y[n0I2];                                                                  /* n0I2 */

dydt[n0A] = (1.0 - Table->p_0) * Table->Gamma_1 * y[n0I1] - Table->Gamma_2 * y[n0A];                                                                                       /* n0A */

dydt[n0Y] = Table->Alpha_0 * y[n0I2] - Table->Gamma_2 * y[n0Y] - Table->Delta_0 * y[n0Y];                                                                                    /* n0Y */

dydt[n0R] = Table->Gamma_2 * (y[n0A] + y[n0I2] + y[n0Y]) ;                                                                                                                   /* n0R */

dydt[a0I] = Table->p_0 * Table->Gamma_1 * y[n0I1];                                                                                                                          /* a0I */

dydt[a0R] = Table->Gamma_2 * (y[n0I2] + y[n0Y]);                                                                                                                             /* a0R */

dydt[a0D] = Table->Delta_0 * y[n0Y];                                                                                                                                         /* a0D */

/* s: Students (6-25) */
dydt[n1S] = - (Table->Beta_10 * Table->b / Table->N0 * (Table->Phi * y[n0I1] + y[n0A] + (1.0-Table->Eps_I) * y[n0I2] + (1.0-Table->Eps_Y) * y[n0Y] ) +                        
	       Table->Beta_11 * Table->b / Table->N1 * (Table->Phi * y[n1I1] + y[n1A] + (1.0-Table->Eps_I) * y[n1I2] + (1.0-Table->Eps_Y) * y[n1Y] ) +                        
	       Table->Beta_12 * Table->b / Table->N2 * (Table->Phi * y[n2I1] + y[n2A] + (1.0-Table->Eps_I) * y[n2I2] + (1.0-Table->Eps_Y) * y[n2Y] ) +                        
	       Table->Beta_13 * Table->b / Table->N3 * (Table->Phi * y[n3I1] + y[n3A] + (1.0-Table->Eps_I) * y[n3I2] + (1.0-Table->Eps_Y) * y[n3Y] )                         
	       ) * y[n1S];                                                                                                                                                    /* n1S */

dydt[n1E] =   (Table->Beta_10 * Table->b / Table->N0 * (Table->Phi * y[n0I1] + y[n0A] + (1.0-Table->Eps_I) * y[n0I2] + (1.0-Table->Eps_Y) * y[n0Y] ) +                        
	       Table->Beta_11 * Table->b / Table->N1 * (Table->Phi * y[n1I1] + y[n1A] + (1.0-Table->Eps_I) * y[n1I2] + (1.0-Table->Eps_Y) * y[n1Y] ) +                        
	       Table->Beta_12 * Table->b / Table->N2 * (Table->Phi * y[n2I1] + y[n2A] + (1.0-Table->Eps_I) * y[n2I2] + (1.0-Table->Eps_Y) * y[n2Y] ) +                        
	       Table->Beta_13 * Table->b / Table->N3 * (Table->Phi * y[n3I1] + y[n3A] + (1.0-Table->Eps_I) * y[n3I2] + (1.0-Table->Eps_Y) * y[n3Y] )                         
	      ) * y[n1S] - Table->Sigma * y[n1E];                                                                                                                            /* n1E */

dydt[n1I1] = Table->Sigma * y[n1E] - Table->Gamma_1 * y[n1I1];                                                                                                               /* n1I1 */

dydt[n1I2] = Table->p_1 * Table->Gamma_1 * y[n1I1] - Table->Gamma_2 * y[n1I2]  - Table->Alpha_1 * y[n1I2];                                                                  /* n1I2 */

dydt[n1A] = (1.0 - Table->p_1) * Table->Gamma_1 * y[n1I1] - Table->Gamma_2 * y[n1A];                                                                                       /* n1A */
 
dydt[n1Y] = Table->Alpha_1 * y[n1I2] - Table->Gamma_2 * y[n1Y] - Table->Delta_1 * y[n1Y];                                                                                    /* n1Y */

dydt[n1R] = Table->Gamma_2 * (y[n1A] + y[n1I2] + y[n1Y]) ;                                                                                                                   /* n1R */

dydt[a1I] = Table->p_1 * Table->Gamma_1 * y[n1I1];                                                                                                                           /* a1I */

dydt[a1R] = Table->Gamma_2 * (y[n1I2] + y[n1Y]);                                                                                                                             /* a1R */

dydt[a1D] = Table->Delta_1 * y[n1Y];                                                                     

/* w: Adults (26-65) */
dydt[n2S] = - ( Table->Beta_20 * Table->b / Table->N0 * (Table->Phi * y[n0I1] + y[n0A] + (1.0-Table->Eps_I) * y[n0I2] + (1.0-Table->Eps_Y) * y[n0Y] ) +                        
	        Table->Beta_21 * Table->b / Table->N1 * (Table->Phi * y[n1I1] + y[n1A] + (1.0-Table->Eps_I) * y[n1I2] + (1.0-Table->Eps_Y) * y[n1Y] ) +                        
	        Table->Beta_22 * Table->b / Table->N2 * (Table->Phi * y[n2I1] + y[n2A] + (1.0-Table->Eps_I) * y[n2I2] + (1.0-Table->Eps_Y) * y[n2Y] ) +                        
	        Table->Beta_13 * Table->b / Table->N3 * (Table->Phi * y[n3I1] + y[n3A] + (1.0-Table->Eps_I) * y[n3I2] + (1.0-Table->Eps_Y) * y[n3Y] )                         
	       ) * y[n2S];                                                                                                                                                   /* n2S */

dydt[n2E] =   ( Table->Beta_20 * Table->b / Table->N0 * (Table->Phi * y[n0I1] + y[n0A] + (1.0-Table->Eps_I) * y[n0I2] + (1.0-Table->Eps_Y) * y[n0Y] ) +                        
	        Table->Beta_21 * Table->b / Table->N1 * (Table->Phi * y[n1I1] + y[n1A] + (1.0-Table->Eps_I) * y[n1I2] + (1.0-Table->Eps_Y) * y[n1Y] ) +                        
	        Table->Beta_22 * Table->b / Table->N2 * (Table->Phi * y[n2I1] + y[n2A] + (1.0-Table->Eps_I) * y[n2I2] + (1.0-Table->Eps_Y) * y[n2Y] ) +                        
	        Table->Beta_23 * Table->b / Table->N3 * (Table->Phi * y[n3I1] + y[n3A] + (1.0-Table->Eps_I) * y[n3I2] + (1.0-Table->Eps_Y) * y[n3Y] )                         
	       ) * y[n2S] - Table->Sigma * y[n2E];                                                                                                                           /* n2E */

dydt[n2I1] = Table->Sigma * y[n2E] - Table->Gamma_1 * y[n2I1];                                                                                                               /* n2I1 */

dydt[n2I2] = Table->p_2 * Table->Gamma_1 * y[n2I1] - Table->Gamma_2 * y[n2I2]  - Table->Alpha_2 * y[n2I2];                                                                  /* n2I2 */

dydt[n2A] = (1.0 - Table->p_2) * Table->Gamma_1 * y[n2I1] - Table->Gamma_2 * y[n2A];                                                                                       /* n2A */
 
dydt[n2Y] = Table->Alpha_2 * y[n2I2] - Table->Gamma_2 * y[n2Y] - Table->Delta_2 * y[n2Y];                                                                                    /* n2Y */

dydt[n2R] = Table->Gamma_2 * (y[n2A] + y[n2I2] + y[n2Y]) ;                                                                                                                   /* n2R */

dydt[a2I] = Table->p_2 * Table->Gamma_1 * y[n2I1];                                                                                                                          /* a2I */

dydt[a2R] = Table->Gamma_2 * (y[n2I2] + y[n2Y]);                                                                                                                             /* a2R */

dydt[a2D] = Table->Delta_2 * y[n2Y];                                                                       

/* a: Seniors (65-100) */
dydt[n3S] = -( Table->Beta_30 * Table->b / Table->N0 * (Table->Phi * y[n0I1] + y[n0A] + (1.0-Table->Eps_I) * y[n0I2] + (1.0-Table->Eps_Y) * y[n0Y] ) +                        
	       Table->Beta_31 * Table->b / Table->N1 * (Table->Phi * y[n1I1] + y[n1A] + (1.0-Table->Eps_I) * y[n1I2] + (1.0-Table->Eps_Y) * y[n1Y] ) +                        
	       Table->Beta_32 * Table->b / Table->N2 * (Table->Phi * y[n2I1] + y[n2A] + (1.0-Table->Eps_I) * y[n2I2] + (1.0-Table->Eps_Y) * y[n2Y] ) +                        
	       Table->Beta_33 * Table->b / Table->N3 * (Table->Phi * y[n3I1] + y[n3A] + (1.0-Table->Eps_I) * y[n3I2] + (1.0-Table->Eps_Y) * y[n3Y] )                         
	     ) * y[n3S];                                                                                                                                                      /* n3S */

dydt[n3E] =  ( Table->Beta_30 * Table->b / Table->N0 * (Table->Phi * y[n0I1] + y[n0A] + (1.0-Table->Eps_I) * y[n0I2] + (1.0-Table->Eps_Y) * y[n0Y] ) +                        
	       Table->Beta_31 * Table->b / Table->N1 * (Table->Phi * y[n1I1] + y[n1A] + (1.0-Table->Eps_I) * y[n1I2] + (1.0-Table->Eps_Y) * y[n1Y] ) +                        
	       Table->Beta_32 * Table->b / Table->N2 * (Table->Phi * y[n2I1] + y[n2A] + (1.0-Table->Eps_I) * y[n2I2] + (1.0-Table->Eps_Y) * y[n2Y] ) +                        
	       Table->Beta_33 * Table->b / Table->N3 * (Table->Phi * y[n3I1] + y[n3A] + (1.0-Table->Eps_I) * y[n3I2] + (1.0-Table->Eps_Y) * y[n3Y] )                         
	     ) * y[n3S] - Table->Sigma * y[n3E];                                                                                                                             /* n3E */

dydt[n3I1] = Table->Sigma * y[n3E] - Table->Gamma_1 * y[n3I1];                                                                                                               /* n3I1 */

dydt[n3I2] = Table->p_3 * Table->Gamma_1 * y[n3I1] - Table->Gamma_2 * y[n3I2]  - Table->Alpha_3 * y[n3I2];                                                                  /* n3I2 */

dydt[n3A] = (1.0 - Table->p_3) * Table->Gamma_1 * y[n3I1] - Table->Gamma_2 * y[n3A];                                                                                       /* n3A */
 
dydt[n3Y] = Table->Alpha_3 * y[n3I2] - Table->Gamma_2 * y[n3Y] - Table->Delta_3 * y[n3Y];                                                                                    /* n3Y */

dydt[n3R] = Table->Gamma_2 * (y[n3A] + y[n3I2] + y[n3Y]) ;                                                                                                                   /* n3R */

dydt[a3I] = Table->p_3 * Table->Gamma_1 * y[n3I1];                                                                                                                          /* a3I */

dydt[a3R] = Table->Gamma_2 * (y[n3I2] + y[n3Y]);                                                                                                                             /* a3R */

dydt[a3D] = Table->Delta_3 * y[n3Y];                                                                       
