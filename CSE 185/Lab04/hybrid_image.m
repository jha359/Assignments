function img_merged = hybrid_image(img1, img2, ratio)

[img1_low, img1_high] = separate_frequency(img1, ratio);
[img2_low, img2_high] = separate_frequency(img2, ratio);

I1 = img1_low(:);
I2 = img2_high(:);
avg = (I1 + I2)/2;
img_merged = reshape(avg, size(img1,1), size(img1, 2), size(img1, 3));
end