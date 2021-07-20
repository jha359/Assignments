function output = median_filter(img, patch_size)
output = zeros(size(img));
ylead = floor(patch_size(1)/2);
xlead = floor(patch_size(2)/2);

for u = 1 + ylead:size(img, 2)-ylead
    for v = 1 + xlead:size(img, 1)-xlead
        
        patch = img(u-ylead:u+ylead, v-xlead:v+xlead);
        median1 = median(patch);
        median2 = median(median1);
        
        output(u,v, :) = median2;
    end
end
end