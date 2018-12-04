from __future__ import print_function
import cv2
import numpy as np
 
 
MAX_FEATURES = 500
GOOD_MATCH_PERCENT = 0.15
 
 
def alignImages(im1, im2):
 
  # Convert images to grayscale
  im1Gray = cv2.cvtColor(im1, cv2.COLOR_BGR2GRAY)
  im2Gray = cv2.cvtColor(im2, cv2.COLOR_BGR2GRAY)
   
  # Detect ORB features and compute descriptors.
  orb = cv2.ORB_create(MAX_FEATURES)
  keypoints1, descriptors1 = orb.detectAndCompute(im1Gray, None)
  keypoints2, descriptors2 = orb.detectAndCompute(im2Gray, None)
   
  # Match features.
  matcher = cv2.DescriptorMatcher_create(cv2.DESCRIPTOR_MATCHER_BRUTEFORCE_HAMMING)
  matches = matcher.match(descriptors1, descriptors2, None)
   
  # Sort matches by score
  matches.sort(key=lambda x: x.distance, reverse=False)
 
  # Remove not so good matches
  numGoodMatches = int(len(matches) * GOOD_MATCH_PERCENT)
  matches = matches[:numGoodMatches]
 
  # Draw top matches
  imMatches = cv2.drawMatches(im1, keypoints1, im2, keypoints2, matches, None)
  cv2.imwrite("matches.jpg", imMatches)
   
  # Extract location of good matches
  points1 = np.zeros((len(matches), 2), dtype=np.float32)
  points2 = np.zeros((len(matches), 2), dtype=np.float32)
 
  for i, match in enumerate(matches):
    points1[i, :] = keypoints1[match.queryIdx].pt
    points2[i, :] = keypoints2[match.trainIdx].pt
   
  # Find homography
  h, mask = cv2.findHomography(points1, points2, cv2.RANSAC)
 
  # Use homography
  height, width, channels = im2.shape
  im1Reg = cv2.warpPerspective(im1, h, (width, height))
   
  return im1Reg, h
 
 
if __name__ == '__main__':
   
  # Read reference image
  refFilename = "form.jpg"
  print("Reading reference image : ", refFilename)
  imReference = cv2.imread(refFilename, cv2.IMREAD_COLOR)
 
  # Read image to be aligned
  imFilename = "scanned-form.jpg"
  print("Reading image to align : ", imFilename);  
  im = cv2.imread(imFilename, cv2.IMREAD_COLOR)
   
  print("Aligning images ...")
  # Registered image will be resotred in imReg. 
  # The estimated homography will be stored in h. 
  imReg, h = alignImages(im, imReference)
   
  # Write aligned image to disk. 
  outFilename = "aligned.jpg"
  print("Saving aligned image : ", outFilename); 
  cv2.imwrite(outFilename, imReg)
 
  # Print estimated homography
  print("Estimated homography : \n",  h)
  
  


# def sift_kp(image):
    # gray_image = cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)
    # sift=cv2.xfeatures2d.SIFT_create()
    # kp,des = sift.detectAndCompute(image,None)
    # kp_image = cv2.drawKeypoints(gray_image,kp,None)
    # return kp_image,kp,des
 
 
# def get_good_match(des1,des2):
    # bf = cv2.BFMatcher()
    # matches = bf.knnMatch(des1, des2, k=2) #des1为模板图，des2为匹配图
    # matches = sorted(matches,key=lambda x:x[0].distance/x[1].distance)
    # good = []
    # for m, n in matches:
        # if m.distance < 0.75 * n.distance:
            # good.append(m)
    # return good
 
 
# def siftImageAlignment(img1,img2):
   # _,kp1,des1 = sift_kp(img1)
   # _,kp2,des2 = sift_kp(img2)
   # goodMatch = get_good_match(des1,des2)
   # if len(goodMatch) > 4:
       # ptsA= np.float32([kp1[m.queryIdx].pt for m in goodMatch]).reshape(-1, 1, 2)
       # ptsB = np.float32([kp2[m.trainIdx].pt for m in goodMatch]).reshape(-1, 1, 2)
       # ransacReprojThreshold = 4
       # H, status =cv2.findHomography(ptsA,ptsB,cv2.RANSAC,ransacReprojThreshold);
       # imgOut = cv2.warpPerspective(img2, H, (img1.shape[1],img1.shape[0]),flags=cv2.INTER_LINEAR + cv2.WARP_INVERSE_MAP)
   # return imgOut,H,status
 
# img1 = cv2.imread(r'sift_img/8.png')
# img2 = cv2.imread(r'sift_img/7.png')
 
# _,kp1,des1 = sift_kp(img1)
# _,kp2,des2 = sift_kp(img2)
# goodMatch = get_good_match(des1,des2)
 
# img3 = cv2.drawMatches(img1, kp1, img2, kp2, goodMatch[:5], None, flags=2)
# #----or----
# #goodMatch = np.expand_dims(goodMatch,1)
# #img3 = cv2.drawMatchesKnn(img1, kp1, img2, kp2, goodMatch[:5], None, flags=2)
 
# cv2.imshow('img',img3)
# cv2.waitKey(0)
# cv2.destroyAllWindows()