///////////////////////////////////////// Pro1

coefImplicitSourcePro1 =1;
coefPConstantPro1 = wellIndexPro1;
explicitSourceTermPro1= ( coefPConstantPro1*pbPro1*WPro1/volumePro1 );

qWellPro1 = 0;
forAll ( mesh.C(),cellI)
{

qWellPro1 = qWellPro1 + coefPConstantPro1[cellI] *( p[cellI] - pbPro1 )*WPro1[cellI] /volumePro1;

}

/////////////////////////////////////////


