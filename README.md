## 📦Huffman Coding Compression

Huffman encoding is a way to assign binary codes to symbols that reduces
the overall number of bits used to encode a typical string of those symbols.

As we all knowe each char stored in 8-bit of 0's and 1's which 
called ```fixed-length-encoding``` as we use the same number of bits to any char .

The idea of Huffman-Coding-Algorithm is to ```use variable-length-encoding``` +  using the fact
that some chars occurs more freq than others

So we assign ```variable-number``` of bits to each char based on its freq in the text.

Our main problem is in decoding the text 
Our solution is to use what called (Prefix Rule) which will result into 
(uniquely-decodable-codes) ==> "No Code is Prefix to another Code".	

```
Example : we have Str = "aabacdab" 
	a	->        0 
	b	->	  10
	c	->	  110
	d	->	  111
```
```
then Str = 00100110111010
```


![625px-Huffman_tree_2 svg](https://user-images.githubusercontent.com/40190772/56161841-ddc1aa00-5fca-11e9-97e8-80d539afa610.png)
