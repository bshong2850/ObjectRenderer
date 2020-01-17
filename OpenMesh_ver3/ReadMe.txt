Last Version 2020 01 17

OpenMesh Library를 활용한 기본적인 함수 모음입니다.

core.h에 있는 함수를 main으로 가져와서 사용하시면 됩니다.

현재 구현되어 있는 함수 구성

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

