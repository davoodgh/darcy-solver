{
    // Bound the pressure
    dimensionedScalar p1 = min(p);
    dimensionedScalar p2 = max(p);

    if (p1 < pMin || p2 > pMax)
    {
        Info<< "p: " << p1.value() << " " << p2.value()
            << ".  Bounding." << endl;

        p.max(pMin);
        p.min(pMax);
        p.correctBoundaryConditions();
    }

   // Bound the saturation
    dimensionedScalar Sb1 = min(Sb);
    dimensionedScalar Sb2 = max(Sb);

    if (Sb1 < SbMin || Sb2 > SbMax)
    {
        Info<< "Sb: " << Sb1.value() << " " << Sb2.value()
            << ".  Bounding." << endl;

        Sb.max(SbMin);
        Sb.min(SbMax);
        Sb.correctBoundaryConditions();
    }
   
}
