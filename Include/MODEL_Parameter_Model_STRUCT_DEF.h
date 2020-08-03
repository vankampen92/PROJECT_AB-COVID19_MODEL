typedef struct Parameter_Modelinfo
{
  int MODEL_INPUT_PARAMETERS;
  int MODEL_OUTPUT_VARIABLES;
  int MODEL_STATE_VARIABLES;

  /* * * Model Parameters  * * */
#include <include.Parameter_Model.global.h>
  
  /* * * Initial Conditions  * */
#include <include.Initial_Conditions.global.h>

  /* * * Error Model * * * */
#include "include.Error_Control.global.h"

  Trend_Control * Tr;

#if defined CPGPLOT_REPRESENTATION
  Parameter_CPGPLOT * CPG;
#endif

  int nS, nE, nI1, nI2, nA, nAd, nY, nR;
  int aI, aR, aD;
  
  int n0S, n0E, n0I1, n0I2, n0A, n0Ad, n0Y, n0R;
  int a0I, a0R, a0D;
  int n1S, n1E, n1I1, n1I2, n1A, n1Ad, n1Y, n1R;
  int a1I, a1R, a1D;
  int n2S, n2E, n2I1, n2I2, n2A, n2Ad, n2Y, n2R;
  int a2I, a2R, a2D; 
  int n3S, n3E, n3I1, n3I2, n3A, n3Ad, n3Y, n3R;
  int a3I, a3R, a3D;
  
  int nTS, nTE, nTI1, nTI2, nTA, nTY, nTR;
  
  int LI0;  /* First Infected Class */
  int LI;   /* Last Infected Class  */

  int L0I0;  /* First Infected Class */
  int L0I;   /* Last Infected Class  */

  int L1I0;  /* First Infected Class */
  int L1I;   /* Last Infected Class  */

  int L2I0;  /* First Infected Class */
  int L2I;   /* Last Infected Class  */

  int L3I0;  /* First Infected Class */
  int L3I;   /* Last Infected Class  */

  int K;

  int TOTAL_No_of_DISEASE_STAGES;  /* Ex: 11 for SEI1I2AAdYR */
  int TOTAL_No_of_AGE_CLASSES;     /* Ex: 4                  */
  int No_of_DISEASE_STAGES;        /* Ex: 8 (without counting acummulating variables) */
  
  int No_of_NEIGHBORS;
  int TYPE_of_NETWORK;
  int TOTAL_No_of_EVENTS;
  /* Total Number of Events within a patch, i.e., 25 * 4 = 100 */
  int No_of_EVENTS;
  
}Parameter_Model;
