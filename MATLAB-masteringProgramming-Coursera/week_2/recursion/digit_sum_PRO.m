function res = digit_sum(n)
  
  % The function does the same, but using the reminder of a division by ten 
  % (such a wonderful mathematical trick, i must re-read some basic math books)
    if n < 10
        res = n;
    else
        res = digit_sum(floor(n/10)) + rem(n,10);
    end
end
