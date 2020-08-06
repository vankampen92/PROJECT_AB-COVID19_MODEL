# =======================
#     LIBRARY make
# =======================

SUBDIRS = Library Definition_Error_Model MODEL_CALCULATIONS 

# Gnu C make cpgplot_GRID UTILS (libda_cpgplot_GRID.a)
export PROJECT_DIR          = ${PWD}/
export CPGPLOT              = ${PROJECT_DIR}../CPGPLOT/




.PHONY:  subdirs $(SUBDIRS)
     
subdirs: $(SUBDIRS)

clean: 
	find . -name *.o -exec rm {} \;
	find . -name ~* -exec rm {} \;	

$(SUBDIRS):
	$(MAKE) -C $@


