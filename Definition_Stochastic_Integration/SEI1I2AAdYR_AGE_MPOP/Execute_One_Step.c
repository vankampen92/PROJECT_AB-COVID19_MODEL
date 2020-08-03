/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                           */
/*                             David Alonso, 2010 (c)                        */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <MODEL.h>

extern gsl_rng * r;   /* Global generator (define at the main program level */
#define RANDOM gsl_rng_uniform_pos(r)

void Execute_One_Step(Community ** SP,
		      Parameter_Table * Table,
		      double max_Probability, 
		      int * Event, int * Patch) 
{
  int x, n_Event, k;
  Community * Patch;
  Parameter_Model * P = Table->P;
  
  Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; /* Ex: 11 times 4 */

   /* Definition of the state vector numerical order, from 0 to K, of model variables */
  #include <Model_Variables_Code.Include.c>
  
  int    * J = Table->Vector_Model_Int_Variables;
  double * Y = Table->Vector_Model_Variables;

  /* Hierarchic procedure to find the even to occur... */  
  /* The event occurs in one of the local populations  */
  if(P->No_of_LOCAL_POPULATIONS == 1) x = 0;
  else                                x = Choose_Village(max_Probability, SP, P);
  
  Patch = SP[x];  /* x represents the chosen patch undegoing a change. */    

  n_Event = Discrete_Sampling(pVil->rToI, no_TOTAL_EVENTS) - 1; /* 0, ..., 99 */ 
  
  n_Event_within_Age_Class = n_Event%Table->No_of_EVENTS;    /* 0, ..., 24 */ 
  n                        = n_Event/Table->No_of_EVENTS;    /* 0, ..., 3  */ 
  
  nS =  n0S  + n*Table->TOTAL_No_of_DISEASE_STAGES;   jS = nS + x*Q;
  nE =  n0E  + n*Table->TOTAL_No_of_DISEASE_STAGES;   jE = nE + x*Q;
  nI1=  n0I1 + n*Table->TOTAL_No_of_DISEASE_STAGES;  jI1 = nI1 + x*Q;
  nI2=  n0A  + n*Table->TOTAL_No_of_DISEASE_STAGES;  jI2 = nI2 + x*Q;
  nA =  n0A  + n*Table->TOTAL_No_of_DISEASE_STAGES;   jA = nA + x*Q;
  nAd=  n0Ad + n*Table->TOTAL_No_of_DISEASE_STAGES;  jAd = nAd + x*Q;
  nY =  n0Y  + n*Table->TOTAL_No_of_DISEASE_STAGES;   jY = nY + x*Q;
  nR =  n0R  + n*Table->TOTAL_No_of_DISEASE_STAGES;   jR = nR + x*Q;
  aI =  a0I  + n*Table->TOTAL_No_of_DISEASE_STAGES;  jaI = aI + x*Q;
  aR =  a0R  + n*Table->TOTAL_No_of_DISEASE_STAGES;  jaR = aR + x*Q;
  aD =  a0D  + n*Table->TOTAL_No_of_DISEASE_STAGES;  jaD = aD + x*Q;

  switch( n_Event_with_Age_Class )
    {
    case  0:  /* (Age n): Infection (S --> S-1 and E --> E + 1) */                               /* 1 */
      Y[jS]--; J[jS]--;  Patch->n[nS]--;
      Y[jE]++; J[jE]++;  Patch->n[nE]++;
      
      break;
    case  1:  /* (Age n): Out-Migration (S --> S-1) and some other patch gains one */ 
      Y[jS]--; J[jS]--;  Patch->n[nS]--;
      Local_Population_Decrease(n,  Patch);
      
      
      break;
    case  2:  /* 2 (Age n): In-Migration (S --> S+1) and some other patch loses one */ 
      Y[jS]++; J[jS]++;  Patch->n[nS]++;
      Local_Population_Increase(n,  Patch);
      
      break;

      
    case  3:  /* 3 (Age n):  Exposed into Infectious (E --> E-1 and I1 --> I1 + 1)*/             /* 2 */
      Y[jE]--;  J[jE]--;   Patch->n[nE]--;
      Y[jI1]++; J[jI1]++;  Patch->n[nI1]++;
      
      break;
    case  4:  /* 4 (Age n): Out-Migration (E --> E-1) and some other patch gains one */ 
      Y[jE]--; J[jE]--;  Patch->n[nE]--;
      Local_Population_Decrease(n,  Patch);
      
      break;
    case  5:  /* 5 (Age n): In-Migration (E --> E+1) and some other patch loses one */ 
       
      break;

      
    case  6:  /* 6 (Age n): Pre-Symptomatic into Infectious (I1 --> I1-1 and I2 --> I2 + 1) */   /* 3 */
              /*                                                         and AI --> AI + 1  */   
      Y[jI1]--; J[jI1]--;  Patch->n[nI1]--;
      Y[jI2]++; J[jI2]++;  Patch->n[nI2]++;
      Y[jaI]++; J[jaI]++;  Patch->n[aI]++; 

      break;
    case  7:  /* 7 (Age n): Pre-Symptomatic into A-symptomatic (I1 --> I1-1 and A --> A+1) */    /* 4 */
      Y[jI1]--; J[jI1]--;  Patch->n[nI1]--;
      Y[jA]--;  J[jA]--;   Patch->n[nA]--;

      break;
    case  8:  /* 8 (Age n): Out-Migration (I1 --> I1-1) and some other patch gains one */ 
      Y[jI1]--; J[jI1]--;  Patch->n[nI1]--;
      Local_Population_Decrease(n,  Patch);
      
      break;
    case  9:  /* 9 (Age n): In-Migration (I1 --> I1+1) and some other patch loses one */ 
      Y[jI1]++; J[jI1]++;  Patch->n[nI1]++;
      Local_Population_Increase(n,  Patch);
      
      break;

      
    case  10: /* 10 (Age n): Infectious I2 into Recovered (I2 -> I2-1 and R --> R + 1) */        /* 5 */
              /*                                                    and AR --> AR + 1  */     
      Y[jI2]--; J[jI2]--;  Patch->n[nI2]--;
      Y[jR]++;  J[jR]++;   Patch->n[nR]++;
      Y[jaR]++; J[jaR]++;  Patch->n[aR]++;
      
      break;
    case  11: /* 11 (Age n): Infectious I2 into severe symptoms ( I2 -> I2-1 and Y --> Y + 1) */ /* 6 */
      Y[jI2]--; J[jI2]--;  Patch->n[nI2]--;
      Y[jY]++;  J[jY]++;   Patch->n[nY]++;
      
      break;
    case  12: /* 12 (Age n): Out-Migration (I2 --> I2-1) and some other patch gains one */ 
      Y[jI2]--; J[jI2]--;  Patch->n[nI2]--;
      Local_Population_Decrease(n,  Patch);
      
      break;
    case  13: /* 13 (Age n): In-Migration (I2 --> I2 + 1) and some other patch loses one */ 
      Y[jI2]++; J[jI2]++;  Patch->n[nI2]++;
      Local_Population_Increase(n,  Patch);
      
      
      break;

      
    case  14:  /* 14 (Age n): Assymptomatic into Recovered (A -> A-1 and R --> R + 1)    */
               /* We don't consider accumulating these recovered (AR --> AR + 1)        
		  because they have not been detected by the system                      */      /* 7 */
      Y[jA]--; J[jA]--;  Patch->n[nA]--;
      Y[jR]++; J[jR]++;  Patch->n[nR]++;
       
      break; 
    case  15:  /* 15 (Age n): Assymptomatic are detected   (A -> A-1 and Ad --> Ad + 1)  */      /* 8 */
               /*                                                    and AI --> AI + 1   */
      Y[jA]--;  J[jA]--;   Patch->n[nA]--;
      Y[jAd]++; J[jAd]++;  Patch->n[nAd]++;
      Y[jaI]++; J[jaI]++;  Patch->n[naI]++;
      
      break;
    case  16:  /* 16 (Age n): Out-Migration (A --> A-1) and some other patch gains one */ 
      Y[jA]--; J[jA]--;  Patch->n[nA]--;
      Local_Population_Decrease(n,  Patch);
      
      break;
    case  17:  /* 17 (Age n): In-Migration (A --> A +1) and some other patch loses one */ 
      Y[jA]++; J[jA]++;  Patch->n[nA]++;
      Local_Population_Increase(n,  Patch);
      
      
      break;
      
      
    case 18:  /* 18 (Age n): Detected Assymtomatic are recovered (Ad -> Ad-1 and R --> R + 1) */ /* 9 */
              /*                                                            and AR --> AR + 1 */
      Y[jAd]--; J[jAd]--;  Patch->n[nAd]--;
      Y[jR]++;  J[jR]++;   Patch->n[nR]++;
      Y[jaR]++; J[jaR]++;  Patch->n[aR]++;
      
      break;
    case  19:  /* 19 (Age n): Out-Migration (Ad --> Ad-1) and some other patch gains one */ 
      Y[jAd]--; J[jAd]--;  Patch->n[nAd]--;
      Local_Population_Decrease(n,  Patch);
      
      break;
    case  20:  /* 20 (Age n): In-Migration (Ad --> Ad +1) and some other patch loses one */ 
      Y[jAd]++; J[jAd]++;  Patch->n[nAd]++;
      Local_Population_Increase(n,  Patch);
      
      break;

      
    case  21:  /* 21 (Age n): Severe Infecious recover (Y --> Y-1 and R --> R + 1)    */        /* 10 */
               /*                                                 and AR --> AR + 1   */
               /*           : Severe Infectious don't move!!!                         */
      Y[jY]--;  J[jY]--;   Patch->n[nY]--;
      Y[jR]++;  J[jR]++;   Patch->n[nR]++;
      Y[jaR]++; J[jaR]++;  Patch->n[aR]++;
        
      break;
    case  22:  /* 22 (Age n): Severe Infecious die (Y --> Y-1 and D --> D + 1 */                /* 11 */
      Y[jY]--;  J[jY]--;   Patch->n[nY]--;
      Y[jaD]++; J[jaD]++;  Patch->n[aD]++;  
               
      break;

      
    case  23:  /* 23 (Age n): Recovered move (R --> R-1 and some other patch gains one) */
      Y[jR]--; J[jR]--;  Patch->n[nR]--;
      Local_Population_Decrease(n,  Patch);
      
      break; 
    case  24:  /* 24 (Age n): In-Migration (R --> R + 1) and some other patch loses one */ 
      Y[jR]++; J[jR]++;  Patch->n[nR]++;
      Local_Population_Increase(n,  Patch);
      
      break;
    
    default:
    /* Something is very very wrong!!! */
      printf("The number of event occurring should be between 0 and 24\n");
      printf("Event to Occur = %d\n", n_Event);
      Press_Key();
      exit(0); 
    }  

  
  (*Event) = n_Event;  (*Patch) = x;
}


