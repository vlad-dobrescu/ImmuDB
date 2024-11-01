-- for now, still in development --

For Stack:

  -push : creates a new stack with a new top node // stack = stack.push(value)
  -top : just returns the top node value //stack.top()
  -pop : returns a new stack without the previous top node // stack = stack.pop()
  -isEmpty : returns a bool 

  -the constructor : just returns an empty stack for now
  -copy constructor : deep copies a stack into a new one // immutable::ImmutableStack<int> newStack = oldStack // this would work
  -destructor : If I would have made a destructor for the class Node like this: ~Node() { delete next; }  It would have deleted all the nodes
   recursively. This wouldn't be a good behavior for an immutable structure. The destructor is in the main class ImmutableStack