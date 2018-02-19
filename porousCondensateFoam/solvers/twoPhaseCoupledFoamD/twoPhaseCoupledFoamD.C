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


Application
   twoPhaseCoupledFoamD

Description
    Stationary coupled solver for incompressible two-phase flow in porous medium

Developers
    Hamid Naderan
    Davood Ghomi

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "wellcase.H"
#include "incompressiblePhase.H"
#include "relativePermeabilityModel.H"
#include "fvBlockMatrix.H"
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #include   "setRootCase.H"
    #include   "createTime.H"
    #include   "createMesh.H"
    #include   "readGravitationalAcceleration.H"
    #include   "createFields.H"
    #include  "createK_member.H"
    #include   "createWellbores.H"
    #include   "createEquationFields.H"

   // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    Info<< "\nStarting time loop\n" << endl;

    while (runTime.run())
    {
          # include "chooseWellPlan.H" 
          # include "setDeltaT.H"
          # include "initConvergenceCheck.H"
             
          runTime++;
          Info<< "Time = " << runTime.timeName() << nl << endl;

	  # include "solvecoupledEquation.H" 
            
          runTime.write();
          Info<< "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
          << "  ClockTime = " << runTime.elapsedClockTime() << " s"
          << nl << endl;
    }

    return (0);
}

// ************************************************************************* //
