//main.cpp
//Raymond Baartmans
//Shunting Yard Algorithm

#include <iostream>
#include <cstring>

using namespace std;

struct node
{
  node * next;
  node * prev;
  char oper;
};

struct stack
{
  node * head;
};

struct queue
{
  node * queuehead;
  node * queuetail;
};

//prototype for finding whether char is op (2), num(1), or neither(0) OR (,)
int whatIsThisChar(char val);

//ptype for checking of op precedence is equal or greater
int doINeedToPop(char op1, char op2);

//function prototypes for operator stack
char pop(stack &thestack);
char peek(stack thestack);
void push(stack &thestack, char op);

//function prototypes for output queue
void enqueue(queue &theQ, char op);
node * dequeue(queue &theQ);

int main()
{
  int debugmode = 1;
  
  stack opStack; queue outputQ;
  
  cout << "Shunting Yard Algorithm" << endl;
  cout << "Enter an infix mathematical expression." << endl;
  
  char input [30];

  cin >> input;

  //clean up the input;
  
  char polishedinput [30];
  int counter = 0;//counter will also be the length of the array after done polishing 
  for (int i = 0; i < 30; i++)
    {
      if (input[i] == '\0')
	{
	  break;
	}
      else
	{
	  if (whatIsThisChar(input[i]) > 0)
	    {
	      polishedinput[counter] = input[i];
	      counter++;
	    }
	}
    }

  if (debugmode == 0)
    {
      char inputnum;
      cout << "Would you like your answer in Infix (type '1'), Prefix (type '2'), or Postfix (type '3')" << endl;
      cin >> inputnum;
      if (inputnum == 1)
	{
	  //Just spit the expression back out
	}
      else if (input == 2 || input == 3)
	{
	  for (int i = 0; i < counter; i++)
	    {
	      if (whatIsThisChar(polishedinput[i]) == 1)//if num
		{
		  enqueue(&outputQ, polishedinput[i]);
		}
	      else if (whatIsThisChar(polishedinput[i]) > 1 && whatIsThisChar(polishedinput[i]) < 4)//if op thats not a right parenth
		{
		  if (doINeedToPop(polishedinput[i], peek(opstack)) == 1)//check op precedence
		    {
		      pop(&opstack);
		    }
		  
		  push(&opstack, polishedinput[i]);
		}
	      else if (whatIsThisChar(polishedinput[i]) == 4)//if right parenth
		{
		  while (whatIsThisChar(peek(opstack)) != 3)//while no left parentheses at top
		    {
		      enqueue(&outputQ , pop(&opstack));//pop to output queue
		    }
		  pop(&opstack);//pop the left parentheses and advance.
		}
	    }//after this for loop the expression should be sorted into the queues

	  while (peek(opstack) != NULL)//move remaining ops into output queue
	    {
	      enqueue(&outputQ, pop(&opstack));
	    }

	  //Display output
	  
	}
      else
	{
	  cout << "Invalid Input." << endl;
	}
      
    }
  else if (debugmode == 1)//for debugging
    {
      push(opStack, '+');
      push(opStack, '-');
      push(opStack, '/');
      cout << "done pushing" << endl;
      cout << peek(opStack) << endl;
      cout << pop(opStack) << endl;
    }
}

//functions for stack
char pop(stack &thestack)
{
  char returnOp;
  node * temp = thestack.head->next;
  cout << "temp node made" << endl;
  thestack.head->prev->next = temp;
  temp->prev = thestack.head->prev->next;
  cout << "new head set" << endl;
  returnOp = thestack.head->oper;
  delete thestack.head;
  thestack.head = temp->prev;
  return returnOp;
}

char peek(stack thestack)
{
  return thestack.head->oper;
}

void push(stack &thestack, char op)
{
  node * newGuy; newGuy->oper = op;

  if (thestack.head == NULL)//if the stack is empty
    {
      thestack.head = newGuy;
    }
  else
    {
      newGuy->prev = thestack.head;
      thestack.head->next = newGuy;
      thestack.head = newGuy;
    }
}

//functions for queue
void enqueue(queue &theQ, char op)
{
  node * thenode; thenode->oper = op;
  
  if(theQ.queuetail == NULL)//if queue is empty
    {
      theQ.queuehead = thenode;
      theQ.queuetail = thenode;
    }
  else
    {
      thenode->next = theQ.queuetail;
      theQ.queuetail = thenode;
    }
}

node * dequeue(queue &theQ)
{
  node * temp = theQ.queuehead;
  theQ.queuehead = theQ.queuehead->prev;
  theQ.queuehead->next = NULL;
  return temp;
}

int whatIsThisChar(char val)
{
  //0 is neither, 1 is number, 2 is operator, 3 is left parenth, 4 is right parenth
  int opOrNum;
  
  if (val >= 48 && val <= 57)
    {
      opOrNum = 1;
    }
  else if (val == 40)
    {
      opOrNum = 3;
    }
  else if (val == 41)
    {
      opOrNum = 4;
    }
  else if ( (val >= 42 && val <= 43) || val == 45 || val == 47 || val == 94)
    {
      opOrNum = 2;
    }
  else
    {
      opOrNum = 0;
    }

  return opOrNum;
}

int doINeedToPop(char op1, char op2)
{//op2 is the one in stack
  int pop = 0; // if 1, need to pop

  if (op1 == op2)
    {
      pop = 1;
    }
  else if (op2 == '^')
    {
      pop = 1;
    }
  else if ( (op2 == '*' || op2 == '/') && (op1 == '*' || op1 == '/' || op1 == '+' || op1 == '-'))
    {
      pop = 1;
    }
  else if ( (op2 == '+' || op2 == '-') && (op1 == '+' || op1 == '-'))
    {
      pop = 1;
    }

  return pop;
}
