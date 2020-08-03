typedef struct Communityinfo
{
  /* Total population of each age class */
  int TOTAL_No_of_AGE_CLASSES;          /* This implementation only supports 4 age classes      */
  int TOTAL_No_of_DISEASE_STAGES;       /* This is model dependent (11 in SEI1I2AAdYR_AGE_MPOP) */ 
  
  int N0;
  int N1;
  int N2;
  int N3; 
  
  int No_of_LOCAL_POPULATIONS; /* Number of patches of the system the single patch is embedded in      */
  int no_VARIABLES;  /* Number of variables needed to describe the state
			of the patch at any given time. This only coicides with the 
			total MODEL_STATE_VARIABLES when the we have only one patch          */

  int * n;           /* n[0], ..., n[no_VARIABLES-1] defines the state
			of the patch completely                                              */
  double * rate;     /* Transition probability for an individual at each class               */
  double * rToI;     /* Transition probability for all individuals at each class             */ 
  double ratePatch;  /* Transition probability of this patch                                 */
  
  struct point position;  /* Patch Geographical Coordinates                                  */

  int No_NEI;

  int * Patch_Connections; 

  double * Total_Per_Capita_Out_Migration_Rate;
  double ** Total_Imm_Rate_Per_Disease_Status;
  /* Total immigration caused by individuals in a given disease status across all 
     neighboring local populations
  */
  double *** Imm_Rates_Per_Disease_Status;
  
  double ** In_Migration_Vector; 
  double ** Out_Migration_Vector;
  double *** Metapop_Connectivity_Matrix; 

  struct Communityinfo ** NEI; /* An array of pointers to the neighbors the focal patch 
				  is connected to                                            */
}Community;

