#include <MODEL.h>

void AssignLabel_to_Output_Variables(int j, char * Label, Parameter_Table * P)
{
  char * p;
  Label[0] = '\0';
  if (j >= OUTPUT_VARIABLES_GENUINE) {
    j -= OUTPUT_VARIABLES_GENUINE;
    /* The first output variables are the model variables */
    AssignLabel_to_Model_Variables(j, Label, P);
  }
  else {       /* SEI1I2AYR fraction and more  */
    switch(j)
      {
      case  0:  p = strcat(Label , "S (Fraction)");         /*  0: S */
        break;
      case  1:  p = strcat(Label , "E (Fraction)");             /*  1: E */
        break;
      case  2:  p = strcat(Label , "I_1 (Fraction)");      /*  2: I1 */
        break;
      case  3:  p = strcat(Label , "I_2 (Fraction)");   /*  3: I2 */
        break;
      case  4:  p = strcat(Label , "A (Fraction)");       /*  4: A */
        break;
      case  5:  p = strcat(Label , "Y (Fraction)");  /*  5: Y */
        break;
      case  6:  p = strcat(Label , "R (Fraction)");  /*  6: R */
        break;
      case  7:  p = strcat(Label , "Prevalence");      /*  7: Disease Prevalence (E+I1+I2+Y+A)/N */
        break;
      case  8:  p = strcat(Label , "I_D (Accumulated)");  /*  8: Total Infected Number (detected)  */
        break;
      case  9:  p = strcat(Label , "R_D (Accumulated)");   /* 9: Total Recovered Number (detected) */
        break;
      case 10:  p = strcat(Label , "M_D (Accumulated)");  /* 10: Detected Mortality */
        break;
      case 11:  p = strcat(Label , "I (Number)");      /* 11; (E+I1+I2+Y+A) */
        break;
      case 12:  p = strcat(Label , "I_D (Detected)");   /* 12 */
        break;
      case 13:  p = strcat(Label , "Total Population");   /* 13 */
        break;

      default:
        printf(".... INVALID OUTPUT VARIABLE KEY [key = %d]\n", j);
        printf(".... The permited correspondences are:\n");
        printf(".... from 0 to 18\n");
        exit(0);
      }
  }
}

void AssignLongLabel_to_Output_Variables(int j, char * Label, Parameter_Table * P)
{
  char * p;
  Label[0] = '\0';
  if (j >= OUTPUT_VARIABLES_GENUINE) {
    j -= OUTPUT_VARIABLES_GENUINE;
    /* The first output variables are the model variables */
    AssignLabel_to_Model_Variables(j, Label, P);
  }
  else {       /* SEI1I2AYR fraction and more  */
    switch(j)
      {
      case  0:  p = strcat(Label , "Fraction of Susceptible Population");         /*  0: S */
        break;
      case  1:  p = strcat(Label , "Fraction of Exposed Population");             /*  1: E */
        break;
      case  2:  p = strcat(Label , "Fraction of Pre-symptomatic Population");     /*  2: I1 */
        break;
      case  3:  p = strcat(Label , "Fraction of Strongly-Infected Population");   /*  3: I2 */
        break;
      case  4:  p = strcat(Label , "Fraction of A-symptomatic Population");       /*  4: A */
        break;
      case  5:  p = strcat(Label , "Fraction of Seriously-Infected Population");  /*  5: Y */
        break;
      case  6:  p = strcat(Label , "Fraction of Recovered");                      /*  6: R */
        break;
      case  7:  p = strcat(Label , "Fraction of Total Infected Population");      /*  7: Disease Prevalence (E+I1+I2+Y+A)/N */
        break;
      case  8:  p = strcat(Label , "Accumulated Number of Detected Infections");  /*  8 */
        break;
      case  9:  p = strcat(Label , "Accoumlated Number of Detected Recoveries");  /*  9 */
        break;
      case 10:  p = strcat(Label , "Accumulated Number of Deaths from Severe Disease"); /* 10  */
        break;
      case 11:  p = strcat(Label , "Total Infected Population");      /* 11; (E+I1+I2+Y+A) */
        break;
      case 12:  p = strcat(Label , "Total Detected Infected Population");   /* 12 */
        break;
      case 13:  p = strcat(Label , "Total (remaining) Population");   /* 13 */
        break;

      default:
        printf(".... INVALID OUTPUT VARIABLE KEY [key = %d]\n", j);
        printf(".... The permited correspondences are:\n");
        printf(".... from 0 to 18\n");
        exit(0);
      }
  }
}


