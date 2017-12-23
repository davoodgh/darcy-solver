//////////////////////////////////////// Inj1

coefPConstantInj1 = wellIndexInj1;
explicitSourceTermInj1 = ( coefPConstantInj1*pbInj1*WInj1/volumeInj1 );

qWellInj1 = 0;
forAll ( mesh.C(),cellI)
{

qWellInj1 = qWellInj1 + coefPConstantInj1[cellI] *( p[cellI] - pbInj1 )*WInj1[cellI] /volumeInj1;

}

////////////////////////////////////////




