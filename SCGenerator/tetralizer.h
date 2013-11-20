//
//  Deformabel Simplicial Complex (DSC) method
//  Copyright (C) 2013  Technical University of Denmark
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  See licence.txt for a copy of the GNU General Public License.

#pragma once

#include "util.h"

class Tetralizer
{
    static void tetralize_cube1(int i, int j, int k, int Ni, int Nj, int Nk, std::vector<int>& tets);
    
    static void tetralize_cube2(int i, int j, int k, int Ni, int Nj, int Nk, std::vector<int>& tets);
    
    static void create_tets(int Ni, int Nj, int Nk, std::vector<int>& tets);
    
    static void create_points(const vec3& size, real avg_edge_length, int Ni, int Nj, int Nk, std::vector<vec3>& points);
    
    static void build_boundary_mesh(std::vector<vec3>& points_boundary, std::vector<int>& faces_boundary, const vec3& size);
    
    static void tetrahedralize_inside(const std::vector<vec3>& points_interface, const std::vector<int>& faces_interface, std::vector<vec3>& points_inside, std::vector<int>& tets_inside);
    
    static void tetrahedralize_outside(const std::vector<vec3>& points_interface, const std::vector<int>&  faces_interface, std::vector<vec3>& points_boundary, std::vector<int>&  faces_boundary, std::vector<vec3>& points_outside, std::vector<int>& tets_outside, const vec3& inside_pts);
    
    static void merge_inside_outside(const std::vector<vec3>& points_interface, const std::vector<int>&  faces_interface, std::vector<vec3>& points_inside, std::vector<int>&  tets_inside, std::vector<vec3>& points_outside, std::vector<int>&  tets_outside, std::vector<vec3>& output_points, std::vector<int>&  output_tets, std::vector<int>&  output_tet_flags);
    
public:
    
    static void tetralize(const std::vector<vec3>& points_interface, const std::vector<int>& faces_interface, std::vector<vec3>& points, std::vector<int>& tets, std::vector<int>& tet_labels)
    {
        vec3 size(4.);
        vec3 inside_point(0.);
        
        std::vector<vec3>    points_boundary;
        std::vector<int>  faces_boundary;
        build_boundary_mesh(points_boundary, faces_boundary, size);
        
        std::vector<vec3> points_inside;
        std::vector<int> tets_inside;
        tetrahedralize_inside(points_interface, faces_interface, points_inside, tets_inside);
        
        std::vector<vec3> points_outside;
        std::vector<int> tets_outside;
        tetrahedralize_outside(points_interface, faces_interface, points_boundary, faces_boundary, points_outside, tets_outside, inside_point);
        
        merge_inside_outside(points_interface, faces_interface, points_inside, tets_inside, points_outside, tets_outside, points, tets, tet_labels);
    }
    
    static void tetralize(const vec3& size, real avg_edge_length, std::vector<vec3>& points, std::vector<int>& tets)
    {
        int Ni = std::ceil(size[0]/avg_edge_length) + 1;
        int Nj = std::ceil(size[1]/avg_edge_length) + 1;
        int Nk = std::ceil(size[2]/avg_edge_length) + 1;
        
        create_points(size, avg_edge_length, Ni, Nj, Nk, points);
        create_tets(Ni, Nj, Nk, tets);
    }
};