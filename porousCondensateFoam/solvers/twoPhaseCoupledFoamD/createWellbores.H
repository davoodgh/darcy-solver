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


// Injection well1 phase a
 
autoPtr<wellcase> wellInj1a = wellcase::New(mesh,wellboreProperties,"Inj1a");
const dimensionedScalar& activeWellInj1a = wellInj1a->activeWell();

const dimensionedScalar& activeTimeConditionInj1a = wellInj1a->activeTimeCondition();
const dimensionedScalar& timeConditionInj1a = wellInj1a->timeCondition();

const dimensionedScalar& activeQConditionInj1a = wellInj1a->activeQCondition();
const dimensionedScalar& qConditionInj1a = wellInj1a->qCondition();

const dimensionedScalar& activeGorConditionInj1a = wellInj1a->activeGorCondition();
const dimensionedScalar& gorConditionInj1a = wellInj1a->gorCondition();

const word& lessTimeConditionPlanInj1a = wellInj1a->lessTimeConditionPlan();
const word& moreTimeConditionPlanInj1a = wellInj1a->moreTimeConditionPlan();

const word& lessQConditionPlanInj1a = wellInj1a->lessQConditionPlan();
const word& moreQConditionPlanInj1a = wellInj1a->moreQConditionPlan();

const word& lessGorConditionPlanInj1a = wellInj1a->lessGorConditionPlan();
const word& moreGorConditionPlanInj1a = wellInj1a->moreGorConditionPlan();

const dimensionedScalar& qConstantInj1a = wellInj1a->qConstant();

const dimensionedScalar& volumeInj1a = wellInj1a->volume();
const dimensionedScalar& radiusInj1a = wellInj1a->radius();
const dimensionedScalar& heightInj1a = wellInj1a->height();
const dimensionedScalar& deltaxInj1a = wellInj1a->deltax();
const dimensionedScalar& deltayInj1a = wellInj1a->deltay();
const dimensionedScalar& pbInj1a = wellInj1a->pb();
const dimensionedVector& zCoordinateInj1a = wellInj1a->zCoordinate();

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

dimensionedScalar SrcInj1a("SrcInj1a",dimensionSet(0,0,-1,0,0),0.);
SrcInj1a = qConstantInj1a/volumeInj1a;

//Fields for constant q plan in wellInj1a

volScalarField coefQConstantInj1a
(
    IOobject
    (
        "coefQConstantInj1a",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
dimensionedScalar  ("coefQConstantInj1a",dimensionSet (0,0,0,0,0,0,0),0)    
);

//Fields for constant pressure plan in wellInj1a

volScalarField coefPConstantInj1a
(
    IOobject
    (
        "coefPConstantInj1a",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
dimensionedScalar  ("coefPConstantInj1a",dimensionSet (-1,4,1,0,0,0,0),0)
);

volScalarField r_eqInj1a=0.28*  Foam::pow( deltaxInj1a*deltaxInj1a*Foam::pow(K2,0.5) + deltayInj1a*deltayInj1a*Foam::pow(K1,0.5),0.5 ) / (Foam::pow(K1,0.25) + Foam::pow(K2,0.25) );

volScalarField  wellIndexInj1a = (2*3.14*heightInj1a*Foam::pow(Kx*Ky,0.5)) / (mua*log(r_eqInj1a/radiusInj1a));

dimensionedScalar coefImplicitSourceInj1a("coefImplicitSourceInj1a",dimensionSet (0,0,0,0,0,0,0),0);
dimensionedScalar coefExplicitSourceInj1a("coefExplicitSourceInj1a",dimensionSet (0,0,0,0,0,0,0),1);
///

volScalarField explicitSourceTermInj1a
(
    IOobject
    (
       "explicitSourceTermInj1a",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
dimensionedScalar  ("explicitSourceTermInj1a",dimensionSet (0,0,-1,0,0,0,0),0)   
);

dimensionedScalar qWellInj1a("qWellInj1a",dimensionSet (0,3,-1,0,0,0,0),0);

volScalarField declineHeadInj1a
(
    IOobject
    (
       "declineHeadInj1a",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
dimensionedScalar  ("declineHeadInj1a",dimensionSet (1,-1,-2,0,0,0,0),0)   
);

//////////////////////////////////////////////////////////////////////////////////////////////


// production well1 phase a

autoPtr<wellcase> wellPro1a = wellcase::New(mesh,wellboreProperties,"Pro1a");
const dimensionedScalar& activeWellPro1a = wellPro1a->activeWell();

const dimensionedScalar& activeTimeConditionPro1a = wellPro1a->activeTimeCondition();
const dimensionedScalar& timeConditionPro1a = wellPro1a->timeCondition();

const dimensionedScalar& activeQConditionPro1a = wellPro1a->activeQCondition();
const dimensionedScalar& qConditionPro1a = wellPro1a->qCondition();

const dimensionedScalar& activeGorConditionPro1a = wellPro1a->activeGorCondition();
const dimensionedScalar& gorConditionPro1a = wellPro1a->gorCondition();

const word& lessTimeConditionPlanPro1a = wellPro1a->lessTimeConditionPlan();
const word& moreTimeConditionPlanPro1a = wellPro1a->moreTimeConditionPlan();

const word& lessQConditionPlanPro1a = wellPro1a->lessQConditionPlan();
const word& moreQConditionPlanPro1a = wellPro1a->moreQConditionPlan();

const word& lessGorConditionPlanPro1a = wellPro1a->lessGorConditionPlan();
const word& moreGorConditionPlanPro1a = wellPro1a->moreGorConditionPlan();

const dimensionedScalar& qConstantPro1a = wellPro1a->qConstant();

const dimensionedScalar& volumePro1a = wellPro1a->volume();
const dimensionedScalar& radiusPro1a = wellPro1a->radius();
const dimensionedScalar& heightPro1a = wellPro1a->height();
const dimensionedScalar& deltaxPro1a = wellPro1a->deltax();
const dimensionedScalar& deltayPro1a = wellPro1a->deltay();
const dimensionedScalar& pbPro1a = wellPro1a->pb();
const dimensionedVector& zCoordinatePro1a = wellPro1a->zCoordinate();


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

dimensionedScalar SrcPro1a("SrcPro1a",dimensionSet(0,0,-1,0,0),0.);
SrcPro1a = qConstantPro1a/volumePro1a;

//Fields for constant q plan in wellPro1a

volScalarField coefQConstantPro1a
(
    IOobject
    (
        "coefQConstantPro1a",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
dimensionedScalar  ("coefQConstantPro1a",dimensionSet (0,0,0,0,0,0,0),0)
);


//Fields for constant pressure plan in wellPro1a

volScalarField coefPConstantPro1a
(
    IOobject
    (
        "coefPConstantPro1a",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
dimensionedScalar  ("coefPConstantPro1a",dimensionSet (-1,4,1,0,0,0,0),0)
);

volScalarField  r_eqPro1a=0.28*  Foam::pow( deltaxPro1a*deltaxPro1a*Foam::pow(K2,0.5) + deltayPro1a*deltayPro1a*Foam::pow(K1,0.5),0.5 ) / (Foam::pow(K1,0.25) + Foam::pow(K2,0.25) );

volScalarField  wellIndexPro1a = (2*3.14*heightPro1a*Foam::pow(Kx*Ky,0.5)) / (mua*log(r_eqPro1a/radiusPro1a));

dimensionedScalar coefImplicitSourcePro1a("coefImplicitSourcePro1a",dimensionSet (0,0,0,0,0,0,0),0);
dimensionedScalar coefExplicitSourcePro1a("coefExplicitSourcePro1a",dimensionSet (0,0,0,0,0,0,0),1);

volScalarField explicitSourceTermPro1a
(
    IOobject
    (
       "explicitSourceTermPro1a",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
dimensionedScalar  ("explicitSourceTermPro1a",dimensionSet (0,0,-1,0,0,0,0),0)   
);
 
dimensionedScalar qWellPro1a("qWellPro1a",dimensionSet (0,3,-1,0,0,0,0),0);

volScalarField declineHeadPro1a
(
    IOobject
    (
       "declineHeadPro1a",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
dimensionedScalar  ("declineHeadPro1a",dimensionSet (1,-1,-2,0,0,0,0),0)   
);

///////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////

// Injection well1 phaseb
 
autoPtr<wellcase> wellInj1b = wellcase::New(mesh,wellboreProperties,"Inj1b");
const dimensionedScalar& activeWellInj1b = wellInj1b->activeWell();

const dimensionedScalar& activeTimeConditionInj1b = wellInj1b->activeTimeCondition();
const dimensionedScalar& timeConditionInj1b = wellInj1b->timeCondition();

const dimensionedScalar& activeQConditionInj1b = wellInj1b->activeQCondition();
const dimensionedScalar& qConditionInj1b = wellInj1b->qCondition();

const dimensionedScalar& activeGorConditionInj1b = wellInj1b->activeGorCondition();
const dimensionedScalar& gorConditionInj1b = wellInj1b->gorCondition();

const word& lessTimeConditionPlanInj1b = wellInj1b->lessTimeConditionPlan();
const word& moreTimeConditionPlanInj1b = wellInj1b->moreTimeConditionPlan();

const word& lessQConditionPlanInj1b = wellInj1b->lessQConditionPlan();
const word& moreQConditionPlanInj1b = wellInj1b->moreQConditionPlan();

const word& lessGorConditionPlanInj1b = wellInj1b->lessGorConditionPlan();
const word& moreGorConditionPlanInj1b = wellInj1b->moreGorConditionPlan();

const dimensionedScalar& qConstantInj1b = wellInj1b->qConstant();

const dimensionedScalar& volumeInj1b = wellInj1b->volume();
const dimensionedScalar& radiusInj1b = wellInj1b->radius();
const dimensionedScalar& heightInj1b = wellInj1b->height();
const dimensionedScalar& deltaxInj1b = wellInj1b->deltax();
const dimensionedScalar& deltayInj1b = wellInj1b->deltay();
const dimensionedScalar& pbInj1b = wellInj1b->pb();
const dimensionedVector& zCoordinateInj1b = wellInj1b->zCoordinate();


dimensionedScalar SrcInj1b("SrcInj1b",dimensionSet(0,0,-1,0,0),0.);
SrcInj1b = qConstantInj1b/volumeInj1b;

//Fields for constant q plan in wellInj1b

volScalarField coefQConstantInj1b
(
    IOobject
    (
        "coefQConstantInj1b",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
dimensionedScalar  ("coefQConstantInj1b",dimensionSet (0,0,0,0,0,0,0),0)    
);

//Fields for constant pressure plan in wellInj1b

volScalarField coefPConstantInj1b
(
    IOobject
    (
        "coefPConstantInj1b",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
dimensionedScalar  ("coefPConstantInj1b",dimensionSet (-1,4,1,0,0,0,0),0)
);

volScalarField r_eqInj1b=0.28*  Foam::pow( deltaxInj1b*deltaxInj1b*Foam::pow(K2,0.5) + deltayInj1b*deltayInj1b*Foam::pow(K1,0.5),0.5 ) / (Foam::pow(K1,0.25) + Foam::pow(K2,0.25) );

volScalarField  wellIndexInj1b = (2*3.14*heightInj1b*Foam::pow(Kx*Ky,0.5)) / (mub*log(r_eqInj1b/radiusInj1b));

dimensionedScalar coefImplicitSourceInj1b("coefImplicitSourceInj1b",dimensionSet (0,0,0,0,0,0,0),0);
dimensionedScalar coefExplicitSourceInj1b("coefExplicitSourceInj1b",dimensionSet (0,0,0,0,0,0,0),1);
///

volScalarField explicitSourceTermInj1b
(
    IOobject
    (
       "explicitSourceTermInj1b",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
dimensionedScalar  ("explicitSourceTermInj1b",dimensionSet (0,0,-1,0,0,0,0),0)   
);

dimensionedScalar qWellInj1b("qWellInj1b",dimensionSet (0,3,-1,0,0,0,0),0);

volScalarField declineHeadInj1b
(
    IOobject
    (
       "declineHeadInj1b",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
dimensionedScalar  ("declineHeadInj1b",dimensionSet (1,-1,-2,0,0,0,0),0)   
);

//////////////////////////////////////////////////////////////////////////////////////////////


// production well1 phaseb

autoPtr<wellcase> wellPro1b = wellcase::New(mesh,wellboreProperties,"Pro1b");
const dimensionedScalar& activeWellPro1b = wellPro1b->activeWell();

const dimensionedScalar& activeTimeConditionPro1b = wellPro1b->activeTimeCondition();
const dimensionedScalar& timeConditionPro1b = wellPro1b->timeCondition();

const dimensionedScalar& activeQConditionPro1b = wellPro1b->activeQCondition();
const dimensionedScalar& qConditionPro1b = wellPro1b->qCondition();

const dimensionedScalar& activeGorConditionPro1b = wellPro1b->activeGorCondition();
const dimensionedScalar& gorConditionPro1b = wellPro1b->gorCondition();

const word& lessTimeConditionPlanPro1b = wellPro1b->lessTimeConditionPlan();
const word& moreTimeConditionPlanPro1b = wellPro1b->moreTimeConditionPlan();

const word& lessQConditionPlanPro1b = wellPro1b->lessQConditionPlan();
const word& moreQConditionPlanPro1b = wellPro1b->moreQConditionPlan();

const word& lessGorConditionPlanPro1b = wellPro1b->lessGorConditionPlan();
const word& moreGorConditionPlanPro1b = wellPro1b->moreGorConditionPlan();

const dimensionedScalar& qConstantPro1b = wellPro1b->qConstant();

const dimensionedScalar& volumePro1b = wellPro1b->volume();
const dimensionedScalar& radiusPro1b = wellPro1b->radius();
const dimensionedScalar& heightPro1b = wellPro1b->height();
const dimensionedScalar& deltaxPro1b = wellPro1b->deltax();
const dimensionedScalar& deltayPro1b = wellPro1b->deltay();
const dimensionedScalar& pbPro1b = wellPro1b->pb();
const dimensionedVector& zCoordinatePro1b = wellPro1b->zCoordinate();

dimensionedScalar SrcPro1b("SrcPro1b",dimensionSet(0,0,-1,0,0),0.);
SrcPro1b = qConstantPro1b/volumePro1b;

//Fields for constant q plan in wellPro1b

volScalarField coefQConstantPro1b
(
    IOobject
    (
        "coefQConstantPro1b",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
dimensionedScalar  ("coefQConstantPro1b",dimensionSet (0,0,0,0,0,0,0),0)
);


//Fields for constant pressure plan in wellPro1b

volScalarField coefPConstantPro1b
(
    IOobject
    (
        "coefPConstantPro1b",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
dimensionedScalar  ("coefPConstantPro1b",dimensionSet (-1,4,1,0,0,0,0),0)
);

volScalarField  r_eqPro1b=0.28*  Foam::pow( deltaxPro1b*deltaxPro1b*Foam::pow(K2,0.5) + deltayPro1b*deltayPro1b*Foam::pow(K1,0.5),0.5 ) / (Foam::pow(K1,0.25) + Foam::pow(K2,0.25) );

volScalarField  wellIndexPro1b = (2*3.14*heightPro1b*Foam::pow(Kx*Ky,0.5)) / (mub*log(r_eqPro1b/radiusPro1b));

dimensionedScalar coefImplicitSourcePro1b("coefImplicitSourcePro1b",dimensionSet (0,0,0,0,0,0,0),0);
dimensionedScalar coefExplicitSourcePro1b("coefExplicitSourcePro1b",dimensionSet (0,0,0,0,0,0,0),1);

volScalarField explicitSourceTermPro1b
(
    IOobject
    (
       "explicitSourceTermPro1b",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
dimensionedScalar  ("explicitSourceTermPro1b",dimensionSet (0,0,-1,0,0,0,0),0)   
);
 
dimensionedScalar qWellPro1b("qWellPro1b",dimensionSet (0,3,-1,0,0,0,0),0);

volScalarField declineHeadPro1b
(
    IOobject
    (
       "declineHeadPro1b",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
dimensionedScalar  ("declineHeadPro1b",dimensionSet (1,-1,-2,0,0,0,0),0)   
);

///////////////////////////////////////////////////////////////////////////////////
