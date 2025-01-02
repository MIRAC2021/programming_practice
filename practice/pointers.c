/* Here's your introduction to pointers! */

#include "stdio.h"  
#include "stdlib.h"

void update_to_five(int value) {
  value = 5;
}

void update_to_five_with_pointer(int* value) {
  *value = 5; // we'll get to this...
}

int main(int argc, char *argv[])
{
  // Start here!
  //
  // Pointers are, frankly, variables that store memory addresses.

  // for example:
  int x = 5;

  // x is a variable on the stack, but let's point to x.
  int* y = &x;

  // An asterisk, *, after a data type means a pointer to that type. while an 
  // ampersand, &, before a variable means the memory address of that variable.
  //
  // Since all "memory addresses" are the same type and size regardles of what
  // they're pointing to, all the data type really does (int*) is tell you what
  // to interpret the value being pointed to as. As a result, can also use a
  // float if we wanted to...
  float* z = &x;

  // Things like this can introduce nasty bugs... dereferencing a pointer of the
  // wrong type. So, what happens here is the value in memory at location &x will
  // be interpretted as a float even though it is an int. This can be even more 
  // dangerous if someone did this instead:
  double* a = &x;

  // Can you guess why this is more dangerous? an int is 4 bytes of memory on most
  // computers while a double is 8. This will lead to undefined behavior... primitives
  // data types are simple, but what about larger structs? needless to say, be careful.
  //
  // What if we want to convert a pointer of one type to another? It's simple enough by
  // casting as show below:
  int* b = (int*)z;

  // Now lets do some dumb stuff by making use of what pointers are. Pointers are, as
  // mentioned before, pointers to memory locations. what is being pointed to aside, what
  // about the value of the pointer? pointers are unsized integer types, so you can actually
  // assign a pointer to an integer:
  b = (int*)43;

  // This is only ever done in embedded systems as far as i know...
  //
  // Now, how about when it comes to dynamic memory allocation? as you know, we
  // can allocate of integers easily with malloc:
  int* arr = (int*)malloc(sizeof(int[100]));

  // do you understand the syntax? we have an integer pointer as designated by int*.
  // allocated memory equivalent to 100 integers, and we casted the pointer to an
  // int*. The malloc is ALWAYS heap allocated memory, however, 'int* arr' is on the 
  // stack. You could say that when you do dynamic memory allocation, you're making
  // two things at once: 1) a pointer on the stack pointing to the heap 2) a value on
  // the heap. don't be confused though, the pointer on the stack's value is the location
  // of the value on the heap.
  //
  // always free your memory...
  free(arr);

  // As for functions... functions copy the value of whatever is passed in. Lets make some
  // data:
  int d1 = 0;
  int d2 = 1;
  int d3 = 2;

  // Now lets make a function to update the value of a variable to 5.
  update_to_five(d1);

  printf("still 0... %d\n", d1);

  // the value is still 1. Why? Becase C copies the value of whatever is passed in.
  // When you call a update_to_five(d1), a copy of d1 is used inside the function, not
  // d1 itself. When the function ends, the copy of d1 is gone. The function has never
  // seen nor had access to the real and original d1.
  //
  // Now, this is where pointers come in handy. What if you passed a copy of the pointer?
  // in the previous case, we copied d1 which had the value of 1, but if we gave a function
  // a copy of a pointer, which would still point to the exact same memory address as the 
  // original, we could modify the data at the memory address, and the change would last.
  update_to_five_with_pointer(&d1);
  printf("now 5! %d\n", d1);

  // So, what about the strange syntax in the update_to_five_with_pointer function? The * on
  // the variable name. When you use an ampersand (&) on a variable, it means the memory address
  // of that variable. Asterisk is the reverse for example:

  int g = 0; // this is a normal variable
  int* h = &g; // this is a pointer to the memory address of g.
  *h; // this is g, or 0. The value at the location pointed to by h.

  return EXIT_SUCCESS;
}
