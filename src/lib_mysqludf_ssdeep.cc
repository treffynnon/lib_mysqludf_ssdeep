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
#include "fuzzy.h"

#define strmov(a,b) stpcpy(a,b)
#define bzero(a,b) memset(a,0,b)
#define memcpy_fixed(a,b,c) memcpy(a,b,c)

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
	
	DLLEXP my_bool ssdeep_fuzzy_hash_init(UDF_INIT *initid, UDF_ARGS *args, char *message);
	DLLEXP void ssdeep_fuzzy_hash_deinit(UDF_INIT *initid);
	DLLEXP char *ssdeep_fuzzy_hash(UDF_INIT *initid, UDF_ARGS *args, char *result, unsigned long *length, char *is_null, char *error);
	
	DLLEXP my_bool ssdeep_fuzzy_compare_init(UDF_INIT *initid, UDF_ARGS *args, char *message);
	DLLEXP long long ssdeep_fuzzy_compare(UDF_INIT *initid, UDF_ARGS *args, char *is_null, char *error);
	DLLEXP void ssdeep_fuzzy_compare_deinit(UDF_INIT *initid);
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

/*
 * Fuzzy hash function
 */
my_bool ssdeep_fuzzy_hash_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
	if(args->arg_count != 1 || args->arg_type[0] != STRING_RESULT) {
		strcpy(message, "Wrong arguments to ssdeep_fuzzy_hash; Must be 1 string argument.");
		return 1;
	}
	initid->max_length = FUZZY_MAX_RESULT;
	return 0;
}

void ssdeep_fuzzy_hash_deinit(UDF_INIT *initid)
{
}

char* ssdeep_fuzzy_hash(UDF_INIT *initid, UDF_ARGS *args, char* result, unsigned long* length, char *is_null, char *error)
{
	char *hash = (char *) malloc(FUZZY_MAX_RESULT);
	char *to_hash = args->args[0];
	int to_hash_len = args->lengths[0];
	
	if(!hash)
	{
		*is_null = 1;
		return 0;
	}
	
	if(0 != fuzzy_hash_buf((unsigned char *) to_hash, to_hash_len, hash))
	{
		*is_null = 1;
		return 0;
	} else {
		*length = strlen(hash);
		return hash;
	}
}

/*
 * Fuzzy compare function
 */
my_bool ssdeep_fuzzy_compare_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
	if(args->arg_count != 2 || args->arg_type[0] != STRING_RESULT || args->arg_type[1] != STRING_RESULT) {
		strcpy(message, "Wrong arguments to ssdeep_fuzzy_compare; Must be 2 string arguments.");
		return 1;
	}
	else
	{
		return 0;
	}
}

void ssdeep_fuzzy_compare_deinit(UDF_INIT *initid)
{
}

long long ssdeep_fuzzy_compare(UDF_INIT *initid, UDF_ARGS *args, char *is_null, char *error)
{
	char *signature1 = args->args[0];
	char *signature2 = args->args[1];
	long long match = 0;
	
	if(!signature1 || !signature2)
	{
		*is_null = 1;
		return 0;
	}
	
	match = (long long) fuzzy_compare(signature1, signature2);
	
	if(match < 0 || match > 100)
	{
		*is_null = 1;
		return 0;
	}
	else 
	{
		return match;
	}
}