# ifndef _CALLBACKS_H_
# define _CALLBACKS_H_

typedef int (*action)(void*) ;
typedef char* (*action_s)(void*) ; // passer un accesseur de chaine de caractère en paramètre
typedef int (*comparator)(void*, void*);

# endif /* _CALLBACKS_H_ */
