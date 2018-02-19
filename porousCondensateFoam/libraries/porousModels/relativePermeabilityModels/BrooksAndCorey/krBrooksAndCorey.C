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


#include "krBrooksAndCorey.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace relativePermeabilityModels
{
defineTypeNameAndDebug(krBrooksAndCorey, 0);

addToRunTimeSelectionTable
(
    relativePermeabilityModel,
    krBrooksAndCorey,
    dictionary
);
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::relativePermeabilityModels::krBrooksAndCorey::krBrooksAndCorey
(
    const word& name,
    const dictionary& transportProperties,
    const volScalarField& Sb
)
    :
    relativePermeabilityModel(name, transportProperties,Sb),
    Smin_
    (
        IOobject
        (
            Sb_.name()+"min",
            Sb_.time().timeName(),
            Sb_.db(),
            IOobject::READ_IF_PRESENT,
            IOobject::NO_WRITE
        ),
        Sb.mesh(),
        transportProperties.lookupOrDefault(Sb_.name()+"min",dimensionedScalar(Sb_.name()+"min",dimless,0))
    ),
    Smax_
    (
        IOobject
        (
            Sb_.name()+"max",
            Sb_.time().timeName(),
            Sb_.db(),
            IOobject::READ_IF_PRESENT,
            IOobject::NO_WRITE
        ),
        Sb.mesh(),
        transportProperties.lookupOrDefault(Sb_.name()+"max",dimensionedScalar(Sb_.name()+"max",dimless,0))
    ),
    krBrooksAndCoreyCoeffs_(transportProperties.subDict(typeName + "Coeffs")),
    n_
    (
        IOobject
        (
            "n",
            Sb_.time().timeName(),
            Sb_.db(),
            IOobject::READ_IF_PRESENT,
            IOobject::NO_WRITE
        ),
        Sb.mesh(),
        krBrooksAndCoreyCoeffs_.lookupOrDefault<scalar>("n",0)
    ),
    Se_((Sb_-Smin_)/(Smax_-Smin_)),
    kramax_
    (
        IOobject
        (
            "kr"+Sb_.name()+"max",
            Sb_.time().timeName(),
            Sb_.db(),
            IOobject::READ_IF_PRESENT,
            IOobject::NO_WRITE
        ),
        Sb.mesh(),
        krBrooksAndCoreyCoeffs_.lookupOrDefault<scalar>("kr"+Sb_.name()+"max",1.0)
    ),
    krbmax_
    (
        IOobject
        (
            "kr"+Sb_.name()+"max",
            Sb_.time().timeName(),
            Sb_.db(),
            IOobject::READ_IF_PRESENT,
            IOobject::NO_WRITE
        ),
        Sb.mesh(),
        krBrooksAndCoreyCoeffs_.lookupOrDefault<scalar>("kr"+Sb_.name()+"max",1.0)
    )
{
    if (gMin(n_) <= 0)
    {
        FatalErrorIn
            (
                "in krBrooksAndCorey.C"
            )
            << "Relative permeability coefficient n equal or less than 0" 
                << exit(FatalError);
    }

}

// ************************************************************************* //
