# INVERTED-SEARCH

Optimizing Search Engine Performance with Inverted Indexing

Developed a C-based application to enhance search engine speed and performance through the implementation of an inverted index data structure. This structure efficiently maps content, such as words or numbers, to their locations within a database, enabling rapid and accurate full-text searches. Key features include the creation of a database through indexing, real-time updates to the index as files are added or removed, and result filtering for improved search relevance. The inverted index was implemented using a sorted linked list and hashing.

Skills Gained: C, Command Line Arguments, File Operations, Bitwise Operations, Pointers, Data Structures

**{ GIST }**
<br>
The purpose of storing an index is to optimize speed and performance in finding relevant documents for a search query. Without an index, the search engine would scan every document in the corpus, which would require considerable time and computing power.
<br><br>
**{ INTRODUCTION }**
<br>
An inverted index is an index data structure storing a mapping from content, such as words or numbers, to its locations in a database file, or in a document or a set of documents. The purpose of an inverted index is to allow fast full text searches, at the cost of increased processing when a document is added to the database. The inverted file may be the database file itself, rather than its index. It is the most popular data structure used in document retrieval systems, used on a large scale for example in search engines.
<br><br>
**{ REQUIREMENT }**
<br>
* Indexing : <br>
By Indexing, we are creating a database file which contains the index of all words. So this can betermed as Database Creation also. All the files whose index are to be created are selected and inputed to this function. All the files are parsed and words are separated and indexed. They are arranged in sorted order. For this a sorted Linked List or Hashing is used which will store the words and the related file details. The index thus created is then stored in the file as database. This file is later used in Querying. While the files are removed or added this index file is updated.

<p align="center">
  <img src="https://github.com/VisheshK65/INVERTED-SEARCH/blob/main/FIRST.jpg" width="500"/><br>
  <img src="https://github.com/VisheshK65/INVERTED-SEARCH/blob/main/SECOND.jpg" width="500"/>
</p>

* Searching : <br>
Once the Indexing is over we have the Querying or Searching. The text to be searched is inputed which is parsed into words and those words are searched in the index file. To avoid the overhead of reading the file again, the file is converted back to a linkedList or hashing program, in which the words are searched. The information about the files which contain the words are collected. The ones with more matches are filtered and produced as the result.

<p align="center">
  <img src="https://github.com/VisheshK65/INVERTED-SEARCH/blob/main/THIRD.jpg" width="500"/><br>
  <img src="https://github.com/VisheshK65/INVERTED-SEARCH/blob/main/FOURTH.jpg" width="500"/>
</p>


