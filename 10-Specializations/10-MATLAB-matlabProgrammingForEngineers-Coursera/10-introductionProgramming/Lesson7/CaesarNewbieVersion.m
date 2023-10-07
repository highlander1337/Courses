function coded = CaesarNewbieVersion(vector, amount)
% coded = CaesarNewbieVersion('AKCSOOS', 3);
myvector = ' ':'~';
coded = vector;
for ii = 1:length(vector)
    % First we find our currently position on the possible vector
    x = findstr(myvector, vector(ii));
    
    % Second we iterate our position one by one
    for jj = 1:abs(amount)
      % if right shift then
      if amount > 0 
          x = x + 1; 
      else % if left shift then
          x = x - 1;
      end
     
     % if we reach the end of the line in both directions on myvector, then reset accordly
      if x > 95
          x = 1; 
      elseif x < 1
          x = 95;
      end
      
    end
    % Set the coded value to the actual value after a few iterations
    coded(ii) = myvector(x);
end

end
