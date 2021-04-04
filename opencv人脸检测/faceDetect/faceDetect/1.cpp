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
//   VideoCapture cap(0);   //��Ĭ������ͷ
//   if(!cap.isOpened())
//	   return -1;
//
//   Mat frame;
//   Mat edges;
//
//   CascadeClassifier cascade, nestedCascade;
//   bool stop = false;
//
//   //ѵ���õ��ļ����ƣ������ڿ�ִ���ļ�ͬĿ¼��
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
//	vector<Rect> faces, faces2;  //�������ڴ����������������
//	const static Scalar colors[] = {CV_RGB(0, 0, 255),       //����һЩ��ɫ��������ʾ��ͬ������
//	                                CV_RGB(0, 128, 255),
//	                                CV_RGB(0, 255, 255),
//	                                CV_RGB(0, 255, 0),
//	                                CV_RGB(255, 128, 0),
//	                                CV_RGB(255, 255, 0),
//	                                CV_RGB(255, 0, 0),
//	                                CV_RGB(255, 0, 255)};
//	//������С��ͼƬ���ӿ����ٶ�
//	//nt cvRound(double value) ��һ��double�͵��������������룬������һ��������
//	Mat gray, smallImg(cvRound(img.rows/scale), cvRound(img.cols/scale), CV_8UC1);
//	cvtColor(img, gray, CV_BGR2GRAY);  //ת�ɻҶ�ͼ��Harr�������ڻҶ�ͼ
//	resize(gray, smallImg, smallImg.size(), 0, 0, INTER_LINEAR);  //�ı�ͼ���С��ʹ��˫���Բ�ֵ
//	equalizeHist(smallImg, smallImg);  //�任���ͼ�����ֱ��ͼ��ֵ������
//
//	t = (double)cvGetTickCount();   //����ʼ�ͽ�������˺�����ȡʱ�䣬������������㷨ִ��ʱ��
//	//�������
//	//detectMultiScale������smallImg��ʾ����Ҫ��������ͼ��ΪsmallImg��faces��ʾ��⵽������Ŀ�����У�
//	// 1.1��ʾÿ��ͼ��ߴ��С�ı���Ϊ1.1�� 2��ʾÿһ��Ŀ������Ҫ����⵽3�β��������Ŀ�꣨��Ϊ��Χ
//	//�����غͲ�ͬ���ڴ�С�����Լ�⵽��������CV_HAAR_SCALE_IMAGE��ʾ�������ŷ���������⣬��������ͼ��
//	//Size(30, 30)ΪĿ�����С���ߴ�
//	cascade.detectMultiScale(smallImg, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE,Size(30, 30));
//	if(tryflip)  //���ʹ�ܣ���תͼ��������
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
//		   //��ʾ��������С֮ǰ��ͼ���ϱ�ʾ����������������ű��������ȥ
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
   ֧�������������Կɷ֣�
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
//	params.term_crit = cvTermCriteria(CV_TERMCRIT_ITER, 100, 1e-6);  //�ڶ�����������������������������
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
	֧�������������Բ��ɷ֣�
*/
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/ml/ml.hpp>
#include <time.h>

using namespace std;
using namespace cv;

/*����˵����
һ��������������ÿ����������100������������90�������Կɷֵģ�10�������Բ��ɷ�
��200���������ݴ洢��trainData�ڣ�trainData��һ��200��2�еľ������е�һ�д洢������xֵ��
�ڶ��д洢������yֵ��ÿһ���е�ǰ90��Ԫ���ǵ�һ������Կɷֲ��֣���90��Ԫ�������Կɷֲ��֣�
�м�20��Ԫ�������Բ��ɷֲ���
��һ��������xֵ�ֲ�������ͼ���[0, 0.4]��Χ�ڣ��ڶ���������xֵ�ֲ�������ͼ���[0.6, 1]��Χ�ڣ�
�м��[0.4, 0.6]�����Բ��ɷֵĲ��֣���������yֵ��������ͼ��ĸ߶������ɷֲ�
*/

#define NTRAINING_SAMPLES 100  //ÿ������������

#define FRAC_LINEAR_SEP 0.9f  //�������Բ���

int main()
{
	const int WIDTH = 512, HEIGHT = 512;
	Mat image = Mat::zeros(WIDTH, HEIGHT, CV_8UC3);  //������ʾ�����ͼ��

	//��һ�����趨ѵ������
	//1.�趨���ݽṹ
	Mat trainData(2*NTRAINING_SAMPLES, 2, CV_32FC1);	//����ѵ�����ݵĽṹ
	Mat labels(2*NTRAINING_SAMPLES, 1, CV_32FC1);   //������Щ���ݷ���Ľṹ
	RNG rng(100);   //�趨���������
	int nLinearSamples = (int)(NTRAINING_SAMPLES * FRAC_LINEAR_SEP); //�趨���Կɷֲ��ֵ�������


	//2.�趨��һ���е�����
	//��������ݼ���ȡ��ǰ[0, 89]��   *Range�ķ�Χ��[a, b)
	Mat trainClass = trainData.rowRange(0, nLinearSamples);
	Mat c = trainClass.colRange(0, 1);   //ȡ����һ��
	rng.fill(c, RNG::UNIFORM, Scalar(1), Scalar(0.4 * WIDTH));   //�������x��ֵ��[0, 0.4*WIDTH]
	c = trainClass.colRange(1, 2);  //ȡ���ڶ���
	rng.fill(c, RNG::UNIFORM, Scalar(1), Scalar(HEIGHT));   //�������y��ֵ

	//�趨�ڶ��������
	//������������ȡ��[110, 199]��
	trainClass = trainData.rowRange(2*NTRAINING_SAMPLES - nLinearSamples, 2 * NTRAINING_SAMPLES);
	c = trainClass.colRange(0, 1);   //ȡ����һ��
	rng.fill(c, RNG::UNIFORM, Scalar(0.6*WIDTH), Scalar(WIDTH));   //�������x��ֵ[0.6*WIDTH, WIDTH]
	c = trainClass.colRange(1, 2);   //ȡ���ڶ���
	rng.fill(c, RNG::UNIFORM, Scalar(1), Scalar(HEIGHT));  //�������y��ֵ


	//�趨���Բ��ɷֵ�����
	//ȡ��[90, 109]��
	trainClass = trainData.rowRange(nLinearSamples, 2*NTRAINING_SAMPLES - nLinearSamples);
	c = trainClass.colRange(0, 1);  //ȡ����һ��
	rng.fill(c, RNG::UNIFORM, Scalar(0.4*WIDTH), Scalar(0.6*WIDTH));   //�������x��ֵ[0.4*WIDTH, 0.6*WIDTH]
	c = trainClass.colRange(1, 2);  //ȡ���ڶ���
	rng.fill(c, RNG::UNIFORM, Scalar(1), Scalar(HEIGHT));  //�������y��ֵ


	//4.Ϊ�����������ñ�ǩ
	labels.rowRange(0, NTRAINING_SAMPLES).setTo(1);  //ǰ100��������Ϊ��һ��
	labels.rowRange(NTRAINING_SAMPLES, 2*NTRAINING_SAMPLES).setTo(2);  //��100��������Ϊ�ڶ���

	//�ڶ���������SVM����
	CvSVMParams params;
	params.svm_type = SVM::C_SVC;   //SVM ����: C-Support Vector Classification
	params.C = 0.1;
	params.kernel_type = SVM::LINEAR;   //�ͺ������ͣ�Linear kernel
	params.term_crit = TermCriteria(CV_TERMCRIT_ITER, (int)1e7, 1e-6);  //��ֹ׼�򣺵����������ﵽ���ֵ����ֹ
	

	//��������ѵ��SVM
	cout<<"��ʼѵ������"<<endl;
	clock_t start, finish;  
	double duration;
	start = clock();   //��ʼ��ʱ
	CvSVM svm;  //����һ��SVMʵ��
	svm.train(trainData, labels, Mat(), Mat(), params);
	finish = clock(); //������ʱ
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout<<"ѵ�����̽����� ����ʱ��"<<duration<<"��"<<endl;


	//���Ĳ�����ʾ�о���
	//��һ������ɫ�� �ڶ�������ɫ
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

	
	//���岽����ʾѵ������
	//��ɫ
	//�����ᵼ�»�����ͼ����ʵ�ĵ�
	int thick = -1;
	int lineType = 8;
	float px, py;
	// 1. ��һ��
	for(int i=0; i<NTRAINING_SAMPLES; ++i)
	{
		px = trainData.at<float>(i, 0);
		py = trainData.at<float>(i, 1);
		circle(image, Point((int)px, (int)py), 3, Scalar(0, 255, 0));
	}

	//2. �ڶ���
	for(int i=NTRAINING_SAMPLES; i<2*NTRAINING_SAMPLES; ++i)
	{
		px = trainData.at<float>(i, 0);
		py = trainData.at<float>(i, 1);
		circle(image, Point((int)px, (int)py), 3, Scalar(255, 0, 0));
	}

	//����������ʾ֧������
	thick = 2;
	lineType = 8;
	int x = svm.get_support_vector_count();  //��ȡ֧�������ĸ���
	for(int i=0; i< x; ++i)
	{
		const float* v = svm.get_support_vector(i);
		circle(image, Point((int)v[0], (int)v[1]), 6, Scalar(128, 128, 128), thick, lineType);
	}
	imshow("������", image);
	waitKey(0);
	return 0;
}

