#ifndef ACTIONS_H_
#define ACTIONS_H_

#include<string>

// enumeration type for actions on the myBag
namespace actions{
    enum action {newBag, fuse, add , del, sortIt, makeSet, read , flip , none};
}

using namespace actions;
action str2action(std::string s);

#endif /* ACTIONS_H_ */
