USE mysql;

DROP FUNCTION IF EXISTS lib_mysqludf_ssdeep_info;
DROP FUNCTION IF EXISTS ssdeep_fuzzy_hash;
DROP FUNCTION IF EXISTS ssdeep_fuzzy_hash_filename;
DROP FUNCTION IF EXISTS ssdeep_fuzzy_compare;
CREATE FUNCTION lib_mysqludf_ssdeep_info RETURNS STRING SONAME 'lib_mysqludf_ssdeep.so';
CREATE FUNCTION ssdeep_fuzzy_hash RETURNS STRING SONAME 'lib_mysqludf_ssdeep.so';
CREATE FUNCTION ssdeep_fuzzy_hash_filename RETURNS STRING SONAME 'lib_mysqludf_ssdeep.so';
CREATE FUNCTION ssdeep_fuzzy_compare RETURNS INTEGER SONAME 'lib_mysqludf_ssdeep.so';