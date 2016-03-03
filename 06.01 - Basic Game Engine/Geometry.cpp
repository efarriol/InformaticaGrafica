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
	loadCube(BLUE_CUBE, glm::vec4(0, 0, 255, 255));
	loadCube(RED_CUBE, glm::vec4(255, 0, 0, 255));
	loadCube(WHITE_CUBE, glm::vec4(255, 255, 255, 255));
	
}
void Geometry::loadCube(int i, glm::vec4 color)
{
		_numVertices[i] = 36;
		_verticesData[i] = new Vertex[36];

		_verticesData[i][0].setPosition(0, 0, 0);
		_verticesData[i][1].setPosition(1, 0, 0);
		_verticesData[i][2].setPosition(0, 1, 0);

		_verticesData[i][3].setPosition(1, 0, 0);
		_verticesData[i][4].setPosition(1, 1, 0);
		_verticesData[i][5].setPosition(0, 1, 0);

		_verticesData[i][6].setPosition(1, 0, 0);
		_verticesData[i][7].setPosition(1, 0, 1);
		_verticesData[i][8].setPosition(1, 1, 0);

		_verticesData[i][9].setPosition(1, 0, 1);
		_verticesData[i][10].setPosition(1, 1, 1);
		_verticesData[i][11].setPosition(1, 1, 0);

		_verticesData[i][12].setPosition(1, 0, 1);
		_verticesData[i][13].setPosition(0, 0, 1);
		_verticesData[i][14].setPosition(1, 1, 1);

		_verticesData[i][15].setPosition(0, 0, 1);
		_verticesData[i][16].setPosition(0, 1, 1);
		_verticesData[i][17].setPosition(1, 1, 1);

		_verticesData[i][18].setPosition(0, 0, 1);
		_verticesData[i][19].setPosition(0, 0, 0);
		_verticesData[i][20].setPosition(0, 1, 1);

		_verticesData[i][21].setPosition(0, 0, 0);
		_verticesData[i][22].setPosition(0, 1, 0);
		_verticesData[i][23].setPosition(0, 1, 1);

		_verticesData[i][24].setPosition(0, 1, 0);
		_verticesData[i][25].setPosition(1, 1, 0);
		_verticesData[i][26].setPosition(0, 1, 1);

		_verticesData[i][27].setPosition(1, 1, 0);
		_verticesData[i][28].setPosition(1, 1, 1);
		_verticesData[i][29].setPosition(0, 1, 1);

		_verticesData[i][30].setPosition(0, 0, 0);
		_verticesData[i][31].setPosition(0, 0, 1);
		_verticesData[i][32].setPosition(1, 0, 1);

		_verticesData[i][33].setPosition(0, 0, 0);
		_verticesData[i][34].setPosition(1, 0, 1);
		_verticesData[i][35].setPosition(1, 0, 0);

		for (int j = 0; j < 36; j++) _verticesData[i][j].setColor[color];
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

