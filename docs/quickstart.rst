Quickstart Tutorial
===================

This UDF is quite simple and its use case is really very clear, but for the impatient many here is a lightening quick run down to get a project up and running.

So if you are writing a system that has to store a large number of documents, but you don't want duplicates or near duplicates cluttering up the application then you can employ ssdeep to generate hashes for you. These hashes can then be compared to any future documents that maybe uploaded to determine their likeness.

Firstly create a documents table:

.. code-block:: sql

    CREATE TABLE IF NOT EXISTS `documents` (
      `id` int(11) NOT NULL AUTO_INCREMENT,
      `title` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
      `ssdeep_hash` text COLLATE utf8_unicode_ci NOT NULL,
      PRIMARY KEY (`id`)
    ) ENGINE=MyISAM DEFAULT CHARSET=utf8;

Next up create two text files and save them as /tmp/document_1.txt and /tmp/document_2.txt. A simple way of getting text is just to nab a few articles from a `news website`_ or wikipedia_.

.. warning::

    These files should contain at least 4 kilobytes of text for an accurate hash to be created. The is a restriction of the fuzzy hashing algorithm itself and not lib_mysqludf_ssdeep.

    I have had success with hashes taken from text with just 250 characters though so your mileage may vary.

Then "upload" the first document with the following insert statement:

.. code-block:: sql

    INSERT INTO `documents`
    SET `title` = 'The first document!',
        `ssdeep_hash` = ssdeep_fuzzy_hash_filename('/tmp/document_1.txt');

So when another document is uploaded you can compare its signature against the documents already in the documents table.

.. code-block:: sql

    SELECT `title`
    FROM `documents`
    WHERE ssdeep_fuzzy_compare(`ssdeep_hash`, ssdeep_fuzzy_hash_filename('/tmp/document_2.txt')) > 20;

Every document that is returned has more than a 20% likeness to the freshly uploaded document.

.. _news website: http://news.bbc.co.uk
.. _wikipedia: http://wikipedia.org
