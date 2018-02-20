// Relative permeability model 
autoPtr<relativePermeabilityModel> krModel = relativePermeabilityModel::New("krModel",transportProperties,Sb);


//- relative permeability (kr)
krModel->correct();
volScalarField kra = krModel->kra();
volScalarField krb = krModel->krb();

surfaceScalarField kraf ("kraf",fvc::interpolate(kra,"kra"));
surfaceScalarField krbf ("krbf",fvc::interpolate(krb,"krb"));
surfaceScalarField Fbf ("Fbf",(krbf/mub) / ((kraf/mua) + (krbf/mub)));

volTensorField M ("M", (K*kra/mua) + (K*krb/mub) );

//- mobility and fractional flow 
surfaceTensorField Maf ("Maf",Kf*kraf/mua);
surfaceTensorField Mbf ("Mbf",Kf*krbf/mub);
surfaceTensorField Laf ("Laf",rhoa*Kf*kraf/mua);
surfaceTensorField Lbf ("Lbf",rhob*Kf*krbf/mub);
		
surfaceTensorField Mf ("Mf",Maf+Mbf);
surfaceTensorField Lf ("Lf",Laf+Lbf);

surfaceScalarField phiG("phiG",(Lf & g) & mesh.Sf());
surfaceScalarField phiGSb("phiG",(Lbf & g) & mesh.Sf());


