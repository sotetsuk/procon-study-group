'use strict';

var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = (input.trim()).split('\n');
lines.shift();
var hash = {};

lines.forEach(function(line) {
  var cmd = line.split(' ')[0];
  var key = line.split(' ')[1];
  if (cmd === 'insert') {
    hash[key] = true;
    return;
  }
  if (hash[key]) {
    console.log('yes');
  } else {
    console.log('no');
  }
});

//var util = require('util');
//waterfall([
//  function(next) {
//    lineReader(1, next);
//  }, function(line, next) {
//    var hash = {};
//    lineReader(parseInt(line[0]), function(line) {
//      var command = line.split(' ')[0];
//      var key = line.split(' ')[1];
//      if (command === 'insert') {
//        hash[key] = true;
//      } else {
//        if (hash[key]) {
//          util.print('yes\n');
//        } else {
//          util.print('no\n');
//        }
//      }
//    }, next);
//  }], function(result) {
//    process.exit(0);
//  });
//
//function strMap(str, map) {
//  var newStr = '';
//  for (var i = 0; i < str.length; i++) {
//    newStr += map(str.charAt(i), i);
//  }
//  return newStr;
//}
//
//function lineReader(limit, lineCb, cb) {
//  if (typeof cb === 'undefined') {
//    cb = lineCb;
//    lineCb = null;
//  }
//  var reader = require('readline').createInterface({
//    input: process.stdin,
//    output: process.stdout,
//  });
//  var lines = [];
//  var counter = 0;
//  reader.on('line', function(line) {
//    if (lineCb) {
//      lineCb(line);
//    }
//    lines.push(line);
//    ++counter;
//    if (counter === limit) {
//      reader.close();
//      return cb(lines);
//    }
//  });
//  reader.on('close', function() {});
//  reader.on('error', function(err) {
//    cb(err);
//  });
//}
//
//function waterfall(tasks, cb) {
//  var taskIndex = 0;
//  function nextTask(args) {
//    if (taskIndex === tasks.length)
//      return cb.apply(null, args);
//
//    var taskCallback = function() {
//      var _arguments = arguments;
//      nextTask(Object.keys(_arguments).reduce(function(memo, key) {
//        memo.push(_arguments[key]);
//        return memo;
//      }, []));
//    };
//    args.push(taskCallback);
//    var task = tasks[taskIndex++];
//    task.apply(null, args);
//  }
//  nextTask([]);
//}
