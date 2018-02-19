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
    Foam::fluidPhase

Description
    Generic fluid phase model for the "porousModels" toolbox.

SourceFiles
    fluidPhase.C

\*---------------------------------------------------------------------------*/


    #ifndef fluidPhase_H
    #define fluidPhase_H

    #include "phase.H"
    #include "dimensionedScalar.H"
    #include "volFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

    /*---------------------------------------------------------------------------* \
                             Class fluidPhase Declaration
    \*---------------------------------------------------------------------------*/

class fluidPhase
:
    public phase
{
   
protected:

    //- phase density
    volScalarField rho_;

    //- phase velocity
    volVectorField U_;

public:

    // Constructors

    fluidPhase
    (
        const fvMesh& mesh,
        const dictionary& transportProperties,
        const word& phaseName
    );


    // Selectors

    //- Return a reference to the selected turbulence model
    static autoPtr<fluidPhase> New
    (
        const fvMesh& mesh,
        const dictionary& transportProperties,
        const word& phaseName
    );

    //- Destructor
    virtual ~fluidPhase();

    // Member Functions
    const word& name() const
        {
            return name_;
        }
    
    const volVectorField& U() const
        {
            return U_;
        }

    volVectorField& U()
        {
            return U_;
        }

};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
