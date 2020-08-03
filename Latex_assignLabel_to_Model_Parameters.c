#include "./Include/MODEL.h"

void AssignLabel_to_Model_Parameters__LATEX(int j, char * Label, Parameter_Table *P)
{
  char * p;
  Label[0] = '\0';

  switch(j)
    {
    case  0:  p = strcat(Label , "Detectability rate"); /*  0 */
      break;
    case  1:  p = strcat(Label , "Immmigration rate"); /*  1 */
      break;
    case  2:  p = strcat(Label , "Contact rate"); /*  2 */
      break;
    case  3:  p = strcat(Label , "Infectivity"); /*  3 */
      break;
    case  4:  p = strcat(Label , "Pre-symptomatic infectivity factor"); /*  4 */
      break;
    case  5:  p = strcat(Label , "Isolation effectiveness of strong cases"); /*  5 */
      break;
    case  6:  p = strcat(Label , "Isolation effectiveness of serious cases"); /*  6 */
      break;
    case  7:  p = strcat(Label , "Rate of the appearance of infectious capaciy"); /*  7 */
      break;
    case  8:  p = strcat(Label , "Rate of the appearance of symptoms"); /*  8 */
      break;
    case  9:  p = strcat(Label , "Age-dependent probability of the appearance of strong symptoms ($p_0$)"); /*  9 */
      break;
    case 10:  p = strcat(Label , "Rate of appearence of serious symptoms"); /*  10 */
      break;
    case 11:  p = strcat(Label , "Disease-induced mortality"); /* 11 */
      break;
    case 12:  p = strcat(Label , "Rate of recovery"); /* 12 */
      break;

    case 13:  p = strcat(Label , "Contact Matrix Element [00]");            /* 00 */
      break;
    case 14:  p = strcat(Label , "Contact Matrix Element [01]");            /* 01 */
      break;
    case 15:  p = strcat(Label , "Contact Matrix Element [02]");            /* 02 */
      break;
    case 16:  p = strcat(Label , "Contact Matrix Element [03]");            /* 03 */
      break;
    case 17:  p = strcat(Label , "Contact Matrix Element [10]");            /* 10 */
      break;
    case 18:  p = strcat(Label , "Contact Matrix Element [11]");            /* 11 */
      break;
    case 19:  p = strcat(Label , "Contact Matrix Element [12]");            /* 12 */
      break;
    case 20:  p = strcat(Label , "Contact Matrix Element [13]");            /* 13 */
      break;
    case 21:  p = strcat(Label , "Contact Matrix Element [20]");            /* 20 */
      break;
    case 22:  p = strcat(Label , "Contact Matrix Element [21]");            /* 21 */
      break;
    case 23:  p = strcat(Label , "Contact Matrix Element [22]");            /* 22 */
      break;
    case 24:  p = strcat(Label , "Contact Matrix Element [23]");            /* 23 */
      break;
    case 25:  p = strcat(Label , "Contact Matrix Element [30]");            /* 30 */
      break;
    case 26:  p = strcat(Label , "Contact Matrix Element [31]");            /* 31 */
      break;
    case 27:  p = strcat(Label , "Contact Matrix Element [32]");            /* 32 */
      break;
    case 28:  p = strcat(Label , "Contact Matrix Element [33]");            /* 33 */
      break;

    case 29:  p = strcat(Label , "Age-dependent Alpha Rate [0]");        
      break;
    case 30:  p = strcat(Label , "Age-dependent Alpha Rate [1]");        
      break;
    case 31:  p = strcat(Label , "Age-dependent Alpha Rate [2]");        
      break;
    case 32:  p = strcat(Label , "Age-dependent Alpha Rate [3]");        
      break;

    case 33:  p = strcat(Label , "Age-dependent disease-induced mortality [0]"); 
      break;
    case 34:  p = strcat(Label , "Age-dependent disease-induced mortality [1]"); 
      break;
    case 35:  p = strcat(Label , "Age-dependent disease-induced mortality [2]"); 
      break;
    case 36:  p = strcat(Label , "Age-dependent disease-induced mortality [3]"); 
      break; 

    case 37:  p = strcat(Label , "Age-dependent probability of the appearance of strong symptoms ($p_1$)"); 
      break;
    case 38:  p = strcat(Label , "Age-dependent probability of the appearance of strong symptoms ($p_2$)"); 
      break;
    case 39:  p = strcat(Label , "Age-dependent probability of the appearance of strong symptoms ($p_3$)"); 
      break; 
      
   default:
      printf(".... INVALID PARAMETER KEY [key = %d]\n", j);
      printf(".... The permited correspondences are:\n");
      printf("\n");
      fprintf_Model_Parameters(stdout, P);
      exit(0);
    }
}

void AssignLabel_to_Model_Parameters__LATEX__SYMBOL(int j, char * Label, Parameter_Table *P)
{
  char * p;
  Label[0] = '\0';

  switch(j)
    {
    case  0: p = strcat(Label, "$\\kappa$");     /* Detectability Rate   *//*  0 */   /*\\gb\\dY\\u"); */
      break;
    case  1: p = strcat(Label, "$\\mu$");        /* Total Immigration Rate *//*  1 */
      break;
    case  2: p = strcat(Label, "$\\beta$");      /* Contact rate: Total no of contacts an individual has per day  *//*  2 */
      break;
    case  3:  p = strcat(Label, "$b$");          /* Infectivity       *//*  3 */
      break;
    case  4: p = strcat(Label, "$\\phi$");       /* Pre-symptomatic Infectivity Factor  *//*  4 */
      break;
    case  5: p = strcat(Label, "$\\epsilon_I$"); /* Isolation effectiveness of strong cases    *//*  5 */
      break;
    case  6: p = strcat(Label, "$\\epsilon_Y$"); /* Isolation effectiveness of serious cases   *//*  6 */
      break;
    case  7: p = strcat(Label, "$\\sigma$");     /* Rate of the appearance of infectious capacity *//*  7 */
      break;
    case  8: p = strcat(Label, "$\\gamma_1$");   /* Rate of the appearance of symptoms   *//*  8 */
      break;
    case  9: p = strcat(Label, "$p_0$");         /* Probability of the appearance of strong symptoms  *//*  9 */
      break;
    case 10: p = strcat(Label, "$\\alpha$");     /*  (Age-dependent) Rate of appearence of serious symptoms *//* 10 */
      break;
    case 11: p = strcat(Label, "$\\delta$");     /* (Age-dependent) Disease-Induced Mortality Rate   *//* 11 */
      break;
    case 12: p = strcat(Label, "$\\gamma_2$");   /*  Rate of Recovery *//* 12 */
      break;

    case 13: p=strcat(Label,"$\\beta_{00}$");     /* Total Immigration Ratge *//*  1 */
      break;
    case 14: p=strcat(Label,"$\\beta_{01}$");     /* Contact rate: Total no of contacts an individual has per day  *//*  2 */
      break;
    case 15: p=strcat(Label,"$\\beta_{02}$");       /* Infectivity       *//*  3 */
      break; 
    case 16: p=strcat(Label,"$\\beta_{03}$");    /* Pre-symptomatic Infectivity Factor  *//*  4 */
      break;

    case 17: p=strcat(Label,"$\\beta_{10}$");    /* Isolation effectiveness of strong cases    *//*  5 */
      break;
    case 18: p=strcat(Label,"$\\beta_{11}$");    /* Isolation effectiveness of serious cases   *//*  6 */
      break;
    case 19: p=strcat(Label,"$\\beta_{12}$");    /* Isolation effectiveness of serious cases   *//*  6 */
      break;
    case 20: p=strcat(Label,"$\\beta_{13}$");  /*  (Age-dependent) Rate of appearence of serious symptoms *//* 10 */
      break;

    case 21: p=strcat(Label,"$\\beta_{20}$");/* (Age-dependent) Disease-Induced Mortality Rate   *//* 11 */
      break;
    case 22: p=strcat(Label,"$\\beta_{21}$");      /*  Rate of Recovery *//* 12 */
      break;
    case 23: p=strcat(Label,"$\\beta_{22}$");     /* Total Immigration Ratge *//*  1 */
      break;
    case 24: p=strcat(Label,"$\\beta_{23}$");     /* Contact rate: Total no of contacts an individual has per day  *//*  2 */
      break;

    case 25: p=strcat(Label,"$\\beta_{30}$");       /* Infectivity       *//*  3 */
      break; 
    case 26: p=strcat(Label,"$\\beta_{31}$");    /* Pre-symptomatic Infectivity Factor  *//*  4 */
      break;
    case 27: p=strcat(Label,"$\\beta_{32}$");    /* Isolation effectiveness of strong cases    *//*  5 */
      break;
    case 28: p=strcat(Label,"$\\beta_{33}$");    /* Isolation effectiveness of serious cases   *//*  6 */
      break;

    case 29: p=strcat(Label,"$\\alpha_0$");    /* Isolation effectiveness of serious cases   *//*  6 */
      break;
    case 30: p=strcat(Label,"$\\alpha_1$");  /*  (Age-dependent) Rate of appearence of serious symptoms *//* 10 */
      break;
    case 31: p=strcat(Label,"$\\alpha_2$");/* (Age-dependent) Disease-Induced Mortality Rate   *//* 11 */
      break;
    case 32: p=strcat(Label,"$\\alpha_3$");      /*  Rate of Recovery *//* 12 */
      break;

    case 33: p=strcat(Label,"$\\delta_0$");     /* Total Immigration Ratge *//*  1 */
      break;
    case 34: p=strcat(Label,"$\\delta_1$");     /* Contact rate: Total no of contacts an individual has per day  *//*  2 */
      break;
    case 35: p=strcat(Label,"$\\delta_2$");       /* Infectivity       *//*  3 */
      break; 
    case 36: p=strcat(Label,"$\\delta_3$");    /* Pre-symptomatic Infectivity Factor  *//*  4 */
      break;

    case 37: p=strcat(Label,"$p_1$");  /* Probability of the appearance of strong symptoms *//* 9 */
      break;
    case 38: p=strcat(Label,"$p_2$");  /* Probability of the appearance of strong symptoms *//* 9 */ 
      break; 
    case 39: p=strcat(Label,"$p_3$");  /* Probability of the appearance of strong symptoms *//* 9 */ 
      break;
    
    default:
      printf(".... INVALID PARAMETER KEY [key = %d]\n", j);
      printf(".... The permited correspondences are:\n");
      printf("\n");
      fprintf_Model_Parameters(stdout, P);
      exit(0);
    }
}
