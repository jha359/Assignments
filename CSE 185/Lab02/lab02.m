%Problem 1
I1 = imread("01.jpg");
fwarp = zeros(300, 400, 3, 'uint8');
y0 = 150;
x0 = 200;
for y1 = 1:300
    for x1 = 1:400
        x2 = cosd(45) * (x1 - x0) + sind(45) * (y1 - y0) + x0;
        y2 = -sind(45) * (x1 - x0) + cosd(45) * (y1 - y0) + y0;
        x2 = round(x2);
        y2 = round(y2);
        
        if x2 > 0 && x2 < 400
            if y2 > 0 && y2 < 300
                fwarp(y2, x2, :) = I1(y1, x1, :);
            end
        end
        
    end
end
figure, imshow(fwarp);
imwrite(fwarp, "rotate_0.jpg");

%Problem 2
I1 = imread("01.jpg");
bwarp = zeros(300, 400, 3, 'uint8');
y0 = 150;
x0 = 200;

for y2 = 1:300
    for x2 = 1:400
        x1 = cosd(45) * (x2 - x0) - sind(45) * (y2 - y0) + x0;
        y1 = sind(45) * (x2 - x0) + cosd(45) * (y2 - y0) + y0;
        x1 = round(x1);
        y1 = round(y1);
        
        if x1 > 0 && x1 < 400
            if y1 > 0 && y1 < 300
                bwarp(y2, x2, :) = I1(y1, x1, :);
            end
        end
        
    end
end
figure, imshow(bwarp);
imwrite(bwarp, "rotate_1.jpg");

%Problem 3
img = im2double(imread("lena_noisy.jpg"));
patch_size = [3,3];

img_median_1 = median_filter(img, patch_size);
figure, imshow(img_median_1);
imwrite(img_median_1, "median_0.jpg");

%Problem 4
img = im2double(imread("lena_noisy.jpg"));
patch_size = [5,5];

img_median_2 = median_filter(img, patch_size);
figure, imshow(img_median_2);
imwrite(img_median_2, "median_1.jpg");
