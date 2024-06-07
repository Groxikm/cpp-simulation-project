#ifndef ABSTRACTCELL_HPP
#define ABSTRACTCELL_HPP

class AbstractCell {
//private:

public:
//    AbstractCell(long given_id);
//    virtual ~AbstractCell() = default; //no obvious sense in having a destructor in such interface
    virtual long getID() = 0;
    virtual void setX(float x) = 0;
    virtual float getX() = 0;
    virtual void setY(float y) = 0;
    virtual float getY() = 0;
};

#endif // ABSTRACTCELL_HPP
