# Hangman

C command-line [Hangman](https://en.wikipedia.org/wiki/Hangman_(game)) game.

## Requirements

 - [Make](https://www.gnu.org/software/make/)
 - [GCC](https://gcc.gnu.org/)

## Compilation

Navigate to the root of the repository from your Terminal and run `make` to build the `hangman` executable file.

## How to use Hangman?

The `hangman` executable expects a dictionary file as argument. Example:

```
./hangman samples/dict1.txt
```

Hangman will import the dictionary file & select a random word from it. Then it will show you the word & your tries left, and ask you to input a letter.

Beginning of a game example:

```
*******
Tries: 10
Your letter: a
a is not in the word.

*******
Tries: 9
Your letter: e

*e*****
Tries: 9
Your letter:
```

## Dictionary files format

You can find dictionary files samples in the `samples/` folder.

A dictionary is basically a list of word separated by new lines (`\n`). Example:
```
hospitality
chance
divorce
ensure
embrace
corner
middle
deposit
knock
instrument
```

## Authors

* **Alexis Jamet**
* **Ronan Boiteau** ([GitHub](https://github.com/ronanboiteau) / [LinkedIn](https://www.linkedin.com/in/ronanboiteau/))
