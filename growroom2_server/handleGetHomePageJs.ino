

void handleGetHomePageJs() {
  String out;
  out.reserve(6000);

  out += "(function() {";
  out += "document.getElementById('content').innerHTML =";
  out += "\"<div class='room-param'>Environment Parameters</div>";

  out += "<div id='room'>";
  out += "<div id='room-auto' class=''>Room auto control is <var></var></div>";
  out += "<div id='light'>";
  out += "<div id='light1' class=''>Light 1 is <var></var></div>";
  out += "<div id='light1-on' class=''>Light 1 on from <var></var></div>";
  out += "<div id='light1-off' class=''>Light 1 off from <var></var></div>";
  out += "<div id='light2' class=''>Light 2 is <var></var></div>";
  out += "<div id='light2-on' class=''>Light 2 on from <var></var></div>";
  out += "<div id='light2-off' class=''>Ligh 2 1 off from <var></var></div>";
  out += "</div>";
  //    out += "<div id='fan' class=''>Fan is <var></var></div>";
  out += "<div id='temperatureC' class=''>Room temperature: <var></var></div>";
  out += "<div id='temperatureF' class=''>Room temperature: <var></var></div>";
  out += "<div id='humidity'>";
  out += "<div id='humidity' class=''>humidity : <var></var>%</div>";
  out += "<div id='humidity-low' class=''>humidity lower bound : <var></var>%</div>";
  out += "<div id='humidity-high' class=''>humidity higher bound : <var></var>%</div>";
  
  out += "</div>";
  out += "<div id='CO2'>";
  out += "<div id='CO2' class=''>CO2 : <var></var> PPM</div>";
  out += "<div id='CO2-auto' class=''>CO2 auto is <var></var></div>";
  out += "<div id='CO2-low' class=''>CO2 lower bound : <var></var> PPM</div>";
  out += "<div id='CO2-high' class=''>CO2 higher bound : <var></var> PPM</div>";
  out += "<div>";
  out += "</div>";

  out += "<br>";
  out += "<div id='dwc1'>";
  out += "<div id='dwc1-auto'>Growing tote 1 auto control <var></var></div>";
  out += "<div id='dwc1-ph' class=''>pH : <var></var></div>";
  out += "<div id='dwc1-ph-7day' class=''>DWC 1 pH 7 day : <var></var></div>";
  out += "<div id='dwc1-tds' class=''>TDS : <var></var></div>";
  out += "<div id='dwc1-tds-7day' class=''>DWC 1 TDS 7 day : <var></var></div>";
  out += "<div id='dwc1-temperature' class=''>Temperature : <var></var></div>";
  out += "<div id='dwc1-temperature-auto' class=''>Temperature control is <var></var></div>";
  out += "<div id='dwc1-temperature-low' class=''>Temperature lower bound : <var></var></div>";
  out += "<div id='dwc1-temperature-high' class=''>Temperature higher bound : <var></var></div>";
  out += "<div id='dwc1-temperature-24hour' class=''>DWC 1 temperature 24 hour : <var></var></div>";
  out += "</div id='dwc1'>";

  out += "<br>";
  out += "<div id='dwc1'>";
  out += "<div id='dwc2-auto'>Growing tote 2 auto control <var></var></div>";
  out += "<div id='dwc2-ph' class=''>pH : <var></var></div>";
  out += "<div id='dwc2-ph-7day' class=''>DWC 2 pH 7 day : <var></var></div>";
  out += "<div id='dwc2-tds' class=''>TDS : <var></var></div>";
  out += "<div id='dwc2-tds-7day' class=''>DWC 2 TDS 7 day : <var></var></div>";
  out += "<div id='dwc2-temperature' class=''>Temperature : <var></var></div>";
  out += "<div id='dwc2-temperature-auto' class=''>Temperature control is <var></var></div>";
  out += "<div id='dwc2-temperature-low' class=''>Temperature lower bound : <var></var></div>";
  out += "<div id='dwc2-temperature-high' class=''>Temperature higher bound : <var></var></div>";
  out += "<div id='dwc2-temperature-24hour' class=''>DWC 2 temperature 24 hour : <var></var></div>";
  out += "</div id='dwc2'><br><br>";
  
  out += "<form method='post' enctype='application/x-www-form-urlencoded' action='updateparam'>";

  out += "Room auto control <input type='text' name='6' value='1'><br>";
  out += "Light 1 (on/off)<input type='text' name='0' value='on'>";
  out += "Light 1 on time <input type='text' name='1' value='400'> off time <input type='text' name='2' value='2200'><br>";
  out += "Light 2 (on/off)<input type='text' name='3' value='on'>";
  out += "Light 2 on time <input type='text' name='4' value='400'> off time <input type='text' name='5' value='2200'><br>";
  
  out += "CO2 high threshold <input type='text' name='10' value='1000'>";
  out += "CO2 low threshold <input type='text' name='11' value='300'><br>";
  out += "Humidity high threshold <input type='text' name='14' value='8500'>";
  out += "Humidity low threshold <input type='text' name='15' value='4000'><br>";

  out += "DWC 1 temperature auto control <input type='text' name='20' value='1'>";
  out += "DWC 1 temperature high threshold <input type='text' name='21' value='2500'>";
  out += "DWC 1 temperature low threshold <input type='text' name='22' value='1500'><br>";
  

  out += "DWC 2 temperature auto control <input type='text' name='27' value='1'>";
  out += "DWC 2 temperature high threshold <input type='text' name='28' value='2500'>";
  out += "DWC 2 temperature low threshold <input type='text' name='29' value='1500'><br>";
  out += "<input type='submit' value='Submit'>";
  out += "</form>";
  
  out += "\";";

  out += "setInterval(() => {";
  out += "var xhttp = new XMLHttpRequest();";

  out += "xhttp.onreadystatechange = function() {";
  out += "if (this.readyState == 4 && this.status == 200) {";

  out += "var envParams = JSON.parse(xhttp.responseText);";
  out += "document.getElementById('room-auto').getElementsByTagName('var')[0].innerHTML = envParams.roomAuto;";
  out += "document.getElementById('light1').getElementsByTagName('var')[0].innerHTML = envParams.light1;";
  out += "document.getElementById('light1-on').getElementsByTagName('var')[0].innerHTML = envParams.light1On;";
  out += "document.getElementById('light1-off').getElementsByTagName('var')[0].innerHTML = envParams.light1Off;";
  out += "document.getElementById('light2').getElementsByTagName('var')[0].innerHTML = envParams.light2;";
  out += "document.getElementById('light2-on').getElementsByTagName('var')[0].innerHTML = envParams.light2On;";
  out += "document.getElementById('light2-off').getElementsByTagName('var')[0].innerHTML = envParams.light2Off;";
  //    out += "document.getElementById('fan').getElementsByTagName('var')[0].innerHTML = envParams.fan;";
  out += "document.getElementById('temperatureC').getElementsByTagName('var')[0].innerHTML = envParams.temperatureC;";
  out += "document.getElementById('temperatureF').getElementsByTagName('var')[0].innerHTML = envParams.temperatureF;";
  out += "document.getElementById('humidity').getElementsByTagName('var')[0].innerHTML = envParams.humidity;";
  out += "document.getElementById('humidity-low').getElementsByTagName('var')[0].innerHTML = envParams.humidityLow;";
  out += "document.getElementById('humidity-high').getElementsByTagName('var')[0].innerHTML = envParams.humidityHigh;";
  out += "document.getElementById('CO2').getElementsByTagName('var')[0].innerHTML = envParams.CO2;";
  out += "document.getElementById('CO2-auto').getElementsByTagName('var')[0].innerHTML = envParams.CO2Auto;";
  out += "document.getElementById('CO2-low').getElementsByTagName('var')[0].innerHTML = envParams.CO2Low;";
  out += "document.getElementById('CO2-high').getElementsByTagName('var')[0].innerHTML = envParams.CO2High;";
  out += "document.getElementById('dwc1-tds').getElementsByTagName('var')[0].innerHTML = envParams.dwc1Tds;";
  out += "document.getElementById('dwc1-ph').getElementsByTagName('var')[0].innerHTML = envParams.dwc1Ph;";
  out += "document.getElementById('dwc1-temperature').getElementsByTagName('var')[0].innerHTML = envParams.dwc1Temp;";
  out += "document.getElementById('dwc1-temperature-auto').getElementsByTagName('var')[0].innerHTML = envParams.dwc1TempAuto ;";
  out += "document.getElementById('dwc1-temperature-low').getElementsByTagName('var')[0].innerHTML = envParams.dwc1TempLow;";
  out += "document.getElementById('dwc1-temperature-high').getElementsByTagName('var')[0].innerHTML = envParams.dwc1TempHigh;";
  out += "document.getElementById('dwc2-tds').getElementsByTagName('var')[0].innerHTML = envParams.dwc2Tds;";
  out += "document.getElementById('dwc2-ph').getElementsByTagName('var')[0].innerHTML = envParams.dwc2Ph;";
  out += "document.getElementById('dwc2-temperature').getElementsByTagName('var')[0].innerHTML = envParams.dwc2Temp;";
  out += "document.getElementById('dwc2-temperature-auto').getElementsByTagName('var')[0].innerHTML = envParams.dwc2TempAuto;";
  out += "document.getElementById('dwc2-temperature-low').getElementsByTagName('var')[0].innerHTML = envParams.dwc2TempLow;";
  out += "document.getElementById('dwc2-temperature-high').getElementsByTagName('var')[0].innerHTML = envParams.dwc2TempHigh;";

  out += "document.getElementById('dwc1-temperature-24hour').getElementsByTagName('var')[0].innerHTML = JSON.stringify(envParams.dwc1Temp24Hour);";
  out += "document.getElementById('dwc1-tds-7day').getElementsByTagName('var')[0].innerHTML = JSON.stringify(envParams.dwc1TDS7Day);";
  out += "document.getElementById('dwc1-ph-7day').getElementsByTagName('var')[0].innerHTML = JSON.stringify(envParams.dwc1PH7Day);";

  out += "document.getElementById('dwc2-temperature-24hour').getElementsByTagName('var')[0].innerHTML = JSON.stringify(envParams.dwc2Temp24Hour);";
  out += "document.getElementById('dwc2-tds-7day').getElementsByTagName('var')[0].innerHTML = JSON.stringify(envParams.dwc2TDS7Day);";
  out += "document.getElementById('dwc2-ph-7day').getElementsByTagName('var')[0].innerHTML = JSON.stringify(envParams.dwc2PH7Day);";

  out += "}";
  out += "else {";
//  out += "document.getElementById('light').getElementsByTagName('var')[0].innerHTML = 'on';";
  out += "}";
  out += "};";
  out += "xhttp.open('GET', 'getparam', true);";
  out += "xhttp.send();";
  out += "}, 5000);";
  out += "})();";



  server.send(200, "application/javascript", out);
}
