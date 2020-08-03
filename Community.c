#include <MODEL.h>

/* This functions allocate, initialize and free a number of local communities,
   which make up our total patch system or metapopulation */

void Community_Allocation ( Community ** PATCH, Parameter_Model * P )
{
  int i, j, a, Q, K;
  int no, n_Age;

  Q = P->TOTAL_No_of_DISEASE_STAGES * P->TOTAL_No_of_AGE_CLASSES; /* Ex: 11 times 4 */
  K = P->No_of_DISEASE_STAGES; 
  
  no    = P->No_of_LOCAL_POPULATIONS;
  n_Age = P->TOTAL_No_of_AGE_CLASSES;

  for(i=0; i<no; i++){
    PATCH[i] = (Community *)calloc( 1, sizeof(Community) );
    
    PATCH[i]->n = (int *)calloc(Q, sizeof( int ));

    PATCH[i]->rate = (double *)calloc(P->TOTAL_No_of_EVENTS, sizeof( double ));
    PATCH[i]->rToI = (double *)calloc(P->TOTAL_No_of_EVENTS, sizeof( double ));

    PATCH[i]->Patch_Connections = (int *)calloc(no, sizeof( double ));

    PATCH[i]->Out_Migration_Vector = (double **)calloc(n_Age, sizeof( double *));
    for(a=0; a<n_Age; a++)
      PATCH[i]->Out_Migration_Vector[a] = (double *)calloc(no, sizeof( double ));

    PATCH[i]->In_Migration_Vector = (double **)calloc(n_Age, sizeof( double *));
    for(a=0; a<n_Age; a++)
      PATCH[i]->In_Migration_Vector[a] = (double *)calloc(no, sizeof( double ));

    PATCH[i]->NEI  = (Community **)calloc(no, sizeof(Community *) );

    PATCH[i]->Total_Per_Capita_Out_Migration_Rate = (double *)calloc(n_Age, sizeof(double) );

    PATCH[i]->Total_Imm_Rate_Per_Disease_Status = (double **)calloc(n_Age, sizeof(double *) );
    for(a=0; a<n_Age; a++) 
      PATCH[i]->Total_Imm_Rate_Per_Disease_Status[a] = (double *)calloc(K, sizeof( double *));  

    PATCH[i]->Imm_Rates_Per_Disease_Status = (double ***)calloc(n_Age, sizeof( double **));
    for(a=0; a<n_Age; a++) {
      PATCH[i]->Imm_Rates_Per_Disease_Status[a] = (double **)calloc(K, sizeof( double *));    
      for(j=0; j<K; j++)
	PATCH[i]->Imm_Rates_Per_Disease_Status[a][j] = (double *)calloc(no, sizeof( double ));
    }
  }
}

void Community_Free (Community ** PATCH, Parameter_Model * P)
{
  int Q, K, i, j, a, n_Age;

  Q  = P->TOTAL_No_of_DISEASE_STAGES * P->TOTAL_No_of_AGE_CLASSES; /* Ex: 11 times 4 */
    
  /* BEGIN: Patch Total Destruction */
  for (i=0; i<P->No_of_LOCAL_POPULATIONS; i++){

    n_Age = PATCH[i]->TOTAL_No_of_AGE_CLASSES;

    free(PATCH[i]->n);

    free(PATCH[i]->rate);
    free(PATCH[i]->rToI);

    free(PATCH[i]->Patch_Connections);

    for(a=0; a<n_Age; a++) { 
      free(PATCH[i]->Out_Migration_Vector[a]);
      free(PATCH[i]->In_Migration_Vector[a]);
      for(j=0; j<K; j++)
	free(PATCH[i]->Imm_Rates_Per_Disease_Status[a][j]);
      free(PATCH[i]->Imm_Rates_Per_Disease_Status[a]);
    }
    free(PATCH[i]->Out_Migration_Vector);  
    free(PATCH[i]->In_Migration_Vector);
    free(PATCH[i]->Imm_Rates_Per_Disease_Status);
    
    free(PATCH[i]->Total_Per_Capita_Out_Migration_Rate); 

    for(a=0; a<n_Age; a++) 
      free(PATCH[i]->Total_Imm_Rate_Per_Disease_Status[a]);
    free(PATCH[i]->Total_Imm_Rate_Per_Disease_Status);
    
    free(PATCH[i]->NEI);
    free(PATCH[i]);
  }
  
  free( PATCH );
  /*   END: Patch Total Destruction */
}

void Community_Initialization (Community ** PATCH,
			       Parameter_Model * P )
{
  int i, j, Q, no;

  /* Q is the number of variables required to define the state of a single patch */
  Q = P->TOTAL_No_of_DISEASE_STAGES * P->TOTAL_No_of_AGE_CLASSES; /* Ex: 11 times 4 */

  no = P->No_of_LOCAL_POPULATIONS;
  for(i=0; i<no; i++){

    PATCH[i]->TOTAL_No_of_AGE_CLASSES    = P->TOTAL_No_of_AGE_CLASSES;
    PATCH[i]->TOTAL_No_of_DISEASE_STAGES = P->TOTAL_No_of_DISEASE_STAGES;

    PATCH[i]->N0 = P->N0;
    PATCH[i]->N1 = P->N1;
    PATCH[i]->N2 = P->N2;
    PATCH[i]->N3 = P->N3;

    PATCH[i]->No_of_LOCAL_POPULATIONS  = P->No_of_LOCAL_POPULATIONS;

    PATCH[i]->no_VARIABLES   = Q;                    // P->MODEL_STATE_VARIABLES;
    /* This is the number of dynamic state variables */
    /* (required to defined the state of the patch)  */

    PATCH[i]->ratePatch    = 0.0;      /* Transition probabilities at this patch */
    for( j=0; j<P->TOTAL_No_of_EVENTS; j++) {
      PATCH[i]->rate[j]= 0.0;
      PATCH[i]->rToI[j]= 0.0;
    }

    PATCH[i]->Metapop_Connectivity_Matrix = P->Metapop_Connectivity_Matrix;
  }

  /* When PATCH represents a multi-patch network, patch connections
     and number of patch connections for each patch (PATCH[i]->No_NEI)
     should be initialized                                          */
  Network_Structure_Inititialization (PATCH, P->TYPE_of_NETWORK);

  Immigration_Preassure_on_Focal_Patch_Initialization( PATCH, P );
  
  Writing_Adjacency_List(PATCH);
}

void Writing_Adjacency_List(Community ** PATCH)
{
  int i,j, a, n_Age, no;

  no    = PATCH[0]->No_of_LOCAL_POPULATIONS;
  n_Age = PATCH[0]->TOTAL_No_of_AGE_CLASSES;

  for(a=0; a<n_Age; a++){
    printf("%s %d\n", "Age class", a);
    for(i=0; i<no; i++){
      printf("%s %d %s", "Local Population No", i, "is conntected to [  ");
      for(j=0; j<PATCH[i]->No_NEI; j++) {
        printf("%d ", PATCH[i]->Patch_Connections[j]);
      }
      printf("%s\n", " ].");
    }
    printf("\n");
  }
  
  Press_Key();
}

void Immigration_Preassure_on_Focal_Patch_Initialization( Community ** PATCH,
							  Parameter_Model * P )
{
  /* This preassure depends on population structure across local populations */

  /* This function is required when the initial condition is set up. It calculates the 
     immigration preassures on each patch caused by individuals of every disease
     status located in the neighborhood of the focal patch                   */

  /* However, this function should be only used in conjunction with: 

     Immigration_Preassure_on_Focal_Patch_Update();
     Temporal_Dynamics_Update();

     which are all functions intended to optimize the algorithm. The idea is that all 
     temporal rates for the different events, including immigration preassures, are only 
     calculated once, at the initial condition, and then they are updated (by summing or 
     substracting) according to the flow of events that occur in the system

     These two functions have not been implemented yet.  
  */
  
  int Q, i, a, j, k, n, n_Age; 
  double Imm_Rate;
  
  /* Q is the number of variables required to define the state of a single patch */
  Q     = P->TOTAL_No_of_DISEASE_STAGES * P->TOTAL_No_of_AGE_CLASSES; /* Ex: 11 times 4 */
  n_Age = P->TOTAL_No_of_AGE_CLASSES;

  for(i=0; i<P->No_of_LOCAL_POPULATIONS; i++) {
    for(j=0; j < Q; j++) {
      
      a = j/P->TOTAL_No_of_DISEASE_STAGES;
      k = j%P->TOTAL_No_of_DISEASE_STAGES; 
      
      if(k < P->No_of_DISEASE_STAGES) { 
	Imm_Rate = 0.0;
	for(n=0; n < PATCH[i]->No_NEI; n++){
	  Imm_Rate += PATCH[i]->In_Migration_Vector[a][n]*(double)PATCH[i]->NEI[n]->n[j]; 
	  PATCH[i]->Imm_Rates_Per_Disease_Status[a][k][n] = PATCH[i]->In_Migration_Vector[a][n]*(double)PATCH[i]->NEI[n]->n[j];
	  }
	PATCH[i]->Total_Imm_Rate_Per_Disease_Status[a][k] = Imm_Rate;
      }   
    }
  }   
}


void Network_Structure_Inititialization (Community ** PATCH, int TYPE_of_NETWORK)
{
  int i,j,n, a, no, n_Age;

  double Total_Per_Capita_Out_Migration_Rate = 0.0;
  
  switch ( TYPE_of_NETWORK )
    {
    case 0:

      no    = PATCH[0]->No_of_LOCAL_POPULATIONS;
      n_Age = PATCH[0]->TOTAL_No_of_AGE_CLASSES;
      for( a=0; a<n_Age; a++ ) {
	Total_Per_Capita_Out_Migration_Rate = 0.0;
	
	for(i=0; i<no; i++){
	  n=0;
	  for(j=0; j<no; j++){
	    if( i != j) {
	      PATCH[i]->NEI[n] = PATCH[j];
	      
	      PATCH[i]->Out_Migration_Vector[a][n] = PATCH[i]->Metapop_Connectivity_Matrix[a][j][i];
	      PATCH[i]->In_Migration_Vector[a][n] = PATCH[i]->Metapop_Connectivity_Matrix[a][i][j];

	      PATCH[i]->Patch_Connections[n] = j;

	      Total_Per_Capita_Out_Migration_Rate += PATCH[i]->Out_Migration_Vector[a][n];
	      n++;
	    }
	  }
	  
	  PATCH[i]->No_NEI = n; /* All patches are connected to i */
	  PATCH[i]->Total_Per_Capita_Out_Migration_Rate[a] = Total_Per_Capita_Out_Migration_Rate; 
	}
      }
      break;
    default:
      printf("Type of Network not yet defined!!!\n");
      printf("Allowed Network Codes are: 0\n");
      printf("TYPE of NETWORK = %d\n", TYPE_of_NETWORK);
      exit(0);
    }
}

void Print_Meta_Community_Patch_System (Parameter_Table * Table)
{
  int k, Q, Patch;

  Community ** Village = Table->Patch_System;
  
  Q = Table->TOTAL_No_of_DISEASE_STAGES * Table->TOTAL_No_of_AGE_CLASSES; /* Ex: 11 times 4 */
  
  for(Patch=0; Patch<Table->No_of_LOCAL_POPULATIONS; Patch++) {
    printf(" Total population on local population %d (checking local pointers, Y and J vectors):\n", Patch);
    for(k = 0; k < Q; k++) {
      if(k%Table->TOTAL_No_of_DISEASE_STAGES == 0 && k > 0) printf("\n");
      printf(" %s = %d\t", Table->Model_Variable_Symbol[k + Patch*Q], Village[Patch]->n[k]);
    }
    printf("\n\n");
    for(k = 0; k < Q; k++) {
      if(k%Table->TOTAL_No_of_DISEASE_STAGES == 0  && k > 0) printf("\n");
      printf(" %s = %g\t", Table->Model_Variable_Symbol[k + Patch*Q],
	     Table->Vector_Model_Variables[k+Patch*Q]);
    }
    printf("\n\n");
    for(k = 0; k < Q; k++) {
      if(k%Table->TOTAL_No_of_DISEASE_STAGES == 0 && k > 0) printf("\n");
      printf(" %s = %d\t", Table->Model_Variable_Symbol[k + Patch*Q],
	     Table->Vector_Model_Int_Variables[k+Patch*Q]);
    }
    printf("\n\n");
  }
}
