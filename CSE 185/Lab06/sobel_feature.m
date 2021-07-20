function [magnitude, orientation] = sobel_feature(img)

Hy = [1, 2, 1; 0, 0, 0; -1, -2, -1];
Hx = [1, 0, -1; 2, 0, -2; 1, 0 ,-1];

img_sobel_horizontal = imfilter(img, Hy);
img_sobel_vertical = imfilter(img, Hx);

magnitude = sqrt((img_sobel_horizontal).^2 + (img_sobel_vertical).^2);
orientation = atan2(img_sobel_horizontal, img_sobel_vertical);

end