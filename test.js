//ajax


//run xml
    var myobj;
    var fs = require('fs');
    xml2js = require('xml2js');
    var parser = new xml2js.Parser();
    fs.readFile( 'CFG.xml', function(err, data) {
    parser.parseString(data, function (err, result) {
        console.dir(JSON.stringify(result));
        console.log('Done');
/*
var obj, dbParam, xmlhttp, myObj, x, txt = "";
obj = { table: "Input", limit: 20 };
dbParam = JSON.stringify(data);
xmlhttp = new XMLHttpRequest();
xmlhttp.onreadystatechange=function () {
    if (this.readyState == 4 && this.status == 200) {
        myObj = JSON.parse(result);
        txt += "<table border='1'>"
        for (x in myObj) {
            txt = "<tr><td>" + myObj[x].name + "</td></tr>";
        }
        txt += "</table>"        
        document.getElementById("demo").innerHTML = txt;
    }
};
*/

});
});

/*

var xhttp = new XMLHttpRequest();
xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
        myFunction(this);
    }
};
xhttp.open("GET","CD.xml", true);
xhttp.send();

function myFunction(xml) {
  var parser, xmlDoc;
  parser = new DOMParser();
  xmlDoc = parser.parseFromString(xml.responseText,"text/xml");
  document.getElementById("WE").innerHTML =
  myLoop(xmlDoc.documentElement);
}

function myLoop(x) {
  var i, y, xLen, txt;
  txt = "";
  x = x.childNodes;
  xLen = x.length;
  for (i = 0; i < xLen ;i++) {
    y = x[i];
    if (y.nodeType != 3) {
      if (y.childNodes[0] != undefined) {
        txt += myLoop(y);
      }
    } else {
    txt += y.nodeValue + "<br>";
    }
  }
  return txt;
}*/