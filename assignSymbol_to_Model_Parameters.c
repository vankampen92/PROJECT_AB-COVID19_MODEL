#include "./Include/MODEL.h"

void AssignCPGPLOT_Symbol_to_Model_Parameters(int j, char * Label, Parameter_Table *P)
{
  /* Short Labels for Model Parameters */

  char * p;
  Label[0] = '\0';

  switch(j)
    {
    case  0: p=strcat(Label,"\\gk");       /* Total (Initial) Population   *//*  0 */   /*\\gb\\dY\\u"); */
      break;
    case  1: p=strcat(Label,"\\gm");    /* Total Immigration Rate *//*  1 */
      break;
    case  2: p=strcat(Label,"\\gb");    /* Contact rate: Total no of contacts an individual has per day  *//*  2 */
      break;
    case  3: p=strcat(Label,"b");       /* Infectivity       *//*  3 */
      break; 
    case  4: p=strcat(Label,"\\gf");    /* Pre-symptomatic Infectivity Factor  *//*  4 */
      break;
    case  5: p=strcat(Label,"\\ge\\dI\\u");    /* Isolation effectiveness of strong cases    *//*  5 */
      break;
    case  6: p=strcat(Label,"\\ge\\dY\\u");    /* Isolation effectiveness of serious cases   *//*  6 */
      break;
    case  7: p=strcat(Label,"\\gs");           /* Rate of the appearance of infectious capacity *//*  7 */
      break;
    case  8: p=strcat(Label,"\\gg\\d1\\u");    /* Rate of the appearance of symptoms   *//*  8 */
      break;
    case  9: p=strcat(Label,"p\\d0\\u");       /* Probability of the appearance of strong symptoms  *//*  9 */
      break;
    case 10: p=strcat(Label,"\\ga");  /*  (Age-dependent) Rate of appearence of serious symptoms *//* 10 */
      break;
    case 11: p=strcat(Label,"\\gd");  /* (Age-dependent) Disease-Induced Mortality Rate   *//* 11 */
      break;
    case 12: p=strcat(Label,"\\g\\d2\\u");      /*  Rate of Recovery *//* 12 */
      break;

    case 13: p=strcat(Label,"\\gb\\d00\\u");     /* Total Immigration Ratge *//*  1 */
      break;
    case 14: p=strcat(Label,"\\gb\\d01\\u");     /* Contact rate: Total no of contacts an individual has per day  *//*  2 */
      break;
    case 15: p=strcat(Label,"\\gb\\d02\\u");       /* Infectivity       *//*  3 */
      break; 
    case 16: p=strcat(Label,"\\gb\\d03\\u");    /* Pre-symptomatic Infectivity Factor  *//*  4 */
      break;

    case 17: p=strcat(Label,"\\gb\\d10\\u");    /* Isolation effectiveness of strong cases    *//*  5 */
      break;
    case 18: p=strcat(Label,"\\gb\\d11\\u");    /* Isolation effectiveness of serious cases   *//*  6 */
      break;
    case 19: p=strcat(Label,"\\gb\\d12\\u");    /* Isolation effectiveness of serious cases   *//*  6 */
      break;
    case 20: p=strcat(Label,"\\gb\\d13\\u");  /*  (Age-dependent) Rate of appearence of serious symptoms *//* 10 */
      break;

    case 21: p=strcat(Label,"\\gb\\d20\\u");/* (Age-dependent) Disease-Induced Mortality Rate   *//* 11 */
      break;
    case 22: p=strcat(Label,"\\gb\\d21\\u");      /*  Rate of Recovery *//* 12 */
      break;
    case 23: p=strcat(Label,"\\gb\\d22\\u");     /* Total Immigration Ratge *//*  1 */
      break;
    case 24: p=strcat(Label,"\\gb\\d23\\u");     /* Contact rate: Total no of contacts an individual has per day  *//*  2 */
      break;

    case 25: p=strcat(Label,"\\gb\\d30\\u");       /* Infectivity       *//*  3 */
      break; 
    case 26: p=strcat(Label,"\\gb\\d31\\u");    /* Pre-symptomatic Infectivity Factor  *//*  4 */
      break;
    case 27: p=strcat(Label,"\\gb\\d32\\u");    /* Isolation effectiveness of strong cases    *//*  5 */
      break;
    case 28: p=strcat(Label,"\\gb\\d33\\u");    /* Isolation effectiveness of serious cases   *//*  6 */
      break;

    case 29: p=strcat(Label,"\\ga\\d0\\u");    /* Isolation effectiveness of serious cases   *//*  6 */
      break;
    case 30: p=strcat(Label,"\\ga\\d1\\u");  /*  (Age-dependent) Rate of appearence of serious symptoms *//* 10 */
      break;
    case 31: p=strcat(Label,"\\ga\\d2\\u");/* (Age-dependent) Disease-Induced Mortality Rate   *//* 11 */
      break;
    case 32: p=strcat(Label,"\\ga\\d3\\u");      /*  Rate of Recovery *//* 12 */
      break;

    case 33: p=strcat(Label,"\\gd\\d0\\u");     /* Total Immigration Ratge *//*  1 */
      break;
    case 34: p=strcat(Label,"\\gd\\d1\\u");     /* Contact rate: Total no of contacts an individual has per day  *//*  2 */
      break;
    case 35: p=strcat(Label,"\\gd\\d2\\u");       /* Infectivity       *//*  3 */
      break; 
    case 36: p=strcat(Label,"\\gd\\d3\\u");    /* Pre-symptomatic Infectivity Factor  *//*  4 */
      break;

    case 37: p=strcat(Label,"p\\d1\\u");     /* Contact rate: Total no of contacts an individual has per day  *//*  2 */
      break;
    case 38: p=strcat(Label,"p\\d2\\u");       /* Infectivity       *//*  3 */
      break; 
    case 39: p=strcat(Label,"p\\d3\\u");    /* Pre-symptomatic Infectivity Factor  *//*  4 */
      break;
      
    default:
      printf(".... INVALID PARAMETER KEY [key=%d]\n", j);
      printf(".... The permited correspondences are (0 to 12):\n");
      printf("\n");
      fprintf_Model_Parameters(stdout, P);
      exit(0);
    }
}


void AssignSymbol_to_Model_Parameters(int j, char * Label, Parameter_Table *P)
{
  /* Short Labels for Model Parameters */

  char * p;
  Label[0] = '\0';

  switch(j)
    {
    case  0: p=strcat(Label,"Kappa"); /*\\gb\\dY\\u"); /* Total (Initial) Population   *//*  0 */
      break;
    case  1: p=strcat(Label,"Mu");     /* Total Immigration Ratge *//*  1 */
      break;
    case  2: p=strcat(Label,"Beta");     /* Contact rate: Total no of contacts an individual has per day  *//*  2 */
      break;
    case  3: p=strcat(Label,"b");       /* Infectivity       *//*  3 */
      break; 
    case  4: p=strcat(Label,"Phi");    /* Pre-symptomatic Infectivity Factor  *//*  4 */
      break;
    case  5: p=strcat(Label,"Eps_I");    /* Isolation effectiveness of strong cases    *//*  5 */
      break;
    case  6: p=strcat(Label,"Eps_Y");    /* Isolation effectiveness of serious cases   *//*  6 */
      break;
    case  7: p=strcat(Label,"Sigma");           /* Rate of the appearance of infectious capacity *//*  7 */
      break;
    case  8: p=strcat(Label,"Gamma_1");    /* Rate of the appearance of symptoms   *//*  8 */
      break;
    case  9: p=strcat(Label,"p_0");      /* Probability of the appearance of strong symptoms  *//*  9 */
     break;
    case 10: p=strcat(Label,"Alpha");  /*  (Age-dependent) Rate of appearence of serious symptoms *//* 10 */
      break;
    case 11: p=strcat(Label,"Delta");/* (Age-dependent) Disease-Induced Mortality Rate   *//* 11 */
      break;
    case 12: p=strcat(Label,"Gamma_2");      /*  Rate of Recovery *//* 12 */
      break;

    case 13: p=strcat(Label,"Beta_00");     /* Total Immigration Ratge *//*  1 */
      break;
    case 14: p=strcat(Label,"Beta_01");     /* Contact rate: Total no of contacts an individual has per day  *//*  2 */
      break;
    case 15: p=strcat(Label,"Beta_02");       /* Infectivity       *//*  3 */
      break; 
    case 16: p=strcat(Label,"Beta_03");    /* Pre-symptomatic Infectivity Factor  *//*  4 */
      break;

    case 17: p=strcat(Label,"Beta_10");    /* Isolation effectiveness of strong cases    *//*  5 */
      break;
    case 18: p=strcat(Label,"Beta_11");    /* Isolation effectiveness of serious cases   *//*  6 */
      break;
    case 19: p=strcat(Label,"Beta_12");    /* Isolation effectiveness of serious cases   *//*  6 */
      break;
    case 20: p=strcat(Label,"Beta_13");  /*  (Age-dependent) Rate of appearence of serious symptoms *//* 10 */
      break;

    case 21: p=strcat(Label,"Beta_20");/* (Age-dependent) Disease-Induced Mortality Rate   *//* 11 */
      break;
    case 22: p=strcat(Label,"Beta_21");      /*  Rate of Recovery *//* 12 */
      break;
    case 23: p=strcat(Label,"Beta_22");     /* Total Immigration Ratge *//*  1 */
      break;
    case 24: p=strcat(Label,"Beta_23");     /* Contact rate: Total no of contacts an individual has per day  *//*  2 */
      break;

    case 25: p=strcat(Label,"Beta_30");       /* Infectivity       *//*  3 */
      break; 
    case 26: p=strcat(Label,"Beta_31");    /* Pre-symptomatic Infectivity Factor  *//*  4 */
      break;
    case 27: p=strcat(Label,"Beta_32");    /* Isolation effectiveness of strong cases    *//*  5 */
      break;
    case 28: p=strcat(Label,"Beta_33");    /* Isolation effectiveness of serious cases   *//*  6 */
      break;

    case 29: p=strcat(Label,"Alpha_0");    /* Isolation effectiveness of serious cases   *//*  6 */
      break;
    case 30: p=strcat(Label,"Alpha_1");  /*  (Age-dependent) Rate of appearence of serious symptoms *//* 10 */
      break;
    case 31: p=strcat(Label,"Alpha_2");/* (Age-dependent) Disease-Induced Mortality Rate   *//* 11 */
      break;
    case 32: p=strcat(Label,"Alpha_3");      /*  Rate of Recovery *//* 12 */
      break;

    case 33: p=strcat(Label,"Delta_0");     /* Total Immigration Ratge *//*  1 */
      break;
    case 34: p=strcat(Label,"Delta_1");     /* Contact rate: Total no of contacts an individual has per day  *//*  2 */
      break;
    case 35: p=strcat(Label,"Delta_2");       /* Infectivity       *//*  3 */
      break; 
    case 36: p=strcat(Label,"Delta_3");    /* Pre-symptomatic Infectivity Factor  *//*  4 */
      break;

    case 37: p=strcat(Label,"p_1");    /* Detectability     *//*  5 */
      break;
    case 38: p=strcat(Label,"p_2");    /* Detectability   *//*  6 */
      break;
    case 39: p=strcat(Label,"p_3");    /* Detectability *//*  6 */
      break;

    default:
      printf(".... INVALID PARAMETER KEY [key=%d]\n", j);
      printf(".... The permited correspondences are (0 to 12)\n");
      printf("\n");
      fprintf_Model_Parameters(stdout, P);
      exit(0);
    }
}
