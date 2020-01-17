#include "core.h"
#include <fstream>

void OpenMeshCore::Writetime(std::string functionname, double second)
{
	if (writeFile.is_open())
	{
		writeFile << functionname << std::endl;
		writeFile << "  - " << second << "sec" << std::endl << std::endl;
	}
}
void OpenMeshCore::AllFunctionTimeCheck(std::string filename, std::string filepath)
{
	OpenMesh::Utils::Timer timer;
	double secondruntime = 0;
	int test_count = 1;
	std::cout << "test_count = " << test_count << std::endl;
	printlog = false;

	writeFile.open(p_Filesavepath + filepath);

	// ReadMesh
	std::cout << "ReadMesh Start" << std::endl;
	double readmeshtotaltime = 0;
	timer.reset();
	for (int i = 0; i< test_count; i++)
	{
		PrintProgressPercent(i + 1, test_count);
		timer.start();
		ReadMesh(filename);
		timer.stop();
		readmeshtotaltime += timer.seconds();
	}
	Writetime("ReadMesh Runtime", readmeshtotaltime / test_count);
	std::cout << "ReadMesh Complete" << std::endl;

	// STL_Binary_WriteMesh
	std::cout << "STL_Binary_WriteMesh Start" << std::endl;
	double stlbinarywritemeshtotaltime = 0;
	timer.reset();
	for (int i = 0; i < test_count; i++)
	{
		PrintProgressPercent(i + 1, test_count);
		timer.start();
		WriteMesh(filename, OpenMesh::IO::Options::Binary);
		timer.stop();
		stlbinarywritemeshtotaltime += timer.seconds();
	}
	Writetime("STL_Binary_WriteMesh Runtime", stlbinarywritemeshtotaltime / test_count);
	std::cout << "STL_Binary_WriteMesh Complete" << std::endl;

	// STL_Ascii_WriteMesh
	std::cout << "STL_Ascii_WriteMesh Start" << std::endl;
	double stlasciiwritemeshtotaltime = 0;
	timer.reset();
	for (int i = 0; i < test_count; i++)
	{
		PrintProgressPercent(i + 1, test_count);
		timer.start();
		WriteMesh(filename, OpenMesh::IO::Options::Default);
		timer.stop();
		stlasciiwritemeshtotaltime += timer.seconds();
	}
	Writetime("STL_Ascii_WriteMesh Runtime", stlasciiwritemeshtotaltime / test_count);
	std::cout << "STL_Ascii_WriteMesh Complete" << std::endl;

	// GetOriginMesh
	std::cout << "GetOriginMesh Start" << std::endl;
	double getoriginmeshwritemeshtotaltime = 0;
	timer.reset();
	for (int i = 0; i < test_count; i++)
	{
		PrintProgressPercent(i + 1, test_count);
		timer.start();
		GetOriginMesh();
		timer.stop();
		getoriginmeshwritemeshtotaltime += timer.seconds();
	}
	//OMC.WriteMesh("GetOriginMesh.stl", OpenMesh::IO::Options::Binary);
	Writetime("GetOriginMesh Runtime", getoriginmeshwritemeshtotaltime / test_count);
	std::cout << "GetOriginMesh Complete" << std::endl;

	// CollapsePoint
	std::cout << "CollapsePoint Start" << std::endl;
	double collapsepointwritemeshtotaltime = 0;
	timer.reset();
	for (int i = 0; i < test_count; i++)
	{
		PrintProgressPercent(i + 1, test_count);
		GetOriginMesh();
		timer.start();
		CollapsePoint(0, 1);
		timer.stop();
		collapsepointwritemeshtotaltime += timer.seconds();
	}
	Writetime("CollapsePoint Runtime", collapsepointwritemeshtotaltime / test_count);
	std::cout << "CollapsePoint Complete" << std::endl;

	// CollapseIter_5
	std::cout << "CollapseIter_5 Start" << std::endl;
	double collapseiter5writemeshtotaltime = 0;
	timer.reset();
	for (int i = 0; i < test_count; i++)
	{
		PrintProgressPercent(i + 1, test_count);
		GetOriginMesh();
		timer.start();
		CollapseIter(5);
		timer.stop();
		collapseiter5writemeshtotaltime += timer.seconds();
	}
	Writetime("CollapseIter_5 Runtime", collapseiter5writemeshtotaltime / test_count);
	std::cout << "CollapseIter_5 Complete" << std::endl;

	// CollapseIter_100
	std::cout << "CollapseIter_100 Start" << std::endl;
	double collapseiter100writemeshtotaltime = 0;
	timer.reset();
	for (int i = 0; i < test_count; i++)
	{
		PrintProgressPercent(i + 1, test_count);
		GetOriginMesh();
		timer.start();
		CollapseIter(100);
		timer.stop();
		collapseiter100writemeshtotaltime += timer.seconds();
	}
	Writetime("CollapseIter_100 Runtime", collapseiter100writemeshtotaltime / test_count);
	std::cout << "CollapseIter_100 Complete" << std::endl;

	// Decimation
	std::cout << "Decimation Start" << std::endl;
	double decimationwritemeshtotaltime = 0;
	timer.reset();
	double decimationcoeff = 1.1;
	for (int i = 0; i < test_count; i++)
	{
		PrintProgressPercent(i + 1, test_count);
		GetOriginMesh();
		timer.start();
		Decimation(decimationcoeff);
		timer.stop();
		decimationwritemeshtotaltime += timer.seconds();
	}
	Writetime("Decimation Runtime", decimationwritemeshtotaltime / test_count);
	std::cout << "Decimation Complete" << std::endl;

	// Smoothing_5
	std::cout << "Smoothing_5 Start" << std::endl;
	double smoothing5writemeshtotaltime = 0;
	timer.reset();
	for (int i = 0; i < test_count; i++)
	{
		PrintProgressPercent(i + 1, test_count);
		GetOriginMesh();
		timer.start();
		Smoothing(5);
		timer.stop();
		smoothing5writemeshtotaltime += timer.seconds();
	}
	Writetime("Smoothing_5 Runtime", smoothing5writemeshtotaltime / test_count);
	std::cout << "Smoothing_5 Complete" << std::endl;

	// Smoothing_50
	std::cout << "Smoothing_50 Start" << std::endl;
	double smoothing50writemeshtotaltime = 0;
	timer.reset();
	for (int i = 0; i < test_count; i++)
	{
		PrintProgressPercent(i + 1, test_count);
		GetOriginMesh();
		timer.start();
		Smoothing(50);
		timer.stop();
		smoothing50writemeshtotaltime += timer.seconds();
	}
	Writetime("Smoothing_50 Runtime", smoothing50writemeshtotaltime / test_count);
	std::cout << "Smoothing_50 Complete" << std::endl;

	// Smoothing_500
	std::cout << "Smoothing_500 Start" << std::endl;
	double smoothing500writemeshtotaltime = 0;
	timer.reset();
	for (int i = 0; i < test_count; i++)
	{
		PrintProgressPercent(i + 1, test_count);
		GetOriginMesh();
		timer.start();
		Smoothing(500);
		timer.stop();
		smoothing500writemeshtotaltime += timer.seconds();
	}
	Writetime("Smoothing_500 Runtime", smoothing500writemeshtotaltime / test_count);
	std::cout << "Smoothing_500 Complete" << std::endl;

	// LoopSubdivision_1
	std::cout << "LoopSubdivision_1 Start" << std::endl;
	double loopsubdivision1writemeshtotaltime = 0;
	timer.reset();
	for (int i = 0; i < test_count; i++)
	{
		PrintProgressPercent(i + 1, test_count);
		GetOriginMesh();
		timer.start();
		LoopSubdivision(1);
		timer.stop();
		loopsubdivision1writemeshtotaltime += timer.seconds();
	}
	Writetime("LoopSubdivision_1 Runtime", loopsubdivision1writemeshtotaltime / test_count);
	std::cout << "LoopSubdivision_1 Complete" << std::endl;

	// LoopSubdivision_2
	std::cout << "LoopSubdivision_2 Start" << std::endl;
	double loopsubdivision2writemeshtotaltime = 0;
	timer.reset();
	for (int i = 0; i < test_count; i++)
	{
		PrintProgressPercent(i + 1, test_count);
		GetOriginMesh();
		timer.start();
		LoopSubdivision(1);
		timer.stop();
		loopsubdivision2writemeshtotaltime += timer.seconds();
	}
	Writetime("LoopSubdivision_2 Runtime", loopsubdivision2writemeshtotaltime / test_count);
	std::cout << "LoopSubdivision_2 Complete" << std::endl;
	writeFile.close();
}

bool OpenMeshCore::CheckMesh()
{
	if (_mymesh.n_vertices() == 0 || _mymesh.n_edges() == 0 || _mymesh.n_faces() == 0)
	{
		std::cout << "Mesh is Empty" << std::endl;
		exit(0);
	}

	return true;
}

void OpenMeshCore::PrintProgressPercent(int current_work, int total_work)
{
	float percent; // 퍼센트 저장 변수  
	percent = (float)current_work / total_work * 100; // 퍼센트 계산  
	printf("\r%0.2f%%", percent); // 퍼센트 출력  
	return;
}
void OpenMeshCore::GetOriginMesh()
{
	if (CheckMesh())
		_mymesh = p_originmesh;
}

void OpenMeshCore::ReadMesh(std::string filename)
{
	OpenMesh::IO::Options opt;
	if (!OpenMesh::IO::read_mesh(_mymesh, p_Fileloadpath + "/" + filename, opt))
	{
		std::cerr << "Error loading mesh from file " << p_Fileloadpath + "/" + filename << std::endl;
		return;
	}
	// If the file did not provide vertex normals, then calculate them
	if (!opt.check(OpenMesh::IO::Options::VertexNormal) &&
		_mymesh.has_face_normals() && _mymesh.has_vertex_normals())
	{
		// let the mesh update the normals
		_mymesh.update_normals();
	}
	p_originmesh = _mymesh;
	if (printlog)
		std::cout << " File Load Complete " << std::endl;
}

void OpenMeshCore::WriteMesh(std::string filename, OpenMesh::IO::Options opt)
{
	try
	{
		if (!OpenMesh::IO::write_mesh(_mymesh, p_Filesavepath + "/" + filename, opt))
		{
			std::cerr << "Cannot write mesh to file " + p_Filesavepath + "/" + filename << std::endl;
			return;
		}
	}
	catch (std::exception& x)
	{
		std::cerr << x.what() << std::endl;
		return;
	}
	if (printlog)
		std::cout << " File Save Complete " << std::endl;
}

void OpenMeshCore::CollapsePoint(int fromvertexindex, int tovertexindex)
{
	if (printlog)
		std::cout << " CollapsePoint START " << std::endl;
	if (CheckMesh())
	{
		// 삭제하기 전에 상태 권한 부여
		_mymesh.request_vertex_status();
		_mymesh.request_edge_status();
		_mymesh.request_face_status();

		// Halfedge를 순회
		//std::cout << "total number of halfedge : " << _mymesh.n_halfedges() << std::endl;
		for (MyMesh::HalfedgeIter it = _mymesh.halfedges_begin(); it != _mymesh.halfedges_end(); ++it) {
			if (_mymesh.from_vertex_handle(*it) == _mymesh.vertex_handle(fromvertexindex) &&
				_mymesh.to_vertex_handle(*it) == _mymesh.vertex_handle(tovertexindex) && _mymesh.is_collapse_ok(*it))
			{
				// 해당하는 edge collapse 진행
				_mymesh.collapse(*it);
				break;
			}
		}
		_mymesh.garbage_collection();
	}

	if (printlog)
		std::cout << " CollapsePoint END " << std::endl;
	return;
}

// collapsecount 때 마다 Collapse 진행
void OpenMeshCore::CollapseIter(int collapsecount)
{
	if (printlog)
		std::cout << " CollapseIter START " << std::endl;
	if (CheckMesh())
	{
		// 삭제하기 전에 상태 권한 부여
		_mymesh.request_vertex_status();
		_mymesh.request_edge_status();
		_mymesh.request_face_status();

		int _count = 0;
		//std::cout << "total number of halfedge : " << _mymesh.n_halfedges() << std::endl;
		for (MyMesh::HalfedgeIter it = _mymesh.halfedges_begin(); it != _mymesh.halfedges_end(); ++it)
		{
			if (_count % collapsecount == 0)
			{
				//PrintProgressPercent(_count, _mymesh.n_halfedges());
				// 해당하는 edge collapse 진행
				if (_mymesh.is_collapse_ok(*it))
				{
					_mymesh.collapse(*it);
				}
			}
			_count++;
		}
		_mymesh.garbage_collection();
	}

	if (printlog)
		std::cout << " CollapseIter END " << std::endl;
	return;
}

void OpenMeshCore::LoopSubdivision(int Itercount)
{
	if (printlog)
		std::cout << " Loopt Subdivision START " << std::endl;
	if (CheckMesh())
	{
		OpenMesh::Subdivider::Uniform::LoopT<MyMesh> LooptSubdivision;
		LooptSubdivision.attach(_mymesh);
		LooptSubdivision(Itercount);
		LooptSubdivision.detach();
	}
	if (printlog)
		std::cout << " Loopt Subdivision END " << std::endl;
	return;
}

void OpenMeshCore::Decimation(double coef)
{
	if (printlog)
		std::cout << " Quadric Decimation START " << std::endl;
	if (CheckMesh())
	{

		using namespace OpenMesh;
		// 원하는 Decimater Handle Type 설정
		typedef Decimater::ModQuadricT<MyMesh>::Handle     ModQuadric;

		// Decimater Type 설정
		typedef Decimater::DecimaterT<MyMesh>          Decimater_;

		// Decimater Object와 Mesh 연결
		Decimater_   decimater(_mymesh);
		// Quadric module 생성
		ModQuadric modquadric;

		// Decimater에 module 등록
		decimater.add(modquadric);
		// unset_max_err() calls set_binary(false) 이므로 선언
		decimater.module(modquadric).unset_max_err();

		// 초기화
		decimater.initialize();

		// Decimate 진행 ( 내부 숫자 변경 가능 )
		decimater.decimate(_mymesh.n_vertices() / coef);
		_mymesh.garbage_collection();
	}
	if (printlog)
		std::cout << " Quadric Decimation END " << std::endl;
	return;
}

void OpenMeshCore::Smoothing(unsigned int Itercount)
{
	if (printlog)
		std::cout << " JacobiLaplace Smoothing START " << std::endl;
	if (CheckMesh())
	{
		// Initialize smoother with input mesh
		OpenMesh::Smoother::JacobiLaplaceSmootherT<MyMesh> smoother(_mymesh);

		/*
		Component
		- Tangential : Smooth in tangential direction
		- Normal : Smooth in normal direction
		- Tangential_and_Normal : Smooth in tangential and normal direction
		Continuity
		- C0 : Shape is continuous, but not the tangent
		- C1 : shape and tangent are continuous
		- C2 : preserves curvature
		*/
		smoother.initialize(smoother.Tangential_and_Normal, smoother.C2);
		smoother.smooth(Itercount);
	}
	if (printlog)
		std::cout << " JacobiLaplace Smoothing END " << std::endl;
}

void OpenMeshCore::BoundaryVertexWrite(std::string filepath)
{
	std::cout << p_Filesavepath + filepath << std::endl;
	writeFile.open(p_Filesavepath + filepath);
	int boundary_count = 0;

	if (writeFile.is_open())
	{

		for (MyMesh::VertexIter v_it = _mymesh.vertices_begin(); v_it != _mymesh.vertices_end(); ++v_it)
			if (!_mymesh.is_boundary(*v_it))
			{
				writeFile << _mymesh.point(*v_it) << std::endl;
				boundary_count++;
			}
		std::cout << _mymesh.n_vertices() << std::endl;
		//writeFile << boundary_count << std::endl;
	}
	writeFile.close();
}

void OpenMeshCore::CubeGenerator()
{
	// Vertex 좌표 직접 설정
	MyMesh::VertexHandle vhandle[8];
	vhandle[0] = _mymesh.add_vertex(MyMesh::Point(-1, -1, 1));
	vhandle[1] = _mymesh.add_vertex(MyMesh::Point(1, -1, 1));
	vhandle[2] = _mymesh.add_vertex(MyMesh::Point(1, 1, 1));
	vhandle[3] = _mymesh.add_vertex(MyMesh::Point(-1, 1, 1));
	vhandle[4] = _mymesh.add_vertex(MyMesh::Point(-1, -1, -1));
	vhandle[5] = _mymesh.add_vertex(MyMesh::Point(1, -1, -1));
	vhandle[6] = _mymesh.add_vertex(MyMesh::Point(1, 1, -1));
	vhandle[7] = _mymesh.add_vertex(MyMesh::Point(-1, 1, -1));

	// Vertex에 맞게 Face 생성
	std::vector<MyMesh::VertexHandle>  face_vhandles;

	face_vhandles.clear();
	face_vhandles.push_back(vhandle[1]);
	face_vhandles.push_back(vhandle[2]);
	face_vhandles.push_back(vhandle[0]);
	_mymesh.add_face(face_vhandles);

	face_vhandles.clear();
	face_vhandles.push_back(vhandle[2]);
	face_vhandles.push_back(vhandle[3]);
	face_vhandles.push_back(vhandle[0]);
	_mymesh.add_face(face_vhandles);

	face_vhandles.clear();
	face_vhandles.push_back(vhandle[1]);
	face_vhandles.push_back(vhandle[6]);
	face_vhandles.push_back(vhandle[2]);
	_mymesh.add_face(face_vhandles);

	face_vhandles.clear();
	face_vhandles.push_back(vhandle[5]);
	face_vhandles.push_back(vhandle[6]);
	face_vhandles.push_back(vhandle[1]);
	_mymesh.add_face(face_vhandles);

	face_vhandles.clear();
	face_vhandles.push_back(vhandle[5]);
	face_vhandles.push_back(vhandle[7]);
	face_vhandles.push_back(vhandle[6]);
	_mymesh.add_face(face_vhandles);

	face_vhandles.clear();
	face_vhandles.push_back(vhandle[4]);
	face_vhandles.push_back(vhandle[7]);
	face_vhandles.push_back(vhandle[5]);
	_mymesh.add_face(face_vhandles);

	face_vhandles.clear();
	face_vhandles.push_back(vhandle[4]);
	face_vhandles.push_back(vhandle[3]);
	face_vhandles.push_back(vhandle[7]);
	_mymesh.add_face(face_vhandles);

	face_vhandles.clear();
	face_vhandles.push_back(vhandle[4]);
	face_vhandles.push_back(vhandle[0]);
	face_vhandles.push_back(vhandle[3]);
	_mymesh.add_face(face_vhandles);

	face_vhandles.clear();
	face_vhandles.push_back(vhandle[6]);
	face_vhandles.push_back(vhandle[3]);
	face_vhandles.push_back(vhandle[2]);
	_mymesh.add_face(face_vhandles);

	face_vhandles.clear();
	face_vhandles.push_back(vhandle[6]);
	face_vhandles.push_back(vhandle[7]);
	face_vhandles.push_back(vhandle[3]);
	_mymesh.add_face(face_vhandles);

	face_vhandles.clear();
	face_vhandles.push_back(vhandle[5]);
	face_vhandles.push_back(vhandle[0]);
	face_vhandles.push_back(vhandle[4]);
	_mymesh.add_face(face_vhandles);

	face_vhandles.clear();
	face_vhandles.push_back(vhandle[1]);
	face_vhandles.push_back(vhandle[0]);
	face_vhandles.push_back(vhandle[5]);
	_mymesh.add_face(face_vhandles);

	return;
}