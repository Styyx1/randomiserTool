# Randomiser Tool

Linux CLI tool to randomise any amount of integers you pass.  
Will probably be expanded as i need more randomisers myself.

## Current functions

```bash
rando 56 22 12
```

this will generate a random number between 1 and the passed integer. You can pass as many as you need.

```bash
rando --mii
rando -m
```

this is the reason I made this tool. Generates random numbers for the Mii appearance selection in Tomodachii Life: Living the Dream  
example output

```bash
---------Mii Creator----------
Male
------------Styles------------
Face Shape: 3
Hair Style: 157
Bangs: 66
Hair Back: 91
Eyebrows: 19
Eyes: 50
Nose: 24
Mouth: 31
Ears: 3
Glasses: 38
-------------Age--------------
Day: 21
Month: 12
Age: 59
```

Dice roll function

```bash
rando --dice 12 20
rando -d
```

rolls a dice with x many sides y times.  
if no number is passed, it's a 6 sided dice once.  
