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

	// 처음 불러온 Mesh 저장
	MyMesh p_originmesh;

protected:

public:
	// PolyMesh _polymesh;
	MyMesh _mymesh;
	bool printlog;

	// OpenMeshCore 생성자
	OpenMeshCore()
	{
		p_Filesavepath = "model/result/";
		p_Fileloadpath = "model/";
		//cube_generator();		
	}
	//~OpenMeshCore();



	// Mesh 가 비어있는지 Check
	bool CheckMesh();
	// Mesh 불러오기
	void ReadMesh(std::string filename);
	// Mesh 저장
	void WriteMesh(std::string filename, OpenMesh::IO::Options opt);
	// Origin Mesh 받아오기
	void GetOriginMesh();

	//total_work 대비 current_work의 진행률을 표시
	void PrintProgressPercent(int current_work, int total_work);

	// basic cube를 생성해서 mymesh에 저장하는 함수
	void CubeGenerator();

	// Mesh의 원하는 frome to vertex의 halfedge를 활용하여 collapse를 진행하는 함수
	void CollapsePoint(int fromvertexindex, int tovertexindex);
	// Mesh에서 collapsecount 마다 있는 halfedge 부분에 collapse를 진행하는 함수
	void CollapseIter(int collapsecount);

	// Mesh를 Iterial 수 만큼 Subdivision 해주는 함수
	void LoopSubdivision(int Itercount);

	// Decimation
	void Decimation(double coef);

	// Smoothing
	void Smoothing(unsigned int Itercount);
	
	// Boundary Vertex 저장
	void BoundaryVertexWrite(std::string filepath);

	// 모든 함수의 걸리는 시간 측정 후 txt 파일로 저장
	std::ofstream writeFile;
	void Writetime(std::string functionname, double second);
	void AllFunctionTimeCheck(std::string filename, std::string filepath);

};

#endif