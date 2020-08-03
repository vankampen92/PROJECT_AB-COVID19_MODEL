/* Scan Parameters */
 
/* Initial Conditions */
	case 'x':
              if (TYPE_of_MODEL == 0 ) {  

		if(argv[argcount][2]=='n') 
		fprintf(fp, "-xn  %d  ",Table->TYPE_of_INITIAL_CONDITION);
		
		else if(argv[argcount][2]=='R') 
		  fprintf(fp, "-xR  %d  ",Table->RESCALING_INITIAL_TOTAL_POPULATION);
		
		else if(argv[argcount][2]=='N') 
		  fprintf(fp, "-xR  %g  ",Table->INITIAL_TOTAL_POPULATION);
		
		else if(argv[argcount][2]=='0') fprintf(fp, "-x0  %g  ",Table->nS__0);
		else if(argv[argcount][2]=='1')    fprintf(fp, "-x1  %g  ",Table->nE__0);
		else if(argv[argcount][2]=='2')    fprintf(fp, "-x2  %g  ",Table->nI1__0);
		else if(argv[argcount][2]=='3')    fprintf(fp, "-x3  %g  ",Table->nI2__0);
		else if(argv[argcount][2]=='4')    fprintf(fp, "-x4  %g  ",Table->nA__0);
		else if(argv[argcount][2]=='5')    fprintf(fp, "-x5  %g  ",Table->nY__0);
		else if(argv[argcount][2]=='6')    fprintf(fp, "-x6  %g  ",Table->nR__0);
		else if(argv[argcount][2]=='7')    fprintf(fp, "-x7  %g  ",Table->aI__0);
		else if(argv[argcount][2]=='8')    fprintf(fp, "-x8  %g  ",Table->aR__0);
		else if(argv[argcount][2]=='9')    fprintf(fp, "-x9  %g  ",Table->aD__0);
		
		else{
		  printf("xn -xN -xR -x0 to -x9 are the only allowable keys.\n");
		  printf("Something goes very wrong (in an argumentfprintf function)\n");
		  exit(0);
		}
		
	      }
              else if (TYPE_of_MODEL == 1 ) {

		if(argv[argcount][2]=='n') 
		fprintf(fp, "-xn  %d  ",Table->TYPE_of_INITIAL_CONDITION);
		
		else if(argv[argcount][2]=='R') 
		  fprintf(fp, "-xR  %d  ",Table->RESCALING_INITIAL_TOTAL_POPULATION);
		
		else if(argv[argcount][2]=='N') 
		  fprintf(fp, "-xN  %g  ",Table->INITIAL_TOTAL_POPULATION);
	
		else if(argv[argcount][2]=='0') fprintf(fp, "-x0  %g  ",Table->n0S__0);
    
		else if(argv[argcount][2]=='1') {
		  if(argv[argcount][3]=='\0')     fprintf(fp, "-x1  %g  ",Table->n0E__0);
		  
		  else if(argv[argcount][3]=='0') fprintf(fp, "-x10  %g  ", Table->n1S__0); 
		  else if(argv[argcount][3]=='1') fprintf(fp, "-x11  %g  ", Table->n1E__0);
		  else if(argv[argcount][3]=='2') fprintf(fp, "-x12  %g  ", Table->n1I1__0);
		  else if(argv[argcount][3]=='3') fprintf(fp, "-x13  %g  ", Table->n1I2__0);
		  else if(argv[argcount][3]=='4') fprintf(fp, "-x14  %g  ", Table->n1A__0);
		  else if(argv[argcount][3]=='5') fprintf(fp, "-x15  %g  ", Table->n1Y__0);
		  else if(argv[argcount][3]=='6') fprintf(fp, "-x16  %g  ", Table->n1R__0);
		  else if(argv[argcount][3]=='7') fprintf(fp, "-x17  %g  ", Table->a1I__0);
		  else if(argv[argcount][3]=='8') fprintf(fp, "-x18  %g  ", Table->a1R__0); 
		  else if(argv[argcount][3]=='9') fprintf(fp, "-x19  %g  ", Table->a1D__0);
		  
		  else {
		    printf(" Error at reading input arguments:\n");
		    printf("-xn -xN -xR -x0 to -x39 are the only allowable keys. You have typed -  %s  ",
			   argv[argcount]);
		    exit(0);
		  }
		}
		else if(argv[argcount][2]=='2') {
		  if(argv[argcount][3]=='\0') 	   fprintf(fp, "-x2  %g  ",Table->n0I1__0);

		  else if(argv[argcount][3]=='0') fprintf(fp, "-x20  %g  ", Table->n2S__0); 
		  else if(argv[argcount][3]=='1') fprintf(fp, "-x21  %g  ", Table->n2E__0);
		  else if(argv[argcount][3]=='2') fprintf(fp, "-x22  %g  ", Table->n2I1__0);
		  else if(argv[argcount][3]=='3') fprintf(fp, "-x23  %g  ", Table->n2I2__0);
		  else if(argv[argcount][3]=='4') fprintf(fp, "-x24  %g  ", Table->n2A__0);
		  else if(argv[argcount][3]=='5') fprintf(fp, "-x25  %g  ", Table->n2Y__0);
		  else if(argv[argcount][3]=='6') fprintf(fp, "-x26  %g  ", Table->n2R__0);
		  else if(argv[argcount][3]=='7') fprintf(fp, "-x27  %g  ", Table->a2I__0);
		  else if(argv[argcount][3]=='8') fprintf(fp, "-x28  %g  ", Table->a2R__0); 
		  else if(argv[argcount][3]=='9') fprintf(fp, "-x29  %g  ", Table->a2D__0);
		  else {
		    printf(" Error at reading input arguments:\n");
		    printf("-xn -xN -xR -x0 to -x39 are the only allowable keys. You have typed -  %s  ",
			   argv[argcount]);
		    exit(0);
		  }
		}
		else if(argv[argcount][2]=='3') {
		  if(argv[argcount][3]=='\0')     fprintf(fp, "-x3  %g  ",Table->n0I2__0);

		  else if(argv[argcount][3]=='0') fprintf(fp, "-x30  %g  ", Table->n3S__0); 
		  else if(argv[argcount][3]=='1') fprintf(fp, "-x31  %g  ", Table->n3E__0);
		  else if(argv[argcount][3]=='2') fprintf(fp, "-x32  %g  ", Table->n3I1__0);
		  else if(argv[argcount][3]=='3') fprintf(fp, "-x33  %g  ", Table->n3I2__0);
		  else if(argv[argcount][3]=='4') fprintf(fp, "-x34  %g  ", Table->n3A__0);
		  else if(argv[argcount][3]=='5') fprintf(fp, "-x35  %g  ", Table->n3Y__0);
		  else if(argv[argcount][3]=='6') fprintf(fp, "-x36  %g  ", Table->n3R__0);
		  else if(argv[argcount][3]=='7') fprintf(fp, "-x37  %g  ", Table->a3I__0);
		  else if(argv[argcount][3]=='8') fprintf(fp, "-x38  %g  ", Table->a3R__0); 
		  else if(argv[argcount][3]=='9') fprintf(fp, "-x39  %g  ", Table->a3D__0);
		  else {
		    printf(" Error at reading input arguments:\n");
		    printf("-xn -xN -xR -x0 to -x39 are the only allowable keys. You have typed -  %s  ",
			   argv[argcount]);
		    exit(0);
		  }
		}  
		else if(argv[argcount][2]=='4')    fprintf(fp, "-x4  %g  ",Table->n0A__0);
		else if(argv[argcount][2]=='5')    fprintf(fp, "-x5  %g  ",Table->n0Y__0);
		else if(argv[argcount][2]=='6')    fprintf(fp, "-x6  %g  ",Table->n0R__0);
		else if(argv[argcount][2]=='7')    fprintf(fp, "-x7  %g  ",Table->a0I__0);
		else if(argv[argcount][2]=='8')    fprintf(fp, "-x8  %g  ",Table->a0R__0);
		else if(argv[argcount][2]=='9')    fprintf(fp, "-x9  %g  ",Table->a0D__0);
		else {
		    printf(" Error at reading input arguments:\n");
		    printf("-xn -xN -xR -x0 to -x39 are the only allowable keys. You have typed -  %s  ",
			   argv[argcount]);
		    exit(0);
		}
	      }
	      else {
		printf(" This TYPE_of_MODEL (-  %d  ) code is not defined.\n", TYPE_of_MODEL);
		printf("Check input argument list\n");
		exit(0);
	      }

        skip++;
        break;

	case 'i':
              if (TYPE_of_MODEL == 0 ) {
		
		if(argv[argcount][2]=='P')        fprintf(fp, "-iP  %d  ", Table->No_of_IC);
		
		else if(argv[argcount][2]=='0')    fprintf(fp, "-i0  %d  ",Table->IC_0);
		else if(argv[argcount][2]=='1')    fprintf(fp, "-i1  %d  ",Table->IC_1);
		else if(argv[argcount][2]=='2')    fprintf(fp, "-i2  %d  ",Table->IC_2);
		else if(argv[argcount][2]=='3')    fprintf(fp, "-i3  %d  ",Table->IC_3);
		else if(argv[argcount][2]=='4')    fprintf(fp, "-i4  %d  ",Table->IC_4);
		else if(argv[argcount][2]=='5')    fprintf(fp, "-i5  %d  ",Table->IC_5);
		else if(argv[argcount][2]=='6')    fprintf(fp, "-i6  %d  ",Table->IC_6);
		else if(argv[argcount][2]=='7')    fprintf(fp, "-i7  %d  ",Table->IC_7);
		else if(argv[argcount][2]=='8')    fprintf(fp, "-i8  %d  ",Table->IC_8);
		else if(argv[argcount][2]=='9')    fprintf(fp, "-i9  %d  ",Table->IC_9);
		
		else{
		  printf("-iP -i0 to -i9 are the only allowable keys.\n");
		  printf("Something goes very wrong (in an argumentfprintf function)\n");
		  exit(0);
		}
		
	      }
              else if (TYPE_of_MODEL == 1 ) {
		if(argv[argcount][2]=='P')        fprintf(fp, "-iP  %d  ", Table->No_of_IC);

		else if (argv[argcount][2]=='0')  fprintf(fp, "-i0  %d  ", Table->IC_0);

		else if(argv[argcount][2]=='1') {
		  if(argv[argcount][3]=='\0')     fprintf(fp, "-i1  %d  ",Table->IC_1);
		  
		  else if(argv[argcount][3]=='0') fprintf(fp, "-i10  %d  ", Table->IC_10);
		  else if(argv[argcount][3]=='1') fprintf(fp, "-i11  %d  ", Table->IC_11);
		  else if(argv[argcount][3]=='2') fprintf(fp, "-i12  %d  ", Table->IC_12);
		  else if(argv[argcount][3]=='3') fprintf(fp, "-i13  %d  ", Table->IC_13);
		  else if(argv[argcount][3]=='4') fprintf(fp, "-i14  %d  ", Table->IC_14);
		  else if(argv[argcount][3]=='5') fprintf(fp, "-i15  %d  ", Table->IC_15);
		  else if(argv[argcount][3]=='6') fprintf(fp, "-i16  %d  ", Table->IC_16);
		  else if(argv[argcount][3]=='7') fprintf(fp, "-i17  %d  ", Table->IC_17);
		  else if(argv[argcount][3]=='8') fprintf(fp, "-i18  %d  ", Table->IC_18);
		  else if(argv[argcount][3]=='9') fprintf(fp, "-i19  %d  ", Table->IC_19);
		  
		  else {
		    printf("-iP -i0 to -i39 are the only allowable keys.\n");
		    printf("Something goes very wrong (in an argumentfprintf function)\n");
		    exit(0);
		  }
		}
		else if(argv[argcount][2]=='2') {
		  if(argv[argcount][3]=='\0') 	   fprintf(fp, "-i2  %d  ",Table->IC_2);

		  else if(argv[argcount][3]=='0') fprintf(fp, "-i20  %d  ", Table->IC_20);
		  else if(argv[argcount][3]=='1') fprintf(fp, "-i21  %d  ", Table->IC_21);
		  else if(argv[argcount][3]=='2') fprintf(fp, "-i22  %d  ", Table->IC_22);
		  else if(argv[argcount][3]=='3') fprintf(fp, "-i23  %d  ", Table->IC_23);
		  else if(argv[argcount][3]=='4') fprintf(fp, "-i24  %d  ", Table->IC_24);
		  else if(argv[argcount][3]=='5') fprintf(fp, "-i25  %d  ", Table->IC_25);
		  else if(argv[argcount][3]=='6') fprintf(fp, "-i26  %d  ", Table->IC_26);
		  else if(argv[argcount][3]=='7') fprintf(fp, "-i27  %d  ", Table->IC_27);
		  else if(argv[argcount][3]=='8') fprintf(fp, "-i28  %d  ", Table->IC_28);
		  else if(argv[argcount][3]=='9') fprintf(fp, "-i29  %d  ", Table->IC_29);
		  
		  else {
		    printf(" Error at reading input arguments:\n");
		    printf("-iP -i0 to -i39 are the only allowable keys. You have typed -  %s  ",
			   argv[argcount]);
		    exit(0);
		  }
		}
		else if(argv[argcount][2]=='3') {
		  if(argv[argcount][3]=='\0')     fprintf(fp, "-i3  %d  ",Table->IC_3);

		  else if(argv[argcount][3]=='0') fprintf(fp, "-i30  %d  ", Table->IC_30);
		  else if(argv[argcount][3]=='1') fprintf(fp, "-i31  %d  ", Table->IC_31);
		  else if(argv[argcount][3]=='2') fprintf(fp, "-i32  %d  ", Table->IC_32);
		  else if(argv[argcount][3]=='3') fprintf(fp, "-i33  %d  ", Table->IC_33);
		  else if(argv[argcount][3]=='4') fprintf(fp, "-i34  %d  ", Table->IC_34);
		  else if(argv[argcount][3]=='5') fprintf(fp, "-i35  %d  ", Table->IC_35);
		  else if(argv[argcount][3]=='6') fprintf(fp, "-i36  %d  ", Table->IC_36);
		  else if(argv[argcount][3]=='7') fprintf(fp, "-i37  %d  ", Table->IC_37);
		  else if(argv[argcount][3]=='8') fprintf(fp, "-i38  %d  ", Table->IC_38);
		  else if(argv[argcount][3]=='9') fprintf(fp, "-i39  %d  ", Table->IC_39);
		  else {
		    printf(" Error at reading input arguments:\n");
		    printf("-iP -i0 to -i39 are the only allowable keys. You have typed -  %s  ",
			   argv[argcount]);
		    exit(0);
		  }
		}
		
		else if(argv[argcount][2]=='4')    fprintf(fp, "-i4  %d  ",Table->IC_4);
		else if(argv[argcount][2]=='5')    fprintf(fp, "-i5  %d  ",Table->IC_5);
		else if(argv[argcount][2]=='6')    fprintf(fp, "-i6  %d  ",Table->IC_6);
		else if(argv[argcount][2]=='7')    fprintf(fp, "-i7  %d  ",Table->IC_7);
		else if(argv[argcount][2]=='8')    fprintf(fp, "-i8  %d  ",Table->IC_8);
		else if(argv[argcount][2]=='9')    fprintf(fp, "-i9  %d  ",Table->IC_9);
		else {
		  printf(" Error at reading input arguments:\n");
		  printf("-iP -i0 to -i39 are the only allowable keys. You have typed -  %s  ",
			   argv[argcount]);
		  exit(0);
		}
	      }
              else {
		printf(" This TYPE_of_MODEL (-  %d  ) code is not defined.\n", TYPE_of_MODEL);
		printf("Check input argument list\n");
		exit(0);
	      }
		
        skip++;
        break;

        case 'u': //Minimum values 
              if (TYPE_of_MODEL == 0 ) {
		
		if(argv[argcount][2]=='0')         fprintf(fp, "-u0  %g  ", Table->IC_min_0);
		else if(argv[argcount][2]=='1')    fprintf(fp, "-u1  %g  ",Table->IC_min_1);
		else if(argv[argcount][2]=='2')    fprintf(fp, "-u2  %g  ",Table->IC_min_2);
		else if(argv[argcount][2]=='3')    fprintf(fp, "-u3  %g  ",Table->IC_min_3);
		else if(argv[argcount][2]=='4')    fprintf(fp, "-u4  %g  ",Table->IC_min_4);
		else if(argv[argcount][2]=='5')    fprintf(fp, "-u5  %g  ",Table->IC_min_5);
		else if(argv[argcount][2]=='6')    fprintf(fp, "-u6  %g  ",Table->IC_min_6);
		else if(argv[argcount][2]=='7')    fprintf(fp, "-u7  %g  ",Table->IC_min_7);
		else if(argv[argcount][2]=='8')    fprintf(fp, "-u8  %g  ",Table->IC_min_8);
		else if(argv[argcount][2]=='9')    fprintf(fp, "-u9  %g  ",Table->IC_min_9);
		
		else{
		  printf("-u0 to -u9 are the only allowable keys.\n");
		  printf("Something goes very wrong (in an argumentfprintf function)\n");
		  exit(0);
		}
		
	      }
              else if (TYPE_of_MODEL == 1 ) {
		if (argv[argcount][2]=='0')  fprintf(fp, "-u0  %g  ", Table->IC_min_0);

		else if(argv[argcount][2]=='1') {
		  if(argv[argcount][3]=='\0')     fprintf(fp, "-u1  %g  ",Table->IC_min_1);
		  
		  else if(argv[argcount][3]=='0') fprintf(fp, "-u10  %g  ", Table->IC_min_10);
		  else if(argv[argcount][3]=='1') fprintf(fp, "-u11  %g  ", Table->IC_min_11);
		  else if(argv[argcount][3]=='2') fprintf(fp, "-u12  %g  ", Table->IC_min_12);
		  else if(argv[argcount][3]=='3') fprintf(fp, "-u13  %g  ", Table->IC_min_13);
		  else if(argv[argcount][3]=='4') fprintf(fp, "-u14  %g  ", Table->IC_min_14);
		  else if(argv[argcount][3]=='5') fprintf(fp, "-u15  %g  ", Table->IC_min_15);
		  else if(argv[argcount][3]=='6') fprintf(fp, "-u16  %g  ", Table->IC_min_16);
		  else if(argv[argcount][3]=='7') fprintf(fp, "-u17  %g  ", Table->IC_min_17);
		  else if(argv[argcount][3]=='8') fprintf(fp, "-u18  %g  ", Table->IC_min_18);
		  else if(argv[argcount][3]=='9') fprintf(fp, "-u19  %g  ", Table->IC_min_19);
		  
		  else {
		    printf("-u0 to -u39 are the only allowable keys.\n");
		    printf("Something goes very wrong (in an argumentfprintf function)\n");
		    exit(0);
		  }
		}
		else if(argv[argcount][2]=='2') {
		  if(argv[argcount][3]=='\0') 	   fprintf(fp, "-u2  %g  ",Table->IC_min_2);

		  else if(argv[argcount][3]=='0') fprintf(fp, "-u20  %g  ", Table->IC_min_20);
		  else if(argv[argcount][3]=='1') fprintf(fp, "-u21  %g  ", Table->IC_min_21);
		  else if(argv[argcount][3]=='2') fprintf(fp, "-u22  %g  ", Table->IC_min_22);
		  else if(argv[argcount][3]=='3') fprintf(fp, "-u23  %g  ", Table->IC_min_23);
		  else if(argv[argcount][3]=='4') fprintf(fp, "-u24  %g  ", Table->IC_min_24);
		  else if(argv[argcount][3]=='5') fprintf(fp, "-u25  %g  ", Table->IC_min_25);
		  else if(argv[argcount][3]=='6') fprintf(fp, "-u26  %g  ", Table->IC_min_26);
		  else if(argv[argcount][3]=='7') fprintf(fp, "-u27  %g  ", Table->IC_min_27);
		  else if(argv[argcount][3]=='8') fprintf(fp, "-u28  %g  ", Table->IC_min_28);
		  else if(argv[argcount][3]=='9') fprintf(fp, "-u29  %g  ", Table->IC_min_29);
		  
		  else {
		    printf(" Error at reading input arguments:\n");
		    printf("-u0 to -u39 are the only allowable keys. You have typed -  %s  ",
			   argv[argcount]);
		    exit(0);
		  }
		}
		else if(argv[argcount][2]=='3') {
		  if(argv[argcount][3]=='\0')     fprintf(fp, "-u3  %g  ",Table->IC_min_3);

		  else if(argv[argcount][3]=='0') fprintf(fp, "-u30  %g  ", Table->IC_min_30);
		  else if(argv[argcount][3]=='1') fprintf(fp, "-u31  %g  ", Table->IC_min_31);
		  else if(argv[argcount][3]=='2') fprintf(fp, "-u32  %g  ", Table->IC_min_32);
		  else if(argv[argcount][3]=='3') fprintf(fp, "-u33  %g  ", Table->IC_min_33);
		  else if(argv[argcount][3]=='4') fprintf(fp, "-u34  %g  ", Table->IC_min_34);
		  else if(argv[argcount][3]=='5') fprintf(fp, "-u35  %g  ", Table->IC_min_35);
		  else if(argv[argcount][3]=='6') fprintf(fp, "-u36  %g  ", Table->IC_min_36);
		  else if(argv[argcount][3]=='7') fprintf(fp, "-u37  %g  ", Table->IC_min_37);
		  else if(argv[argcount][3]=='8') fprintf(fp, "-u38  %g  ", Table->IC_min_38);
		  else if(argv[argcount][3]=='9') fprintf(fp, "-u39  %g  ", Table->IC_min_39);
		  else {
		    printf(" Error at reading input arguments:\n");
		    printf("-u0 to -u39 are the only allowable keys. You have typed -  %s  ",
			   argv[argcount]);
		    exit(0);
		  }
		}
		
		else if(argv[argcount][2]=='4')    fprintf(fp, "-u4  %g  ",Table->IC_min_4);
		else if(argv[argcount][2]=='5')    fprintf(fp, "-u5  %g  ",Table->IC_min_5);
		else if(argv[argcount][2]=='6')    fprintf(fp, "-u6  %g  ",Table->IC_min_6);
		else if(argv[argcount][2]=='7')    fprintf(fp, "-u7  %g  ",Table->IC_min_7);
		else if(argv[argcount][2]=='8')    fprintf(fp, "-u8  %g  ",Table->IC_min_8);
		else if(argv[argcount][2]=='9')    fprintf(fp, "-u9  %g  ",Table->IC_min_9);
		else {
		  printf(" Error at reading input arguments:\n");
		  printf("-u0 to -u39 are the only allowable keys. You have typed -  %s  ",
			   argv[argcount]);
		  exit(0);
		}
	      }
              else {
		printf(" This TYPE_of_MODEL (-  %d  ) code is not defined.\n", TYPE_of_MODEL);
		printf("Check input argument list\n");
		exit(0);
	      }

        skip++;
        break;

        case 'U':  //Maximum values

                if (TYPE_of_MODEL == 0 ) {
		
		  if(argv[argcount][2]=='0')         fprintf(fp, "-U0  %g  ", Table->IC_MAX_0);
		  else if(argv[argcount][2]=='1')    fprintf(fp, "-U1  %g  ",Table->IC_MAX_1);
		  else if(argv[argcount][2]=='2')    fprintf(fp, "-U2  %g  ",Table->IC_MAX_2);
		  else if(argv[argcount][2]=='3')    fprintf(fp, "-U3  %g  ",Table->IC_MAX_3);
		  else if(argv[argcount][2]=='4')    fprintf(fp, "-U4  %g  ",Table->IC_MAX_4);
		  else if(argv[argcount][2]=='5')    fprintf(fp, "-U5  %g  ",Table->IC_MAX_5);
		  else if(argv[argcount][2]=='6')    fprintf(fp, "-U6  %g  ",Table->IC_MAX_6);
		  else if(argv[argcount][2]=='7')    fprintf(fp, "-U7  %g  ",Table->IC_MAX_7);
		  else if(argv[argcount][2]=='8')    fprintf(fp, "-U7  %g  ",Table->IC_MAX_8);
		  else if(argv[argcount][2]=='9')    fprintf(fp, "-U8  %g  ",Table->IC_MAX_9);
		
		else{
		  printf("-U0 to -U9 are the only allowable keys.\n");
		  printf("Something goes very wrong (in an argumentfprintf function)\n");
		  exit(0);
		}
		
	      }
              else if (TYPE_of_MODEL == 1 ) {
		
		if (argv[argcount][2]=='0')  fprintf(fp, "-U0  %g  ", Table->IC_MAX_0);

		else if(argv[argcount][2]=='1') {
		  if(argv[argcount][3]=='\0')     fprintf(fp, "-U1  %g  ",Table->IC_MAX_1);
		  
		  else if(argv[argcount][3]=='0') fprintf(fp, "-U10  %g  ", Table->IC_MAX_10);
		  else if(argv[argcount][3]=='1') fprintf(fp, "-U11  %g  ", Table->IC_MAX_11);
		  else if(argv[argcount][3]=='2') fprintf(fp, "-U12  %g  ", Table->IC_MAX_12);
		  else if(argv[argcount][3]=='3') fprintf(fp, "-U13  %g  ", Table->IC_MAX_13);
		  else if(argv[argcount][3]=='4') fprintf(fp, "-U14  %g  ", Table->IC_MAX_14);
		  else if(argv[argcount][3]=='5') fprintf(fp, "-U15  %g  ", Table->IC_MAX_15);
		  else if(argv[argcount][3]=='6') fprintf(fp, "-U16  %g  ", Table->IC_MAX_16);
		  else if(argv[argcount][3]=='7') fprintf(fp, "-U17  %g  ", Table->IC_MAX_17);
		  else if(argv[argcount][3]=='8') fprintf(fp, "-U18  %g  ", Table->IC_MAX_18);
		  else if(argv[argcount][3]=='9') fprintf(fp, "-U19  %g  ", Table->IC_MAX_19);
		  
		  else {
		    printf("-U0 to -U39 are the only allowable keys.\n");
		    printf("Something goes very wrong (in an argumentfprintf function)\n");
		    exit(0);
		  }
		}
		else if(argv[argcount][2]=='2') {
		  if(argv[argcount][3]=='\0') 	   fprintf(fp, "-U2  %g  ",Table->IC_MAX_2);

		  else if(argv[argcount][3]=='0') fprintf(fp, "-U20  %g  ", Table->IC_MAX_20);
		  else if(argv[argcount][3]=='1') fprintf(fp, "-U21  %g  ", Table->IC_MAX_21);
		  else if(argv[argcount][3]=='2') fprintf(fp, "-U22  %g  ", Table->IC_MAX_22);
		  else if(argv[argcount][3]=='3') fprintf(fp, "-U23  %g  ", Table->IC_MAX_23);
		  else if(argv[argcount][3]=='4') fprintf(fp, "-U24  %g  ", Table->IC_MAX_24);
		  else if(argv[argcount][3]=='5') fprintf(fp, "-U25  %g  ", Table->IC_MAX_25);
		  else if(argv[argcount][3]=='6') fprintf(fp, "-U26  %g  ", Table->IC_MAX_26);
		  else if(argv[argcount][3]=='7') fprintf(fp, "-U27  %g  ", Table->IC_MAX_27);
		  else if(argv[argcount][3]=='8') fprintf(fp, "-U28  %g  ", Table->IC_MAX_28);
		  else if(argv[argcount][3]=='9') fprintf(fp, "-U29  %g  ", Table->IC_MAX_29);
		  
		  else {
		    printf(" Error at reading input arguments:\n");
		    printf("-U0 to -U39 are the only allowable keys. You have typed -  %s  ",
			   argv[argcount]);
		    exit(0);
		  }
		}
		else if(argv[argcount][2]=='3') {
		  if(argv[argcount][3]=='\0')     fprintf(fp, "-U3  %g  ",Table->IC_MAX_3);

		  else if(argv[argcount][3]=='0') fprintf(fp, "-U30  %g  ", Table->IC_MAX_30);
		  else if(argv[argcount][3]=='1') fprintf(fp, "-U31  %g  ", Table->IC_MAX_31);
		  else if(argv[argcount][3]=='2') fprintf(fp, "-U32  %g  ", Table->IC_MAX_32);
		  else if(argv[argcount][3]=='3') fprintf(fp, "-U33  %g  ", Table->IC_MAX_33);
		  else if(argv[argcount][3]=='4') fprintf(fp, "-U34  %g  ", Table->IC_MAX_34);
		  else if(argv[argcount][3]=='5') fprintf(fp, "-U35  %g  ", Table->IC_MAX_35);
		  else if(argv[argcount][3]=='6') fprintf(fp, "-U36  %g  ", Table->IC_MAX_36);
		  else if(argv[argcount][3]=='7') fprintf(fp, "-U37  %g  ", Table->IC_MAX_37);
		  else if(argv[argcount][3]=='8') fprintf(fp, "-U38  %g  ", Table->IC_MAX_38);
		  else if(argv[argcount][3]=='9') fprintf(fp, "-U39  %g  ", Table->IC_MAX_39);
		  else {
		    printf(" Error at reading input arguments:\n");
		    printf("-U0 to -U39 are the only allowable keys. You have typed -  %s  ",
			   argv[argcount]);
		    exit(0);
		  }
		}
		
		else if(argv[argcount][2]=='4')    fprintf(fp, "-U4  %g  ",Table->IC_MAX_4);
		else if(argv[argcount][2]=='5')    fprintf(fp, "-U5  %g  ",Table->IC_MAX_5);
		else if(argv[argcount][2]=='6')    fprintf(fp, "-U6  %g  ",Table->IC_MAX_6);
		else if(argv[argcount][2]=='7')    fprintf(fp, "-U7  %g  ",Table->IC_MAX_7);
		else if(argv[argcount][2]=='8')    fprintf(fp, "-U8  %g  ",Table->IC_MAX_8);
		else if(argv[argcount][2]=='9')    fprintf(fp, "-U9  %g  ",Table->IC_MAX_9);
		else {
		  printf(" Error at reading input arguments:\n");
		  printf("-U0 to -U39 are the only allowable keys. You have typed -  %s  ",
			   argv[argcount]);
		  exit(0);
		}
	      }
              else {
		printf(" This TYPE_of_MODEL (-  %d  ) code is not defined.\n", TYPE_of_MODEL);
		printf("Check input argument list\n");
		exit(0);
	      }

        skip++;
        break;


