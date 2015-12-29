# get_next_line

The function returns the line read from the file descriptor. Characters followed by `'\n'` (ascii code 0x0a) or by an End Of File (E0F) will be considered as a line.

#### Return value

It will be  1, 0 or -1 respectively if the line has been read, the reading is finished or an error occured. The function return value without `'\n'`.
