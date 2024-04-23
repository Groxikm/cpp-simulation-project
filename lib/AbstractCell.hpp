#ifndef ABSTRACTCELL_HPP
#define ABSTRACTCELL_HPP

class AbstractCell {
public:
    virtual ~AbstractCell() = default;
    virtual long giveID() = 0;
    virtual long getID() = 0;
};

#endif // ABSTRACTCELL_HPP
