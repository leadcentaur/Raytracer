//!write a test scale for each of these 
//Transvection(Vector(2,3,4,1), 0,0,0,0,0,1).print();
//Transvection(Vector(2,3,4,1), 0,0,0,0,1,0).print();
//Transvection(Vector(2,3,4,1), 0,0,0,1,0,0).print();
//Transvection(Vector(2,3,4,1), 0,0,1,0,0,0).print();
//Transvection(Vector(2,3,4,1), 1,1,0,0,0,0).print();


    //! Rotation test

    // Vector p1 = Vector(2,3,4,POINT_FLAG);
    // Matrix hQY = Rotation(M_PI / 4, Axis::RotZ);
    // Vector r4 = hQY * p1;

    // // Transvection(Vector(2,3,4,1), 0,0,0,0,0,1).print();
    // Vector(2,3,4,1).Transvection(0,0,0,0,0,1).print();

//  vector<vector<int>> z = {
//         {1,2,6},
//         {-5,8,-4},
//         {2,6,4}
//     };

//     vector<vector<double>> a = {
//         {8,-5,9,2},
//         {7,5,6,1},
//         {-6,0,9,6},
//         {-3,0,-9,-4}
//     };

//     vector<vector<double>> b = {
//         {9,3,0,9},
//         {-5,-2,-6,-3},
//         {-4,9,6,4},
//         {-7,6,6,2}
//     };

//      vector<vector<double>> dm = {
//         {1,5},
//         {-3,2},
//     }; 

//     Matrix mi = Matrix(4,4, b);
//     Matrix x = mi.Inverse();
//     x.print();

//     // //point multiplied by translation
//     // Vector tranformation = Vector(5,-3,2,1);
//     // Vector point = Vector(-3, 4, 5, 1);
//     // Matrix tM = Translation(tranformation);
//     // Vector pXtform = tM * point;

//     // //point multiplied by inverse of trans
//     // Matrix inv = tM.Inverse();
//     // Vector res = inv * point;
//     // //res.print();

//     // //scaling by a vector or a point
//     // Vector scaleVec = Vector(2, 3, 4, 1);
//     // Vector p0 = Vector(-4, 6, 8, 1);
//     // Matrix scaleMatrix = Scaling(scaleVec);
//     // Vector pXsm = scaleMatrix * p0;
//     // //pXsm.print();

//     // //scaling inverse
//     // Matrix invScalemat = scaleMatrix.Inverse();
//     // Vector iXv = invScalemat * p0;
//     // //iXv.print();

//     // //reflection example
//     // Matrix scalingMatrix = Scaling(Vector(-1, 1, 1, 0));
//     // //the point to reflect
//     // Vector reflectPoint = Vector(2,3,4,1);
//     // Vector reflectionVec = scalingMatrix * reflectPoint;
//     // //gets reflected on the xAxis
//     // //reflectionVec.print();
    

//     // //Matrix rotation of a point along x axis
//     // cout << "Half quarter: " << M_PI / 4 << '\n';  

//     // Vector p1 = Vector(0,1,0,0);
//     // Matrix halfQuarter = Rotation(M_PI / 4, Axis::RotX);
//     // Vector resx = halfQuarter * p1;

//     // Matrix fullQuarter = Rotation(M_PI / 4, Axis::RotY);
//     // Vector resy = fullQuarter * p1;
//     // //resd.print();

//     // Vector p2 = Vector(0,1,0);
//     // Matrix halfQuarter2 = Rotation(M_PI / 4, Axis::RotX);
//     // halfQuarter2.print();

//     // Matrix inverseHalfQuarter = halfQuarter2.Inverse();
//     // Vector resInv = inverseHalfQuarter * p2;
//     resInv.print();


//  // chaning transformations example
//     // rotating the teapot right side up
//     Matrix A = Rotation(PI / 2, Axis::RotX);
//     // teapot = A * Teapot
//     A.print();

//     // next make the tea pot 5x larger
//     Matrix B = Scaling(Vector(5,5,5,0));
//     // teapot = B * teapot
//     B.print();

//     //finally, move the teapot onto a table
//     Matrix C = Translation(Vector(10,5,7,0));
//     // teapot = C * Teapot
// Ray rayA = Ray(Vector(0,0,0), Vector(0,0,1));
//     vector<Intersection> ic1 = Intersect(s1, rayA);
//     cout << "Intersections for Sphere " << ic1[0].sphere.getSphereID() << " are: " << ic1[0].t << "  and " << ic1[1].t << '\n';

//     Ray rayB = Ray(Vector(0,0,-5), Vector(0,0,1));
//     vector<Intersection> ic2 = Intersect(s1, rayB);
//     cout << "Intersections for Sphere " << ic2[0].sphere.getSphereID() << " are: " << ic2[0].t << "  and " << ic2[1].t << '\n';

//     //Each call to the intersection function returners two
//     // or possibly one intersection record output as per ic1[0] and [1] index referencing.
//     Ray rayC = Ray(Vector(0,0,-5), Vector(0,0,1));
//     vector<Intersection> ic3 = Intersect(s1, rayC);

//     Intersection i1 = ic1[0];
//     i1.t = -1;

//     Intersection i2 = ic1[1];
//     i2.t = -1;
    
//      Intersection i3 = ic2[0];
//     i3.t = -3;
   
//      Intersection i4 = ic2[1];
//      i4.t = 2;

//     vector<Intersection> results = aggregatePoints({i2, i1});

//      cout << "Front: " << results.front().t << '\n';
//      cout << "Back: " << results.back().t << "\n\n";

//      for (auto x : results){
//          cout << x.t << '\n';
//      }

//      Intersection val = hit(results);
//      cout << "\nHit returned: " << val.t << "\n";

//     //Translating a ray example
//     Ray rx = Ray(Vector(1,2,3,1),Vector(0,1,0,0));
//     Matrix tMatrix = Translation(Vector(3,4,5,0));
//     Ray tForm = transform(rx, tMatrix);

//     tForm.getDirection().print();
//     tForm.getOrigin().print();

//     //Scaling a ray example
//     Ray ry = Ray(Vector(1,2,3,1), Vector(0,1,0,0));
//     Matrix sMatrix = Scaling(Vector(2,3,4,0));
//     Ray tf = transform(ry, sMatrix);

//     tf.getDirection().print();
//     tf.getOrigin().print();

//     cout << "Direction: ";
//     tForm.getDirection().print();
//     cout << "Origin: ";
//     tForm.getOrigin().print();

//     cout << "The lowest result: " << results[0].t;

//     vector<Intersection> i1 = {a1,a2};

//     vector<vector<Intersection>> w = {i1};
//     iSections.is = w;

//     cout << "The lowest intersection object has a t value of: " << val.t << '\n';



//     for (int x = 0; x < points.size(); x++){
//         cout << points[x] << '\n';
//     }


// Translating a ray
    // Sphere s1 = Sphere();
    // Ray rx = Ray(Vector(0,0,-5,1), Vector(0,0,1,0));
    // s1.setTransform(Scaling(Vector(2,2,2,1)));
    // vector<Intersection> vInters= Intersect(s1, rx);
    // cout << vInters[0].t;
    // cout << vInters[1].t;

    // Sphere s = Sphere();
    // Ray r0 = Ray(Vector(0,0,-5,1),Vector(0,0,1,0));
    // s.setTransform(Translation(Vector(5,0,0,1)));
    // vector<Intersection> vInters = Intersect(s, r0);
    // cout << vInters[0].t << '\n';
    // cout << vInters[1].t;
