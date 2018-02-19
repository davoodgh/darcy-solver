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
    Foam::relativePermeabilityModels::krBrooksAndCorey

Description
    Standard Brooks and Corey relative permeability model.

SourceFiles
    krBrooksAndCorey.C

\*---------------------------------------------------------------------------*/

#ifndef krBrooksAndCorey_H
#define krBrooksAndCorey_H

#include "relativePermeabilityModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace relativePermeabilityModels
{

/*---------------------------------------------------------------------------*\
    Class krBrooksAndCorey Declaration
    \*---------------------------------------------------------------------------*/

class krBrooksAndCorey
:
    public relativePermeabilityModel
{
    //- Private data
    volScalarField Smin_;
    volScalarField Smax_;

    dictionary krBrooksAndCoreyCoeffs_;
    volScalarField n_;

    //- effective saturation of phase b
    volScalarField Se_;

    //- end points
    volScalarField kramax_;
    volScalarField krbmax_;

        
public:

    //- Runtime type information
    TypeName("BrooksAndCorey");

    // Constructors

    //- Construct from components
    krBrooksAndCorey
    (
        const word& name,
        const dictionary& transportProperties,
        const volScalarField& Sb
    );

    //- Destructor
    ~krBrooksAndCorey()
        {}

    // Member Functions

    //- Correct the relative permeabilities
    void correct()
        {
            Se_==(Sb_-Smin_)/(Smax_-Smin_);
            kra_ = kramax_* pow((scalar(1)-Se_),n_);
            krb_ = krbmax_ * pow(Se_,n_);
	
        }

};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace relativePermeabilityModels

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
