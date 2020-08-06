# =======================
#     LIBRARY make
# =======================


SUBDIRS =  TEMPORAL_EVOLUTION_DETERMINISTIC  TEMPORAL_EVOLUTION_STOCHASTIC   
BUILDIRS = $(SUBDIRS:%=build-%)
CLEANDIRS = $(SUBDIRS:%=clean-%)




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
.PHONY:  subdirs $(CLEANDIRS)
.PHONY:  all clean


