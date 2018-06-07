Perl Programming

Requirements and Specifications

This is what your program should do:

It should read all of its input from STDIN; i.e., you do not need to open any files. If you want to have your program read from a file stored on disk, just use Unix I/O redirection.

It should read the first line, and check that it matches the XML header format described earlier. If it does not, your program should output the error message "Not a Baby-XML file" and exit (by calling the "die" function, described in the lecture notes).
It should then go into a loop reading lines from STDIN.

For each line, it should use the power or Perl's regular expression-matching to scan for an open tag, a close tag, or an open-tag/close-tag pair together on a line. (Hint: the order in which you do these checks will matter.) If it finds any, it should do the following:

If the next match is an open tag, it should add that tag to a stack of currently open tags. It should print out the current line number, followed by ": OPEN ", followed by the tag name (without the angle brackets). This line should be indented, with the amount of indentation based upon the level of nesting; each extra level of nesting should be indented by an additional two spaces--like formatting nested blocks of code in C++ or Python. (See the sample output below for an example.)

If the match is a close tag, it should pop the topmost element off the stack of open tags, and compare that to the close tag, to make sure it matches (don't forget to exclude the close tag's '/' prefix when doing the comparison). If they match, print out a line similar to the line output for the open tag, but with "CLOSE" instead of "OPEN" in the message.

If the close tag doesn't match the curent top open tag on the stack, use "die" to print an error message that includes the line number, the expected closing tag, and the actual non-matching closing tag, and exit.

If the match is an open-tag/close-tag pair, it should handle it just like it saw an open followed by a close, as above, except you obviously don't have to push-then-pop it. You should print out both an OPEN and a CLOSE message as above, though. Again, if the close tag doesn't match the open tag, handle the error as above.

At the end of the input, check to make sure the open tags stack is empty, i.e., that every open tag has been closed. If not, again, use "die" to print out the list of still-open tags, then exit.

It should be obvious that you will also need to keep track of what line of the file you are on, to output this with the messages; don't forget to include the XML header line in the count.

Additional Perl Skills You Will Need

You will need a couple of slightly more advanced regular expression skills to do this assignment. When you do regular expression matching, the pattern can contain parenthesized subexpressions. The corresponding matching parts can be accessed afterwards as $1, $2, $3, etc.. So, if you did the following (recall that '\w' matches all alphanumeric characters):

    $a = "Here @123@ I am";
    if ($a =~ m/@(#?)(\w+)@/) {
      print "Found a match: prefix '" . $1 . "', string '" . $2 . "'\n";

    $a = "Here @#abc@ I am";
    if ($a =~ m/@(#?)(\w+)@/) {
      print "Found a match: prefix " . $1 . ", string " . $2 . "\n";
      print "Found a match: prefix '" . $1 . "', string '" . $2 . "'\n";
    }
    
it would print out:

    Found a match: prefix '', string '123'
    
    Found a match: prefix '#', string 'abc'
    
The first parenthesized part--"(#?)"--matches an optional '#', and the second parenthesized part--"(\w+)"--matches the alphanumeric part. Since the bracketing '@'s are part of the regular expression pattern, but not inside the parentheses, they are not part of the selections $1 or $2. Also, note that the first line of output has an empty string for the prefix ($1), because the optional '#' was not seen.

Sample Run

With the following input (available as a link here: hw8data.xml):

<?xml version="1.0"?>

<student>
  
  <name>John</name>
  
  <age>18</age>
  
  <address>123 Elm St.</address>
  
  <mother>
  
    <name>Jane</name>
    
    <age>48</age>
    
  </mother>
  
</student>

Your program should output:

2: OPEN student

  3: OPEN name
  
  3: CLOSE name
  4: OPEN age
  
  4: CLOSE age
  
  5: OPEN address
  
  5: CLOSE address
  
  6: OPEN mother
  
    7: OPEN name
    
    7: CLOSE name
    
    8: OPEN age
    
    8: CLOSE age
    
  9: CLOSE mother
  
10: CLOSE student

Whereas, the input:

<?xml version="1.0"?>

<student>
  
  <name>John
  
</student>

would produce the output:

2: OPEN student

  3: OPEN name
  
4: close tag "student" doesn't match current open tag "name".

And the input:

<?xml version="1.0"?>

<student>
  
  <name>John
  
will output:

2: OPEN student

  3: OPEN name
  
End of file with still-open tags: student, name.
