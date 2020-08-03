/* Human Parameters */

	    case 'H': /* Maximum and Minimum Transmission Rate */

              if(argv[argcount][2]=='N')  fprintf(fp,"-HN  %d  ",
						  Table->No_of_LOCAL_POPULATIONS);    /*  N */     

              else if(argv[argcount][2]=='0')    fprintf(fp,"-H0  %g  ",Table->Kappa);    /*  0 */

	      else if(argv[argcount][2]=='1') {
		if(argv[argcount][3]=='0') 	 fprintf(fp,"-H10  %g  ",Table->Alpha);     /* 10 */ 
		else if(argv[argcount][3]=='1')  fprintf(fp,"-H11  %g  ",Table->Delta);     /* 11 */
		else if(argv[argcount][3]=='2')  fprintf(fp,"-H12  %g  ",Table->Gamma_2);   /* 12 */
		else if(argv[argcount][3]=='3')  fprintf(fp,"-H13  %g  ",Table->Beta_00);   /* 13 */
		else if(argv[argcount][3]=='4')  fprintf(fp,"-H14  %g  ",Table->Beta_01);   /* 14 */
		else if(argv[argcount][3]=='5')  fprintf(fp,"-H15  %g  ",Table->Beta_02);   /* 15 */
		else if(argv[argcount][3]=='6')  fprintf(fp,"-H16  %g  ",Table->Beta_03);   /* 16 */
		else if(argv[argcount][3]=='7')  fprintf(fp,"-H17  %g  ",Table->Beta_10);   /* 17 */
		else if(argv[argcount][3]=='8')  fprintf(fp,"-H18  %g  ",Table->Beta_11);   /* 18 */
		else if(argv[argcount][3]=='9')  fprintf(fp,"-H19  %g  ",Table->Beta_12);   /* 19 */
		else if(argv[argcount][3]=='\0') fprintf(fp,"-H1  %g  ",Table->Imm);  /*  1 */  
		else {
		  printf(" Error at reading input arguments: -  -  %s    \n", argv[argcount]);
		  exit(0);
		}
	      }

	      else if(argv[argcount][2]=='2') {
	      	if(argv[argcount][3]=='0')       fprintf(fp,"-H20  %g  ", Table->Beta_13);  /* 20 */ 
	      	else if(argv[argcount][3]=='1')  fprintf(fp,"-H21  %g  ", Table->Beta_20);  /* 21 */
	      	else if(argv[argcount][3]=='2')  fprintf(fp,"-H21  %g  ", Table->Beta_21);  /* 22 */
	      	else if(argv[argcount][3]=='3')  fprintf(fp,"-H23  %g  ", Table->Beta_22);  /* 23 */
	      	else if(argv[argcount][3]=='4')  fprintf(fp,"-H24  %g  ", Table->Beta_23);  /* 24 */
	      	else if(argv[argcount][3]=='5')  fprintf(fp,"-H24  %g  ", Table->Beta_30);  /* 25 */
		else if(argv[argcount][3]=='6')  fprintf(fp,"-H26  %g  ", Table->Beta_31);  /* 26 */
	      	else if(argv[argcount][3]=='7')  fprintf(fp,"-H27  %g  ", Table->Beta_32);  /* 27 */
	      	else if(argv[argcount][3]=='8')  fprintf(fp,"-H28  %g  ", Table->Beta_33);  /* 28 */
	      	else if(argv[argcount][3]=='9')  fprintf(fp,"-H29  %g  ", Table->Alpha_0);  /* 29 */
		else if(argv[argcount][3]=='\0') fprintf(fp,"-H3  %g  ", Table->Beta);   /* 2 */
	      	else {
	      	  printf(" Error at reading input arguments: -  -  %s    \n", argv[argcount]);
	      	  exit(0);
	      	}
	      }

              else if(argv[argcount][2]=='3') {
		if(argv[argcount][3]=='0')       fprintf(fp,"-H30  %g  ", Table->Alpha_1);  /* 30 */
	      	else if(argv[argcount][3]=='1')  fprintf(fp,"-H31  %g  ", Table->Alpha_2);  /* 31 */
	      	else if(argv[argcount][3]=='2')  fprintf(fp,"-H32  %g  ", Table->Alpha_3);  /* 32 */
	      	else if(argv[argcount][3]=='3')  fprintf(fp,"-H33  %g  ", Table->Delta_0);  /* 33 */
	      	else if(argv[argcount][3]=='4')  fprintf(fp,"-H34  %g  ", Table->Delta_1);  /* 34 */
	      	else if(argv[argcount][3]=='5')  fprintf(fp,"-H35  %g  ", Table->Delta_2);  /* 35 */
		else if(argv[argcount][3]=='6')  fprintf(fp,"-H36  %g  ", Table->Delta_3);  /* 36 */
	      	else if(argv[argcount][3]=='7')  fprintf(fp,"-H37  %g  ", Table->p_1);
	      	else if(argv[argcount][3]=='8')  fprintf(fp,"-H38  %g  ", Table->p_2);
	      	else if(argv[argcount][3]=='9')  fprintf(fp,"-H39  %g  ", Table->p_3);
		
		else if(argv[argcount][3]=='\0') fprintf(fp,"-  %g  ", Table->b);    /* 3 */
	      	else {
	      	  printf(" Error at reading input arguments: -  -  %s    \n", argv[argcount]);
	      	  exit(0);
	      	}
	      }

	      else if(argv[argcount][2]=='4')    fprintf(fp,"-H4  %g  ",Table->Phi);    /*  4 */
	      else if(argv[argcount][2]=='5')    fprintf(fp,"-H5  %g  ",Table->Eps_I); /*  5 */
	      else if(argv[argcount][2]=='6')    fprintf(fp,"-H6  %g  ",Table->Eps_Y);  /*  6 */ 
	      else if(argv[argcount][2]=='7')    fprintf(fp,"-H7  %g  ",Table->Sigma);  /*  7 */
	      else if(argv[argcount][2]=='8')    fprintf(fp,"-H8  %g  ",Table->Gamma_1);/*  8 */ 
	      else if(argv[argcount][2]=='9')    fprintf(fp,"-H9  %g  ",Table->p_0);   /*  9 */
	      else {
		printf(" Error at reading input arguments: -  -  %s    \n", argv[argcount]);
		exit(0);
	      }
	      skip++;
	      break;

#include <include.Type_of_Model.argumentControl_fprintf.c>
