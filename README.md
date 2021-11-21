# CS203_Project
NOTE-FOR NEGATION USE '!' IN PLACE OF '
NOTE-max number of variable allowed id 11
NOTE-if a term in expression does not contain all variable then add all value contain in group
EXAMPLE-in 3 variable expression if a term is AC! then it is combination of ABC! and AB!C! then we have to add remain term,program take value of a term of in which missing variable present in negation. you have to enter minterm value of remaing term in the group, like in example program automatically take AB!C! (because reamining variable present in negation) and then remain term is ABC! so,we have to enter minterm value of ABC! which is 3.

HERE I PRESENT OUTPUT OF OUR PROGRAM TO EXPLAIN PROPERLY
--------------------------------------------------------------
Please enter expression in SOP and check that all term are a midterm in expression
AB!C+ABC+AC!

No. Of term     minterm value
1               value =5
2               value =7
3               value =1
if you want add term (add in min term value form) type 'Y' else 'N'
Y

ENTER TOTAL number of terms you want to add
1
enter value of min term
3

The minimized function is :- A
----------------------------------------------------------------
(1) In line 10, we give our input in SOP form.
(2) from line 12 to 15, our program present minterm value of terms we enter in SOP expreesion, 
(3) in line 12, 'No. Of term' mean order of term in expreesion like AB!C is first term, ABC is second term and AC! is third term
(4) NOW, in our input expreesion, third term(AC!) does not contain all variable ('B' is missing), means it represent 'AB!C!' and 'ABC!', now our program only take those term in     which missing term is present in negation(here 'AB!C!'), so we have to enter value remaing term in minterm value (ABC! = 3)
(5) In line 16, program ask either you want to enter any remaing term or not (here ABC! is remaing so, we type 'Y')
(6) In line 17, program ask number of remaing term(here only ABC! is remaing so, we give 1 as input)
(7) In line 18, program ask value of remaining terms minterm value, one at a time (here minterm value is ABC! = 3)
(8) In Line 19, program give final output.
I suppose this will helpful to understand, if you have any confusion pelease let us know.
thanks.
