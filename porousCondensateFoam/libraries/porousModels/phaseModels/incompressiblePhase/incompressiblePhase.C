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

\*---------------------------------------------------------------------------*/

#include "incompressiblePhase.H"
#include "fixedValueFvPatchFields.H"
#include "linear.H"


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::incompressiblePhase::incompressiblePhase
(
    const fvMesh& mesh,
    const dictionary& transportProperties,
    const word& phaseName
)
:
    fluidPhase(mesh,transportProperties,phaseName),
    mu_(dict_.lookup("mu")),
    rho_(dict_.lookup("rho"))
{   
    const word phiName = "phi" + phaseName;

    wordList phiTypes
        (
            U_.boundaryField().size(),
            calculatedFvPatchScalarField::typeName
        );

    phiPtr_.reset
        (
            new surfaceScalarField
            (
                IOobject
                (
                    phiName,
                    mesh.time().timeName(),
                    mesh,
                    IOobject::NO_READ,
                    IOobject::AUTO_WRITE
                ),
                Foam::linearInterpolate(U_) & mesh.Sf(),
                phiTypes
            )
        );
}


Foam::autoPtr<Foam::incompressiblePhase> Foam::incompressiblePhase::New
(
    const fvMesh& mesh,
    const dictionary& transportProperties,
    const word& phaseName
)
{
    return autoPtr<incompressiblePhase>
    (
        new incompressiblePhase(mesh, transportProperties, phaseName)
    );
}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::incompressiblePhase::~incompressiblePhase()
{}


// ************************************************************************* //
