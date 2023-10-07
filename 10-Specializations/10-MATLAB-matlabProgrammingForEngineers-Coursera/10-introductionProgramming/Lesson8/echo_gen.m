% Write a function called echo_gen that adds an echo effect to an audio recording. An echo is the original signal delayed and
% attenuated. Therefore, you will first need to compute the echo and then add it to the original signal with the correct offset.
% The function is to be called like this: output = echo_gen(input, fs, delay, amp);
% where input is a column vector with values between -1 and 1 representing a time series of digitized sound data.
% The input argument fs is the sampling rate. The sampling rate specifies how many samples we have in the data each second.
% The input argument delay represent the delay of the echo in seconds. That is, the echo should start after delay seconds have passed 
% from the start of the audio signal. Finally, amp specifies the amplfication of the echo. While typically this is a value less than
% 1 because the echo is not as loud, your function should work if amp is greater than 1.

% The output of the function is a column vector containing the original sound with the echo superimposed. The output vector will be longer
% than the input vector if the delay is not zero (round to the nearest number of points neede to get the delay, as opposed to floor or ceil).
% A sound recording has values between -1 and 1, so if the echo causes some values to be outside of this range, you will need to scale the entire
% vector, so that all values are within the range while retaining their relative amplitudes.

function echo = echo_gen(input, fs, delay, amp)
% Samples to be avoided if delay is applied
avoided_samples = [];

% Check if delay is applied
if delay > 0
    avoided_samples = zeros(round(fs*delay), 1); % Generate a column vector of zeros
end
% Generate the echo with avoided_samples
echo = ([avoided_samples; input])*amp;

% Superimpose the input vector with the echo vector then append the rest of the echo vector to the result
echo = [input + echo(1:length(input), 1); echo(length(input) +1:end, 1)];

% Scaling while renaining the relative amplitudes (note, relative amplitude does not care about the sign)
if max(abs(echo))>1    % scaling b/w -1,+1 throught relative scaling.   
        echo=echo/max(abs(echo));
end

% If relative amplitudes are not applied, that is, if the signs care, use this
%HighV = find(echo > 1);
%LowV = find(echo < -1);
%echo(HighV) = echo(HighV)/max(echo(HighV));
%echo(LowV) = -echo(LowV)/min(echo(LowV));


end
