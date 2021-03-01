# Expression Parser

** I need to take a few days off because I'm really feeling the burnout, I'll resume work on this project in a few days **

This is the beginning of a project I've wanted to do for awhile now.  I've been interested in how computers can make sense of a programming language and making
a basic expression parser like this seems to be the best project to play around with how it works.  
Most of the information will be taken and ported from the section on expression evaluation in Lafore's Data strucutres and algorithms book.  I don't think that 
implementation uses any kind of token system, so I'm hoping to add that in the future.  This may also become a basic scheme interpreter someday, who knows.

# What this lacks and plans for the future

This is a working expression parser, it's definitely not complete, but it works for single digit numbers 0-9 and +-/* operators.  The main feature this lacks is a
proper tokenizer (there really isn't one right now) and parser.  Without a tokenizer and parser, there's no way to take in anything more than a single char, which
limits the uses of this to no more than a fun experiment.  I'd like to implement those in the future, but as of right now, there's still a lot I need to learn 
before I feel like I can comforatbly add those features. 

# New and improved

After finding the book *Crafting Interpreters* by Bob Nystrom, I've felt much more confident about actually fixing this project up.  *Crafting Interpreters* focuses 
less on the theory of how compilers/interpreters work and more on how to actually build one.  It's been an amazing resource so far and I feel much more confident 
in really making this expression parser work properly.

With that being said, as I work through the book, I'm planning to take what I've learned and apply it to this project and actually make it work as it should. 
It is much simpler than actually writing a full new langauge interpreter, but still enough of a challenge that it stays fun.  
I've separated this project into two separate files, mainly because the whole system needs a rewrite and trying to retrofit tokens into the system I've already got
is something I just don't really feel like doing.  I'll use it as a template for sure, but I think I'd spend more time trying to get it to work with the tokens than
I would just rewriting one that works with tokens.  

When this is all finished, it should resemble more of an interpreter and less of a few fancy algorithms mixed together.  I'm currently working on the AST and I'm not
sure there's a whole lot to do after that is finished. 
