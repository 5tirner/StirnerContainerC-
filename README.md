### Stiner Container Depends On An UnderLying Container (LinkedList)
### Add Element In The Back Using The Memeber Function:
`addAtEnd(DataType val)` -> void, Throw Const Char* In Error Case.
### Add Element In The Front Using The Memeber Function:
`addAtbegin(dataType val)` -> void, Throw Const Char* In Error Case.
### Delete Element By Position Using The Memeber Function:
`removePosition(int Position)` -> void, Throw Const Char* In Error Case.
### See The Size Of Your Container Using The Memeber Function:
`getSize()` -> int, return size.
### Get The Content Of An Index Using The Member Function:
`getContentOfPosiotion` -> Data, Throw Const Char* In Error Case.
### Remove Range Of Index Using The Member Fucntion:
`removeRange(int From, int Until)` -> void, Throw Const Char* In Error Case (Until Excluded).
### Print All The Contenet Using The Member Function:
`getContentOfPosiotion` -> Print Conetent.
### Access To An Element By Using `Operator[]` -> Throw Const Char * In Error Case.
`Override The Value Of The Index Is Allowed`.
### Search For Index Of An Element By Using The Member Function:
`search(dataType val)` -> int, Return Position, Throw Const Char * In Error Case.
### Insert A Value In A Poition Using The Memmber Function:
`insertInPosition(int pos, dataType val)` -> void, Throw Const Char * In Error Case.

-------------------------------------------------------------------------------------------
### ==954804== Memcheck, a memory error detector:
`==954804== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.`\
`==954804== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info`\
`==954804== Command: ./a.out`
### ==954804==
`Size At Start = 9`\
`Content Of Pos 5 Is: 6`\
`Describe The Container: `\
`[ 1, 2, 3, 4, 5, 6, 7, 8, 9 ]`\
`Remove Index Number 4.`\
`Size After Remove Index 4 = 8`\
`Describe The Container Again: `\
`[ 1, 2, 3, 4, 6, 7, 8, 9 ]`\
`Add 0 At Begin.`\
`Size After Add 0 At Begin = 9`\
`Describe The Container Again: `\
`[ 0, 1, 2, 3, 4, 6, 7, 8, 9 ]`\
`Remove Elements From 0 To 3: `\
`Size After Delete The Range = 6`\
`Describe The Container Again: `\
`[ 3, 4, 6, 7, 8, 9 ]`\
`Value Of Index 1 Is: 4`\
`Describe The Container Again: `\
`[ 3, 10, 6, 7, 8, 9 ]`
### ==954804==
`==954804== HEAP SUMMARY:`\
`==954804==     in use at exit: 0 bytes in 0 blocks`\
`==954804==   total heap usage: 26 allocs, 26 frees, 74,112 bytes allocated`
### ==954804==
`==954804== All heap blocks were freed -- no leaks are possible`
### ==954804==
`==954804== For lists of detected and suppressed errors, rerun with: -s`\
`==954804== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)`
