## Description ##

1. **src/relative_edges.cpp** : It can be used to generate artifical odometry in global frame and odometry/loop closing edges for graph slam in local(or relative) frame to be used by g2o optimizer. 
	1. *Usage*: `./relative_edges binary_noise[0/1] output.g2o`
	2. *Example(without noise)*: `./relative_edges 0 ~/Desktop/output.g2o`
	3. *[Sample Results](https://docs.google.com/document/d/184T_EzZ0WNf-sPdoBy972vT6ftdLsvyvUiQUbh6G6yE/edit)*

2. **Packages used** : 
	1. *[matplotlibcpp](https://github.com/lava/matplotlib-cpp)*: C++ wrapper of matplotlib.
	2. *[g2o](https://github.com/RainerKuemmerle/g2o)*: Graph optimization library based on spatial constraints(edges).
	3. *[Eigen](https://eigen.tuxfamily.org/dox/GettingStarted.html)*: Linear algebra library in C++.