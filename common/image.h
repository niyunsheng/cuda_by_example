#ifndef __IMAGE__
#define __IMAGE__

#include <iostream>
using namespace std;

#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;

class IMAGE
{
public:
    Mat image;

    IMAGE( int w, int h) 
    {
        image = Mat::zeros(w,h,CV_8UC4);
        // imwrite("ori.jpg",image);
    }


    unsigned char* get_ptr( void ) const   
    { 
        return (unsigned char*)image.data; 
    }

    long image_size( void ) const 
    { 
		return image.cols * image.rows * 4; 
    }


    void save_image(int frame_id=0)
    {
        char a[10]="000.jpg";
        a[0] = a[0] + frame_id/100;
        a[1] = a[1] + (frame_id/10)%10;
        a[2] = a[2] + frame_id%10;
        imwrite(a,image);
        return;
    }

};



#endif  // __IMAGE__

