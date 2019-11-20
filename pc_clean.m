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
% load stereo camera parameter
load('webcamStereoParams2.mat')
I1 = imread('my_photo-1.jpg');
I2 = imread('my_photo-2.jpg');
J1 = rgb2gray(I1);
J2 = rgb2gray(I2);
[G1,G2] = rectifyStereoImages(I1,I2,stereoParams2);
J1rec = rgb2gray(G1);
J2rec = rgb2gray(G2);
%% disparity map example
disparityRange = [0 80];
dispRange1 = num2str(disparityRange(1));
dispRange2 = num2str(disparityRange(2));
blocksize=7;
disparityMap = disparity(J1,J2,'BlockSize',blocksize,'DisparityRange',disparityRange);
disparityMapRec = disparity(J1rec,J2rec,'BlockSize',blocksize,'DisparityRange',disparityRange);
imgfilt = medfilt2(disparityMap);
imgfiltrec = medfilt2(disparityMapRec);

%% Show images from two cameras
A = stereoAnaglyph(G1,G2);
figure
imshow(A)

%%
figure
% imshow(disparityMap,disparityRange);
imshow(disparityMapRec,disparityRange);
% title(['Disparity Map with blocksize ', num2str(blocksize), ' and range [',dispRange1,' ',dispRange2,']']);
title('Rectified Disparity Map');
colormap(gca,jet)
colorbar

%% Reconstruct 3D scene
points3D = reconstructScene(disparityMapRec, stereoParams2);

% Convert to meters and create a pointCloud object
points3D = points3D ./ 1000;
ptCloud = pointCloud(points3D, 'Color', G1);

% Create a streaming point cloud viewer
player3D = pcplayer([-3, 3], [-3, 3], [0, 8], 'VerticalAxis', 'y', ...
    'VerticalAxisDir', 'down');

% Visualize the point cloud
view(player3D, ptCloud);
