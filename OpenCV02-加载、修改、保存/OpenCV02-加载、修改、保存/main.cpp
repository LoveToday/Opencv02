//
//  main.cpp
//  OpenCV02-加载、修改、保存
//
//  Created by 陈江林 on 2019/9/8.
//  Copyright © 2019 陈江林. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
using namespace std;
using namespace cv;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    // 加载图片
    // imread 功能是加载图像文件称为一个Mat对象，其中第一个参数表示文件名称
    // 第二个参数表示加载的图像是什么类型支持常见的三个参数
    // 1. IMREAD_UNCHANGED(<0)表示加载原图，不做任何改变
    // 2. IMREAD_GRAYSCALE(0)表示把原图作为灰度图加载
    // 3. IMREAD_COLOR(>0)表示吧原图作为RGB图像加载进来
    // Opencv支持JPG PNG TIFF 等常见的格式图片格式
    string imagePath = "/Users/chenjianglin/Documents/C++/OpenCV02/OpenCV02-加载、修改、保存/OpenCV02-加载、修改、保存/tupian.jpg";
    Mat image = imread(imagePath, IMREAD_UNCHANGED);
//    Mat image = imread(imagePath, IMREAD_GRAYSCALE);
//    Mat image = imread(imagePath, IMREAD_COLOR);
    if (image.empty()) {
        cout << "图片地址错误或是加载失败";
        return -1;
    }
    string window = "opencv-window";
    // WINDOW_AUTOSIZE 不能人为改变窗口大小
    // WINDOW_NORMAL可以改变窗口大小
    // 高版本自动释放
    namedWindow(window, WINDOW_AUTOSIZE);
    imshow(window, image);
    
    Mat out_image;
    // 修改image 以灰度显示出来 改变了颜色通道
    cvtColor(image, out_image, COLOR_BGR2GRAY);
    
    string window2 = "opencv-window02";
    namedWindow(window2);
    imshow(window2, out_image);
    
    //保存图像
    string saveSource = "/Users/chenjianglin/Documents/C++/OpenCV02/OpenCV02-加载、修改、保存/Source";
    // imwrite 保存的图片的格式跟 图片的名字的扩展保持一致
    imwrite(saveSource + "/gray.png", out_image);
    
    waitKey(0);
    return 0;
}
