USE mysql;

DROP FUNCTION IF EXISTS lib_mysqludf_ssdeep_info;
CREATE FUNCTION lib_mysqludf_ssdeep_info RETURNS STRING SONAME 'lib_mysqludf_ssdeep.so';
