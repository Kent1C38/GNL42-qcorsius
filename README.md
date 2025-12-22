*This project has been created as part of the 42 curriculum by qcorsius*

# Description
Get Next Line is a function that reads a file and return one line, then when we call it again it gives us the line right after, and so on. The function stores in a static variable the rest of the content readed that is after the requested line, so we can retrieve it when we call back our function.
There are two versions here, one that can handle properly only one opened file, and an other that handle multiple files.

# Instructions
In order to use this function, you will have to compile you code with `get_next_line(_bonus).c` and `get_next_line_utils(_bonus).c` and include the `get_next_line(_bonus).h`. Then just call the function and pass the file descriptor of your file that you want to read.

# Resources
- [Medium (thanks to bbazaglia)](https://medium.com/@beatrizbazaglia/get-next-line-3872eb3189e6)

Some AI were used for:
- Reformating code (to satisfy the norm)