function output = digit_sum(input)
% A simple recursion function thats calculate the sum of 
% n consecutive digits as one single integer input
% Example digit_sum(12345) will return 15
  
% Base case
if input < 1
    output = 0;
else
    output = digit_sum(input/10) + ((floor(input)/10 - floor(floor(input/10)))*10);
end

end
