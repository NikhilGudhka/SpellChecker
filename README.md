# SpellChecker
Command Line interface Spell Checker Written in C 

Reads the relevant files, stores the relevant data, checks the autocorrect value in the 
setting (spellrc) file, if yes autocorrects to its best ability, if no the asks the user 
if he/she would like to accept the suggested word, lastly writes to file.

FILES
----------------------------------------------------------------------------------------
    spellchecker.c - the main of the spellchecker program
    settings.c - reads the settings file
    settings.h - header file for settings.c
    user.c - reads the user file
    user.h - header file for user.c
    dictionary.c - reads the dictionary file
    dictionary.h - header file for dictionary.c
    check.c - file to perform the check
    check.h - header file for check.c
    callBackFunc.c - the call back function to replace suggested words
    callbackFunc.h - header file for callbackFunc.c
    write.c - writes to the output file
    write.h - the header file for write.c
    spellrc - the settings file
    dictionary.txt - dictionary file
    makefile - the makefile for the program
========================================================================================

COMPILING & EXECUTING
----------------------------------------------------------------------------------------
    Execute the makefile in the src directory (using make)
    ./spellchecker "filename to check and correct" to execute the program
    (quotes not included in filename and the file should be in the same directory with executable)
========================================================================================

SETTINGS FILE (spellrc)
----------------------------------------------------------------------------------------
maxcorrection - Difference in characters between actual and misspelt word the program 
                should consider.
dictionary - The dictionary file to use to look up the correct spelling of words
autocorrect - Set "yes" to autocorrect, "no" for manual selection per misspelt word where
              the user is asked to accept/reject the suggested word for each misspelt word
              (quotes not included)
========================================================================================

VALGRIND ISSUES
----------------------------------------------------------------------------------------
    NONE
========================================================================================
