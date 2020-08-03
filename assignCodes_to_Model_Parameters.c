#include "./Include/MODEL.h"

void AssignCodes_to_Model_Parameters(int j, char * Label, Parameter_Table *P)
{
  char * p;
  Label[0] = '\0';

  switch(j)
    {
    case  0:  p = strcat(Label, "-H0");  
	break;
    case  1:  p = strcat(Label, "-H1");  /*Immmigration rate into the population*//*  1 */
      break;
    case  2:  p = strcat(Label, "-H2");  /*Contact rate (number of contacts per day)*//*  2 */
      break;
    case  3:  p = strcat(Label, "-H3");  /*Average infectivity*//*  3 */
      break;
    case  4:  p = strcat(Label, "-H4");  /*Pre-symptomatic infectivity factor*//*  4 */
      break;
    case  5:  p = strcat(Label, "-H5");  /*Isolation effectiveness of strong cases*//*  5 */
      break;
    case  6:  p = strcat(Label, "-H6");  /*Isolation effectiveness of serious cases*//* 6 */
      break;
    case  7:  p = strcat(Label, "-H7");  /*Rate of the appearance of infectious capaciy*//*  7 */
      break;
    case  8:  p = strcat(Label, "-H8");  /*Rate of the appearance of symptoms*//*  8 */
      break;
    case  9:  p = strcat(Label, "-H9");  /*Probability of the appearance of strong symptoms*//* 9 */
      break;
    case 10:  p = strcat(Label, "-H10");  /*Age-dependent of the appearence serious symptoms*//* 10 */
      break;
    case 11:  p = strcat(Label, "-H11");  /*Age-dependent mortality rate *//* 11 */
      break;
    case 12:  p = strcat(Label, "-H12");  /*Rate of recovery*//* 12 */
      break;
    case 13:  p = strcat(Label, "-H13");  
      break;
    case 14:  p = strcat(Label, "-H14");  
      break;
    case 15:  p = strcat(Label, "-H15");  
      break;
    case 16:  p = strcat(Label, "-H16");  
      break;
    case 17:  p = strcat(Label, "-H17");  
      break;
    case 18:  p = strcat(Label, "-H18");  
      break;
    case 19:  p = strcat(Label, "-H19");  
      break;
    case 20:  p = strcat(Label, "-H20");  
      break;
    case 21:  p = strcat(Label, "-H21");  
      break;
    case 22:  p = strcat(Label, "-H22");  
      break;
    case 23:  p = strcat(Label, "-H23");  
      break;
    case 24:  p = strcat(Label, "-H24");  
      break;
    case 25:  p = strcat(Label, "-H25");  
      break;
    case 26:  p = strcat(Label, "-H26");  
      break;
    case 27:  p = strcat(Label, "-H27");  
      break;
    case 28:  p = strcat(Label, "-H28");  
      break;
    case 29:  p = strcat(Label, "-H29");  
      break;
    case 30:  p = strcat(Label, "-H30");  
      break;
    case 31:  p = strcat(Label, "-H31");  
      break;
    case 32:  p = strcat(Label, "-H32");  
      break;
    case 33:  p = strcat(Label, "-H33");  
      break;
    case 34:  p = strcat(Label, "-H34");  
      break;
    case 35:  p = strcat(Label, "-H35");  
      break;
    case 36:  p = strcat(Label, "-H36");  
      break;
    case 37:  p = strcat(Label, "-H37");  /*Rate of recovery*//* 12 */
      break;
    case 38:  p = strcat(Label, "-H38");  /*Rate of recovery*//* 12 */
      break;
    case 39:  p = strcat(Label, "-H39");  /*Rate of recovery*//* 12 */
      break; 
     
    default:
      printf(".... INVALID PARAMETER KEY [key = %d]\n", j);
      printf(".... The permited correspondences are 0 to 36:\n");
      printf("\n");
      fprintf_Model_Parameters(stdout, P);
      exit(0);
    }
}
