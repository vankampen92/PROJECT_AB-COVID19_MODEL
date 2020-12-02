/* Scan Parameters */
 
/* Initial Conditions */
	case 'x':
              if (TYPE_of_MODEL == 0 ) {  

		if(argv[argcount][2]=='n') 
		sscanf(argv[argcount+1], "%d",&TYPE_of_INITIAL_CONDITION);
		
		else if(argv[argcount][2]=='R') 
		  sscanf(argv[argcount+1], "%d",&RESCALING_INITIAL_TOTAL_POPULATION);
		
		else if(argv[argcount][2]=='N') 
		  sscanf(argv[argcount+1], "%lf",&INITIAL_TOTAL_POPULATION);
		
		else if(argv[argcount][2]=='0') sscanf(argv[argcount+1], "%lf",&nS__0);
		else if(argv[argcount][2]=='1')    sscanf(argv[argcount+1], "%lf",&nE__0);
		else if(argv[argcount][2]=='2')    sscanf(argv[argcount+1], "%lf",&nI1__0);
		else if(argv[argcount][2]=='3')    sscanf(argv[argcount+1], "%lf",&nI2__0);
		else if(argv[argcount][2]=='4')    sscanf(argv[argcount+1], "%lf",&nA__0);
		else if(argv[argcount][2]=='5')    sscanf(argv[argcount+1], "%lf",&nY__0);
		else if(argv[argcount][2]=='6')    sscanf(argv[argcount+1], "%lf",&nR__0);
		else if(argv[argcount][2]=='7')    sscanf(argv[argcount+1], "%lf",&aI__0);
		else if(argv[argcount][2]=='8')    sscanf(argv[argcount+1], "%lf",&aR__0);
		else if(argv[argcount][2]=='9')    sscanf(argv[argcount+1], "%lf",&aD__0);
		
		else{
		  printf("xn -xN -xR -x0 to -x9 are the only allowable keys.\n");
		  printf("Something goes very wrong (in an argumentsscanf function)\n");
		  exit(0);
		}
		
	      }
              else if (TYPE_of_MODEL > 0 ) {

		if(argv[argcount][2]=='n') 
		sscanf(argv[argcount+1], "%d",&TYPE_of_INITIAL_CONDITION);
		
		else if(argv[argcount][2]=='R') 
		  sscanf(argv[argcount+1], "%d",&RESCALING_INITIAL_TOTAL_POPULATION);
		
		else if(argv[argcount][2]=='N') 
		  sscanf(argv[argcount+1], "%lf",&INITIAL_TOTAL_POPULATION);
	
		else if(argv[argcount][2]=='0') sscanf(argv[argcount+1], "%lf", &n0S__0);
    
		else if(argv[argcount][2]=='1') {
		  if(argv[argcount][3]=='\0')     sscanf(argv[argcount+1], "%lf",&n0E__0);
		  
		  else if(argv[argcount][3]=='0') sscanf(argv[argcount+1], "%lf", &n1S__0); 
		  else if(argv[argcount][3]=='1') sscanf(argv[argcount+1], "%lf", &n1E__0);
		  else if(argv[argcount][3]=='2') sscanf(argv[argcount+1], "%lf", &n1I1__0);
		  else if(argv[argcount][3]=='3') sscanf(argv[argcount+1], "%lf", &n1I2__0);
		  else if(argv[argcount][3]=='4') sscanf(argv[argcount+1], "%lf", &n1A__0);
		  else if(argv[argcount][3]=='5') sscanf(argv[argcount+1], "%lf", &n1Y__0);
		  else if(argv[argcount][3]=='6') sscanf(argv[argcount+1], "%lf", &n1R__0);
		  else if(argv[argcount][3]=='7') sscanf(argv[argcount+1], "%lf", &a1I__0);
		  else if(argv[argcount][3]=='8') sscanf(argv[argcount+1], "%lf", &a1R__0); 
		  else if(argv[argcount][3]=='9') sscanf(argv[argcount+1], "%lf", &a1D__0);
		  
		  else {
		    printf(" Error at reading input arguments:\n");
		    printf("-xn -xN -xR -x0 to -x39 are the only allowable keys. You have typed %s",
			   argv[argcount]);
		    exit(0);
		  }
		}
		else if(argv[argcount][2]=='2') {
		  if(argv[argcount][3]=='\0') 	   sscanf(argv[argcount+1], "%lf",&n0I1__0);

		  else if(argv[argcount][3]=='0') sscanf(argv[argcount+1], "%lf", &n2S__0); 
		  else if(argv[argcount][3]=='1') sscanf(argv[argcount+1], "%lf", &n2E__0);
		  else if(argv[argcount][3]=='2') sscanf(argv[argcount+1], "%lf", &n2I1__0);
		  else if(argv[argcount][3]=='3') sscanf(argv[argcount+1], "%lf", &n2I2__0);
		  else if(argv[argcount][3]=='4') sscanf(argv[argcount+1], "%lf", &n2A__0);
		  else if(argv[argcount][3]=='5') sscanf(argv[argcount+1], "%lf", &n2Y__0);
		  else if(argv[argcount][3]=='6') sscanf(argv[argcount+1], "%lf", &n2R__0);
		  else if(argv[argcount][3]=='7') sscanf(argv[argcount+1], "%lf", &a2I__0);
		  else if(argv[argcount][3]=='8') sscanf(argv[argcount+1], "%lf", &a2R__0); 
		  else if(argv[argcount][3]=='9') sscanf(argv[argcount+1], "%lf", &a2D__0);
		  else {
		    printf(" Error at reading input arguments:\n");
		    printf("-xn -xN -xR -x0 to -x39 are the only allowable keys. You have typed %s",
			   argv[argcount]);
		    exit(0);
		  }
		}
		else if(argv[argcount][2]=='3') {
		  if(argv[argcount][3]=='\0')     sscanf(argv[argcount+1], "%lf",&n0I2__0);

		  else if(argv[argcount][3]=='0') sscanf(argv[argcount+1], "%lf", &n3S__0); 
		  else if(argv[argcount][3]=='1') sscanf(argv[argcount+1], "%lf", &n3E__0);
		  else if(argv[argcount][3]=='2') sscanf(argv[argcount+1], "%lf", &n3I1__0);
		  else if(argv[argcount][3]=='3') sscanf(argv[argcount+1], "%lf", &n3I2__0);
		  else if(argv[argcount][3]=='4') sscanf(argv[argcount+1], "%lf", &n3A__0);
		  else if(argv[argcount][3]=='5') sscanf(argv[argcount+1], "%lf", &n3Y__0);
		  else if(argv[argcount][3]=='6') sscanf(argv[argcount+1], "%lf", &n3R__0);
		  else if(argv[argcount][3]=='7') sscanf(argv[argcount+1], "%lf", &a3I__0);
		  else if(argv[argcount][3]=='8') sscanf(argv[argcount+1], "%lf", &a3R__0); 
		  else if(argv[argcount][3]=='9') sscanf(argv[argcount+1], "%lf", &a3D__0);
		  else {
		    printf(" Error at reading input arguments:\n");
		    printf("-xn -xN -xR -x0 to -x39 are the only allowable keys. You have typed %s",
			   argv[argcount]);
		    exit(0);
		  }
		}  
		else if(argv[argcount][2]=='4')    sscanf(argv[argcount+1], "%lf",&n0A__0);
		else if(argv[argcount][2]=='5')    sscanf(argv[argcount+1], "%lf",&n0Y__0);
		else if(argv[argcount][2]=='6')    sscanf(argv[argcount+1], "%lf",&n0R__0);
		else if(argv[argcount][2]=='7')    sscanf(argv[argcount+1], "%lf",&a0I__0);
		else if(argv[argcount][2]=='8')    sscanf(argv[argcount+1], "%lf",&a0R__0);
		else if(argv[argcount][2]=='9')    sscanf(argv[argcount+1], "%lf",&a0D__0);
		else {
		    printf(" Error at reading input arguments:\n");
		    printf("-xn -xN -xR -x0 to -x39 are the only allowable keys. You have typed %s",
			   argv[argcount]);
		    exit(0);
		}
	      }
	      else {
		printf(" This TYPE_of_MODEL (%d) code is not defined.\n", TYPE_of_MODEL);
		printf("Check input argument list\n");
		exit(0);
	      }

        skip++;
        break;

	case 'i':
              if (TYPE_of_MODEL == 0 ) {
		
		if(argv[argcount][2]=='P')        sscanf(argv[argcount+1], "%d", &No_of_IC);
		
		else if(argv[argcount][2]=='0')    sscanf(argv[argcount+1], "%d", &IC_0);
		else if(argv[argcount][2]=='1')    sscanf(argv[argcount+1], "%d",&IC_1);
		else if(argv[argcount][2]=='2')    sscanf(argv[argcount+1], "%d",&IC_2);
		else if(argv[argcount][2]=='3')    sscanf(argv[argcount+1], "%d",&IC_3);
		else if(argv[argcount][2]=='4')    sscanf(argv[argcount+1], "%d",&IC_4);
		else if(argv[argcount][2]=='5')    sscanf(argv[argcount+1], "%d",&IC_5);
		else if(argv[argcount][2]=='6')    sscanf(argv[argcount+1], "%d",&IC_6);
		else if(argv[argcount][2]=='7')    sscanf(argv[argcount+1], "%d",&IC_7);
		else if(argv[argcount][2]=='8')    sscanf(argv[argcount+1], "%d",&IC_8);
		else if(argv[argcount][2]=='9')    sscanf(argv[argcount+1], "%d",&IC_9);
		
		else{
		  printf("-iP -i0 to -i9 are the only allowable keys.\n");
		  printf("Something goes very wrong (in an argumentsscanf function)\n");
		  exit(0);
		}
		
	      }
              else if (TYPE_of_MODEL > 0 ) {
		if(argv[argcount][2]=='P')        sscanf(argv[argcount+1], "%d", &No_of_IC);

		else if (argv[argcount][2]=='0')  sscanf(argv[argcount+1], "%d", &IC_0);

		else if(argv[argcount][2]=='1') {
		  if(argv[argcount][3]=='\0')     sscanf(argv[argcount+1], "%d",&IC_1);
		  
		  else if(argv[argcount][3]=='0') sscanf(argv[argcount+1], "%d", &IC_10);
		  else if(argv[argcount][3]=='1') sscanf(argv[argcount+1], "%d", &IC_11);
		  else if(argv[argcount][3]=='2') sscanf(argv[argcount+1], "%d", &IC_12);
		  else if(argv[argcount][3]=='3') sscanf(argv[argcount+1], "%d", &IC_13);
		  else if(argv[argcount][3]=='4') sscanf(argv[argcount+1], "%d", &IC_14);
		  else if(argv[argcount][3]=='5') sscanf(argv[argcount+1], "%d", &IC_15);
		  else if(argv[argcount][3]=='6') sscanf(argv[argcount+1], "%d", &IC_16);
		  else if(argv[argcount][3]=='7') sscanf(argv[argcount+1], "%d", &IC_17);
		  else if(argv[argcount][3]=='8') sscanf(argv[argcount+1], "%d", &IC_18);
		  else if(argv[argcount][3]=='9') sscanf(argv[argcount+1], "%d", &IC_19);
		  
		  else {
		    printf("-iP -i0 to -i39 are the only allowable keys.\n");
		    printf("Something goes very wrong (in an argumentsscanf function)\n");
		    exit(0);
		  }
		}
		else if(argv[argcount][2]=='2') {
		  if(argv[argcount][3]=='\0') 	   sscanf(argv[argcount+1], "%d",&IC_2);

		  else if(argv[argcount][3]=='0') sscanf(argv[argcount+1], "%d", &IC_20);
		  else if(argv[argcount][3]=='1') sscanf(argv[argcount+1], "%d", &IC_21);
		  else if(argv[argcount][3]=='2') sscanf(argv[argcount+1], "%d", &IC_22);
		  else if(argv[argcount][3]=='3') sscanf(argv[argcount+1], "%d", &IC_23);
		  else if(argv[argcount][3]=='4') sscanf(argv[argcount+1], "%d", &IC_24);
		  else if(argv[argcount][3]=='5') sscanf(argv[argcount+1], "%d", &IC_25);
		  else if(argv[argcount][3]=='6') sscanf(argv[argcount+1], "%d", &IC_26);
		  else if(argv[argcount][3]=='7') sscanf(argv[argcount+1], "%d", &IC_27);
		  else if(argv[argcount][3]=='8') sscanf(argv[argcount+1], "%d", &IC_28);
		  else if(argv[argcount][3]=='9') sscanf(argv[argcount+1], "%d", &IC_29);
		  
		  else {
		    printf(" Error at reading input arguments:\n");
		    printf("-iP -i0 to -i39 are the only allowable keys. You have typed %s",
			   argv[argcount]);
		    exit(0);
		  }
		}
		else if(argv[argcount][2]=='3') {
		  if(argv[argcount][3]=='\0')     sscanf(argv[argcount+1], "%d",&IC_3);

		  else if(argv[argcount][3]=='0') sscanf(argv[argcount+1], "%d", &IC_30);
		  else if(argv[argcount][3]=='1') sscanf(argv[argcount+1], "%d", &IC_31);
		  else if(argv[argcount][3]=='2') sscanf(argv[argcount+1], "%d", &IC_32);
		  else if(argv[argcount][3]=='3') sscanf(argv[argcount+1], "%d", &IC_33);
		  else if(argv[argcount][3]=='4') sscanf(argv[argcount+1], "%d", &IC_34);
		  else if(argv[argcount][3]=='5') sscanf(argv[argcount+1], "%d", &IC_35);
		  else if(argv[argcount][3]=='6') sscanf(argv[argcount+1], "%d", &IC_36);
		  else if(argv[argcount][3]=='7') sscanf(argv[argcount+1], "%d", &IC_37);
		  else if(argv[argcount][3]=='8') sscanf(argv[argcount+1], "%d", &IC_38);
		  else if(argv[argcount][3]=='9') sscanf(argv[argcount+1], "%d", &IC_39);
		  else {
		    printf(" Error at reading input arguments:\n");
		    printf("-iP -i0 to -i39 are the only allowable keys. You have typed %s",
			   argv[argcount]);
		    exit(0);
		  }
		}
		
		else if(argv[argcount][2]=='4')    sscanf(argv[argcount+1], "%d",&IC_4);
		else if(argv[argcount][2]=='5')    sscanf(argv[argcount+1], "%d",&IC_5);
		else if(argv[argcount][2]=='6')    sscanf(argv[argcount+1], "%d",&IC_6);
		else if(argv[argcount][2]=='7')    sscanf(argv[argcount+1], "%d",&IC_7);
		else if(argv[argcount][2]=='8')    sscanf(argv[argcount+1], "%d",&IC_8);
		else if(argv[argcount][2]=='9')    sscanf(argv[argcount+1], "%d",&IC_9);
		else {
		  printf(" Error at reading input arguments:\n");
		  printf("-iP -i0 to -i39 are the only allowable keys. You have typed %s",
			   argv[argcount]);
		  exit(0);
		}
	      }
              else {
		printf(" This TYPE_of_MODEL (%d) code is not defined.\n", TYPE_of_MODEL);
		printf("Check input argument list\n");
		exit(0);
	      }
		
        skip++;
        break;

        case 'u': //Minimum values 
              if (TYPE_of_MODEL == 0 ) {
		
		if(argv[argcount][2]=='0')  sscanf(argv[argcount+1], "%lf", &IC_min_0);
		
		else if(argv[argcount][2]=='1')    sscanf(argv[argcount+1], "%lf",&IC_min_1);
		else if(argv[argcount][2]=='2')    sscanf(argv[argcount+1], "%lf",&IC_min_2);
		else if(argv[argcount][2]=='3')    sscanf(argv[argcount+1], "%lf",&IC_min_3);
		else if(argv[argcount][2]=='4')    sscanf(argv[argcount+1], "%lf",&IC_min_4);
		else if(argv[argcount][2]=='5')    sscanf(argv[argcount+1], "%lf",&IC_min_5);
		else if(argv[argcount][2]=='6')    sscanf(argv[argcount+1], "%lf",&IC_min_6);
		else if(argv[argcount][2]=='7')    sscanf(argv[argcount+1], "%lf",&IC_min_7);
		else if(argv[argcount][2]=='8')    sscanf(argv[argcount+1], "%lf",&IC_min_8);
		else if(argv[argcount][2]=='9')    sscanf(argv[argcount+1], "%lf",&IC_min_9);
		
		else{
		  printf("-u0 to -u39 are the only allowable keys.\n");
		  printf("Something goes very wrong (in an argumentsscanf function)\n");
		  exit(0);
		}
		
	      }
              else if (TYPE_of_MODEL > 0 ) {
		if (argv[argcount][2]=='0')  sscanf(argv[argcount+1], "%lf", &IC_min_0);

		else if(argv[argcount][2]=='1') {
		  if(argv[argcount][3]=='\0')     sscanf(argv[argcount+1], "%lf",&IC_min_1);
		  
		  else if(argv[argcount][3]=='0') sscanf(argv[argcount+1], "%lf", &IC_min_10);
		  else if(argv[argcount][3]=='1') sscanf(argv[argcount+1], "%lf", &IC_min_11);
		  else if(argv[argcount][3]=='2') sscanf(argv[argcount+1], "%lf", &IC_min_12);
		  else if(argv[argcount][3]=='3') sscanf(argv[argcount+1], "%lf", &IC_min_13);
		  else if(argv[argcount][3]=='4') sscanf(argv[argcount+1], "%lf", &IC_min_14);
		  else if(argv[argcount][3]=='5') sscanf(argv[argcount+1], "%lf", &IC_min_15);
		  else if(argv[argcount][3]=='6') sscanf(argv[argcount+1], "%lf", &IC_min_16);
		  else if(argv[argcount][3]=='7') sscanf(argv[argcount+1], "%lf", &IC_min_17);
		  else if(argv[argcount][3]=='8') sscanf(argv[argcount+1], "%lf", &IC_min_18);
		  else if(argv[argcount][3]=='9') sscanf(argv[argcount+1], "%lf", &IC_min_19);
		  
		  else {
		    printf("-u0 to -u39 are the only allowable keys.\n");
		    printf("Something goes very wrong (in an argumentsscanf function)\n");
		    exit(0);
		  }
		}
		else if(argv[argcount][2]=='2') {
		  if(argv[argcount][3]=='\0') 	   sscanf(argv[argcount+1], "%lf",&IC_min_2);

		  else if(argv[argcount][3]=='0') sscanf(argv[argcount+1], "%lf", &IC_min_20);
		  else if(argv[argcount][3]=='1') sscanf(argv[argcount+1], "%lf", &IC_min_21);
		  else if(argv[argcount][3]=='2') sscanf(argv[argcount+1], "%lf", &IC_min_22);
		  else if(argv[argcount][3]=='3') sscanf(argv[argcount+1], "%lf", &IC_min_23);
		  else if(argv[argcount][3]=='4') sscanf(argv[argcount+1], "%lf", &IC_min_24);
		  else if(argv[argcount][3]=='5') sscanf(argv[argcount+1], "%lf", &IC_min_25);
		  else if(argv[argcount][3]=='6') sscanf(argv[argcount+1], "%lf", &IC_min_26);
		  else if(argv[argcount][3]=='7') sscanf(argv[argcount+1], "%lf", &IC_min_27);
		  else if(argv[argcount][3]=='8') sscanf(argv[argcount+1], "%lf", &IC_min_28);
		  else if(argv[argcount][3]=='9') sscanf(argv[argcount+1], "%lf", &IC_min_29);
		  
		  else {
		    printf(" Error at reading input arguments:\n");
		    printf("-u0 to -u39 are the only allowable keys. You have typed %s",
			   argv[argcount]);
		    exit(0);
		  }
		}
		else if(argv[argcount][2]=='3') {
		  if(argv[argcount][3]=='\0')     sscanf(argv[argcount+1], "%lf",&IC_min_3);

		  else if(argv[argcount][3]=='0') sscanf(argv[argcount+1], "%lf", &IC_min_30);
		  else if(argv[argcount][3]=='1') sscanf(argv[argcount+1], "%lf", &IC_min_31);
		  else if(argv[argcount][3]=='2') sscanf(argv[argcount+1], "%lf", &IC_min_32);
		  else if(argv[argcount][3]=='3') sscanf(argv[argcount+1], "%lf", &IC_min_33);
		  else if(argv[argcount][3]=='4') sscanf(argv[argcount+1], "%lf", &IC_min_34);
		  else if(argv[argcount][3]=='5') sscanf(argv[argcount+1], "%lf", &IC_min_35);
		  else if(argv[argcount][3]=='6') sscanf(argv[argcount+1], "%lf", &IC_min_36);
		  else if(argv[argcount][3]=='7') sscanf(argv[argcount+1], "%lf", &IC_min_37);
		  else if(argv[argcount][3]=='8') sscanf(argv[argcount+1], "%lf", &IC_min_38);
		  else if(argv[argcount][3]=='9') sscanf(argv[argcount+1], "%lf", &IC_min_39);
		  else {
		    printf(" Error at reading input arguments:\n");
		    printf("-u0 to -u39 are the only allowable keys. You have typed %s",
			   argv[argcount]);
		    exit(0);
		  }
		}
		
		else if(argv[argcount][2]=='4')    sscanf(argv[argcount+1], "%lf",&IC_min_4);
		else if(argv[argcount][2]=='5')    sscanf(argv[argcount+1], "%lf",&IC_min_5);
		else if(argv[argcount][2]=='6')    sscanf(argv[argcount+1], "%lf",&IC_min_6);
		else if(argv[argcount][2]=='7')    sscanf(argv[argcount+1], "%lf",&IC_min_7);
		else if(argv[argcount][2]=='8')    sscanf(argv[argcount+1], "%lf",&IC_min_8);
		else if(argv[argcount][2]=='9')    sscanf(argv[argcount+1], "%lf",&IC_min_9);
		else {
		  printf(" Error at reading input arguments:\n");
		  printf("-u0 to -u39 are the only allowable keys. You have typed %s",
			   argv[argcount]);
		  exit(0);
		}
	      }
              else {
		printf(" This TYPE_of_MODEL (%d) code is not defined.\n", TYPE_of_MODEL);
		printf("Check input argument list\n");
		exit(0);
	      }

        skip++;
        break;

        case 'U':  //Maximum values

                if (TYPE_of_MODEL == 0 ) {
		
		  if(argv[argcount][2]=='0')         sscanf(argv[argcount+1], "%lf", &IC_MAX_0);
		  else if(argv[argcount][2]=='1')    sscanf(argv[argcount+1], "%lf",&IC_MAX_1);
		  else if(argv[argcount][2]=='2')    sscanf(argv[argcount+1], "%lf",&IC_MAX_2);
		  else if(argv[argcount][2]=='3')    sscanf(argv[argcount+1], "%lf",&IC_MAX_3);
		  else if(argv[argcount][2]=='4')    sscanf(argv[argcount+1], "%lf",&IC_MAX_4);
		  else if(argv[argcount][2]=='5')    sscanf(argv[argcount+1], "%lf",&IC_MAX_5);
		  else if(argv[argcount][2]=='6')    sscanf(argv[argcount+1], "%lf",&IC_MAX_6);
		  else if(argv[argcount][2]=='7')    sscanf(argv[argcount+1], "%lf",&IC_MAX_7);
		  else if(argv[argcount][2]=='8')    sscanf(argv[argcount+1], "%lf",&IC_MAX_8);
		  else if(argv[argcount][2]=='9')    sscanf(argv[argcount+1], "%lf",&IC_MAX_9);
		
		else{
		  printf("-U0 to -U39 are the only allowable keys.\n");
		  printf("Something goes very wrong (in an argumentsscanf function)\n");
		  exit(0);
		}
		
	      }
              else if (TYPE_of_MODEL > 0 ) {
		
		if (argv[argcount][2]=='0')  sscanf(argv[argcount+1], "%lf", &IC_MAX_0);

		else if(argv[argcount][2]=='1') {
		  if(argv[argcount][3]=='\0')     sscanf(argv[argcount+1], "%lf",&IC_MAX_1);
		  
		  else if(argv[argcount][3]=='0') sscanf(argv[argcount+1], "%lf", &IC_MAX_10);
		  else if(argv[argcount][3]=='1') sscanf(argv[argcount+1], "%lf", &IC_MAX_11);
		  else if(argv[argcount][3]=='2') sscanf(argv[argcount+1], "%lf", &IC_MAX_12);
		  else if(argv[argcount][3]=='3') sscanf(argv[argcount+1], "%lf", &IC_MAX_13);
		  else if(argv[argcount][3]=='4') sscanf(argv[argcount+1], "%lf", &IC_MAX_14);
		  else if(argv[argcount][3]=='5') sscanf(argv[argcount+1], "%lf", &IC_MAX_15);
		  else if(argv[argcount][3]=='6') sscanf(argv[argcount+1], "%lf", &IC_MAX_16);
		  else if(argv[argcount][3]=='7') sscanf(argv[argcount+1], "%lf", &IC_MAX_17);
		  else if(argv[argcount][3]=='8') sscanf(argv[argcount+1], "%lf", &IC_MAX_18);
		  else if(argv[argcount][3]=='9') sscanf(argv[argcount+1], "%lf", &IC_MAX_19);
		  
		  else {
		    printf("-U0 to -U39 are the only allowable keys.\n");
		    printf("Something goes very wrong (in an argumentsscanf function)\n");
		    exit(0);
		  }
		}
		else if(argv[argcount][2]=='2') {
		  if(argv[argcount][3]=='\0') 	   sscanf(argv[argcount+1], "%lf",&IC_MAX_2);

		  else if(argv[argcount][3]=='0') sscanf(argv[argcount+1], "%lf", &IC_MAX_20);
		  else if(argv[argcount][3]=='1') sscanf(argv[argcount+1], "%lf", &IC_MAX_21);
		  else if(argv[argcount][3]=='2') sscanf(argv[argcount+1], "%lf", &IC_MAX_22);
		  else if(argv[argcount][3]=='3') sscanf(argv[argcount+1], "%lf", &IC_MAX_23);
		  else if(argv[argcount][3]=='4') sscanf(argv[argcount+1], "%lf", &IC_MAX_24);
		  else if(argv[argcount][3]=='5') sscanf(argv[argcount+1], "%lf", &IC_MAX_25);
		  else if(argv[argcount][3]=='6') sscanf(argv[argcount+1], "%lf", &IC_MAX_26);
		  else if(argv[argcount][3]=='7') sscanf(argv[argcount+1], "%lf", &IC_MAX_27);
		  else if(argv[argcount][3]=='8') sscanf(argv[argcount+1], "%lf", &IC_MAX_28);
		  else if(argv[argcount][3]=='9') sscanf(argv[argcount+1], "%lf", &IC_MAX_29);
		  
		  else {
		    printf(" Error at reading input arguments:\n");
		    printf("-U0 to -U39 are the only allowable keys. You have typed %s",
			   argv[argcount]);
		    exit(0);
		  }
		}
		else if(argv[argcount][2]=='3') {
		  if(argv[argcount][3]=='\0')     sscanf(argv[argcount+1], "%lf",&IC_MAX_3);

		  else if(argv[argcount][3]=='0') sscanf(argv[argcount+1], "%lf", &IC_MAX_30);
		  else if(argv[argcount][3]=='1') sscanf(argv[argcount+1], "%lf", &IC_MAX_31);
		  else if(argv[argcount][3]=='2') sscanf(argv[argcount+1], "%lf", &IC_MAX_32);
		  else if(argv[argcount][3]=='3') sscanf(argv[argcount+1], "%lf", &IC_MAX_33);
		  else if(argv[argcount][3]=='4') sscanf(argv[argcount+1], "%lf", &IC_MAX_34);
		  else if(argv[argcount][3]=='5') sscanf(argv[argcount+1], "%lf", &IC_MAX_35);
		  else if(argv[argcount][3]=='6') sscanf(argv[argcount+1], "%lf", &IC_MAX_36);
		  else if(argv[argcount][3]=='7') sscanf(argv[argcount+1], "%lf", &IC_MAX_37);
		  else if(argv[argcount][3]=='8') sscanf(argv[argcount+1], "%lf", &IC_MAX_38);
		  else if(argv[argcount][3]=='9') sscanf(argv[argcount+1], "%lf", &IC_MAX_39);
		  else {
		    printf(" Error at reading input arguments:\n");
		    printf("-U0 to -U39 are the only allowable keys. You have typed %s",
			   argv[argcount]);
		    exit(0);
		  }
		}
		
		else if(argv[argcount][2]=='4')    sscanf(argv[argcount+1], "%lf",&IC_MAX_4);
		else if(argv[argcount][2]=='5')    sscanf(argv[argcount+1], "%lf",&IC_MAX_5);
		else if(argv[argcount][2]=='6')    sscanf(argv[argcount+1], "%lf",&IC_MAX_6);
		else if(argv[argcount][2]=='7')    sscanf(argv[argcount+1], "%lf",&IC_MAX_7);
		else if(argv[argcount][2]=='8')    sscanf(argv[argcount+1], "%lf",&IC_MAX_8);
		else if(argv[argcount][2]=='9')    sscanf(argv[argcount+1], "%lf",&IC_MAX_9);
		else {
		  printf(" Error at reading input arguments:\n");
		  printf("-U0 to -U39 are the only allowable keys. You have typed %s",
			   argv[argcount]);
		  exit(0);
		}
	      }
              else {
		printf(" This TYPE_of_MODEL (%d) code is not defined.\n", TYPE_of_MODEL);
		printf("Check input argument list\n");
		exit(0);
	      }

        skip++;
        break;


