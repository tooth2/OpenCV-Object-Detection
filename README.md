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
* Harris corner detection : Chris Harris & Mike Stephens in their paper A Combined Corner and Edge Detector in 1988. OpenCV has the function cv.cornerHarris() for this purpose. Its arguments are:  
    * img - Input image (grayscale , float32 type)
    * blockSize - the size of neighbourhood considered for corner detection
    * ksize - Aperture parameter of the Sobel derivative used.
    * k - Harris detector free parameter in the equation.
* FAST(Feature accelerated Segments Test): FAST (Features from Accelerated Segment Test) algorithm was proposed by Edward Rosten and Tom Drummond in their paper "Machine learning for high-speed corner detection" in 2006 (Later revised it in 2010). 
    * It is several times faster than other existing corner detectors.
    * But not robust to high levels of noise. It is dependent on a threshold
* BRISK(Binary Robust Invariant Scalable Keypoints)
* ORB(ORiented Fast Rotated Brief)
* KAZE, AKAZE 

2. Keypoint Descriptors
* BRISK(Binary Robust Invariant Scalable Keypoints): BRISK is equipped with a mechanism for orientation compensation; the orientation of the keypoint and rotation the sampling pattern by that orientation, BRISK becomes somewhat invariant to rotation. 
* BRIEF(Binary Robust Independent Elementary Features): in 2010, BRIEF was introduced as the first binary descriptor. It does not have an elaborate sampling pattern or an orientation compensation mechanism,  BRIEF takes only the information at single pixels location to build the descriptor.
* ORB(ORiented Fast Rotated Brief) : The ORB descriptor is a bit similar to BRIEF. It doesn’t have an elaborate sampling pattern as BRISK or FREAK. However, ORB uses an orientation compensation mechanism, making it rotation invariant.
* FREAK(The Fast REtina Keypoint): FREAK is similar to BRISK by having a handcrafter sampling pattern and also similar to ORB by using unsupervised learning techniques to learn the optimal set of sampling pairs. FREAK also has an orientation mechanism that is similar to that of BRISK.
* AKAZE(Accelerated KAZE (A-KAZE): A-KAZE uses the A-KAZE detector’s estimation of patch scale to sub-sample the grid in steps that are a function of the patch scale.
* SIFT : HOG(Histograms of Oriented Gradients) family descriptor 

> Binary and HOG descriptors all rely on patterns of intensity to identify different shapes (like edges) and eventually whole objects with feature vectors. Hog Family descriptors such as SIFT and SURF are based on histograms of gradients. Thus the gradients of each pixel in the patch need some amunt of computational cost. Even though SURF speeds up the computation using integral imags, this still isn’t fast enough for some applications compared to Binary descriptors. Also, SIFT and SURF are patent-protected. 

3. BF_Matcher (Brute-force descriptor matcher) `cv::BFMatcher`
For each descriptor in the first set, this matcher finds the closest descriptor in the second set by trying each one.
`cv::BFMatcher::create	(normType, crossCheck = false)` 	
* normType:
    * SIFT: `cv::NORM_L2`
    * ORB, BRISK and BRIEF : `cv::NORM_HAMMING`
    * ORB when `WTA_K==3 or 4`: `cv::NORM_HAMMING` (see ORB::ORB constructor description).
* crossCheck:	
    * default, false:  BFMatcher default behaviour when it finds the k nearest neighbors for each query descriptor.
    * crossCheck==true : the knnMatch() method with k=1 will only return pairs (i,j) such that for i-th query descriptor the j-th descriptor in the matcher's collection is the nearest and vice versa, i.e. the BFMatcher will only return consistent pairs to produce best results with minimal number of outliers when there are enough matches. This is alternative to the ratio test, used by D. Lowe in SIFT paper.

* `cv::DMatch`
 As a result of BFMatcher.match(), a list of DMatch objects is produced. 
    * Class for matching keypoint descriptors.
    * attributes: query descriptor index, train descriptor index, train image index, and distance between descriptors.
    * descriptor: A descriptor can be real-valued (e.g. SIFT) or binary (e.g. BRIEF).  The descriptors of both the images are matched to find matching key points between the images by BFMatcher -> match(), knnMatch() or FlannBasedMatcher -> knnMatch(). When matching, a pair of descriptors (train descriptor and query descriptor) is matched from each image, which are the most similar among all of the descriptors. 
    * distance attribute: distance between two descriptors(vectors) of a match. For real-valued descriptors(SIFT or SURF), the Euclidean distance is  used, but the Hamming distance is common for binary descriptors (ORB, BRIEF, BRISK, etc).

Note that, OpenCV reads in images in BGR format (instead of RGB) so that color converting process is needed for example,
`cv2.cvtColor(image, cv2.COLOR_BGR2GRAY). ## convert color to Gray scale`

### Reference
[OpenCV 2D Features framework](https://docs.opencv.org/master/d9/d97/tutorial_table_of_content_features2d.html)
