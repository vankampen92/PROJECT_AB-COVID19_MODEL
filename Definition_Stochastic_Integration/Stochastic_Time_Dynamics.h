void S_T_O_C_H_A_S_T_I_C___T_I_M_E___D_Y_N_A_M_I_C_S( int i, 
						      Parameter_Table * Table, 
						      int * Bad_Times );

void Initial_Conditions_Stochastic_Dynamics( Parameter_Table * Table, double * y_INI );

void Patch_System_Initialization (Community ** PATCH, Parameter_Table * Table, double * y_INI);

int Advance_Current_Time( Parameter_Table * Table, 
			   Stochastic_Rate * Rate, double * Time_Current, int * New );

int Choose_Village(double max_Probability, Community ** Pop, Parameter_Model * Par);

void Execute_One_Step(Community ** SP,
		      Parameter_Table * Table,
		      double max_Probability, 
		      int * Event, int * Patch);

void Temporal_Dynamics(Community ** My_Community, Parameter_Table * Table, Stochastic_Rate * Rate);

void Temporal_Dynamics_Update( Community ** My_Community,
			       Parameter_Table * Table, Stochastic_Rate * Rate,
			       int Type_of_Event, int Patch);
