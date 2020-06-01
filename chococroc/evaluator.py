import turingarena as ta
from collections import namedtuple
import random

Result = namedtuple("Result", ["win_from", "move", "error", "time_usage"])
Move = namedtuple("Move", ["cut_direction", "eat_size"])

def evaluate(algo, n, m):
    win_from = None
    move = None
    error = None
    time_usage = None

    try:
        with ta.run_algorithm(algo) as p:
            w = p.functions.win_from(n, m)
            if w:
                d = p.functions.cut_direction(n, m)
                s = p.functions.eat_size(n, m)
        time_usage = p.time_usage
        p.check(w in (0, 1), f"got invalid value {w} from 'win_from'")
        win_from = bool(w)
        if win_from:
            p.check(d in (0, 1), f"got invalid value {d} from 'cut_direction'")
            size = [n, m][d]
            p.check(size > 1, f"cannot eat along direction {d}, it has length only one")
            p.check(1 <= s, f"you have to eat at least one, 'eat_size' returned {s}")
            max_eat = size // 2
            p.check(s <= max_eat, f"direction {d} has length {size}, can eat at most {max_eat}, 'eat_size' returned {s}")
            move = Move(d, s)
    except ta.AlgorithmError as e:
        error = e

    return Result(win_from, move, error, time_usage)

def evaluate_goal(goal, sizes):
    for (n, m) in sizes:
        expected = evaluate("solutions/correct_linear.cpp", n, m)
        actual = evaluate(ta.submission.source, n, m)
        assert expected.error is None

        if ta.parameters.debug:
            print(f"Testing with n = {n:2}, m = {m:2} --> {actual} ({expected})", end="")
        else:
            print(f"Testing with n = {n:2}, m = {m:2} --> ", end="")

        if actual.win_from != expected.win_from:
            ta.goals[f"win_from_{goal}"] = False
            print("Wrong win outcome.")
        elif actual.error:
            print(f"{actual.error}")

        if expected.win_from and actual.move != expected.move:
            if actual.error != None:
                ta.goals[f"move_{goal}"] = False
            else:
                if actual.move.cut_direction == 0:
                    n -= actual.move.eat_size
                else:
                    m -= actual.move.eat_size
                if evaluate("solutions/correct_linear.cpp", n, m).win_from:
                    ta.goals[f"move_{goal}"] = False
                    print("wrong move.")
        print("ok.")

    ta.goals.setdefault(f"win_from_{goal}", True)
    ta.goals.setdefault(f"move_{goal}", True)

def random_lose(n):
    row = random.randint(1, int(n**(1/2)))
    col = row
    while row < n:
        row = row * 2 + 1
    if random.randint(0, 1):
        col, row = row, col
    return col, row

def generate_sizes(n):
    return (
    [(random.randint(1, n), random.randint(1, n)) for _ in range(5)] +
    [random_lose(n) for _ in range(5)] +
    [(n, n)])
def main():

    evaluate_goal("1e1", [
    (1, 1),
    (2, 1),
    (1, 2),
    (1, 3),
    (3, 1),
    (4, 4),
    (5, 7),
    (8, 4),
    (7, 8),
    (8, 9),
    (9, 8),
    (9, 9),
    (10, 10)])
    evaluate_goal("1e3", generate_sizes(1000))
    evaluate_goal("1e9", generate_sizes(int(1e9)))

if __name__ == "__main__":
    main()
