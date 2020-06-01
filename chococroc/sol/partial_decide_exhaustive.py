def win_from(n, m):
    assert 1 <= n and 1 <= m

    if n == 1 and m == 1:
        return 0

    if (
        any(not win_from(n - s, m) for s in range(1, n // 2 + 1))
        or
        any(not win_from(n, m - s) for s in range(1, m // 2 + 1))
    ):
        return 1
    else:
        return 0

def cut_direction(n, m):
    return 0

def eat_size(n, m):
    return 0
