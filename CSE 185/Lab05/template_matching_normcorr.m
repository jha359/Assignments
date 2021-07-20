function [output, match] = template_matching_normcorr(img, template, threshold)

shift_u = floor(size(template, 2) / 2);
shift_v = floor(size(template, 1) / 2);
output = zeros(size(img));
img = padarray(img, [shift_v shift_u], 0, 'both');

for u = 1 + shift_u : size(img, 2) - shift_u
    for v = 1 + shift_v : size(img, 1) - shift_v
        
        x1 = u - shift_u; x2 = u + shift_u;
        y1 = v - shift_v; y2 = v + shift_v;
        patch = img(y1:y2, x1:x2);
        
        patchvector = patch(:);
        templatevector = template(:);
        patchmean = mean(patchvector);
        templatemean = mean(templatevector);
        patchsub = patchvector - patchmean;
        templatesub = templatevector - templatemean;
        patchnorm = patchsub / norm(patchsub);
        templatenorm = templatesub / norm(templatesub);
        norm_value = dot(patchnorm, templatenorm);
        
        output(v - shift_v ,u - shift_u) = norm_value;
    end
end

match = (output > threshold);


end