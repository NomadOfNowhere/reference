// Push to an array all possible values
coord.pb(x);
sort(all(coord));
coord.resize(unique(all(coord)) - coord.begin());

auto get = [&](int x) = {
    return lower_bound(all(coord), x) - coord.begin();
};