    // Read field bounds
    dictionary fieldBounds = mesh.solutionDict().subDict("fieldBounds");

    // Pressure bounds
    dimensionedScalar pMin("pMin", p.dimensions(), 0);
    dimensionedScalar pMax("pMax", p.dimensions(), 0);

    fieldBounds.lookup(p.name()) >> pMin.value() >> pMax.value();

    // saturation bound
    dimensionedScalar SbMax("SbMax", Sb.dimensions(), 0);
    dimensionedScalar SbMin("SbMin", Sb.dimensions(), 0);

    fieldBounds.lookup(Sb.name()) >> SbMin.value() >> SbMax.value();

