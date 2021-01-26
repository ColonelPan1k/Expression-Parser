# Expression Parser

This is the beginning of a project I've wanted to do for awhile now.  I've been interested in how computers can make sense of a programming language and making
a basic expression parser like this seems to be the best project to play around with how it works.  
Most of the information will be taken and ported from the section on expression evaluation in Lafore's Data strucutres and algorithms book.  I don't think that 
implementation uses any kind of token system, so I'm hoping to add that in the future.  This may also become a basic scheme interpreter someday, who knows.

# What this lacks and plans for the future

This is a working expression parser, it's definitely not complete, but it works for single digit numbers 0-9 and +-/* operators.  The main feature this lacks is a
proper tokenizer (there really isn't one right now) and parser.  Without a tokenizer and parser, there's no way to take in anything more than a single char, which
limits the uses of this to no more than a fun experiment.  I'd like to implement those in the future, but as of right now, there's still a lot I need to learn 
before I feel like I can comforatbly add those features. 

