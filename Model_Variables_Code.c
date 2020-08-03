#include <MODEL.h>

void Model_Variables_Code_into_Parameter_Table (Parameter_Table * P)
{
  int i, Q; 
  int TYPE_of_MODEL;
  
  TYPE_of_MODEL = P->TYPE_of_MODEL;

  switch( TYPE_of_MODEL )
    {
      /* SEI1I2AYR * * * * * * * * * * * * * * * * * * * * * * */
    case 0:

      P->TOTAL_No_of_DISEASE_STAGES = 10; /* This includes accumulated variables */
      P->TOTAL_No_of_AGE_CLASSES    = 1;
      P->No_of_DISEASE_STAGES       = 7; 
      
        P->nS =   0; 
        P->nE =   1; 
        P->nI1 =  2; 
        P->nI2 =  3; 
        P->nA =   4;
        P->nY =   5;
        P->nR =   6;
	P->aI =   7;  /* Accumulated Number of Detected Infections (strong + severe symptoms) */
	P->aR =   8;  /* Accumulated Number of Detected Recoveries                            */ 
	P->aD =   9;  /* Accumulated Number of Deaths from Severe Symptoms                    */
	
        /* Conventions */
        P->K   = 9;     /* Label last class            */
        P->LI0 = 1;     /* Label first infected class  */
        P->LI  = 5;     /* Label last infected  class  */
   break;

   /* SEI1I2AYR_AGE * * * * * * * * * * * * * * * * * * * * * * */
    case 1:

      P->TOTAL_No_of_DISEASE_STAGES = 10; /* This includes accumulated variables */ 
      P->TOTAL_No_of_AGE_CLASSES    = 4;
      P->No_of_DISEASE_STAGES       = 7;

      P->TOTAL_No_of_EVENTS         = 72;  /* SEI1I2AAdYR_AGE: Total Number of Events */
      P->No_of_EVENTS               = 18;  /* SEI1I2AAdYR_AGE: Total Number of Events 
					      within an age class 
					      (These two numbers are not true: Under construction!!!) 
					   */
	P->n0S =   0; /* (0: Children) */
        P->n0E =   1; 
        P->n0I1 =  2; 
        P->n0I2 =  3; 
        P->n0A =   4;
        P->n0Y =   5;
        P->n0R =   6;
	P->a0I =   7;  /* Accumulated Number of Detected Infections (strong + severe symptoms) */
	P->a0R =   8;  /* Accumulated Number of Detected Recoveries                          */ 
	P->a0D =   9;  /* Accumulated Number of Deaths from Severe Symptoms                  */

	P->n1S =   10; /* (1: Students) */
        P->n1E =   11; 
        P->n1I1 =  12; 
        P->n1I2 =  13; 
        P->n1A =   14;
        P->n1Y =   15;
        P->n1R =   16;
	P->a1I =   17;  /* Accumulated Number of Detected Infections (strong + severe symptoms) */
	P->a1R =   18;  /* Accumulated Number of Detected Recoveries                          */ 
	P->a1D =   19;  /* Accumulated Number of Deaths from Severe Symptoms                  */

	P->n2S =   20; /* (2: Students) */
        P->n2E =   21; 
        P->n2I1 =  22; 
        P->n2I2 =  23; 
        P->n2A =   24;
        P->n2Y =   25;
        P->n2R =   26;
	P->a2I =   27;  /* Accumulated Number of Detected Infections (strong + severe symptoms) */
	P->a2R =   28;  /* Accumulated Number of Detected Recoveries                          */ 
	P->a2D =   29;  /* Accumulated Number of Deaths from Severe Symptoms                  */

	P->n3S =   30; /* (3: Seniors) */
        P->n3E =   31; 
        P->n3I1 =  32; 
        P->n3I2 =  33; 
        P->n3A =   34;
        P->n3Y =   35;
        P->n3R =   36;
	P->a3I =   37;  /* Accumulated Number of Detected Infections (strong + severe symptoms) */
	P->a3R =   38;  /* Accumulated Number of Detected Recoveries                          */ 
	P->a3D =   39;  /* Accumulated Number of Deaths from Severe Symptoms                  */
	
        /* Conventions */
        P->L0I0 = 1;     /* Label first infected class  (0: Children) */
        P->L0I  = 5;     /* Label last infected  class  */

	P->L1I0 = 11;     /* Label first infected class  (1: Students) */
        P->L1I  = 15;     /* Label last infected  class  */

	P->L2I0 = 21;     /* Label first infected class  (2: Workers) */
        P->L2I  = 25;     /* Label last infected  class  */

	P->L3I0 = 31;     /* Label first infected class  (3: Seniors) */
        P->L3I  = 35;     /* Label last infected  class  */

	P->K   = 39;     /* Label last class            */
   break;

   /* SEI1I2AAdYR_AGE * * * * * * * * * * * * * * * * * * * * * * */
   case 2:
     P->TOTAL_No_of_DISEASE_STAGES = 11; /* This includes accumulated variables */
     P->TOTAL_No_of_AGE_CLASSES    = 4;
     P->No_of_DISEASE_STAGES       = 8; 

     P->TOTAL_No_of_EVENTS         = 100;  /* SEI1I2AAdYR_AGE: Total Number of Events */
     P->No_of_EVENTS               = 25;   /* SEI1I2AAdYR_AGE: Total Number of Events 
					      within an age class */
	P->n0S =   0; /* (0: Children) */
        P->n0E =   1; 
        P->n0I1 =  2; 
        P->n0I2 =  3; 
        P->n0A =   4;
	P->n0Ad =  5;
        P->n0Y =   6;
        P->n0R =   7;
	P->a0I =   8;  /* Accumulated Number of Detected Infections (strong + severe symptoms) */
	P->a0R =   9;  /* Accumulated Number of Detected Recoveries                          */ 
	P->a0D =  10;  /* Accumulated Number of Deaths from Severe Symptoms                  */

	P->n1S =   11; /* (1: Students) */
        P->n1E =   12; 
        P->n1I1 =  13; 
        P->n1I2 =  14; 
        P->n1A =   15;
	P->n1Ad =  16;
        P->n1Y =   17;
        P->n1R =   18;
	P->a1I =   19;  /* Accumulated Number of Detected Infections (strong + severe symptoms) */
	P->a1R =   20;  /* Accumulated Number of Detected Recoveries                          */ 
	P->a1D =   21;  /* Accumulated Number of Deaths from Severe Symptoms                  */

	P->n2S =   22; /* (2: Students) */
        P->n2E =   23; 
        P->n2I1 =  24; 
        P->n2I2 =  25; 
	P->n2A =   26;
        P->n2Ad =  27;
        P->n2Y =   28;
        P->n2R =   29;
	P->a2I =   30;  /* Accumulated Number of Detected Infections (strong + severe symptoms) */
	P->a2R =   31;  /* Accumulated Number of Detected Recoveries                          */ 
	P->a2D =   32;  /* Accumulated Number of Deaths from Severe Symptoms                  */

	P->n3S =   33; /* (3: Seniors) */
        P->n3E =   34; 
        P->n3I1 =  35; 
        P->n3I2 =  36; 
        P->n3A =   37;
	P->n3Ad =  38;
        P->n3Y =   39;
        P->n3R =   40;
	P->a3I =   41;  /* Accumulated Number of Detected Infections (strong + severe symptoms) */
	P->a3R =   42;  /* Accumulated Number of Detected Recoveries                          */ 
	P->a3D =   43;  /* Accumulated Number of Deaths from Severe Symptoms                  */
	
        /* Conventions */
        P->L0I0 = 1;     /* Label first infected class  (0: Children) */
        P->L0I  = 6;     /* Label last infected  class  */

	P->L1I0 = 12;     /* Label first infected class  (1: Students) */
        P->L1I  = 17;     /* Label last infected  class  */

	P->L2I0 = 23;     /* Label first infected class  (2: Workers) */
        P->L2I  = 28;     /* Label last infected  class  */

	P->L3I0 = 34;     /* Label first infected class  (3: Seniors) */
        P->L3I  = 39;     /* Label last infected  class  */

	P->K   = 43;     /* Label last class            */
   break;

   /* SEI1I2AAdYR_AGE_MPOP * * * * * * * * * * * * * * * * * * * * * * */
   case 3:

     P->TOTAL_No_of_DISEASE_STAGES = 11; /* This includes accumulated variables */
     P->TOTAL_No_of_AGE_CLASSES    = 4;
     P->No_of_DISEASE_STAGES       = 8;
     
     P->TOTAL_No_of_EVENTS         = 100;  /* SEI1I2AAdYR_AGE_MPOP: Total Number of Events 
					     within every patch */
     P->No_of_EVENTS               = 25;  /* SEI1I2AAdYR_AGE_MPOP: Total Number of Events 
					     within a patch and an age class */
	P->n0S =   0; /* (0: Children) */
        P->n0E =   1; 
        P->n0I1 =  2; 
        P->n0I2 =  3; 
        P->n0A =   4;
	P->n0Ad =  5;
        P->n0Y =   6;
        P->n0R =   7;
	P->a0I =   8;  /* Accumulated Number of Detected Infections (strong + severe symptoms) */
	P->a0R =   9;  /* Accumulated Number of Detected Recoveries                            */ 
	P->a0D =  10;  /* Accumulated Number of Deaths from Severe Symptoms                    */

	P->n1S =   11; /* (1: Students) */
        P->n1E =   12; 
        P->n1I1 =  13; 
        P->n1I2 =  14; 
        P->n1A =   15;
	P->n1Ad =  16;
        P->n1Y =   17;
        P->n1R =   18;
	P->a1I =   19;  /* Accumulated Number of Detected Infections (strong + severe symptoms) */
	P->a1R =   20;  /* Accumulated Number of Detected Recoveries                          */ 
	P->a1D =   21;  /* Accumulated Number of Deaths from Severe Symptoms                  */

	P->n2S =   22; /* (2: Students) */
        P->n2E =   23; 
        P->n2I1 =  24; 
        P->n2I2 =  25; 
	P->n2A =   26;
        P->n2Ad =  27;
        P->n2Y =   28;
        P->n2R =   29;
	P->a2I =   30;  /* Accumulated Number of Detected Infections (strong + severe symptoms) */
	P->a2R =   31;  /* Accumulated Number of Detected Recoveries                          */ 
	P->a2D =   32;  /* Accumulated Number of Deaths from Severe Symptoms                  */

	P->n3S =   33; /* (3: Seniors) */
        P->n3E =   34; 
        P->n3I1 =  35; 
        P->n3I2 =  36; 
        P->n3A =   37;
	P->n3Ad =  38;
        P->n3Y =   39;
        P->n3R =   40;
	P->a3I =   41;  /* Accumulated Number of Detected Infections (strong + severe symptoms) */
	P->a3R =   42;  /* Accumulated Number of Detected Recoveries                          */ 
	P->a3D =   43;  /* Accumulated Number of Deaths from Severe Symptoms                  */

	Q  = P->TOTAL_No_of_DISEASE_STAGES * P->TOTAL_No_of_AGE_CLASSES; 
        /* Conventions */
	for (i=0; i<P->No_of_LOCAL_POPULATIONS; i++) { 
	  P->L_0I0[i] = 1+ Q*i;     /* Label first infected class  (0: Children) */
	  P->L_0I[i]  = 6+ Q*i;     /* Label last infected  class  */
	  
	  P->L_1I0[i] = 12+ Q*i;     /* Label first infected class  (1: Students) */
	  P->L_1I[i]  = 17+ Q*i;     /* Label last infected  class  */
	  
	  P->L_2I0[i] = 23+ Q*i;     /* Label first infected class  (2: Workers) */
	  P->L_2I[i]  = 28+ Q*i;     /* Label last infected  class  */
	  
	  P->L_3I0[i] = 34+ Q*i;     /* Label first infected class  (3: Seniors) */
	  P->L_3I[i]  = 39+ Q*i;     /* Label last infected  class  */
	}
	
	P->K = P->TOTAL_No_of_DISEASE_STAGES * P->TOTAL_No_of_AGE_CLASSES * P->No_of_LOCAL_POPULATIONS - 1;    
     
   break;
   default:
     printf(" This TYPE_of_MODEL (%d) code is not defined.\n", TYPE_of_MODEL);
     printf("Check input argument list\n");
     exit(0);
   }
  /* Conventionally, the last label in the argument list of

     Model_Variables_Code_into_Parameter_Table (...),

     (*K), should be the label of the last model state variable.
     Then ( * K) + 1 becomes de total number of dynamic variables.
  */
}
