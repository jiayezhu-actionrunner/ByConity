SELECT max(x) - min(x) < 0.000001 FROM (
    SELECT arrayJoin([e1, e2, e3, e4, e5, e6, e7, e8]) AS x
    FROM (
        SELECT  entropy(number % 2, number % 5) AS e1,
                log2(10) AS e2,
                log2(uniq(number % 2, number % 5)) AS e3,
                entropy(number) AS e4,
                entropy(toString(number)) AS e5,
                entropy(number % 2 ? 'hello' : 'world', range(number % 5)) AS e6,
                entropy(number, number + 1, number - 1) AS e7,
                entropy(([[number], [number, number]], [[], [number]])) AS e8
        FROM numbers(10)
    )
);
SELECT abs(entropy(number) - 8) < 0.000001, abs(entropy(number % 64, number % 32) - 6) < 0.000001 FROM numbers(256);
