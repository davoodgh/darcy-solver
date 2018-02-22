
fvScalarMatrix pEqn
(
  - fvm::laplacian(Mf, p) + fvc::div(phiG) + fvm::Sp(coefImplicitSourcePro1a*coefPConstantPro1a*WPro1/volumePro1a,p)

  + fvm::Sp(coefImplicitSourceInj1a*coefPConstantInj1a*WInj1/volumeInj1a,p) - coefExplicitSourcePro1a*explicitSourceTermPro1a 
 
  - coefExplicitSourceInj1a*explicitSourceTermInj1a + fvm::Sp(coefImplicitSourcePro1b*coefPConstantPro1b*WPro1/volumePro1b,p)

  + fvm::Sp(coefImplicitSourceInj1b*coefPConstantInj1b*WInj1/volumeInj1b,p) - coefExplicitSourcePro1b*explicitSourceTermPro1b 
 
  - coefExplicitSourceInj1b*explicitSourceTermInj1b

);

pEqn.setReference(pRefCell, pRefValue);

XEqn.insertEquation(0, pEqn);



