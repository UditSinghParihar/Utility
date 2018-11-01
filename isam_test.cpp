#include <isam/isam.h>

using namespace std;
using namespace isam;
using namespace Eigen;

int main(int argc, char const *argv[]){
	Slam slam;
	vector<Pose2d_Node*> poses;
	Noise odom_noise = Information(100.0 * eye(3));
	Noise landmark_noise = Information(100.0 * eye(2));

	Pose2d_Node* new_node = new Pose2d_Node();
	slam.add_node(new_node);
	poses.push_back(new_node);

	Pose2d origin(0., 0., 0.);
	Pose2d_Factor* prior_constraint = new Pose2d_Factor(poses[0], origin, odom_noise);
	slam.add_factor(prior_constraint);

	for (int i = 1; i < 10; ++i){
		Pose2d_Node* new_node = new Pose2d_Node();
		slam.add_node(new_node);
		poses.push_back(new_node);

		Pose2d odom_transform(1.5,0., 0.);
		Pose2d_Pose2d_Factor* odom_constraint = new Pose2d_Pose2d_Factor(poses[i-1],poses[i],odom_transform,odom_noise);
		slam.add_factor(odom_constraint);	
	}

	Point2d_Node* landmark = new Point2d_Node();
	slam.add_node(landmark);
	Point2d coordinate(5., 3.);
	Pose2d_Point2d_Factor* measurement = new Pose2d_Point2d_Factor(poses[3], landmark, coordinate, landmark_noise);
	slam.add_factor(measurement);

	slam.batch_optimization();
	cout << "\nFull graph\n";
	slam.write(cout);
	return 0;
}