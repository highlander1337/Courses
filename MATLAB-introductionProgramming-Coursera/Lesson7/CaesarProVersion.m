function txt = CaesarProVersion(txt,key)
    % How to call it
    % txt = CaesarProVersion('AKCSOOS', 3);
    txt = double(txt) + key;
    first = double(' ');
    last = double('~');
    % use mod to shift the characters since the result of mod is the residual from crossing by a range a number of times
    
    % Imagine two clocks, one for measure the actual number and other to measure how many times we cross the limits on the first one, 
    % now we wanted to know the new predicted value after we summ or substract some units from the actual value. Using mod allow us to 
    % quickly calculate the rest of a division, therefore, the rest plus the initial value of the first clock will be the predicted value from the actual one.
    
    % notice the + 1
    % this is a common error and results in shifts 
    % being off by 1
    txt = char(mod(txt - first,last - first + 1) + first);
end
