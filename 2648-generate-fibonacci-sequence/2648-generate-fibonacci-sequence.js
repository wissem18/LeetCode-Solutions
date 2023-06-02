/**
 * @return {Generator<number>}
 */
var fibGenerator = function*(cur=0,next=1) {
    yield cur;
    yield* fibGenerator(next,cur+next);
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */