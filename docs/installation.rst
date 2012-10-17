Installation
============

Get the source
--------------

Either clone down the git respository from github_ or download the `latest tag`_ as a tar gzip::

    $ git clone git://github.com/treffynnon/lib_mysqludf_ssdeep.git

This should beplaintext yeah

Install dependencies
--------------------

Ubuntu/Debian
^^^^^^^^^^^^^

To install the MySQL development headers and ssdeep install the following package::

    $ sudo apt-get install libmysqlclient-dev ssdeep libfuzzy-dev

Redhat
^^^^^^

To install the GCC C++ compiler and the MySQL development headers install the following packages::

    $ yum install gcc-c++ mysql-devel autoconf automake libtool

As there is no libfuzzy package on Redhat you need to build ssdeep from `its sources`_::

    $ cd ssdeep
    $ ./configure
    $ make
    $ make install

Build lib_mysqludf_ssdeep
-------------------------

Now onto building the lib_mysqludf_sseep library::

    $ cd lib_mysqludf_ssdeep
    $ ./build.sh

The library file, lib_mysqludf_ssdeep.so, is now in the current directory ready to be installed into MySQL,

Install lib_mysqludf_ssdeep
---------------------------

The library needs to be copied to the MySQL plugin directory. To find out the location of your plugin directory run the following SQL

.. code-block:: sql

    show variables like 'plugin_dir';

A common location is /usr/lib/mysql/plugin, but it can be changed in the MySQL configuration at /etc/mysql/my.cnf in the mysqld section::

    [mysqld]
    plugin_dir=/usr/lib/mysql/plugin

To install the library execute the following commands::

    $ sudo cp lib_mysqludf_ssdeep.so /usr/lib/mysql/plugin/
    $ mysql -u root -p < src/installdb.sql

.. _github: https://github.com/treffynnon/lib_mysqludf_ssdeep
.. _latest tag: https://github.com/treffynnon/lib_mysqludf_ssdeep/tags
.. _its sources: http://ssdeep.sourceforge.net
