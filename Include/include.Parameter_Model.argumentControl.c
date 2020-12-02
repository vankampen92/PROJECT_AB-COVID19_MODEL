/* Human Parameters */

	    case 'H': /* Maximum and Minimum Transmission Rate */
              if(argv[argcount][2]=='N')         sscanf(argv[argcount+1],"%d",
							&No_of_LOCAL_POPULATIONS);          /*  N */
  
              else if(argv[argcount][2]=='0')    sscanf(argv[argcount+1],"%lf",&Kappa) ;    /*  0 */

	      else if(argv[argcount][2]=='1') {
		if(argv[argcount][3]=='0') 	 sscanf(argv[argcount+1],"%lf",&Alpha);     /* 10 */ 
		else if(argv[argcount][3]=='1')  sscanf(argv[argcount+1],"%lf",&Delta);     /* 11 */
		else if(argv[argcount][3]=='2')  sscanf(argv[argcount+1],"%lf",&Gamma_2);   /* 12 */
		else if(argv[argcount][3]=='3')  sscanf(argv[argcount+1],"%lf",&Beta_00);   /* 13 */
		else if(argv[argcount][3]=='4')  sscanf(argv[argcount+1],"%lf",&Beta_01);   /* 14 */
		else if(argv[argcount][3]=='5')  sscanf(argv[argcount+1],"%lf",&Beta_02);   /* 15 */
		else if(argv[argcount][3]=='6')  sscanf(argv[argcount+1],"%lf",&Beta_03);   /* 16 */
		else if(argv[argcount][3]=='7')  sscanf(argv[argcount+1],"%lf",&Beta_10);   /* 17 */
		else if(argv[argcount][3]=='8')  sscanf(argv[argcount+1],"%lf",&Beta_11);   /* 18 */
		else if(argv[argcount][3]=='9')  sscanf(argv[argcount+1],"%lf",&Beta_12);   /* 19 */

		else if(argv[argcount][3]=='\0') sscanf(argv[argcount+1],"%lf",&Imm);       /*  1 */  
		else {
		  printf(" Error at reading input arguments: -  %s  \n", argv[argcount]);
		  exit(0);
		}
	      }

	      else if(argv[argcount][2]=='2') {
	      	if(argv[argcount][3]=='0')       sscanf(argv[argcount+1],"%lf", &Beta_13);  /* 20 */ 
	      	else if(argv[argcount][3]=='1')  sscanf(argv[argcount+1],"%lf", &Beta_20);  /* 21 */
	      	else if(argv[argcount][3]=='2')  sscanf(argv[argcount+1],"%lf", &Beta_21);  /* 22 */
	      	else if(argv[argcount][3]=='3')  sscanf(argv[argcount+1],"%lf", &Beta_22);  /* 23 */
	      	else if(argv[argcount][3]=='4')  sscanf(argv[argcount+1],"%lf", &Beta_23);  /* 24 */
	      	else if(argv[argcount][3]=='5')  sscanf(argv[argcount+1],"%lf", &Beta_30);  /* 25 */
		else if(argv[argcount][3]=='6')  sscanf(argv[argcount+1],"%lf", &Beta_31);  /* 26 */
	      	else if(argv[argcount][3]=='7')  sscanf(argv[argcount+1],"%lf", &Beta_32);  /* 27 */
	      	else if(argv[argcount][3]=='8')  sscanf(argv[argcount+1],"%lf", &Beta_33);  /* 28 */
	      	else if(argv[argcount][3]=='9')  sscanf(argv[argcount+1],"%lf", &Alpha_0);  /* 29 */

		else if(argv[argcount][3]=='\0') sscanf(argv[argcount+1],"%lf", &Beta);     /* 2 */
	      	else {
	      	  printf(" Error at reading input arguments: -  %s  \n", argv[argcount]);
	      	  exit(0);
	      	}
	      }

              else if(argv[argcount][2]=='3') {
		if(argv[argcount][3]=='0')       sscanf(argv[argcount+1],"%lf", &Alpha_1);  /* 30 */
	      	else if(argv[argcount][3]=='1')  sscanf(argv[argcount+1],"%lf", &Alpha_2);  /* 31 */
	      	else if(argv[argcount][3]=='2')  sscanf(argv[argcount+1],"%lf", &Alpha_3);  /* 32 */
	      	else if(argv[argcount][3]=='3')  sscanf(argv[argcount+1],"%lf", &Delta_0);  /* 33 */
	      	else if(argv[argcount][3]=='4')  sscanf(argv[argcount+1],"%lf", &Delta_1);  /* 34 */
	      	else if(argv[argcount][3]=='5')  sscanf(argv[argcount+1],"%lf", &Delta_2);  /* 35 */
		else if(argv[argcount][3]=='6')  sscanf(argv[argcount+1],"%lf", &Delta_3);  /* 36 */
	      	else if(argv[argcount][3]=='7')  sscanf(argv[argcount+1],"%lf", &p_1);
	      	else if(argv[argcount][3]=='8')  sscanf(argv[argcount+1],"%lf", &p_2);
	      	else if(argv[argcount][3]=='9')  sscanf(argv[argcount+1],"%lf", &p_3);
	       
		else if(argv[argcount][3]=='\0') sscanf(argv[argcount+1],"%lf", &b);        /* 3 */
	      	else {
	      	  printf(" Error at reading input arguments: -  %s  \n", argv[argcount]);
	      	  exit(0);
	      	}
	      }

	      else if(argv[argcount][2]=='4')    sscanf(argv[argcount+1],"%lf",&Phi);       /*  4 */
	      else if(argv[argcount][2]=='5')    sscanf(argv[argcount+1],"%lf",&Eps_I);     /*  5 */
	      else if(argv[argcount][2]=='6')    sscanf(argv[argcount+1],"%lf",&Eps_Y);     /*  6 */ 
	      else if(argv[argcount][2]=='7')    sscanf(argv[argcount+1],"%lf",&Sigma);     /*  7 */
	      else if(argv[argcount][2]=='8')    sscanf(argv[argcount+1],"%lf",&Gamma_1);   /*  8 */ 
	      else if(argv[argcount][2]=='9')    sscanf(argv[argcount+1],"%lf",&p_0);       /*  9 */
	      else {
		printf(" Error at reading input arguments: -  %s  \n", argv[argcount]);
		exit(0);
	      }
	      skip++;
	      break;

#include <include.Type_of_Model.argumentControl.c>
