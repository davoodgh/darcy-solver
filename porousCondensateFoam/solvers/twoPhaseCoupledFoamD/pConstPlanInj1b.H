//////////////////////////////////////////////////////// Injection well1 phaseb/////////////////////////////////////////////////////////////////
//                                                                                                                                            //
///////////////////////////////////////////////////  well plan is constant pressure////////////////////////////////////////////////////////////

coefExplicitSourceInj1b =1;
coefImplicitSourceInj1b =1;
coefPConstantInj1b = wellIndexInj1b;

declineHeadInj1b = ( cellCoordinate - zCoordinateInj1b*WInj1 ) & g * rhob;

explicitSourceTermInj1b = ( coefPConstantInj1b*pbInj1b*WInj1/volumeInj1b - coefPConstantInj1b*declineHeadInj1b*WInj1/volumeInj1b );
qWellInj1b = sum( coefPConstantInj1b*pbInj1b*WInj1 - coefPConstantInj1b*p*WInj1 - coefPConstantInj1b*declineHeadInj1b*WInj1);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


