# -*- makefile -*-
#----------------------------------------------------------------------------
#       GNU ACE Workspace
#
# 
#
# This file was generated by MPC.  Any changes made directly to
# this file will be lost the next time it is generated.
#
# MPC Command:
# /home/johnny/DOC_ROOT/stage-31304/ACE_wrappers/bin/mwc.pl -type gnuace -exclude TAO/TAO_ACE.mwc -workers 8 -recurse -hierarchy -relative ACE_ROOT=/home/johnny/DOC_ROOT/stage-31304/ACE_wrappers -relative TAO_ROOT=/home/johnny/DOC_ROOT/stage-31304/ACE_wrappers/TAO
#
#----------------------------------------------------------------------------

MAKEFILE = GNUmakefile

ifeq ($(findstring k,$(MAKEFLAGS)),k)
  KEEP_GOING = -
endif

include $(ACE_ROOT)/include/makeinclude/macros.GNU

all: Codeset_Idl Codeset

depend: Codeset_Idl-depend Codeset-depend

REMAINING_TARGETS := $(filter-out all depend,$(TARGETS_NESTED:.nested=)) $(CUSTOM_TARGETS)
.PHONY: $(REMAINING_TARGETS)

$(REMAINING_TARGETS):
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Codeset_Idl $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Codeset $(@)

.PHONY: Codeset_Idl
Codeset_Idl:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Codeset_Idl all

.PHONY: Codeset_Idl-depend
Codeset_Idl-depend:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Codeset_Idl depend

.PHONY: Codeset
Codeset: Codeset_Idl
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Codeset all

.PHONY: Codeset-depend
Codeset-depend:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.Codeset depend

project_name_list:
	@echo Codeset
	@echo Codeset_Idl
