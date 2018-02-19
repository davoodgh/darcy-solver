///////////////////////////////////////////////////// Injection well1 phasea//////////////////////////////////////////////////////////////////
//                                                                                                                                           //
////////////////////////////////////////////////  well plan is constant pressure//////////////////////////////////////////////////////////////

coefExplicitSourceInj1a =1;
coefImplicitSourceInj1a =1;
coefPConstantInj1a = wellIndexInj1a;

declineHeadInj1a = ( cellCoordinate - zCoordinateInj1a*WInj1 ) & g * rhoa;

explicitSourceTermInj1a = ( coefPConstantInj1a*pbInj1a*WInj1/volumeInj1a - coefPConstantInj1a*declineHeadInj1a*WInj1/volumeInj1a );
qWellInj1a = sum( coefPConstantInj1a*pbInj1a*WInj1 - coefPConstantInj1a*p*WInj1 - coefPConstantInj1a*declineHeadInj1a*WInj1);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


