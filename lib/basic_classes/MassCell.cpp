#include <MassCell.hpp>
#include <Simulation.hpp>
#include <math.h>
MassCell::MassCell(long id, float x, float y, float mass, float speed, float direction) {
	this.id = id;
	this.x = x;
	this.y = y;
	this.mass = mass;
	this.speed = speed;
	this.direction = direction;
}
long MassCell::getID(){
	return id;
}
float MassCell:: getX(){
	return x;
}
float MassCell::getY(){
	return y;
}
float MassCell::getMass(){
	return mass;
}
float MassCell::getSpeed(){
	return speed;
}
float MassCell::getDirection(){
	return direction;
}
MassCell::setVelocity(float speed, float direction){
	this.speed = speed;
	this.direction = direction;
}
MassCell::move(){
	float dt = Simulation::dt;
	this.x += Math.cos(direction*Math.Pi/180.)*speed*dt;
	this.y += Math.sin(direction*Math.Pi/180.)*speed*dt;
}