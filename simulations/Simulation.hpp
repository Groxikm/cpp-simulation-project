class Simulation {
public:
    Simulation(float time_coeff, float gravity_coeff, float reaction_coeff, bool ceiling, float ground_width, float walls_height); //better to use vectors, later

    virtual float getTimeCoefficient() = 0;
    virtual void setTimeCoefficient(float time_coeff) = 0;
    virtual float getGravityCoefficient() = 0;
    virtual void setGravityCoefficient(float gravity_coeff) = 0;
    virtual float getReactionCoefficient() = 0;
    virtual void setReactionCoefficient(float reaction_coeff) = 0;
    virtual bool isCeiling() = 0;
    virtual void setCeiling(bool ceilor) = 0;
    virtual float getGroundWidth() = 0;
    virtual void setGroundWidth(float ground_width) = 0;
    virtual float getWallsHeight()  = 0;
    virtual void setWallsHeight(float walls_height) = 0;;

private:
    const static float dt;
    float timeCoefficient;
    float gravityCoefficient;
    float reactionCoefficient;
    bool ceilor;
    float groundWidth;
    float wallsHeight;

protected:

};