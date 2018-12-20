## Description ##

1. **src/relative_edges.cpp** : It can be used to generate artifical odometry in global frame and odometry/loop closing edges for graph slam in local frame to be used by g2o optimizer. 
	1. *Usage*: `./relative_edges binary_noise[0/1] output.g2o`

2. **Packages used** : 
	1. *[matplotlibcpp](https://github.com/lava/matplotlib-cpp)*: It is used as plotting library in c++. Basicaly it is a c++ wrapper of matplotlib.
	2. *[g2o](https://github.com/RainerKuemmerle/g2o)*: Graph optimization library based on spatial constraints(edges).
	3. *[Eigen](https://eigen.tuxfamily.org/dox/GettingStarted.html)*: Linear algebra library in c++.