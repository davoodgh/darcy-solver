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
    Foam::wellcase

Description
    Generic fluid phase model for the "porousModels" toolbox.

SourceFiles
    wellcase.C

\*---------------------------------------------------------------------------*/
    #ifndef wellcase_H
    #define wellcase_H

    #include "well.H"
    #include "dimensionedScalar.H"
    #include "volFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

   

class wellcase
:
    public well
{
   
protected:

    
     dimensionedScalar              activeWell_;

     dimensionedScalar     activeTimeCondition_;
     dimensionedScalar           timeCondition_;

     dimensionedScalar        activeQCondition_;
     dimensionedScalar              qCondition_;

     dimensionedScalar      activeGorCondition_;
     dimensionedScalar            gorCondition_;

     word                lessTimeConditionPlan_;
     word                moreTimeConditionPlan_;
 
     word                   lessQConditionPlan_;
     word                   moreQConditionPlan_;
     
     word                 lessGorConditionPlan_;
     word                 moreGorConditionPlan_;
     
     dimensionedScalar               qConstant_;
     dimensionedScalar                  volume_;
     dimensionedScalar                  radius_;
     dimensionedScalar                  height_;
     dimensionedScalar                  deltax_;
     dimensionedScalar                  deltay_;
     dimensionedScalar                      pb_;
     dimensionedVector             zCoordinate_;

public:

    // Constructors

    wellcase
    (
        const fvMesh& mesh,
        const dictionary& wellboreProperties,
        const word& wellName
    );


    // Selectors

    //- Return a reference to the selected turbulence model
    static autoPtr<wellcase> New
    (
        const fvMesh& mesh,
        const dictionary& wellboreProperties,
        const word& wellName
    );

    //- Destructor
    virtual ~wellcase();

    // Member Functions
    const word& name() const
        {
                return name_;
        }
    
    const dimensionedScalar& activeWell() const
        {
                return activeWell_;
        }
   
    const dimensionedScalar& activeTimeCondition() const
        {
                return activeTimeCondition_;
        } 
     
    const dimensionedScalar& timeCondition() const
        {
                return timeCondition_;
        } 
        
    const dimensionedScalar& activeQCondition() const
        {
                return activeQCondition_;
        } 

    const dimensionedScalar& qCondition() const
        {
                return qCondition_;
        }
        
    const dimensionedScalar& activeGorCondition() const
        {
                return activeGorCondition_;
        }

     const dimensionedScalar& gorCondition() const
        {
                return gorCondition_;
        }

     const word& lessTimeConditionPlan() const
        {
                return lessTimeConditionPlan_;
        }
 
     const word& moreTimeConditionPlan() const
        {
                return moreTimeConditionPlan_;
        } 

     const word& lessQConditionPlan() const
        {
                return lessQConditionPlan_;
        } 

     const word& moreQConditionPlan() const
        {
                return moreQConditionPlan_;
        } 

     const word& lessGorConditionPlan() const
        {
                return lessGorConditionPlan_;
        } 

     const word& moreGorConditionPlan() const
        {
                return moreGorConditionPlan_;
        } 

     const dimensionedScalar& qConstant() const
        {
                return qConstant_;
        }
   
     const dimensionedScalar& volume() const
        {
                return volume_;
        } 
     
     const dimensionedScalar& radius() const
        {
                return radius_;
        } 
     
     const dimensionedScalar& height() const
        {
                return height_;
        }
        
     const dimensionedScalar& deltax() const
        {
                return deltax_;
        }
        
     const dimensionedScalar& deltay() const
        {
                return deltay_;
        }

     const dimensionedScalar& pb() const
        {
                return pb_;
        }

     const dimensionedVector& zCoordinate() const
        {
                return zCoordinate_;
        }    
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
