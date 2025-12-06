# 🔥 IoT-Based Gas Leakage Detector (Home Safety System)

This project is an IoT-enabled home safety device designed to detect gas leaks using the MQ6 sensor and provide immediate visual and sound alerts. The system uses an ESP8266 for processing and cloud connectivity, allowing real-time monitoring through Firebase.

---

## ⚡ Features

- Real-time gas leakage detection (MQ6)
- Automatic LED warning + delayed buzzer alert
- Temperature and humidity monitoring (DHT11)
- Live data upload to Firebase for remote monitoring
- Compact, low-cost, and easy-to-deploy home safety solution

---

## 🔧 Hardware Used

- ESP8266 NodeMCU  
- MQ6 Gas Sensor  
- DHT11 Temperature & Humidity Sensor  
- LED (Immediate alert)  
- Buzzer (2-second delayed alert)  
- Breadboard & Jumper wires  

---

## 💻 Software Used

- Arduino IDE  
- Firebase Realtime Database  
- Libraries: ESP8266WiFi, Firebase ESP Client, DHT sensor library  

---

## ⚙️ How the System Works

1. MQ6 sensor continuously detects gas concentration in the environment.  
2. If the gas level crosses the threshold:  
   - LED turns ON immediately  
   - Buzzer activates after 2 seconds  
3. DHT11 records temperature & humidity.  
4. ESP8266 uploads all data (gas, temp, humidity, alert status) to Firebase.  
5. Users can monitor home safety from anywhere via cloud access.

---

## 📁 Repository Structure

hardware/ — circuit diagram & sensor details  
firmware/ — Arduino code  
documentation/ — project report & presentation  
images/ — prototype photos & output screenshots  
video/ — working of the project  

---

## 📸 Results

- MQ6 successfully detected gas leakage during testing  
- LED and buzzer alerts triggered reliably  
- Temperature & humidity readings uploaded to Firebase  
- Real-time monitoring confirmed via cloud logs  

---

## 🚀 Benefits

- Prevents fire hazards and accidents  
- Enables remote monitoring using IoT  
- Fast response alerts (visual + audible)  
- Cost-effective and scalable  
- Ideal for homes, kitchens, and industries  

---

## 🔮 Future Enhancements

- Mobile app alerts (push notifications)  
- Automatic gas valve shutoff  
- Battery backup support  
- Integration with Alexa/Google Assistant  
- Adding ventilation control during leakage  

---

## 👥 Team - NEXUS 4

Ishan Jiji George  
Manuel James  
Sherry John  
Sona Salu
