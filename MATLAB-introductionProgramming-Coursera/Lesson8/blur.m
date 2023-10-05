% Write a function called blur that blurs the input image. The function is to be called like this:
% output = blur(img, w);
% where img, the input image is a two-dimensional matrix of grayscale pixel values between 0 and 255. Blurring is to be carried out by
% averaging the pixel values in the vicinity of every pixel. Specifically, the output pixel value is the mean of the pixels in a square
% submatrix of size 2*w +1 where the given pixel sits in the center. For example, if w is 1, the we use a 3x3 matrix, that is, we average
% all the neighboring pixels of the given pixel and itself. Only use valid pixels when portions of the blurring matrix fall outside the 
% image. For example, the blurred value corresponding to w=1 at index (1,1) would be the mean of the elements (1,1), (1,2), (2,1) and (2,2).
% Both input img and output are of type uint8.


function output = blur(img, w)

dims = size(img);
output = ones(dims(1), dims(2));

for i = 1:dims(1)
    for j = 1:dims(2)
% Submatrix indice limits      
a = i - w;
b = i + w;
c = j - w;
d = j + w;

% Check if we are in the corners
if a <= 0
    a = 1;
end

if c <= 0
    c = 1;
end

if b > dims(1)
    b = i;
end

if d > dims(2)
    d = j;
end
% Collecting the submatrix
submatrix = img(a:b, c:d);

% Applying the blur filter
output(i, j) = mean(submatrix(:));

    end
end

% Return uint8 0 to 255
output = uint8(output);
end
