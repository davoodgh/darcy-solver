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

Class
    Foam::well

Description
    Generic phase model for the "porousModels" toolbox.

SourceFiles
    well.C

\*---------------------------------------------------------------------------*/

    #ifndef well_H
    #define well_H

    #include "dictionary.H"
    #include "fvMesh.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

  

class well
{

protected:

    //- reference to the mesh
    const fvMesh& mesh_;

    // Private data
    dictionary dict_;

    //- Name of well
    word name_;

public:

    // Constructors

    well
    (
        const fvMesh& mesh,
        const dictionary& wellboreProperties,
        const word& wellName
    );

    // Selectors

  
    static autoPtr<well> New
    (
        const fvMesh& mesh,
        const dictionary& wellboreProperties,
        const word& wellName
    );

    //- Destructor
    virtual ~well();

    // Member Functions
    const word& name() const
        {
            return name_;
        }

    const fvMesh& mesh() const
        {
            return mesh_;
        }

};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
