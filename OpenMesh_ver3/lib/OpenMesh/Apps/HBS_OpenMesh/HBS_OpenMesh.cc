//
//#include <iostream>
//// -------------------- OpenMesh
//#include <OpenMesh/Core/IO/MeshIO.hh>
//#include <OpenMesh/Core/Mesh/PolyMesh_ArrayKernelT.hh>
//// ----------------------------------------------------------------------------
//typedef OpenMesh::PolyMesh_ArrayKernelT<>  MyMesh;
//// ----------------------------------------------------------------------------
//// Build a simple cube and write it to std::cout
//  
//int main()
//{
//  MyMesh mesh;
//  // generate vertices
//  MyMesh::VertexHandle vhandle[8];
//  vhandle[0] = mesh.add_vertex(MyMesh::Point(-1, -1,  1));
//  vhandle[1] = mesh.add_vertex(MyMesh::Point( 1, -1,  1));
//  vhandle[2] = mesh.add_vertex(MyMesh::Point( 1,  1,  1));
//  vhandle[3] = mesh.add_vertex(MyMesh::Point(-1,  1,  1));
//  vhandle[4] = mesh.add_vertex(MyMesh::Point(-1, -1, -1));
//  vhandle[5] = mesh.add_vertex(MyMesh::Point( 1, -1, -1));
//  vhandle[6] = mesh.add_vertex(MyMesh::Point( 1,  1, -1));
//  vhandle[7] = mesh.add_vertex(MyMesh::Point(-1,  1, -1));
//  // generate (quadrilateral) faces
//  std::vector<MyMesh::VertexHandle>  face_vhandles;
//  face_vhandles.clear();
//  face_vhandles.push_back(vhandle[0]);
//  face_vhandles.push_back(vhandle[1]);
//  face_vhandles.push_back(vhandle[2]);
//  face_vhandles.push_back(vhandle[3]);
//  mesh.add_face(face_vhandles);
// 
//  face_vhandles.clear();
//  face_vhandles.push_back(vhandle[7]);
//  face_vhandles.push_back(vhandle[6]);
//  face_vhandles.push_back(vhandle[5]);
//  face_vhandles.push_back(vhandle[4]);
//  mesh.add_face(face_vhandles);
//  face_vhandles.clear();
//  face_vhandles.push_back(vhandle[1]);
//  face_vhandles.push_back(vhandle[0]);
//  face_vhandles.push_back(vhandle[4]);
//  face_vhandles.push_back(vhandle[5]);
//  mesh.add_face(face_vhandles);
//  face_vhandles.clear();
//  face_vhandles.push_back(vhandle[2]);
//  face_vhandles.push_back(vhandle[1]);
//  face_vhandles.push_back(vhandle[5]);
//  face_vhandles.push_back(vhandle[6]);
//  mesh.add_face(face_vhandles);
//  face_vhandles.clear();
//  face_vhandles.push_back(vhandle[3]);
//  face_vhandles.push_back(vhandle[2]);
//  face_vhandles.push_back(vhandle[6]);
//  face_vhandles.push_back(vhandle[7]);
//  mesh.add_face(face_vhandles);
//  face_vhandles.clear();
//  face_vhandles.push_back(vhandle[0]);
//  face_vhandles.push_back(vhandle[3]);
//  face_vhandles.push_back(vhandle[7]);
//  face_vhandles.push_back(vhandle[4]);
//  mesh.add_face(face_vhandles);
//  // write mesh to output.obj
//  try
//  {
//    if ( !OpenMesh::IO::write_mesh(mesh, "output.obj") )
//    {
//      std::cerr << "Cannot write mesh to file 'output.off'" << std::endl;
//      return 1;
//    }
//  }
//  catch( std::exception& x )
//  {
//    std::cerr << x.what() << std::endl;
//    return 1;
//  }
//  return 0;
//}

//#include <iostream>
//#include <vector>
//// -------------------- OpenMesh
//#include <OpenMesh/Core/IO/MeshIO.hh>
//#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
//typedef OpenMesh::TriMesh_ArrayKernelT<>  MyMesh;
//int main(int argc, char **argv)
//{
//	MyMesh  mesh;
//	// check command line options
//	//if (argc != 4)
//	//{
//	//	//std::cerr << "Usage:  " << argv[0] << " #iterations infile outfile\n";
//	//	return 1;
//	//}
//	// read mesh from stdin
//	if (!OpenMesh::IO::read_mesh(mesh, "output.obj"))
//	{
//		std::cerr << "Error: Cannot read mesh from " << "output.obj" << std::endl;
//		return 1;
//	}
//	// this vector stores the computed centers of gravity
//	std::vector<MyMesh::Point>  cogs;
//	std::vector<MyMesh::Point>::iterator cog_it;
//	cogs.reserve(mesh.n_vertices());
//	// smoothing mesh argv[1] times
//	MyMesh::VertexIter          v_it, v_end(mesh.vertices_end());
//	MyMesh::VertexVertexIter    vv_it;
//	MyMesh::Point               cog;
//	MyMesh::Scalar              valence;
//	unsigned int                i, N(atoi("3"));
//	for (i = 0; i < N; ++i)
//	{
//		cogs.clear();
//		for (v_it = mesh.vertices_begin(); v_it != v_end; ++v_it)
//		{
//			cog[0] = cog[1] = cog[2] = valence = 0.0;
//
//			for (vv_it = mesh.vv_iter(*v_it); vv_it.is_valid(); ++vv_it)
//			{
//				cog += mesh.point(*vv_it);
//				++valence;
//			}
//			cogs.push_back(cog / valence);
//		}
//
//		for (v_it = mesh.vertices_begin(), cog_it = cogs.begin();
//			v_it != v_end; ++v_it, ++cog_it)
//			if (!mesh.is_boundary(*v_it))
//				mesh.set_point(*v_it, *cog_it);
//	}
//	// write mesh to stdout
//	if (!OpenMesh::IO::write_mesh(mesh, "output_smooth_test.obj"))
//	{
//		std::cerr << "Error: cannot write mesh to " << "no" << std::endl;
//		return 1;
//	}
//	return 0;
//}

//#include <iostream>
//#include <typeinfo>
//// --------------------
//#include <OpenMesh/Core/IO/MeshIO.hh>
//#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
//#include <OpenMesh/Core/Geometry/VectorT.hh>
//#ifndef DOXY_IGNORE_THIS
//// Define my personal traits
//struct MyTraits : OpenMesh::DefaultTraits
//{
//	// Let Point and Normal be a vector of doubles
//	typedef OpenMesh::Vec3d Point;
//	typedef OpenMesh::Vec3d Normal;
//	// Already defined in OpenMesh::DefaultTraits
//	// HalfedgeAttributes( OpenMesh::Attributes::PrevHalfedge );
//
//	// Uncomment next line to disable attribute PrevHalfedge
//	// HalfedgeAttributes( OpenMesh::Attributes::None );
//	//
//	// or
//	//
//	// HalfedgeAttributes( 0 );
//};
//#endif
//// Define my mesh with the new traits!
//typedef OpenMesh::TriMesh_ArrayKernelT<MyTraits>  MyMesh;
//// ------------------------------------------------------------------ main ----
//int main(int argc, char **argv)
//{
//	MyMesh mesh;
//	/*if (argc != 2)
//	{
//		std::cerr << "Usage: " << argv[0] << " <input>\n";
//		return 1;
//	}*/
//	// Just make sure that point element type is double
//	if (typeid(OpenMesh::vector_traits<MyMesh::Point>::value_type)
//		!= typeid(double))
//	{
//		std::cerr << "Ouch! ERROR! Data type is wrong!\n";
//		return 1;
//	}
//	// Make sure that normal element type is double
//	if (typeid(OpenMesh::vector_traits<MyMesh::Normal>::value_type)
//		!= typeid(double))
//	{
//		std::cerr << "Ouch! ERROR! Data type is wrong!\n";
//		return 1;
//	}
//	// Add vertex normals as default property (ref. previous tutorial)
//	mesh.request_vertex_normals();
//	// Add face normals as default property
//	mesh.request_face_normals();
//	// load a mesh
//	OpenMesh::IO::Options opt;
//	if (!OpenMesh::IO::read_mesh(mesh, "output.obj", opt))
//	{
//		std::cerr << "Error loading mesh from file " << "output.obj" << std::endl;
//		return 1;
//	}
//	// If the file did not provide vertex normals, then calculate them
//	if (!opt.check(OpenMesh::IO::Options::VertexNormal) &&
//		mesh.has_face_normals() && mesh.has_vertex_normals())
//	{
//		// let the mesh update the normals
//		mesh.update_normals();
//	}
//	// move all vertices one unit length along it's normal direction
//	for (MyMesh::VertexIter v_it = mesh.vertices_begin();
//		v_it != mesh.vertices_end(); ++v_it)
//	{
//		std::cout << "Vertex #" << *v_it << ": " << mesh.point(*v_it);
//		mesh.set_point(*v_it, mesh.point(*v_it) - mesh.normal(*v_it));
//		std::cout << " moved to " << mesh.point(*v_it) << std::endl;
//	}
//	if (!OpenMesh::IO::write_mesh(mesh, "output_move_minus.stl"))
//	{
//		std::cerr << "Error: cannot write mesh to " << "output_move.stl" << std::endl;
//		return 1;
//	}
//	return 0;
//}

/* ========================================================================= *
*                                                                           *
*                               OpenMesh                                    *
*           Copyright (c) 2001-2015, RWTH-Aachen University                 *
*           Department of Computer Graphics and Multimedia                  *
*                          All rights reserved.                             *
*                            www.openmesh.org                               *
*                                                                           *
*---------------------------------------------------------------------------*
* This file is part of OpenMesh.                                            *
*---------------------------------------------------------------------------*
*                                                                           *
* Redistribution and use in source and binary forms, with or without        *
* modification, are permitted provided that the following conditions        *
* are met:                                                                  *
*                                                                           *
* 1. Redistributions of source code must retain the above copyright notice, *
*    this list of conditions and the following disclaimer.                  *
*                                                                           *
* 2. Redistributions in binary form must reproduce the above copyright      *
*    notice, this list of conditions and the following disclaimer in the    *
*    documentation and/or other materials provided with the distribution.   *
*                                                                           *
* 3. Neither the name of the copyright holder nor the names of its          *
*    contributors may be used to endorse or promote products derived from   *
*    this software without specific prior written permission.               *
*                                                                           *
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS       *
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED *
* TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A           *
* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER *
* OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  *
* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,       *
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR        *
* PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF    *
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING      *
* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS        *
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.              *
*                                                                           *
* ========================================================================= */
/*===========================================================================*\
*                                                                           *
*   $Revision: 736 $                                                         *
*   $Date: 2012-10-08 09:30:49 +0200 (Mo, 08. Okt 2012) $                   *
*                                                                           *
\*===========================================================================*/
//#include <iostream>
//// -------------------- OpenMesh
//#include <OpenMesh/Core/IO/MeshIO.hh>
//#include <OpenMesh/Core/Mesh/PolyMesh_ArrayKernelT.hh>
//#include <OpenMesh/Core/System/config.h>
//#include <OpenMesh/Core/Mesh/Status.hh>
//// ----------------------------------------------------------------------------
//struct MyTraits : public OpenMesh::DefaultTraits
//{
//};
//typedef OpenMesh::PolyMesh_ArrayKernelT<MyTraits>  MyMesh;
//// ----------------------------------------------------------------------------
//// Build a simple cube and delete it except one face
//
//int main()
//{
//	MyMesh mesh;
//	// the request has to be called before a vertex/face/edge can be deleted. it grants access to the status attribute
//	mesh.request_face_status();
//	mesh.request_edge_status();
//	mesh.request_vertex_status();
//	// generate vertices
//	MyMesh::VertexHandle vhandle[8];
//	MyMesh::FaceHandle   fhandle[6];
//	vhandle[0] = mesh.add_vertex(MyMesh::Point(-1, -1, 1));
//	vhandle[1] = mesh.add_vertex(MyMesh::Point(1, -1, 1));
//	vhandle[2] = mesh.add_vertex(MyMesh::Point(1, 1, 1));
//	vhandle[3] = mesh.add_vertex(MyMesh::Point(-1, 1, 1));
//	vhandle[4] = mesh.add_vertex(MyMesh::Point(-1, -1, -1));
//	vhandle[5] = mesh.add_vertex(MyMesh::Point(1, -1, -1));
//	vhandle[6] = mesh.add_vertex(MyMesh::Point(1, 1, -1));
//	vhandle[7] = mesh.add_vertex(MyMesh::Point(-1, 1, -1));
//	// generate (quadrilateral) faces
//	std::vector<MyMesh::VertexHandle>  tmp_face_vhandles;
//	tmp_face_vhandles.clear();
//	tmp_face_vhandles.push_back(vhandle[0]);
//	tmp_face_vhandles.push_back(vhandle[1]);
//	tmp_face_vhandles.push_back(vhandle[2]);
//	tmp_face_vhandles.push_back(vhandle[3]);
//	fhandle[0] = mesh.add_face(tmp_face_vhandles);
//
//	tmp_face_vhandles.clear();
//	tmp_face_vhandles.push_back(vhandle[7]);
//	tmp_face_vhandles.push_back(vhandle[6]);
//	tmp_face_vhandles.push_back(vhandle[5]);
//	tmp_face_vhandles.push_back(vhandle[4]);
//	fhandle[1] = mesh.add_face(tmp_face_vhandles);
//
//	tmp_face_vhandles.clear();
//	tmp_face_vhandles.push_back(vhandle[1]);
//	tmp_face_vhandles.push_back(vhandle[0]);
//	tmp_face_vhandles.push_back(vhandle[4]);
//	tmp_face_vhandles.push_back(vhandle[5]);
//	fhandle[2] = mesh.add_face(tmp_face_vhandles);
//
//	tmp_face_vhandles.clear();
//	tmp_face_vhandles.push_back(vhandle[2]);
//	tmp_face_vhandles.push_back(vhandle[1]);
//	tmp_face_vhandles.push_back(vhandle[5]);
//	tmp_face_vhandles.push_back(vhandle[6]);
//	fhandle[3] = mesh.add_face(tmp_face_vhandles);
//	tmp_face_vhandles.clear();
//	tmp_face_vhandles.push_back(vhandle[3]);
//	tmp_face_vhandles.push_back(vhandle[2]);
//	tmp_face_vhandles.push_back(vhandle[6]);
//	tmp_face_vhandles.push_back(vhandle[7]);
//	fhandle[4] = mesh.add_face(tmp_face_vhandles);
//
//	tmp_face_vhandles.clear();
//	tmp_face_vhandles.push_back(vhandle[0]);
//	tmp_face_vhandles.push_back(vhandle[3]);
//	tmp_face_vhandles.push_back(vhandle[7]);
//	tmp_face_vhandles.push_back(vhandle[4]);
//	fhandle[5] = mesh.add_face(tmp_face_vhandles);
//	// And now delete all faces and vertices
//	// except face (vh[7], vh[6], vh[5], vh[4])
//	// whose handle resides in fhandle[1]
//
//	// Delete face 0
//	mesh.delete_face(fhandle[0], false);
//	// ... face 2
//	mesh.delete_face(fhandle[2], false);
//	// ... face 3
//	mesh.delete_face(fhandle[3], false);
//	// ... face 4
//	mesh.delete_face(fhandle[4], false);
//	// ... face 5
//	mesh.delete_face(fhandle[5], false);
//
//	// If isolated vertices result in a face deletion
//	// they have to be deleted manually. If you want this
//	// to happen automatically, change the second parameter
//	// to true.
//	// Now delete the isolated vertices 0, 1, 2 and 3
//	mesh.delete_vertex(vhandle[0], false);
//	mesh.delete_vertex(vhandle[1], false);
//	mesh.delete_vertex(vhandle[2], false);
//	mesh.delete_vertex(vhandle[3], false);
//	// Delete all elements that are marked as deleted
//	// from memory.
//	mesh.garbage_collection();
//	// write mesh to output.obj
//	try {
//		if (!OpenMesh::IO::write_mesh(mesh, "output.obj")) {
//			std::cerr << "Cannot write mesh to file " << "output.obj" << std::endl;
//			return 1;
//		}
//	}
//	catch (std::exception& x)
//	{
//		std::cerr << x.what() << std::endl;
//		return 1;
//	}
//
//	return 0;
//}