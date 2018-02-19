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
    Foam::incompressiblePhase

Description
    Incompressible phase model for the "porousModels" toolbox.

SourceFiles
    incompressiblePhase.C

\*---------------------------------------------------------------------------*/

    #ifndef incompressiblePhase_H
    #define incompressiblePhase_H

    #include "fluidPhase.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

    /*---------------------------------------------------------------------------*\
                   Class incompressiblePhase Declaration
    \*---------------------------------------------------------------------------*/

    class incompressiblePhase
    :
    public fluidPhase
    {

        //- dynamic viscosity
        dimensionedScalar mu_;

        //- density
        dimensionedScalar rho_;

        //- phase fluxes
        autoPtr<surfaceScalarField> phiPtr_;

    public:

        // Constructors

        incompressiblePhase
        (
            const fvMesh& mesh,
            const dictionary& transportProperties,
            const word& phaseName
        );

        // Selectors

        //- Return a reference to the selected turbulence model
        static autoPtr<incompressiblePhase> New
        (
            const fvMesh& mesh,
            const dictionary& transportProperties,
            const word& phaseName
        );

        //- Destructor
        virtual ~incompressiblePhase();

        // Member Functions
        const dimensionedScalar& mu() const
            {
                return mu_;
            }
        
        const dimensionedScalar& rho() const
            {
                return rho_;
            }
        
        const surfaceScalarField& phi() const
            {
                return phiPtr_();
            }
        
        surfaceScalarField& phi()
            {
                return phiPtr_();
            }
    };

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
