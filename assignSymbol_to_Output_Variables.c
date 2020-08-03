#include <MODEL.h>

void AssignSymbol_to_Output_Variables(int j, char * Label, Parameter_Table * Table)
{
  char * p;
  Label[0] = '\0';
  if (j >= OUTPUT_VARIABLES_GENUINE) {
    j -= OUTPUT_VARIABLES_GENUINE;
    /* The first output variables are the model variables */
    AssignSymbol_to_Model_Variables(j, Label, Table);
  }
  else {        /* SEI1I2AYR fraction and more  */
    switch(j)
      {
      case  0:  p = strcat(Label , "f_S");       /*  0 */
        break;
      case  1:  p = strcat(Label , "f_E");        /*  1 */
        break;
      case  2:  p = strcat(Label , "f_I1");       /*  2 */
        break;
      case  3:  p = strcat(Label , "f_I2");       /*  3 */
        break;
      case  4:  p = strcat(Label , "f_A");        /*  4 */
        break;
      case  5:  p = strcat(Label , "f_Y");        /*  5 */
        break;
      case  6:  p = strcat(Label , "f_R");        /*  6 */
        break;
      case  7:  p = strcat(Label , "f_I");        /*  7 */
        break;
      case  8:  p = strcat(Label , "I_A");        /*  8 */
        break;
      case  9:  p = strcat(Label , "R_A");        /*  9 */
        break;
      case 10:  p = strcat(Label , "M_A");        /*  10 */
        break;
      case 11:  p = strcat(Label , "I");        /*  11 */
        break;
      case 12:  p = strcat(Label , "I_D");        /*  12 */
        break; 
      case 13:  p = strcat(Label , "N");          /*  13 */
        break;
      
      default:
        printf(".... INVALID OUTPUT VARIABLE KEY [key = %d]\n", j);
        printf(".... The permited correspondences are:\n");
        printf(".... from 0 to 13\n");
        exit(0);
      }
  }
}

void AssignCPGPLOT_Symbol_to_Output_Variables(int j, char * Label, Parameter_Table * Table)
{
  char * p;
  Label[0] = '\0';
  if (j >= OUTPUT_VARIABLES_GENUINE) {
    j -= OUTPUT_VARIABLES_GENUINE;
    /* The first output variables are the model variables */
    AssignSymbol_to_Model_Variables(j, Label, Table);
  }
  else {
    switch(j)
      {
      case  0:  p = strcat(Label , "f\\dS\\u");       /*  0 */
	break;
      case  1:  p = strcat(Label , "f\\dE\\u");        /*  1 */
        break;
      case  2:  p = strcat(Label , "f\\dI1\\u");       /*  2 */
        break;
      case  3:  p = strcat(Label , "f\\dI2\\u");       /*  3 */
        break;
      case  4:  p = strcat(Label , "f\\dA\\u");        /*  4 */
        break;
      case  5:  p = strcat(Label , "f\\dY\\u");        /*  5 */
        break;
      case  6:  p = strcat(Label , "f\\dR\\u");        /*  6 */
        break;
      case  7:  p = strcat(Label , "f\\dI\\u");        /*  7 */
        break;
      case  8:  p = strcat(Label , "I\\dA\\u");        /*  8 */
        break;
      case  9:  p = strcat(Label , "R\\dA\\u");        /*  9 */
        break;
      case 10:  p = strcat(Label , "M\\dA\\u");        /*  10 */
        break;
      case 11:  p = strcat(Label , "I");               /*  11 */
        break;
      case 12:  p = strcat(Label , "I\\dD\\u");        /*  12 */
        break;
      case 13:  p = strcat(Label , "N");        /*  13 */
        break;
	
      default:
        printf(".... INVALID OUTPUT VARIABLE KEY [key = %d]\n", j);
        printf(".... The permited correspondences are:\n");
        printf(".... from 0 to 13\n");
        exit(0);
      }
  }
}
