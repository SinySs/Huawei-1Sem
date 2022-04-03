#ifndef POISON_H_INCLUDED
#define POISON_H_INCLUDED


#define PtrOk(ptr, type) ((ptr) != NULL && (ptr) != (type*)UninitializedPtr && (ptr) != (type*)FreedPtr)

#define LOCATION(obj) { #obj, __FILE__, __FUNCTION__, __LINE__ }

enum poisons{
    UninitializedPtr =  10,
    UninitializedInt = -13,

    FreedElem    = -12,
    FreedPtr        = 13
};

#endif // POISON_H_INCLUDED
