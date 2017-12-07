Info<< "Reading K_member \n" << endl;

IOdictionary K_member
(
    IOobject
    (
        "K_member",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ,
        IOobject::NO_WRITE
    )
);


dimensionedVector d_x (K_member.lookup("d_x"));
dimensionedVector d_z (K_member.lookup("d_z"));

volScalarField Kx ("Kx",K & d_x & d_x);
volScalarField Kz ("Kz",K & d_z & d_z);

volScalarField K1 ("K1",Kx/Kz);
volScalarField K2 ("K2",Kz/Kx);
