def win_from(n, m):
    assert 1 <= n and 1 <= m

    if n == 1 and m == 1:
        return 0

    if (
        all(win_from(n - s, m) for s in range(1, n // 2 + 1))
        and
        all(win_from(n, m - s) for s in range(1, m // 2 + 1))
    ):
        return 0
    else:
        return 1

def find_move(n, m):
    for s in range(1, n // 2 + 1):
        if not win_from(n - s, m):
            return (0, s)
    for s in range(1, m // 2 + 1):
        if not win_from(n, m - s):
            return (1, s)

def cut_direction(n, m):
    d, s = find_move(n, m)
    return d

def eat_size(n, m):
    d, s = find_move(n, m)
    return s
