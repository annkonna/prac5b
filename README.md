Pointer Math Practice
===

In this practice, you will implement an encoding function that uses
pointer math to interpret bytes stored in memory.

Requirements
---

You must implement the `encode_text()` function in `encode.c`.  This
function will be passed a buffer of type `char *` containing text data
called 'text' and a 'void *' named 'encode' that you will fill with
bytes based on the input text.

The input text needs to be split into lines and stored in the encode
buffer as chunks. Each chunck holds one line from input text file.
The chunk should consist of a number of type `int` which stores the
number of characters in the chunk followed immediately by character
data consisting of the number of characters stored in the 'int'.  An
example chunk might look like this:

| (int)6 | 'H' | 'e' | 'l' | 'l' | 'o' | '\n' |

The final chunk should consist of a `int` containing the value `0` and
no character data.


Building, Running, and Testing
---

The command `make` will build a binary called `encode` that you can
run using the command:

./encode < data.txt > encode.out

If your function works correctly, encode.out would show the encoded bytes 
when encoding the three lines of text in data.txt. To verify it is
correct, study the text in data.txt and the output in encode.out and
verify that the output confirms to the format described above.

NOTE: One could use the output file from the encode program as the input
file for the decode program. To do this, comment-out the last line that
calls 'dump_mem' and instead uncomment the call to 'dump_raw_bytes'. 


Hints
---

Remember that pointer math on a `void *` pointer is in terms of _bytes_,
while many data types (such as `size_t`!) are larger than one byte.  You
can add increments of `sizeof(type)` to adjust a `void` pointer by the
size of another type.

Pointer casting works like casting of any other type.  For example:

```C
int readptr(void *ptr) {
    return *(int *)ptr;
}
```

This function accepts a `void` pointer argument, but interprets the data
stored at the pointer as an `int` pointer.  A `void` pointer _cannot be
directly dereferenced_, you will _have_ to cast it in order to read the
data to which it points.

