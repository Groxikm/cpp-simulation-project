#ifndef MASSCELL_HPP
#define MASSCELL_HPP

class MassCell : public AbstractCell, public MovableInterface {
public:
    MassCell(long id, float x, float y, float mass, float speed, float direction);
    float getMass();

private:
    MassCell();
protected:
    float mass;
};

#endif // MASSCELL_HPP
