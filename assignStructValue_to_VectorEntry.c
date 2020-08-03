#include <MODEL.h>

void Parameter_Table_into_Vector_Entries ( Parameter_Table * P, gsl_vector * X,
					   int * Parameter_Index, int No_of_PARAMETERS )
{
  int i;
  int key;
  double value;

  for( i=0; i<No_of_PARAMETERS; i++) {
    key = Parameter_Index[i];
    value = AssignStructValue_to_VectorEntry( key, P );
    gsl_vector_set(X, i, value);
  }
}

void Parameter_Table_into_Vector_Entries_Initial_Condition ( Parameter_Table * P, gsl_vector * X,
							     int * Index,
							     int No_of_PARAMETERS,
							     int No_of_IC)
{
  int i;
  int key;
  double value;

  for( i=0; i<No_of_IC; i++) {
    key = Index[i];
    value = Model_Variable_Initial_Condition_into_Vector_Entry_Table( key, P );
    gsl_vector_set(X, i+No_of_PARAMETERS, value);
  }
}

double AssignStructValue_to_VectorEntry(int j, Parameter_Table * P)
{
  double value;

  switch(j)
    {
    case  0: value = P->Kappa;      /* Total (Initial) Population */                          /*  0 */
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

    case 37: value = P->p_1;   /* (Age-dependent) Disease-Induced Mortality Rate */                   /* 11 */
      break;
    case 38: value = P->p_2; /* Rate of Recovery */                                  /* 12 */
      break;
    case 39: value = P->p_3; /* Rate of Recovery */                                  /* 12 */
      break;

      
    default:
      printf(".... INVALID PARAMETER KEY (key = %d)\n", j);

      printf(".... The permited correspondences are:\n");
      printf("\n");
      fprintf_Model_Parameters(stdout, P);

      printf(" The maximum number of parameters is Number_PAR_MAX\n");
      printf(" The permited number of keys go from 0, to %d\n", MODEL_PARAMETERS_MAXIMUM-1);

      exit(0);
    }

  return(value);
}
