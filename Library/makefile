# =======================
#     LIBRARY make
# =======================

SUBDIRS =C_NumRecip  GSL_RANDOM  IO_Library  Optimization_Library  
     


BUILDIRS = $(SUBDIRS:%=build-%)
CLEANDIRS = $(SUBDIRS:%=clean-%)




all: $(BUILDIRS)
$(SUBDIRS): $(BUILDIRS)
$(BUILDIRS):
	$(MAKE) -C $(@:build-%=%) all


subdirs: $(SUBDIRS)

clean: $(CLEANDIRS)
$(CLEANDIRS):
	$(MAKE) -C $(@:clean-%=%) clean



.PHONY:  subdirs $(SUBDIRS)
.PHONY:  subdirs $(BUILDDIRS)
.PHONY:  subdirs $(CLEANDIRS)
.PHONY:  all clean
