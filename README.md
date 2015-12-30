# get_next_line

#### Synopsis

`int		get_next_line(int const fd, char **line)`

#### Description

The function returns the line read from the file descriptor, `fd`. Characters followed by `'\n'` (ascii code `0x0a`) or by an End Of File (`E0F`) will be considered as a line. Each lines are stocked in `char **line`.

#### Return value

It will be  1, 0 or -1 respectively if the line has been read, the reading is finished or an error occured. The function return value without `'\n'`.
