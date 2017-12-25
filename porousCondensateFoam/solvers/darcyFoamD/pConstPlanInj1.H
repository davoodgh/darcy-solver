//////////////////////////////////////// Inj1
coefExplicitSourceInj1 =1;
coefImplicitSourceInj1 =1;
coefPConstantInj1 = wellIndexInj1;
explicitSourceTermInj1 = ( coefPConstantInj1*pbInj1*WInj1/volumeInj1 );
qWellInj1 = sum( coefPConstantInj1*p*WInj1 - coefPConstantInj1*pbInj1*WInj1 );


