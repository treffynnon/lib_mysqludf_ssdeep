Function Reference
==================

ssdeep_fuzzy_hash
-----------------

.. function:: ssdeep_fuzzy_hash(to_hash)

   Calculates an ssdeep fuzzy hash for the supplied string.

   :param to_hash: The string to create a hash from - should be 4kb or greater in size
   :type to_hash: string
   :rtype: string

.. warning::

    These files should contain at least 4 kilobytes of text for an accurate hash to be created. The is a restriction of the fuzzy hashing algorithm itself and not lib_mysqludf_ssdeep.

    I have had success with hashes taken from text with just 250 characters though so your mileage may vary.

Example
^^^^^^^

.. code-block:: sql

    SELECT ssdeep_fuzzy_hash('A 4kb string would go here.');

ssdeep_fuzzy_hash_filename
--------------------------

.. function:: ssdeep_fuzzy_hash_filename(file_name)

   Calculates an ssdeep fuzzy hash from the supplied file path.

   :param file_name: The path to a file on disk to create a hash from
   :type file_name: string
   :rtype: string

.. warning::

    These files should contain at least 4 kilobytes of text for an accurate hash to be created. The is a restriction of the fuzzy hashing algorithm itself and not lib_mysqludf_ssdeep.

    I have had success with hashes taken from text with just 250 characters though so your mileage may vary.

Example
^^^^^^^

.. code-block:: sql

    SELECT ssdeep_fuzzy_hash_filename('/tmp/file.txt');

ssdeep_fuzzy_compare
--------------------

.. function:: ssdeep_fuzzy_compare(signature1, signature2)

   Calculates match percentage between two hash strings.

   :param signature1: ssdeep hash to compare
   :type signature1: string
   :param signature2: ssdeep hash to compare
   :type signature2: string
   :returns: 0 to 100 on success and null otherwise.
   :rtype: integer or null

Example
^^^^^^^

.. code-block:: sql

    SELECT ssdeep_fuzzy_compare('384:eGWhC3Uvw60bolB5EqQWXVyBp5ZXHqDj2Gub:mYUvywB620rZPh', '48:H46piMWRaKuCghtYCzHq2nzu50mAmyyGl7A/eIMTQySmmf2ysIX3zxPZ:H46I4tYCb9xmyyGlsMT9Smg2ysUZ');


lib_mysqludf_ssdeep_info
------------------------

.. function:: lib_mysqludf_ssdeep_info()

   This function will return the version number of the UDF.

   :rtype: string

Example
^^^^^^^

.. code-block:: sql

    SELECT lib_mysqludf_ssdeep_info();
