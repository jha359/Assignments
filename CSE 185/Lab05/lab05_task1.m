img = im2double(imread('lena.jpg'));

sigma = 2.0;
hsize = 7;
scale = 5;

%% Gaussian Pyramid
IG = img;
for s = 1:scale
    H = fspecial('gaussian', hsize, sigma);
    IG = imfilter(IG, H);
    imwrite(IG, sprintf('Gaussian_scale%d.jpg', s));
    IG = imresize(IG, 0.5, 'nearest');
end

%% Laplacian Pyramid

IL = img;
for s = 1:scale
    H = fspecial('gaussian', hsize, sigma);
    ILG = imfilter(IL, H);
    IL = IL - ILG;
    imwrite(IL + 0.5, sprintf('Laplacian_scale%d.jpg', s));
    figure, imshow(IL);
    IL = imresize(IL, 0.5, 'nearest');
end