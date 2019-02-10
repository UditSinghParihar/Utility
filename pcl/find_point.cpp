#include <iostream>
#include <vector>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <limits>
#include <cmath>

using namespace std;
using namespace pcl;

typedef pcl::PointXYZRGB PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

struct Point3D{
	float x;
	float y;
	float z;

	Point3D(float arg_x, float arg_y, float arg_z): x{arg_x}, y{arg_y}, z{arg_z}{}

	friend ostream& operator<<(ostream& out, const Point3D& point){
		out << "x: " << point.x << "\ty: " << point.y << "\tz: " << point.z << "\n--\n";
	}
};

void red_colorization(PointCloudT::Ptr cloud){
	for(size_t index=0; index<cloud->points.size(); ++index){
		cloud->points[index].r = 230;
		cloud->points[index].g = 20;
		cloud->points[index].b = 20;
	}
}

void simple_visualize(const PointCloudT::Ptr cloud){
	pcl::visualization::PCLVisualizer viewer("Reddening");
	pcl::visualization::PointCloudColorHandlerRGBField<PointT> rgb(cloud);
	viewer.addPointCloud<PointT>(cloud, rgb, "cloud_points");
	while(! viewer.wasStopped())
		viewer.spinOnce();
}

void fill_base_points(vector<Point3D>& base_points){
	base_points.push_back(Point3D{-6.17246, -10.3393, -1.76436});
	base_points.push_back(Point3D{-3.31098, 17.6496, 9.53353});
	base_points.push_back(Point3D{7.49274, 8.01208, -7.62501});
	base_points.push_back(Point3D{-4.84244, 3.2643, 4.08124});
}

float get_distance(const PointT& point, const Point3D& base_point){
	float sum_of_squares = pow(point.x - base_point.x, 2) + 
							pow(point.y - base_point.y, 2) + 
							pow(point.z - base_point.z, 2);

	return pow(sum_of_squares, 0.5);
}

int get_nearest_point(const Point3D& base_point, PointCloudT::Ptr cloud){
	float min_distance = std::numeric_limits<float>::max();
	int min_index = 0;

	for(int i=0; i<cloud->points.size(); ++i){
		float distance = get_distance(cloud->points[i], base_point);
		if(distance < min_distance){
			min_distance = distance;
			min_index = i;
		}
	}

	cout << "Corresponding point for:" << base_point << "is:\nx: " << 
			cloud->points[min_index].x << "\ty: " << cloud->points[min_index].y << 
			"\tz: " << cloud->points[min_index].z << "\nwith distance = \n" <<
			min_distance << endl;

	return min_index;
}

int main(int argc, char const *argv[]){
	if(argc !=2){
		fprintf(stdout, "Usage: %s file.pcd\n", argv[0]);
		return 1;
	}

	PointCloudT::Ptr cloud(new PointCloudT);
	io::loadPCDFile<PointT> (argv[1], *cloud);
	
	red_colorization(cloud);
	simple_visualize(cloud);
		
	vector<Point3D> base_points;
	fill_base_points(base_points);

	for(Point3D point : base_points){
		int index = get_nearest_point(point, cloud);		
	}

	return 0;
}