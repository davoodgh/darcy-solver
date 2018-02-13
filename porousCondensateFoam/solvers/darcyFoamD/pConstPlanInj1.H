//////////////////////////////////////// Inj1

coefExplicitSourceInj1 =1;
coefImplicitSourceInj1 =1;
coefPConstantInj1 = wellIndexInj1;

declineHeadInj1 = ( cellCoordinate - zCoordinateInj1*WInj1 ) & g * rho;

explicitSourceTermInj1 = ( coefPConstantInj1*pbInj1*WInj1/volumeInj1 - coefPConstantInj1*declineHeadInj1*WInj1/volumeInj1 );
qWellInj1 = sum( coefPConstantInj1*pbInj1*WInj1 - coefPConstantInj1*p*WInj1 - coefPConstantInj1*declineHeadInj1*WInj1);

/////////////////////////////////////////


