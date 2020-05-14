#include "RobotBehaviour.h"

RobotBehaviour::RobotBehaviour(size_t const xSize, size_t const ySize, Robot &robot){


	_fields.reserve(xSize);
	for (size_t x = 0; x < xSize; ++x)
	{
		_fields.push_back(std::vector<FieldInfo>());
		_fields[x].reserve(ySize);
		for (size_t y = 0; y < ySize; ++y)
			_fields[x].push_back(FieldInfo());
	} //attributes are initialized as false in the constructor

_robot=robot;

}


void RobotBehaviour::reinit(){






}








bool RobotBehaviour::explore(Position const& startPosition, Direction const &startDirection)
{

    
    
    
    
    
    while (!robot.isInExit())
	{

/*tu trzeba pewnie wpisać jeszcze sporo rzeczy*/ 

        int fieldIndex=0; //tymczasowo
        int nextFieldIndex=0; //tymczasowo

        if(!_maze.isWallW(_fields[fieldIndex]._position)){
            Position nextFieldPosition=_fields[fieldsIndex]._position;
            --nextFieldPosition._x;
            processField(fieldIndex,nextFieldPosition);
        }

        if(!_maze.isWallE(_fields[fieldIndex]._position)){
            Position nextFieldPosition=_fields[fieldsIndex]._position;
            ++nextFieldPosition._x;
            processField(fieldIndex,nextFieldPosition);
        }

        if(!_maze.isWallS(_fields[fieldIndex]._position)){
            Position nextFieldPosition=_fields[fieldsIndex]._position;
            ++nextFieldPosition._y;
            processField(fieldIndex,nextFieldPosition);
        }

        if(!_maze.isWallN(_fields[fieldIndex]._position)){
            Position nextFieldPosition=_fields[fieldsIndex]._position;
            --nextFieldPosition._y;
            processField(fieldIndex,nextFieldPosition);
        }   
        _fields[fieldIndex]._processed=true;
    }

return false;
}

//G
void RobotBehaviour::forwardAndUpdate()
{
    switch (_robotDirection)
    {
    case N:
        _robotPosition._y--;
        break;

    case S:
        _robotPosition._y++;
        break;    

    case W:
        _robotPosition._x--;
        break;

    case E:
        _robotPosition._x++;
        break;
    
    default:
        break;
    }

}

//G
void RobotBehaviour::turnLeftAndUpdate()
{
    switch (_robotDirection)
    {
    case N:
        _robotDirection=W;
        break;

    case W:
        _robotDirection=S;
        break;    

    case S:
        _robotDirection=E;
        break;

    case E:
        _robotDirection=N;
        break;
    
    default:
        break;
    }
}


//G
void RobotBehaviour::turnLeftAndUpdate()
{
    switch (_robotDirection)
    {
    case N:
        _robotDirection=E;
        break;

    case E:
        _robotDirection=S;
        break;    

    case S:
        _robotDirection=W;
        break;

    case W:
        _robotDirection=N;
        break;
    
    default:
        break;
    }
}



int RobotBehaviour::findField(Position const& position) const{



}





int RobotBehaviour::findNextField() const{




}




//G
void RobotBehaviour::processField(int const previousField, Position const& fieldPosition)
{
    int fieldIndex=-1;
    if(findField(fieldPosition)==-1){
        //field not found, add field
        _fields.push_back(FieldInfo(fieldPosition,_fields[previousFieldIndex].position/*,coś tu*/));
    }
    else
    {
        //field is on the list
        if(_fields[fieldIndex]._routeCost>_fields[previousFieldIndex]._routeCost+1)
        {
            //new route is shorter -update
            _fields[fieldIndex]._routeCost=_fields[fieldIndex]._routeCost+1;
            _fields[fieldIndex]._previousField=_fields[fieldIndex]._position;
        }
    }

}



int RobotBehaviour::distanceToExit(Position const& position) const{
    int distance=0;





}



void RobotBehaviour::setVisitedAndLookAround(){





}




//G
void RobotBehaviour::moveTo(Position const& newPosition)
{
    _robot.teleport(newPosition);
    _robotPosition=newPosition;
}
