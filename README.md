# CS203_Project
1. NOTE-FOR NEGATION USE '!' IN PLACE OF '
2. NOTE-max number of variable allowed is 11.
3. NOTE-if a term in expression does not contain all variable then add all value contain in group.
4. EXAMPLE-in 3 variable expression if a term is AC! then it is combination of ABC! and AB!C! then we have to add remain term,program take value of a term of in which missing 
   variable present in negation. you have to enter minterm value of remaing term in the group, like in example program automatically take AB!C! (because reamining variable 
   present in negation) and then remain term is ABC! so,we have to enter minterm value of ABC! which is 3.

HERE I PRESENT OUTPUT OF OUR PROGRAM TO EXPLAIN PROPERLY
---
```
Please enter expression in SOP and check that all term are a midterm in expression  //line 1
AB!C+ABC+AC!                                                                        //line 2
No. Of term     minterm value                                                       //line 3
1               value =5                                                            //line 4
2               value =7                                                            //line 5
3               value =1                                                            //line 6
if you want add term (add in min term value form) type 'Y' else 'N'                 //line 7
Y                                                                                   //line 8

ENTER TOTAL number of terms you want to add                                         //line 9                                   
1                                                                                   //line 10
enter value of min term                                                             //line 11
3                                                                                   //line 12

The minimized function is :- A                                                      //line 13
```
---
1. In line 2, we give our input in SOP form.
2. from line 3 to 6, our program present minterm value of terms we enter in SOP expreesion, 
3. in line 3, 'No. Of term' mean order of term in expreesion like AB!C is first term, ABC is second term and AC! is third term
4. NOW, in our input expreesion, third term(AC!) does not contain all variable ('B' is missing), means it represent 'AB!C!' and 'ABC!', now our program only take those term 
    in which missing term is present in negation(here 'AB!C!'), so we have to enter value remaing term in minterm value (ABC! = 3)
5. In line 7, program ask either you want to enter any remaing term or not (here ABC! is remaing so, we type 'Y')
6. In line 9, program ask number of remaing term(here only ABC! is remaing so, we give 1 as input)
7. In line 11, program ask value of remaining terms minterm value, one at a time (here minterm value is ABC! = 3)
8. In Line 13, program give final output.
I suppose this will helpful to understand, if you have any confusion pelease let us know.
thanks.
