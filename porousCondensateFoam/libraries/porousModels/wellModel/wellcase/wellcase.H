/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011-2016 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.


\*---------------------------------------------------------------------------*/

    #ifndef wellcase_H
    #define wellcase_H

    #include "well.H"
    #include "dimensionedScalar.H"
    #include "volFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

   

class wellcase
:
    public well
{
   
protected:

    
     dimensionedScalar activate_;
     dimensionedScalar q_;
     dimensionedScalar volume_;
     dimensionedScalar activetimecondition_;
     dimensionedScalar timechangeplan_;
     dimensionedScalar qchangeplan_;
     dimensionedScalar radius_;
     dimensionedScalar height_;
     dimensionedScalar deltax_;
     dimensionedScalar deltay_;
     dimensionedScalar pb_;

public:

    // Constructors

    wellcase
    (
        const fvMesh& mesh,
        const dictionary& wellboreProperties,
        const word& wellName
    );


    // Selectors

    //- Return a reference to the selected turbulence model
    static autoPtr<wellcase> New
    (
        const fvMesh& mesh,
        const dictionary& wellboreProperties,
        const word& wellName
    );

    //- Destructor
    virtual ~wellcase();

    // Member Functions
    const word& name() const
        {
            return name_;
        }
    
    const dimensionedScalar& activate() const
        {
                return activate_;
        }
   
    const dimensionedScalar& q() const
        {
                return q_;
        } 
     
    const dimensionedScalar& volume() const
        {
                return volume_;
        } 
        
    const dimensionedScalar& activetimecondition() const
        {
                return activetimecondition_;
        } 

    const dimensionedScalar& timechangeplan() const
        {
                return timechangeplan_;
        }
        
        const dimensionedScalar& qchangeplan() const
        {
                return qchangeplan_;
        }
 
     const dimensionedScalar& radius() const
        {
                return radius_;
        } 
     
     const dimensionedScalar& height() const
        {
                return height_;
        }
        
        const dimensionedScalar& deltax() const
        {
                return deltax_;
        }
        
        const dimensionedScalar& deltay() const
        {
                return deltay_;
        }

     const dimensionedScalar& pb() const
        {
                return pb_;
        }  
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
