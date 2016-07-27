#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>

int
 main (int argc, char** argv)
{
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_in (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_out (new pcl::PointCloud<pcl::PointXYZ>);

  // Fill in the CloudIn data
  cloud_in->width    = 5;
  cloud_in->height   = 1;
  cloud_in->is_dense = false;
  cloud_in->points.resize (cloud_in->width * cloud_in->height);
/*
  for (size_t i = 0; i < cloud_in->points.size (); ++i)
  {
    cloud_in->points[i].x = 1024 * rand () / (RAND_MAX + 1.0f);
    cloud_in->points[i].y = 1024 * rand () / (RAND_MAX + 1.0f);
    cloud_in->points[i].z = 1024 * rand () / (RAND_MAX + 1.0f);
  }
*/
  cloud_out->width    = 5;
  cloud_out->height   = 1;
  cloud_out->is_dense = false;
  cloud_out->points.resize (cloud_out->width * cloud_out->height);

//////data sound-in face_out normalized vectors

size_t iz=0;
cloud_in->points[iz].x =-0.92742;
cloud_in->points[iz].y =-0.315679;
cloud_in->points[iz].z =-0.20060;
cloud_out->points[iz].x =0.99433;
cloud_out->points[iz].y =0.089472;
cloud_out->points[iz].z =-0.057422;
iz++;
cloud_in->points[iz].x =-0.97877;
cloud_in->points[iz].y =-0.083598;
cloud_in->points[iz].z =-0.18715;
cloud_out->points[iz].x =0.99488;
cloud_out->points[iz].y =-0.061463;
cloud_out->points[iz].z =-0.080169;
iz++;
cloud_in->points[iz].x =-0.97986;
cloud_in->points[iz].y =0.102197;
cloud_in->points[iz].z =-0.17155;
cloud_out->points[iz].x =0.96418;
cloud_out->points[iz].y =-0.247328;
cloud_out->points[iz].z =-0.095823;
iz++;
cloud_in->points[iz].x =-0.92848;
cloud_in->points[iz].y =0.295677;
cloud_in->points[iz].z =-0.22470;
cloud_out->points[iz].x =0.87694;
cloud_out->points[iz].y =-0.478164;
cloud_out->points[iz].z =-0.048288;
iz++;
cloud_in->points[iz].x =-0.99064;
cloud_in->points[iz].y =-0.057046;
cloud_in->points[iz].z =0.12401;
cloud_out->points[iz].x =0.89916;
cloud_out->points[iz].y =-0.020529;
cloud_out->points[iz].z =-0.437144;
iz++;

//////
  std::cout << "Saved " << cloud_in->points.size () << " data points to input:"
      << std::endl;
  for (size_t i = 0; i < cloud_in->points.size (); ++i) std::cout << "    " <<
      cloud_in->points[i].x << " " << cloud_in->points[i].y << " " <<
      cloud_in->points[i].z << std::endl;
//  *cloud_out = *cloud_in;
  std::cout << "size:" << cloud_out->points.size() << std::endl;
/*
  for (size_t i = 0; i < cloud_in->points.size (); ++i)
    cloud_out->points[i].x = cloud_in->points[i].x + 0.7f;
  std::cout << "Transformed " << cloud_in->points.size () << " data points:"
      << std::endl;
*/
  for (size_t i = 0; i < cloud_out->points.size (); ++i)
    std::cout << "    " << cloud_out->points[i].x << " " <<
      cloud_out->points[i].y << " " << cloud_out->points[i].z << std::endl;
  pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
  icp.setInputCloud(cloud_in);
  icp.setInputTarget(cloud_out);
  pcl::PointCloud<pcl::PointXYZ> Final;
  icp.align(Final);
  std::cout << "has converged:" << icp.hasConverged() << " score: " <<
  icp.getFitnessScore() << std::endl;
  std::cout << icp.getFinalTransformation() << std::endl;

 return (0);
}

/*
Saved 5 data points to input:
    -0.92742 -0.315679 -0.2006
    -0.97877 -0.083598 -0.18715
    -0.97986 0.102197 -0.17155
    -0.92848 0.295677 -0.2247
    -0.99064 -0.057046 0.12401
size:5
    0.99433 0.089472 -0.057422
    0.99488 -0.061463 -0.080169
    0.96418 -0.247328 -0.095823
    0.87694 -0.478164 -0.048288
    0.89916 -0.020529 -0.437144

has converged:1 score: 0.00970005
 -0.978733 -0.0245197   0.203665  0.0128649
  0.121826   0.729311   0.673252  0.0488694
  0.165042  -0.683746   0.710813  0.0247305
         0          0          0          1

*/
