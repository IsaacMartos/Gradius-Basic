#pragma once
#include  "Objeto.h"

class Actor : public Objeto
{

protected:
	char actorRepresentation;

public:
    Actor(int posX, int posY, char rep) : Objeto(posX, posY), actorRepresentation(rep)
    {
	    
    }

    virtual void BeginPlay() = 0;

    virtual void Tick() = 0;

    virtual void OnCollision() {}

    char GetActorRepresentation() const {
        return actorRepresentation;
    }
	 
};

