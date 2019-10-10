# get_next_line
get_next_line is an assignment from 42, it is a function that takes a file descriptor and an empty line as an input. It writes the first line of the file onto the empty line. Every consecutive time it is called, it writes the next line of the file onto the empty file. When it hits EOF (end of file), it stops writing.

# How to use
The prototype is `get_next_line(const int fd, char **line);` `fd` being the file descriptor for the file that is being, read, and `line` being an empty string. It is the users responsibility that the string is empty each time the function runs.

**Return value**

Returns 1 on successful run, 0 on successful run and EOF has been reached.
Returns -1 on error.

# Test program
I wrote a program to test gnl.
Navigate inside `gnl includes`, and run
```
make
```
Then run 
```
./gnl [1 - 3 source files]
```
