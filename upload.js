var request = require('request');
var fs = require('fs');
const formData = {
    file: fs.createReadStream('/Users/satyam/Downloads/to-be-trash/GameMania.psd')
}
var start = new Date();
request({
    method: 'POST',
    url: 'http://aem65.aal.corp.adobe.com:4502/content/dam/test.createasset.html',
    headers: {
        'Sling-uploadmode': 'stream'
      },
    formData: formData
  },
  function (error, response, body) {
    if (error) {
      return console.error('upload failed:', error);
    }
    console.log('Upload successful!  Server responded with:', body);
    var end = new Date() - start;
    console.info('Execution time: %dms', end);
  }).auth('admin', 'bC7DLcl7Wss2')