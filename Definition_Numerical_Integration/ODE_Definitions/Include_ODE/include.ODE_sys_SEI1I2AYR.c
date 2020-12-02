/* C: Children (0-5) */
dydt[nS] = -Table->Beta * Table->b / Table->N * (Table->Phi * y[nI1] + y[nA] + (1.0-Table->Eps_I) * y[nI2] + (1.0-Table->Eps_Y) * y[nY]) * y[nS];                        /* nS */

dydt[nE] =  Table->Beta * Table->b / Table->N * (Table->Phi * y[nI1] + y[nA] + (1.0-Table->Eps_I) * y[nI2] + (1.0-Table->Eps_Y) * y[nY]) * y[nS] - Table->Sigma * y[nE]; /* nE */

dydt[nI1] = Table->Sigma * y[nE] - Table->Gamma_1 * y[nI1];                                                                                                               /* nI1 */

dydt[nI2] = Table->p_0 * Table->Gamma_1 * y[nI1] - Table->Gamma_2 * y[nI2]  - Table->Alpha * y[nI2];                                                                     /* nI2 */

dydt[nA] = (1.0 - Table->p_0) * Table->Gamma_1 * y[nI1] - Table->Gamma_2 * y[nA];                                                                                        /* nA */
 
dydt[nY] = Table->Alpha * y[nI2] - Table->Gamma_2 * y[nY] - Table->Delta * y[nY];                                                                                          /* nY */

dydt[nR] = Table->Gamma_2 * (y[nA] + y[nI2] + y[nY]) ;                                                                                                                     /* nR */

dydt[aI] = Table->p_0 * Table->Gamma_1 * y[nI1];                                                                                                                          /* aI */

dydt[aR] = Table->Gamma_2 * (y[nI2] + y[nY]);                                                                                                                              /* aR */

dydt[aD] = Table->Delta * y[nY];                                                                                                                                           /* aD */

/* S: Students (6-25) */
  
/* A: Adults (26-65) */
  
/* V: Adults (65-100) */
  
