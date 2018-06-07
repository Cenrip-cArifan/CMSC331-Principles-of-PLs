#File: hw8.pl
#Name: Gabriel Kilungya
#Date: 12/13/17
#Email: kilgab1@ubc.edu

#!/usr/bin/perl

@tagList = ();  
$line = <STDIN>; 
$openTag; 
$closeTag; 
$topOfStack; 
$numOfTags; 
$indents;

if ($line !~ /\<\?xml\sversion=\"1\.0\"\?>/) { 
    die "Not a Baby-XML file\n"; 
}
else{

    while($line = <STDIN>){

	#if the line we are on is open & close tag match
	#print the line number, "OPEN" and the tag itself
        #then it's matching close tag, the line number, "CLOSE" and the
        #tag itself


	if ($line =~ m/(<)(\w+)(>)([\s]?(\w+\.?)[\s]?)+(<\/)(\w+)(>)/){
	    
	    $numOfTags = @tagList;
	    $indents = "  " x $numOfTags;
	    $openTag = $2;
	    
	    print $indents, "$.: OPEN $openTag", "\n";
	    
	    $closeTag = $6;
	    print $indents, "$.: CLOSE $2", "\n";
	    next;
	}
	
	#else if the line we are on is only an open tag
	#push the tag on the stack @tagList
	#print the line number, "OPEN" and the tag itself
	elsif ($line =~ m/(<)([\s]?(\w+)[\s]?)+(>)/){
	    
	    $openTag = $2;

	    $numOfTags = @tagList;
	    $indents = "  " x $numOfTags;

	    print $indents, "$.: OPEN $openTag", "\n";
	    
	    push(@tagList, $openTag);
	    next;
	}

	#if the line we are on is another open tag (neseted open tag)
	#push the tag on the stack @tagList as well
	#print the line indented two spaces, the line number
	#"OPEN" and the tag itself
	if ($line =~ m/(<)([\s]?(\w+)[\s]?)+(>)/){
	    

	    $openTag = $2;
	    
	    $numOfTags = @tagList;
	    $indents = "  " x $numOfTags;
	    
	    print $indents, "$.: OPEN $openTag", "\n";

	    push(@tagList, $openTag);
	    next;
	}
	
	#else if the line we are on is open & close tag match
        #print both tags
        #first the open tag, the line number, "OPEN" and the tag itself
	#then it's matching close tag, the line number, "CLOSE" and the
	#tag itself

	elsif ($line =~ m/(<)(\w+)(>)([\s]?(\w+\.?)[\s]?)+(<\/)(\w+)(>)/) {
	    $numOfTags = @tagList;

	    $indents = "  " x $numOfTags;
	    $openTag = $2; 
	    print $indents, "$.: OPEN $openTag", "\n";
	    $closeTag = $6; 
	    print $indents, "$.: CLOSE $2", "\n"; 
	    next;
	}

	#if the line we are on is a closing tag
	#compare the close tag to the open tag, on top of the stack
	#if they are a macth, pop of the open tag
	#print the close tage: the line number, "CLOSE" and the tag itself
	#otherwise, use die function to print error message that includes:
        #line number, the expected closing tag, & the actual non-matching closing tag,
	

	if ($line =~ m/(<\/)([\s]?(\w+)[\s]?)+(>)/) {

	    $closeTag = $2;
	    $topOfStack = pop(@tagList);

	    $numOfTags = @tagList;
	    $indents = "  " x $numOfTags;
	    
	    if($topOfStack eq $closeTag){
		print $indents, "$.: CLOSE $2", "\n";
		next;
	    }
	    else{
		die "closing tag $2 doesn't match current openTaging tag", $topOfStack, ".";
	    }

	    
	}

    }


    # check to make sure the open tags stack is empty; 
    #that every open tag has been closed. 
    #If not, use "die" to print out list of still-open tags, then exit.
    if($numOfTags != 0){
	die "End of file with still-openTag tags: ", join(", ", @tagList), "\n";
    }

    
}





