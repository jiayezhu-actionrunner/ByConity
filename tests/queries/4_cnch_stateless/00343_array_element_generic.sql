SELECT range(0)[-1];
SELECT range(0)[1];
SELECT range(number)[2] FROM system.numbers LIMIT 10;
SELECT range(number)[-1] FROM system.numbers LIMIT 10;
SELECT range(number)[number] FROM system.numbers LIMIT 10;
SELECT range(number)[2 - number] FROM system.numbers LIMIT 10;

SELECT arrayMap(x -> toString(x), range(number))[2] FROM system.numbers LIMIT 10;
SELECT arrayMap(x -> toString(x), range(number))[-1] FROM system.numbers LIMIT 10;
SELECT arrayMap(x -> toString(x), range(number))[number] FROM system.numbers LIMIT 10;
SELECT arrayMap(x -> toString(x), range(number))[2 - number] FROM system.numbers LIMIT 10;

SELECT arrayMap(x -> range(x), range(number))[2] FROM system.numbers LIMIT 10;
SELECT arrayMap(x -> range(x), range(number))[-1] FROM system.numbers LIMIT 10;
SELECT arrayMap(x -> range(x), range(number))[number] FROM system.numbers LIMIT 10;
SELECT arrayMap(x -> range(x), range(number))[2 - number] FROM system.numbers LIMIT 10;

SELECT [[1]][1], materialize([[1]])[1], [[1]][materialize(1)], materialize([[1]])[materialize(1)];
SELECT [['Hello']][1], materialize([['World']])[1], [['Hello']][materialize(1)], materialize([['World']])[materialize(1)];

SELECT arr[number], arr[number][number], arr[number][number][number] FROM (SELECT number, [[['a'], ['b', 'c']], [['d', 'e', 'f'], ['g', 'h', 'i', 'j'], ['k', 'l', 'm', 'n', 'o']], [['p', 'q', 'r', 's', 't', 'u'], ['v', 'w', 'x', 'y', 'z', 'aa', 'bb'], ['cc', 'dd', 'ee', 'ff', 'gg', 'hh', 'ii', 'jj'], ['kk', 'll', 'mm', 'nn', 'oo', 'pp', 'qq', 'rr', 'ss']]] AS arr FROM system.numbers LIMIT 10);
