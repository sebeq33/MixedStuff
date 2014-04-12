#ifndef ISELECTABLE_H_
# define ISELECTABLE_H_

#include <stdint.h>

class ISelectable
{
public:
    virtual ~ISelectable() {}
    virtual int32_t getFD() const = 0;
};

#endif