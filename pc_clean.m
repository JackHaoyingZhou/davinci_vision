% point cloud cleanup test

fileID = fopen('new_pattern_pointcloud.txt','r');
size_A = [3 Inf];
A = fscanf(fileID,'%f %f %f',size_A);
A = A';

% clean up point cloud

pcloud = pointCloud(A);
figure
pcshow(pcloud)
xlabel('x')
ylabel('y')
zlabel('z')

%% Load new stereo images
I1 = imread('test_left11.png');
I2 = imread('test_right11.png');
J1 = rgb2gray(I1);
J2 = rgb2gray(I2);

%% disparity map example
disparityRange = [0 80];
blocksize=7;
disparityMap = disparity(J1,J2,'BlockSize',blocksize,'DisparityRange',disparityRange);
imgfilt = medfilt2(disparityMap);

figure
imshow(disparityMap,disparityRange);
title('Disparity Map');

colormap(gca,jet)
colorbar

% 
% figure
% imshow(stereoAnaglyph(I1,I2));
% title('Red-cyan composite view of the stereo images');

% alpha(0.5)
