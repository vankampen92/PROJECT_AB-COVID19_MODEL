# =======================
#     LIBRARY make
# =======================

SUBDIRS = Library Definition_Error_Model MODEL_CALCULATIONS 
BUILDIRS = $(SUBDIRS:%=build-%)
CLEANDIRS = $(SUBDIRS:%=clean-%)

# Gnu C make cpgplot_GRID UTILS (libda_cpgplot_GRID.a)
export PROJECT_DIR          = ${PWD}/
export CPGPLOT              = ${PROJECT_DIR}../CPGPLOT/



all: $(BUILDIRS)
$(SUBDIRS): $(BUILDIRS)
$(BUILDIRS):
	$(MAKE) -C $(@:build-%=%)
	
     
subdirs: $(SUBDIRS)

clean: $(CLEANDIRS)
$(CLEANDIRS): 
	$(MAKE) -C $(@:clean-%=%) clean



.PHONY:  subdirs $(SUBDIRS)
.PHONY:  subdirs $(BUILDDIRS)
.PHONY: subdirs $(CLEANDIRS)
.PHONY:  all clean

