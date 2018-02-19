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

#include "wellcase.H"
#include "fixedValueFvPatchFields.H"
#include "linear.H"


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::wellcase::wellcase
(
    const fvMesh& mesh,
    const dictionary& wellboreProperties,
    const word& wellName
)
    :  
    well(mesh,wellboreProperties,wellName),
    activeWell_(dict_.lookup("activeWell")),

    activeTimeCondition_(dict_.lookup("activeTimeCondition")),
    timeCondition_(dict_.lookup("timeCondition")),
    
    activeQCondition_(dict_.lookup("activeQCondition")),
    qCondition_(dict_.lookup("qCondition")),

    activeGorCondition_(dict_.lookup("activeGorCondition")),
    gorCondition_(dict_.lookup("gorCondition")),
 
    lessTimeConditionPlan_(dict_.lookup("lessTimeConditionPlan")),
    moreTimeConditionPlan_(dict_.lookup("moreTimeConditionPlan")),

    lessQConditionPlan_(dict_.lookup("lessQConditionPlan")),
    moreQConditionPlan_(dict_.lookup("moreQConditionPlan")),

    lessGorConditionPlan_(dict_.lookup("lessGorConditionPlan")),
    moreGorConditionPlan_(dict_.lookup("moreGorConditionPlan")),
        
    qConstant_(dict_.lookup("qConstant")),
    volume_(dict_.lookup("volume")),
    radius_(dict_.lookup("radius")),
    height_(dict_.lookup("height")),
    deltax_(dict_.lookup("deltax")),
    deltay_(dict_.lookup("deltay")),
    pb_(dict_.lookup("pb")),
    zCoordinate_(dict_.lookup("zCoordinate"))
    
{
}



Foam::autoPtr<Foam::wellcase> Foam::wellcase::New
(
    const fvMesh& mesh,
    const dictionary& wellboreProperties,
    const word& wellName
)
{
    return autoPtr<wellcase>
    (
        new wellcase(mesh, wellboreProperties, wellName)
    );
}





// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::wellcase::~wellcase()
{}


// ************************************************************************* //
