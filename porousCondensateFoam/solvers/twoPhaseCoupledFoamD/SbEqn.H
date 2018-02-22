
    fvScalarMatrix SbEqn
    (
        eps*fvm::ddt(Sb) + fvc::div(phiGSb) - coefExplicitSourcePro1b*explicitSourceTermPro1b  

        - coefExplicitSourceInj1b*explicitSourceTermInj1b
    );

    //SbEqn.relax();

    XEqn.insertEquation(1, SbEqn);

