%% Task 1: Split Frequency
%Ratio = 0.1
img = im2double(imread('images/lena.jpg'));
ratio = 0.1;
[low_pass_img, high_pass_img] = separate_frequency(img, ratio);

figure, imshow(low_pass_img);
figure, imshow(high_pass_img + 0.5);
imwrite(low_pass_img, 'lena_low_0.1.jpg');
imwrite(high_pass_img + 0.5, 'lena_high_0.1.jpg');

%Ratio = 0.2
ratio = 0.2;
[low_pass_img, high_pass_img] = separate_frequency(img, ratio);

figure, imshow(low_pass_img);
figure, imshow(high_pass_img + 0.5);
imwrite(low_pass_img, 'lena_low_0.2.jpg');
imwrite(high_pass_img + 0.5, 'lena_high_0.2.jpg');

%% Task 2: Hybrid Image
% Low-Frequency marilyn.jpg & High-Frequency einsten.jpg
% Ratio = 0.15
name1 = 'images/marilyn.jpg';
name2 = 'images/einstein.jpg';
img1 = im2double(imread(name1));
img2 = im2double(imread(name2));

ratio = 0.15;
img_merged = hybrid_image(img1, img2, ratio);
figure, imshow(img_merged);
imwrite(img_merged, 'hybrid_1.jpg');

% Low-Frequency einstein.jpg and High-Frequency marilyn.jpg
% Ratio = 0.15
img_merged = hybrid_image(img2, img1, ratio);
figure, imshow(img_merged);
imwrite(img_merged, 'hybrid_2.jpg');