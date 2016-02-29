#include "Geometry.h"
#include "ErrorManagement.h"
#include <iostream>
#include <fstream>

using namespace std;

//	4
//	0 0 0 0 45 0 0 1 0.1 0.1 0.1  el primero es el id, los 3 sig son traslacion, el siguiente los angulos, los tres siguientes sobre que eje rota y los tres ultimos el escalado
//	1 0.6 0.6 0 0 0 0 0 0.05 0.05 0.05
//	2 0 - 0.9 0 0 0 0 0 1 0.1 0.1
//	2 0 0.9 0 0 0 0 0 1 0.1 0.1

/*
* Constructor 
*/
Geometry::Geometry(){
	_numVertices[RED_CUBE] = 36;
	_verticesData[RED_CUBE] = new Vertex[36];
	_verticesData[RED_CUBE][0].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][1].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][2].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][3].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][4].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][5].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][6].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][7].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][8].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][9].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][10].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][11].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][12].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][13].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][14].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][15].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][16].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][17].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][18].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][19].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][20].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][21].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][22].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][23].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][24].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][25].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][26].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][27].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][28].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][29].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][30].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][31].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][32].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][33].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][34].setPosition(0, 0, 0);
	_verticesData[RED_CUBE][35].setPosition(0, 0, 0);
}


Geometry::~Geometry(){
	
}

/*
* Load the game elements from a text file
*/
void Geometry::loadGameElements(char fileName[100]){	
	/* Text format
	<number of game elements>
	<type of game element> <vec3 position> <angle> <vec3 rotation> <vec3 scale>	
	*/
	int numGameElements;
	GameObject tempObject;
	glm::vec3 vector3fElements;
	ifstream file;
	file.open(fileName);

	if (file.is_open()){
		//TODO: Read the content and add it into the data structure
		file >> tempObject._objectType;
		for (int i = 0; i < numGameElements; i++) {
			file >> tempObject._objectType >> tempObject._translate.x >> tempObject._translate.y >> tempObject._translate.z >> tempObject._angle
				>> tempObject._rotation.x >> tempObject._rotation.y >> tempObject._rotation.z >> tempObject._scale.x >> tempObject._scale.y >> tempObject._scale.z;

		}
		file.close();
	}
	else{
		string message = "The file "+ string(fileName)+" doesn't exists";
		ErrorManagement::errorRunTime(message);
	}

}

/*
* Get the vertices data for an specific object
* @param objectID is the identifier of the requested object
* @return Vertex * is an array with all the vertices data
*/
Vertex * Geometry::getData(int objectID){
	return _verticesData[objectID];
}

/*
* Get the number of vertices for an specific object
* @param objectID is the identifier of the requested object
* @return int is the number of vertices
*/

int Geometry::getNumVertices(int objectID){
	return _numVertices[objectID];
}

/*
* Get the number of elements to render
*/
int Geometry::getNumGameElements() {
	return _listOfObjects.size();
}

/*
* Get the number of vertices of an specific game element
* @param objectID is the identifier of the requested object
*/
GameObject & Geometry::getGameElement(int objectID) {
	return (_listOfObjects[objectID]);
}