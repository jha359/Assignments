function feature = multiscale_sobel_feature(img, scale)

feature = [];

for i = 1:scale
    
    [fmag, fori] = sobel_feature(img);
    
    feature = cat(1, feature, fori(:));
    
    img = imresize(img, 0.5, 'nearest');

end