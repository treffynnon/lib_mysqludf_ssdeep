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
#     AC_SUBST(SSDEEP_INCLUDEDIR)
#
#####

AC_DEFUN([AX_SSDEEP], [
  AC_MSG_CHECKING(for ssdeep)
  AC_ARG_WITH(ssdeep,
    [[  --with-ssdeep[=PATH]   use ssdeep @<:@default=yes@:>@, optionally specify path to ssdeep build directory]],
    [withssdeep="$withval"],
    [withssdeep="yes"]
  )

  if test -z "$withssdeep" -o "$withssdeep" = "yes"; then
    for i in /usr/lib /usr/local/lib; do
      if test -f "$i/libfuzzy.so"; then
        SSDEEP_LIB_DIR="$i"
      fi
    done
    if test "$SSDEEP_LIB_DIR" = ""; then
      AC_MSG_ERROR(["could not find ssdeep libfuzzy"])
    fi
  elif test "$withssdeep" = "no"; then
    AC_MSG_ERROR(["can not build with ssdeep disabled"])
  else
    if test -f "$withssdeep/libfuzzy.so"; then
      SSDEEP_LIB_DIR="$withssdeep"
    else
      if test -f "$withssdeep/.libs/libfuzzy.so"; then
        SSDEEP_LIB_DIR="$withssdeep"
      else
        AC_MSG_ERROR(["could not find ssdeep: $withssdeep/.libs/libfuzzy.so"])
      fi
    fi
  fi

  SSDEEP_LIBDIR="-L$SSDEEP_LIB_DIR"
  SSDEEP_LIBS="-lfuzzy"

  if test -z "$withssdeep" -o "$withssdeep" = "yes"; then
    for i in /usr/include /usr/local/include; do
      if test -f "$i/fuzzy.h"; then
        SSDEEP_INCLUDEDIR="-I$i"
      fi
    done 
    if test "$SSDEEP_INCLUDEDIR" = ""; then
      AC_MSG_ERROR(["could not find headers for ssdeep libfuzzy"])
    fi
  else
    if test -f "$withssdeep/../fuzzy.h"; then
      SSDEEP_INCLUDEDIR="$withssdeep/../"
    else
      if test -f "$withssdeep/fuzzy.h"; then
        SSDEEP_LIB_DIR="$withssdeep"
      else
        AC_MSG_ERROR(["could not find ssdeep fuzzy.h header file"])
      fi
    fi
  fi

  AC_MSG_RESULT([$SSDEEP_LIB_DIR])
    
  AC_DEFINE([SSDEEP_ENABLED], [1], [Enables ssdeep])
  
  AC_SUBST(SSDEEP_LIBDIR)
  AC_SUBST(SSDEEP_LIBS)
  AC_SUBST(SSDEEP_INCLUDEDIR)
])