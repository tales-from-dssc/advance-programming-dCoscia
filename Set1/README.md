# Exercises - session 01

## uniq

Program = `uniq.cpp`
Input = `uniq_01_input.txt` or `uniq_02_input.txt`

- Simple version of the Unix program `uniq -c`, which, when fed with a text, outputs the same text with **consecutive** identical lines collapsed into one prepended with the number of repetitions.  You can redirect the content of a text to stdin trough the `<` operator
```
./a.out <a_file
```
## Getters

Program = `getters.cpp`

- Function `get_int` that reads from stdin until a valid number is fed
- Function `get_double` that reads from stdin until a valid number is fed.


## **Optional**: Text formatter

Program = `formatter.cpp`
Input = `filo.txt`

- Simple text formatter that breaks the lines longer than a given number of characters. This formatter does not break words and leaves unmodified the lines shorter than the given threshold.
