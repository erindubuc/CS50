# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

Pneumonoultramicroscopicsilicovolcanoconiosis is an invented long word said to mean a lung
disease caused by inhaling very fine ash and sand dust.

## According to its man page, what does `getrusage` do?

getrusage() returns resource usage measures for who, which can be one of the following:
RUSAGE_CHILDREN, RUSAGE_THREAD, or RUSAGE_SELF.
RUSAGE_SELF returns resource usage statistics for the calling process, which is the sum of resources used by all threads in the
process.

## Per that same man page, how many members are in a variable of type `struct rusage`?

There are 16 members in a variable type `struct rusage`.

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

Even though we are not changing their contents, I think we pass `before` and `after` by reference, instead of by value,
so we can access just their memory addresses. Passing by reference means that you are passing the memory of the address of the variable,
versus passing the value which will create another instance in the memory.  Therefore, when you pass the value, the return value in the memory is copied
to another location.  Passing by reference is easier on memory.


## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

The `main` function works as follows:
After checking for the proper command-line arguments, the structures for resource usage measures are declared, and benchmarking time variables are initialized.
`main` calls for the dictionary to be loaded and returns true if successful.  The resource usage will be reported for before and after loading.
Then, the text file called for from the command-line will be opened, and variables for index, num of misspelled words, and num of words in dictionary are initialized.
Also, a variable for the word being checked is created which allows speller to get the index of the char being passed in.
When the file is opened, fgetc checks each character while it is not the "end of the file".  If the char is an alpha, or is an apostrophe, at an index greater than 0,
the char will be added to a word and the index of that word will be incremented by one.  If the index of a char being read is larger than 45 (LENGTH), the index will be set back to 0
to start looking for a new word.  Words containing numbers will be ignored and the index will be set back to 0.
If the index of the char within a word is greater than 0, and it is the end of the word, the word counter will increment by 1.  The word will be checked by the check function and the
resource usage measures of before and after will be collected.  The word will be checked for being misspelled and the index will be set back to 0 to begin
checking the next word.
If there are errors with the text file, it will be closed and the dictionary will be unloaded.
The size of the dictionary and the time to determine it's size will be calculated, and then the dictionary will be unloaded.  The time to unload the dictionary will be calculated,
and 0 will be returned if all was successful.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

I think we used `fgetc` to read each word's characters one at a time because we are checking the words from the text file against the dictionary. Checking each character one at a time makes the most sense to spell check.
If we used `fscanf`, we would be reading whole strings at a time, so we might run into a problem with words containing apostrophes.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

I think that we declared the params for `check` and `load` as constants because they are pointers.  We don't want to be changing these values since we will always need to load the dictionary
and check words from a text file.  We want check and load to get these constants from their addresses.
