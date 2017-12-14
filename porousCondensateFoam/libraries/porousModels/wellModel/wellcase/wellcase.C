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
    activeWell_(dict_.lookup("activeWell_")),

    activeTimeCondition_(dict_.lookup("activeTimeCondition_")),
    timeCondition_(dict_.lookup("timeCondition_")),
    
    activeQCondition_(dict_.lookup("activeQCondition_")),
    qCondition_(dict_.lookup("qCondition_")),

    activeGorCondition_(dict_.lookup("activeGorCondition_")),
    gorCondition_(dict_.lookup("gorCondition_")),
 
    lessTimeConditionPlan_(dict_.lookup("lessTimeConditionPlan_")),
    moreTimeConditionPlan_(dict_.lookup("moreTimeConditionPlan_")),

    lessQConditionPlan_(dict_.lookup("lessQConditionPlan_")),
    moreQConditionPlan_(dict_.lookup("moreQConditionPlan_")),

    lessGorConditionPlan_(dict_.lookup("lessGorConditionPlan_")),
    moreGorConditionPlan_(dict_.lookup("moreGorConditionPlan_")),
        
    qConstant_(dict_.lookup("qConstant")),
    volume_(dict_.lookup("volume")),
    radius_(dict_.lookup("radius")),
    height_(dict_.lookup("height")),
    deltax_(dict_.lookup("deltax")),
    deltaz_(dict_.lookup("deltaz")),
    pb_(dict_.lookup("pb"))
    
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
