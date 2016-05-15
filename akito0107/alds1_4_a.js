'use strict';

waterfall([
  function(next) {
    lineReader(4, next);
  }, function(line, next) {
    var toInt = function(s) {
      return parseInt(s);
    }
    var s = line[1].split(' ').map(toInt);
    var t = line[3].split(' ').map(toInt);
    next(t.reduce(function(sum, i) {
      return s.some(function(test) {
        return test === i;
      }) ? sum + 1 : sum;
    }, 0));
  }], function(result) {
    console.log(result);
    process.exit(0);
  });

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
