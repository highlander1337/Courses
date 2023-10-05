function y = CaesarMasterVersion(ch, key)
    % How to call it
    % y = CaesarMasterVersion('adsidasd', 3)
    v = ' ' : '~';
    [~, loc] = ismember(ch, v);
    v2 = circshift(v, -key);
    y = v2(loc);
end
