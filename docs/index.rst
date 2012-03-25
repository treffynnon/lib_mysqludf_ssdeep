.. lib_mysqludf_ssdeep documentation master file, created by
   sphinx-quickstart on Sat Mar 24 22:06:09 2012.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

lib_mysqludf_ssdeep documentation
===============================================

ssdeep is a utility for creating and comparing fuzzy hashes or `context-triggered piecewise hashing`_.

Fuzzy hashing can match signatures which have "...sequences of identical bytes in the same order, although bytes in between these sequences may be different in both content and length". (`ssdeep project page`_)

This MySQL `User Defined Function`_ provides functions for creating and comparing fuzzy hashes.

Contents:

.. toctree::
   :maxdepth: 2

   installation
   quickstart
   functions



Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`

.. _context-triggered piecewise hashing: http://dfrws.org/2006/proceedings/12-Kornblum.pdf
.. _User Defined Function: http://dev.mysql.com/doc/refman/5.5/en/adding-functions.html
.. _ssdeep project page: http://ssdeep.sourceforge.net
