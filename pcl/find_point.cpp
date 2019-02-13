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

void blue_colorization(PointCloudT::Ptr cloud){
	for(size_t index=0; index<cloud->points.size(); ++index){
		cloud->points[index].r = 20;
		cloud->points[index].g = 20;
		cloud->points[index].b = 230;
	}
}

void simple_visualize(const PointCloudT::Ptr cloud){
	pcl::visualization::PCLVisualizer viewer("Normal_cloud");
	pcl::visualization::PointCloudColorHandlerRGBField<PointT> rgb(cloud);
	viewer.addPointCloud<PointT>(cloud, rgb, "cloud_points");
	viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE,
												3, "cloud_points");
	viewer.setBackgroundColor (220, 220, 220);
	while(! viewer.wasStopped())
		viewer.spinOnce();
}

void simple_visualize(const PointCloudT::Ptr cloud, const vector<int>& indices){
	pcl::visualization::PCLVisualizer viewer("Cloud_with_quadrilateral");
	pcl::visualization::PointCloudColorHandlerRGBField<PointT> rgb(cloud);
	viewer.addPointCloud<PointT>(cloud, rgb, "cloud_points");
	viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE,
												3, "cloud_points");
	viewer.setBackgroundColor (220, 220, 220);

	viewer.addLine(cloud->points[indices[0]], cloud->points[indices[1]], 255, 0, 0, "line1");
	viewer.addLine(cloud->points[indices[1]], cloud->points[indices[2]], 255, 0, 0, "line2");
	viewer.addLine(cloud->points[indices[2]], cloud->points[indices[3]], 255, 0, 0, "line3");
	viewer.addLine(cloud->points[indices[3]], cloud->points[indices[0]], 255, 0, 0, "line4");

	viewer.addSphere(cloud->points[indices[0]], 0.1, 255, 0, 0, "shphere1");
	viewer.addSphere(cloud->points[indices[1]], 0.1, 255, 0, 0, "shphere2");
	viewer.addSphere(cloud->points[indices[2]], 0.1, 255, 0, 0, "shphere3");
	viewer.addSphere(cloud->points[indices[3]], 0.1, 255, 0, 0, "shphere4");

	while(! viewer.wasStopped())
		viewer.spinOnce();
}

void fill_base_points(vector<Point3D>& base_points){
	// base_points.push_back(Point3D{-5.70759, 15.0452, -2.73189});
	// base_points.push_back(Point3D{-7.60092, 15.6629, -1.31274});
	// base_points.push_back(Point3D{-7.62833, 15.617, -2.64937});
	// base_points.push_back(Point3D{-1.16865, 15.0312, -0.736361});

	base_points.push_back(Point3D{-6.02769, 16.0724, -5.90009});
	base_points.push_back(Point3D{-6.48369, 16.4077, -5.28741});
	base_points.push_back(Point3D{-6.1264, 16.1918, -5.95713});
	base_points.push_back(Point3D{-5.95571, 16.4025, -6.48623});
}

void mark_red(PointCloudT::Ptr cloud, int index){
	cloud->points[index].r = 230;
	cloud->points[index].g = 0;
	cloud->points[index].b = 0;
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

	mark_red(cloud, min_index);

	return min_index;
}

int main(int argc, char const *argv[]){
	if(argc !=2){
		fprintf(stdout, "Usage: %s file.pcd\n", argv[0]);
		return 1;
	}

	PointCloudT::Ptr cloud(new PointCloudT);
	io::loadPCDFile<PointT> (argv[1], *cloud);
	
	blue_colorization(cloud);
	simple_visualize(cloud);
		
	vector<Point3D> base_points;
	fill_base_points(base_points);

	vector<int> quad_indices;
	for(Point3D point : base_points){
		int index = get_nearest_point(point, cloud);
		quad_indices.push_back(index);		
	}

	simple_visualize(cloud, quad_indices);

	return 0;
}