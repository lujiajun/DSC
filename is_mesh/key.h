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

namespace is_mesh
{
    class Key
    {
    protected:
        unsigned int key;
        
        Key() : Key(static_cast<unsigned int>(-1))
        {
            
        }
        
        Key(unsigned int _key) : key(_key)
        {
            
        }
        
    public:
        bool is_valid() const
        {
            return key != static_cast<unsigned int>(-1);
        }
        
        //conversion to int
        operator unsigned int() { return key; }
        
        friend inline bool operator==(Key    const & a, Key    const & b)   { return a.key == b.key; }
        friend inline bool operator==(Key          & a, Key          & b)   { return a.key == b.key; }
        friend inline bool operator==(unsigned int const & k, Key    const & b)   { return   k   == b.key; }
        friend inline bool operator==(Key    const & a, unsigned int const & k)   { return a.key ==   k;   }
        friend inline bool operator!=(Key    const & a, Key    const & b)   { return a.key != b.key; }
        friend inline bool operator!=(Key          & a, Key          & b)   { return a.key != b.key; }
        friend inline bool operator!=(unsigned int const & k, Key    const & b)   { return   k   != b.key; }
        friend inline bool operator!=(Key    const & a, unsigned int const & k)   { return a.key !=   k;   }
        friend inline bool operator< (Key    const & a, Key    const & b)   { return a.key <  b.key; }
        friend inline bool operator< (Key          & a, Key          & b)   { return a.key <  b.key; }
        friend inline bool operator< (unsigned int const & k, Key    const & b)   { return   k   <  b.key; }
        friend inline bool operator< (Key    const & a, unsigned int const & k)   { return a.key <    k;   }
        
        friend std::ostream& operator<< (std::ostream & os, Key const & a) { return (os << a.key); }
        friend std::istream& operator>> (std::istream & is, Key       & a) { return (is >> a.key); }
    };
    
    class NodeKey : public Key
    {
    public:
        constexpr const static int dim = 0;
        
        NodeKey() : Key() {}
        NodeKey(unsigned int k) : Key(k) {}
    };
    
    class EdgeKey : public Key
    {
    public:
        constexpr const static int dim = 1;
        
        EdgeKey() : Key() {}
        EdgeKey(unsigned int k) : Key(k) {}
    };
    
    class FaceKey : public Key
    {
    public:
        constexpr const static int dim = 2;

        FaceKey() : Key() {}
        FaceKey(unsigned int k) : Key(k) {}
    };
    
    class TetrahedronKey : public Key
    {
    public:
        constexpr const static int dim = 3;
        
        TetrahedronKey() : Key() {}
        TetrahedronKey(unsigned int k) : Key(k) {}
    };
    
}
