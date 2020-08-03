#include <MODEL.h>

void assert_right_model_definition( Parameter_Table * P )
{

#if defined SEI1I2AYR
  
    assert ( P->TYPE_of_MODEL == 0 );
    assert( P->No_of_LOCAL_POPULATIONS == 1);   /* Command line to run should contain : -HN 1 */
  
#endif

#if defined SEI1I2AYR_AGE
  
    assert( P->TYPE_of_MODEL == 1 );
    assert( P->No_of_LOCAL_POPULATIONS == 1); /* Command line to run should contain : -HN 1 */
    
#endif

#if defined SEI1I2AAdYR_AGE
    
    assert( P->TYPE_of_MODEL == 2 );
    assert( P->No_of_LOCAL_POPULATIONS == 1); /* Command line to run should contain : -HN 1 */
  
#endif

#if defined SEI1I2AAdYR_AGE_MPOP
    
    assert( P->TYPE_of_MODEL == 3 );
  
#endif

}
