/////////////////////////////////////////////////////////////////////////

Info<< "Reading wellboreProperties\n" << endl;

IOdictionary wellboreProperties
(
    IOobject
    (
        "wellboreProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ,
        IOobject::NO_WRITE
    )
);



// Injection1 
autoPtr<wellcase> wellInj1 = wellcase::New(mesh,wellboreProperties,"Inj1");
const dimensionedScalar& activateInj1 = wellInj1->activate();
const dimensionedScalar& qInj1 = wellInj1->q();
const dimensionedScalar& volumeInj1 = wellInj1->volume();
const dimensionedScalar& timechangeplanInj1 = wellInj1->timechangeplan();
const dimensionedScalar& radiusInj1 = wellInj1->radius();
const dimensionedScalar& heightInj1 = wellInj1->height();
const dimensionedScalar& pbInj1 = wellInj1->pb();

Info<< "Reading field WInj1 (injection wellbore)\n" << endl;
volScalarField WInj1
(
    IOobject
    (
        "WInj1",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("",dimensionSet(0,0,0,0,0),0)
);

dimensionedScalar SrcInj1("SrcInj1",dimensionSet(0,0,-1,0,0),0.);
SrcInj1 = qInj1/volumeInj1;

//////plan

volScalarField r_eq=0.28*  Foam::pow( xDim*xDim*Foam::pow(K2,0.5) + zDim*zDim*Foam::pow(K1,0.5),0.5 ) / (Foam::pow(K1,0.25) + Foam::pow(K2,0.25) );
volScalarField coefInj1=mu*log(r_eq/radiusInj1)/(2*3.14*heightInj1*Foam::pow(Kx*Kz,0.5));

// production1
autoPtr<wellcase> wellPro1 = wellcase::New(mesh,wellboreProperties,"Pro1");
const dimensionedScalar& activatePro1 = wellPro1->activate();
const dimensionedScalar& qPro1 = wellPro1->q();
const dimensionedScalar& volumePro1 = wellPro1->volume();
const dimensionedScalar& timechangeplanPro1 = wellPro1->timechangeplan();
const dimensionedScalar& radiusPro1 = wellPro1->radius();
const dimensionedScalar& heightPro1 = wellPro1->height();
const dimensionedScalar& pbPro1 = wellPro1->pb();

Info<< "Reading field WPro1 (production wellbore)\n" << endl;
volScalarField WPro1
(
    IOobject
    (
        "WPro1",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("",dimensionSet(0,0,0,0,0),0)
);

dimensionedScalar SrcPro1("SrcPro1",dimensionSet(0,0,-1,0,0),0.);
SrcPro1 = qPro1/volumePro1;

//plan
volScalarField coefPro1=mu*log(r_eq/radiusPro1)/(2*3.14*heightPro1*Foam::pow(Kx*Kz,0.5));


////////////////////////////////////////////
