# OpenCV-Object-Detection

Implemented various Object-Detection Algorithm in Open CV 2D Features framework.

OpenCV is a popular computer vision library that has many built in tools for image analysis and understanding. Especially, features and feature extraction is the basis for many computer vision applications. The idea is that any set of data, such as a set of images, can be represented by a smaller, simpler model made of a combination of visual features: color-based and shape-based features. In this practice, by using Open CV 2D Features framework, shape-based features are mainly explored.

The first step is to locate all the keypoints in the training image. After the keypoints have been located, each detectors creates their corresponding binary feature vectors and groups them together in the paired descriptor. We will use OpenCV’s 2D Feature framework to locate the keypoints and create their corresponding descriptors. The parameters of the object detection algorithm are setup using the XXX_create() function. The parameters of the XXX_create() function and their default values are different according to each algorithm.

main properties of the object detection algithms are tested in the following use cases: 
- Scale Invariance
- Rotational Invariance
- Illumination Invariance 
- Noise Invariance

 
1. Corner Detectors 
A single corner will not be enough to identify an object in any other images, but, we can take a set of features that define the shape of the object, group them together into an array or vector, and then use that set of features to create a specific detector.

* Shi-Tomasi corner detector 
* Harris corner detection 
* FAST(Feature accelerated Segments Test)
* BRISK
* ORB(ORiented Fast Rotated Brief)
* KAZE, AKAZE 

2. Keypoint Descriptors
* BRISK 
* BRIEF
* ORB(ORiented Fast Rotated Brief) 
* FREAK(Binary Robust Independent Elementary Features)
* AKAZE 
* SIFT : HOG(Histograms of Oriented Gradients) family descriptor 

> Binary and HOG descriptors all rely on patterns of intensity to identify different shapes (like edges) and eventually whole objects (with feature vectors).

Note that, OpenCV reads in images in BGR format (instead of RGB) so that color converting process is needed for example,
`cv2.cvtColor(image, cv2.COLOR_BGR2GRAY). ## convert color to Gray scale`

### Reference
[OpenCV 2D Features framework](https://docs.opencv.org/master/d9/d97/tutorial_table_of_content_features2d.html)
