#include <MODEL.h>

#include "extern.h"
extern int HELP_INPUT_ARGUMENTS;

void Parameters_from_Command_Line(FILE *fp, Parameter_Table *P)
{


#if defined CPGPLOT_REPRESENTATION
#include <include.CPG.fprintPar.c>
#endif

#include <include.Type_of_Model.report.c>

#include <include.Trend_Control.report.c>

#include <include.Time_Control.report.c>

#include <include.Initial_Conditions.report.c>

#include <include.Parameter_Space.report.c>
  fprintf_Input_Parameters(fp, P);
  fprintf_Output_Variables(fp, P);
#include <include.Parameter_Model.report.c>
}

void Parameters_ModelReport(char *File, Parameter_Table *P)
{
  FILE *fp;
  Parameters_from_Command_Line(stdout, P);
  fp = fopen(File, "w");
  Parameters_from_Command_Line(fp, P);
  fclose(fp);
}
