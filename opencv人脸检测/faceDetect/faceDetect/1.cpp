//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/core/core.hpp>
//#include <opencv2/objdetect/objdetect.hpp>
//#include <Windows.h>
//
//using namespace cv;
//
//void detectAndDraw(Mat& img, CascadeClassifier& cascade, CascadeClassifier& nestedCascade, double scale, bool tryflip);
//
//int main()
//{
//   VideoCapture cap(0);   //打开默认摄像头
//   if(!cap.isOpened())
//	   return -1;
//
//   Mat frame;
//   Mat edges;
//
//   CascadeClassifier cascade, nestedCascade;
//   bool stop = false;
//
//   //训练好的文件名称，放置在可执行文件同目录下
//   cascade.load("haarcascade_frontalface_alt.xml");
//   nestedCascade.load("D:\\Program Files (x86)\\opencv\\sources\\data\\haarcascades\\haarcascade_eye.xml");
//  // nestedCascade.load("haarcascade_eye_tree_eyeglasses.xml");
//   Sleep(1000);
//   while(!stop)
//   {
//	 cap>>frame;
//	 if(frame.empty())
//		 break;
//	 detectAndDraw(frame, cascade, nestedCascade, 2, 0);
//	 if(waitKey(30) >= 0)
//		 stop = true;
//   }
//   return 0;
//}
//
//void detectAndDraw(Mat& img, CascadeClassifier& cascade, CascadeClassifier& nestedCascade, double scale, bool tryflip)
//{
//	int i = 0;
//	double t = 0;
//	vector<Rect> faces, faces2;  //建立用于存放人脸的向量容器
//	const static Scalar colors[] = {CV_RGB(0, 0, 255),       //定义一些颜色，用来标示不同的人脸
//	                                CV_RGB(0, 128, 255),
//	                                CV_RGB(0, 255, 255),
//	                                CV_RGB(0, 255, 0),
//	                                CV_RGB(255, 128, 0),
//	                                CV_RGB(255, 255, 0),
//	                                CV_RGB(255, 0, 0),
//	                                CV_RGB(255, 0, 255)};
//	//建立缩小的图片，加快检测速度
//	//nt cvRound(double value) 对一个double型的数进行四舍五入，并返回一个整型数
//	Mat gray, smallImg(cvRound(img.rows/scale), cvRound(img.cols/scale), CV_8UC1);
//	cvtColor(img, gray, CV_BGR2GRAY);  //转成灰度图像，Harr特征基于灰度图
//	resize(gray, smallImg, smallImg.size(), 0, 0, INTER_LINEAR);  //改变图像大小，使用双线性差值
//	equalizeHist(smallImg, smallImg);  //变换后的图像进行直方图均值化处理
//
//	t = (double)cvGetTickCount();   //程序开始和结束插入此函数获取时间，经过计算求得算法执行时间
//	//检测人脸
//	//detectMultiScale函数中smallImg表示的是要检测的输入图像为smallImg，faces表示检测到的人脸目标序列，
//	// 1.1表示每次图像尺寸减小的比例为1.1， 2表示每一个目标至少要被检测到3次才算是真的目标（因为周围
//	//的像素和不同窗口大小都可以检测到人脸），CV_HAAR_SCALE_IMAGE表示不是缩放分类器来检测，而是缩放图像，
//	//Size(30, 30)为目标的最小最大尺寸
//	cascade.detectMultiScale(smallImg, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE,Size(30, 30));
//	if(tryflip)  //如果使能，翻转图像继续检测
//	{
//		flip(smallImg, smallImg, 1);
//		cascade.detectMultiScale(smallImg, faces2, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30));
//		for(vector<Rect>::const_iterator r=faces2.begin(); r != faces2.end(); r++)
//		{
//			faces.push_back(Rect(smallImg.cols - r->x - r->width, r->y, r->width, r->height));
//		}
//	}
//	t = (double)cvGetTickCount() - t;
//	for(vector<Rect>::const_iterator r = faces.begin(); r != faces.end(); r++, i++)
//	{
//		Mat smallImgROI;
//		vector<Rect> nestedObjects;
//		Point center;
//		Scalar color = colors[i%8];
//		int radius;
//
//		double aspect_ratio = (double)r->width / r->height;
//		if( 0.75 < aspect_ratio && aspect_ratio < 1.3)
//		{
//		   //标示人脸在缩小之前的图像上标示，所以这里根据缩放比例换算回去
//			center.x = cvRound((r->x + r->width * 0.5)*scale);
//			center.y = cvRound((r->y + r->height * 0.5)*scale);
//			radius = cvRound((r->width + r->height)*0.25*scale);
//			circle(img, center, radius, color, 3, 8, 0);
//		}
//		else
//			rectangle(img, cvPoint(cvRound(r->x * scale), cvRound(r->y * scale)),
//			cvPoint(cvRound((r->x + r->width  - 1)*scale), cvRound((r->y + r->height - 1)*scale)),
//			color, 3, 8, 0);
//
//		if(nestedCascade.empty())
//			continue;
//
//		smallImgROI = smallImg(*r);
//		nestedCascade.detectMultiScale(smallImgROI, nestedObjects, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30));
//		for(vector<Rect>::const_iterator nr = nestedObjects.begin(); nr !=nestedObjects.end(); nr++)
//		{
//			center.x = cvRound((r->x + nr->x + nr->width * 0.5)*scale);
//			center.y = cvRound((r->y + nr->y + nr->height * 0.5)*scale);
//			radius = cvRound((nr->width + nr->height)*0.25*scale);
//			circle(img, center, radius, color, 3, 8, 0);
//		}
//
//	}
//	imshow("result", img);
//}

/*
   支持向量机（线性可分）
*/
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/ml/ml.hpp>
//
//using namespace cv;
//
//int main()
//{
//	int width = 512, height = 512;
//	Mat image = Mat::zeros(width, height, CV_8UC3);
//	float labels[5] = {1.0, -1.0, -1.0, -1.0, 1.0};
//	Mat labelsMat(5, 1, CV_32FC1, labels);
//	float trainingData[5][2] = { {501, 10}, {255, 10}, {501, 255}, {10, 501}, {501, 128} };
//	Mat trainingDataMat(5, 2, CV_32FC1, trainingData);
//	CvSVMParams params;
//	params.svm_type = CvSVM::C_SVC;
//	params.kernel_type = CvSVM::LINEAR;
//	params.term_crit = cvTermCriteria(CV_TERMCRIT_ITER, 100, 1e-6);  //第二第三个参数：最大迭代次数、精度
//	CvSVM SVM;
//	SVM.train(trainingDataMat, labelsMat, Mat(), Mat(), params);
//	Vec3b green(0, 255, 0), blue(255, 0, 0);
//	for(int i=0; i<image.rows; ++i)
//		for(int j=0; j<image.cols; ++j)
//		{
//			Mat sampleMat = (Mat_<float>(1, 2)<<i, j);
//			float response = SVM.predict(sampleMat);
//
//			if(response == 1)
//				image.at<Vec3b>(j, i) = green;
//			else if(response == -1)
//				image.at<Vec3b>(j, i) = blue;
//		}
//
//	int thickness = -1;
//	int lineType = 8;
//	circle(image, Point(501, 10), 5, Scalar(0, 0, 0), thickness, lineType); 
//	circle(image, Point(255, 10), 5, Scalar(255, 255, 255), thickness, lineType);
//	circle(image, Point(501, 255), 5, Scalar(255, 255, 255), thickness, lineType);
//	circle(image, Point(10, 501), 5, Scalar(255, 255, 255), thickness, lineType);
//	circle(image, Point(501, 128), 5, Scalar(0, 0, 0), thickness, lineType);
//	thickness = 2;
//	lineType = 8;
//	int c = SVM.get_support_vector_count();
//	for(int i=0; i<c; ++i)
//	{
//		const float* v = SVM.get_support_vector(i);
//		circle(image, Point((int)v[0], (int)v[1]), 6, Scalar(128, 128, 128), thickness, lineType);
//	}
//	imshow("SVM Simple Example", image);
//	waitKey(0);
//	return 0;
//}


/*
	支持向量机（线性不可分）
*/
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/ml/ml.hpp>
#include <time.h>

using namespace std;
using namespace cv;

/*程序说明：
一共两个样本集，每个样本集有100个样本，其中90个是线性可分的，10个是线性不可分
这200个样本数据存储在trainData内：trainData是一个200行2列的矩阵，其中第一列存储样本的x值，
第二列存储样本的y值，每一个列的前90个元素是第一类的线性可分部分，后90个元素是线性可分部分，
中间20个元素是线性不可分部分
第一类样本的x值分布在整幅图像的[0, 0.4]范围内，第二类样本的x值分布在整幅图像的[0.6, 1]范围内，
中间的[0.4, 0.6]是线性不可分的部分，这三部分y值都在整幅图像的高度内自由分布
*/

#define NTRAINING_SAMPLES 100  //每个样本的数量

#define FRAC_LINEAR_SEP 0.9f  //其中线性部分

int main()
{
	const int WIDTH = 512, HEIGHT = 512;
	Mat image = Mat::zeros(WIDTH, HEIGHT, CV_8UC3);  //定义显示结果的图像

	//第一步：设定训练数据
	//1.设定数据结构
	Mat trainData(2*NTRAINING_SAMPLES, 2, CV_32FC1);	//承载训练数据的结构
	Mat labels(2*NTRAINING_SAMPLES, 1, CV_32FC1);   //承载这些数据分类的结构
	RNG rng(100);   //设定随机数种子
	int nLinearSamples = (int)(NTRAINING_SAMPLES * FRAC_LINEAR_SEP); //设定线性可分部分的数据量


	//2.设定第一类中的数据
	//从这个数据集中取出前[0, 89]行   *Range的范围是[a, b)
	Mat trainClass = trainData.rowRange(0, nLinearSamples);
	Mat c = trainClass.colRange(0, 1);   //取出第一列
	rng.fill(c, RNG::UNIFORM, Scalar(1), Scalar(0.4 * WIDTH));   //随机生成x的值：[0, 0.4*WIDTH]
	c = trainClass.colRange(1, 2);  //取出第二列
	rng.fill(c, RNG::UNIFORM, Scalar(1), Scalar(HEIGHT));   //随机生成y的值

	//设定第二类的数据
	//从整个数据总取出[110, 199]行
	trainClass = trainData.rowRange(2*NTRAINING_SAMPLES - nLinearSamples, 2 * NTRAINING_SAMPLES);
	c = trainClass.colRange(0, 1);   //取出第一列
	rng.fill(c, RNG::UNIFORM, Scalar(0.6*WIDTH), Scalar(WIDTH));   //随机生成x的值[0.6*WIDTH, WIDTH]
	c = trainClass.colRange(1, 2);   //取出第二列
	rng.fill(c, RNG::UNIFORM, Scalar(1), Scalar(HEIGHT));  //随机生成y的值


	//设定线性不可分的数据
	//取出[90, 109]行
	trainClass = trainData.rowRange(nLinearSamples, 2*NTRAINING_SAMPLES - nLinearSamples);
	c = trainClass.colRange(0, 1);  //取出第一列
	rng.fill(c, RNG::UNIFORM, Scalar(0.4*WIDTH), Scalar(0.6*WIDTH));   //随机生成x的值[0.4*WIDTH, 0.6*WIDTH]
	c = trainClass.colRange(1, 2);  //取出第二列
	rng.fill(c, RNG::UNIFORM, Scalar(1), Scalar(HEIGHT));  //随机生成y的值


	//4.为所有数据设置标签
	labels.rowRange(0, NTRAINING_SAMPLES).setTo(1);  //前100个数据设为第一类
	labels.rowRange(NTRAINING_SAMPLES, 2*NTRAINING_SAMPLES).setTo(2);  //后100个数据设为第二关

	//第二步：设置SVM参数
	CvSVMParams params;
	params.svm_type = SVM::C_SVC;   //SVM 类型: C-Support Vector Classification
	params.C = 0.1;
	params.kernel_type = SVM::LINEAR;   //和函数类型：Linear kernel
	params.term_crit = TermCriteria(CV_TERMCRIT_ITER, (int)1e7, 1e-6);  //终止准则：当迭代次数达到最大值后终止
	

	//第三步：训练SVM
	cout<<"开始训练过程"<<endl;
	clock_t start, finish;  
	double duration;
	start = clock();   //开始计时
	CvSVM svm;  //建立一个SVM实例
	svm.train(trainData, labels, Mat(), Mat(), params);
	finish = clock(); //结束计时
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout<<"训练过程结束， 共耗时："<<duration<<"秒"<<endl;


	//第四步：显示判决域
	//第一类用绿色， 第二类用蓝色
	Vec3b green(0, 100, 0), blue(100, 0, 0);
	for(int i=0; i<image.rows; ++i)
		for(int j=0; j<image.cols; ++j)
		{
			Mat sampleMat = (Mat_<float>(1, 2)<<i, j);
			float response = svm.predict(sampleMat);
			if(response == 1)
				image.at<Vec3b>(j, i) = green;
			else if(response == 2)
				image.at<Vec3b>(j, i) = blue;
		}

	
	//第五步：显示训练数据
	//红色
	//负数会导致画出的图形是实心的
	int thick = -1;
	int lineType = 8;
	float px, py;
	// 1. 第一类
	for(int i=0; i<NTRAINING_SAMPLES; ++i)
	{
		px = trainData.at<float>(i, 0);
		py = trainData.at<float>(i, 1);
		circle(image, Point((int)px, (int)py), 3, Scalar(0, 255, 0));
	}

	//2. 第二类
	for(int i=NTRAINING_SAMPLES; i<2*NTRAINING_SAMPLES; ++i)
	{
		px = trainData.at<float>(i, 0);
		py = trainData.at<float>(i, 1);
		circle(image, Point((int)px, (int)py), 3, Scalar(255, 0, 0));
	}

	//第六步：显示支持向量
	thick = 2;
	lineType = 8;
	int x = svm.get_support_vector_count();  //获取支持向量的个数
	for(int i=0; i< x; ++i)
	{
		const float* v = svm.get_support_vector(i);
		circle(image, Point((int)v[0], (int)v[1]), 6, Scalar(128, 128, 128), thick, lineType);
	}
	imshow("分类结果", image);
	waitKey(0);
	return 0;
}

