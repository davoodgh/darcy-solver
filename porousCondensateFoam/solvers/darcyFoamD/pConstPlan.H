//////////////////////////////////////// Inj1

coefPConstantInj1 = wellIndexInj1;
explicitSourceTermInj1 = ( coefPConstantInj1*pbInj1*WInj1/volumeInj1 );

qWellInj1 = 0;
forAll ( mesh.C(),cellI)
{

qWellInj1 = qWellInj1 + coefPConstantInj1[cellI] *( -p[cellI] + pbInj1 )*WInj1[cellI] /volumeInj1;

}

////////////////////////////////////////


///////////////////////////////////////// Pro1

coefPConstantPro1 = wellIndexPro1;
explicitSourceTermPro1= ( coefPConstantPro1*pbPro1*WPro1/volumePro1 );

qWellPro1 = 0;
forAll ( mesh.C(),cellI)
{

qWellPro1 = qWellPro1 + coefPConstantPro1[cellI] *( p[cellI] - pbPro1 )*WPro1[cellI] /volumePro1;

}

/////////////////////////////////////////


