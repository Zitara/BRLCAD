set(HALFTONE_INCLUDE_DIRS
  ${BU_INCLUDE_DIRS}
  ${BN_INCLUDE_DIRS}
  ${RT_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  )
LIST(REMOVE_DUPLICATES HALFTONE_INCLUDE_DIRS)
include_directories(${HALFTONE_INCLUDE_DIRS})

if(LEX_EXECUTABLE)
  LEX_TARGET(SS_Scanner script.l
    ${CMAKE_CURRENT_BINARY_DIR}/script.c COMPILE_FLAGS "-l")
  BRLCAD_ADDEXEC(scriptsort "scriptsort.c;${LEX_SS_Scanner_OUTPUTS}" librt)
  # we can quell most in the lexer source, but not some -- don't emit warnings we can't quell
  SET_TARGET_PROPERTIES(scriptsort PROPERTIES COMPILE_FLAGS "-Wno-error -Wno-unused-label -Wno-documentation")
else(LEX_EXECUTABLE)
  CMAKEFILES(scriptsort.c)
endif(LEX_EXECUTABLE)

BRLCAD_ADDEXEC(script-tab script-tab.c "librt;libbn;libbu;${M_LIBRARY}")
BRLCAD_ADDEXEC(tabinterp tabinterp.c "librt;libbu;${M_LIBRARY}")
BRLCAD_ADDEXEC(tabsub tabsub.c "libbn;libbu;${M_LIBRARY}")

CMAKEFILES(script.l tokens.h)

# Local Variables:
# tab-width: 8
# mode: cmake
# indent-tabs-mode: t
# End:
# ex: shiftwidth=2 tabstop=8
