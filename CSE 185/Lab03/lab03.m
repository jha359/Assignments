%Problem 1
img = im2double(imread("lena.jpg"));
H = [1, 2, 1; 0 0 0; -1, -2, -1];

img_sobel = sobel_filter(img, H);
figure, imshow(img_sobel);
imwrite(img_sobel, "sobel_h.jpg");

%Problem 2
V = [1, 0, -1; 2, 0, -2; 1, 0 ,-1;];

img_sobel = sobel_filter(img, V);
figure, imshow(img_sobel);
imwrite(img_sobel, "sobel_v.jpg");

%Problem 3
hsize = 5;
sigma = 2;

img_gaussian = gaussian_filter(img, hsize, sigma);
figure, imshow(img_gaussian);
imwrite(img_gaussian, "gaussian_5.jpg");

%Problem 4
hsize = 9;
sigma = 4;

img_gaussian = gaussian_filter(img, hsize, sigma);
figure, imshow(img_gaussian);
imwrite(img_gaussian, "gaussian_9.jpg");