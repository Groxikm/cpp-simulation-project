#ifndef ABSTRACTCELL_HPP
#define ABSTRACTCELL_HPP

class AbstractCell {
//private:
//    virtual ~AbstractCell() = default;
public:
//    AbstractCell(long given_id);
    virtual long getID() = 0;
    virtual void setX(float x) = 0;
    virtual float getX() = 0;
    virtual void setY(float y) = 0;
    virtual float getY() = 0;
};

#endif // ABSTRACTCELL_HPP
