/* Initial Conditions parameters */
fprintf(fp, "\n");
fprintf(fp, " M O D E L   ( C O R E )   P A R A M E T E R S :\n");
fprintf(fp, " No of LOCAL POPULATIONS              ...> -HN   %d\n", No_of_LOCAL_POPULATIONS);/* N */
fprintf(fp, " Detectability rate (assymptomatics)  ...> -H0   %g\n", Kappa); /*  0 */
fprintf(fp, " Total Immigration Rate            ...> -H1   %g\n", Imm);    /*  1 */
fprintf(fp, " Contact rate: Total no of contacts an individual has per day           ...> -H2   %g\n", Beta);    /*  2 */
fprintf(fp, " Infectivity                     ...> -H3   %g\n", b);  /*  3 */
fprintf(fp, " Pre-symptomatic Infectivity Factor                ...> -H4   %g\n", Phi);  /*  4 */
fprintf(fp, " Isolation effectiveness of strong cases                       ...> -H5   %g\n", Eps_I);  /*  5 */
fprintf(fp, " Isolation effectiveness of serious cases            ...> -H6   %g\n", Eps_Y);     /*  6 */
fprintf(fp, " Rate of the appearance of infectious capacity                    ...> -H7   %g\n", Sigma); /*  7 */
fprintf(fp, " Rate of the appearance of symptoms                ...> -H8   %g\n", Gamma_1); /*  8 */
fprintf(fp, " Probability of the appearance of strong symptoms             ...> -H9   %g\n", p_0);    /* 9 */
fprintf(fp, " (Age-dependent) Rate of appearence of serious symptoms                ...> -H10   %g\n", Alpha);  /* 10 */
fprintf(fp, " (Age-dependent) Disease-Induced Mortality Rate              ...> -H11  %g\n", Delta);/* 11 */
fprintf(fp, " Rate of Recovery              ...> -H12  %g\n", Gamma_2);    /* 12 */
