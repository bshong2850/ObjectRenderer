#pragma once
#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <string>
#include <windows.h>

#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
#include <OpenMesh/Core/Mesh/PolyMesh_ArrayKernelT.hh>
#include <OpenMesh/Core/Geometry/VectorT.hh>
#include <OpenMesh/Core/System/config.h>
#include <OpenMesh/Core/Mesh/Status.hh>
#include <OpenMesh/Tools/Utils/Timer.hh>

// subdivision header
#include <OpenMesh/Tools/Subdivider/Uniform/LoopT.hh>

#include <vector>
#include <cmath>
#include <OpenMesh/Core/Mesh/Handles.hh>
#include <OpenMesh/Tools/Subdivider/Uniform/SubdividerT.hh>

// Decimator header
#include <OpenMesh/Tools/Decimater/DecimaterT.hh>
#include <OpenMesh/Tools/Decimater/BaseDecimaterT.hh>
#include <OpenMesh/Tools/Decimater/ModBaseT.hh>
#include <OpenMesh/Tools/Decimater/ModQuadricT.hh>
#include <OpenMesh/Tools/Decimater/ModAspectRatioT.hh>
#include <OpenMesh/Tools/Decimater/ModNormalFlippingT.hh>
#include <OpenMesh/Tools/Decimater/ModProgMeshT.hh>
#include <OpenMesh/Tools/Decimater/ModIndependentSetsT.hh>

// Smoothing header
#include <OpenMesh/Tools/Smoother/SmootherT.hh>
#include <OpenMesh/Tools/Smoother/LaplaceSmootherT.hh>
#include <OpenMesh/Tools/Smoother/JacobiLaplaceSmootherT.hh>

class OpenMeshCore
{
private:
	struct MyTraits : public OpenMesh::DefaultTraits
	{
	};

	std::string p_Filesavepath;
	std::string p_Fileloadpath;
	typedef OpenMesh::PolyMesh_ArrayKernelT<MyTraits>  MyMesh;

	// ó�� �ҷ��� Mesh ����
	MyMesh p_originmesh;

protected:

public:
	// PolyMesh _polymesh;
	MyMesh _mymesh;
	bool printlog;

	// OpenMeshCore ������
	OpenMeshCore()
	{
		p_Filesavepath = "model/result/";
		p_Fileloadpath = "model/";
		//cube_generator();		
	}
	//~OpenMeshCore();



	// Mesh �� ����ִ��� Check
	bool CheckMesh();
	// Mesh �ҷ�����
	void ReadMesh(std::string filename);
	// Mesh ����
	void WriteMesh(std::string filename, OpenMesh::IO::Options opt);
	// Origin Mesh �޾ƿ���
	void GetOriginMesh();

	//total_work ��� current_work�� ������� ǥ��
	void PrintProgressPercent(int current_work, int total_work);

	// basic cube�� �����ؼ� mymesh�� �����ϴ� �Լ�
	void CubeGenerator();

	// Mesh�� ���ϴ� frome to vertex�� halfedge�� Ȱ���Ͽ� collapse�� �����ϴ� �Լ�
	void CollapsePoint(int fromvertexindex, int tovertexindex);
	// Mesh���� collapsecount ���� �ִ� halfedge �κп� collapse�� �����ϴ� �Լ�
	void CollapseIter(int collapsecount);

	// Mesh�� Iterial �� ��ŭ Subdivision ���ִ� �Լ�
	void LoopSubdivision(int Itercount);

	// Decimation
	void Decimation(double coef);

	// Smoothing
	void Smoothing(unsigned int Itercount);
	
	// Boundary Vertex ����
	void BoundaryVertexWrite(std::string filepath);

	// ��� �Լ��� �ɸ��� �ð� ���� �� txt ���Ϸ� ����
	std::ofstream writeFile;
	void Writetime(std::string functionname, double second);
	void AllFunctionTimeCheck(std::string filename, std::string filepath);

};

#endif