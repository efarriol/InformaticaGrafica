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
	max = 1;
	min = -1;
	loadCube(BLUE_CUBE, glm::vec4(0, 0, 255, 255));
	loadCube(RED_CUBE, glm::vec4(255, 0, 0, 255));
	loadCube(WHITE_CUBE, glm::vec4(255, 255, 255, 255));
	
}
void Geometry::loadCube(int i, glm::vec4 color)
{
		_numVertices[i] = 36;
		_verticesData[i] = new Vertex[36];

		_verticesData[i][0].setPosition(min, min, min);
		_verticesData[i][1].setPosition(max, min, min);
		_verticesData[i][2].setPosition(min, max, min);

		_verticesData[i][3].setPosition(max, min, min);
		_verticesData[i][4].setPosition(max, max, min);
		_verticesData[i][5].setPosition(min, max, min);

		_verticesData[i][6].setPosition(max, min, min);
		_verticesData[i][7].setPosition(max, min, max);
		_verticesData[i][8].setPosition(max, max, min);

		_verticesData[i][9].setPosition(max, min, max);
		_verticesData[i][10].setPosition(max, max, max);
		_verticesData[i][11].setPosition(max, max, min);

		_verticesData[i][12].setPosition(max, min, max);
		_verticesData[i][13].setPosition(min, min, max);
		_verticesData[i][14].setPosition(max, max, max);

		_verticesData[i][15].setPosition(min, min, max);
		_verticesData[i][16].setPosition(min, max, max);
		_verticesData[i][17].setPosition(max, max, max);

		_verticesData[i][18].setPosition(min, min, max);
		_verticesData[i][19].setPosition(min, min, min);
		_verticesData[i][20].setPosition(min, max, max);

		_verticesData[i][21].setPosition(min, min, min);
		_verticesData[i][22].setPosition(min, max, min);
		_verticesData[i][23].setPosition(min, max, max);

		_verticesData[i][24].setPosition(min, max, min);
		_verticesData[i][25].setPosition(max, max, min);
		_verticesData[i][26].setPosition(min, max, max);

		_verticesData[i][27].setPosition(max, max, min);
		_verticesData[i][28].setPosition(max, max, max);
		_verticesData[i][29].setPosition(min, max, max);

		_verticesData[i][30].setPosition(min, min, min);
		_verticesData[i][31].setPosition(min, min, max);
		_verticesData[i][32].setPosition(max, min, max);

		_verticesData[i][33].setPosition(min, min, min);
		_verticesData[i][34].setPosition(max, min, max);
		_verticesData[i][35].setPosition(max, min, min);

		for (int j = 0; j < 36; j++) _verticesData[i][j].setColor(color.x, color.y, color.z, color.w);
}

void Geometry::loadPyramid(int pyramid, glm::vec4 color)
{

}



Geometry::~Geometry(){
	for (int i = 0; i < NUMBASICOBJECTS; i++) {
		delete _verticesData[i];
	}
}

/*
* Load the game elements from a text file
*/
void Geometry::loadGameElements(char fileName[100]){	
	/* Text format
	<number of game elements>
	<type of game element> <vec3 position> <angle> <vec3 rotation> <vec3 scale>	
	*/  
	GameObject tempObject;
	glm::vec3 vector3fElements;
	ifstream file;
	file.open(fileName);
	
	if (file.is_open()){
		//TODO: Read the content and add it into the data structure
		file >> tempObject._objectType;
		for (int i = 0; i < NUMBASICOBJECTS; i++) {
			file >> tempObject._objectType >> tempObject._translate.x >> tempObject._translate.y >> tempObject._translate.z >> tempObject._angle
				>> tempObject._rotation.x >> tempObject._rotation.y >> tempObject._rotation.z >> tempObject._scale.x >> tempObject._scale.y >> tempObject._scale.z;
			_listOfObjects.push_back(tempObject);
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

