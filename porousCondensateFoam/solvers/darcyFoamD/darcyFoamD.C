/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011-2016 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------


\*---------------------------------------------------------------------------*/

#include "fvCFD.H"

#include "wellcase.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #include   "setRootCase.H"
    #include   "createTime.H"
    #include   "createMesh.H"
    #include   "readGravitationalAcceleration.H"
    #include   "createFields.H"
    # include  "createK_member.H"
    #include   "createWellbores.H"

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

      Info<< "\nStarting time loop\n" << endl;

    while (runTime.run())
    {
             # include "choosewellplan.H"
             
            # include "setDeltaT.H"
             
            runTime++;
            
            Info<< "Time = " << runTime.timeName() << nl << endl;
	    fvScalarMatrix pEqn
                (
                    fvm::laplacian(-Mf,p) + fvc::div(phig) + fvm::Sp(coefImplicitSourcePro1*coefPConstantPro1*WPro1/volumePro1,p)
                   + fvm::Sp(coefImplicitSourceInj1*coefPConstantInj1*WInj1/volumeInj1,p) - coefExplicitSourcePro1*explicitSourceTermPro1 - coefExplicitSourceInj1*explicitSourceTermInj1 
                );

	    pEqn.solve();
            volVectorField U("U",((-M & fvc::grad(p)) + (M & g) * rho ) );
	    U.correctBoundaryConditions();
          
          //  surfaceScalarField phip("phip",Mf & mesh.Sf());
            runTime.write();
       
            Info<< "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
            << "  ClockTime = " << runTime.elapsedClockTime() << " s"
            << nl << endl;
    }

 


    return 0;
}

// ************************************************************************* //
