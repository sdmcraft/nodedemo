function generate(N) {
    var rootPatterns = ['D_', 'DU', '_U', '__'];
    var patterns = [];
    if(N === 1) {
        return rootPatterns;
    } else {
        var subPatterns = generate(N-1);
        rootPatterns.forEach(function(rootPattern) {
            subPatterns.forEach(function(subPattern) {
                patterns.push(rootPattern.concat(subPattern));
            });
          });
    }
    return patterns;
}

var patterns = generate(4);
console.log(patterns);