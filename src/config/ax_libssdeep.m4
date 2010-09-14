#####
#
# SYNOPSIS
#
#   AX_SSDEEP()
#
# DESCRIPTION
#
#   This macro provides tests of availability of SSDEEP library and headers.
#
#   This macro calls:
#
#     AC_SUBST(SSDEEP_LIBDIR)
#     AC_SUBST(SSDEEP_LIBS)
#
# TODO
# 
#   Need a better hunting system for ssdeep libs ala http://www.mysqludf.org/lib_mysqludf_xql/index.php
#####

AC_DEFUN([AX_SSDEEP], [
  AC_MSG_CHECKING(for ssdeep)

	SSDEEP_LIBDIR="-L/usr/lib"
	SSDEEP_LIBS="-lfuzzy"
    
  AC_DEFINE([SSDEEP_ENABLED], [1], [Enables ssdeep])
  
  AC_SUBST(SSDEEP_LIBDIR)
  AC_SUBST(SSDEEP_LIBS)
])