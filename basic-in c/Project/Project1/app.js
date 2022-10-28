var rl = require('readline-sync');
var name;
var grade;

console.log("-------------------------------------------------------------");
console.log("-----------------Program check score student-----------------");
console.log("-------------------------------------------------------------");

var exit = 'N';
while(exit.toUpperCase() != 'Y')
{
    name = rl.question("Enter name : ");
    grade = rl.questionInt("Enter score : ");

    if(grade>=80 && grade<=100) //condition expression
    {
        console.log(name +" got grade A"); //statement
    } 
    
    else if(grade>=70 && grade<=79)
        {
            console.log(name +" got grade B");
        } else if(grade>=60 && grade<=79)
            {
                console.log(name +" got grade C");
            } else if(grade>=50 && grade<=59)
                {
                    console.log(name +" got grade D");
                }else
                    {
                        console.log(name +" got grade F");
                    } 
    exit = rl.question("\nDo you want to exit Y/N : ");
    console.log("\n");
    
}
console.log("-------------------------------------------------------------\n");
console.log("-------------------------------------------------------------\n");