USE mysql;

DROP FUNCTION IF EXISTS lib_mysqludf_ssdeep_info;
DROP FUNCTION IF EXISTS ssdeep_fuzzy_hash;
CREATE FUNCTION lib_mysqludf_ssdeep_info RETURNS STRING SONAME 'lib_mysqludf_ssdeep.so';
CREATE FUNCTION ssdeep_fuzzy_hash RETURNS STRING SONAME 'lib_mysqludf_ssdeep.so';