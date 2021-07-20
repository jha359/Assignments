function output = gaussian_filter(img, hsize, sigma)
kernel = fspecial('gaussian', hsize, sigma);
output = zeros(size(img));
lead = floor(hsize/2);
img = padarray(img,[lead lead], 0, 'both');

for i = 1 :size(output, 2)
    for j = 1:size(output, 1)
        
        mag = 0;
        patch = img(i:i+lead*2, j:j+lead*2);
        
        for u = 1:hsize
            for v = 1:hsize
                mag = mag + patch(u,v) * kernel(u,v);
            end
        end
        
        output(i, j, :) = mag;
    end
end

end