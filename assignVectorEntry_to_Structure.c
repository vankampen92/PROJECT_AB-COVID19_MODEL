#include <MODEL.h>

void Vector_Entries_into_Parameter_Table ( const gsl_vector * X, Parameter_Table * P,
					   int * Parameter_Index, int No_of_PARAMETERS )
{
  int i;
  int key;
  double value;

  for( i=0; i<No_of_PARAMETERS; i++) {
    key = Parameter_Index[i];
    value = gsl_vector_get(X, i);
    AssignVectorEntry_to_Structure( P, key, value );
  }
}

void Vector_Entries_into_Parameter_Table_Initial_Condition ( const gsl_vector * X,
							     Parameter_Table * P,
							     int * Index,
							     int No_of_PARAMETERS,
							     int No_of_IC)
{
  int i;
  int key;
  double value;

  for( i=0; i<No_of_IC; i++) {
    key = Index[i];
    value = gsl_vector_get(X, i+No_of_PARAMETERS);
    Vector_Entry_into_Model_Variable_Initial_Condition_Table( value, key, P );
  }
}

void AssignVectorEntry_to_Structure(Parameter_Table * P, int j, double value)
{

  switch(j)
    {
    
    case  0:  P->Kappa = value;      
      break;
    case  1:  P->Imm = value;    /* Total Immigration Ratge */                             /*  1 */
      break;
    case  2:  P->Beta = value;   /* Contact rate: Total no of contacts an individual has per day   *//*  2 */
      break;
    case  3:  P->b = value;      /* Infectivity  */                                        /*  3 */
      break;
    case  4:  P->Phi = value;    /* Pre-symptomatic Infectivity Factor */                  /*  4 */
      break;
    case  5:  P->Eps_I = value; /* Isolation effectiveness of strong cases */            /*  5 */
      break;
    case  6:  P->Eps_Y = value;  /* Isolation effectiveness of serious cases */            /*  6 */
      break;
    case  7:  P->Sigma = value;  /* Rate of the appearance of infectious capacity */       /*  7 */
      break;
    case  8:  P->Gamma_1 = value; /* Rate of the appearance of symptoms  */                /*  8 */
      break; 
    case  9:  P->p_0 = value;    /* Probability of the appearance of strong symptoms */   /*  9 */
      break;
    case 10:  P->Alpha = value;   /* (Age-dependent) Rate of appearence of serious symptoms */           /* 10 */
      break;
    case 11:  P->Delta = value;   /* (Age-dependent) Disease-Induced Mortality Rate */                   /* 11 */
      break;
    case 12:  P->Gamma_2 = value; /* Rate of Recovery */                                  /* 12 */
      break;

    case 13:  P->Beta_00 = value;
      break;
    case 14:  P->Beta_01 = value;
      break;
    case 15:  P->Beta_02 = value;
      break;
    case 16:  P->Beta_03 = value;
      break;

    case 17:  P->Beta_10 = value;
      break;
    case 18:  P->Beta_11 = value;
      break;
    case 19:  P->Beta_12 = value;
      break;
    case 20:  P->Beta_13 = value;
      break;

    case 21:  P->Beta_20 = value;
      break;
    case 22:  P->Beta_21 = value;
      break;
    case 23:  P->Beta_22 = value;
      break;
    case 24:  P->Beta_23 = value;
      break;

    case 25:  P->Beta_30 = value;
      break;
    case 26:  P->Beta_31 = value;
      break;
    case 27:  P->Beta_32 = value;
      break;
    case 28:  P->Beta_33 = value;
      break;

    case 29:  P->Alpha_0 = value;
      break;  
    case 30:  P->Alpha_1 = value;
      break;
    case 31:  P->Alpha_2 = value;
      break;
    case 32:  P->Alpha_3 = value;
      break;

    case 33:  P->Delta_0 = value;
      break;
    case 34:  P->Delta_1 = value;
      break;
    case 35:  P->Delta_2 = value;
      break;
    case 36:  P->Delta_3 = value;
      break;

    case 37:  P->p_1 = value;
      break;
    case 38:  P->p_2 = value;
      break;
    case 39:  P->p_3 = value;
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
}
