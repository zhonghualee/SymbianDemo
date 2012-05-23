# ============================================================================
#  Name	 : build_help.mk
#  Part of  : SymbianDemo1
# ============================================================================
#  Name	 : build_help.mk
#  Part of  : SymbianDemo1
#
#  Description: This make file will build the application help file (.hlp)
# 
# ============================================================================

do_nothing :
	@rem do_nothing

# build the help from the MAKMAKE step so the header file generated
# will be found by cpp.exe when calculating the dependency information
# in the mmp makefiles.

MAKMAKE : SymbianDemo1_0xe68a9f1f.hlp
SymbianDemo1_0xe68a9f1f.hlp : SymbianDemo1.xml SymbianDemo1.cshlp Custom.xml
	cshlpcmp SymbianDemo1.cshlp
ifeq (WINSCW,$(findstring WINSCW, $(PLATFORM)))
	md $(EPOCROOT)epoc32\$(PLATFORM)\c\resource\help
	copy SymbianDemo1_0xe68a9f1f.hlp $(EPOCROOT)epoc32\$(PLATFORM)\c\resource\help
endif

BLD : do_nothing

CLEAN :
	del SymbianDemo1_0xe68a9f1f.hlp
	del SymbianDemo1_0xe68a9f1f.hlp.hrh

LIB : do_nothing

CLEANLIB : do_nothing

RESOURCE : do_nothing
		
FREEZE : do_nothing

SAVESPACE : do_nothing

RELEASABLES :
	@echo SymbianDemo1_0xe68a9f1f.hlp

FINAL : do_nothing
