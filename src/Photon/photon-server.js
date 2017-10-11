var express = require('express');
var Particle = require('particle-api-js');

var server = express();
var particle = new Particle();

var deviceId = '27002d000d51353532343635';
var token = '9e7291e786194c836b9605b5672110bc1918ffcf';
var content;


  setInterval(function() {
      particle.getVariable({ deviceId: deviceId, name: 'int_val', auth: token }).then(
          function(data) {
    console.log('Device variable retrieved successfully:', data.body.result);
    content = data.body.result;
  }, function(err) {
    console.log('An error occurred while getting attrs:', err);
  })}, 2000);

server.get('/', function(req, res) {
    console.log('Someone requested the index page');
    res.send(content);
})

server.listen('3000', function() {
    console.log('Express is now running on port 3000');
});