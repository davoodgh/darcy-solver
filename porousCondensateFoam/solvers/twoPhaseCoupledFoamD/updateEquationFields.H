//- relative permeability computation
krModel->correct();
kra = krModel->kra();
krb = krModel->krb();

kraf = fvc::interpolate(kra,"kra");
krbf = fvc::interpolate(krb,"krb");
Fbf = (krbf/mub) / ((kraf/mua) + (krbf/mub));

M = (K*kra/mua) + (K*krb/mub);

//- mobility computation 
Maf = Kf*kraf/mua;
Laf = rhoa*Kf*kraf/mua;	
Mbf = Kf*krbf/mub;
Lbf = rhob*Kf*krbf/mub;
Mf = Maf+Mbf;
Lf = Laf+Lbf;

phiG = (Lf & g) & mesh.Sf();
phiGSb = (Lbf & g) & mesh.Sf();
