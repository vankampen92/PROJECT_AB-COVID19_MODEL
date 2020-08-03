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
  int x, n_Event;
  Community * pVil;
  Parameter_Model * P = Table->P;
  
  /// M_O_D_E_L___V_A_R_I_A_B_L_E_S___C_O_D_E ( Table );
  int S, I, C;
  int X, W, K;
  S = Table->S; I = Table->I;
  X = Table->X; W = Table->W; 
  C = Table->C; K = Table->K;

  int * J    = Table->Vector_Model_Int_Variables;
  double * Y = Table->Vector_Model_Variables;
  /* Hierarchic procedure to find the even to occur... */  
  /* The event occurs within the villages... */
  if(P->No_of_PATCHES == 1) x = 0;
  else                      x = Choose_Village(max_Probability, SP, P);
  
  pVil = SP[x];  /* x represents the chosen patch undegoing a change. */    

  int no_TOTAL_EVENTS = Table->No_of_EVENTS;

  n_Event = Discrete_Sampling(pVil->rToI, no_TOTAL_EVENTS) - 1; 

  switch(n_Event)
    {
    case  0: /* 0: Death (S --> S-1) */ 
      Y[S]--; J[S]--; pVil->n[S]--; pVil->H_POPULATION--;
      break;
    case  1: /* 1: Birth (S --> S+1) */ 
      Y[S]++; J[S]++; pVil->n[S]++; pVil->H_POPULATION++; 
      break;
    case  2: /* 2: Death (I --> I-1) */ 
      Y[I]--; J[I]--; pVil->n[I]--; pVil->H_POPULATION--;       
      break;
    case  3: /* 3: Infection (S --> S-1 and I --> I+1) */ 
      Y[S]--; J[S]--; pVil->n[S]--;
      Y[I]++; J[I]++; pVil->n[I]++;  
      break;
    case  4: /* 4: Recovery (S --> S+1  and I --> I-1) */ 
      Y[S]++; J[S]++; pVil->n[S]++;
      Y[I]--; J[I]--; pVil->n[I]--;  
      break;
    case  5: /* 5: Mosquito Infection (X --> X-1 and W ---> W+1) */ 
      Y[X]--; J[X]--; pVil->n[X]--;
      Y[W]++; J[W]++; pVil->n[W]++;  
      break; 
    case  6: /* 6: Mosquito Birth (X --> X+1) */ 
      Y[X]++; J[X]++; pVil->n[X]++; pVil->M_POPULATION++; 
      break;
    case  7: /* 7: Mosquito Death (X --> X-1) */ 
      Y[X]--; J[X]--; pVil->n[X]--; pVil->M_POPULATION--; 
      break;
    case  8: /* 8: Mosquito Death (W --> W-1) */  
      Y[W]--; J[W]--; pVil->n[W]--; pVil->M_POPULATION--; 
      break;
  
    default:
    /* Something is very very wrong!!! */
      printf("The number of event occurring should be between 0 and 8\n");
      printf("Event to Occur = %d\n", n_Event);
      Press_Key();
    }  

  /* Tracking total population of human and mosquitoes */
  if(P->No_of_PATCHES == 1) {
    Table->M_POPULATION = pVil->M_POPULATION;
    P->M_POPULATION     = pVil->M_POPULATION;

    Table->H_POPULATION = pVil->H_POPULATION;
    P->H_POPULATION     = pVil->H_POPULATION;
  }
  // else /*Under Construction */
  
  (*Event) = n_Event;  (*Patch) = x;
}


