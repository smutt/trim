trim
====

Got tired of not having trim(), ltrim() and rtrim() in C so I wrote them.

// Remove all characters in *c from left and right of *dest
char *trim(char *dest, char *c)

// Remove all characters in *c from left of *dest
char *ltrim(char *dest, char *c)

// Remove all characters in *c from right of *dest
char *rtrim(char *dest, char *c)
