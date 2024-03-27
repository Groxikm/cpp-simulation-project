#ifndef ABSTRACTCELL_HPP
#define ABSTRACTCELL_HPP

class AbstractCell {
public:
    
    long getID();
    float getX();
    float getY();

private:
    AbstractCell();

protected:
    const long id;
    float x,y;
};

#endif // ABSTRACTCELL_HPP
