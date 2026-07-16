/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = (n) => {
    let curr = n;
    return {
        increment: () => ++curr,
        decrement: () => --curr,
        reset: () => (curr = n)
    }
}

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */