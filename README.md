# fillit

42 school - Hive Helsinki - project.


The goal of this project is to arrange every Tetriminos with each others in order to make the smallest possible square. 
But in some cases, this square should contains holes when some given pieces won’t fit in perfectly with others.
Even if they are embedded in a 4x4 square, each Tetrimino is defined by its minimal boundaries (their ’#’). 
The 12 remaining empty characters will be ignored for the Tetriminos assemble process.
Tetriminos are ordered by they apparition order in the file. 
Among all the possible candidates for the smallest square, 
only the one where Tetriminos is placed on their most upper-left position is accepted. 

Program output:
The program displays the smallest assembled square on the standard output. 
To identify each Tetrimino in the square solution, a capital letter is assigned to each Tetrimino, 
starting with ’A’ and increasing for each new Tetrimino.
If the file contains at least one error, the program displays error on the standard output 
followed by a newline.

Example output: 

```
$> cat sample.fillit | cat -e
....$
##..$ 
.#..$
.#..$ 
$
....$ 
####$
....$ 
....$
$ 
#...$
###.$ 
....$
....$ 
$ 
....$
##..$ 
.##.$
....$
$> ./fillit sample.fillit | cat -e
DDAA$ 
CDDA$
CCCA$ 
BBBB$
$>
```
