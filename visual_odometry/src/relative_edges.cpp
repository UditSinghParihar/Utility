#include "graph.h"

void generate_trajectory(vector<Pose>& poses, vector<Edge>& edges,
							const Pose& initial_pose, const float noise){
	Pose current_pose_world_frame = initial_pose;
	Pose new_pose_current_frame;
	Affine3f current_frame_in_world_frame;
	initial_frame_in_world_frame(current_frame_in_world_frame);
	
	for(int i=0; i<10; ++i){
		Edge correct_edge{2, 0, 0, current_pose_world_frame.id,
							current_pose_world_frame.id+1};
		poses.push_back(current_pose_world_frame);

		if(noise == 0.0){
			new_point_in_current_frame(correct_edge, current_pose_world_frame, new_pose_current_frame);
			edges.push_back(correct_edge);
		}
		else{
			Edge noisy_edge;
			add_noise(correct_edge, noisy_edge, noise);
			new_point_in_current_frame(noisy_edge, current_pose_world_frame, new_pose_current_frame);
			edges.push_back(noisy_edge);
		}
		new_point_in_world_frame(new_pose_current_frame, current_frame_in_world_frame, 
									current_pose_world_frame);
		
		get_current_frame_in_world_frame(current_frame_in_world_frame, current_pose_world_frame); 
		++current_pose_world_frame.id;
	}

	for(int i=0; i<6; ++i){
		Edge correct_edge{2, 0, PI/6, current_pose_world_frame.id,
							current_pose_world_frame.id+1};
		poses.push_back(current_pose_world_frame);

		if(noise == 0.0){
			new_point_in_current_frame(correct_edge, current_pose_world_frame, new_pose_current_frame);
			edges.push_back(correct_edge);
		}
		else{
			Edge noisy_edge;
			add_noise(correct_edge, noisy_edge, noise);
			new_point_in_current_frame(noisy_edge, current_pose_world_frame, new_pose_current_frame);
			edges.push_back(noisy_edge);
		}		
		new_point_in_world_frame(new_pose_current_frame, current_frame_in_world_frame, 
									current_pose_world_frame);
		
		get_current_frame_in_world_frame(current_frame_in_world_frame, current_pose_world_frame); 
		++current_pose_world_frame.id;
	}

	for(int i=0; i<10; ++i){
		Edge correct_edge{2, 0, 0,current_pose_world_frame.id,
							current_pose_world_frame.id+1};
		poses.push_back(current_pose_world_frame);

		if(noise == 0.0){
			new_point_in_current_frame(correct_edge, current_pose_world_frame, new_pose_current_frame);
			edges.push_back(correct_edge);
		}
		else{
			Edge noisy_edge;
			add_noise(correct_edge, noisy_edge, noise);
			new_point_in_current_frame(noisy_edge, current_pose_world_frame, new_pose_current_frame);
			edges.push_back(noisy_edge);
		}
		new_point_in_world_frame(new_pose_current_frame, current_frame_in_world_frame, 
									current_pose_world_frame);
		
		get_current_frame_in_world_frame(current_frame_in_world_frame, current_pose_world_frame); 
		++current_pose_world_frame.id;
	}
	edges.pop_back();
}

int main(int argc, char const *argv[]){
	if(argc != 2){
		fprintf(stdout, "Usage: ./relative_edges output.g2o\n");
		return 1;
	}

	Pose initial_pose{2, 2, 0};
	vector<Pose> correct_poses;
	vector<Edge> correct_edges;
	vector<Pose> noisy_poses;
	vector<Edge> noisy_edges;

	generate_trajectory(correct_poses, correct_edges, initial_pose, 0);
	generate_trajectory(noisy_poses, noisy_edges, initial_pose, 0.3);

	add_loop_closing_edges(correct_poses, noisy_edges);
	print_graph(noisy_poses, noisy_edges);
	plot_graph(correct_poses);
	plot_graph(noisy_poses);
	write_g2o_file(noisy_poses, noisy_edges, argv[1]);
	return 0;
}