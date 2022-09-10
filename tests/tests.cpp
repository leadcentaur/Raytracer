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
