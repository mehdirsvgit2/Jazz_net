# C++ questions
1. Consider:
```
class window
{
...
};
class window_with_toolbar : public window
{
...
};
class window_with_menu : public window
{
...
};
class window_with_menu_and_toolbar : public window_with_menu,
public window_with_toolbar
{
...
};
```
What problem can you see and what change would you make to address it?

#### Answer
The problem here is Diamond problem that is a result of multi-inheritance  multiple inheritance. Imagine that class 
_window_ had a non-private property (e.g. _size_), then _window_with_menu_and_toolbar_ would not know to use the one 
that is inherited in _window_with_toolbar_ or _window_with_menu_

Solution to this problem is to _virtual_ inheritance. Then the _window_with_menu_and_toolbar_ would only have one 
instance of _window_ like this 


```
class window
{
...
};
class window_with_toolbar : virtual public window
{
...
};
class window_with_menu : virtual public window
{
...
};
class window_with_menu_and_toolbar : public window_with_menu,
public window_with_toolbar
{
...
};
```

2. Implement a class with a member function 'int nobjs()' which returns the number of object
of that class currently in existence. What assumptions have you made?

#### Answer
_Assumption_ The _++_ operation is NOT atomic so if we assume that there is no other thread accessing our class, This 
code would be working correctly.
codes are in cpp directory 
```
counter.h
counter.cpp
main_counter.cpp
```


3. Given:
```
struct node_t
{
unsigned v;
struct node_t* next;
};
```
A singly linked list of nodes is referred to by a pointer to the head node (the head pointer will be
NULL in the case of an empty list).
Write a function:
```
struct node_t* even_nodes(struct node_t**)
```
which is passed a pointer to the head pointer of a list. It should remove all nodes with even
values from the indicated list, putting them in a new list, which is returned.

#### Answer
Check 
```
linked_list.cpp
```

for implementation. 
