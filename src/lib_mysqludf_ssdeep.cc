// Copyright (C) 2010 Simon Holywell <simon@holywell.com.au>
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#include "mysqludf.h"

/* For Windows, define PACKAGE_STRING in the VS project */
#ifndef __WIN__
#include "config.h"
#endif

/* These must be right or mysqld will not find the symbol! */
#ifdef	__cplusplus
extern "C" {
#endif
	DLLEXP my_bool lib_mysqludf_ssdeep_info_init(UDF_INIT *initid, UDF_ARGS *args, char *message);
	DLLEXP void lib_mysqludf_ssdeep_info_deinit(UDF_INIT *initid);
	DLLEXP char *lib_mysqludf_ssdeep_info(UDF_INIT *initid, UDF_ARGS *args, char *result, unsigned long *length, char *is_null, char *error);
#ifdef	__cplusplus
}
#endif


/*
 * Output the library version.
 * lib_mysqludf_ssdeep_info()
 */

my_bool lib_mysqludf_ssdeep_info_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
	return 0;
}

void lib_mysqludf_ssdeep_info_deinit(UDF_INIT *initid)
{
}

char* lib_mysqludf_ssdeep_info(UDF_INIT *initid, UDF_ARGS *args, char* result, unsigned long* length, char *is_null, char *error)
{
	strcpy(result, PACKAGE_STRING);
	*length = strlen(PACKAGE_STRING);
	return result;
}