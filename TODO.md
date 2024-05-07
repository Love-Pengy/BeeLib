# TODO For BeeLib

+ ~~fix list prepending in dynamic array~~ 
+ ~~fix seg fault for line 15 of prependTest.c~~
+ ~~practice using snprintf instead of strcpy and strcat~~
+ ~~put header guards silly!~~
+ make a hash table for the hash set and map modules
    + ~~test addElement and createHashTable functions~~
    + ~~figure out if theres a way to figure out later on what the type of a void pointer is otherwise create a struct for the values~~ 
         + ~~this doesn't seem very viable as hash tables seem to me to be specified by way of its data, but if I wanted to I could create a struct that holds all primitives easily by using a union and an enum specifying type~~
    + ~~handle collisions (when two keys get the same hash)~~
        + ~~in the remove function we need to be checking if the key exists as well as getting the offset for collisions~~
    + handle rehashing (when the table is too smalll for the next element)
    + make MAX_SIZE not global so that all hash tables can have their own rehash time (put it inside the struct)


+ make hash set 
+ make hash map 
+ make generics
+ move doubly linked list from WColumn
+ do singly linked list 
+ do a queue 
