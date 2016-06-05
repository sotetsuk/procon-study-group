'use strict';

waterfall([
  function(next) {
    lineReader(1, next);
  }, function(line, next) {
    solve(line[0], next);
  }], function(sum, result) {
    console.log(sum);
    console.log(result.reduce(function(memo, s) {
      memo.push(s.area);
      return memo;
    }, [result.length]).join(' '));
    process.exit(0);
  });

function solve(line, cb) {
  var stack = [];
  var result = [];
  var sum = 0;
  strMap(line, function(c, i) {
    if (c === '\\') {
      stack.push(i);
      return;
    }
    if (c === '/') {
      var s = stack.pop();
      if (s !== 0 && !s) return;

      sum += i - s;
      var tmp = i - s;
      while(result.length > 0 && result[result.length - 1].left > s) {
        tmp += result[result.length - 1].area;
        result.pop();
      }

      result.push({left: s, area: tmp});
    }
  });
  cb(sum, result);
}

function strMap(str, map) {
  var newStr = '';
  for (var i = 0; i < str.length; i++) {
    newStr += map(str.charAt(i), i);
  }
  return newStr;
}

function lineReader(limit, cb) {
  var reader = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout,
  });
  var lines = [];
  var counter = 0;
  reader.on('line', function(line) {
    lines.push(line);
    ++counter;
    if (counter === limit) {
      reader.close();
      return cb(lines);
    }
  });
  reader.on('close', function() {});
  reader.on('error', function(err) {
    cb(err);
  });
}

function waterfall(tasks, cb) {
  var taskIndex = 0;
  function nextTask(args) {
    if (taskIndex === tasks.length)
      return cb.apply(null, args);

    var taskCallback = function() {
      var _arguments = arguments;
      nextTask(Object.keys(_arguments).reduce(function(memo, key) {
        memo.push(_arguments[key]);
        return memo;
      }, []));
    };
    args.push(taskCallback);
    var task = tasks[taskIndex++];
    task.apply(null, args);
  }
  nextTask([]);
}
