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

#include "darcyGradPressureAniso.H"
#include "addToRunTimeSelectionTable.H"
#include "fvPatchFieldMapper.H"
#include "volFields.H"
#include "uniformDimensionedFields.H"

#include "linear.H"
#include "fvCFD.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::darcyGradPressureAniso::darcyGradPressureAniso
(
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF
)
    :
    fixedGradientFvPatchScalarField(p, iF),
    MfName_("Mf"),
    UName_("U"),
    LfName_("Lf")
{}

Foam::darcyGradPressureAniso::darcyGradPressureAniso
(
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF,
    const dictionary& dict
)
    :
    fixedGradientFvPatchScalarField(p, iF),
    MfName_(dict.lookupOrDefault<word>("Mf", "Mf")),
    UName_(dict.lookupOrDefault<word>("U", "U")),
    LfName_(dict.lookupOrDefault<word>("Lf","Lf"))
{
    fvPatchField<scalar>::operator=(patchInternalField());
    gradient() = 0.0;
}

Foam::darcyGradPressureAniso::darcyGradPressureAniso
(
    const darcyGradPressureAniso& ptf,
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
    :
    fixedGradientFvPatchScalarField(ptf, p, iF, mapper),
    MfName_(ptf.MfName_),
    UName_(ptf.UName_),
    LfName_(ptf.LfName_)
{}

Foam::darcyGradPressureAniso::darcyGradPressureAniso
(
    const darcyGradPressureAniso& ptf
)
    :
    fixedGradientFvPatchScalarField(ptf),
    MfName_(ptf.MfName_),
    UName_(ptf.UName_),
    LfName_(ptf.LfName_)
{}

Foam::darcyGradPressureAniso::darcyGradPressureAniso
(
    const darcyGradPressureAniso& ptf,
    const DimensionedField<scalar, volMesh>& iF
)
    :
    fixedGradientFvPatchScalarField(ptf, iF),
    MfName_(ptf.MfName_),
    UName_(ptf.UName_),
    LfName_(ptf.LfName_)
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::darcyGradPressureAniso::updateCoeffs()
{
    if (updated())
    {
        return;
    }

    const fvsPatchField<tensor>& Mf=
        patch().lookupPatchField<surfaceTensorField, tensor>(MfName_);

    const fvPatchField<vector>& U=
        patch().lookupPatchField<volVectorField, vector>(UName_);

    const fvsPatchField<tensor>& Lf=
        patch().lookupPatchField<surfaceTensorField, tensor>(LfName_);

    //Extract the dictionary from database
    uniformDimensionedVectorField g(db().lookupObject<IOobject>("g"));

	
    gradient() = -  ( inv(Mf) & U & patch().nf());
    gradient() = gradient() + (inv(Mf) & Lf & g.value() & patch().nf() );
  
    fixedGradientFvPatchScalarField::updateCoeffs();
}


void Foam::darcyGradPressureAniso::write(Ostream& os) const
{
    fixedGradientFvPatchScalarField::write(os);
    writeEntryIfDifferent<word>(os, "Mf", "Mf", MfName_);
    writeEntryIfDifferent<word>(os, "U", "U", UName_);
    writeEntryIfDifferent<word>(os, "Lf", "Lf", LfName_);  
    writeEntry("value", os);
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
makePatchTypeField
(
    fvPatchScalarField,
    darcyGradPressureAniso
);
}


// ************************************************************************* //
