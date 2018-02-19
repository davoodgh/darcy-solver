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
dimensionedVector d_y (K_member.lookup("d_y"));

volScalarField Kx ("Kx",K & d_x & d_x);
volScalarField Ky ("Ky",K & d_y & d_y);

volScalarField K1 ("K1",Kx/Ky);
volScalarField K2 ("K2",Ky/Kx);
