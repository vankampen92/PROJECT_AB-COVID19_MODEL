# README #

This project runs on linux machines out of the box. To run in other platforms makefiles should be modified accordingly. 
The follwing dependencies are required:

## GNU Scientific Library (GSL)
This is a numerical library for C and C++ programmers. It is free software under the GNU General Public License.
## CPGPLOT Graphix Library. 
This is a set of functions written in C relying on cpgplot primitives from pgplot, and plplot. As a consequence, the CPGPLOT Graphix library, in turns, depends on: 
### [pgplot](/http://www.astro.caltech.edu/~tjp/pgplot/)
### [plplot](http://plplot.sourceforge.net/)
You can git clone the CPGPLOT library from my repository.

### What is this repository for? ###

* This repository sets up a number of SIR-like models with application to the spread of COVI19 in heterogeneous populations (age classes) distributed across a network metatapopulation structure. Both ODEs and Gillespie simulations are implemented. 

* Version: 0.0.0.999
* [Learn Markdown](https://bitbucket.org/tutorials/markdowndemo)

### How do I get set up? ###

First you should install the libraries to meet the dependencies mentioned above. Look for GSL, pgplot and libplplot12 in your usual package handler.
Notice that the linking command from most makefiles contains, at least, the following libraries:

* -lgsl -lgslcblas 
* -lWL -lpng -lplplotd -lpgplot -lcpgplot 
* -lda_cpgplot_XY_GRID_FILE -lda_cpgplot_BASIC

The first two ones are basic GSL libraries. The following 5 are required to use primitive plotting functions from the graphic libraries cpplot and plplot. The final two are mandatory when using higher-level plotting functions from the CPGPLOT Graphix library. All of them are usually required to produce a graphical output. However, the control variable (see any makefile) 'CPG" can also be set up to 'NON_CPG_REPRESENTATION' and, then, through conditional compilation, the same program is built to just run the numerical computations without graphics. In all cases, the output may be saved in files. 

When you git clone the repository on your machine, you should do it from your home directory. As a result, the directory 'PROJECT_AB-COVID19_MODEL' will be created on your machine.

If graphic libraries have been correctly installed, this should be enough to make all makefiles work out of the box. Remember though you require to have also git cloned my CPGPLOT repository on your machine. To be clear, you should end up with two directories:

* -$ ./CPGPLOT
* -$ ./PROJECT_AB-COVID_MODEL

both in you home directory.

* Summary of set up:
	+ #### 1. Install GSL library
	+ #### 2. Install plplot library
	+ #### 3. Install pgplot library
	+ #### 4. git clone https://github.com/vankampen92/CPGPLOT
	+ #### 5. git clone https://github.com/vankampen92/PROJECT_AB-COVID19_MODEL.git
	+ #### 6. Tests: 
	In order to test if pgplot, plplot and CPGPLOT are correctly installed in your machine, you can expand the tar file PROJECT_CPGPLOT_EXAMPLES.tar, which is in the project root directory on your home directory. Then you will get the directory ~/PROJECT_CPGPLOT_EXAMPLES. In that directory, there is a simple example of how to use the CPGPLOT library. You build it by typing:
	
		+ ~/PROJECT_CPGPLOT_EXAMPLES/make
		
		and you will get the exectutable file PLOT. You may run the example with some command arguments (see main.c). You should get a graph with four different subplots. You may also type:
		
		+ ~/PROJECT_CPGPLOT_EXAMPLES/PLOT -h
		
		and see other available command line arguments. You may also type: 
		
		+ ~/PROJECT_CPGPLOT_EXAMPLES/PLOT -G29 ?
		
	and see the different avaiable graphic formats in whcodeich plots can be saved. Notice that sometimes the value for these input arguments is overriden by the internal program code. When this happens, it is for a good reason. Please check the code to understand why and make moodgodfications at your own risk. Be creative.   
	
	+ #### 7. Examples:
	See, for instance, ./MODEL_CALCULATIONS/TEMPORAL_EVOLUTION_STOCHASTICS/main.c, and follow the directions to compile and run the code: 
		
		+ ~$ make MODEL=SEI1I2AAdYR_AGE_MPOP
		
		+ ~$ ./SEI1I2AAdYR_AGE_MPOP -y0 3 -h  (help associated to type of model 3. That's why, we have -y0 3)
		code
		+ ~$ ./SEI1I2AAdYR_AGE_MPOP -y0 3 -HN 4 -n 1 -v0 12 -G0 1 -G1 1 -tn 50 -t0 0.0 -t1 50.0 -t4 0 -tR 10 -tE 0.1 -xn 0 -xN 10000 -G2 1 -G3 0.0 -G4 50.0 -G5 1 -G6 0.0 -G7 7000.0 -H2 2.5 -H0 0.01 -H1 0.3 -H9 0.0001 -H37 0.001 -H38 0.05 -H39 0.2
		
	The code depends on some auxiliary libraries in ./Library  and ./Definition_Error_Model subdirectories. You may notice that you need to generate these libraries before, and then execute the command 'make MODEL=SEI1I2AAdYR_AGE_MPOP'. In principle, a recursive makefile does this job for you. However, if gcc does not find these libraries, they may have been accidentally deleted and you should build them back up again. Also, the code is linked against R libraries.  You may remove these R links or install R in your system. I recommend this 2n option. This will allow you to create shared libraries that, then, can be called as standard R funcions from RStudio, for example. 
	
	The call on the third line above generates a bunch of stochatic realizations (-tR 10) and presents a single output variable (-n 1), thi is, the epidemic curve of the detected infection (-v0 12) across 4 (-HN 4) local populations with 4 age classes conntected by individual migrations. These are represented on a single plot as they are produced. 

### Contribution guidelines ###

* Writing tests
* Code review
* Other guidelines

### Who do I talk to? ###
code
* Drop an email to David Alonso (<dalonso@ceab.csic.es>)
