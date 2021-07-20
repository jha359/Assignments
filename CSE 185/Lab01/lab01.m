%Problem 1
I = imread("01.jpg");
I(:, :, 2) = 0;
figure, imshow(I);
imwrite(I, "green.jpg");

%Problem 2
G = imread("01.jpg");
gray = G(:, :, 1) * 0.299 + G(:, :, 2) * 0.587 + G(:, :, 3) * 0.114;
figure, imshow(gray);
imwrite(gray, "gray.jpg");

%Problem 3
R = imread("01.jpg");
rotated = imrotate(R, 90);
figure, imshow(rotated);
imwrite(rotated, "rotate.jpg");

%Problem 4
C = imread("01.jpg");
cropped = imcrop(C, [30, 100, 270, 300]);
figure, imshow(cropped);
imwrite(cropped, "crop.jpg");

%Problem 5
F = imread("01.jpg");
flipped = flip(F,2);
figure, imshow(flipped);
imwrite(flipped, "flip.jpg");

%Problem 6
I1 = imread("01.jpg");
I2 = imread("02.jpg");
I3 = imread("03.jpg");
I4 = imread("04.jpg");
combined = zeros(300 * 2 + 10, 400 * 2 + 10, 3, 'uint8');
combined(1:300, 1:400, :) = I1;
combined(1:300, 411:810, :) = I2;
combined(311:610, 1:400, :) = I3;
combined(311:610, 411:810, :) = I4;
figure, imshow(combined);
imwrite(combined, "combine.jpg");

%Problem 7
I1 = imread("05.jpg");
I2 = imread("06.jpg");
I1 = I1(:);
I2 = I2(:);
avg = (I1 + I2) / 2;
average = reshape(avg, 375, 1242, 3);
figure, imshow(average);
imwrite(average, "average.jpg");