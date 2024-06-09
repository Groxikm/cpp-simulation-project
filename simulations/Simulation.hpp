#include "../lib/mass/MassCell.hpp"


#include <vector>
#include <memory>

class Simulation {
public:

    Simulation(float time_coeff, float gravity_coeff, float reaction_coeff, bool ceiling, float ground_width, float walls_height, long ID); //better to use vectors, later
    //field logic
    virtual float getTimeCoefficient() ;
    virtual void setTimeCoefficient(float m_time_coeff) ;
    virtual float getGravityCoefficient();
    virtual void setGravityCoefficient(float m_gravity_coeff) ;
    virtual float getReactionCoefficient();
    virtual void setReactionCoefficient(float m_reaction_coeff) ;
    virtual bool isCeiling() ;
    virtual void setCeiling(bool ceiling) ;
    virtual float getGroundWidth() ;
    virtual void setGroundWidth(float m_ground_width) ;
    virtual float getWallsHeight();
    virtual void setWallsHeight(float m_walls_height) ;
    virtual long getID() ;
    //objects logic
    virtual void instantiateMassCell(long id, float x, float y, float mass, float speed, float direction) ;
    virtual void destroyObject(std::shared_ptr<MassCell> cell);
    unsigned int getObjectAmount() {return object_amount;}

    virtual void applyGravity(std::shared_ptr<MassCell> cell) ;
    virtual void run();

private:
    const static float m_dt;
    float m_timeCoefficient;
    float m_gravityCoefficient;
    float m_reactionCoefficient;
    bool m_ceiling;
    float m_groundWidth;
    float m_wallsHeight;
    long m_ID;

    unsigned int object_amount;

protected:
    std::vector<std::shared_ptr<MassCell>> pointers;
};