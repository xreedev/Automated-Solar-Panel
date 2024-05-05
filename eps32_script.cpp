// Function to handle the root page
void handleRoot() {
  String html = "<html><head>";
  html += "<style>";
  html += "body {";
  html += "  background-color: #000033;";
  html += "  color: #fff;";
  html += "  text-align: center;";
  html += "}";
  html += "h1 {";
  html += "  font-size: 36px;";
  html += "  font-weight: bold;";
  html += "}";
  html += "form {";
  html += "  max-width: 400px;";
  html += "  margin: 0 auto;";
  html += "}";
  html += "input[type='text'] {";
  html += "  width: 100%;";
  html += "  padding: 12px;";
  html += "  margin-bottom: 20px;";
  html += "  border-radius: 6px;";
  html += "  border: none;";
  html += "}";
  html += "input[type='submit'] {";
  html += "  background-color: #ffcc00;";
  html += "  color: #000033;";
  html += "  padding: 15px 30px;";
  html += "  border: none;";
  html += "  cursor: pointer;";
  html += "  border-radius: 6px;";
  html += "  font-weight: bold;";
  html += "  transition: background-color 0.3s ease;";
  html += "}";
  html += "input[type='submit']:hover {";
  html += "  background-color: #ffdf80;";
  html += "}";
  html += "</style>";
  html += "</head><body>";
  html += "<h1>Sun Tracking Solar Panel</h1>";
  html += "<form action='/update-location' method='POST'>";
  html += "Latitude: <input type='text' name='latitude'><br>";
  html += "Longitude: <input type='text' name='longitude'><br>";
  html += "<input type='submit' value='Submit'>";
  html += "</form>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

// Function to handle the location update
void handleUpdateLocation() {
  if (server.hasArg("latitude") && server.hasArg("longitude")) {
    latitude = server.arg("latitude").toFloat();
    longitude = server.arg("longitude").toFloat();

    server.send(200, "text/plain", "Location updated successfully");
  } else {
    server.send(400, "text/plain", "Invalid request");
  }
}

// Function to move the servo based on the sun position
void moveServoToSunPosition() {
  solpos.setDate();
  solpos.setObserver(latitude, longitude);
  solpos.calculateSunPosition();

  int angle = map(solpos.getAzimuth(), 0, 360, servoMin, servoMax);
  pwm.setPWM(servoPin, 0, angle);
}

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Initialize the servo driver
  pwm.begin();
  pwm.setPWMFreq(60);

  // Start the web server
  server.on("/", handleRoot);
  server.on("/update-location", handleUpdateLocation);
  server.begin();
}

void loop() {
  server.handleClient();

  // Move the servo to track the sun's position
  moveServoToSunPosition();

  delay(1000);
}