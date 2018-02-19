/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | foam-extend: Open Source CFD
   \\    /   O peration     | Version:     4.0
    \\  /    A nd           | Web:         http://www.foam-extend.org
     \\/     M anipulation  | For copyright notice see file Copyright
-------------------------------------------------------------------------------
License
    This file is part of foam-extend.

    foam-extend is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation, either version 3 of the License, or (at your
    option) any later version.

    foam-extend is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with foam-extend.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::phase

Description
    Generic phase model for the "porousModels" toolbox.

SourceFiles
    phase.C

\*---------------------------------------------------------------------------*/

    #ifndef phase_H
    #define phase_H

    #include "dictionary.H"
    #include "fvMesh.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

    /*---------------------------------------------------------------------------* \
                             Class fluidPhase Declaration
    \*---------------------------------------------------------------------------*/

class phase
{

protected:

    //- reference to the mesh
    const fvMesh& mesh_;

    // Private data
    dictionary dict_;

    //- Name of phase
    word name_;

public:

    // Constructors

    phase
    (
        const fvMesh& mesh,
        const dictionary& transportProperties,
        const word& phaseName
    );

    // Selectors

    //- Return a reference to the selected turbulence model
    static autoPtr<phase> New
    (
        const fvMesh& mesh,
        const dictionary& transportProperties,
        const word& phaseName
    );

    //- Destructor
    virtual ~phase();

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
