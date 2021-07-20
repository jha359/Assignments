function output = sobel_filter(img, kernel)
output = zeros(size(img));
img = padarray(img, [1 1], 0, 'both');

for i = 1:size(output, 2)
    for j = 1:size(output, 1)
        
        mag = 0;
        patch = img(i:i+2, j:j+2);
        
        for u = 1:3
            for v = 1:3
                mag = mag + patch(u,v) * kernel(u,v);
            end
        end
        
        output(i, j, :) = mag;
    end
end

end