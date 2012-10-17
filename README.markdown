lib\_mysqludf\_ssdeep
=====================

More comprehensive documentation can be found on the [lib\_mysqludf\_ssdeep readthedocs.org page](http://lib_mysqludf_ssdeep.readthedocs.org).

Functions
------------------

### ssdeep_fuzzy_hash(*STRING* to_hash)
- **Param:** _to_hash_ string to be hashed using ssdeep.
- **Return:** a hash _STRING_ on success and _NULL_ otherwise.

Calculates an ssdeep hash for the supplied string.

### ssdeep_fuzzy_hash_filename(*STRING* file_name)
- **Param:** _file_name_ to be hashed using ssdeep.
- **Return:** a hash _STRING_ on success and _NULL_ otherwise.

Calculates an ssdeep hash for the supplied filename.

### ssdeep_fuzzy_compare(*STRING* signature1, *STRING* signature2)
- **Param:** _signature1_ ssdeep hash string to compare.
- **Param:** _signature2_ ssdeep hash string to compare.
- **Return:** an _INTEGER_ (0 to 100) on success and _NULL_ otherwise.

Calculates match percentage between two hash strings.


Building
------------------

### Ubuntu

Move into the lib\_mysqludf\_ssdeep directory.

#### MySQL Libraries

	sudo apt-get install libmysqlclient-dev

#### ssdeep Libraries

1. Get [ssdeep from sourceforge](http://ssdeep.sourceforge.net/ "ssdeep on sourceforge")
2. Install with `./configure` and then `make` and then `make install`
3. Done

#### Build It!

1. `mkdir build`
2. `./build.sh`
3. lib\_mysqludf\_ssdeep.so will now be in the current directory.


### Redhat

Move into the lib\_mysqludf\_ssdeep directory.

#### MySQL Libraries

	yum install gcc-c++ mysql-devel autoconf automake libtools

#### ssdeep Libraries

1. Get [ssdeep from sourceforge](http://ssdeep.sourceforge.net/ "ssdeep on sourceforge")
2. Install with `./configure` and then `make` and then `make install`
3. Done

#### Build It!

1. `mkdir build`
2. `./build.sh`
3. lib\_mysqludf\_ssdeep.so will now be in the current directory.

Install
------------------

To find your MySQL plugin directory run the following query in MySQL:

    show variables like 'plugin_dir';

Mine is /usr/lib/mysql/plugin/ and I have used that in the examples below. It can be changed in your /etc/mysql/my.cnf file with the line in the mysqld section:

    [mysqld]
    plugin_dir=/usr/lib/mysql/plugin

### Ubuntu

1. `sudo cp lib_mysqludf_ssdeep.so /usr/lib/mysql/plugin/`
2. `mysql -u root -p < src/installdb.sql`
3. Done.

Uninstall
------------------

### Ubuntu

1. `sudo rm /usr/lib/mysql/plugin/lib_mysqludf_ssdeep.so`
2. `mysql -u root -p < src/uninstalldb.sql`
3. Done.