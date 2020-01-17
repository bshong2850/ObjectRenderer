
#include <iostream>
#include <typeinfo>

#include "core.h"

#include <Windows.h>
using namespace std;

int main(int argc, char ** argv)
{

	OpenMeshCore OMC;

	OMC.AllFunctionTimeCheck("basic_cube.stl", "function_timecheck.txt");
	OMC.ReadMesh("basic_cube.stl");
	OMC.BoundaryVertexWrite("basic_cube.bv");

	


	
	return 0;
}


