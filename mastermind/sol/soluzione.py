#!/usr/bin/env python3
from grader import inizializza, pensoCheCodiceSia, checkCode


def check_code(attempt, result, history):
    black = 0
    white = 0

    fr_att = [0] * 6
    fr_hist = [0] * 6

    for i in range(4):
        if attempt[i] == history[i]:
            black += 1
        else:
            assert(0 <= attempt[i] <= 5)
            assert(0 <= history[i] <= 5)
            fr_att[attempt[i]] += 1
            fr_hist[history[i]] += 1

    for i in range(6):
        white += min(fr_att[i], fr_hist[i])

    result[0] = black
    result[1] = white


def rank(black, white):
    return black * 4 + white


def increase(num):
    for i in reversed(range(4)):
        num[i] += 1
        if num[i] == 6:
            num[i] = 0
        else:
            break


is_invalid = [[[[False for _ in range(6)]
                for _ in range(6)] for _ in range(6)] for _ in range(6)]


def is_valid(code):
    return not is_invalid[code[0]][code[1]][code[2]][code[3]]


def set_invalid(code):
    is_invalid[code[0]][code[1]][code[2]][code[3]] = 1


def get_score(code):

    p_code = [0, 0, 0, 0]

    results = [0] * 17

    while True:
        if is_valid(p_code):
            result = [0, 0]
            check_code(p_code, result, code)
            results[rank(result[0], result[1])] += 1
        increase(p_code)
        if sum(p_code) == 0:
            break

    worst = 0

    for i in range(17):
        if results[i]:
            worst = max(results[i], worst)

    return worst


inizializza()

g_code = [0, 0, 1, 1]  # Codice soluzione da sottomettere

guesses = 0
result = [0, 0]

previous_answers = [[0] * 4 for _ in range(10)]
previous_rankings = [0] * 10

while True:
    guesses += 1

    checkCode(g_code, result)
    ranking = rank(result[0], result[1])

    previous_answers[guesses - 1][0] = g_code[0]
    previous_answers[guesses - 1][1] = g_code[1]
    previous_answers[guesses - 1][2] = g_code[2]
    previous_answers[guesses - 1][3] = g_code[3]
    previous_rankings[guesses - 1] = ranking

    if result[0] == 4:
        break

    a_code = [0] * 4  # Codice soluzione temporaneo

    while True:
        if is_valid(a_code):
            for i in range(guesses):
                check_code(a_code, result, previous_answers[i])
                test_ranking = rank(result[0], result[1])
                if test_ranking != previous_rankings[i]:
                    set_invalid(a_code)
                    break

        increase(a_code)
        if sum(a_code) == 0:
            break

    best_score = 0x7fffffff
    b_code = [0] * 4

    while True:
        if is_valid(a_code):
            score = get_score(a_code)
            if best_score > score:
                best_score = score
                b_code[0] = a_code[0]
                b_code[1] = a_code[1]
                b_code[2] = a_code[2]
                b_code[3] = a_code[3]

        increase(a_code)
        if sum(a_code) == 0:
            break

    g_code[0] = b_code[0]
    g_code[1] = b_code[1]
    g_code[2] = b_code[2]
    g_code[3] = b_code[3]

pensoCheCodiceSia(g_code)
