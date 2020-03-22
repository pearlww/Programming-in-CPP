#include "actions.h"
// translation of strings into actions
action str2action(std::string s){
    if (s=="newBag") return newBag;
    if (s=="fuse") return fuse;
    if (s=="add") return add;
    if (s=="del") return del;
    if (s=="sortIt") return sortIt;
    if (s=="makeSet") return makeSet;
    if (s=="read") return read;
    if (s=="flip") return flip;
    return none;
}
